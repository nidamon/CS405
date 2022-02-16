/* basicCheckersMain.cpp
Nathan Damon
CS 405
1/18/2022
This is the file that contains main and will run the program
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