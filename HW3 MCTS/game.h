/* game.h
Nathan Damon
CS 405
1/18/2022
This is the header file for the game class that will handle the game.
*/

#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <chrono>
#include <queue>
#include <memory>
#include <iomanip>

class Game
{
public:
	enum class PlayerColor
	{
		CPU_playerGame,
		Red,
		Black,
		White
	};

    Game(sf::RenderWindow& gfx, PlayerColor playerColor = PlayerColor::Red, sf::Vector2u boardsize = { 512, 512 }, PlayerColor player2Color = PlayerColor::Black);
    Game(sf::RenderWindow& gfx, PlayerColor playerColor, PlayerColor player2Color, bool tournamentMode, int difficulty, int difficultyDepth = 1);
	~Game();

	void run();
    // Returns true if gameover
    bool runStep(bool mouseButtonPressed);
	void doTests();
	int test(std::string testName, std::vector<PieceType>& initialBoardTiles, std::vector<std::vector<PieceType>>& finalBoards, int turn, int movesToBeMade, int depth);

	void enableDebugPrintout(bool doDebugPrintout);

	void nextTurn();
	void displayMoves();
private:
	void setupWinSprite();
	void winDisplay();
	void winDisplaySet(PlayerColor playerColor);
	void winCheck();

	void drawSelf();
	// Returns true if player2's color is black
	bool setPlayer2Color(PlayerColor playerColor, PlayerColor team2Color);
	void setUpBoard(std::vector<PieceType>& tiles, int turn);

	void getMoves();
	void conductMoves(DWORD sleepTime);

	void setSelectedIndex();
	void userInputHandle();
	bool isUserTurn();
	void makeUserMove();
	// True if the move given is in the possible moves
	bool findMoveMatch(int indexFrom, int indexTo);

	// returns difference of piece values with respect to teamTurn
	static float boardEvaluate(const std::vector<PieceType> tiles, int teamTurn);
	// Recursively makes boards and evaluates them. Returns the minimum and maximum boardEvaluations made
	float miniMax(Board& board, const int teamTurn, const int maximizingTurn, const int depth, std::vector<sf::Vector3<int>>& additionalJumps);
	// Recursively makes boards and evaluates them with alpha beta cutoff. Returns the minimum and maximum boardEvaluations made
	float alphaBeta(Board& board, const int turn, const int maximizingTurn, const int depth, std::vector<sf::Vector3<int>>& additionalJumps, float& a, float& b);

public:
	class MCTS_Node
	{
	public:
		MCTS_Node(Board& board, int teamTurn)
			: _board(board), _teamTurn(teamTurn)
		{
			++_MCTS_nodeCount;
		}
		MCTS_Node(MCTS_Node* parentNode, Board& board, int teamTurn, std::queue<sf::Vector3<int>>& movesMade)
			: _parentNode(parentNode), _board(board), _teamTurn(teamTurn), _movesMade(movesMade)
		{
			++_MCTS_nodeCount;
		}
		~MCTS_Node()
		{
			--_MCTS_nodeCount;
		}

		std::vector<std::unique_ptr<MCTS_Node>>& getChildrenNodes()
		{
			return _childrenNodes;
		}
		MCTS_Node* getParentNode()
		{
			return _parentNode;
		}


		bool isFullyExpanded()
		{
			if (_childrenNodes.size() == 0)
				return false;
			for (auto& child : _childrenNodes)
				if (child->getVisitCount() == 0)
					return false;
			return true;
		}
		bool isRoot()
		{
			return _parentNode == nullptr;
		}
		bool isNotTerminal()
		{
			if (!_generatedAvailableChildren)
				generateChildren();
			return !_childrenNodes.empty();
		}

		MCTS_Node* getUnvisited()
		{
			if (isNotTerminal())
			{
				for (auto& child : _childrenNodes)
					if (child->getVisitCount() == 0)
						return child.get();
			}
			else
				return this;
		}
		std::queue<sf::Vector3<int>> getMovesMade()
		{
			return _movesMade;
		}

		Board& getBoard()
		{
			return _board;
		}
		int getTurn()
		{
			return _teamTurn;
		}
		float getScore()
		{
			return _totalScore;
		}
		int getVisitCount()
		{
			return _visitCount;
		}
		void setStats(float score, int visits)
		{
			_totalScore = score;
			_visitCount = visits;
		}
		void updateStats(float addScore)
		{
			//std::cout << "updateStats called\n";
			setStats(getScore() + addScore, getVisitCount() + 1);
		}

		float getEvaluation(int teamTurn)
		{
			if (teamTurn == _teamTurn)
				return 0.0f;
			return 1.0f;
		}
		void setGeneratedAvailableChildren(bool b)
		{
			_generatedAvailableChildren = b;
			_childrenNodes.clear();
		}
		void generateChildren() 
		{
			if (!_generatedAvailableChildren)
			{				
				std::vector<sf::Vector3<int>> possibleGeneratedMoves;
				_board.generateMoves(possibleGeneratedMoves, _teamTurn);

				if (possibleGeneratedMoves.size() > 0)
				{
					std::vector<std::queue<sf::Vector3<int>>> possibleMoves;
					// These moves are jumps
					if (possibleGeneratedMoves[0].z != -1)
					{
						std::queue<sf::Vector3<int>> currentMoveSequence = {};
						getFullJumpSet(possibleGeneratedMoves, possibleMoves, currentMoveSequence, _board, _teamTurn);
					}
					else
					{
						// No jumps
						for (size_t i = 0; i < possibleGeneratedMoves.size(); i++)
						{
							std::queue<sf::Vector3<int>> temp;
							temp.push(possibleGeneratedMoves[i]);
							possibleMoves.push_back(temp);
						}

						for (auto& moveSequences : possibleMoves)
						{
							Board newBoard(Board::portrayMove(_board.getBoardTiles(), moveSequences.front()));
							auto child = std::make_unique<MCTS_Node>(this, newBoard, nextTurn(), moveSequences);
							_childrenNodes.push_back(std::move(child));
						}
					}

				}
				_generatedAvailableChildren = true;
			}
		}

		void setParentPointer(MCTS_Node* newParentNode)
		{
			_parentNode = newParentNode;
		}
		/*std::unique_ptr<MCTS_Node>& removeMatchingChild(MCTS_Node* childNode)
		{
			for (auto& p : _childrenNodes)
				if (p->getBoard().getBoardTiles() == childNode->getBoard().getBoardTiles())
					return p;
		}*/
		static int getNodeCount()
		{
			return _MCTS_nodeCount;
		}
	private:
		void getFullJumpSet(std::vector<sf::Vector3<int>>& possibleGeneratedMovesIN, std::vector<std::queue<sf::Vector3<int>>> &movesOUT, 
							std::queue<sf::Vector3<int>>& currentMoveSequence, Board& board, int& teamTurn)
		{
			for (size_t i = 0; i < possibleGeneratedMovesIN.size(); i++)
			{				
				// Push first move in sequence
				currentMoveSequence.push(possibleGeneratedMovesIN[i]);

				bool isKing = false;
				if(board.getBoardTiles()[possibleGeneratedMovesIN[i].x] >= PieceType::Player1_King)
					isKing = true;

				Board newBoard(Board::portrayMove(board.getBoardTiles(), possibleGeneratedMovesIN[i]));

				std::vector<sf::Vector3<int>> possibleJumps;
				// Was not a king, but is now
				if (isKing || (!isKing && newBoard.getBoardTiles()[possibleGeneratedMovesIN[i].y] < PieceType::Player1_King))
					newBoard.getIndividualPieceMoves(possibleJumps, possibleGeneratedMovesIN[i].y, teamTurn, true);

				// Either we have more jumps or we don't and thus add the jump sequence
				if (possibleJumps.empty())
				{
					movesOUT.push_back(currentMoveSequence);				
					auto child = std::make_unique<MCTS_Node>(this, newBoard, nextTurn(), currentMoveSequence);
					_childrenNodes.push_back(std::move(child));
				}
				else
				{
					getFullJumpSet(possibleJumps, movesOUT, currentMoveSequence, newBoard, teamTurn);
				}

				// Remove move at end of sequence
				currentMoveSequence.pop();
			}
		}
		int nextTurn()
		{
			if (_teamTurn == 1)
				return 2;
			else
				return 1;
		}

		Board _board;
		int _teamTurn;
		std::queue<sf::Vector3<int>> _movesMade;

		float _totalScore = 0.0f;
		int _visitCount = 0;

		bool _generatedAvailableChildren = false;
		std::vector<std::unique_ptr<MCTS_Node>> _childrenNodes;
		MCTS_Node* _parentNode = nullptr;

		static int _MCTS_nodeCount;
	};

private:
	float getUCB(MCTS_Node* node);

	MCTS_Node* traverse(MCTS_Node* node);
	MCTS_Node* bestUCB(MCTS_Node* node);
	// Make moves based on rollout policy till result
	float mCTS_Rollout(MCTS_Node* node);
	// Get random child node
	std::unique_ptr<MCTS_Node>& rolloutPolicy(MCTS_Node* node);
	// Picks the child with the highest number of visits
	MCTS_Node* best_child(MCTS_Node* node);
	// Back propagates data back up the search tree
	void backPropagate(MCTS_Node* node, float result);
	// Calls the Monte Carlo Tree Search algorithm
	std::queue<sf::Vector3<int>> mCTS(MCTS_Node* rootNode, float timeAvailableInSeconds);


	// Returns the optimal move upon a DFS of x turns of possible moves
	sf::Vector3<int> miniMaxCall(const std::vector<sf::Vector3<int>>& possibleMoves, int depthOfSearch, int turn, bool doPrintout);
	sf::Vector3<int> miniMaxCall(bool doPrintout);
	// Returns the optimal move upon an alpha beta DFS of x turns of possible moves 2x to 5x and sometimes 10x faster although results are slightly different at times
	sf::Vector3<int> alphaBetaCall(std::vector<sf::Vector3<int>>& possibleMoves, int depthOfSearch, int turn, bool doPrintout);
	sf::Vector3<int> alphaBetaCall(bool doPrintout);

	sf::Vector3<int> mCTSCall();

	// Compares the results of the comparison between miniMaxCall() and alphaBetaCall()
	void alphaBetaMiniMaxCompare(bool doPrintout);
	// Sets the search depth of miniMaxCall() and alphaBetaCall()
	void setDepthOfSearch(int depthOfSearch);

    // Randomly chooses a move available
    void makeRandomMove();
	// Uses miniMax function to pick a move
	void makeMiniMaxMove(bool doPrintout);
	// Uses alphaBeta function to pick a move
	void makeAlphaBetaMove(bool doPrintout);
	// Uses  the Monte Carlo Tree Search algorithm to pick a move
	void makeMCTS_Move();
	void finalizeMove();

	void loadAdditionalJumps();
	bool areAdditionalJumps();

	int getBoardTile(size_t index);

    // Sets up on of the 216 starting tournament boards
    void setupRandomTournamentBoard();
    // Generates the 216 starting tournament boards
	void tournamentBoardGen();

    int _difficulty;
	int _turn = 1;
	int _turnCount = 0;
	bool _gameOver = false;
	sf::Vector3<int> _latestMove;
	std::vector<sf::Vector3<int>> _possibleMoves;
	std::vector<sf::Vector3<int>> _possibleAdditionalJumps;

	static std::vector<std::vector<PieceType>> _startingBoards;

	// Evaluation piece weights
	static float _pawnWeight;
	static float _kingWeight;
	int _depthOfSearch = 0;

	int _lastTurnMCTS_wasCalled = 0;
	std::unique_ptr<MCTS_Node> _mCTS_RootNode = nullptr;
	float _timeAvailableInSeconds = 1.0f;
	// MCTS moves
	std::queue<sf::Vector3<int>> _mCTS_Moves;

	// Testing
	bool _isTesting = false;
	int _testCount = 0;
	bool _doDebugPrintout = true;

	static int _miniMaxCalls;
	static int _alphaBetaCalls;
	static int _evaluationCalls;

	int _branchSplitCount = 0;
	int _branchCount = 0;
	float _averageBranchFactor = 0.0f;

	int _userTurn = 1;
	int _userSelectedIndex = -1;
	int _userSelectedPiece = -1;

	PlayerColor _player2Color = PlayerColor::Black;
	Board _board;
	sf::RenderWindow& _gfx; // Remove for menus

	static sf::Texture _winTexture;
	static sf::Sprite _winSprite;
};




#endif // !GAME_H
