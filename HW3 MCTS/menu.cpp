/* menu.cpp
Nathan Damon
CS 405
2/15/2022
This is the source file for the menu class which handles the menus.
*/

#include "menu.h"

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
	_gfx.setFramerateLimit(30);
	while (_gfx.isOpen())
	{
		_mouseButtonPressed = false;
		sf::Event event;
		while (_gfx.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
				_mouseButtonPressed = true;

			if (event.type == sf::Event::Closed)
				_gfx.close();
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
			// Pass the bool to game
			runGame();
			break;
		case Menu::State::Quit: // Quit
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
		_game = std::move(std::make_unique<Game>(_gfx, getPlayer1Color(), getPlayer2Color(), _tournamentModeOn, _difficulty, _depth));
		_game->enableDebugPrintout(true);
	}
	if (_game != nullptr && _game->runStep(_mouseButtonPressed))
	{
		_currentState = State::Main;
		_game = nullptr;	
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
	areaToDisplay = sf::IntRect({ 0, 81 }, { 202, 117 });
	_mainOptionsSprite = sf::Sprite(_MenuTextures, areaToDisplay);
	sf::Vector2<int> positionOffset = { 26, 60 };
	_mainOptionsSprite.setPosition(positionOffset.x, positionOffset.y);



	// Difficulty levels

	// Randomness
	areaToDisplay = sf::IntRect({ 0, 20 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));
	_difficultyLevels.back().setPosition(positionOffset.x + 17, positionOffset.y + 97);

	// MiniMax
	areaToDisplay = sf::IntRect({ 0, 40 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));
	_difficultyLevels.back().setPosition(positionOffset.x + 17, positionOffset.y + 97);

	// Alpha Beta
	areaToDisplay = sf::IntRect({ 0, 60 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));
	_difficultyLevels.back().setPosition(positionOffset.x + 17, positionOffset.y + 97);

	// MCTS
	areaToDisplay = sf::IntRect({ 114, 60 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));
	_difficultyLevels.back().setPosition(positionOffset.x + 17, positionOffset.y + 97);

	setOptionsMenuButtons();
}
void Menu::displayOptionsMenu()
{
	_gfx.clear();
	drawMenuBackground();

	_gfx.draw(_optionsSpriteTitle);
	_gfx.draw(_mainOptionsSprite);
	_gfx.draw(_difficultyLevels[_difficulty]);

	// Player color
	_gfx.draw(_playerPieces[_playerColor]);
	_gfx.draw(_opponentPieces[_opponentColor]);

	// Minimax or AlphaBeta or MCTS
	if (_difficulty == 1 || _difficulty == 2 || _difficulty == 3)
	{
		sf::Vector2<int> optionsPositionOffset = { 26, 60 };
		sf::Vector2<int> positionOffset = { optionsPositionOffset.x + 12 + 47, optionsPositionOffset.y + 97 + 21 };

		drawNumber(_gfx, 2, _depth, positionOffset);
	}

	drawButtons(_optionsMenuButtons);

	_gfx.display();
}
void Menu::setOptionsMenuButtons()
{
	sf::Vector2<int> positionOffset = { 26, 60 };
	sf::Vector2<int> position;


	// Player Color
	{
		// PlayerColor left arrow 
		Button playerColorLeftArrow(Button::Purpose::PlayerColorLeftArrow, { 114, 40 }, { 15, 15 }, _MenuTextures);
		position = { 148, 3 };
		playerColorLeftArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(playerColorLeftArrow);

		// PlayerColor right arrow 
		Button playerColorRightArrow(Button::Purpose::PlayerColorRightArrow, { 129, 40 }, { 15, 15 }, _MenuTextures);
		position = { 187, 3 };
		playerColorRightArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(playerColorRightArrow);
	}

	// Opponent Color
	{
		// OpponentColor left arrow 
		Button opponentColorLeftArrow(Button::Purpose::OpponentColorLeftArrow, { 114, 40 }, { 15, 15 }, _MenuTextures);
		position = { 148, 26 };
		opponentColorLeftArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(opponentColorLeftArrow);

		// OpponentColor right arrow 
		Button opponentColorRightArrow(Button::Purpose::OpponentColorRightArrow, { 129, 40 }, { 15, 15 }, _MenuTextures);
		position = { 187, 26 };
		opponentColorRightArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(opponentColorRightArrow);
	}

	// Tournament mode On/Off
	{
		// Tournament mode On
		Button tournamentModeOn(Button::Purpose::TournamentModeOn, { 170, 0 }, { 37, 20 }, _MenuTextures);
		position = { 157, 49 };
		tournamentModeOn.setPosition(position + positionOffset);
		tournamentModeOn.setActive(false);
		_optionsMenuButtons.push_back(tournamentModeOn);

		// Tournament mode Off
		Button tournamentModeOff(Button::Purpose::TournamentModeOff, { 207, 0 }, { 37, 20 }, _MenuTextures);
		position = { 157, 49 };
		tournamentModeOff.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(tournamentModeOff);
	}

	// Difficulty
	{
		// Difficulty left arrow
		Button difficultyLeftArrow(Button::Purpose::DifficultyLeftArrow, { 114, 40 }, { 15, 15 }, _MenuTextures);
		position = { 0, 100 };
		difficultyLeftArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(difficultyLeftArrow);

		// Difficulty right arrow
		Button difficultyRightArrow(Button::Purpose::DifficultyRightArrow, { 129, 40 }, { 15, 15 }, _MenuTextures);
		position = { 133, 100 };
		difficultyRightArrow.setPosition(position + positionOffset);
		_optionsMenuButtons.push_back(difficultyRightArrow);
	}

	// Difficulty - DepthShift
	{
		// Difficulty - Muscle Head left arrow
		Button difficultyMuscleHeadLeftArrow(Button::Purpose::DepthShiftLeftArrow, { 114, 40 }, { 15, 15 }, _MenuTextures);
		position = { 12 + 31, 97 + 24 };
		difficultyMuscleHeadLeftArrow.setPosition(position + positionOffset);
		difficultyMuscleHeadLeftArrow.setActive(false);
		_optionsMenuButtons.push_back(difficultyMuscleHeadLeftArrow);

		// Difficulty - Muscle Head right arrow
		Button difficultyMuscleHeadRightArrow(Button::Purpose::DepthShiftRightArrow, { 129, 40 }, { 15, 15 }, _MenuTextures);
		position = { 23 + 65, 97 + 24 };
		difficultyMuscleHeadRightArrow.setPosition(position + positionOffset);
		difficultyMuscleHeadRightArrow.setActive(false);
		_optionsMenuButtons.push_back(difficultyMuscleHeadRightArrow);
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
			case Menu::Button::Purpose::PlayerColorLeftArrow:
				playerColorShift(-1);
				return;
			case Menu::Button::Purpose::PlayerColorRightArrow:
				playerColorShift(1);
				return;


			case Menu::Button::Purpose::OpponentColorLeftArrow:
				opponentColorShift(-1);
				return;
			case Menu::Button::Purpose::OpponentColorRightArrow:
				opponentColorShift(1);
				return;


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


			case Menu::Button::Purpose::DifficultyLeftArrow:
				difficultyShift(-1);
				return;
			case Menu::Button::Purpose::DifficultyRightArrow:
				difficultyShift(1);
				return;

			case Menu::Button::Purpose::DepthShiftLeftArrow:
				depthShift(-1);
				return;
			case Menu::Button::Purpose::DepthShiftRightArrow:
				depthShift(1);
				return;
			case Button::Purpose::Back:
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
				if (_gameLogIndex == 0)
					_gameLogIndex = _gameLogs->getLogs().size() - 1;
				else
					--_gameLogIndex;

				_gameLogMoveIndex = 0; // Reset move index on game change
				setReplayBoard();
				return;
			case Menu::Button::Purpose::NextGame:
				if (_gameLogIndex == _gameLogs->getLogs().size() - 1)
					_gameLogIndex = 0;
				else
					++_gameLogIndex;

				_gameLogMoveIndex = 0; // Reset move index on game change
				setReplayBoard();
				return;

			case Menu::Button::Purpose::BackOneMove:
				replayStepBackwardsOnce();
				std::cout << "Step Backward Once\n";
				return;
			case Menu::Button::Purpose::ForwardOneMove:
				replayStepForwardsOnce();
				std::cout << "Step Forward Once\n";
				return;
			case Menu::Button::Purpose::JumpBackFiveMoves:
				for (size_t i = 0; i < 5; i++)
					replayStepBackwardsOnce();
				return;
			case Menu::Button::Purpose::JumpForwardFiveMoves:
				for (size_t i = 0; i < 5; i++)
					replayStepForwardsOnce();
				return;

			case Menu::Button::Purpose::PauseReplay:
				_replaysIsPaused = true;
				std::cout << "Pause Replay\n";
				return;
			case Menu::Button::Purpose::PlayReplay:
				_replaysIsPaused = false;
				std::cout << "Play Replay\n";
				return;


			case Button::Purpose::ReturnToMain:
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
	for (int j = 0; j < 2; j++)
	{
		positionOffset = { optionsPositionOffset.x + 168, optionsPositionOffset.y + 3 + 23 * j };

		areaToDisplay = sf::IntRect({ 211, 40 }, { 14, 14 });
		for (size_t i = 0; i < 3; i++)
		{
			if (i != 0)
				areaToDisplay.left += 14; // Position in row
			sf::Sprite piece(_MenuTextures, areaToDisplay);
			piece.setPosition(positionOffset.x, positionOffset.y);
			if (j == 0)
				_playerPieces.push_back(piece);
			else
				_opponentPieces.push_back(piece);
		}
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
Game::PlayerColor Menu::getPlayer1Color()
{
	if (_cPU_PlayerGame)
		return Game::PlayerColor::CPU_playerGame;
	if (_playerColor == 0) // Red
		return Game::PlayerColor::Red;
	else if (_playerColor == 1)
		return Game::PlayerColor::Black;
	else
		return Game::PlayerColor::White;
}
Game::PlayerColor Menu::getPlayer2Color()
{
	if (_playerColor == 1 || _opponentColor == 1) // Black
		return Game::PlayerColor::Black;
	else if (_playerColor == 2 || _opponentColor == 2) // White
		return Game::PlayerColor::White;
}

void Menu::playerColorShift(int shift)
{
	_playerColor += shift;
	if (_playerColor > 2)
		_playerColor = 0;
	if (_playerColor < 0)
		_playerColor = 2;

	if (_playerColor == 0 && _opponentColor == 0) // Both red
		_opponentColor = 1; // Black
	if (_playerColor > 0 && _opponentColor > 0) // Both black or white
		_opponentColor = 0; // Red
}
void Menu::opponentColorShift(int shift)
{
	_opponentColor += shift;
	if (_opponentColor > 2)
		_opponentColor = 0;
	if (_opponentColor < 0)
		_opponentColor = 2;

	if (_opponentColor == 0 && _playerColor == 0) // Both red
		_playerColor = 1; // Black
	if (_opponentColor > 0 && _playerColor > 0) // Both black or white
		_playerColor = 0; // Red
}
void Menu::difficultyShift(int shift)
{
	_difficulty += shift;
	if (_difficulty >= _difficultyCount)
		_difficulty = 0;
	if (_difficulty < 0)
		_difficulty = _difficultyCount - 1;

	if (_difficulty == 1 || _difficulty == 2 || _difficulty == 3) // DepthShift
	{
		getButton(Button::Purpose::DepthShiftLeftArrow, _optionsMenuButtons)->setActive(true);
		getButton(Button::Purpose::DepthShiftRightArrow, _optionsMenuButtons)->setActive(true);
	}
	else
	{
		getButton(Button::Purpose::DepthShiftLeftArrow, _optionsMenuButtons)->setActive(false);
		getButton(Button::Purpose::DepthShiftRightArrow, _optionsMenuButtons)->setActive(false);
	}
}
void Menu::depthShift(int shift)
{
	_depth += shift;
	if (_depth > 99)
		_depth = 1;
	if (_depth < 1)
		_depth = 99;
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