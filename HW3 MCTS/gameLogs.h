/* gameLogs.h
Nathan Damon
CS 405
3/14/2022
This is the header file for the gameLogs class that will handle the gameLogs.
*/

#ifndef GAMELOGS_H
#define GAMELOGS_H

#include "board.h"
#include <chrono>
#include <queue>
#include <memory>
#include <iomanip>

#include <string>
#include <sstream>
#include <fstream>



class GameLogs
{
public:
	struct GameLog
	{
		GameLog();
		GameLog(int gameNumber, char p2Color, char winnerColor, int startingBoard, int turnCount, std::vector<sf::Vector3<int>>& movesMade, bool copyMovesMade = true);

		static GameLog getGameLogFromString(std::string& gameLogString);
		std::string getStr();
		void addMove(sf::Vector3<int>& move);

		int _gameNumber = -1;
		char _p2Color = 'e';
		char _winnerColor = 'e';
		int _startingBoard = -1;
		int _turnCount = 0;

		std::vector<sf::Vector3<int>> _movesMade;
	};

public:
	GameLogs();
	~GameLogs();

	static GameLog getNewGameLog();
	
	bool loadGameLogs();
	static bool saveGameLog(GameLog& gameLog);

	std::vector<std::unique_ptr<GameLog>>& getLogs();

private:
	static std::string _gameLogsFileName;

	std::vector<std::unique_ptr<GameLog>> _gameLogs;
};


#endif // !GAMELOGS_H
