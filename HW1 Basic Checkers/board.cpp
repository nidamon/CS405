/* board.cpp
Nathan Damon
CS 405
1/18/2022
This is the cpp file for the board class.
*/

#include "board.h"

Board::Board() : _tiles(std::vector<PieceType>(32, PieceType::NoPiece))
{
	setup();
	playerPieceDisplaySetup();

	if (!_boardTexture.loadFromFile("CheckerBoard.png"))
		std::cout << "Error in board image load" << std::endl;

	_boardSprite.setTexture(_boardTexture);
}

Board::~Board()
{
}


void Board::setup()
{
	for (size_t i = 0; i < _tiles.size(); i++)
	{
		if(i < 12)					// Top of board
			_tiles[i] = PieceType::Player1_King;
		else if (i >= 12 && i < 20)	// Middle of board
			_tiles[i] = PieceType::NoPiece;
		else						// Bottom of board
			_tiles[i] = PieceType::Player2_Pawn;
	}
}

// Piece diplay setup
void Board::playerPieceDisplaySetup()
{	
	_player1PiecePawn.setFillColor(sf::Color::Red);
	_player2PiecePawn.setFillColor(sf::Color::Black);

	_player1PieceKing.setFillColor(sf::Color::Red);
	_player1PieceKing.setOutlineColor(sf::Color::Yellow);
	_player1PieceKing.setOutlineThickness(2);

	_player2PieceKing.setFillColor(sf::Color::Black);
	_player2PieceKing.setOutlineColor(sf::Color::Yellow);
	_player2PieceKing.setOutlineThickness(2);
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

sf::Vector2<float> Board::indexToPosition(int tileIndex)
{
	int x = tileIndex % 4;
	int y = tileIndex / 4;
	return sf::Vector2<float>(float(x * 2 + (1 - y % 2)), float(y));
}

std::vector<sf::Vector2<int>> Board::generateMoves(int team)
{
	return std::vector<sf::Vector2<int>>();
}

void Board::movePiece(int currentLocation, int newLocation)
{
	std::swap(_tiles[newLocation], _tiles[currentLocation]);
}

void Board::removePiece(int location)
{
	_tiles[location] = PieceType::NoPiece;
}

int Board::getBoardLength()
{
	return _length;
}
void Board::setBoardLength(int newBoardLength)
{
	_length = newBoardLength;
	setPieceRadius(_length / 20.0f);
	_pieceOffset = { _length / 16.0f - _pieceRadius, _length / 16.0f - _pieceRadius };
}

void Board::setPieceRadius(float newSize)
{
	_pieceRadius = newSize;

	// Pawns
	_player1PiecePawn.setRadius(_pieceRadius);
	_player2PiecePawn.setRadius(_pieceRadius);

	// Kings
	_player1PieceKing.setRadius(_pieceRadius);
	_player2PieceKing.setRadius(_pieceRadius);
}