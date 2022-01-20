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
	Game();
	~Game();

	void run();

	void nextTurn();
	void displayMoves();
private:
	void drawSelf();
	void makeRandomMove();

	void displayStats();
	void addHistogramData(int movesGenerated);

	int _turn = 1;
	std::vector<sf::Vector3<int>> _possibleMoves;

	Board _board;
	sf::RenderWindow _gfx;


	int _maxMovesGenerated = 0;
	int _minMovesGenerated = 100;
	std::vector<int> _histogramData;
};




#endif // !GAME_H
