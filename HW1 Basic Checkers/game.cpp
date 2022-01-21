/* game.cpp
Nathan Damon
CS 405
1/18/2022
This is the cpp file for the game class.
*/

#include "game.h"

std::random_device r;
std::mt19937 gen(r());
std::uniform_real_distribution<float> randPercent(0.0f, 1.0f);

Game::Game() 
    : _gfx(sf::VideoMode(_board.getBoardLength(), _board.getBoardLength()), "Basic Checkers!")
{
}
Game::Game(PlayerColor playerColor) 
    : _gfx(sf::VideoMode(_board.getBoardLength(), _board.getBoardLength()), "Basic Checkers!"),
    _playerTurn(int(playerColor))
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
            if (_playerTurn == _turn)
                if (event.type == sf::Event::MouseButtonPressed) {                    
                    auto pos = (sf::Mouse::getPosition() - _gfx.getPosition()) + sf::Vector2i(-8, -31);
                    std::cout << "MousePos: (" << pos.x << "," << pos.y << ")" << std::endl;
                    if (pos.x >= 0 && pos.x < _board.getBoardLength())
                        if (pos.y >= 0 && pos.y < _board.getBoardLength())
                        {
                            pos.x /= (_gfx.getSize().x / 8);
                            pos.y /= (_gfx.getSize().y / 8);
                            std::cout << "Window size: (" << _gfx.getSize().x << "," << _gfx.getSize().x << ")" << std::endl;
                            std::cout << "BoardPos: (" << pos.x << "," << pos.y << ")" << std::endl;
                            _userSelectedIndex = _board.xyToIndex(pos.x, pos.y);
                        }
                }

            if (event.type == sf::Event::Closed)
                _gfx.close();
        }

        // Get possible piece moves
        if (!areAdditionalJumps())
        {
            // Don't generate new moves if a move has yet to be made
            if (_possibleMoves.empty())
            {
                _board.generateMoves(_possibleMoves, _turn);
                addHistogramData(_possibleMoves.size());
            }
        }
        else
            loadAdditionalJumps();


        
        // Game over
        if (_possibleMoves.empty())
        {
            if (_turn == 2) // Black can't play
                std::cout << "Red Wins" << std::endl;
            if (_turn == 1) // Red can't play
                std::cout << "Black Wins" << std::endl;                
            return;
        }

        drawSelf();

        if (isUserTurn())
            userInputHandle();
        else
        {
            Sleep(200);
            makeRandomMove();

            drawSelf();
            Sleep(200);
        }
    }
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

    // Total generations
    int totalMoveGenerations = 0;
    for (size_t i = 0; i < _histogramData.size(); i++)
    {
        totalMoveGenerations += _histogramData[i];
    }
    std::cout << "Total generations: " << totalMoveGenerations << std::endl;

    int totalMovesGenerated = 0;
    for (size_t i = 0; i < _histogramData.size(); i++)
    {
        totalMovesGenerated += i * _histogramData[i];
    }
    std::cout << "Total moves generated: " << totalMovesGenerated << std::endl;
    std::cout << "Average: " << totalMovesGenerated / totalMoveGenerations << std::endl;
}



void Game::drawSelf()
{
    _gfx.clear();
    _board.drawSelf(_gfx);
    displayMoves();
    _gfx.display();
}

void Game::userInputHandle()
{
    if (_userSelectedIndex >= 0 && _userSelectedIndex < 32)
    {
        if (_userSelectedPiece != -1)
        {
            // Clicking the same area more than once
            if (_userSelectedPiece == _userSelectedIndex)
            {
                _userSelectedIndex = -1;
                return;
            }
            // Clicking on a different one of your pieces
            if (getBoardTile(_userSelectedIndex) != 0 && getBoardTile(_userSelectedIndex) % 2 == _turn % 2)
            {
                _userSelectedPiece = _userSelectedIndex;
                _userSelectedIndex = -1;
                return;
            }


            if (findMoveMatch(_userSelectedPiece, _userSelectedIndex))
            {
                std::cout << "Moving: (" << _board.indexToXY(_userSelectedPiece).x << ", " << _board.indexToXY(_userSelectedPiece).y << ") -> ("
                    << _board.indexToXY(_userSelectedIndex).x << ", " << _board.indexToXY(_userSelectedIndex).y << ")" << std::endl;
                // Make the chosen move
                makeUserMove();
            }
            else
            {
                std::cout << "Tried: (" << _board.indexToXY(_userSelectedPiece).x << ", " << _board.indexToXY(_userSelectedPiece).y << ") -> ("
                    << _board.indexToXY(_userSelectedIndex).x << ", " << _board.indexToXY(_userSelectedIndex).y << ")" << std::endl;
            }
            _userSelectedPiece = -1;
        }
        else
            _userSelectedPiece = _userSelectedIndex;
    }
    _userSelectedIndex = -1;
}
bool Game::isUserTurn()
{
    return _playerTurn == _turn;
}
void Game::makeUserMove()
{
    if (_possibleMoves.size() > 0)
    {
        finalizeMove();
    }
}
bool Game::findMoveMatch(int indexFrom, int indexTo)
{
    for (auto move : _possibleMoves)
        if (move.x == _userSelectedPiece && move.y == _userSelectedIndex)
        {
            _latestMove = move;
            return true;
        }
    return false;
}

void Game::makeRandomMove()
{
    // Random
    if (_possibleMoves.size() > 0)
    {
        _latestMove = _possibleMoves[(int(randPercent(gen) * float(int(_possibleMoves.size()) + 1))) % _possibleMoves.size()];

        finalizeMove();
    }
}
void Game::finalizeMove()
{
    _board.movePiece(_latestMove);
    _possibleMoves.clear();

    if (_latestMove.z != -1) // We just jumped
    {
        if (_board.getIndividualPieceMoves(_possibleAdditionalJumps, _latestMove.y, _turn))
        {
            _possibleAdditionalJumps.erase(
                std::remove_if(_possibleAdditionalJumps.begin(), _possibleAdditionalJumps.end(),
                    [](const sf::Vector3<int> move) {return move.z == -1; }), _possibleAdditionalJumps.end());
            return; // Don't change turns
        }
        // No jumps but still need to clear
        _possibleAdditionalJumps.clear();
    }

    // Change turn if current player has made a move and has no additional jumps to make
    if (!areAdditionalJumps())
        nextTurn();
}

void Game::loadAdditionalJumps()
{
    std::swap(_possibleMoves, _possibleAdditionalJumps);
    _possibleAdditionalJumps.clear();

    if (isUserTurn() && _possibleMoves.size() > 0)
        _userSelectedPiece = _possibleMoves[0].x;
}
bool Game::areAdditionalJumps()
{
    return _possibleAdditionalJumps.size() > 0;
}

int Game::getBoardTile(size_t index)
{
    return int(_board.getBoardTiles()[index]);
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