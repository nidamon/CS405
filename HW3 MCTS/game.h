/* game.h
Nathan Damon
CS 405
1/18/2022
This is the header file for the game class that will handle the game.
*/

#ifndef GAME_H
#define GAME_H

#include "board.h"

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

	// Returns the optimal move upon a DFS of x turns of possible moves
	sf::Vector3<int> miniMaxCall(const std::vector<sf::Vector3<int>>& possibleMoves, int depthOfSearch, int turn, bool doPrintout);
	sf::Vector3<int> miniMaxCall(bool doPrintout);
	// Returns the optimal move upon an alpha beta DFS of x turns of possible moves 2x to 5x and sometimes 10x faster although results are slightly different at times
	sf::Vector3<int> alphaBetaCall(const std::vector<sf::Vector3<int>>& possibleMoves, int depthOfSearch, int turn, bool doPrintout);
	sf::Vector3<int> alphaBetaCall(bool doPrintout);

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
	bool _gameOver = false;
	sf::Vector3<int> _latestMove;
	std::vector<sf::Vector3<int>> _possibleMoves;
	std::vector<sf::Vector3<int>> _possibleAdditionalJumps;

	static std::vector<std::vector<PieceType>> _startingBoards;

    // Remove
    static std::vector<std::string> tournamentBoards;

	// MiniMax piece weights
	static float _pawnWeight;
	static float _kingWeight;
	int _depthOfSearch = 0;

	// Testing
	bool _isTesting = false;
	int _testCount = 0;
	bool _doDebugPrintout = false;

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
