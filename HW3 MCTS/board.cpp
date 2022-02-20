/* board.cpp
Nathan Damon
CS 405
1/18/2022
This is the source file for the board class.
*/

#include "board.h"



// Static variables


// Display
sf::Texture Board::_boardTexture;
sf::Sprite Board::_boardSprite;

sf::Texture Board::_player1PiecePawnTexture;
sf::Texture Board::_player2PiecePawnTexture;
sf::Texture Board::_player1PieceKingTexture;
sf::Texture Board::_player2PieceKingTexture;

sf::Sprite Board::_player1PiecePawn;
sf::Sprite Board::_player2PiecePawn;
sf::Sprite Board::_player1PieceKing;
sf::Sprite Board::_player2PieceKing;

size_t Board::_length = 256;
float Board::_tileWidth = 32.0f;

float Board::_pieceScale = 1.0f;
float Board::_halfPieceLength = 16.0f;
sf::Vector2<float> Board::_pieceOffset = { 0.0f, 0.0f };


// Movement
// For use with forloop for getToMoveIndex input
std::vector<int> Board::_upAndDownMoves = { 0, 1, 4, 5, 2, 3, 6, 7 };

std::vector<int> Board::_oddRowMoveOffsets = { -4, -3, 4, 5, -9, -7, 7, 9 };
std::vector<int> Board::_evenRowMoveOffsets = { -5, -4, 3, 4, -9, -7, 7, 9 };

// Board count
int Board::_boardCount = 0;



// Functions


Board::Board(bool player2IsBlack) : _tiles(std::vector<PieceType>(32, PieceType::NoPiece))
{
	setup();
	playerPieceDisplaySetup(player2IsBlack);

	if (!_boardTexture.loadFromFile("CheckerBoard.png"))
		std::cout << "Error in board image load" << std::endl;

	_boardSprite.setTexture(_boardTexture);
	++_boardCount;
}

Board::Board(std::vector<PieceType> tiles) : _tiles(tiles)
{
	++_boardCount;
}

Board::~Board()
{
	--_boardCount;
}


void Board::setup()
{
	for (size_t i = 0; i < _tiles.size(); i++)
	{
		if(i < 12)					// Top of board
			_tiles[i] = PieceType::Player1_Pawn;
		else if (i >= 12 && i < 20)	// Middle of board
			_tiles[i] = PieceType::NoPiece;
		else						// Bottom of board
			_tiles[i] = PieceType::Player2_Pawn;
	}
}
void Board::setup(std::vector<PieceType>& newTiles)
{
	_tiles = newTiles;
}

// Piece diplay setup
void Board::playerPieceDisplaySetup(bool player2IsBlack)
{
	bool textureTest = true;
	if (!_player1PiecePawnTexture.loadFromFile("RedPawnBase.png"))
		textureTest = false;

	// Black or White Piece
	if (player2IsBlack)
	{
		if (!_player2PiecePawnTexture.loadFromFile("BlackPawnBase.png"))
			textureTest = false;
	}
	else
	{
		if (!_player2PiecePawnTexture.loadFromFile("WhitePawnBase.png"))
			textureTest = false;
	}


	if (!_player1PieceKingTexture.loadFromFile("RedKing.png"))
		textureTest = false;

	// Black or White King
	if (player2IsBlack)
	{
		if (!_player2PieceKingTexture.loadFromFile("BlackKing.png"))
			textureTest = false;
	}
	else 
	{
		if (!_player2PieceKingTexture.loadFromFile("WhiteKing.png"))
			textureTest = false;
	}

	if (!textureTest)
		std::cout << "Error in piece image load" << std::endl;



	_player1PiecePawn.setTexture(_player1PiecePawnTexture);
	_player2PiecePawn.setTexture(_player2PiecePawnTexture);

	_player1PieceKing.setTexture(_player1PieceKingTexture);
	_player2PieceKing.setTexture(_player2PieceKingTexture);

	setPieceScale(0.8f);
}

void Board::drawSelf(sf::RenderWindow& gfx)
{
	gfx.draw(_boardSprite);
	for (size_t i = 0; i < _tiles.size(); i++)
	{
		drawPiece(gfx, indexToPosition(i) * float(getBoardLength()) / 8.0f + _pieceOffset, i);
	}
}

void Board::drawPiece(sf::RenderWindow& gfx, sf::Vector2<float> position, int tilesIndex)
{
	switch (_tiles[tilesIndex])
	{
	case PieceType::NoPiece:
		break;
	case PieceType::Player1_Pawn:
		_player1PiecePawn.setPosition(position);
		gfx.draw(_player1PiecePawn);
		break;
	case PieceType::Player2_Pawn:
		_player2PiecePawn.setPosition(position);
		gfx.draw(_player2PiecePawn);
		break;
	case PieceType::Player1_King:
		_player1PieceKing.setPosition(position);
		gfx.draw(_player1PieceKing);
		break;
	case PieceType::Player2_King:
		_player2PieceKing.setPosition(position);
		gfx.draw(_player2PieceKing);
		break;
	default:
		break;
	}		
}

void Board::pieceTypeToCout(PieceType pieceType) {
	switch (pieceType)
	{
	case PieceType::NoPiece:
		std::cout << "NoPiece";
		break;
	case PieceType::Player1_Pawn:
		std::cout << "Player1_Pawn";
		break;
	case PieceType::Player2_Pawn:
		std::cout << "Player2_Pawn";
		break;
	case PieceType::Player1_King:
		std::cout << "Player1_King";
		break;
	case PieceType::Player2_King:
		std::cout << "Player2_King";
		break;
	default:
		break;
	}
};


sf::Vector2<float> Board::indexToPosition(int tileIndex)
{
	int x = tileIndex % 4;
	int y = tileIndex / 4;
	return sf::Vector2<float>(float(x * 2 + (1 - y % 2)), float(y));
}
int Board::xyToIndex(int x, int y)
{
	// 4 * 8 board
	return y * 4 + x / 2;
}
sf::Vector2<int> Board::indexToXY(int tileIndex)
{
	return sf::Vector2<int>(tileIndex % 4, tileIndex / 4);
}

// {-1, -1, -1} if invalid, otherwise returns {from, to, pieceJumpedIndex}
sf::Vector3<int> Board::getMoveToIndex(int tileIndex, int movement)
{
	int moveTo = -1; // invalid index
	sf::Vector3<int> invalidMove(-1, -1, -1);
	if ((tileIndex / 4) % 2 == 0) // If on an odd row (includes Top row)
		moveTo = tileIndex + _oddRowMoveOffsets[movement];
	else
		moveTo = tileIndex + _evenRowMoveOffsets[movement];

	if (moveTo >= (int)_tiles.size() || moveTo < 0 // 
		|| movement < 4 && abs((tileIndex / 4) - (moveTo / 4)) != 1 // Difference of rows
		|| movement >= 4 && abs((tileIndex / 4) - (moveTo / 4)) != 2) // Difference of rows
		return invalidMove;
	else
	{
		if (_tiles[moveTo] != PieceType::NoPiece)
			return invalidMove;

		// Check the jumped piece
		if (movement >= 4)
		{				
			if ((tileIndex / 4) % 2 == 0) // If on an odd row (includes Top row)
			{
				// Piece being jumped is not on the jumper's team
				if (_tiles[tileIndex + _oddRowMoveOffsets[movement - 4]] != PieceType::NoPiece && int(_tiles[tileIndex + _oddRowMoveOffsets[movement - 4]]) % 2 != int(_tiles[tileIndex]) % 2)
				{		
					return { tileIndex, moveTo, tileIndex + _oddRowMoveOffsets[movement - 4] };
				}
				else
					return invalidMove;
			}
			else // If on an even row (includes Bottom row)
			{
				// Piece being jumped is not on the jumper's team
				if (_tiles[tileIndex + _evenRowMoveOffsets[movement - 4]] != PieceType::NoPiece && int(_tiles[tileIndex + _evenRowMoveOffsets[movement - 4]]) % 2 != int(_tiles[tileIndex]) % 2)
				{			
					return { tileIndex, moveTo, tileIndex + _evenRowMoveOffsets[movement - 4] };
				}
				else
					return invalidMove;
			}
		}
		

		return { tileIndex, moveTo, -1 };
	}

}

void Board::setPieceScale(float newScale)
{
	_pieceScale = newScale;
	_pieceOffset = { float(_length) / 16.0f - (_halfPieceLength * _pieceScale), float(_length) / 16.0f - (_halfPieceLength * _pieceScale) };

	// Pawns
	_player1PiecePawn.setScale(_pieceScale, _pieceScale);
	_player2PiecePawn.setScale(_pieceScale, _pieceScale);

	// Kings
	_player1PieceKing.setScale(_pieceScale, _pieceScale);
	_player2PieceKing.setScale(_pieceScale, _pieceScale);
}

std::vector<PieceType>& Board::getBoardTiles()
{
	return _tiles;
}
const int Board::getBoardLength()
{
	return _length;
}
const float Board::getTileWidth()
{
	return _tileWidth;
}
const sf::Vector2<float> Board::getPieceOffset()
{
	return _pieceOffset;
}
const float Board::getHalfPieceLength()
{
	return _halfPieceLength;
}
void Board::setBoardLength(int newBoardLength)
{
	_length = newBoardLength;
	_tileWidth = float(newBoardLength) / 8.0f;
	_pieceOffset = { float(_length) / 16.0f - (_halfPieceLength * _pieceScale), float(_length) / 16.0f - (_halfPieceLength * _pieceScale) };
}
const int Board::getBoardCount()
{
	return _boardCount;
}

// Finds the moves of a given piece (looks for jumps if getJumps is true or regular moves if false)
void Board::getIndividualPieceMoves(std::vector<sf::Vector3<int>>& moves, int index, int teamTurn, bool getJumps)
{
	int jumpMoveIndexOffset = 0;
	if (getJumps)
		jumpMoveIndexOffset = 2;

	if (_tiles[index] != PieceType::NoPiece && int(_tiles[index]) % 2 == teamTurn % 2)
	{
		sf::Vector3<int> move;
		if (_tiles[index] != PieceType::Player1_Pawn) // It is player2_Pawn, Player1_King, or Player2_King
		{
			// Look at moves directed up
			for (int i = jumpMoveIndexOffset; i < 2 + jumpMoveIndexOffset; i++) // 4 moves up possible (second 2 are jumps)
			{
				move = getMoveToIndex(index, _upAndDownMoves[i]);
				if (move.x != -1) // Not invalid
					moves.push_back(move);
			}
		}

		if (_tiles[index] != PieceType::Player2_Pawn) // It is player1_Pawn, Player1_King, or Player2_King
		{
			// Look at moves directed down
			for (int i = 4 + jumpMoveIndexOffset; i < 6 + jumpMoveIndexOffset; i++) // 4 moves up possible (second 2 are jumps)
			{
				move = getMoveToIndex(index, _upAndDownMoves[i]);
				if (move.x != -1) // Not invalid
					moves.push_back(move);
			}
		}
	}
}

void Board::generateMoves(std::vector<sf::Vector3<int>>& generatedMoves, int teamTurn)
{
	// Look for jumps
	for (size_t i = 0; i < _tiles.size(); i++)
		getIndividualPieceMoves(generatedMoves, i, teamTurn, true);

	// If no jumps
	if (generatedMoves.size() == 0)
	{
		// Get the regular moves
		for (size_t i = 0; i < _tiles.size(); i++)
			getIndividualPieceMoves(generatedMoves, i, teamTurn, false);
	}
}

// Returns a set of tiles with the given move made
std::vector<PieceType> Board::portrayMove(std::vector<PieceType>& tiles, const sf::Vector3<int>& move)
{
	std::vector<PieceType> newTiles = tiles;
	movePiece(newTiles, move);
	return newTiles;
}

// Returns true if a piece was crowned
bool Board::movePiece(sf::Vector3<int> move)
{
	return movePiece(_tiles, move);
}
bool Board::movePiece(std::vector<PieceType>& tiles, sf::Vector3<int> move)
{
	std::swap(tiles[move.x], tiles[move.y]);
	// Crowning
	bool didCrown = false;
	if (move.y < 4 && tiles[move.y] == PieceType::Player2_Pawn)
	{
		tiles[move.y] = PieceType::Player2_King;
		didCrown = true;
	}
	if (move.y > 27 && tiles[move.y] == PieceType::Player1_Pawn)
	{
		tiles[move.y] = PieceType::Player1_King;
		didCrown = true;
	}

	// Remove jumped piece
	removePiece(tiles, move.z);
	return didCrown;
}
void Board::removePiece(int location)
{
	removePiece(_tiles, location);
}
void Board::removePiece(std::vector<PieceType>& tiles, int location)
{
	if(location >= 0 && location < (int)tiles.size())
		tiles[location] = PieceType::NoPiece;
}
