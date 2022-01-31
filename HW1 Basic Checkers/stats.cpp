/* stats.cpp
Nathan Damon
CS 405
1/26/2022
This is the source file for the stats class that will handle the statistics of the games.
*/

#include "stats.h"

// Data struct
void Data::addToVictor(int playerNum)
{
    if (playerNum == 1)
        ++_player1Victories;
    else
        ++_player2Victories;
}
void Data::addTurnsTaken(int turnsTaken)
{
    // Turns
    bool addedTurnsTaken = false;
    for (auto& [turns, games] : _numTurnsInXGames)
    {
        if (turns == turnsTaken)
        {
            ++games;
            addedTurnsTaken = true;
            return;
        }
    }
    if (!addedTurnsTaken)
    {
        _numTurnsInXGames.push_back({ turnsTaken, 1 });
        std::sort(_numTurnsInXGames.begin(), _numTurnsInXGames.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.first < b.first; });
    }
}
void Data::addMovesGenerated(const std::vector<int>& movesGenerated)
{
    // Moves
    bool needToSortData = false;
    std::vector<std::pair<int, int>> movesGeneratedThatWereNotAdded;
    for (size_t i = 0; i < movesGenerated.size(); i++)
    {
        bool addedMovesGenerated = false;
        for (auto& [moves, generatedCount] : _numMoveGenerationsInXGames)
        {
            if (moves == i) // i is the moves count with the value at movesGenerated[i] being the generated count
            {
                generatedCount += movesGenerated[i];
                addedMovesGenerated = true;
            }
        }
        if (!addedMovesGenerated)
            movesGeneratedThatWereNotAdded.push_back({ i, movesGenerated[i] });
    }

    if (movesGeneratedThatWereNotAdded.size() > 0)
        needToSortData = true;

    // Add in the values that did not have a place
    while (movesGeneratedThatWereNotAdded.size() > 0)
    {
        _numMoveGenerationsInXGames.push_back(movesGeneratedThatWereNotAdded.back());
        movesGeneratedThatWereNotAdded.pop_back();
    }

    if (needToSortData)
        std::sort(_numMoveGenerationsInXGames.begin(), _numMoveGenerationsInXGames.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {return a.first < b.first; });




    // Average max moveGenerations per Game
    _averageMaxMoveGenerationsPerGame = (float(movesGenerated.size() - 1) + _averageMaxMoveGenerationsPerGame * float(_gamesPlayed)) / float(_gamesPlayed + 1);

    // Total moves generated
    int totalMoves = 0;
    int totalMovesAlltime = 0;
    for (size_t i = 0; i < movesGenerated.size(); i++)
        totalMoves += i * movesGenerated[i];
    for (const auto& [moves, generatedCount] : _numMoveGenerationsInXGames)
        totalMovesAlltime += moves * generatedCount;

    // MinMax number of moves generated
    if (_minMovesGenerated > totalMoves)
        _minMovesGenerated = totalMoves;
    if (_maxMovesGenerated < totalMoves)
        _maxMovesGenerated = totalMoves;

    // Average moves generated per game
    _averageMovesGeneratedPerGame = float(totalMovesAlltime) / float(_gamesPlayed + 1);


    // Average median of moves generated per turn
    // Total generations
    int totalMoveGenerations = 0;
    for (size_t i = 0; i < movesGenerated.size(); i++)
        totalMoveGenerations += movesGenerated[i];
    int sum = 0;
    int median = 0;
    for (size_t i = 0; i < movesGenerated.size(); i++)
    {
        sum += movesGenerated[i];
        if (sum >= totalMoveGenerations / 2)
        {
            median = i;
            break;
        }
    }
    _averageMedianMovesGeneratedPerTurn = (float(median) + _averageMedianMovesGeneratedPerTurn * float(_gamesPlayed)) / float(_gamesPlayed + 1);
};

void Data::tallyTotalGamesPlayed() {
    _gamesPlayed = 0;
    for (const auto& [turn, gameCount] : _numTurnsInXGames)
        _gamesPlayed += gameCount;
}
void Data::tallyTotalMoveGenerations()
{
    _numTotalMoveGenerations = 0;
    for (const auto& [moves, generations] : _numMoveGenerationsInXGames)
        _numTotalMoveGenerations += generations;
}

float Data::winPercent(int p1WinCount, int p2WinCount)
{
    if (p1WinCount + p2WinCount == 0)
        return 0.0f;
    return 100.0f * float(p1WinCount) / float(p1WinCount + p2WinCount);
}

int Data::getMin(const std::vector<std::pair<int, int>>& dataVector) {
    return dataVector.front().first;
}
// Returns most recurring first value
int Data::getMode(const std::vector<std::pair<int, int>>& dataVector) {
    int mode = 0;
    int games = 0;
    for (auto item : dataVector)
    {
        if (item.second > games)
        {
            mode = item.first;
            games = item.second;
        }
    }

    return mode;
}
int Data::getMax(const std::vector<std::pair<int, int>>& dataVector) {
    return dataVector.back().first;
}
// Returns the median as per the totalAmount
int Data::getMedian(const std::vector<std::pair<int, int>>& dataVector, int totalAmount) {
    int gameSum = 0;
    for (size_t i = 0; i < dataVector.size(); i++)
    {
        gameSum += dataVector[i].second;
        if (gameSum >= totalAmount / 2) // Return the median number of turns
            return dataVector[i].first;
    }
}
// Returns the average as per the totalAmount
float Data::getAverage(const std::vector<std::pair<int, int>>& dataVector, int totalAmount) {
    int total = 0;
    for (size_t i = 0; i < dataVector.size(); i++)
        total += dataVector[i].first * dataVector[i].second;

    return float(total) / float(totalAmount);
}

std::string Data::getDataString()
{
    if (_needsToCalculate)
    {
        tallyTotalGamesPlayed();
        tallyTotalMoveGenerations();

        std::string turnsInXGames;
        std::string moveGenerationsInXGames;

        // turnsInXGames
        std::stringstream strStream1;
        for (size_t i = 0; i < _numTurnsInXGames.size(); i++)
        {
            if (i != 0)
                strStream1 << ",";
            strStream1 << "(" << _numTurnsInXGames[i].first << "," << _numTurnsInXGames[i].second << ")";
        }
        turnsInXGames = strStream1.str();

        // moveGenerationsInXGames
        std::stringstream strStream2;
        for (size_t i = 0; i < _numMoveGenerationsInXGames.size(); i++)
        {
            if (i != 0)
                strStream2 << ",";
            strStream2 << "(" << _numMoveGenerationsInXGames[i].first << "," << _numMoveGenerationsInXGames[i].second << ")";
        }
        moveGenerationsInXGames = strStream2.str();

        _streamOfData << "Games Played: " << _gamesPlayed << '\n'
            << "P1 to P2 Wins: " << _player1Victories << " : " << _player2Victories << " (" << winPercent(_player1Victories, _player2Victories) << "% P1 victory)\n"
            << "Turns:\n"
            << "  Totaled - (Num of turns, games with this many turns): " << turnsInXGames << '\n'
            << "  MinModeMax turns taken: " << getMin(_numTurnsInXGames) << ", " << getMode(_numTurnsInXGames) << ", " << getMax(_numTurnsInXGames) << '\n'
            << "  MedianAverage turns taken: " << getMedian(_numTurnsInXGames, _gamesPlayed) << ", " << getAverage(_numTurnsInXGames, _gamesPlayed) << '\n'
            << "MovesGenerated:\n"
            << " Generations:\n"
            << "  Totaled - (Num available moves, times generated): " << moveGenerationsInXGames << '\n'
            << "  MinModeMax: " << getMin(_numMoveGenerationsInXGames) << ", " << getMode(_numMoveGenerationsInXGames) << ", " << getMax(_numMoveGenerationsInXGames) << '\n'
            << "  MedianAverage: " << getMedian(_numMoveGenerationsInXGames, _numTotalMoveGenerations) << ", " << getAverage(_numMoveGenerationsInXGames, _numTotalMoveGenerations) << '\n'
            << "  Average max move generations per game: " << _averageMaxMoveGenerationsPerGame << '\n'
            << "Moves:\n"
            << "  MinMax number of moves generated per game: " << _minMovesGenerated << ", " << _maxMovesGenerated << '\n'
            << "  Average number of moves generated per game: " << _averageMovesGeneratedPerGame << '\n'
            << "  Average median number of moves generated per turn: " << _averageMedianMovesGeneratedPerTurn << '\n';
    }

    return _streamOfData.str();
}


// Stats class

Stats::Stats()
{
}

Stats::~Stats()
{
}

void Stats::displayStats()
{
    for (size_t i = 0; i < _statisticsData.size(); i++)
    {
        if (i != 0)
            std::cout << ",";
        std::cout << "(" << i << "," << _statisticsData[i] << ")";
    }
    std::cout << std::endl;
    std::cout << "MovesGenerated: " << std::endl;
    std::cout << "Max: " << _statisticsData.size() << std::endl;
    std::cout << "Min: " << 0 << std::endl;

    // Total generations
    int totalMoveGenerations = 0;
    for (size_t i = 0; i < _statisticsData.size() - 1; i++)
    {
        totalMoveGenerations += _statisticsData[i];
    }
    std::cout << "Total generations: " << totalMoveGenerations << std::endl;

    int totalMovesGenerated = 0;
    for (size_t i = 0; i < _statisticsData.size(); i++)
    {
        totalMovesGenerated += i * _statisticsData[i];
    }
    std::cout << "Total moves generated: " << totalMovesGenerated << std::endl;
    std::cout << "Average: " << totalMovesGenerated / totalMoveGenerations << std::endl;
}

void Stats::addTurnData(int movesGenerated)
{
    ++_turnsTaken;
    if (_statisticsData.size() <= movesGenerated)
        _statisticsData.resize(movesGenerated + 1, 0);

    ++_statisticsData[movesGenerated];
}
void Stats::updateRawGameDataSheet(int turn, int userTurn)
{
    int gameNumber = 0;
    // Getting the current game's number from the OverallCheckersStats text file
    std::ifstream fin(_overallCheckersStatsFileName, std::ios::binary);
    if (!fin)
        fin = std::ifstream("Debug/" + _overallCheckersStatsFileName, std::ios::binary);
    if (!fin)
    {
        std::cout << "ERROR: Did not open the OverallCheckersStats text file. Setting game number to 1" << std::endl;
        gameNumber = 1;
    }
    else
    {
        std::string junk;
        std::string line;
        std::getline(fin, line);
        if (!fin)
        {
            if (!fin.eof())
                std::cout << "ERROR: Failure upon reading file." << std::endl;
        }
        else
        {
            std::istringstream gameNumberGetter(line);
            gameNumberGetter >> junk >> junk >> junk >> gameNumber;
            ++gameNumber;
        }
    }

    // Check for location of file
    std::string filePath = _rawGameDataFileName;
    std::ifstream finTest(filePath, std::ios::binary);
    if (!finTest)
    {
        filePath = "Debug/" + filePath;
        finTest = std::ifstream(filePath, std::ios::binary);

        // If there is no file, make a file within the project's or executable's folder
        if(!finTest)
            filePath = _rawGameDataFileName;
    }

    std::ofstream fout(filePath, std::ios::binary | std::ios::app);
    if (!fout)
    {
        std::cout << "ERROR: Bad file write." << std::endl;
        return;
    }
    else
    {
        std::string player1;
        std::string player2;
        int playerThatWon;
        std::string movesGenerated;
        int min = 0;
        int mode = 0;
        int max = std::max(0, int(_statisticsData.size()) - 1);
        int median = 0;
        int average = 0;
        int totalMoveGenerations = 0;
        int totalMovesGenerated = 0;

        // Setup
        switch (userTurn)
        {
        case 0: // CPU game
            player1 = "CPU";
            player2 = "CPU";
            break;
        case 1: // User is player1
            player1 = "User";
            player2 = "CPU";
            break;
        case 2: // User is player2
            player1 = "CPU";
            player2 = "User";
            break;
        default:
            break;
        }

        if (turn == 2) // Player1 won
            playerThatWon = 1;
        else
            playerThatWon = 2;
        _victor = playerThatWon;

        // Moves Generated
        std::stringstream strStream;
        for (size_t i = 0; i < _statisticsData.size(); i++)
        {
            if (i != 0)
                strStream << ",";
            strStream << "(" << i << "," << _statisticsData[i] << ")";
        }
        movesGenerated = strStream.str();

        // Mode
        int generationValue = 0;
        for (size_t i = 0; i < _statisticsData.size(); i++)
        {
            if (_statisticsData[i] > generationValue)
            {
                mode = i;
                generationValue = _statisticsData[i];
            }
        }

        // Total generations
        for (size_t i = 0; i < _statisticsData.size(); i++)
        {
            totalMoveGenerations += _statisticsData[i];
        }
        // Total moves generated
        for (size_t i = 0; i < _statisticsData.size(); i++)
        {
            totalMovesGenerated += i * _statisticsData[i];
        }

        // Median
        int sum = 0;
        for (size_t i = 0; i < _statisticsData.size(); i++)
        {
            sum += _statisticsData[i];
            if (sum >= totalMoveGenerations / 2)
            {
                median = i;
                break;
            }
        }

        // Average
        average = totalMovesGenerated / totalMoveGenerations;



        // Formating
        fout << "Game: " << gameNumber << "\n"
            << "Player1: " << player1 << "\n"
            << "Player2: " << player2 << "\n"
            << "Player " << playerThatWon << " Won\n"
            << "Turns Taken: " << _turnsTaken << "\n"
            << "MovesGenerated:\n"
            << "  (Num available moves, times generated): " << movesGenerated << "\n"
            << "  MinModeMax: " << min << ", " << mode << ", " << max << "\n"
            << "  MedianAverage: " << median << ", " << average << "\n"
            << "  Total generations: " << totalMoveGenerations << "\n"
            << "  Total moves generated: " << totalMovesGenerated << "\n\n";
    }

    getAndUpdateOverallCheckersData(userTurn);
}

void Stats::getAndUpdateOverallCheckersData(int userTurn)
{
    // Get the overall game data for all games
    std::ifstream fin(_overallCheckersStatsFileName, std::ios::binary);
    if (!fin)
        fin = std::ifstream("Debug/" + _overallCheckersStatsFileName, std::ios::binary);
    if (!fin)
    {
        std::cout << "ERROR: Did not open the OverallCheckersStats text file." << std::endl;
        return;
    }
    else
    {
        int section = 0;

        _overall_Data._needsToCalculate = true;
        _overall_Data._streamOfData << "Total ";

        switch (userTurn)
        {
        case 0: // CPU game
            _cPU_CPU_Data._needsToCalculate = true;
            _cPU_CPU_Data._streamOfData << '\n' << "Player1: CPU\n" << "Player2: CPU\n";
            break;
        case 1: // User is player1
            _user_CPU_Data._needsToCalculate = true;
            _user_CPU_Data._streamOfData << '\n' << "Player1: User\n" << "Player2: CPU\n";
            break;
        case 2: // User is player2
            _cPU_User_Data._needsToCalculate = true;
            _cPU_User_Data._streamOfData << '\n' << "Player1: CPU\n" << "Player2: User\n";
            break;
        default:
            break;
        }

        int lineInSection = 0;
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
                    std::cout << "ERROR: Failure upon reading file." << std::endl;
                    break;
                }
            }
            else
            {
                //std::cout << line << std::endl;
                if (line.size() < 2)
                {
                    ++section;
                    lineInSection = 0;
                }

                auto extract = [&](Data& data, int lineAt, int lineOffset = 0) {
                    std::string junkStr;
                    std::istringstream dataExtraction(line);

                    auto removeExtaWords = [&](int wordsToSkip) {
                        // Remove extra words in front of wanted information
                        for (int i = 0; i < wordsToSkip; i++)
                            dataExtraction >> junkStr;
                    };

                    auto arrayDataExtractionTo = [&](size_t wordsToSkip, std::vector<std::pair<int, int>>& destination) {
                        removeExtaWords(wordsToSkip);
                        std::string arrayString;
                        dataExtraction >> arrayString;

                        // Remove everything other than the values
                        std::replace(arrayString.begin(), arrayString.end(), '(', ' ');
                        std::replace(arrayString.begin(), arrayString.end(), ')', ' ');
                        std::replace(arrayString.begin(), arrayString.end(), ',', ' ');

                        // Put values into the destination vector
                        std::istringstream arrayExtraction(arrayString);
                        std::pair<int, int> dataPair;
                        int count = 0;
                        while (true)
                        {
                            if (arrayExtraction >> dataPair.first >> dataPair.second)
                                destination.push_back(dataPair);
                            else
                                break;
                        }
                    };

                    if (lineOffset == 0)
                    {
                        // Total Games Played: #
                        if (lineAt == 0)
                            dataExtraction >> junkStr >> junkStr >> junkStr >> data._gamesPlayed;
                    }                 
                    else
                    {
                        //Games Played: #
                        if (lineAt == 0 + lineOffset)
                            dataExtraction >> junkStr >> junkStr >> data._gamesPlayed;
                    }
                    if (lineAt == 1 + lineOffset) // P1 to P2 Wins: # : # (##% P1 victory)
                        dataExtraction >> junkStr >> junkStr >> junkStr >> junkStr >> data._player1Victories >> junkStr >> data._player2Victories;
                    if (lineAt == 3 + lineOffset) // Totaled - (Num of turns, games with this many turns): (##,#),(##,#), ...
                        arrayDataExtractionTo(10, data._numTurnsInXGames);
                    if (lineAt == 8 + lineOffset) // Totaled - (Num available moves, times generated): (##,#),(##,#), ...
                        arrayDataExtractionTo(7, data._numMoveGenerationsInXGames);
                    if (lineAt == 11 + lineOffset) // Average max move generations per game: #
                    {
                        removeExtaWords(6);
                        dataExtraction >> data._averageMaxMoveGenerationsPerGame;
                    }
                    if (lineAt == 13 + lineOffset) // Average MinMax of moves generated per game: ##, ##
                    {
                        removeExtaWords(7);
                        std::string temp;
                        dataExtraction >> temp >> data._maxMovesGenerated;

                        std::replace(temp.begin(), temp.end(), ',', ' ');
                        std::istringstream afterCleaning(temp);
                        afterCleaning >> data._minMovesGenerated;
                    }
                    if (lineAt == 14 + lineOffset) // Average moves generated per game: ##
                    {
                        removeExtaWords(7);
                        std::string temp;
                        dataExtraction >> temp >> junkStr; // Don't need the second value

                        std::replace(temp.begin(), temp.end(), ',', ' ');
                        std::istringstream afterCleaning(temp);
                        afterCleaning >> data._averageMovesGeneratedPerGame;
                    }
                    if (lineAt == 15 + lineOffset) // Average median of moves generated per turn : ##
                    {
                        removeExtaWords(8);
                        dataExtraction >> data._averageMedianMovesGeneratedPerTurn;
                    }

                };

                switch (section)
                {
                case 0: // Overall                            
                    extract(_overall_Data, lineInSection);
                    break;
                case 1: // CPU game
                    if (userTurn == 0)
                        extract(_cPU_CPU_Data, lineInSection, 3);
                    else
                        _cPU_CPU_Data._streamOfData << line << std::endl;
                    break;
                case 2: // User is player1
                    if (userTurn == 1)
                        extract(_user_CPU_Data, lineInSection, 3);
                    else
                        _user_CPU_Data._streamOfData << line << std::endl;
                    break;
                case 3: // User is player2
                    if (userTurn == 2)
                        extract(_cPU_User_Data, lineInSection, 3);
                    else
                        _cPU_User_Data._streamOfData << line << std::endl;
                    break;
                default:
                    break;
                }

                ++lineInSection;
            }
        }

        // Add the new game's data
        _overall_Data.addToVictor(_victor);
        _overall_Data.addTurnsTaken(_turnsTaken);
        _overall_Data.addMovesGenerated(_statisticsData);
        switch (userTurn)
        {
        case 0: // CPU game
            _cPU_CPU_Data.addToVictor(_victor);
            _cPU_CPU_Data.addTurnsTaken(_turnsTaken);
            _cPU_CPU_Data.addMovesGenerated(_statisticsData);
            break;
        case 1: // User is player1
            _user_CPU_Data.addToVictor(_victor);
            _user_CPU_Data.addTurnsTaken(_turnsTaken);
            _user_CPU_Data.addMovesGenerated(_statisticsData);
            break;
        case 2: // User is player2
            _cPU_User_Data.addToVictor(_victor);
            _cPU_User_Data.addTurnsTaken(_turnsTaken);
            _cPU_User_Data.addMovesGenerated(_statisticsData);
            break;
        default:
            break;
        }
    }

    saveNewStats();
}

void Stats::saveNewStats()
{
    // Check for location of file
    std::string filePath = _overallCheckersStatsFileName;
    std::ifstream finTest(filePath, std::ios::binary);
    if (!finTest)
    {
        filePath = "Debug/" + filePath;
        finTest = std::ifstream(filePath, std::ios::binary);

        // If there is no file, make a file within the project's or executable's folder
        if (!finTest)
            filePath = _rawGameDataFileName;
    }

    // Overwrite OverallGameData in file
    std::ofstream fout(filePath, std::ios::binary | std::ios::out);
    if (!fout)
    {
        std::cout << "ERROR: Bad file write." << std::endl;
        return;
    }
    else
    {
        // Output the statistics back to the file
        fout << _overall_Data.getDataString()
            << _cPU_CPU_Data.getDataString()
            << _user_CPU_Data.getDataString()
            << _cPU_User_Data.getDataString()
            << std::endl;
    }
}