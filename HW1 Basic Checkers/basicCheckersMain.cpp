/* basicCheckersMain.cpp
Nathan Damon
CS 405
1/18/2022
This is the file that contains main and will run the program
*/

#include "board.h"

int main()
{
    Board board;

    board.setBoardLength(256);

    sf::RenderWindow window(sf::VideoMode(board.getBoardLength(), board.getBoardLength()), "Basic Checkers!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        board.drawSelf(window);
        window.display();
    }

	return 0;
}