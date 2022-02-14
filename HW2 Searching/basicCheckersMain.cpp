/* basicCheckersMain.cpp
Nathan Damon
CS 405
1/18/2022
This is the file that contains main and will run the program
*/

#include "game.h"

int main()
{
	Game game(Game::PlayerColor::White, { 768, 768 }, Game::PlayerColor::White);
	//game.doTests();
	game.run();

	//game.displayStats();

	return 0;
}