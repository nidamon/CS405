/* gameLogs.cpp
Nathan Damon
CS 405
3/14/2022
This is the source file for the gameLogs class that will handle the gameLogs.
*/

#include "gameLogs.h"

// ###########################
// GameLogs
// ###########################

std::string GameLogs::_gameLogsFileName = "GameLogs.txt";


GameLogs::GameLogs()
{
}
GameLogs::~GameLogs()
{
}

GameLogs::GameLog GameLogs::getNewGameLog()
{
	std::vector<sf::Vector3<int>> errorMovesMade;
	GameLog gameLog(-1, 'e', 'e', 0, errorMovesMade);

	std::ifstream fin(_gameLogsFileName, std::ios::binary);
	if (!fin)
		fin = std::ifstream("Debug/" + _gameLogsFileName, std::ios::binary);
	if (!fin)
	{
		std::cout << "ERROR: Did not open the " << _gameLogsFileName << " file." << std::endl;
	}
	else
	{
		int lastGameNum = 0;
		while (true)
		{
			std::string line;
			std::getline(fin, line);
			if (!fin)
			{
				if (fin.eof())
					break;
				else
				{
					std::cout << "ERROR: Failure upon reading file in getGameLog()." << std::endl;
					break;
				}
			}
			else
			{
				std::istringstream gameNumberExtraction(line);
				gameNumberExtraction >> lastGameNum;
			}
		}

		// Increment the game number by one
		gameLog._gameNumber = lastGameNum + 1;
	}

	return gameLog;
}

bool GameLogs::loadGameLogs()
{
	std::ifstream fin(_gameLogsFileName, std::ios::binary);
	if (!fin)
		fin = std::ifstream("Debug/" + _gameLogsFileName, std::ios::binary);
	if (!fin)
	{
		std::cout << "ERROR: Did not open the " << _gameLogsFileName << " file." << std::endl;
		return false;
	}
	else
	{
		while (true)
		{
			std::string line;
			std::getline(fin, line);
			if (!fin)
			{
				if (fin.eof())
					break;
				else
				{
					std::cout << "ERROR: Failure upon reading file in loadGameLogs()." << std::endl;
					return false;
				}
			}
			else
			{
				// Add the game log to the gameLog list
				// Pointers will make any kind of future sorting much quicker
				_gameLogs.push_back(std::make_unique<GameLog>(GameLog::getGameLogFromString(line)));
			}
		}
	}
	return true;
}
bool GameLogs::saveGameLog(GameLog& gameLog)
{
	// Check for location of file
	std::string filePath = _gameLogsFileName;
	std::ifstream finTest(filePath, std::ios::binary);
	if (!finTest)
	{
		filePath = "Debug/" + filePath;
		finTest = std::ifstream(filePath, std::ios::binary);

		// If there is no file, make a file within the project's or executable's folder
		if (!finTest)
			filePath = _gameLogsFileName;
	}


	// Append the new gameLog to the GameLogs file
	std::ofstream fout(filePath, std::ios::binary | std::ios::app);
	if (!fout)
	{
		std::cout << "ERROR: Bad file write." << std::endl;
		std::cout << "GameLog dump: " << gameLog.getStr();
		return false;
	}
	else
	{
		// Output the gameLog back to the file
		fout << gameLog.getStr();
	}

	return true;
}

std::vector<std::unique_ptr<GameLogs::GameLog>>& GameLogs::getLogs()
{
	return _gameLogs;
}

// ###########################
// GameLog
// ###########################

GameLogs::GameLog::GameLog()
	: _gameNumber(-1), _p2Color('e'), _winnerColor('e'), _turnCount(0)
{

}
GameLogs::GameLog::GameLog(int gameNumber, char p2Color, char winnerColor, int turnCount, std::vector<sf::Vector3<int>>& movesMade, bool copyMovesMade)
	: _gameNumber(gameNumber), _p2Color(p2Color), _winnerColor(winnerColor), _turnCount(turnCount)
{
	if (copyMovesMade)
		_movesMade = movesMade;
	else
		_movesMade = std::move(movesMade);
}

GameLogs::GameLog GameLogs::GameLog::getGameLogFromString(std::string& gameLogString)
{
	int gameNumber = -1;
	char p2Color = 'E';
	char winnerColor = 'E';
	int turnCount = 0;
	std::vector<sf::Vector3<int>> movesMade;

	std::istringstream dataExtraction(gameLogString);
	dataExtraction >> gameNumber >> p2Color >> winnerColor >> turnCount;

	std::string junk;
	while (true)
	{
		sf::Vector3<int> move;
		if (dataExtraction >> junk >> move.x >> move.y >> move.z >> junk)
			movesMade.push_back(move);
		else
			break;
	}

	return GameLog(gameNumber, p2Color, winnerColor, turnCount, movesMade, false);
}
std::string GameLogs::GameLog::getStr()
{
	std::stringstream strStream;
	strStream << std::setw(7) << _gameNumber
		<< " " << _p2Color
		<< " " << _winnerColor
		<< std::setw(3) << _turnCount << " ";

	for (size_t i = 0; i < _movesMade.size(); i++)
	{
		if (i != 0)
			strStream << ", ";
		strStream << "{ " << _movesMade[i].x << " " << _movesMade[i].y << " " << _movesMade[i].z << " }";
	}

	return strStream.str() + "\n";
}
void GameLogs::GameLog::addMove(sf::Vector3<int>& move)
{
	_movesMade.push_back(move);
}