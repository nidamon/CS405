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

	Game(bool tests);
	Game(PlayerColor playerColor = PlayerColor::Red, sf::Vector2u boardsize = { 512, 512 }, PlayerColor player2Color = PlayerColor::Black);
	~Game();

	void run();
	void doTests();
	bool test(std::string testName, std::vector<PieceType>& initialBoardTiles, std::vector<PieceType>& finalBoardTiles);

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

	void getMoves();
	void conductMoves();

	void setSelectedIndex();
	void userInputHandle();
	bool isUserTurn();
	void makeUserMove();
	// True if the move given is in the possible moves
	bool findMoveMatch(int indexFrom, int indexTo);

	// returns difference of piece values with respect to teamTurn
	float boardEvaluate(const std::vector<PieceType> tiles, int teamTurn);
	// Recursively makes boards and evaluates them. Returns the minimum and maximum boardEvaluations made
	float miniMax(Board& board, const int teamTurn, const int depth, const bool getMin);
	// Returns the optimal move upon a DFS of x turns of possible moves
	sf::Vector3<int> miniMaxCall();
	// Sets the search depth of miniMaxCall()
	void setDepthOfSearch(int depthOfSearch);

	// Uses miniMax function to pick a move
	void makeMiniMaxMove();
	void finalizeMove();

	void loadAdditionalJumps();
	bool areAdditionalJumps();

	int getBoardTile(size_t index);

	int _turn = 1;
	bool _gameOver = false;
	sf::Vector3<int> _latestMove;
	std::vector<sf::Vector3<int>> _possibleMoves;
	std::vector<sf::Vector3<int>> _possibleAdditionalJumps;

	// MiniMax piece weights
	float _pawnWeight = 1.0f;
	float _kingWeight = 1.5f;
	int _depthOfSearch = 0;

	// Testing
	int _testCount = 0;

	int _miniMaxCalls = 0;
	int _evaluationCalls = 0;

	int _userTurn = 1;
	int _userSelectedIndex = -1;
	int _userSelectedPiece = -1;

	PlayerColor _player2Color = PlayerColor::Black;
	Board _board;
	sf::RenderWindow _gfx;

	sf::Texture _winTexture;
	sf::Sprite _winSprite;

	Stats _stats;
};




#endif // !GAME_H
