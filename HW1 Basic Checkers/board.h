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

	void setup();
	void playerPieceDisplaySetup();
	
	void drawSelf(sf::RenderWindow& gfx);

private:
	void drawPiece(sf::RenderWindow& gfx, sf::Vector2<float> position, int tilesIndex);
	sf::Vector2<float> indexToPosition(int tileIndex);
public:

	std::vector<sf::Vector2<int>> generateMoves(int team);

	void movePiece(int currentLocation, int newLocation);
	void removePiece(int location);

	int getBoardLength();
	void setBoardLength(int newBoardLength);

	void setPieceScale(float newScale);

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

	size_t _length = 200;

	float _pieceScale = 1.0f;
	float _halfPieceLength = 16.0f;
	sf::Vector2<float> _pieceOffset = { 0.0f, 0.0f };
};




#endif // !BOARD_H
