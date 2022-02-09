/* game.cpp
Nathan Damon
CS 405
1/18/2022
This is the source file for the game class.
*/

#include "game.h"

std::random_device r;
std::mt19937 gen(r());
std::uniform_real_distribution<float> randPercent(0.0f, 1.0f);

Game::Game(PlayerColor playerColor, sf::Vector2u boardsize, PlayerColor player2Color)
    : _board(setPlayer2Color(playerColor, player2Color)),
      _gfx(sf::VideoMode(_board.getBoardLength(), _board.getBoardLength()), "Basic Checkers!")
{
    _gfx.setSize(boardsize);

    // Player 1 or Red player
    if (playerColor == PlayerColor::CPU_playerGame)
        _userTurn = 0; // Player has no turn
    else if (playerColor == PlayerColor::Red)
        _userTurn = 1;
    else
        _userTurn = 2;

    // Player 1 or Red player
    if (playerColor == PlayerColor::Black)
        _player2Color = PlayerColor::Black;
    else
        _player2Color = PlayerColor::White;

    setupWinSprite();    
    setDepthOfSearch(6);
}

Game::~Game()
{
    if(_gfx.isOpen())
        _gfx.close();
}

void Game::run()
{
    while (_gfx.isOpen())
    {
        sf::Event event;
        while (_gfx.pollEvent(event))
        {            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (_gameOver) // If mouse click and the game is over
                    return;
                if (_userTurn == _turn)
                    setSelectedIndex();
            }

            if (event.type == sf::Event::Closed)
                _gfx.close();
        }

        // Get possible piece moves
        getMoves();

        // Game over
        winCheck();

        drawSelf();
        conductMoves();
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

void Game::setupWinSprite()
{
    if (!_winTexture.loadFromFile("WinMessage.png"))
        std::cout << "Error in winTexture image load" << std::endl;

    _winSprite.setTexture(_winTexture);
}
void Game::winDisplay()
{
    _gfx.draw(_winSprite);
}
void Game::winDisplaySet(PlayerColor playerColor)
{   
    sf::Vector2<int> rectArea(104, 20);
    sf::Vector2<int> position(0, 0);
    sf::IntRect areaToDisplay(position, rectArea);
    switch (playerColor)
    {
    case Game::PlayerColor::Red:
        // The area of the texture that needs to be displayed is set to Red by default
        break;
    case Game::PlayerColor::Black:
        position.y = 20;
        areaToDisplay = sf::IntRect(position, rectArea);
        break;
    case Game::PlayerColor::White:
        position.y = 40;
        areaToDisplay = sf::IntRect(position, rectArea);
        break;
    default:
        std::cout << "Error in winDisplaySetup() PlayerColor is invalid" << std::endl;
        break;
    }

    _winSprite.setTextureRect(areaToDisplay);
    _winSprite.setScale(2.0f, 2.0f);
    // Scaling for the whole window happens later. So here we use the default window size (the initial window size).
    _winSprite.setPosition((_board.getBoardLength() - rectArea.x * _winSprite.getScale().x) / 2,
                           (_board.getBoardLength() - rectArea.y * _winSprite.getScale().y) / 2);
}
void Game::winCheck()
{ 
    if (_possibleMoves.empty() && !_gameOver)
    {
        if (_turn == 2) // Black/White can't play
        {
            winDisplaySet(PlayerColor::Red);
            std::cout << "Red Wins" << std::endl;
        }
        else // Red can't play
        {
            if (_player2Color == PlayerColor::Black)
            {
                winDisplaySet(PlayerColor::Black);
                std::cout << "Black Wins" << std::endl;
            }
            else
            {
                winDisplaySet(PlayerColor::White);
                std::cout << "White Wins" << std::endl;
            }
        }        
        _gameOver = true;
        _stats.updateRawGameDataSheet(_turn, _userTurn);
        _stats.displayStats();
    }
}

void Game::drawSelf()
{
    _gfx.clear();
    _board.drawSelf(_gfx);
    displayMoves();
    if(_gameOver)
        winDisplay();
    _gfx.display();
}
// Returns true if player2's color is black
bool Game::setPlayer2Color(PlayerColor playerColor, PlayerColor team2Color)
{
    if (playerColor <= PlayerColor::Red)
        return (int(team2Color) + 1) % 2;
    else
        return (int(playerColor) + 1) % 2;
}
void Game::getMoves()
{
    if (!_gameOver)
    {
        // Get possible piece moves
        if (!areAdditionalJumps())
        {
            // Don't generate new moves if a move has yet to be made
            if (_possibleMoves.empty())
                _board.generateMoves(_possibleMoves, _turn);
        }
        else
            loadAdditionalJumps();
    }
}
void Game::conductMoves()
{
    if (!_gameOver)
    {
        if (isUserTurn())
            userInputHandle();
        else
        {
            Sleep(200);
            makeMiniMaxMove();

            drawSelf();
            Sleep(200);
        }
    }
}

void Game::setSelectedIndex()
{
    auto pos = (sf::Mouse::getPosition() - _gfx.getPosition()) + sf::Vector2i(-8, -31);
    if (pos.x >= 0 && pos.x < (int)_gfx.getSize().x)
        if (pos.y >= 0 && pos.y < (int)_gfx.getSize().y)
        {
            pos.x /= ((int)_gfx.getSize().x / 8);
            pos.y /= ((int)_gfx.getSize().y / 8);
            _userSelectedIndex = _board.xyToIndex(pos.x, pos.y);
        }
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
    return _userTurn == _turn;
}
void Game::makeUserMove()
{
    if (_possibleMoves.size() > 0)
    {
        finalizeMove();
    }
}
// True if the move given is in the possible moves
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

// returns difference of piece values with respect to teamTurn
float Game::boardEvaluate(const std::vector<PieceType> tiles, int teamTurn)
{
    ++_evaluationCalls;
    float evaluation = 0.0f;
    for (size_t index = 0; index < tiles.size(); index++)
    {
        switch (tiles[index])
        {
        case PieceType::NoPiece:
            break;
        case PieceType::Player1_Pawn:
            evaluation += _pawnWeight;
            break;
        case PieceType::Player2_Pawn:
            evaluation -= _pawnWeight;
            break;
        case PieceType::Player1_King:
            evaluation += _kingWeight;
            break;
        case PieceType::Player2_King:
            evaluation -= _kingWeight;
            break;
        default:
            break;
        }
    }
    if (teamTurn == 2)
        evaluation = -evaluation;
    return evaluation;
}
// Recursively makes boards and evaluates them. Returns the minimum and maximum boardEvaluations made
float Game::miniMax(Board& board, const int teamTurn, const int depth, const bool getMin)
{
    ++_miniMaxCalls;
    float minMax = 10000.0f;
    if (!getMin)
        minMax = -minMax;
    if (depth > 0)
    { 
        float holder;
        int jumpAdjustment = 0;
        std::vector<sf::Vector3<int>> possibleMoves;
        board.generateMoves(possibleMoves, teamTurn);

        if (possibleMoves.size() > 0) 
        {
            if (possibleMoves[0].z != -1) // Check if jump
                jumpAdjustment = 1;
            for (size_t i = 0; i < possibleMoves.size(); i++)
            {
                Board newBoard(Board::portrayMove(board.getBoardTiles(), possibleMoves[i]));
                holder = miniMax(newBoard, (teamTurn + 1) % 2, depth - 1 + jumpAdjustment, !getMin);

                if (getMin)
                {
                    if (holder < minMax)
                        minMax = holder;
                }
                else // GetMax
                {
                    if (holder > minMax)
                        minMax = holder;
                }
            }
            return minMax;
        }
        else // No moves available means game over
        {
            if (getMin)
            {
                return -1000.0f; // Win
            }
            else // GetMax
            {
                return 1000.0f; // Loss
            }
        }
    }
    else
        return boardEvaluate(board.getBoardTiles(), teamTurn);
}
// Returns the optimal move upon a DFS of x turns of possible moves
sf::Vector3<int> Game::miniMaxCall()
{
    std::vector<sf::Vector3<int>> optimalMove;
    float max = -10000.0f;
    float holder;

    int jumpAdjustment = 0;
    if (_possibleMoves[0].z != -1) // Check if jump
        jumpAdjustment = 1;

    // First depth call here
    if (_depthOfSearch > 0 && (int)_possibleMoves.size() > 1)
    {
        for (size_t i = 0; i < _possibleMoves.size(); i++)
        {
            Board newBoard(Board::portrayMove(_board.getBoardTiles(), _possibleMoves[i]));
            holder = miniMax(newBoard, (_turn + 1) % 2, _depthOfSearch - 1 + jumpAdjustment, false);

            std::cout << holder << "  (Initial Pos, Destination, Jumped index if not -1) { " << _possibleMoves[i].x << ", " << _possibleMoves[i].y << ", " << _possibleMoves[i].z << " }" << std::endl;


            if (holder > max || optimalMove.size() == 0)
            {
                optimalMove.clear();

                optimalMove.push_back(_possibleMoves[i]);
                max = holder;
            }
            if(holder == max)
                optimalMove.push_back(_possibleMoves[i]);
        }
    }
    else
        return _possibleMoves[(int(randPercent(gen) * float(int(_possibleMoves.size()) + 1))) % _possibleMoves.size()];
    // Return a random optimal move (for when several options seem eqaully optimal)
    return optimalMove[(int(randPercent(gen) * float(int(optimalMove.size()) + 1))) % optimalMove.size()];
}
// Sets the search depth of miniMaxCall()
void Game::setDepthOfSearch(int depthOfSearch)
{
    _depthOfSearch = depthOfSearch;
    _stats.setDepthOfSearch(depthOfSearch);
}

// Uses miniMax function to pick a move
void Game::makeMiniMaxMove()
{
    if (_possibleMoves.size() > 0)
    {
        _miniMaxCalls = 0;
        _evaluationCalls = 0;

        _latestMove = miniMaxCall();

        std::cout << "MiniMax calls: " << _miniMaxCalls << std::endl;
        std::cout << "BoardEvaluation calls: " << _evaluationCalls << std::endl;

        finalizeMove();
    }
}
void Game::finalizeMove()
{
    _stats.addTurnData(_possibleMoves.size(), _latestMove);
    _possibleMoves.clear();

    if (!_board.movePiece(_latestMove))
        if (_latestMove.z != -1) // We just jumped and no piece has been crowned
        {
            _board.getIndividualPieceMoves(_possibleAdditionalJumps, _latestMove.y, _turn, true);
            if (_possibleAdditionalJumps.size() > 0)
                return;
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
