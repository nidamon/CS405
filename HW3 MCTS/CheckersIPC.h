/* CheckersIPC.h
Nathan Damon
CS 405
4/5/2022
This is the header file for connecting Checkers with the Checkers brain (Checkers game side)
*/

#ifndef CHECKERS_IPC_H
#define CHECKERS_IPC_H

#include <vector>

// Checkers Game version should not have this redefined
enum class PieceType;

struct BoardArrAndPercent
{
	PieceType _board[32];
	float _redWinPercent;
};

struct BoardVectAndPercent
{
	std::vector<PieceType> _board;
	float _redWinPercent;
};

struct CheckersIPC
{
	BoardArrAndPercent _bp;
	bool _nextBoardPlease = true;
	bool _thinkStart = false;
	bool _thinking = false;
	int _chosenBoardIndex = -1;
	int _turn = 0;

	bool _brainOn = false;
	bool _gameOn = false;
	bool _training = false;


	BoardVectAndPercent getBoardAndClassification() const
	{
		std::vector<PieceType> vectBoard(32);
		for (size_t i = 0; i < 32; i++)
			vectBoard[i] = _bp._board[i];

		return BoardVectAndPercent{ vectBoard, _bp._redWinPercent };
	}
	void setBoardAndClassification(std::vector<PieceType>& board, float redWinPercent)
	{
		for (size_t i = 0; i < 32; i++)
			_bp._board[i] = board[i];

		_bp._redWinPercent = redWinPercent;
	}

	void nextBoardPlease()
	{
		_nextBoardPlease = true;
	}
	bool isNextBoardRequested()
	{
		return _nextBoardPlease;
	}

	bool startThinking()
	{
		_thinkStart = !_thinkStart;
		return !_thinkStart;
	}
	void setThinking(bool thinking)
	{
		_thinking = thinking;
	}
	bool isThinking()
	{
		return _thinking;
	}

	void setChosenBoardIndex(int chosenBoardIndex)
	{
		_chosenBoardIndex = chosenBoardIndex;
	}
	int getChosenBoardIndex()
	{
		return _chosenBoardIndex;
	}

	bool isBrainOn()
	{
		return _brainOn;
	}
	void setBrainOnOff(bool brainOnOff)
	{
		_brainOn = brainOnOff;
	}

	bool isGameOn()
	{
		return _gameOn;
	}
	void setGameOnOff(bool gameOnOff)
	{
		_gameOn = gameOnOff;
	}

	bool isTraining()
	{
		return _training;
	}
	void setTrainingOnOff(bool trainingOnOff)
	{
		_training = trainingOnOff;
	}
};



#endif // !CHECKERS_IPC_H