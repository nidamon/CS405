/* stats.h
Nathan Damon
CS 405
1/26/2022
This is the header file for the stats class that will handle the statistics of the games.
*/

#ifndef STATS_H
#define STATS_H

#include <SFML\Graphics.hpp>

#include <vector>
#include <map>
#include <iostream>

#include <random>

#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

struct Data
{
	void addToVictor(int playerNum);
	void addTurnsTaken(int turnsTaken);
	void addMovesGenerated(const std::vector<int>& movesGenerated);

	void tallyTotalGamesPlayed();
	void tallyTotalMoveGenerations();

	float winPercent(int p1WinCount, int p2WinCount);

	int getMin(const std::vector<std::pair<int, int>>& dataVector);
	// Returns most recurring first value
	int getMode(const std::vector<std::pair<int, int>>& dataVector);
	int getMax(const std::vector<std::pair<int, int>>& dataVector);
	// Returns the median as per the totalAmount
	int getMedian(const std::vector<std::pair<int, int>>& dataVector, int totalAmount);
	// Returns the average as per the totalAmount
	float getAverage(const std::vector<std::pair<int, int>>& dataVector, int totalAmount);

	std::string getDataString();

	bool _needsToCalculate = false; // Determines if we just return _strOfData or put together a new string of data
	std::stringstream _streamOfData; // Holds the data if no changes are made

	int _gamesPlayed = 0;
	int _player1Victories = 0;
	int _player2Victories = 0;

	// Turns
	std::vector<std::pair<int, int>> _numTurnsInXGames = {};

	// MovesGenerated
	std::vector<std::pair<int, int>> _numMoveGenerationsInXGames = {};
	int _numTotalMoveGenerations = 0;
	float _averageMaxMoveGenerationsPerGame = 0.0f;

	// Moves
	int _minMovesGenerated = 0;
	int _maxMovesGenerated = 0;
	float _averageMovesGeneratedPerGame = 0.0f;
	float _averageMedianMovesGeneratedPerTurn = 0.0f;
};

class Stats
{
public:
	Stats();
	~Stats();

	void displayStats();
	void addTurnData(int movesGenerated, sf::Vector3<int> moveMade);

	void updateRawGameDataSheet(int turn, int userTurn);

	void setDepthOfSearch(int depthOfSearch);
private:
	void getAndUpdateOverallCheckersData(int userTurn);
	void saveNewStats();

	Data _overall_Data;
	Data _user_CPU_Data;
	Data _cPU_User_Data;
	Data _cPU_CPU_Data;

	// Temporary statistics data
	int _victor = 0;
	int _depthOfSearch = 0;
	std::vector<sf::Vector3<int>> _movesMade;
	std::vector<int> _statisticsData;

	// Save files
	std::string _overallCheckersStatsFileName = "OverallCheckersStats.txt";
	std::string _rawGameDataFileName = "RawGameData.txt";
};

#endif // !STATS_H
