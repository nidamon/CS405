/* board.h
Nathan Damon
CS 405
1/18/2022
This is the header file for the board class which handles the board.
*/

#ifndef BOARD_H
#define BOARD_H

#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>

enum class PieceType
{
	NoPiece,
	Player1_Pawn,
	Player2_Pawn,
	Player1_King,
	Player2_King,
};

class Board
{
public:
	Board();
	~Board();

	void drawSelf(sf::RenderWindow& gfx);

private:
	void setup();
	void playerPieceDisplaySetup();

	void drawPiece(sf::RenderWindow& gfx, sf::Vector2<float> position, int tilesIndex);

	void pieceTypeToCout(PieceType pieceType);

public:
	sf::Vector2<float> indexToPosition(int tileIndex);
	int xyToIndex(int x, int y);
	sf::Vector2<int> indexToXY(int tileIndex);

	// {-1, -1} if invalid, otherwise returns {from, to}
	sf::Vector3<int> getMoveToIndex(int tileIndex, int movement);
	//int getIndexInBetween(int indexFrom, int indexTo);

	void setPieceScale(float newScale);

	int getBoardLength();
	float getTileWidth();
	sf::Vector2<float> getPieceOffset();
	float getHalfPieceLength();
	void setBoardLength(int newBoardLength);
	   
	// Movement
	std::vector<sf::Vector3<int>> generateMoves(int team);

	void movePiece(sf::Vector3<int> move);
	void removePiece(int location);

private:
	// Function
	std::vector<PieceType> _tiles;

	// Display
	sf::Texture _boardTexture;
	sf::Sprite _boardSprite;

	sf::Texture _player1PiecePawnTexture;
	sf::Texture _player2PiecePawnTexture;
	sf::Texture _player1PieceKingTexture;
	sf::Texture _player2PieceKingTexture;

	sf::Sprite _player1PiecePawn;
	sf::Sprite _player2PiecePawn;
	sf::Sprite _player1PieceKing;
	sf::Sprite _player2PieceKing;

	size_t _length = 256;
	float _tileWidth = 32.0f;

	float _pieceScale = 1.0f;
	float _halfPieceLength = 16.0f;
	sf::Vector2<float> _pieceOffset = { 0.0f, 0.0f };


	// Movement
	// For use with forloop for getToMoveIndex input
	std::vector<int> _upAndDownMoves = { 0, 1, 4, 5, 2, 3, 6, 7 };

	std::vector<int> _oddRowMoveOffsets = { -4, -3, 4, 5, -9, -7, 7, 9 };
	std::vector<int> _evenRowMoveOffsets = { -5, -4, 3, 4, -9, -7, 7, 9 };
};




#endif // !BOARD_H
