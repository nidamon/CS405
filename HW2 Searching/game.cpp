/* game.cpp
Nathan Damon
CS 405
1/18/2022
This is the source file for the game class.
*/

#include "game.h"

std::vector<std::vector<PieceType>> Game::_startingBoards = {
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn },
        { PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::Player1_Pawn, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::NoPiece, PieceType::Player1_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::NoPiece, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn, PieceType::Player2_Pawn }
};

// Remove
std::vector<std::string> Game::tournamentBoards = {
    { "rrrr-rrrrrrrr---b----bbbbbbbbbbb" },
    { "rrrrr-rrrrrrr---b----bbbbbbbbbbb" },
    { "rrrrrrrr--rrrr--b----bbbbbbbbbbb" },
    { "rrrrrrrr--rrr-r-b----bbbbbbbbbbb" },
    { "rrrrrrrr-r-rr-r-b----bbbbbbbbbbb" },
    { "rrrrrrrr-r-rr--rb----bbbbbbbbbbb" },
    { "rrrrrrrr-rr-r--rb----bbbbbbbbbbb" },
    { "rrrrrrrr-rrr--------brbbbbbbbbbb" },
    { "rrrr-rrrrrrrr----b--b-bbbbbbbbbb" },
    { "rrrrr-rrrrrrr----b--b-bbbbbbbbbb" },
    { "rrrrrrrr--rrrr---b--b-bbbbbbbbbb" },
    { "rrrrrrrr--rrr-r--b--b-bbbbbbbbbb" },
    { "rrrrrrrr-r-rr-r--b--b-bbbbbbbbbb" },
    { "rrrrrrrr-r-rr--r-b--b-bbbbbbbbbb" },
    { "rrrrrrrr-rr-r--r-b--b-bbbbbbbbbb" },
    { "rrrrrrrr-rrr----rb--b-bbbbbbbbbb" },
    { "rrrr-rrrrrrrr----b--bb-bbbbbbbbb" },
    { "rrrrr-rrrrrrr----b--bb-bbbbbbbbb" },
    { "rrrrrrrr--rrrr---b--bb-bbbbbbbbb" },
    { "rrrrrrrr--rrr-r--b--bb-bbbbbbbbb" },
    { "rrrrrrrr-r-rr-r--b--bb-bbbbbbbbb" },
    { "rrrrrrrr-r-rr--r-b--bb-bbbbbbbbb" },
    { "rrrrrrrr-rr-r--r-b--bb-bbbbbbbbb" },
    { "rrrrrrrr-rrr----rb--bb-bbbbbbbbb" },
    { "rrrr-rrrrrrrr-----b-bb-bbbbbbbbb" },
    { "rrrrr-rrrrrrr-----b-bb-bbbbbbbbb" },
    { "rrrrrrrr--rrrr----b-bb-bbbbbbbbb" },
    { "rrrrrrrr--rrr-r---b-bb-bbbbbbbbb" },
    { "rrrrrrrr-r-rr-r---b-bb-bbbbbbbbb" },
    { "rrrrrrrr-r-rr--r--b-bb-bbbbbbbbb" },
    { "rrrrrrrr-rr-r--r--b-bb-bbbbbbbbb" },
    { "rrrrrrrr-rrr----r-b-bb-bbbbbbbbb" },
    { "rrrr-rrrrrrrr-----b-bbb-bbbbbbbb" },
    { "rrrrr-rrrrrrr-----b-bbb-bbbbbbbb" },
    { "rrrrrrrr--rrrr----b-bbb-bbbbbbbb" },
    { "rrrrrrrr--rrr-r---b-bbb-bbbbbbbb" },
    { "rrrrrrrr-r-rr-r---b-bbb-bbbbbbbb" },
    { "rrrrrrrr-r-rr--r--b-bbb-bbbbbbbb" },
    { "rrrrrrrr-rr-r--r--b-bbb-bbbbbbbb" },
    { "rrrrrrrr-rrr----r-b-bbb-bbbbbbbb" },
    { "rrrr-rrrrrrrr------bbbb-bbbbbbbb" },
    { "rrrrr-rrrrrrr------bbbb-bbbbbbbb" },
    { "rrrrrrrr--rrrr-----bbbb-bbbbbbbb" },
    { "rrrrrrrr--rrr-r----bbbb-bbbbbbbb" },
    { "rrrrrrrr-r-rr-r----bbbb-bbbbbbbb" },
    { "rrrrrrrr-r-rr--r---bbbb-bbbbbbbb" },
    { "rrrrrrrr-rr-r--r---bbbb-bbbbbbbb" },
    { "rrrrrrrr-rrr----r--bbbb-bbbbbbbb" },
    { "rrrrrrrr-rrr--------rbbbbbbbbbbb" },
    { "rrrr-rrrrrrr-r--b---b-bbbbbbbbbb" },
    { "rrrrr-rrrrrr-r--b---b-bbbbbbbbbb" },
    { "rrrrrrrr--rr-rr-b---b-bbbbbbbbbb" },
    { "rrrrrrrr-r-r-rr-b---b-bbbbbbbbbb" },
    { "rrrrrrrr-r-r-r-rb---b-bbbbbbbbbb" },
    { "rrrrrrrr-rr--r-rb---b-bbbbbbbbbb" },
    { "rrrrrrrr-rrr----br--b-bbbbbbbbbb" },
    { "rrrr-rrrrrrr-r---b--b-bbbbbbbbbb" },
    { "rrrrr-rrrrrr-r---b--b-bbbbbbbbbb" },
    { "rrrrrrrr--rr-rr--b--b-bbbbbbbbbb" },
    { "rrrrrrrr-r-r-rr--b--b-bbbbbbbbbb" },
    { "rrrrrrrr-r-r-r-r-b--b-bbbbbbbbbb" },
    { "rrrrrrrr-rr--r-r-b--b-bbbbbbbbbb" },
    { "rrrrrrrr-rrr--------bbrbbbbbbbbb" },
    { "rrrr-rrrrrrr-r----b-bb-bbbbbbbbb" },
    { "rrrrr-rrrrrr-r----b-bb-bbbbbbbbb" },
    { "rrrrrrrr--rr-rr---b-bb-bbbbbbbbb" },
    { "rrrrrrrr-r-r-rr---b-bb-bbbbbbbbb" },
    { "rrrrrrrr-r-r-r-r--b-bb-bbbbbbbbb" },
    { "rrrrrrrr-rr--r-r--b-bb-bbbbbbbbb" },
    { "rrrrrrrr-rrr-----rb-bb-bbbbbbbbb" },
    { "rrrr-rrrrrrr-r----b-bbb-bbbbbbbb" },
    { "rrrrr-rrrrrr-r----b-bbb-bbbbbbbb" },
    { "rrrrrrrr--rr-rr---b-bbb-bbbbbbbb" },
    { "rrrrrrrr-r-r-rr---b-bbb-bbbbbbbb" },
    { "rrrrrrrr-r-r-r-r--b-bbb-bbbbbbbb" },
    { "rrrrrrrr-rr--r-r--b-bbb-bbbbbbbb" },
    { "rrrrrrrr-rrr-----rb-bbb-bbbbbbbb" },
    { "rrrr-rrrrrrr-r-----bbbb-bbbbbbbb" },
    { "rrrrr-rrrrrr-r-----bbbb-bbbbbbbb" },
    { "rrrrrrrr--rr-rr----bbbb-bbbbbbbb" },
    { "rrrrrrrr-r-r-rr----bbbb-bbbbbbbb" },
    { "rrrrrrrr-r-r-r-r---bbbb-bbbbbbbb" },
    { "rrrrrrrr-rr--r-r---bbbb-bbbbbbbb" },
    { "rrrrrrrr-rrr-----r-bbbb-bbbbbbbb" },
    { "rrrrrrrrr-rr--------rbbbbbbbbbbb" },
    { "rrrrrr-rrrrr-r--b---b-bbbbbbbbbb" },
    { "rrrrrrrr--rrrr--b---b-bbbbbbbbbb" },
    { "rrrrrrrrr--r-rr-b---b-bbbbbbbbbb" },
    { "rrrrrrrrr--r-r-rb---b-bbbbbbbbbb" },
    { "rrrrrrrrr-r--r-rb---b-bbbbbbbbbb" },
    { "rrrrrrrrr-rr----br--b-bbbbbbbbbb" },
    { "rrrrrr-rrrrr-r---b--b-bbbbbbbbbb" },
    { "rrrrrrrrr--r-rr--b--b-bbbbbbbbbb" },
    { "rrrrrrrrr--r-r-r-b--b-bbbbbbbbbb" },
    { "rrrrrrrrr-r--r-r-b--b-bbbbbbbbbb" },
    { "rrrrrrrrr-rr----rb--b-bbbbbbbbbb" },
    { "rrrrrrrrr-rr--------bbrbbbbbbbbb" },
    { "rrrrrr-rrrrr-r----b-bb-bbbbbbbbb" },
    { "rrrrrrrrr--r-rr---b-bb-bbbbbbbbb" },
    { "rrrrrrrrr--r-r-r--b-bb-bbbbbbbbb" },
    { "rrrrrrrrr-r--r-r--b-bb-bbbbbbbbb" },
    { "rrrrrrrrr-rr----r-b-bb-bbbbbbbbb" },
    { "rrrrrrrrr-rr-----rb-bb-bbbbbbbbb" },
    { "rrrrrr-rrrrr-r----b-bbb-bbbbbbbb" },
    { "rrrrrrrrr--r-rr---b-bbb-bbbbbbbb" },
    { "rrrrrrrrr--r-r-r--b-bbb-bbbbbbbb" },
    { "rrrrrrrrr-r--r-r--b-bbb-bbbbbbbb" },
    { "rrrrrrrrr-rr----r-b-bbb-bbbbbbbb" },
    { "rrrrrrrrr-rr-----rb-bbb-bbbbbbbb" },
    { "rrrrrr-rrrrr-r-----bbbb-bbbbbbbb" },
    { "rrrrrrrrr--r-rr----bbbb-bbbbbbbb" },
    { "rrrrrrrrr--r-r-r---bbbb-bbbbbbbb" },
    { "rrrrrrrrr-r--r-r---bbbb-bbbbbbbb" },
    { "rrrrrrrrr-rr----r--bbbb-bbbbbbbb" },
    { "rrrrrrrrr-rr-----r-bbbb-bbbbbbbb" },
    { "rrrrr-rrrrrr--r-b----bbbbbbbbbbb" },
    { "rrrrrr-rrrrr--r-b----bbbbbbbbbbb" },
    { "rrrrrrrr--rr-rr-b----bbbbbbbbbbb" },
    { "rrrrrrrrr--r--rrb----bbbbbbbbbbb" },
    { "rrrrrrrrr-r---rrb----bbbbbbbbbbb" },
    { "rrrrrrrrr-rr----br---bbbbbbbbbbb" },
    { "rrrrrrrrr-rr----b-r--bbbbbbbbbbb" },
    { "rrrrr-rrrrrr--r-b---b-bbbbbbbbbb" },
    { "rrrrrr-rrrrr--r-b---b-bbbbbbbbbb" },
    { "rrrrrrrr--rrr-r-b---b-bbbbbbbbbb" },
    { "rrrrrrrrr--r--rrb---b-bbbbbbbbbb" },
    { "rrrrrrrrr-r---rrb---b-bbbbbbbbbb" },
    { "rrrrrrrrr-rr----b-r-b-bbbbbbbbbb" },
    { "rrrrrrrrr-rr--------brbbbbbbbbbb" },
    { "rrrrr-rrrrrr--r--b--bb-bbbbbbbbb" },
    { "rrrrrr-rrrrr--r--b--bb-bbbbbbbbb" },
    { "rrrrrrrr--rr-rr--b--bb-bbbbbbbbb" },
    { "rrrrrrrrr--r--rr-b--bb-bbbbbbbbb" },
    { "rrrrrrrrr-r---rr-b--bb-bbbbbbbbb" },
    { "rrrrrrrrr-rr-----br-bb-bbbbbbbbb" },
    { "rrrrr-rrrrrr--r---b-bb-bbbbbbbbb" },
    { "rrrrrr-rrrrr--r---b-bb-bbbbbbbbb" },
    { "rrrrrrrrr--r--rr--b-bb-bbbbbbbbb" },
    { "rrrrrrrrr-r---rr--b-bb-bbbbbbbbb" },
    { "rrrrrrrrr-rr--------bbbrbbbbbbbb" },
    { "rrrrr-rrrrrr--r----bbbb-bbbbbbbb" },
    { "rrrrrr-rrrrr--r----bbbb-bbbbbbbb" },
    { "rrrrrrrrr--r--rr---bbbb-bbbbbbbb" },
    { "rrrrrrrrr-r---rr---bbbb-bbbbbbbb" },
    { "rrrrrrrrr-rr------rbbbb-bbbbbbbb" },
    { "rrrrrrr-rrrr--r-b----bbbbbbbbbbb" },
    { "rrrrrrrr-r-r-rr-b----bbbbbbbbbbb" },
    { "rrrrrrrrr--r-rr-b----bbbbbbbbbbb" },
    { "rrrrrrrrrr----rrb----bbbbbbbbbbb" },
    { "rrrrrrrrrr-r----br---bbbbbbbbbbb" },
    { "rrrrrrrrrr-r----b-r--bbbbbbbbbbb" },
    { "rrrrrrr-rrrr--r-b---b-bbbbbbbbbb" },
    { "rrrrrrrr-r-rr-r-b---b-bbbbbbbbbb" },
    { "rrrrrrrrrr----rrb---b-bbbbbbbbbb" },
    { "rrrrrrrrrr-r----br--b-bbbbbbbbbb" },
    { "rrrrrrrrrr-r----b-r-b-bbbbbbbbbb" },
    { "rrrrrrrrrr-r--------brbbbbbbbbbb" },
    { "rrrrrrr-rrrr--r--b--bb-bbbbbbbbb" },
    { "rrrrrrrr-r-r-rr--b--bb-bbbbbbbbb" },
    { "rrrrrrrrr--r-rr--b--bb-bbbbbbbbb" },
    { "rrrrrrrrrr----rr-b--bb-bbbbbbbbb" },
    { "rrrrrrrrrr-r-----br-bb-bbbbbbbbb" },
    { "rrrrrrr-rrrr--r---b-bb-bbbbbbbbb" },
    { "rrrrrrrrrr----rr--b-bb-bbbbbbbbb" },
    { "rrrrrrrrrr-r-----rb-bb-bbbbbbbbb" },
    { "rrrrrrrrrr-r--------bbbrbbbbbbbb" },
    { "rrrrrrr-rrrr--r----bbbb-bbbbbbbb" },
    { "rrrrrrrrrr----rr---bbbb-bbbbbbbb" },
    { "rrrrrrrrrr-r-----r-bbbb-bbbbbbbb" },
    { "rrrrrrrrrr-r------rbbbb-bbbbbbbb" },
    { "rrrrrr-rrrrr---rb----bbbbbbbbbbb" },
    { "rrrrrrr-rrrr---rb----bbbbbbbbbbb" },
    { "rrrrrrrr-r-r-r-rb----bbbbbbbbbbb" },
    { "rrrrrrrrr--r-r-rb----bbbbbbbbbbb" },
    { "rrrrrrrrrr-r----b--r-bbbbbbbbbbb" },
    { "rrrrrr-rrrrr---rb---b-bbbbbbbbbb" },
    { "rrrrrrr-rrrr---rb---b-bbbbbbbbbb" },
    { "rrrrrrrr-r-rr--rb---b-bbbbbbbbbb" },
    { "rrrrrrrrrr-r----b--rb-bbbbbbbbbb" },
    { "rrrrrr-rrrrr---r-b--b-bbbbbbbbbb" },
    { "rrrrrrr-rrrr---r-b--b-bbbbbbbbbb" },
    { "rrrrrrrrr--r--rr-b--b-bbbbbbbbbb" },
    { "rrrrrrrrrr-r-----br-b-bbbbbbbbbb" },
    { "rrrrrrrrrr-r-----b-rb-bbbbbbbbbb" },
    { "rrrrrr-rrrrr---r-b--bb-bbbbbbbbb" },
    { "rrrrrrr-rrrr---r-b--bb-bbbbbbbbb" },
    { "rrrrrrrr-r-r-r-r-b--bb-bbbbbbbbb" },
    { "rrrrrrrrr--r-r-r-b--bb-bbbbbbbbb" },
    { "rrrrrrrrrr-r-----b-rbb-bbbbbbbbb" },
    { "rrrrrrrrrr-r--------bbrbbbbbbbbb" },
    { "rrrrrr-rrrrr---r--b-bbb-bbbbbbbb" },
    { "rrrrrrr-rrrr---r--b-bbb-bbbbbbbb" },
    { "rrrrrrrrr--r--rr--b-bbb-bbbbbbbb" },
    { "rrrrrrrrrr-r------brbbb-bbbbbbbb" },
    { "rrrrrr-rrrrr---r---bbbb-bbbbbbbb" },
    { "rrrrrrr-rrrr---r---bbbb-bbbbbbbb" },
    { "rrrrrrrr-rr--r-rb----bbbbbbbbbbb" },
    { "rrrrrrrrr-r--r-rb----bbbbbbbbbbb" },
    { "rrrrrrrrrrr-----b-r--bbbbbbbbbbb" },
    { "rrrrrrrrrrr-----b--r-bbbbbbbbbbb" },
    { "rrrrrrrr-rr-r--rb---b-bbbbbbbbbb" },
    { "rrrrrrrrrrr-----b-r-b-bbbbbbbbbb" },
    { "rrrrrrrrrrr-----b--rb-bbbbbbbbbb" },
    { "rrrrrrrrr-r---rr-b--b-bbbbbbbbbb" },
    { "rrrrrrrrrr----rr-b--b-bbbbbbbbbb" },
    { "rrrrrrrrrrr------br-b-bbbbbbbbbb" },
    { "rrrrrrrrrrr------b-rb-bbbbbbbbbb" },
    { "rrrrrrrr-rr--r-r-b--bb-bbbbbbbbb" },
    { "rrrrrrrrr-r--r-r-b--bb-bbbbbbbbb" },
    { "rrrrrrrrrrr------br-bb-bbbbbbbbb" },
    { "rrrrrrrrrrr------b-rbb-bbbbbbbbb" },
    { "rrrrrrrrrrr---------bbrbbbbbbbbb" },
    { "rrrrrrrrr-r---rr--b-bbb-bbbbbbbb" },
    { "rrrrrrrrrr----rr--b-bbb-bbbbbbbb" },
    { "rrrrrrrrrrr-------brbbb-bbbbbbbb" },
    { "rrrrrrrrrrr-------rbbbb-bbbbbbbb" },
}; // boards end

// MiniMax piece weights
float Game::_pawnWeight = 1.0f;
float Game::_kingWeight = 1.5f;

int Game::_miniMaxCalls = 0;
int Game::_alphaBetaCalls = 0;
int Game::_evaluationCalls = 0;

sf::Texture Game::_winTexture;
sf::Sprite Game::_winSprite;


std::random_device r;
std::mt19937 gen(r());
std::uniform_real_distribution<float> randPercent(0.0f, 1.0f);

Game::Game(sf::RenderWindow& gfx, PlayerColor playerColor, sf::Vector2u boardsize, PlayerColor player2Color)
    : _board(setPlayer2Color(playerColor, player2Color)), _gfx(gfx)
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
    _difficulty = 1;
    setupRandomTournamentBoard();
}
Game::Game(sf::RenderWindow& gfx, PlayerColor playerColor, PlayerColor player2Color, bool tournamentMode, int difficulty, int difficultyDepth)
    : _board(setPlayer2Color(playerColor, player2Color)), _gfx(gfx), _difficulty(difficulty)
{
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
    if(difficulty == 1) // MuscleBrain
        setDepthOfSearch(difficultyDepth);
    if(tournamentMode)
        setupRandomTournamentBoard();
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
// Returns true if gameover
bool Game::runStep(bool mouseButtonPressed)
{
    if (mouseButtonPressed)
    {
        if (_gameOver) // If mouse click and the game is over
            return true;
        if (_userTurn == _turn)
            setSelectedIndex();
    }

    // Get possible piece moves
    getMoves();

    // Game over
    winCheck();

    drawSelf();
    conductMoves(200);

    return false;
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

void Game::enableDebugPrintout(bool doDebugPrintout)
{
    _doDebugPrintout = doDebugPrintout;
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
            switch (_difficulty)
            {
            case 0: // No Brainer
                makeRandomMove();
                break;
            case 1: // Muscle Head
                makeAlphaBetaMove(_doDebugPrintout);
                //makeMiniMaxMove(_doDebugPrintout);
                break;
            default:
                std::cout << "Making random moves as the difficulty selected is unavailable.\n";
                makeRandomMove(); // If nothing else, make it random!
                break;
            }
                

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
        ++_branchSplitCount;
        float valHolder;
        int jumpAdjustment = 0;

        std::vector<sf::Vector3<int>> possibleMoves;
        std::vector<sf::Vector3<int>> newAdditionalJumps;

        // Test all available moves
        getMoves(possibleMoves);
        _branchCount += (int)possibleMoves.size();
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
    return boardEvaluate(board.getBoardTiles(), maximizingTurn);
}
// Recursively makes boards and evaluates them with alpha beta cutoff. Returns the minimum and maximum boardEvaluations made
//float Game::alphaBeta(Board& board, const int turn, const int maximizingTurn, const int depth, std::vector<sf::Vector3<int>>& additionalJumps, float& a, float& b)
//{
//    int teamTurn = turn;
//    if (turn > 2)
//        teamTurn = turn - 2;
//    
//
//    auto getMoves = [&](std::vector<sf::Vector3<int>>& possibleMoves) {
//        if (additionalJumps.empty())
//            board.generateMoves(possibleMoves, teamTurn);
//        else
//            possibleMoves = additionalJumps;
//    };
//
//    ++_alphaBetaCalls;
//    float value = 1000.0f; // Get min
//    if (teamTurn == maximizingTurn)
//        value = -1000.0f; // Get max 
//
//    // Base case for recursion
//    if (depth > 0)
//    {
//        ++_branchSplitCount;
//        float valHolder;
//
//        std::vector<sf::Vector3<int>> possibleMoves;
//        std::vector<sf::Vector3<int>> newAdditionalJumps;
//
//        // Test all available moves
//        getMoves(possibleMoves);
//        _branchCount += (int)possibleMoves.size();
//
//        // Get the boards
//        std::vector<std::pair<Board, sf::Vector3<int>>> boardsAndMoves;
//        for (size_t i = 0; i < possibleMoves.size(); i++)
//            boardsAndMoves.push_back(std::make_pair(Board(Board::portrayMove(_board.getBoardTiles(), possibleMoves[i])), possibleMoves[i]));
//
//        std::sort(boardsAndMoves.begin(), boardsAndMoves.end(), [&teamTurn](std::pair<Board, sf::Vector3<int>>& boardA, std::pair<Board, sf::Vector3<int>>& boardB)
//            {return boardEvaluate(boardA.first.getBoardTiles(), teamTurn) > boardEvaluate(boardB.first.getBoardTiles(), teamTurn); });
//
//
//        for (size_t i = 0; i < boardsAndMoves.size(); i++)
//        {  
//            int jumpAdjustment = 0;
//            // Adjust for any jumps
//            if (boardsAndMoves[i].second.z != -1)
//                jumpAdjustment = 1;
//
//            int teamAdjustment = 0;
//            // Look for additional jumps after current jump
//            newAdditionalJumps.clear();
//            if (jumpAdjustment == 1)
//            {
//                boardsAndMoves[i].first.getIndividualPieceMoves(newAdditionalJumps, boardsAndMoves[i].second.y, teamTurn, true);
//                if (newAdditionalJumps.size() > 0)
//                    teamAdjustment = -1; // If can make another jump
//            }
//
//            // Recursion call
//            valHolder = alphaBeta(boardsAndMoves[i].first, (teamTurn + teamAdjustment + 1), maximizingTurn, depth - 1 + jumpAdjustment, newAdditionalJumps, a, b);
//
//            /*for (int i = 0; i < _depthOfSearch - (depth - 1 + jumpAdjustment); i++)
//                std::cout << "  ";
//            std::cout << "Team: " << teamTurn << "  ";
//            std::cout << valHolder << "  (Pos, Destination, Jumped) { " << boardsAndMoves[i].second.x << ", " << boardsAndMoves[i].second.y << ", " << boardsAndMoves[i].second.z << " }" << std::endl;*/
//
//            // Get new min or max
//            if (teamTurn == maximizingTurn) // Get Max
//            {
//                value = std::max(valHolder, value);
//                if (value >= b)
//                    break; // Beta cutoff
//                a = std::max(a, value);
//            }
//            else // Get Min
//            {
//                value = std::min(valHolder, value);
//                if (value <= a)
//                    break; // Alpha cutoff
//                b = std::min(b, value);
//            }
//        }
//        return value;
//    }
//    float evaluation = boardEvaluate(board.getBoardTiles(), maximizingTurn);
//
//    return evaluation;
//}

// Recursively makes boards and evaluates them with alpha beta cutoff. Returns the minimum and maximum boardEvaluations made
float Game::alphaBeta(Board& board, const int teamTurn, const int maximizingTurn, const int depth, std::vector<sf::Vector3<int>>& additionalJumps, float& a, float& b)
{
    auto getMoves = [&](std::vector<sf::Vector3<int>>& possibleMoves) {
        if (additionalJumps.empty())
            board.generateMoves(possibleMoves, teamTurn);
        else
            possibleMoves = additionalJumps;
    };

    ++_alphaBetaCalls;
    float value = 1000.0f; // Get min
    if (teamTurn == maximizingTurn)
        value = -1000.0f; // Get max 

    // Base case for recursion
    if (depth > 0)
    {
        ++_branchSplitCount;
        float valHolder;
        int jumpAdjustment = 0;

        std::vector<sf::Vector3<int>> possibleMoves;
        std::vector<sf::Vector3<int>> newAdditionalJumps;

        // Test all available moves
        getMoves(possibleMoves);
        _branchCount += (int)possibleMoves.size();
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
            valHolder = alphaBeta(newBoard, ((teamTurn + teamAdjustment + 1) % 2), maximizingTurn, depth - 1 + jumpAdjustment, newAdditionalJumps, a, b);

            // Get new min or max
            if (teamTurn == maximizingTurn) // Get Max
            {
                value = std::max(valHolder, value);
                if (value >= b)
                    break; // Beta cutoff
                a = std::max(a, value);
            }
            else // Get Min
            {
                value = std::min(valHolder, value);
                if (value <= a)
                    break; // Alpha cutoff
                b = std::min(b, value);
            }
        }
        return value;
    }
    return boardEvaluate(board.getBoardTiles(), maximizingTurn);
}

// Returns the optimal move upon a DFS of x turns of possible moves
sf::Vector3<int> Game::miniMaxCall(const std::vector<sf::Vector3<int>>& possibleMoves, int depthOfSearch, int turn, bool doPrintout)
{
    std::vector<sf::Vector3<int>> optimalMove;
    float max = -10000.0f;
    float holder;
    int jumpAdjustment = 0;

    if (possibleMoves[0].z != -1) // Check if jump
        jumpAdjustment = 1;

    _branchCount = 0;
    // First depth call here
    if (depthOfSearch > 0 && (int)possibleMoves.size() > 1)
    {  
        _branchSplitCount = 1;
        _branchCount += (int)possibleMoves.size();
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

            if(doPrintout)
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
sf::Vector3<int> Game::miniMaxCall(bool doPrintout)
{
    return miniMaxCall(_possibleMoves, _depthOfSearch, _turn, doPrintout);
}
// Returns the optimal move upon an alpha beta DFS of x turns of possible moves 2x to 5x and sometimes 10x faster although results are slightly different at times
//sf::Vector3<int> Game::alphaBetaCall(const std::vector<sf::Vector3<int>>& possibleMoves, int depthOfSearch, int turn, bool doPrintout)
//{
//    std::vector<sf::Vector3<int>> optimalMove;
//    float value = -10000.0f;
//    float holder;
//    int jumpAdjustment = 0;
//
//    float alpha = -10000.0f;
//    float beta = 10000.0f;
//
//    if (possibleMoves[0].z != -1) // Check if jump
//        jumpAdjustment = 1;
//
//    _branchCount = 0;
//    // First depth call here
//    if (depthOfSearch > 0 && (int)possibleMoves.size() > 1)
//    {
//        _branchSplitCount = 1;
//        _branchCount += (int)possibleMoves.size();
//
//        // Get the boards
//        std::vector<std::pair<Board, sf::Vector3<int>>> boardsAndMoves;
//        for (size_t i = 0; i < possibleMoves.size(); i++)
//            boardsAndMoves.push_back(std::make_pair(Board(Board::portrayMove(_board.getBoardTiles(), possibleMoves[i])), possibleMoves[i]));
//
//        std::sort(boardsAndMoves.begin(), boardsAndMoves.end(), [&turn](std::pair<Board, sf::Vector3<int>>& boardA, std::pair<Board, sf::Vector3<int>>& boardB) 
//            {return boardEvaluate(boardA.first.getBoardTiles(), turn) > boardEvaluate(boardB.first.getBoardTiles(), turn); });
//
//        for (size_t i = 0; i < boardsAndMoves.size(); i++)
//        {
//            int teamAdjustment = 0;
//            std::vector<sf::Vector3<int>> additionalJumps;
//            // Look for additional jumps
//            if (jumpAdjustment == 1)
//            {
//                boardsAndMoves[i].first.getIndividualPieceMoves(additionalJumps, boardsAndMoves[i].second.y, turn, true);
//                if (additionalJumps.size() > 0)
//                    teamAdjustment = -1;
//            }
//
//            holder = alphaBeta(boardsAndMoves[i].first, turn + teamAdjustment + 1, turn, depthOfSearch - 1 + jumpAdjustment, additionalJumps, alpha, beta);
//
//            std::cout << "Team: " << turn << "  ";
//            if(doPrintout)
//                std::cout << holder << "  (Pos, Destination, Jumped) { " << boardsAndMoves[i].second.x << ", " << boardsAndMoves[i].second.y << ", " << boardsAndMoves[i].second.z << " }" << std::endl;
//
//
//            if (holder > value || optimalMove.size() == 0)
//            {
//                optimalMove.clear();
//
//                optimalMove.push_back(boardsAndMoves[i].second);
//                value = holder;
//            }
//            if (holder == value)
//                optimalMove.push_back(boardsAndMoves[i].second);
//        }
//    }
//    else
//        return possibleMoves[(int(randPercent(gen) * float(int(possibleMoves.size()) + 1))) % possibleMoves.size()];
//    // Return a random optimal move (for when several options seem eqaully optimal)
//    return optimalMove[(int(randPercent(gen) * float(int(optimalMove.size()) + 1))) % optimalMove.size()];
//}

// Returns the optimal move upon an alpha beta DFS of x turns of possible moves 2x to 5x and sometimes 10x faster although results are slightly different at times
sf::Vector3<int> Game::alphaBetaCall(const std::vector<sf::Vector3<int>>& possibleMoves, int depthOfSearch, int turn, bool doPrintout)
{
    std::vector<sf::Vector3<int>> optimalMove;
    float value = -10000.0f;
    float holder;
    int jumpAdjustment = 0;

    float alpha = -10000.0f;
    float beta = 10000.0f;

    if (possibleMoves[0].z != -1) // Check if jump
        jumpAdjustment = 1;

    _branchCount = 0;
    // First depth call here
    if (depthOfSearch > 0 && (int)possibleMoves.size() > 1)
    {
        _branchSplitCount = 1;
        _branchCount += (int)possibleMoves.size();
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

            holder = alphaBeta(newBoard, ((turn + teamAdjustment + 1) % 2), turn % 2, depthOfSearch - 1 + jumpAdjustment, additionalJumps, alpha, beta);

            if (doPrintout)
                std::cout << holder << "  (Pos, Destination, Jumped) { " << possibleMoves[i].x << ", " << possibleMoves[i].y << ", " << possibleMoves[i].z << " }" << std::endl;


            if (holder > value || optimalMove.size() == 0)
            {
                optimalMove.clear();

                optimalMove.push_back(possibleMoves[i]);
                value = holder;
            }
            if (holder == value)
                optimalMove.push_back(possibleMoves[i]);
        }
    }
    else
        return possibleMoves[(int(randPercent(gen) * float(int(possibleMoves.size()) + 1))) % possibleMoves.size()];
    // Return a random optimal move (for when several options seem eqaully optimal)
    return optimalMove[(int(randPercent(gen) * float(int(optimalMove.size()) + 1))) % optimalMove.size()];
}
sf::Vector3<int> Game::alphaBetaCall(bool doPrintout)
{
    return alphaBetaCall(_possibleMoves, _depthOfSearch, _turn, doPrintout);
}

// Compares the results of the comparison between miniMaxCall() and alphaBetaCall()
void Game::alphaBetaMiniMaxCompare(bool doPrintout)
{
    if (_possibleMoves.size() > 0)
    {
        _miniMaxCalls = 0;
        _evaluationCalls = 0;

        sf::Vector3<int> latestMove1 = miniMaxCall(doPrintout);

        if (_miniMaxCalls > 0)
        {
            std::cout << "MiniMax calls: " << _miniMaxCalls << std::endl;
            std::cout << "BoardEvaluation calls: " << _evaluationCalls << std::endl;
        }

        _alphaBetaCalls = 0;
        _evaluationCalls = 0;

        sf::Vector3<int> latestMove2 = alphaBetaCall(doPrintout);

        if (_alphaBetaCalls > 0)
        {
            std::cout << "AlphaBeta calls: " << _alphaBetaCalls << std::endl;
            std::cout << "BoardEvaluation calls: " << _evaluationCalls << std::endl;
        }

        std::cout << "Moves are ";
        if (latestMove1 == latestMove2)
            std::cout << "the same.\n";
        else
            std::cout << "different!!!\n";
        std::cout << "AlphaBetaCall reduction: " << float(_miniMaxCalls - _alphaBetaCalls) / float(_miniMaxCalls) << "% of MiniMaxCall count\n";
    }
}
// Sets the search depth of miniMaxCall() and alphaBetaCall()
void Game::setDepthOfSearch(int depthOfSearch)
{
    _depthOfSearch = depthOfSearch;
    _stats.setDepthOfSearch(depthOfSearch);
}

// Randomly chooses an available move 
void Game::makeRandomMove()
{
    // Random
    if (_possibleMoves.size() > 0)
    {
        _latestMove = _possibleMoves[(int(randPercent(gen) * float(int(_possibleMoves.size()) + 1))) % _possibleMoves.size()];

        finalizeMove();
    }
}
// Uses miniMax function to pick a move
void Game::makeMiniMaxMove(bool doPrintout)
{
    if (_possibleMoves.size() > 0)
    {
        _miniMaxCalls = 0;
        _evaluationCalls = 0;

        _latestMove = miniMaxCall(doPrintout);

        if (_miniMaxCalls > 0)
        {
            std::cout << "MiniMax calls: " << _miniMaxCalls << std::endl;
            std::cout << "BoardEvaluation calls: " << _evaluationCalls << std::endl;
            std::cout << "Average branch factor: " << (float)_branchCount / (float)_branchSplitCount << std::endl;

        }

        finalizeMove();
    }
}
// Uses alphaBeta function to pick a move
void Game::makeAlphaBetaMove(bool doPrintout)
{
    if (_possibleMoves.size() > 0)
    {
        _alphaBetaCalls = 0;
        _evaluationCalls = 0;

        _latestMove = alphaBetaCall(doPrintout);

        if (_alphaBetaCalls > 0)
        {
            std::cout << "AlphaBeta calls: " << _alphaBetaCalls << std::endl;
            std::cout << "BoardEvaluation calls: " << _evaluationCalls << std::endl;
            std::cout << "Average branch factor: " << (float)_branchCount / (float)_branchSplitCount << std::endl;
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

// Sets up on of the 216 starting tournament boards
void Game::setupRandomTournamentBoard()
{    
    _board.setup(_startingBoards[(int(randPercent(gen) * float(int(_startingBoards.size()) + 1))) % _startingBoards.size()]);
    _turn = 2; // Player 2 goes next
}
// Generates the 216 starting tournament boards
void Game::tournamentBoardGen()
{    
    std::vector<std::vector<PieceType>> startingBoards;


    int teamTurn = 1;
    std::vector<sf::Vector3<int>> possibleMoves1;
    _board.generateMoves(possibleMoves1, teamTurn);


    for (size_t i = 0; i < possibleMoves1.size(); i++) // First set of moves
    {
        Board board2(Board::portrayMove(_board.getBoardTiles(), possibleMoves1[i]));
        teamTurn = 2;

        std::vector<sf::Vector3<int>> possibleMoves2;
        board2.generateMoves(possibleMoves2, teamTurn);

        for (size_t j = 0; j < possibleMoves2.size(); j++) // Second set of moves
        {
            Board board3(Board::portrayMove(board2.getBoardTiles(), possibleMoves2[j]));
            teamTurn = 1;

            std::vector<sf::Vector3<int>> possibleMoves3;
            board3.generateMoves(possibleMoves3, teamTurn);
            for (size_t k = 0; k < possibleMoves3.size(); k++) // Third set of moves
            {
                startingBoards.push_back(Board::portrayMove(board3.getBoardTiles(), possibleMoves3[k]));
            }
        }
    }

    _startingBoards.clear();
    std::copy_if(startingBoards.begin(), startingBoards.end(),
        std::back_inserter(_startingBoards),
        [&](const std::vector<PieceType>& newboard)
        {
            for (auto& board : _startingBoards)
            {
                if (newboard == board)
                    return false;
            }
            return true;
        }    
    );

    /*std::sort(_startingBoards.begin(), _startingBoards.end(), [](const std::vector<PieceType>& a, const std::vector<PieceType>& b) {return a < b; });
    std::unique(_startingBoards.begin(), _startingBoards.end());
    _startingBoards.erase(
        remove_if(_startingBoards.begin(), _startingBoards.end(),
            [](const std::vector<PieceType>& a) {return a.size() == 0; }), _startingBoards.end());*/
    

    /*std::cout << _startingBoards.size() << "\n";
    for (size_t i = 0; i < _startingBoards.size(); i++)
    {
        std::cout << "        { ";
        for (size_t j = 0; j < _startingBoards[i].size(); j++)
        {
            if (j != 0)
                std::cout << ", ";
            std::cout << "PieceType::";
            Board::pieceTypeToCout(_startingBoards[i][j]);
        }
        std::cout << " },\n";
    }*/

    std::cout << _startingBoards.size() << "\n";
    
    std::cout << "std::vector<std::string> boards = {\n";
    for (size_t i = 0; i < _startingBoards.size(); i++)
    {
        std::cout << "        { \"";
        for (size_t j = 0; j < _startingBoards[i].size(); j++)
        {
            switch (_startingBoards[i][j])
            {
            case PieceType::NoPiece:
                std::cout << "-";
                break;
            case PieceType::Player1_Pawn:
                std::cout << "r";
                break;
            case PieceType::Player2_Pawn:
                std::cout << "b";
                break;
            case PieceType::Player1_King:
                std::cout << "R";
                break;
            case PieceType::Player2_King:
                std::cout << "B";
                break;
            default:
                break;
            }
        }
        std::cout << "\" },\n";
    }
    std::cout << "}; // boards end\n";
}
