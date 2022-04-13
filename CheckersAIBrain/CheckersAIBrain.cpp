// CheckersAIBrain.cpp : Defines the entry point for the application.
/* 
Nathan Damon
CS 405
4/5/2022
This is the main / source file for using the neural network features from PyTorch
*/

#include "CheckersAIBrain.h"

#include <iomanip>
#include <Windows.h>
#include <string>
#include "out/build/CheckersIPC.h"

#define DEBUG_PRINTOUT_CHECKERSBRAIN

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
	size_t _szGame;
};

FileMappingVars fileMappingVars = { NULL, 0, nullptr, sizeof(CheckersIPC) };

FileMappingVars& getFileMappingVars()
{
	return fileMappingVars;
}

//int main()
//{
//
//	//PieceType _ = PieceType::NoPiece;
//	//PieceType r = PieceType::Player1_Pawn;
//	//PieceType b = PieceType::Player2_Pawn;
//	//PieceType R = PieceType::Player1_King;
//	//PieceType B = PieceType::Player2_King;
//	//std::vector<PieceType> board1 = {
//	//			_,    _,    _,    _,
//	//		 R,    _,    _,    _,
//	//			b,    B,    _,    _,
//	//		 _,    _,    R,    _,
//	//			b,    b,    b,    _,
//	//		 _,    _,    _,    _,
//	//			_,    _,    b,    _,
//	//		 _,    _,    _,    _,
//	//};
//	//std::vector<PieceType> board2 = {
//	//		_,    _,    _,    _,
//	//	 R,    _,    _,    _,
//	//		_,    _,    _,    _,
//	//	 _,    _,    _,    _,
//	//		_,    _,    _,    _,
//	//	 _,    _,    _,    _,
//	//		_,    _,    _,    _,
//	//	 _,    _,    R,    _,
//	//};
//	//
//	//auto addBoardsValues = [](std::vector<float>& data, const std::vector<PieceType>& board1, const std::vector<PieceType>& board2, int turn)
//	//{
//	//	auto addBoardValues = [turn](std::vector<float>& data, size_t indexStart, const std::vector<PieceType>& board) {
//	//		float modifier = 1.0f;
//	//		if (turn % 2 == 0)
//	//			modifier = -1.0f;
//	//		for (size_t i = 0; i < board.size(); i++)
//	//		{
//	//			float tileVal = 0.0f;
//	//			switch (board[i])
//	//			{
//	//			case PieceType::NoPiece:
//	//				tileVal = 0.0f * modifier;
//	//				break;
//	//			case PieceType::Player1_Pawn:
//	//				tileVal = 1.0f * modifier;
//	//				break;
//	//			case PieceType::Player2_Pawn:
//	//				tileVal = -1.0f * modifier;
//	//				break;
//	//			case PieceType::Player1_King:
//	//				tileVal = 1.5f * modifier;
//	//				break;
//	//			case PieceType::Player2_King:
//	//				tileVal = -1.5f * modifier;
//	//				break;
//	//			default:
//	//				break;
//	//			}
//	//			data[indexStart + i] = tileVal;
//	//		}
//	//	};
//	//	addBoardValues(data, 0, board1);
//	//	addBoardValues(data, 32, board2);
//	//};
//	//
//	//std::vector<float> data(64);
//	//int turn = 1; // getFileMappingVars()._mappedViewOfFile->_turn
//	//addBoardsValues(data, board1, board2, turn);
//
//	bool isTraining = true;
//	if (getFileMappingVars()._mappedViewOfFile != nullptr)
//		bool isTraining = getFileMappingVars()._mappedViewOfFile->isTraining();
//	int session = 0;
//	int save = 0;
//	int iterationCount = 0;
//	int checkPointNum = 100;
//	NeuralNet net(64, 44, 1);
//	//if (!loadLatestNetwork(net, session, save))
//	//{
//	//	std::cout << "ERROR: Failed to load Neural Network from file." << std::endl;
//	//	//return 0;
//	//}
//	//// Increment session
//	//session += 1;
//	//save = 0; // New session, so new save count
//
//	std::vector<BoardVectAndClass> boards;
//
//
//
//
//	float learningRate = 0.001f;
//	auto criterion = torch::nn::CrossEntropyLoss();
//	auto optimizer = torch::optim::Adam(net.get()->parameters(), learningRate);
//
//	// Network stuff in here
//	auto boardSelection = [&](BoardVectAndClass& a, BoardVectAndClass& b) {
//		auto addBoardsValues = [](std::vector<float>& data, const std::vector<PieceType>& board1, const std::vector<PieceType>& board2, int turn)
//		{
//			auto addBoardValues = [turn](std::vector<float>& data, size_t indexStart, const std::vector<PieceType>& board) {
//				float modifier = 1.0f;
//				if (turn % 2 == 0)
//					modifier = -1.0f;
//				for (size_t i = 0; i < board.size(); i++)
//				{
//					float tileVal = 0.0f;
//					switch (board[i])
//					{
//					case PieceType::NoPiece:
//						tileVal = 0.0f * modifier;
//						break;
//					case PieceType::Player1_Pawn:
//						tileVal = 1.0f * modifier;
//						break;
//					case PieceType::Player2_Pawn:
//						tileVal = -1.0f * modifier;
//						break;
//					case PieceType::Player1_King:
//						tileVal = 1.5f * modifier;
//						break;
//					case PieceType::Player2_King:
//						tileVal = -1.5f * modifier;
//						break;
//					default:
//						break;
//					}
//					data[indexStart + i] = tileVal;
//				}
//			};
//			addBoardValues(data, 0, board1);
//			addBoardValues(data, 32, board2);
//		};
//
//		std::vector<float> data(64);			   		 		
//		int turn = 1; 
//		if (getFileMappingVars()._mappedViewOfFile != nullptr)
//			turn = getFileMappingVars()._mappedViewOfFile->_turn;
//		addBoardsValues(data, a._board, b._board, turn);
//
//		float value = 0.0f;
//		at::Tensor output;
//		if (isTraining)
//		{
//			std::vector<float> preference{ 0.0f };
//			if (a._boardClassification > b._boardClassification)
//				preference.front() = 1.0f;
//			else if (a._boardClassification < b._boardClassification)
//				preference.front() = -1.0f;
//			else
//				preference.front() = 0.0f; // If 0, don't train for picking
//
//			auto target = torch::tensor(torch::detail::TensorDataContainer(preference));
//
//			// Forward
//			auto x = torch::tensor(torch::detail::TensorDataContainer(data));
//			output = net->forward(x);
//			auto loss = criterion(output, target);
//
//			// Backward
//			optimizer.zero_grad();
//			loss.backward();
//
//			// Gradient descent or adam step
//			optimizer.step();
//
//
//			iterationCount++;
//			if (iterationCount >= checkPointNum)
//			{
//				iterationCount = 0;
//				saveNetwork(net, session, save);
//				save += 1;
//			}
//		}
//		else
//		{
//			auto x = torch::tensor(torch::detail::TensorDataContainer(data));
//			output = net->forward(x);
//		}
//
//		// Result
//		std::cout << output << " ";
//		value = output.item;
//		std::cout << value << "\n";
//		if (value > 0.0f)
//		{
//			return a;
//		}
//		else
//		{
//			return b;
//		}
//	};
//
//	// Load up the boards into pointer vector
//	std::vector<BoardVectAndClass*> lastRoundWinners;
//	for (size_t i = 0; i < boards.size(); i++)
//	{
//		lastRoundWinners.push_back(&boards[i]);
//	}
//
//	// Get THE board
//	std::vector<BoardVectAndClass*> winningBoards;
//	while (lastRoundWinners.size() > 1)
//	{
//		for (size_t i = 0; i < lastRoundWinners.size(); i++)
//		{
//			if (i % 2 == 0)
//			{
//				BoardVectAndClass* winningBoard = nullptr;
//				// Compare boards i and i+1
//				winningBoard = &boardSelection(*lastRoundWinners[i], *lastRoundWinners[i + 1]);
//
//				// Add the new winner
//				winningBoards.push_back(winningBoard);
//			}
//			else // Odd board gets free pass to next round
//			{
//				if(i + 1 == lastRoundWinners.size())
//					winningBoards.push_back(lastRoundWinners[i]);
//			}
//		}
//		lastRoundWinners = winningBoards;
//		winningBoards.clear();
//	}
//
//
//
//
//	
//}

// Main
int main()
{
	const bool doDebugPrintOut = true;
	   
	bool openMapHasTriedOnce = false;
	if(!openMappedFile())
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

	getFileMappingVars()._mappedViewOfFile->setBrainOnOff(true);
	   
	bool isTraining = true;
	if (getFileMappingVars()._mappedViewOfFile != nullptr)
	{
		isTraining = getFileMappingVars()._mappedViewOfFile->isTraining();
		if (getFileMappingVars()._mappedViewOfFile->isTraining())
			std::cout << "It says training\n";
		else
			std::cout << "It DOES NOT say training\n";
	}

	if(doDebugPrintOut)
		std::cout << "Debug printout on.\n";

	int session = 0;
	int save = 0;
	int iterationCount = 0;
	int checkPointNum = 500;
	NeuralNet net;
	// Load the last network to continue previous learning
	if (!loadLatestNetwork(net, session, save))
	{
		std::cout << "ERROR: Failed to load Neural Network from file." << std::endl;
		return 0;
	}
	net->train(isTraining);
	
	// Increment session
	session += 1;
	save = 0; // New session, so new save count

	std::vector<BoardVectAndPercent> boards;

	const float learningRate = 0.001f;
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

		std::vector<float> data(32);
		addBoardValues(data, boardAndTrainingValue._board);

		at::Tensor output;
		if (isTraining)
		{
			std::vector<float> targetVal = { boardAndTrainingValue._redWinPercent };
			auto target = torch::tensor(torch::detail::TensorDataContainer(targetVal));

			// Forward
			auto x = torch::tensor(torch::detail::TensorDataContainer(data));
			output = net(x);

			auto loss = criterion(output, target); // This here
			//std::cout << "Output: " << output << "\nTarget: " << target << "\n";

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
		std::cout << "Out: " << value << " -> " << boardAndTrainingValue._redWinPercent << "\n";

		return value;
	};

	while (getFileMappingVars()._mappedViewOfFile != nullptr   // No mapped file
		&& getFileMappingVars()._mappedViewOfFile->isBrainOn() // Are we supposed to be off
		&& getFileMappingVars()._mappedViewOfFile->isGameOn()) // Should we turn off
	{
		boards.clear();

		// Load Data from file
		while (getFileMappingVars()._mappedViewOfFile->_thinkStart == false)
		{
			// If there is no longer a mapped file to look at
			if (getFileMappingVars()._mappedViewOfFile == nullptr || getFileMappingVars()._mappedViewOfFile->isGameOn() == false)   // No mapped file
			{
				if (isTraining)
					saveNetwork(net, session, save);
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

		if (doDebugPrintOut)
			for (size_t i = 0; i < boards.size(); i++)
			{
				std::cout << "[" << i << "] redWinPercent: " << boards[i]._redWinPercent;
				std::cout << "\n";
			}


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

	// Save on exit
	if(isTraining)
		saveNetwork(net, session, save);
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
			getFileMappingVars()._szGame);

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