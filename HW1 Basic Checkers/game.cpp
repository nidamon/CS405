/* game.cpp
Nathan Damon
CS 405
1/18/2022
This is the cpp file for the game class.
*/

#include "game.h"

std::random_device r;
std::mt19937 gen(r());
std::uniform_real_distribution<> randPercent(0.0, 1.0);

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
        addHistogramData(_possibleMoves.size());
        
        // Game over
        if (_possibleMoves.empty())
        {
            if (_turn == 1)
                std::cout << "Red Wins" << std::endl;
            if (_turn == 2)
                std::cout << "Black Wins" << std::endl;
                       
            displayStats();
            return;
        }

        drawSelf();
        //Sleep(200);

        makeRandomMove();

        //drawSelf();
        //Sleep(200);
    };
}
void Game::nextTurn()
{
	if (++_turn > 2)
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
	    _board.movePiece(_possibleMoves[(int(randPercent(gen) * double(_possibleMoves.size() + 1))) % _possibleMoves.size()]);
	nextTurn();
}


void Game::displayStats()
{
    for (size_t i = 0; i < _histogramData.size(); i++)
    {
        if (i != 0)
            std::cout << ",";
        std::cout << "(" << i << "," << _histogramData[i] << ")";
    }
    std::cout << std::endl;
    std::cout << "MovesGenerated: " << std::endl;
    std::cout << "Max: " << _maxMovesGenerated << std::endl;
    std::cout << "Min: " << _minMovesGenerated << std::endl;
    int totalMoves = 0;
    for (size_t i = 0; i < _histogramData.size(); i++)
    {
        totalMoves += _histogramData[i];
    }
    float averageMoves = 0;
    for (size_t i = 0; i < _histogramData.size(); i++)
    {
        averageMoves += float(i) * float(_histogramData[i]) / float(totalMoves);
    }
    std::cout << "Average: " << averageMoves << std::endl;
    std::cout << "Total: " << totalMoves << std::endl;
}
void Game::addHistogramData(int movesGenerated)
{
    if (movesGenerated > _maxMovesGenerated)
        _maxMovesGenerated = movesGenerated;
    if (_minMovesGenerated > movesGenerated)
        _minMovesGenerated = movesGenerated;

    if (_histogramData.size() <= movesGenerated)
        _histogramData.resize(movesGenerated + 1, 0);

    ++_histogramData[movesGenerated];    
}