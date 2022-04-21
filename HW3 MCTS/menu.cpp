/* menu.cpp
Nathan Damon
CS 405
2/15/2022
This is the source file for the menu class which handles the menus.
*/

#include "menu.h"


void buttonDebug(std::string debugText)
{
#ifdef MENUBUTTONDEBUG
	std::cout << "[ButtonDebug] " + debugText;
#endif // MENUBUTTONDEBUG
}

// ####################################################################
// Menu
// ####################################################################

Menu::Menu()
	: _windowSize({ Board::getBoardLength(), Board::getBoardLength() }), _windowResolution(768, 768),
	_gfx(sf::VideoMode(Board::getBoardLength(), Board::getBoardLength()), "Checkers!")
{
	_gfx.setSize(sf::Vector2u(_windowResolution));
	_gfx.setPosition({ 600, 150 });

	// Load the menu button textures
	if (!_MenuTextures.loadFromFile("Menu parts.png"))
		std::cout << "Error in \"Menu parts\" image load" << std::endl;
	// Load menu background
	if (!_MenuBackGroundTexture.loadFromFile("Menu background.png"))
		std::cout << "Error in \"Menu background\" image load" << std::endl;
	_MenuBackGroundSprite.setTexture(_MenuBackGroundTexture);

	setupMiscSprites();
	setupMainMenu();
	setupOptionsMenu();
	setupReplaysMenu();
}
Menu::~Menu()
{
}

void Menu::run()
{
	// Prevents jumping straight into a game from the menu when undesired
	bool gameOn = false;
	int gameCount = 0;
	int everyTen = 10;

	_gfx.setFramerateLimit(30);
	while (_gfx.isOpen())
	{

		if (Game::getFileMappingVars()._mappedViewOfFile != nullptr && Game::getFileMappingVars()._mappedViewOfFile->isTraining())
			if (gameOn && _game == nullptr && float((std::chrono::steady_clock::now() - _menuWaitTimerStart).count()) / 1000000000.0f > _menuWaitTimerForTraining)
			{
				//std::cout << "\n\nAuto starting next Game\n\n";

				gameCount++;
				// 100 games test
				if (gameCount == everyTen)
				{
					if (everyTen == 100)
					{
						gameOn = false;
						everyTen = 0;
						gameCount = 0;
					}
					std::cout << everyTen << " games played.\n";
					everyTen += 10;
				}

				_currentState = State::Play;
			}

		_mouseButtonPressed = false;
		sf::Event event;
		while (_gfx.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				_mouseButtonPressed = true;

			if (event.type == sf::Event::Closed)
			{
				if (Game::getFileMappingVars()._hFileMap != NULL)
				{
					_game = nullptr;
					unMapFile();
				}
				_gfx.close();
			}
		}

		switch (_currentState)
		{
		case Menu::State::Main:
			// Search buttons and act
			runMainMenu();
			break;
		case Menu::State::Options:
			// Search buttons and act
			runOptionsMenu();
			break;
		case Menu::State::Replays:
			// Search buttons and act
			runReplaysMenu();
			break;
		case Menu::State::Play:
			// Run game
			if (Game::getFileMappingVars()._mappedViewOfFile != nullptr)
				if (_game != nullptr && gameOn == false)
					gameOn = true;
			runGame();
			break;
		case Menu::State::Quit: // Quit
			if (Game::getFileMappingVars()._hFileMap != NULL)
				unMapFile();
		default:
			_gfx.close();
		}
	}
}

void Menu::runMainMenu()
{
	displayMainMenu();
	if (_mouseButtonPressed)
		mainMenuButtonCheck();
}
void Menu::runOptionsMenu()
{
	displayOptionsMenu();
	if (_mouseButtonPressed)
		optionsMenuButtonCheck();
}
void Menu::runReplaysMenu()
{
	displayReplaysMenu();
	if (_mouseButtonPressed)
		replaysMenuButtonCheck();

	// If we have a board and a gameLog
	if (_replayBoard != nullptr && _gameLogs->getLogs().size() > 0)
	{
		// If we are auto stepping
		if (!_replaysIsPaused && _timeTillNextStepForward < 0.0f)
		{
			// Make step
			_timePoint = std::chrono::steady_clock::now();
			_timeTillNextStepForward = _timeInBetweenSteps;
			replayStepForwardsOnce();
		}
		else
		{
			// Reduce time till next step
			auto timeNow = std::chrono::steady_clock::now();
			_timeTillNextStepForward -= float((timeNow - _timePoint).count()) / 1000000000.0f;
			_timePoint = timeNow;
		}
	}
}
void Menu::runGame()
{
	// Game running code here
	if (_game == nullptr) // Create a new game
	{
		// Inter proccess communications check
		if (_p1Difficulty == 5 || _p2Difficulty == 5)
		{
			if (Game::getFileMappingVars()._hFileMap == NULL)
			{
				std::cout << "Error: File Map not set.\n";
				_currentState = State::Main;
				return;
			}
			else if (Game::getFileMappingVars()._mappedViewOfFile->isBrainOn() == false)
			{
				std::cout << "Error: No brain found. Run CheckersAIBrain.\n";
				_currentState = State::Main;
				return;
			}
			else
			{
				//std::cout << "Starting up Neural Net game.\n";
			}
		}

		// Set up game
		_game = std::move(std::make_unique<Game>(_gfx, getPlayer2Color(), _tournamentModeOn, _p1Difficulty, _p1Depth, _p2Difficulty, _p2Depth));
	}
	if (_game != nullptr && _game->runStep(_mouseButtonPressed))
	{
		_currentState = State::Main;
		_game = nullptr;	
		if (Game::getFileMappingVars()._mappedViewOfFile != nullptr)
		{
			if (Game::getFileMappingVars()._mappedViewOfFile->isTraining())
			{
				_menuWaitTimerStart = std::chrono::steady_clock::now();
			}
		}
	}
}

// Main menu
void Menu::setupMainMenu()
{
	// Checkers title
	sf::IntRect areaToDisplay = sf::IntRect({ 161, 20 }, { 87, 20 });
	_checkersTitle = sf::Sprite(_MenuTextures, areaToDisplay);
	_checkersTitle.setPosition(0, 30);
	centerX(_checkersTitle);

	setMainMenuButtons();
}
void Menu::displayMainMenu()
{
	_gfx.clear();
	drawMenuBackground();
	_gfx.draw(_checkersTitle);
	drawButtons(_mainMenuButtons);

	_gfx.display();
}
void Menu::setMainMenuButtons()
{
	int numMiddleButtons = 4; // 1-> -10, 2-> -22, 3-> -34, 4-> -46
	sf::Vector2<int> positionOffset = { 0, _windowSize.y / 2 - (10 + (numMiddleButtons - 1) * 12) };

	// Play 
	Button play(Button::Purpose::Play, { 164, 40 }, { 47, 20 }, _MenuTextures);
	play.setPosition(positionOffset);
	play.centerX(_windowSize);
	_mainMenuButtons.push_back(play);
	positionOffset.y += 24; // Button hieght=20 and a space between buttons of 4

	// Replays 
	Button replays(Button::Purpose::Replays, { 47, 198 }, { 77, 20 }, _MenuTextures);
	replays.setPosition(positionOffset);
	replays.centerX(_windowSize);
	_mainMenuButtons.push_back(replays);
	positionOffset.y += 24; // Button hieght=20 and a space between buttons of 4

	// Options 
	Button options(Button::Purpose::Options, { 124, 198 }, { 77, 20 }, _MenuTextures);
	options.setPosition(positionOffset);
	options.centerX(_windowSize);
	_mainMenuButtons.push_back(options);
	positionOffset.y += 24; // Button hieght=20 and a space between buttons of 4

	// Quit 
	Button quit(Button::Purpose::Quit, { 0, 198 }, { 47, 20 }, _MenuTextures);
	quit.setPosition(positionOffset);
	quit.centerX(_windowSize);
	_mainMenuButtons.push_back(quit);
	positionOffset.y += 24; // Button hieght=20 and a space between buttons of 4
}
void Menu::mainMenuButtonCheck()
{
	for (auto& button : _mainMenuButtons)
		if (button.isPressed(_gfx, _windowResolution.x / _windowSize.x))
		{
			switch (button.getPurpose())
			{
			case Button::Purpose::Play:
				_currentState = State::Play;
				return;
			case Button::Purpose::Replays:
				prepReplayMenu();
				_currentState = State::Replays;
				return;
			case Button::Purpose::Options:
				_currentState = State::Options;
				return;
			case Button::Purpose::Quit:
				_currentState = State::Quit;
				return;
			default:
				break;
			}
		}
}

// Options menu
void Menu::setupOptionsMenu()
{
	// Options title
	sf::IntRect areaToDisplay = sf::IntRect({ 124, 198 }, { 77, 20 });
	_optionsSpriteTitle = sf::Sprite(_MenuTextures, areaToDisplay);
	_optionsSpriteTitle.setPosition(0, 30);
	centerX(_optionsSpriteTitle);

	// All options sprite
	areaToDisplay = sf::IntRect({ 0, 80 }, { 194, 83 });
	_mainOptionsSprite = sf::Sprite(_MenuTextures, areaToDisplay);
	sf::Vector2<int> positionOffset = { 26, 60 };
	_mainOptionsSprite.setPosition(positionOffset.x, positionOffset.y);

	// P2Color
	areaToDisplay = sf::IntRect({ 114, 238 }, { 140, 20 });
	_p2ColorSprite = sf::Sprite(_MenuTextures, areaToDisplay);
	_p2ColorSprite.setPosition(positionOffset.x + 0, positionOffset.y + 105);
	

	// Difficulty levels

	// Randomness
	areaToDisplay = sf::IntRect({ 0, 20 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));

	// MiniMax
	areaToDisplay = sf::IntRect({ 0, 40 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));

	// Alpha Beta
	areaToDisplay = sf::IntRect({ 0, 60 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));

	// MCTS
	areaToDisplay = sf::IntRect({ 114, 60 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));

	// Player
	areaToDisplay = sf::IntRect({ 0, 238 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));

	// Neural Net
	areaToDisplay = sf::IntRect({ 0, 258 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));

	setOptionsMenuButtons();
}
void Menu::displayOptionsMenu()
{
	_gfx.clear();
	drawMenuBackground();

	_gfx.draw(_optionsSpriteTitle);
	_gfx.draw(_mainOptionsSprite);

	// Difficulties
	_difficultyLevels[_p1Difficulty].setPosition(_mainOptionsSprite.getPosition() + sf::Vector2f(46, 21));
	_gfx.draw(_difficultyLevels[_p1Difficulty]);

	_difficultyLevels[_p2Difficulty].setPosition(_mainOptionsSprite.getPosition() + sf::Vector2f(46, 63));
	_gfx.draw(_difficultyLevels[_p2Difficulty]);

	_gfx.draw(_p2ColorSprite);
	// Player 2 color
	_gfx.draw(_colorPickPieces[_p2Color]);

	// Algorithm for player 1
	if (_p1Difficulty == 1 || _p1Difficulty == 2 || _p1Difficulty == 3 || _p1Difficulty == 5)
	{
		sf::Vector2<int> optionsPositionOffset = { 26, 60 };
		sf::Vector2<int> positionOffset = { optionsPositionOffset.x + 91, optionsPositionOffset.y + 42 };

		drawNumber(_gfx, 2, _p1Depth, positionOffset);
	}
	// Algorithm for player 2
	if (_p2Difficulty == 1 || _p2Difficulty == 2 || _p2Difficulty == 3 || _p2Difficulty == 5)
	{
		sf::Vector2<int> optionsPositionOffset = { 26, 60 };
		sf::Vector2<int> positionOffset = { optionsPositionOffset.x + 91, optionsPositionOffset.y + 42 + 42 };

		drawNumber(_gfx, 2, _p2Depth, positionOffset);
	}

	drawButtons(_optionsMenuButtons);

	_gfx.display();
}
void Menu::setOptionsMenuButtons()
{
	sf::Vector2<int> positionOffset = { 26, 60 };
	sf::Vector2<int> position;

	// Tournament mode On/Off
	{
		// Tournament mode On
		Button tournamentModeOn(Button::Purpose::TournamentModeOn, { 170, 0 }, { 37, 20 }, _MenuTextures);
		position = { 157, 0 };
		tournamentModeOn.setPosition(position + positionOffset);
		tournamentModeOn.setActive(false);
		_optionsMenuButtons.push_back(tournamentModeOn);

		// Tournament mode Off
		Button tournamentModeOff(Button::Purpose::TournamentModeOff, { 207, 0 }, { 37, 20 }, _MenuTextures);
		position = { 157, 0 };
		tournamentModeOff.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(tournamentModeOff);
	}

	// Player 1 Mode
	{
		// PlayerMode left arrow 
		Button playerColorLeftArrow(Button::Purpose::Player1ModeLeftArrow, { 114, 40 }, { 15, 15 }, _MenuTextures);
		position = { 29, 24 };
		playerColorLeftArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(playerColorLeftArrow);

		// PlayerMode right arrow 
		Button playerColorRightArrow(Button::Purpose::Player1ModeRightArrow, { 129, 40 }, { 15, 15 }, _MenuTextures);
		position = { 162, 24 };
		playerColorRightArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(playerColorRightArrow);
	}

	// Player 2 Mode
	{
		// PlayerMode left arrow 
		Button playerColorLeftArrow(Button::Purpose::Player2ModeLeftArrow, { 114, 40 }, { 15, 15 }, _MenuTextures);
		position = { 29, 66 };
		playerColorLeftArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(playerColorLeftArrow);

		// PlayerMode right arrow 
		Button playerColorRightArrow(Button::Purpose::Player2ModeRightArrow, { 129, 40 }, { 15, 15 }, _MenuTextures);
		position = { 162, 66 };
		playerColorRightArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(playerColorRightArrow);
	}

	// Player 2 Color
	{
		// Player 2 Color left arrow 
		Button opponentColorLeftArrow(Button::Purpose::Player2ColorLeftArrow, { 114, 40 }, { 15, 15 }, _MenuTextures);
		position = { 86, 108 };
		opponentColorLeftArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(opponentColorLeftArrow);

		// Player 2 Color right arrow 
		Button opponentColorRightArrow(Button::Purpose::Player2ColorRightArrow, { 129, 40 }, { 15, 15 }, _MenuTextures);
		position = { 86 + 39, 108 };
		opponentColorRightArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(opponentColorRightArrow);
	}


	// Player 1 Difficulty - DepthShift
	{
		// Difficulty
		Button p1DifficultyDepthLeftArrow(Button::Purpose::P1DepthShiftLeftArrow, { 114, 40 }, { 15, 15 }, _MenuTextures);
		position = { 74, 45 };
		p1DifficultyDepthLeftArrow.setPosition(position + positionOffset);
		p1DifficultyDepthLeftArrow.setActive(false);
		_optionsMenuButtons.push_back(p1DifficultyDepthLeftArrow);

		// Difficulty
		Button p1DifficultyDepthRightArrow(Button::Purpose::P1DepthShiftRightArrow, { 129, 40 }, { 15, 15 }, _MenuTextures);
		position = { 75 + 46, 45 };
		p1DifficultyDepthRightArrow.setPosition(position + positionOffset);
		p1DifficultyDepthRightArrow.setActive(false);
		_optionsMenuButtons.push_back(p1DifficultyDepthRightArrow);
	}

	// Player 2 Difficulty - DepthShift
	{
		// Difficulty
		Button p2DifficultyDepthLeftArrow(Button::Purpose::P2DepthShiftLeftArrow, { 114, 40 }, { 15, 15 }, _MenuTextures);
		position = { 74, 46 + 41 };
		p2DifficultyDepthLeftArrow.setPosition(position + positionOffset);
		p2DifficultyDepthLeftArrow.setActive(false);
		_optionsMenuButtons.push_back(p2DifficultyDepthLeftArrow);

		// Difficulty
		Button p2DifficultyDepthRightArrow(Button::Purpose::P2DepthShiftRightArrow, { 129, 40 }, { 15, 15 }, _MenuTextures);
		position = { 75 + 46, 46 + 41 };
		p2DifficultyDepthRightArrow.setPosition(position + positionOffset);
		p2DifficultyDepthRightArrow.setActive(false);
		_optionsMenuButtons.push_back(p2DifficultyDepthRightArrow);
	}

	// Back
	{
		Button back(Button::Purpose::Back, { 114, 20 }, { 47, 20 }, _MenuTextures);
		position = { 0, _windowSize.y - 50 };
		back.setPosition(position);
		back.centerX(_windowSize);
		_optionsMenuButtons.push_back(back);
	}
}
void Menu::optionsMenuButtonCheck()
{
	for (auto& button : _optionsMenuButtons)
		if (button.isPressed(_gfx, _windowResolution.x / _windowSize.x))
		{
			switch (button.getPurpose())
			{
			case Menu::Button::Purpose::TournamentModeOn:
				_tournamentModeOn = false; // It is the opposite because we see that it is on and want to turn it off
				getButton(Button::Purpose::TournamentModeOff, _optionsMenuButtons)->setActive(true);
				button.setActive(false);
				return;
			case Menu::Button::Purpose::TournamentModeOff:
				_tournamentModeOn = true; // It is the opposite because we see that it is off and want to turn it on
				getButton(Button::Purpose::TournamentModeOn, _optionsMenuButtons)->setActive(true);
				button.setActive(false);
				return;



			case Menu::Button::Purpose::Player1ModeLeftArrow:
				player1ModeShift(-1);
				return;
			case Menu::Button::Purpose::Player1ModeRightArrow:
				player1ModeShift(1);
				return;

			case Menu::Button::Purpose::Player2ModeLeftArrow:
				player2ModeShift(-1);
				return;
			case Menu::Button::Purpose::Player2ModeRightArrow:
				player2ModeShift(1);
				return;



			case Menu::Button::Purpose::Player2ColorLeftArrow:
				player2ColorShift(-1);
				return;
			case Menu::Button::Purpose::Player2ColorRightArrow:
				player2ColorShift(1);
				return;



			case Menu::Button::Purpose::P1DepthShiftLeftArrow:
				player1DepthShift(-1);
				return;
			case Menu::Button::Purpose::P1DepthShiftRightArrow:
				player1DepthShift(1);
				return;

			case Menu::Button::Purpose::P2DepthShiftLeftArrow:
				player2DepthShift(-1);
				return;
			case Menu::Button::Purpose::P2DepthShiftRightArrow:
				player2DepthShift(1);
				return;



			case Button::Purpose::Back:
				// Create the file mapping for the Neural Network
				if (_p1Difficulty == 5 || _p2Difficulty == 5)
				{
					if (Game::getFileMappingVars()._hFileMap == NULL)
						createMappedFile();
					std::cout << "Start CheckersAIBrain before clicking play.\n";
				}
				else
				{
					if (Game::getFileMappingVars()._hFileMap != NULL)
						unMapFile();
				}

				_currentState = State::Main;
				return;
			default:
				break;
			}
		}
}

// Replays menu
void Menu::setupReplaysMenu()
{
	// Replays title
	sf::IntRect areaToDisplay = sf::IntRect({ 47, 198 }, { 77, 20 });
	_replaysSpriteTitle = sf::Sprite(_MenuTextures, areaToDisplay);
	_replaysSpriteTitle.setPosition(0, 30);
	centerX(_replaysSpriteTitle);

	setReplaysMenuButtons();
}
void Menu::displayReplaysMenu()
{
	_gfx.clear();
	drawMenuBackground();
	_gfx.draw(_replaysSpriteTitle);

	drawNumber(_gfx, 7, _gameLogIndex + 1, { (_windowSize.x - (3 + 7 * 11 + 3)) / 2, 52 });

	if (_replayBoard)
	{
		// Scale and position the board to the center
		float scale = 0.5f;
		auto xPos = (float(_windowSize.x) - float(Board::getBoardLength()) * scale) / 2.0f;
		auto yPos = (float(_windowSize.y) - float(Board::getBoardLength()) * scale) / 2.0f;
		_replayBoard->drawSelf(_gfx, scale, {xPos, yPos + 10});
	}
	drawButtons(_replaysMenuButtons);

	_gfx.display();
}
void Menu::setReplaysMenuButtons()
{
	int numButtons = 8; // 1-> -10, 2-> -22, 3-> -34, 4-> -46
	sf::Vector2<int> positionOffset = { _windowSize.x / 2 - (10 + (numButtons - 1) * 12), 206 }; // Far left start of buttons
	int buttonNum;

	// Game index change
	{
		// Previous game
		buttonNum = 0;
		Button previousGame(Button::Purpose::PreviousGame, { buttonNum * 20, 218 }, { 20, 20 }, _MenuTextures);
		previousGame.setPosition(sf::Vector2<int>(buttonNum * 24, 0) + positionOffset);
		_replaysMenuButtons.push_back(previousGame);

		// Next game 
		buttonNum = 7;
		Button nextGame(Button::Purpose::NextGame, { buttonNum * 20, 218 }, { 20, 20 }, _MenuTextures);
		nextGame.setPosition(sf::Vector2<int>(buttonNum * 24, 0) + positionOffset);
		_replaysMenuButtons.push_back(nextGame);
	}

	// Game move index change
	{
		// Back One Move
		buttonNum = 2;
		Button backOneMove(Button::Purpose::BackOneMove, { buttonNum * 20, 218 }, { 20, 20 }, _MenuTextures);
		backOneMove.setPosition(sf::Vector2<int>(buttonNum * 24, 0) + positionOffset);
		_replaysMenuButtons.push_back(backOneMove);

		// Forward One Move 
		buttonNum = 5;
		Button forwardOneMove(Button::Purpose::ForwardOneMove, { buttonNum * 20, 218 }, { 20, 20 }, _MenuTextures);
		forwardOneMove.setPosition(sf::Vector2<int>(buttonNum * 24, 0) + positionOffset);
		_replaysMenuButtons.push_back(forwardOneMove);

		// Jump Back Five Moves
		buttonNum = 1;
		Button jumpBackFiveMoves(Button::Purpose::JumpBackFiveMoves, { buttonNum * 20, 218 }, { 20, 20 }, _MenuTextures);
		jumpBackFiveMoves.setPosition(sf::Vector2<int>(buttonNum * 24, 0) + positionOffset);
		_replaysMenuButtons.push_back(jumpBackFiveMoves);

		// Jump Forward Five Moves 
		buttonNum = 6;
		Button jumpForwardFiveMoves(Button::Purpose::JumpForwardFiveMoves, { buttonNum * 20, 218 }, { 20, 20 }, _MenuTextures);
		jumpForwardFiveMoves.setPosition(sf::Vector2<int>(buttonNum * 24, 0) + positionOffset);
		_replaysMenuButtons.push_back(jumpForwardFiveMoves);
	}

	// Pause and Play of replay
	{
		// Pause Replay
		buttonNum = 3;
		Button pauseReplay(Button::Purpose::PauseReplay, { buttonNum * 20, 218 }, { 20, 20 }, _MenuTextures);
		pauseReplay.setPosition(sf::Vector2<int>(buttonNum * 24, 0) + positionOffset);
		_replaysMenuButtons.push_back(pauseReplay);

		// Play Replay
		buttonNum = 4;
		Button playReplay(Button::Purpose::PlayReplay, { buttonNum * 20, 218 }, { 20, 20 }, _MenuTextures);
		playReplay.setPosition(sf::Vector2<int>(buttonNum * 24, 0) + positionOffset);
		_replaysMenuButtons.push_back(playReplay);
	}

	// Return to main menu
	{
		// Return To Main
		buttonNum = 8; // Not with other buttons though
		Button returnToMain(Button::Purpose::ReturnToMain, { buttonNum * 20, 218 }, { 20, 20 }, _MenuTextures);
		returnToMain.setPosition(sf::Vector2<int>(206, 30));
		_replaysMenuButtons.push_back(returnToMain);
	}
}
void Menu::replaysMenuButtonCheck()
{
	for (auto& button : _replaysMenuButtons)
		if (button.isPressed(_gfx, _windowResolution.x / _windowSize.x))
		{
			switch (button.getPurpose())
			{
			case Menu::Button::Purpose::PreviousGame:
				buttonDebug("Previous Game\n");
				if (_gameLogIndex == 0)
					_gameLogIndex = _gameLogs->getLogs().size() - 1;
				else
					--_gameLogIndex;

				_gameLogMoveIndex = 0; // Reset move index on game change
				setReplayBoard();
				return;
			case Menu::Button::Purpose::NextGame:
				buttonDebug("Next Game\n");
				if (_gameLogIndex == _gameLogs->getLogs().size() - 1)
					_gameLogIndex = 0;
				else
					++_gameLogIndex;

				_gameLogMoveIndex = 0; // Reset move index on game change
				setReplayBoard();
				return;

			case Menu::Button::Purpose::BackOneMove:
				buttonDebug("Step Backward Once\n");
				replayStepBackwardsOnce();
				return;
			case Menu::Button::Purpose::ForwardOneMove:
				buttonDebug("Step Forward Once\n");
				replayStepForwardsOnce();
				return;
			case Menu::Button::Purpose::JumpBackFiveMoves:				
				buttonDebug("Step Back Five Times\n");
				for (size_t i = 0; i < 5; i++)
					replayStepBackwardsOnce();
				return;
			case Menu::Button::Purpose::JumpForwardFiveMoves:
				buttonDebug("Step Forward Five Times\n");
				for (size_t i = 0; i < 5; i++)
					replayStepForwardsOnce();
				return;

			case Menu::Button::Purpose::PauseReplay:
				buttonDebug("Pause Replay\n");
				_replaysIsPaused = true;
				return;
			case Menu::Button::Purpose::PlayReplay:
				buttonDebug("Play Replay\n");
				_replaysIsPaused = false;
				return;


			case Button::Purpose::ReturnToMain:
				buttonDebug("Return To Main\n");
				exitReplays();
				return;
			default:
				break;
			}
		}
}


void Menu::drawMenuBackground()
{
	_gfx.draw(_MenuBackGroundSprite);
}
void Menu::drawButtons(std::vector<Button>& buttons)
{
	for (auto& button : buttons)
		if (button.isActive())
			button.draw(_gfx);
}
void Menu::drawNumber(sf::RenderWindow& gfx, int digitCount, int number, sf::Vector2<int> positionOffset)
{
	sf::Vector2<int> pos = { 0, 0 };

	_leftBorder.setPosition(pos.x + positionOffset.x, pos.y + positionOffset.y);
	pos.x += _leftBorder.getTextureRect().width;
	_gfx.draw(_leftBorder);

	int digit = 10;
	for (size_t i = 0; i < digitCount - 1; i++)
		digit *= 10;

	for (size_t i = 0; i < digitCount; i++)
	{
		int digitValue = (number % digit * 10) / digit;

		if (digitValue >= 0 && digitValue < 10)
		{
			_numbers0To9[digitValue].setPosition(pos.x + positionOffset.x, pos.y + positionOffset.y);
			_gfx.draw(_numbers0To9[digitValue]);
		}

		pos.x += _numbers0To9[0].getTextureRect().width;
		digit /= 10;
	}
	
	_rightBorder.setPosition(pos.x + positionOffset.x, pos.y + positionOffset.y);
	_gfx.draw(_rightBorder);
}

Menu::Button* Menu::getButton(Button::Purpose purpose, std::vector<Button>& buttons)
{
	for (auto& button : buttons)
		if (button.getPurpose() == purpose)
			return &button;
	return nullptr;
}

void Menu::setupMiscSprites()
{
	sf::Vector2<int> optionsPositionOffset = { 26, 60 };
	sf::IntRect areaToDisplay;

	// Specifically offset for the options menu
	sf::Vector2<int> positionOffset = { optionsPositionOffset.x + 17 + 47, optionsPositionOffset.y + 97 + 21 };

	// Borders
	{
		// LeftBorder
		areaToDisplay = sf::IntRect({ 0, 0 }, { 3, 20 });
		_leftBorder.setTexture(_MenuTextures);
		_leftBorder.setTextureRect(areaToDisplay);

		// RightBorder
		areaToDisplay = sf::IntRect({ 14, 0 }, { 3, 20 });
		_rightBorder.setTexture(_MenuTextures);
		_rightBorder.setTextureRect(areaToDisplay);
	}

	// Numbers 0-9
	areaToDisplay = sf::IntRect({ 3, 0 }, { 11, 20 });
	for (size_t i = 0; i < 10; i++)
	{
		areaToDisplay.left = 3 + i * 17; // Position in row
		sf::Sprite num(_MenuTextures, areaToDisplay);
		num.setPosition(positionOffset.x, positionOffset.y);
		_numbers0To9.push_back(num);
	}

	// Pieces to display player colors in the options menu
	positionOffset = { optionsPositionOffset.x + 106, optionsPositionOffset.y + 108};
	areaToDisplay = sf::IntRect({ 211, 40 }, { 14, 14 });
	for (size_t i = 0; i < 3; i++)
	{
		if (i != 0)
			areaToDisplay.left += 14; // Position in row
		sf::Sprite piece(_MenuTextures, areaToDisplay);
		piece.setPosition(positionOffset.x, positionOffset.y);
			_colorPickPieces.push_back(piece);
	}
}
void Menu::centerX(sf::Sprite& sprite)
{
	sprite.setPosition((_windowSize.x - sprite.getLocalBounds().width) / 2, sprite.getPosition().y);
}
void Menu::centerY(sf::Sprite& sprite)
{
	sprite.setPosition(sprite.getPosition().x, (_windowSize.y - sprite.getLocalBounds().height) / 2);
}

// Options menu functionality
void Menu::player1ModeShift(int shift)
{
	_p1Difficulty += shift;
	if (_p1Difficulty >= _difficultyCount)
		_p1Difficulty = 0;
	if (_p1Difficulty < 0)
		_p1Difficulty = _difficultyCount - 1;

	// Cannot support 2 players
	if (_p1Difficulty == 4 && _p2Difficulty == 4)
		player2ModeShift(1);

	if (_p1Difficulty == 1 || _p1Difficulty == 2 || _p1Difficulty == 3 || _p1Difficulty == 5) // DepthShift
	{
		getButton(Button::Purpose::P1DepthShiftLeftArrow, _optionsMenuButtons)->setActive(true);
		getButton(Button::Purpose::P1DepthShiftRightArrow, _optionsMenuButtons)->setActive(true);
	}
	else
	{
		getButton(Button::Purpose::P1DepthShiftLeftArrow, _optionsMenuButtons)->setActive(false);
		getButton(Button::Purpose::P1DepthShiftRightArrow, _optionsMenuButtons)->setActive(false);
	}		
}
void Menu::player2ModeShift(int shift)
{
	_p2Difficulty += shift;
	if (_p2Difficulty >= _difficultyCount)
		_p2Difficulty = 0;
	if (_p2Difficulty < 0)
		_p2Difficulty = _difficultyCount - 1;

	// Cannot support 2 players
	if (_p2Difficulty == 4 && _p1Difficulty == 4)
		player1ModeShift(1);

	if (_p2Difficulty == 1 || _p2Difficulty == 2 || _p2Difficulty == 3 || _p2Difficulty == 5) // DepthShift
	{
		getButton(Button::Purpose::P2DepthShiftLeftArrow, _optionsMenuButtons)->setActive(true);
		getButton(Button::Purpose::P2DepthShiftRightArrow, _optionsMenuButtons)->setActive(true);
	}
	else
	{
		getButton(Button::Purpose::P2DepthShiftLeftArrow, _optionsMenuButtons)->setActive(false);
		getButton(Button::Purpose::P2DepthShiftRightArrow, _optionsMenuButtons)->setActive(false);
	}
}
void Menu::player2ColorShift(int shift)
{
	_p2Color += shift;
	if (_p2Color > 2)
		_p2Color = 1;
	if (_p2Color < 1)
		_p2Color = 2;
}
void Menu::player1DepthShift(int shift)
{
	_p1Depth += shift;
	if (_p1Depth > 99)
		_p1Depth = 1;
	if (_p1Depth < 1)
		_p1Depth = 99;
}
void Menu::player2DepthShift(int shift)
{
	_p2Depth += shift;
	if (_p2Depth > 99)
		_p2Depth = 1;
	if (_p2Depth < 1)
		_p2Depth = 99;
}

Game::PlayerColor Menu::getPlayer1Color()
{
	return Game::PlayerColor::Red;
}
Game::PlayerColor Menu::getPlayer2Color()
{
	if (_p2Color == 1) // Black
		return Game::PlayerColor::Black;
	else // White
		return Game::PlayerColor::White;
}


// Replays menu functionality
void Menu::prepReplayMenu()
{
	// Get the game logs
	_gameLogs = std::move(std::make_unique<GameLogs>());
	_gameLogs->loadGameLogs();

	// Most recent game log
	_gameLogIndex = _gameLogs->getLogs().size() - 1;

	setReplayBoard();
}
void Menu::replayStepForwardsOnce()
{
	if (_gameLogMoveIndex < _gameLogs->getLogs()[_gameLogIndex]->_movesMade.size())
	{
		auto move = _gameLogs->getLogs()[_gameLogIndex]->_movesMade[_gameLogMoveIndex];

		// Add piece that is about to be removed to the list of pieces that might need to be re-added in the case of stepping backwards
		if (move.z != -1)
			_piecesRemoved.push_back(_replayBoard->getPieceAt(move.z));

		// Move piece
		_replayBoard->movePiece(move);

		++_gameLogMoveIndex;
	}
}
void Menu::replayStepBackwardsOnce()
{
	if (_gameLogMoveIndex > 0 )
	{
		// Undoing the previous move (so index - 1)
		auto moveToUndo = _gameLogs->getLogs()[_gameLogIndex]->_movesMade[_gameLogMoveIndex - 1];
		// Reverse the move
		_replayBoard->movePiece({ moveToUndo.y, moveToUndo.x, -1 });

		// Add removed piece back and pop it from piecesRemoved list
		if (moveToUndo.z != -1)
		{
			_replayBoard->placePieceAt(moveToUndo.z, _piecesRemoved.back());
			_piecesRemoved.pop_back();
		}

		--_gameLogMoveIndex;
	}
}
void Menu::setReplayBoard()
{
	bool team2IsBlack = true;
	if (_gameLogs->getLogs()[_gameLogIndex]->_p2Color == 'W')
		team2IsBlack = false;

	_replayBoard = std::move(std::make_unique<Board>(team2IsBlack));

	int startingBoard = _gameLogs->getLogs()[_gameLogIndex]->_startingBoard;
	if(startingBoard != -1)
		_replayBoard->setup(Game::getTournamentBoards()[startingBoard]);
}
void Menu::exitReplays()
{
	_gameLogs = nullptr;
	_replayBoard = nullptr;
	_piecesRemoved.clear();
	_currentState = State::Main;
}

// Options menu Neural Network fileMapping
bool Menu::createMappedFile()
{
	bool retBool = true;

	std::cout << "\t\t....Mapping File (Opening)...." << std::endl;
	std::cout << std::endl;

	CheckersIPC checkersIPC[1];

	// Create File Map
	Game::getFileMappingVars()._hFileMap = 
		 CreateFileMapping(
			INVALID_HANDLE_VALUE,
			NULL,
			PAGE_READWRITE,
			0,
			 Game::getFileMappingVars()._szIPC,
			TEXT("Local\\CheckersFileMap")
		);

	if (Game::getFileMappingVars()._hFileMap == FALSE)
	{
		std::cout << "CreateFileMapping Failed & Error NO - " << GetLastError() << std::endl;
		retBool = false;
	}
	else
	{
		std::cout << "CreateFileMapping Success" << std::endl;

		// MapViewOfFile
		Game::getFileMappingVars()._mappedViewOfFile = (CheckersIPC*)MapViewOfFile(
			Game::getFileMappingVars()._hFileMap,
			FILE_MAP_ALL_ACCESS,
			0,
			0,
			Game::getFileMappingVars()._szIPC);

		if (Game::getFileMappingVars()._mappedViewOfFile == NULL)
		{
			std::cout << "MapViewOfFile Failed & Error NO - " << GetLastError() << std::endl;
			retBool = false;
		}
		else
			std::cout << "MapViewOfFile Success" << std::endl;
	}

	// Copy Memory Function
	MoveMemory(Game::getFileMappingVars()._mappedViewOfFile, checkersIPC, Game::getFileMappingVars()._szIPC);

	Game::getFileMappingVars()._mappedViewOfFile->setGameOnOff(true);

	// Do we want to train?
	bool doTraining = false;
	if (doTraining)
	{
		std::cout << "Training -> ON.\n";
		Game::getFileMappingVars()._mappedViewOfFile->setTrainingOnOff(doTraining);
	}
	else
	{
		std::cout << "Training -> OFF.\n";
		Game::getFileMappingVars()._mappedViewOfFile->setTrainingOnOff(false);
	}

	return retBool;
}
bool Menu::unMapFile()
{
	bool retBool = true;

	std::cout << "\t\t....UnMapping File (Closing)...." << std::endl;
	std::cout << std::endl;

	Game::getFileMappingVars()._mappedViewOfFile->setBrainOnOff(false);
	Game::getFileMappingVars()._mappedViewOfFile->setGameOnOff(false);
	
	// Wait for brain to turn off to prevent access violations
	std::cout << "Waiting for brain to turn off";
	while (Game::getFileMappingVars()._mappedViewOfFile->isBrainOn())
	{
		Sleep(0050);
		std::cout << ".";
	}
	std::cout << "\n";


	// UnMapViewOfFile
	Game::getFileMappingVars()._bResultOfMapping = UnmapViewOfFile(Game::getFileMappingVars()._mappedViewOfFile);
	if (Game::getFileMappingVars()._bResultOfMapping == FALSE)
	{
		std::cout << "UnMapViewOfFile Failed & Error No - " << GetLastError() << std::endl;
		retBool = false;
	}
	else
		std::cout << "UnMapViewOfFile Success" << std::endl;


	// Close Handle
	CloseHandle(Game::getFileMappingVars()._hFileMap);

	Game::getFileMappingVars()._hFileMap = NULL;

	return retBool;
}

// ####################################################################
// Menu::Button
// ####################################################################


Menu::Button::Button(Purpose purpose, sf::Vector2<int> sourcePosition, sf::Vector2<int> sourceDimensions, sf::Texture& menuButtonTextures)
	: _purpose(purpose)
{
	// Set sprite
	_buttonSprite.setTexture(menuButtonTextures);
	// Set part of sprite to display
	sf::IntRect areaToDisplay(sourcePosition, sourceDimensions);
	_buttonSprite.setTextureRect(areaToDisplay);
}
Menu::Button::~Button()
{
}

const bool Menu::Button::isPressed(sf::RenderWindow& gfx, int scale, sf::Vector2<int> screenOffset)
{
	if (_active)
		return isPosWithin(((sf::Mouse::getPosition() - gfx.getPosition()) + screenOffset) / scale);
	return false;
}
void Menu::Button::draw(sf::RenderWindow& gfx)
{
	gfx.draw(_buttonSprite);
}

void Menu::Button::setActive(bool isActive)
{
	_active = isActive;
}
bool Menu::Button::isActive()
{
	return _active;
}
Menu::Button::Purpose Menu::Button::getPurpose()
{
	return _purpose;
}

void Menu::Button::setPosition(sf::Vector2<int> newPosition)
{
	_buttonSprite.setPosition(sf::Vector2<float>(newPosition));
}
sf::Vector2<int> Menu::Button::getPosition()
{
	return sf::Vector2<int>(_buttonSprite.getPosition());
}

void Menu::Button::centerX(sf::Vector2<int> windowSize)
{
	setPosition({ (windowSize.x - (int)_buttonSprite.getLocalBounds().width) / 2, getPosition().y });
}
void Menu::Button::centerY(sf::Vector2<int> windowSize)
{
	setPosition({ getPosition().x, (windowSize.y - (int)_buttonSprite.getLocalBounds().height) / 2 });
}

const bool Menu::Button::isPosWithin(const sf::Vector2<int> mousePositionOnScreen)
{
	auto pos = mousePositionOnScreen - getPosition();
	if (pos.x >= 0 && pos.x < _buttonSprite.getTextureRect().width)
		if (pos.y >= 0 && pos.y < _buttonSprite.getTextureRect().height)
			return true;
	return false;
}