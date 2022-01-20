/* game.cpp
Nathan Damon
CS 405
1/18/2022
This is the cpp file for the game class.
*/

#include "game.h"

Game::Game() : _gfx(sf::VideoMode(_board.getBoardLength(), _board.getBoardLength()), "Basic Checkers!")
{
}

Game::~Game()
{
}

void Game::run()
{
    while (_gfx.isOpen())
    {
        sf::Event event;
        while (_gfx.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _gfx.close();
        }

        // Get possible piece moves
        _possibleMoves = _board.generateMoves(_turn);

        drawSelf();
        Sleep(200);

        makeRandomMove();

        drawSelf();
        Sleep(200);
    };
}
void Game::nextTurn()
{
	++_turn;
	if (_turn > 2)
		_turn = 1;
}

void Game::displayMoves()
{
    for (size_t i = 0; i < _possibleMoves.size(); i++)
    {
        sf::VertexArray lines(sf::LinesStrip, 2);
        lines[0].position = _board.indexToPosition(_possibleMoves[i].x) * _board.getTileWidth() + sf::Vector2<float>(_board.getBoardLength() / 16.0f, _board.getBoardLength() / 16.0f);
        lines[1].position = _board.indexToPosition(_possibleMoves[i].y) * _board.getTileWidth() + sf::Vector2<float>(_board.getBoardLength() / 16.0f, _board.getBoardLength() / 16.0f);
        _gfx.draw(lines);
    }
}

void Game::drawSelf()
{
    _gfx.clear();
    _board.drawSelf(_gfx);
    displayMoves();
    _gfx.display();
}

void Game::makeRandomMove()
{
    if(_possibleMoves.size() > 0)
	    _board.movePiece(_possibleMoves[rand() % _possibleMoves.size()]);
	nextTurn();
}