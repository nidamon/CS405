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

// MiniMax piece weights
float Game::_pawnWeight = 1.0f;
float Game::_kingWeight = 1.5f;

int Game::_miniMaxCalls = 0;
int Game::_alphaBetaCalls = 0;
int Game::_evaluationCalls = 0;

sf::Texture Game::_winTexture;
sf::Sprite Game::_winSprite;

// File Mapping
Game::FileMappingVars Game::_fileMappingVars = { NULL, 0, NULL, sizeof(CheckersIPC) };

// MCTS_node - Monte Carlo Tree Search Node
int Game::MCTS_Node::_MCTS_currentNodeCount = 0;;
int Game::MCTS_Node::_MCTS_nodeCount = 0;

std::random_device r;
std::mt19937 gen(r());
std::uniform_real_distribution<float> randPercent(0.0f, 1.0f);

Game::Game(sf::RenderWindow& gfx, PlayerColor player1Color, sf::Vector2u boardsize, PlayerColor player2Color)
    : _board(setPlayer2Color(player1Color, player2Color)), _gfx(gfx), _currentGameLog(GameLogs::getNewGameLog())
{
    _gfx.setSize(boardsize);

    // Player 1 or Red player
    if (player1Color == PlayerColor::CPU_playerGame)
        _userTurn = 0; // Player has no turn
    else if (player1Color == PlayerColor::Red)
        _userTurn = 1;
    else
        _userTurn = 2;

    // Player 1 or Red player
    if (player2Color == PlayerColor::Black || player1Color == PlayerColor::Black)
        _player2Color = PlayerColor::Black;
    else
        _player2Color = PlayerColor::White;

    setupWinSprite();    
    setDepthOfSearch(4);
    _difficulty = 1;
    _currentGameLog._startingBoard = setupRandomTournamentBoard();

    // Current GameLog setup

    // If is black
    if (setPlayer2Color(player1Color, player2Color))
        _currentGameLog._p2Color = 'B';
    else
        _currentGameLog._p2Color = 'W';


}
Game::Game(sf::RenderWindow& gfx, PlayerColor player1Color, PlayerColor player2Color, bool tournamentMode, int difficulty, int difficultyDepth)
    : _board(setPlayer2Color(player1Color, player2Color)), _gfx(gfx), _difficulty(difficulty), _currentGameLog(GameLogs::getNewGameLog())
{
    // Player 1 or Red player
    if (player1Color == PlayerColor::CPU_playerGame)
        _userTurn = 0; // Player has no turn
    else if (player1Color == PlayerColor::Red)
        _userTurn = 1;
    else
        _userTurn = 2;

    //_userTurn = 0;

    // Player 1 or Red player
    if (player2Color == PlayerColor::Black || player1Color == PlayerColor::Black)
        _player2Color = PlayerColor::Black;
    else
        _player2Color = PlayerColor::White;

    setupWinSprite();
    if(difficulty == 1 || difficulty == 2) // MiniMax or Alpha beta
        setDepthOfSearch(difficultyDepth);
    if (difficulty == 3) // MCTS
        _timeAvailableInSeconds = float(difficultyDepth);
    if(tournamentMode)
        _currentGameLog._startingBoard = setupRandomTournamentBoard();

    // Current GameLog setup

    // If is black
    if(setPlayer2Color(player1Color, player2Color))
        _currentGameLog._p2Color = 'B';
    else
        _currentGameLog._p2Color = 'W';
}
Game::Game(sf::RenderWindow& gfx, PlayerColor p2Color, bool tournamentMode, int p1Mode, int p1DifficultyDepth, int p2Mode, int p2DifficultyDepth)
    : _board(setPlayer2Color(PlayerColor::Red, p2Color)) , _gfx(gfx), _difficulty(0), _currentGameLog(GameLogs::getNewGameLog()),
    _p1Mode(p1Mode), _p1Depth(p1DifficultyDepth), _p2Mode(p2Mode), _p2Depth(p2DifficultyDepth)
{
    if (p1Mode == 4) // Player 1 is user
        _userTurn = 1; 
    else if (p2Mode == 4) // Player 2 is user
        _userTurn = 2;
    else // Player has no turn
        _userTurn = 0;

    // Player 1 or Red player
    if (p2Color == PlayerColor::Black)
        _player2Color = PlayerColor::Black;
    else
        _player2Color = PlayerColor::White;

    setupWinSprite();    
    if (tournamentMode)
        _currentGameLog._startingBoard = setupRandomTournamentBoard();

    // Current GameLog setup

    // If player 2 is black
    if (setPlayer2Color(PlayerColor::Red, p2Color))
        _currentGameLog._p2Color = 'B';
    else
        _currentGameLog._p2Color = 'W';


    if (p1Mode == 5 || p2Mode == 5)
        if (getFileMappingVars()._mappedViewOfFile != nullptr && getFileMappingVars()._mappedViewOfFile->_training == true)
        {
            std::cout << "Training mode on!\n";
            _isNN_Training = true;
        }
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
    ++_turnCount;
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
            _currentGameLog._winnerColor = 'R';
        }
        else // Red can't play
        {
            if (_player2Color == PlayerColor::Black)
            {
                winDisplaySet(PlayerColor::Black);
                std::cout << "Black Wins" << std::endl;
                _currentGameLog._winnerColor = 'B';
            }
            else
            {
                winDisplaySet(PlayerColor::White);
                std::cout << "White Wins" << std::endl;
                _currentGameLog._winnerColor = 'W';
            }
        }        
        _gameOver = true;
        if (!_isTesting)
        {
            _currentGameLog._turnCount = _turnCount;
            if (_currentGameLog._gameNumber != -1)
                GameLogs::saveGameLog(_currentGameLog);
            else
            {
                std::cout << "Bad gameLog number (was -1)." << std::endl;
                std::cout << _currentGameLog.getStr() << std::endl;
            }
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
        else // Algorithms
        { 
            // Save values
            int difficultySave = _difficulty;
            int depthSave = _depthOfSearch;
            if (_turn == 1) // Player 1
            {
                _difficulty = _p1Mode;
                _depthOfSearch = _p1Depth;
            }
            else // Player 2
            {
                _difficulty = _p2Mode;
                _depthOfSearch = _p2Depth;
            }

            if (_difficulty == 3) // MCTS
                _timeAvailableInSeconds = float(_depthOfSearch);


            if(_isTesting)
                drawSelf();
            if(sleepTime > 0 && !_isNN_Training)
                Sleep(sleepTime);
            switch (_difficulty)
            {
            case 0: // pure Randomness
                makeRandomMove();
                break;
            case 1: // Alpha Beta
                makeMiniMaxMove(_doDebugPrintout);
                break;
            case 2: // Alpha Beta
                //alphaBetaMiniMaxCompare(true);
                makeAlphaBetaMove(_doDebugPrintout);
                break; 
            case 3: // Monte Carlo Tree Search
                makeMCTS_Move();
                break; 
            case 4: // Player that never plays here                
                break;
            case 5: // Neural Network
                makeNN_Move();
                break;
            default:
                std::cout << "Making random moves as the difficulty selected is unavailable.\n";
                makeRandomMove(); // If nothing else, make it random!
                break;
            }
                
            // Return to previous values
            _difficulty = difficultySave;
            _depthOfSearch = depthSave;


            drawSelf();
            if (sleepTime > 0 && !_isNN_Training)
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
float Game::biasedBoardEvaluate(const std::vector<PieceType> tiles, int teamTurn, float bias)
{
    ++_evaluationCalls;
    float evaluation = 0.0f;
    if (teamTurn % 2 == 0)
        bias = -bias;
    for (size_t index = 0; index < tiles.size(); index++)
    {
        switch (tiles[index])
        {
        case PieceType::NoPiece:
            break;
        case PieceType::Player1_Pawn:
            evaluation += _pawnWeight + bias;
            break;
        case PieceType::Player2_Pawn:
            evaluation -= _pawnWeight;
            break;
        case PieceType::Player1_King:
            evaluation += _kingWeight + bias;
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
float Game::miniMax(Board& board, const int teamTurn, const int maximizingTurn, const int depth, std::vector<sf::Vector3<int>>& additionalJumps, float biasForEvaluation)
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
            valHolder = miniMax(newBoard, ((teamTurn + teamAdjustment + 1) % 2), maximizingTurn, depth - 1 + jumpAdjustment, newAdditionalJumps, biasForEvaluation);

            // Get new min or max
            if (teamTurn == maximizingTurn) // Get Max
                minMax = std::max(valHolder, minMax);
            else // Get Min
                minMax = std::min(valHolder, minMax);
        }
        return minMax;
    }
    if(biasForEvaluation == 0.0f)
        return boardEvaluate(board.getBoardTiles(), maximizingTurn);
    else
        return biasedBoardEvaluate(board.getBoardTiles(), maximizingTurn, biasForEvaluation);
}

// Recursively makes boards and evaluates them with alpha beta cutoff. Returns the minimum and maximum boardEvaluations made
float Game::alphaBeta(Board& board, const int turn, const int maximizingTurn, const int depth, std::vector<sf::Vector3<int>>& additionalJumps, float& a, float& b)
{
    int teamTurn = turn;
    if (turn > 2)
        teamTurn = turn - 2;

    auto getMoves = [&](std::vector<sf::Vector3<int>>& possibleMoves) {
        if (additionalJumps.empty())
            board.generateMoves(possibleMoves, teamTurn);
        else
            possibleMoves = additionalJumps;
    };

    ++_alphaBetaCalls;
    float value = 1000.0f; 

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
        // Adjust for any jumps
        if (possibleMoves.size() > 0)
        {
            if (possibleMoves[0].z != -1)
                jumpAdjustment = 1;

            std::sort(possibleMoves.begin(), possibleMoves.end(),
                [&](const sf::Vector3<int>& a, const sf::Vector3<int>& b) {
                    return boardEvaluate(Board::portrayMove(board.getBoardTiles(), a), maximizingTurn)
                         > boardEvaluate(Board::portrayMove(board.getBoardTiles(), b), maximizingTurn);
                });
        }

        for (size_t i = 0; i < possibleMoves.size(); i++)
        {
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
            }

            /*newBoard.drawSelf(_gfx);  
            for (size_t i = 0; i < possibleMoves.size(); i++)
            {
                sf::VertexArray lines(sf::LinesStrip, 2);
                lines[0].position = _board.indexToPosition(possibleMoves[i].x) * _board.getTileWidth() + sf::Vector2<float>(_board.getBoardLength() / 16.0f, _board.getBoardLength() / 16.0f);
                lines[1].position = _board.indexToPosition(possibleMoves[i].y) * _board.getTileWidth() + sf::Vector2<float>(_board.getBoardLength() / 16.0f, _board.getBoardLength() / 16.0f);
                _gfx.draw(lines);
            }
            _gfx.display();
            Sleep(500);*/

            // Recursion call
            valHolder = alphaBeta(newBoard, (teamTurn + teamAdjustment + 1), maximizingTurn, depth - 1 + jumpAdjustment, newAdditionalJumps, a, b);

            if (value == 1000.0f)
                value = valHolder;

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
        if (possibleMoves.size() == 0)
            return boardEvaluate(board.getBoardTiles(), maximizingTurn);

        return value;
    }
    return boardEvaluate(board.getBoardTiles(), maximizingTurn);
}

float Game::getUCB(Game::MCTS_Node* node)
{
    if (node->getVisitCount() == 0)
        return INFINITY;
    auto avg = node->getScore() / float(node->getVisitCount());
    float c = 2.0f;
    auto N = float(node->getParentNode()->getVisitCount());
    auto n = float(node->getVisitCount());

    /*std::cout
        << " <> avg: " << std::setw(10) << avg
        << " N: " << std::setw(4) << N
        << " n: " << std::setw(4) << n;

    std::cout << " getUCB: " << avg + c * sqrtf(log1p(N) / n) << "\n"; */
    return avg + c * sqrtf(log(N) / n);
}

Game::MCTS_Node* Game::traverse(Game::MCTS_Node* node)
{
    while (node->isFullyExpanded())
        node = bestUCB(node);

    return node->getUnvisited();
}
Game::MCTS_Node* Game::bestUCB(Game::MCTS_Node* node)
{
    if (node->isNotTerminal())
    {
        MCTS_Node* bestChild = node->getChildrenNodes()[0].get();

        for (auto& child : node->getChildrenNodes())
        {
            //std::cout << "Comparing new: " << getUCB(child.get()) << " to old: " << getUCB(bestChild) << "\n";

            if (getUCB(child.get()) > getUCB(bestChild))
                bestChild = child.get();
        }
        //std::cout << "Result: " << getUCB(bestChild) << "\n";
        return bestChild;
    }
    return node;
}
// Make moves based on rollout policy till result
float Game::mCTS_Rollout(Game::MCTS_Node* node)
{
    if (node->isNotTerminal())
    {
        std::unique_ptr<Game::MCTS_Node>& saveRoller = rolloutPolicy(node);

        auto rolloutNode = saveRoller.get();
        while (rolloutNode->isNotTerminal())
        {
            /*Sleep(1000);
            _gfx.clear();
            rolloutNode->getBoard().drawSelf(_gfx);
            for (size_t i = 0; i < rolloutNode->getChildrenNodes().size(); i++)
            {
                sf::VertexArray lines(sf::LinesStrip, 2);
                lines[0].position = rolloutNode->getBoard().indexToPosition(rolloutNode->getChildrenNodes()[i]->getMovesMade().front().x) * rolloutNode->getBoard().getTileWidth() + sf::Vector2<float>(rolloutNode->getBoard().getBoardLength() / 16.0f, rolloutNode->getBoard().getBoardLength() / 16.0f);
                lines[1].position = rolloutNode->getBoard().indexToPosition(rolloutNode->getChildrenNodes()[i]->getMovesMade().front().y) * rolloutNode->getBoard().getTileWidth() + sf::Vector2<float>(rolloutNode->getBoard().getBoardLength() / 16.0f, rolloutNode->getBoard().getBoardLength() / 16.0f);
                _gfx.draw(lines);
            }
            _gfx.display();
            std::cout << "Evaluation: " << rolloutNode->getEvaluation() << "\n";*/
            
            rolloutNode = rolloutPolicy(rolloutNode).get();
        }
        auto result = rolloutNode->getEvaluation(_turn);
        saveRoller->setGeneratedAvailableChildren(false); // Remove all rollout nodes
        return result;
    }
    return node->getEvaluation(_turn);
}
// Get random child node
std::unique_ptr<Game::MCTS_Node>& Game::rolloutPolicy(Game::MCTS_Node* node)
{
    return node->getChildrenNodes()[(int(randPercent(gen) * float(int(node->getChildrenNodes().size()) + 1))) % node->getChildrenNodes().size()];
}
// Picks the child with the highest number of visits
Game::MCTS_Node* Game::best_child(Game::MCTS_Node* node)
{
    std::cout << "best_child called\n";

    if (node->isNotTerminal())
    {
        std::cout << "children count = " << node->getChildrenNodes().size() << "\n";
        std::cout << "visit count = " << node->getVisitCount() << "\n";
        std::cout << "Score = " << node->getScore() << "\n";

        MCTS_Node* bestChild = node->getChildrenNodes()[0].get();

        size_t indexOfBestChild = 0;
        for (size_t i = 0; i < node->getChildrenNodes().size(); i++)
        {
            std::cout << "Child visit count: " << std::setw(6) << node->getChildrenNodes()[i]->getVisitCount()
                << " Score: " << std:: setw(7) << node->getChildrenNodes()[i]->getScore()
                << " UCB: " << getUCB(node->getChildrenNodes()[i].get()) 
                << " Moves: " << node->getChildrenNodes()[i]->movesStr()
                << "\n";

            if (node->getChildrenNodes()[i]->getVisitCount() > bestChild->getVisitCount())
            {
                bestChild = node->getChildrenNodes()[i].get();
                indexOfBestChild = i;
            }
        }

        /*for (auto& child : node->getChildrenNodes())
        {
            if(child == nullptr)
                std::cout << "nullptr child\n";

            if (child->getVisitCount() > bestChild->getVisitCount())
                bestChild = child.get();
        }*/

        if (bestChild != nullptr)
        {
            //return bestChild;
            int nodeCountBefore = MCTS_Node::getCurrentNodeCount();
            _mCTS_RootNode = std::move(node->getChildrenNodes()[indexOfBestChild]);
            _mCTS_RootNode->setParentPointer(nullptr);
            std::cout << "MCTS root swap success. Before: " << nodeCountBefore << " After: " << MCTS_Node::getCurrentNodeCount() << "\n";
            return _mCTS_RootNode.get();
        }
    }
    return node;
}
// Back propagates data back up the search tree
void Game::backPropagate(Game::MCTS_Node* node, float result)
{
    //std::cout << "BackPropagate called\n";
    node->updateStats(result);
    if (node->isRoot())
        return;
    backPropagate(node->getParentNode(), result);
}
// Calls the Monte Carlo Tree Search algorithm
std::queue<sf::Vector3<int>> Game::mCTS(Game::MCTS_Node* rootNode, float timeAvailableInSeconds)
{
    // Get time stamp
    auto timeStart = std::chrono::steady_clock::now();
    auto resourcesLeft = true;

    while (resourcesLeft)
    {
        MCTS_Node* leaf = traverse(rootNode);
        auto simulationResult = mCTS_Rollout(leaf);
        backPropagate(leaf, simulationResult);

        resourcesLeft = float((std::chrono::steady_clock::now() - timeStart).count()) / 1000000000.0f < timeAvailableInSeconds;
        //std::cout << "mCTS resources: " << float((std::chrono::steady_clock::now() - timeStart).count()) / 1000000000.0f << "\n";
    }
    return best_child(rootNode)->getMovesMade();
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

            holder = miniMax(newBoard, ((turn + teamAdjustment + 1) % 2), turn % 2, depthOfSearch - 1 + jumpAdjustment, additionalJumps, 0.0f);

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
sf::Vector3<int> Game::alphaBetaCall(std::vector<sf::Vector3<int>>& possibleMoves, int depthOfSearch, int turn, bool doPrintout)
{
    std::vector<sf::Vector3<int>> optimalMove;
    float value = -10000.0f;
    float holder;
    int jumpAdjustment = 0;

    float alpha = -1000000.0f;
    float beta = 1000000.0f;

    if (possibleMoves[0].z != -1) // Check if jump
        jumpAdjustment = 1;

    _branchCount = 0;
    // First depth call here
    if (depthOfSearch > 0 && (int)possibleMoves.size() > 1)
    {
        _branchSplitCount = 1;
        _branchCount += (int)possibleMoves.size();

        std::sort(possibleMoves.begin(), possibleMoves.end(),
            [&](const sf::Vector3<int>& a, const sf::Vector3<int>& b) {
                return boardEvaluate(Board::portrayMove(_board.getBoardTiles(), a), turn)
                         > boardEvaluate(Board::portrayMove(_board.getBoardTiles(), b), turn);
            });

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

            holder = alphaBeta(newBoard, (turn + teamAdjustment + 1), turn, depthOfSearch - 1 + jumpAdjustment, additionalJumps, alpha, beta);

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

sf::Vector3<int> Game::mCTSCall()
{
    std::cout << "Turn count: " << _turnCount << "\n";
    std::cout << "_lastTurnMCTS_wasCalled count: " << _lastTurnMCTS_wasCalled << "\n";


    // If no root, make root
    if (_mCTS_RootNode == nullptr)
    {
        _mCTS_RootNode = std::move(std::make_unique<MCTS_Node>(_board, _turn));
    }
    else
    {
        // Opponent Call
        if (_lastTurnMCTS_wasCalled == _turnCount - 1)
        {
            // Do nothing. The root is as it should be
            std::cout << "StartUp: MCTS was called by opponent. No change.\n";
        }
        // Same team call after an opponent turn with no call
        else if (_lastTurnMCTS_wasCalled == _turnCount - 2)
        {
            std::cout << "StartUp: Same team call after an opponent turn with no MCTS call.\n";

            //MCTS_Node* matchingChild = _mCTS_RootNode->getChildrenNodes()[0].get();
            int indexOfMatch = -1;
            for (size_t i = 0; i < _mCTS_RootNode->getChildrenNodes().size(); i++)
            {
                if (_mCTS_RootNode->getChildrenNodes()[i]->getBoard().getBoardTiles() == _board.getBoardTiles())
                {
                    indexOfMatch = i;
                    //break;
                }
            }
            int nodeCountBefore = MCTS_Node::getCurrentNodeCount();
            if (indexOfMatch != -1)
            {
                _mCTS_RootNode = std::move(_mCTS_RootNode->getChildrenNodes()[indexOfMatch]);
                _mCTS_RootNode->setParentPointer(nullptr);
                std::cout << "MCTS root swap success. Before: " << nodeCountBefore << " After: " << MCTS_Node::getCurrentNodeCount() << "\n";
            }
            else
            {
                std::cout << "MCTS root swap FAILURE.\n";
                _mCTS_RootNode = std::move(std::make_unique<MCTS_Node>(_board, _turn));
            }
        }
        else
        {
            // Just make a new root node
            _mCTS_RootNode = std::move(std::make_unique<MCTS_Node>(_board, _turn));
            std::cout << "StartUp: Made new root node.\n";
        }

    }

    // If we have a set of moves that need to be made in succession (jumps)
    if (_queuedMoves.size() == 0)
    {
        std::cout << "Before call: " << MCTS_Node::getCurrentNodeCount() << " nodes\n";
        _queuedMoves = mCTS(_mCTS_RootNode.get(), _timeAvailableInSeconds);
        _lastTurnMCTS_wasCalled = _turnCount;


        {
            auto movesCopy = _queuedMoves;
            std::stringstream strStream;
            auto size = _queuedMoves.size();
            for (size_t i = 0; i < size; i++)
            {
                if (i != 0)
                    strStream << ", ";
                strStream << "{ " << movesCopy.front().x << " " << movesCopy.front().y << " " << movesCopy.front().z << " }";
                movesCopy.pop();
            }
            std::cout << "Moves: " << strStream.str() << "\n";
        }


        std::cout << "After call: " << MCTS_Node::getCurrentNodeCount() << " nodes\n";
        std::cout << "Total nodes created this call: " << MCTS_Node::getNumNodesCreated() << "\n";
        MCTS_Node::resetNodeCount();
    }

    auto front = _queuedMoves.front();
    _queuedMoves.pop();
    
    std::cout << "Current submove: " << "{ " << front.x << " " << front.y << " " << front.z << " }" << "\n";

    return front;
}

sf::Vector3<int> Game::neuralNetworkCall(bool doPrintout)
{
    // If we have a set of moves that need to be made in succession (jumps)
    if (_queuedMoves.size() == 0)
    {
        _queuedMoves = brainCall(_possibleMoves, _turn, doPrintout);

        // Debug printout of moves
        if (doPrintout)
        {
            auto movesCopy = _queuedMoves;
            std::stringstream strStream;
            auto size = _queuedMoves.size();
            for (size_t i = 0; i < size; i++)
            {
                if (i != 0)
                    strStream << ", ";
                strStream << "{ " << movesCopy.front().x << " " << movesCopy.front().y << " " << movesCopy.front().z << " }";
                movesCopy.pop();
            }

            std::cout << "Moves: " << strStream.str() << "\n";
        }
    }

    auto front = _queuedMoves.front();
    _queuedMoves.pop();

    if(doPrintout)
        std::cout << "Current submove: " << "{ " << front.x << " " << front.y << " " << front.z << " }" << "\n";

    return front;
}

void getFullJumpSet(const std::vector<sf::Vector3<int>>& possibleGeneratedMovesIN,
    std::vector<std::queue<sf::Vector3<int>>>& movesOUT,
    std::queue<sf::Vector3<int>>& currentMoveSequence,
    Board& board,
    int& teamTurn)
{
    for (size_t i = 0; i < possibleGeneratedMovesIN.size(); i++)
    {
        // Push first move in sequence
        currentMoveSequence.push(possibleGeneratedMovesIN[i]);

        bool isKing = false;
        if (board.getBoardTiles()[possibleGeneratedMovesIN[i].x] >= PieceType::Player1_King)
            isKing = true;

        Board newBoard(Board::portrayMove(board.getBoardTiles(), possibleGeneratedMovesIN[i]));

        std::vector<sf::Vector3<int>> possibleJumps;
        // Was not a king, but is now
        if (isKing || (!isKing && newBoard.getBoardTiles()[possibleGeneratedMovesIN[i].y] < PieceType::Player1_King))
            newBoard.getIndividualPieceMoves(possibleJumps, possibleGeneratedMovesIN[i].y, teamTurn, true);

        // Either we have more jumps or we don't and thus add the jump sequence
        if (possibleJumps.empty())
        {
            movesOUT.push_back(currentMoveSequence);
        }
        else
        {
            getFullJumpSet(possibleJumps, movesOUT, currentMoveSequence, newBoard, teamTurn);
        }

        // Remove move at end of sequence
        currentMoveSequence.pop();
    }
}

std::queue<sf::Vector3<int>> Game::brainCall(const std::vector<sf::Vector3<int>>& possibleMoves, int team, bool doPrintout)
{
    std::vector<std::queue<sf::Vector3<int>>> possibleMoveSequences;
    // These moves are jumps
    if (possibleMoves[0].z != -1)
    {
        std::queue<sf::Vector3<int>> currentMoveSequence = {};
        getFullJumpSet(possibleMoves, possibleMoveSequences, currentMoveSequence, _board, team);
    }
    else
    {
        // No jumps
        for (size_t i = 0; i < possibleMoves.size(); i++)
        {
            std::queue<sf::Vector3<int>> temp;
            temp.push(possibleMoves[i]);
            possibleMoveSequences.push_back(temp);
        }
    }

    // Make boards to evaluate
    std::vector<BoardAndMoves> boardsAndMoves = {};
    for (auto& moveSequence : possibleMoveSequences)
    {
        auto movesCopy = moveSequence;

        // Set up board with game tiles
        Board newBoard(Board::portrayMove(_board.getBoardTiles(), movesCopy.front()));
        movesCopy.pop();

        // Iterate through rest of move sequence if there are more moves to be made
        auto size = movesCopy.size();
        for (size_t i = 0; i < size; i++)
        {
            newBoard = Board(Board::portrayMove(newBoard.getBoardTiles(), movesCopy.front()));
            movesCopy.pop();
        }

        boardsAndMoves.push_back({ newBoard, moveSequence, 0.0f, BoardClassification::NotAvailable });
    }

    // Boards to brain here
    int chosenBoard = 0;
    if (boardsAndMoves.size() > 1)
    {
        // Evaluation for training
        if (_isNN_Training)
        {
            auto evaluateBoard = [this](Board& board, int depthOfSearch, int turn, float bias) {
                std::vector<sf::Vector3<int>> additionalJumps = {};
                return miniMax(board, (turn + 1) % 2, turn % 2, depthOfSearch, additionalJumps, bias);
            };
            
            int searchDepth = 4;
            float bias = 0.0f;

            // Sort and rank boards
            // Sort by minimax
            for (size_t i = 0; i < boardsAndMoves.size(); i++)
                boardsAndMoves[i]._evaluation = evaluateBoard(boardsAndMoves[i]._board, searchDepth, _turn, bias);

            std::sort(boardsAndMoves.begin(), boardsAndMoves.end(), [](BoardAndMoves& a, BoardAndMoves& b) {
                return a._evaluation > b._evaluation; });

            auto getNumDiffVals = [](std::vector<BoardAndMoves>& boardsAndMoves)
            {
                int count = 0;
                float currentValue = -100000.333f; // This value should not come up at all (ever)
                for (size_t i = 0; i < boardsAndMoves.size(); i++)
                {
                    if (currentValue != boardsAndMoves[i]._evaluation)
                    {
                        currentValue = boardsAndMoves[i]._evaluation;
                        count++;
                    }
                }
                return count;
            };
            auto setClassifications = [](std::vector<BoardAndMoves>& boardsAndMoves, int numGood, int numNeutral, int numBad)
            {
                int count = 0;
                auto getClassification = [&]() {
                    if (count < numGood)
                        return BoardClassification::Good;
                    else if (count < numGood + numNeutral)
                        return BoardClassification::Neutral;
                    else
                        return BoardClassification::Bad;
                };
                
                float currentValue = boardsAndMoves[0]._evaluation;
                for (size_t i = 0; i < boardsAndMoves.size(); i++)
                {
                    if (currentValue != boardsAndMoves[i]._evaluation)
                    {
                        currentValue = boardsAndMoves[i]._evaluation;
                        count++;
                    }
                    boardsAndMoves[i]._classification = getClassification();
                }
            };

            int switchVal = getNumDiffVals(boardsAndMoves);
            switch (switchVal)
            {
            case 1: // All boards the same
                setClassifications(boardsAndMoves, 0, 1, 0);
                break;
            case 2:
                setClassifications(boardsAndMoves, 1, 0, 1);
                break;
            case 3:
                setClassifications(boardsAndMoves, 1, 1, 1);
                break;
            case 4:
                setClassifications(boardsAndMoves, 2, 0, 2);
                break;
            default:
                int neutral = switchVal - (switchVal + 1) / 3 * 2;
                int GoodBad = (switchVal - neutral) / 2;
                setClassifications(boardsAndMoves, GoodBad, neutral, GoodBad);
                break;
            }
                       
            // Randomize boards so as to prevent left/right leaning descisions
            std::shuffle(boardsAndMoves.begin(), boardsAndMoves.end(), gen);

            if(doPrintout)
            {
                for (size_t i = 0; i < boardsAndMoves.size(); i++)
                {
                    switch (boardsAndMoves[i]._classification)
                    {
                    case BoardClassification::Good:
                        std::cout << "Good:    ";
                        break;
                    case BoardClassification::Neutral:
                        std::cout << "Neutral: ";
                        break;
                    case BoardClassification::Bad:
                        std::cout << "Bad:     ";
                        break;
                    default:
                        std::cout << "NA:      ";
                        break;
                    }
                    std::cout << boardsAndMoves[i]._evaluation << "  ";

                    auto movesCopy = boardsAndMoves[i]._moveSequence;
                    auto size = movesCopy.size();
                    for (size_t i = 0; i < size; i++)
                    {
                        if (i != 0)
                            std::cout << ", ";
                        std::cout << "{ " << movesCopy.front().x << " " << movesCopy.front().y << " " << movesCopy.front().z << " }";
                        movesCopy.pop();
                    };
                    std::cout << "\n";
                }
            }
        }

        // Load Data into mapped file
        // Set the turn to make decisions for
        getFileMappingVars()._mappedViewOfFile->_turn = _turn;

        if (doPrintout)
            std::cout << "Passing Board: ";
        for (size_t i = 0; i < boardsAndMoves.size(); i++)
        {            
            // Load in the board
            getFileMappingVars()._mappedViewOfFile->setBoardAndClassification(boardsAndMoves[i]._board.getBoardTiles(), boardsAndMoves[i]._classification);
            getFileMappingVars()._mappedViewOfFile->_nextBoardPlease = false;

            // Waiting for nextBoardRequest
            while (getFileMappingVars()._mappedViewOfFile->isNextBoardRequested() == false)
            {
                // Do nothing
            }
            if (doPrintout)
                std::cout << i << " ";
        }
        if (doPrintout)
        std::cout << "\n";

        getFileMappingVars()._mappedViewOfFile->startThinking(); // Makes _startThink True

        // Wait for selection
        while (getFileMappingVars()._mappedViewOfFile->_thinkStart == true || getFileMappingVars()._mappedViewOfFile->isThinking() == true)
        {
            // Do nothing
        }

        // Get selection from mapped file
        chosenBoard = getFileMappingVars()._mappedViewOfFile->getChosenBoardIndex();
    }

    // Return chosen moves
    return boardsAndMoves[chosenBoard]._moveSequence;
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
    //_stats.setDepthOfSearch(depthOfSearch);
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
// Uses  the Monte Carlo Tree Search algorithm to pick a move
void Game::makeMCTS_Move()
{
    if (_possibleMoves.size() > 0)
    {
        if (_possibleMoves.size() == 1 && _queuedMoves.size() == 0)
        {
            _latestMove = _possibleMoves[0];
        }
        else
        {
            _latestMove = mCTSCall();
        }

        finalizeMove();
    }
}
// Uses a Neural Network to pick a move
void Game::makeNN_Move()
{
    if (_possibleMoves.size() > 0)
    {
        _latestMove = neuralNetworkCall(_doDebugPrintout);

        finalizeMove();
    }
}

void Game::finalizeMove()
{
    //_stats.addTurnData(_possibleMoves.size(), _latestMove);
    _possibleMoves.clear();

    _currentGameLog.addMove(_latestMove);
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
int Game::setupRandomTournamentBoard()
{    
    int boardNum = (int(randPercent(gen) * float(int(_startingBoards.size()) + 1))) % _startingBoards.size();
    _board.setup(_startingBoards[boardNum]);
    _turn = 2; // Player 2 goes next
    return boardNum;
}
std::vector<std::vector<PieceType>>& Game::getTournamentBoards()
{
    return _startingBoards;
}

Game::FileMappingVars& Game::getFileMappingVars()
{
    return _fileMappingVars;
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
