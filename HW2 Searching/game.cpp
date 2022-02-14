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
    setDepthOfSearch(4);
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
        conductMoves(200);
    }
}
void Game::doTests()
{
    _isTesting = true;
    int testsPassed = 0;
    int startDepth = 2;
    int maxDepth = 4;

    PieceType _ = PieceType::NoPiece;
    PieceType r = PieceType::Player1_Pawn;
    PieceType b = PieceType::Player2_Pawn;
    PieceType R = PieceType::Player1_King;
    PieceType B = PieceType::Player2_King;

    // Long Multi-Jump test
    {
        std::vector<PieceType> testTiles = {
            _,    _,    _,    _,
         R,    _,    _,    _,
            b,    B,    _,    _,
         _,    _,    R,    _,
            b,    b,    b,    _,
         _,    _,    _,    _,
            _,    _,    b,    _,
         _,    _,    _,    _,
        };

        std::vector<PieceType> expectedResultTiles = {
            _,    _,    _,    _,
         R,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    R,    _,
        };

        std::vector<std::vector<PieceType>> finalBoards = { expectedResultTiles };

        for (int depth = startDepth; depth < maxDepth + 1; depth++)
            testsPassed += test("Long Multi-Jump test", testTiles, finalBoards, 1, 6, depth);

        std::cout << "\n\n";
    }
    // Move Piece out of way test
    {
        std::vector<PieceType> testTiles = {
            _,    _,    r,    r,
         r,    _,    r,    r,
            _,    r,    _,    b,
         r,    _,    b,    b,
            _,    _,    b,    b,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
        };

        std::vector<PieceType> expectedResultTiles = {
             _,    _,    r,    r,
         r,    _,    r,    r,
            _,    _,    _,    b,
         r,    r,    b,    b,
            _,    _,    b,    b,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
        };

        std::vector<std::vector<PieceType>> finalBoards = { expectedResultTiles };

        for (int depth = startDepth; depth < maxDepth + 1; depth++)
            testsPassed += test("Move Piece out of way test", testTiles, finalBoards, 1, 1, depth);

        std::cout << "\n\n";
    }
    // Block Piece test
    {
        std::vector<PieceType> testTiles = {
            _,    _,    B,    _,
         _,    B,    R,    _,
            _,    _,    _,    _,
         _,    _,    R,    _,
            _,    B,    _,    _,
         _,    B,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
        };

        std::vector<PieceType> expectedResultTiles = {
            _,    _,    B,    _,
         _,    B,    _,    _,
            _,    _,    R,    _,
         _,    _,    R,    _,
            _,    B,    _,    _,
         _,    B,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
        };

        std::vector<std::vector<PieceType>> finalBoards = { expectedResultTiles};

        for (int depth = startDepth; depth < maxDepth + 1; depth++)
            testsPassed += test("Block Piece test", testTiles, finalBoards, 1, 1, depth);

        std::cout << "\n\n";
    }
    // Don't Self Destruct test
    {
        std::vector<PieceType> testTiles = {
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    R,    _,    _,
         _,    _,    _,    _,
            _,    B,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
        };

        std::vector<PieceType> expectedResultTiles = {
            _,    _,    _,    _,
         _,    R,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    B,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
        };
        std::vector<PieceType> expectedResultTiles2 = {
            _,    _,    _,    _,
         _,    _,    R,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    B,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
        };

        std::vector<std::vector<PieceType>> finalBoards = { expectedResultTiles, expectedResultTiles2 };

        for (int depth = startDepth; depth < maxDepth + 1; depth++)
            testsPassed += test("Block Piece test", testTiles, finalBoards, 1, 1, depth);

        std::cout << "\n\n";
    }








        
        /*
        std::vector<PieceType> testTiles = {
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
        };
        std::vector<PieceType> expectedResultTiles = {
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
            _,    _,    _,    _,
         _,    _,    _,    _,
        };
        */

                                    
    //std::cout << "Depth of search: " << _depthOfSearch;
    if (testsPassed == _testCount)
        std::cout << "\nTests: All PASSED\n\n";
    else
        std::cout << "\nTests: " << _testCount - testsPassed << " FAILED, " << testsPassed << " PASSED\n\n";
}
int Game::test(std::string testName, std::vector<PieceType>& initialBoardTiles, std::vector<std::vector<PieceType>>& finalBoards, int turn, int movesToBeMade, int depth)
{
    std::cout << '\n';
    _depthOfSearch = depth;

    if (_gameOver)
        _gameOver = !_gameOver;
    ++_testCount;
    // Perform actions on initialBoardTiles that should get the finalBoardTiles
    setUpBoard(initialBoardTiles, turn);
    for (int movesMade = 0; movesMade < movesToBeMade; movesMade++)
    {
        // The turn isn't supposed to end until after the last iteration
        if (turn != _turn)
            break;
        getMoves();
        conductMoves(0);
    } 
    // Test it
    for (auto& finalBoard : finalBoards)
    {
        if (_board.getBoardTiles() == finalBoard)
            return 1;
    }
    // Failure upon not passing
    std::cout << testName + ": FAILED with depth search of " << _depthOfSearch << '\n';
    return 0;
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
        if (!_isTesting)
        {
            _stats.updateRawGameDataSheet(_turn, _userTurn);
            _stats.displayStats();
        }
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
void Game::setUpBoard(std::vector<PieceType>& tiles, int turn)
{
    _turn = turn;
    _board.setup(tiles);
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
void Game::conductMoves(DWORD sleepTime)
{
    if (!_gameOver)
    {
        if (isUserTurn())
            userInputHandle();
        else
        {
            if(_isTesting)
                drawSelf();
            if(sleepTime > 0)
                Sleep(sleepTime);
            makeMiniMaxMove();

            drawSelf();
            if (sleepTime > 0)
                Sleep(sleepTime);
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
    if (teamTurn % 2 == 0)
        evaluation = -evaluation;
    return evaluation;
}

// Recursively makes boards and evaluates them. Returns the minimum and maximum boardEvaluations made
float Game::miniMax(Board& board, const int teamTurn, const int maximizingTurn, const int depth, std::vector<sf::Vector3<int>>& additionalJumps)
{
    auto getMoves = [&](std::vector<sf::Vector3<int>>& possibleMoves) {
        if (additionalJumps.empty())
            board.generateMoves(possibleMoves, teamTurn);
        else
            possibleMoves = additionalJumps;
    };

    ++_miniMaxCalls;
    float minMax = 1000.0f; // Get min
    if (teamTurn == maximizingTurn)
        minMax = -1000.0f; // Get max 

    // Base case for recursion
    if (depth > 0)
    {
        float valHolder;
        int jumpAdjustment = 0;

        std::vector<sf::Vector3<int>> possibleMoves;
        std::vector<sf::Vector3<int>> newAdditionalJumps;

        // Test all available moves
        getMoves(possibleMoves);
        for (size_t i = 0; i < possibleMoves.size(); i++)
        {
            // Adjust for any jumps
            if (possibleMoves[0].z != -1)
                jumpAdjustment = 1;

            int teamAdjustment = 0;
            // Get a new board with new piece positions
            Board newBoard(Board::portrayMove(board.getBoardTiles(), possibleMoves[i]));

            // Look for additional jumps after current jump
            if (jumpAdjustment == 1)
            {
                newAdditionalJumps.clear();
                newBoard.getIndividualPieceMoves(newAdditionalJumps, possibleMoves[i].y, teamTurn, true);
                if (newAdditionalJumps.size() > 0)
                    teamAdjustment = -1; // If can make another jump
                else
                    jumpAdjustment = 0;
            }

            // Recursion call
            valHolder = miniMax(newBoard, ((teamTurn + teamAdjustment + 1) % 2), maximizingTurn, depth - 1 + jumpAdjustment, newAdditionalJumps);

            // Get new min or max
            if (teamTurn == maximizingTurn) // Get Max
                minMax = std::max(valHolder, minMax);
            else // Get Min
                minMax = std::min(valHolder, minMax);
        }
        return minMax;
    }
    return boardEvaluate(board.getBoardTiles(), teamTurn);
}

// Returns the optimal move upon a DFS of x turns of possible moves
sf::Vector3<int> Game::miniMaxCall(std::vector<sf::Vector3<int>>& possibleMoves, int depthOfSearch, int turn)
{
    std::vector<sf::Vector3<int>> optimalMove;
    float max = -10000.0f;
    float holder;
    int jumpAdjustment = 0;

    if (possibleMoves[0].z != -1) // Check if jump
        jumpAdjustment = 1;

    // First depth call here
    if (depthOfSearch > 0 && (int)possibleMoves.size() > 1)
    {
        for (size_t i = 0; i < possibleMoves.size(); i++)
        {
            int teamAdjustment = 0;
            Board newBoard(Board::portrayMove(_board.getBoardTiles(), possibleMoves[i]));

            std::vector<sf::Vector3<int>> additionalJumps;
            // Look for additional jumps
            if (jumpAdjustment == 1)
            {
                newBoard.getIndividualPieceMoves(additionalJumps, possibleMoves[i].y, turn, true);
                if (additionalJumps.size() > 0)
                    teamAdjustment = -1;
            }

            holder = miniMax(newBoard, ((turn + teamAdjustment + 1) % 2), turn % 2, depthOfSearch - 1 + jumpAdjustment, additionalJumps);

            std::cout << holder << "  (Pos, Destination, Jumped) { " << possibleMoves[i].x << ", " << possibleMoves[i].y << ", " << possibleMoves[i].z << " }" << std::endl;


            if (holder > max || optimalMove.size() == 0)
            {
                optimalMove.clear();

                optimalMove.push_back(possibleMoves[i]);
                max = holder;
            }
            if (holder == max)
                optimalMove.push_back(possibleMoves[i]);
        }
    }
    else
        return possibleMoves[(int(randPercent(gen) * float(int(possibleMoves.size()) + 1))) % possibleMoves.size()];
    // Return a random optimal move (for when several options seem eqaully optimal)
    return optimalMove[(int(randPercent(gen) * float(int(optimalMove.size()) + 1))) % optimalMove.size()];
}
sf::Vector3<int> Game::miniMaxCall()
{
    return miniMaxCall(_possibleMoves, _depthOfSearch, _turn);
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

        if (_miniMaxCalls > 0)
        {
            std::cout << "MiniMax calls: " << _miniMaxCalls << std::endl;
            std::cout << "BoardEvaluation calls: " << _evaluationCalls << std::endl;
        }

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
