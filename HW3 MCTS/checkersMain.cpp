/* checkersMain.cpp
Nathan Damon
CS 405
2/20/2022
This is the file that contains main and will run the program
This file replaced the old basicCheckersMain as this is no longer basic checkers
*/

#include "menu.h"

int main()
{
	Menu gameMenu;
	gameMenu.run();
	//sf::RenderWindow window(sf::VideoMode(Board::getBoardLength(), Board::getBoardLength()), "Checkers!");
	//Game game(window, Game::PlayerColor::White, { 768, 768 }, Game::PlayerColor::White);
	//game.enableDebugPrintout(false);
	////game.doTests();
	//game.run();

	return 0;
}