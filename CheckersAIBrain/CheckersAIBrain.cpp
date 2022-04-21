// CheckersAIBrain.cpp : Defines the entry point for the application.
/* 
Nathan Damon
CS 405
4/5/2022
This is the main / source file for using the neural network features from PyTorch
*/

#include "CheckersAIBrain.h"

#include <random>
#include <iomanip>
#include <Windows.h>
#include <string>
#include "out/build/CheckersIPC.h"

//#define DEBUG_PRINTOUT_CHECKERSBRAIN

void DebugTextOut(std::string debugText)
{
#ifdef DEBUG_PRINTOUT_CHECKERSBRAIN
	std::cout << "[Debug] " + debugText + "\n";
#endif // DEBUG_PRINTOUT_CHECKERSBRAIN
}


struct FileMappingVars {
	HANDLE _hFileMap;
	BOOL _bResultOfMapping;
	CheckersIPC* _mappedViewOfFile;
	size_t _szIPC;
};

FileMappingVars fileMappingVars = { NULL, 0, nullptr, sizeof(CheckersIPC) };

FileMappingVars& getFileMappingVars()
{
	return fileMappingVars;
}

bool loadTrainingData(std::vector<BoardArrAndPercent>& trainingData)
{
	std::string trainingDataFileName = "CheckersBrainSaves/TrainingData/TrainingData.dat";;
	std::ifstream fin(trainingDataFileName, std::ios::binary);
	if (!fin)
	{
		std::cout << "ERROR: Did not open the " << trainingDataFileName << " file." << std::endl;
		return false;
	}
	else
	{
		while (fin)
		{	
			BoardArrAndPercent bAP;
			fin.read(reinterpret_cast<char*>(&bAP), sizeof(bAP));

			trainingData.push_back(bAP);			
		}

		std::cout << "Training Data size: " << trainingData.size() << "\n";
		std::cout << "SizeOf training data point: " << sizeof(BoardArrAndPercent) << "\n";

		if (!fin)
		{
			if (fin.eof())
				return true;
			else
			{
				std::cout << "ERROR: Failure upon reading file in loadGameLogs()." << std::endl;
				return false;
			}
		}
	}
	return true;
}
bool saveTrainingData(std::vector<BoardArrAndPercent>& trainingData)
{
	std::string trainingDataFileName = "CheckersBrainSaves/TrainingData/TrainingData.dat";
	std::ofstream fout(trainingDataFileName, std::ios::binary | std::ios::out);
	if (!fout)
	{
		std::cout << "ERROR: Did not open/create " << trainingDataFileName << std::endl;
		return false;
	}
	else
	{
		for (auto& i : trainingData) {
			fout.write(reinterpret_cast<char*>(&i), sizeof(i));
			if (!fout)
			{
				std::cout << "ERROR: Could not write trainingData into " << trainingDataFileName << std::endl;
				return false;
			}
		}
	}
	return true;
}

bool createMappedFile()
{
	bool retBool = true;

	std::cout << "\t\t....Mapping File (Opening)...." << std::endl;
	std::cout << std::endl;

	CheckersIPC checkersIPC[1];

	// Create File Map
	getFileMappingVars()._hFileMap =
		CreateFileMapping(
			INVALID_HANDLE_VALUE,
			NULL,
			PAGE_READWRITE,
			0,
			getFileMappingVars()._szIPC,
			TEXT("Local\\CheckersFileMap")
		);

	if (getFileMappingVars()._hFileMap == FALSE)
	{
		std::cout << "CreateFileMapping Failed & Error NO - " << GetLastError() << std::endl;
		retBool = false;
	}
	else
	{
		std::cout << "CreateFileMapping Success" << std::endl;

		// MapViewOfFile
		getFileMappingVars()._mappedViewOfFile = (CheckersIPC*)MapViewOfFile(
			getFileMappingVars()._hFileMap,
			FILE_MAP_ALL_ACCESS,
			0,
			0,
			getFileMappingVars()._szIPC);

		if (getFileMappingVars()._mappedViewOfFile == NULL)
		{
			std::cout << "MapViewOfFile Failed & Error NO - " << GetLastError() << std::endl;
			retBool = false;
		}
		else
			std::cout << "MapViewOfFile Success" << std::endl;
	}

	// Copy Memory Function
	MoveMemory(getFileMappingVars()._mappedViewOfFile, checkersIPC, getFileMappingVars()._szIPC);

	getFileMappingVars()._mappedViewOfFile->setGameOnOff(true);

	// Do we want to train?
	bool doTraining = true;
	if (doTraining)
	{
		std::cout << "Training -> ON.\n";
		getFileMappingVars()._mappedViewOfFile->setTrainingOnOff(doTraining);
	}
	else
	{
		std::cout << "Training -> OFF.\n";
		getFileMappingVars()._mappedViewOfFile->setTrainingOnOff(false);
	}

	return retBool;
}
bool unMapFile()
{
	bool retBool = true;

	std::cout << "\t\t....UnMapping File (Closing)...." << std::endl;
	std::cout << std::endl;

	// UnMapViewOfFile
	getFileMappingVars()._bResultOfMapping = UnmapViewOfFile(getFileMappingVars()._mappedViewOfFile);
	if (getFileMappingVars()._bResultOfMapping == FALSE)
	{
		std::cout << "UnMapViewOfFile Failed & Error No - " << GetLastError() << std::endl;
		retBool = false;
	}
	else
		std::cout << "UnMapViewOfFile Success" << std::endl;


	// Close Handle
	CloseHandle(getFileMappingVars()._hFileMap);

	getFileMappingVars()._hFileMap = NULL;

	return retBool;
}
std::random_device r;
std::mt19937 gen(r());
std::uniform_real_distribution<float> randPercent(0.0f, 1.0f);

// Main
int main()
{
	bool selfRunning = true;
	const bool doDebugPrintOut = false;
	int checkPointNum = 10000;
	   
	bool openMapHasTriedOnce = false;
	if (selfRunning)
	{
		createMappedFile();
	}
	else
	{
		if (!openMappedFile())
		{
			std::string str;
			std::cout << "Could not find the mapped file.\n";
			std::cout << "If the game has not requested for this proccess to run, then wait until it does and then hit enter. ";
			std::getline(std::cin, str);
			if (!openMappedFile())
			{
				std::cout << "Failed to open.\nExiting.\n";
				return 0;
			}
		}
	}

	getFileMappingVars()._mappedViewOfFile->setBrainOnOff(true);
	   
	bool isTraining = false;
	if (getFileMappingVars()._mappedViewOfFile != nullptr)
	{
		isTraining = getFileMappingVars()._mappedViewOfFile->isTraining();
		if (isTraining)
			std::cout << "It says training\n";
		else
			std::cout << "It DOES NOT say training\n";
	}

	// Training data vector
	std::vector<BoardArrAndPercent> trainingData = {};
	bool usingTrainingData = false;
	if(isTraining)
		usingTrainingData = loadTrainingData(trainingData);
	   

	if(doDebugPrintOut)
		std::cout << "Debug printout Enabled.\n";

	int session = 0;
	int save = 0;
	int iterationCount = 0;
	NeuralNet net;
	// Load the last network to continue previous learning
	if (!loadLatestNetwork(net, session, save))
	{
		std::cout << "ERROR: Failed to load Neural Network from file." << std::endl;
		return 0;
	}
	else
		std::cout << "Latest Neural Network Loaded." << std::endl;

	net->train(isTraining);
	
	// Increment session
	session += 1;
	save = 0; // New session, so new save count

	std::vector<BoardVectAndPercent> boards;

	const float learningRate = 0.0001f;
	auto criterion = torch::nn::HuberLoss();
	auto optimizer = torch::optim::Adam(net.get()->parameters(), learningRate);

	// Network stuff in here		   
	const float pawnWeight = 1.0f;
	const float kingWeight = 1.5f;
	auto boardEvaluation = [&](BoardVectAndPercent& boardAndTrainingValue)
	{
		auto addBoardValues = [&](std::vector<float>& data, const std::vector<PieceType>& board) {
			for (size_t i = 0; i < board.size(); i++)
			{
				float tileVal = 0.0f;
				switch (board[i])
				{
				case PieceType::NoPiece:
					tileVal = 0.0f;
					break;
				case PieceType::Player1_Pawn:
					tileVal = pawnWeight;
					break;
				case PieceType::Player2_Pawn:
					tileVal = -pawnWeight;
					break;
				case PieceType::Player1_King:
					tileVal = kingWeight;
					break;
				case PieceType::Player2_King:
					tileVal = -kingWeight;
					break;
				default:
					break;
				}
				data[i] = tileVal;
			}
		};

		auto getControlValues = [&](const std::vector<PieceType>& board)
		{
			// Get a vector that is easier to look at
			std::vector<float> boardPieceVals(64);
			for (size_t i = 0; i < boardPieceVals.size(); i++)
			{
				float tileVal = 0.0f;
				if (i % 2 == 1)
					switch (board[i / 2])
					{
					case PieceType::NoPiece:
						tileVal = 0.0f;
						break;
					case PieceType::Player1_Pawn:
						tileVal = pawnWeight;
						break;
					case PieceType::Player2_Pawn:
						tileVal = -pawnWeight;
						break;
					case PieceType::Player1_King:
						tileVal = kingWeight;
						break;
					case PieceType::Player2_King:
						tileVal = -kingWeight;
						break;
					default:
						break;
					}
				boardPieceVals[i] = tileVal;
			}

			auto areaControlPercent = [&boardPieceVals](int areaWidth, int areaHeight, int areaX, int areaY)
			{
				float areaRedSum = 0.0f;
				float areaOppSum = 0.0f;
				// Area sum
				for (size_t ay = 0; ay < areaHeight; ay++)
				{
					size_t y = areaY + ay;
					for (size_t ax = 0; ax < areaWidth; ax++)
					{
						size_t x = areaX + ax;
						size_t pos = x % 8 + y * 8;
						if (boardPieceVals[pos] > 0) // Red
							areaRedSum += boardPieceVals[pos];
						else // Opponent (opponent pieces are negative values)
							areaOppSum -= boardPieceVals[pos];
					}
				}
				// Red's point value / total points in the area
				float val = 0.0f;
				if(areaRedSum + areaOppSum > 0.0f)
					val = areaRedSum / (areaRedSum + areaOppSum);
				if (val != val)
				{
					std::cout << "areaRedSum=" << areaRedSum << "\n";
					std::cout << "areaTotal=" << areaOppSum << "\n";
					std::cout << "Dim=" << areaWidth << " area(" << areaX << ", " << areaY << ") = " << val << "\n";
				}
				return val;
			};


			std::vector<float> controlPercents(91);
			size_t index = 0;
			for (size_t i = 3; i < 9; i++)
			{
				// 36 3x3
				// 25 4x4
				// 16 5x5
				//  9 6x6
				//  4 7x7
				//  1 8x8
				size_t areaDim = (6 - (i - 3));
				for (size_t j = 0; j < areaDim * areaDim; j++)
				{
					auto val = areaControlPercent(i, i, j % areaDim, j / areaDim);

					controlPercents[index] = val;
					index++;
				}
			}

			return controlPercents;
		};


		//std::vector<float> data(32);
		//addBoardValues(data, boardAndTrainingValue._board);
		std::vector<float> data = getControlValues(boardAndTrainingValue._board);

		at::Tensor output;
		if (isTraining)
		{
			std::vector<float> targetVal = { boardAndTrainingValue._redWinPercent };
			auto target = torch::tensor(torch::detail::TensorDataContainer(targetVal));

			// Forward
			auto x = torch::tensor(torch::detail::TensorDataContainer(data));
			output = net(x);

			auto loss = criterion(output, target); // This here

			// Backward
			optimizer.zero_grad();
			loss.backward();

			// Gradient descent or adam step
			optimizer.step();


			iterationCount++;
			if (iterationCount >= checkPointNum)
			{
				iterationCount = 0;
				saveNetwork(net, session, save);
				save += 1;
			}
		}
		else
		{
			auto x = torch::tensor(torch::detail::TensorDataContainer(data));
			output = net(x);
		}

		// Result
		auto value = output.item().toFloat();
		if(doDebugPrintOut)
			std::cout << "Out: " << value << " -> " << boardAndTrainingValue._redWinPercent << "\n";

		return value;
	};

	while (getFileMappingVars()._mappedViewOfFile != nullptr   // No mapped file
		&& getFileMappingVars()._mappedViewOfFile->isBrainOn() // Are we supposed to be off
		&& getFileMappingVars()._mappedViewOfFile->isGameOn()) // Should we turn off
	{
		if (getFileMappingVars()._mappedViewOfFile->_hasBoradsToPass || isTraining == false)
		{
			boards.clear();

			// Load Data from file
			while (getFileMappingVars()._mappedViewOfFile->_thinkStart == false || getFileMappingVars()._mappedViewOfFile->_hasBoradsToPass)
			{
				// If there is no longer a mapped file to look at
				if (getFileMappingVars()._mappedViewOfFile == nullptr || getFileMappingVars()._mappedViewOfFile->isGameOn() == false)   // No mapped file
				{
					if (isTraining)
						saveNetwork(net, session, save);
					if (usingTrainingData)
						if (saveTrainingData(trainingData))
							std::cout << "Training data saved.\n";
					return 0;
				}

				// load in boards
				if (getFileMappingVars()._mappedViewOfFile->isNextBoardRequested() == false) // Waiting for board input
				{
					boards.push_back(getFileMappingVars()._mappedViewOfFile->getBoardAndClassification());
					getFileMappingVars()._mappedViewOfFile->nextBoardPlease();
					DebugTextOut("Waiting for next board.");
				}
			}

			DebugTextOut("All boards acquired.");
		}

		if (usingTrainingData)
		{
			size_t trainingDataSize = trainingData.size();
			for (size_t i = 0; i < boards.size(); i++)
			{
				BoardArrAndPercent bAP;
				bAP._redWinPercent = boards[i]._redWinPercent;
				bAP._checkCount = boards[i]._checkCount;
				for (size_t j = 0; j < boards[i]._board.size(); j++)
					bAP._board[j] = boards[i]._board[j];

				auto it = std::find_if(trainingData.begin(), trainingData.end(), [&](BoardArrAndPercent& compareBoard) {
					for (size_t k = 0; k < 32; k++)
						if (boards[i]._board[k] != compareBoard._board[k])
							return false;
					return true;
					});

				if (it != trainingData.end())
				{
					// Readjust the win%
					auto num = it->_redWinPercent * float(it->_checkCount) + bAP._redWinPercent * float(bAP._checkCount);
					it->_redWinPercent = num / (float(it->_checkCount) + float(bAP._checkCount));
				}
				else
					trainingData.push_back(bAP);
			}
			if (trainingDataSize != trainingData.size())
				std::cout << "Training data added " << trainingDataSize << " -> " << trainingData.size() << "\n";
		}

		if (getFileMappingVars()._mappedViewOfFile->isTraining() == false)
		{
			getFileMappingVars()._mappedViewOfFile->setThinking(true);
			getFileMappingVars()._mappedViewOfFile->startThinking(); // Makes _startThink false

			// Thinking right here
			for (size_t i = 0; i < boards.size(); i++)
				boards[i]._redWinPercent = boardEvaluation(boards[i]);


			int boardIndex = 0;

			// Getting board
			if (doDebugPrintOut)
			{
				std::cout << "BoardCount: " << boards.size() << "\n";
			}
			float currentWinPercent = 0.0f;
			auto turn = getFileMappingVars()._mappedViewOfFile->_turn % 2;
			if (turn == 0) // Not red's turn
				currentWinPercent = 1.0f; // = loss for red's opponent
			for (size_t i = 0; i < boards.size(); i++)
			{
				switch (turn)
				{
				case 0:
					// If less chance of losing
					if (boards[i]._redWinPercent < currentWinPercent)
					{
						currentWinPercent = boards[i]._redWinPercent;
						boardIndex = i;
					}
					break;
				case 1:
					// If higher chance of winning
					if (boards[i]._redWinPercent > currentWinPercent)
					{
						currentWinPercent = boards[i]._redWinPercent;
						boardIndex = i;
					}
					break;
				default:
					std::cout << "Default case error in win% <> currWin% switch.\n";
					break;
				}
			}
			if (doDebugPrintOut)
				std::cout << "Chosen board num: " << boardIndex << " Value: " << boards[boardIndex]._redWinPercent << "%\n";

			// Make selection and finish this transaction
			getFileMappingVars()._mappedViewOfFile->setChosenBoardIndex(boardIndex);
			getFileMappingVars()._mappedViewOfFile->setThinking(false);

			DebugTextOut("Selection made.");
		}
		else
		{
			// Get a random piece of data to run through the network
			BoardArrAndPercent bAP = trainingData[(int(randPercent(gen) * float(int(trainingData.size()) + 1))) % trainingData.size()];

			std::vector<PieceType> vectBoard(32);
			for (size_t i = 0; i < 32; i++)
				vectBoard[i] = bAP._board[i];

			BoardVectAndPercent vBP = { vectBoard, bAP._redWinPercent };

			// Pass to network
			boardEvaluation(vBP);
		}
	}

	// Save on exit
	if (isTraining)
		saveNetwork(net, session, save);
	if (selfRunning)
	{
		unMapFile();
	}
	else
	{
		if (usingTrainingData)
			if (saveTrainingData(trainingData))
				std::cout << "Training data saved.\n";
	}
	return 0;
}

bool saveNetwork(NeuralNet& net, int session, int saveNum)
{
	std::stringstream strStream;
	strStream << "CheckersBrainSaves/CheckersBrainSave-";
	strStream << std::setfill('0') << std::setw(3) << session << "-";
	strStream << std::setfill('0') << std::setw(3) << saveNum << ".pt";

	torch::save(net, strStream.str());

	// Overwrite the latest save as current save
	std::ofstream fout("CheckersBrainSaves/latestSave.txt", std::ios::binary | std::ios::out);
	if (!fout)
	{
		std::cout << "ERROR: Bad file write." << std::endl;
		return false;
	}
	else
	{
		// Output the latestSave to the file
		fout << strStream.str();
		return true;
	}
}
NeuralNet loadNetwork(int session, int saveNum)
{
	std::stringstream strStream;
	strStream << "CheckersBrainSaves/CheckersBrainSave-";
	strStream << std::setfill('0') << std::setw(3) << session << "-";
	strStream << std::setfill('0') << std::setw(3) << saveNum << ".pt";
	
	NeuralNet net;
	torch::load(net, strStream.str());
	return net;
}
bool loadLatestNetwork(NeuralNet& net, int& outSession, int& outSaveNum)
{
	std::string latestSaveStr;
	std::ifstream fin("CheckersBrainSaves/latestSave.txt", std::ios::binary);
	if (!fin)
	{
		std::cout << "ERROR: Did not open latestSave.txt file." << std::endl;
		return false;
	}
	else
	{
		std::string line;
		std::getline(fin, line);
		if (!fin)
		{
			if (fin.eof())
			{
				std::cout << "ERROR: End of latestSave.txt file." << std::endl;
				return false;
			}
			else
			{
				std::cout << "ERROR: Failure upon reading latestSave.txt file." << std::endl;
				return false;
			}
		}
		else
		{
			latestSaveStr = line;
		}
	}

	torch::load(net, latestSaveStr);

	// Get the latest save's session and save number
	std::replace(latestSaveStr.begin(), latestSaveStr.end(), '-', ' ');
	std::replace(latestSaveStr.begin(), latestSaveStr.end(), '.', ' ');

	std::string junk;
	std::istringstream dataExtraction(latestSaveStr);
	dataExtraction >> junk >> outSession >> outSaveNum;

	return true;
}

bool openMappedFile()
{
	bool retBool = true;

	std::cout << "\t\t....Mapping File (Opening)...." << std::endl;
	std::cout << std::endl;

	// OpenFileMapping
	getFileMappingVars()._hFileMap =
		OpenFileMapping(
			FILE_MAP_ALL_ACCESS,
			FALSE,
			TEXT("Local\\CheckersFileMap")
		);

	if (getFileMappingVars()._hFileMap == NULL)
	{
		std::cout << "OpenFileMap Failed & Error NO - " << GetLastError() << std::endl;
		retBool = false;
	}
	else
	{
		std::cout << "OpenFileMap Success." << std::endl;

		// MapViewOfFile
		getFileMappingVars()._mappedViewOfFile = (CheckersIPC*)MapViewOfFile(
			getFileMappingVars()._hFileMap,
			FILE_MAP_ALL_ACCESS,
			0,
			0,
			getFileMappingVars()._szIPC);

		if (getFileMappingVars()._mappedViewOfFile == NULL)
		{
			std::cout << "MapViewOfFile Failed & Error NO - " << GetLastError() << std::endl;
			retBool = false;
		}
		else
			std::cout << "MapViewOfFile Success." << std::endl;
	}

	return retBool;
}
bool closeMappedFile()
{
	bool retBool = true;

	std::cout << "\t\t....Mapping File (Closing)...." << std::endl;
	std::cout << std::endl;

	// UnMapViewOfFile
	getFileMappingVars()._bResultOfMapping = UnmapViewOfFile(getFileMappingVars()._mappedViewOfFile);
	if (getFileMappingVars()._bResultOfMapping == FALSE)
	{
		std::cout << "UnMapViewOfFile Failed & Error No - " << GetLastError() << std::endl;
		retBool = false;
	}
	else
		std::cout << "UnMapViewOfFile Success." << std::endl;


	// Close Handle
	CloseHandle(getFileMappingVars()._hFileMap);

	return retBool;
}