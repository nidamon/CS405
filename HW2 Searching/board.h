/* board.h
Nathan Damon
CS 405
1/18/2022
This is the header file for the board class which handles the board.
*/

#ifndef BOARD_H
#define BOARD_H

#include "stats.h"
#include <Windows.h>

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
	Board(bool player2IsBlack = true);
	Board(std::vector<PieceType> tiles);
	~Board();

	void drawSelf(sf::RenderWindow& gfx);

private:
	void setup();
	void playerPieceDisplaySetup(bool player2IsBlack);

	void drawPiece(sf::RenderWindow& gfx, sf::Vector2<float> position, int tilesIndex);

	void pieceTypeToCout(PieceType pieceType);

public:
	void setup(std::vector<PieceType>& newTiles);
	static sf::Vector2<float> indexToPosition(int tileIndex);
	static int xyToIndex(int x, int y);
	static sf::Vector2<int> indexToXY(int tileIndex);

	// {-1, -1} if invalid, otherwise returns {from, to}
	sf::Vector3<int> getMoveToIndex(int tileIndex, int movement);

	void setPieceScale(float newScale);

	std::vector<PieceType>& getBoardTiles();
	const int getBoardLength();
	const float getTileWidth();
	const sf::Vector2<float> getPieceOffset();
	const float getHalfPieceLength();
	void setBoardLength(int newBoardLength);
	const int getBoardCount();
	   
	// Movement
	// Finds the moves of a given piece (looks for jumps if getJumps is true or regular moves if false)
	void getIndividualPieceMoves(std::vector<sf::Vector3<int>>& moves, int index, int teamTurn, bool getJumps);
	void generateMoves(std::vector<sf::Vector3<int>>& generatedMoves, int teamTurn);
	// Returns a set of tiles with the given move made
	static std::vector<PieceType> portrayMove(std::vector<PieceType>& tiles, const sf::Vector3<int>& move);

	// Returns true if a piece was crowned
	bool movePiece(sf::Vector3<int> move);
	static bool movePiece(std::vector<PieceType>& tiles, sf::Vector3<int> move);
	void removePiece(int location);
	static void removePiece(std::vector<PieceType>& tiles, int location);

private:
	// Functional
	std::vector<PieceType> _tiles;

	// Display
	static sf::Texture _boardTexture;
	static sf::Sprite _boardSprite;

	static sf::Texture _player1PiecePawnTexture;
	static sf::Texture _player2PiecePawnTexture;
	static sf::Texture _player1PieceKingTexture;
	static sf::Texture _player2PieceKingTexture;

	static sf::Sprite _player1PiecePawn;
	static sf::Sprite _player2PiecePawn;
	static sf::Sprite _player1PieceKing;
	static sf::Sprite _player2PieceKing;

	static size_t _length;
	static float _tileWidth;

	static float _pieceScale;
	static float _halfPieceLength;
	static sf::Vector2<float> _pieceOffset;


	// Movement
	// For use with forloop for getToMoveIndex input
	static std::vector<int> _upAndDownMoves;

	static std::vector<int> _oddRowMoveOffsets;
	static std::vector<int> _evenRowMoveOffsets;

	// Board count
	static int _boardCount;
};




#endif // !BOARD_H
