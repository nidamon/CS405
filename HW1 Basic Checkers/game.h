/* game.h
Nathan Damon
CS 405
1/18/2022
This is the header file for the game class that will handle the game.
*/

#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <Windows.h>
#include <random>

class Game
{
public:
	enum class PlayerColor
	{
		CPU_playerGame,
		Red,
		Black,
		White = Black
	};

	Game();
	Game(PlayerColor playerColor);
	~Game();

	void run();

	void nextTurn();
	void displayMoves();
	void displayStats();
private:
	void drawSelf();

	void userInputHandle();
	bool isUserTurn();
	void makeUserMove();
	bool findMoveMatch(int indexFrom, int indexTo);

	void makeRandomMove();
	void finalizeMove();

	void loadAdditionalJumps();
	bool areAdditionalJumps();

	int getBoardTile(size_t index);
	
	void addHistogramData(int movesGenerated);

	int _turn = 1;
	sf::Vector3<int> _latestMove;
	std::vector<sf::Vector3<int>> _possibleMoves;
	std::vector<sf::Vector3<int>> _possibleAdditionalJumps;

	int _playerTurn = 1;
	bool _playerMadeSelection = false;
	int _userSelectedIndex = -1;
	int _userSelectedPiece = -1;

	Board _board;
	sf::RenderWindow _gfx;


	int _maxMovesGenerated = 0;
	int _minMovesGenerated = 100;
	std::vector<int> _histogramData;
};




#endif // !GAME_H
