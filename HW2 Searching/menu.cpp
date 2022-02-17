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
}
Menu::~Menu()
{
}

void Menu::run()
{
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
void Menu::runGame()
{
	// Game running code here
	if (_game == nullptr) // Create a new game
	{
		_game = std::move(std::make_unique<Game>(_gfx, getPlayer1Color(), getPlayer2Color(), _tournamentModeOn, _difficulty, _muscleHeadDepth));
		_game->enableDebugPrintout(false);
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
	int numMiddleButtons = 3; // 1-> -10, 2-> -22, 3-> -34, 4-> -46
	sf::Vector2<int> positionOffset = { 0, _windowSize.y / 2 - (10 + (numMiddleButtons - 1) * 12) };

	// Play 
	Button play(Button::Purpose::Play, { 164, 40 }, { 47, 20 }, _MenuTextures);
	play.setPosition(positionOffset);
	play.centerX(_windowSize);
	_mainMenuButtons.push_back(play);
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

	// No Brainer
	areaToDisplay = sf::IntRect({ 0, 20 }, { 114, 20 });
	_difficultyLevels.push_back(sf::Sprite(_MenuTextures, areaToDisplay));
	_difficultyLevels.back().setPosition(positionOffset.x + 17, positionOffset.y + 97);

	// Muscle Head
	areaToDisplay = sf::IntRect({ 0, 40 }, { 114, 41 });
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

	// Muscle Head
	if (_difficulty == 1)
		_gfx.draw(_numbers1To9[_muscleHeadDepth - 1]);

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
		Button tournamentModeOn(Button::Purpose::TournamentModeOn, { 153, 0 }, { 37, 20 }, _MenuTextures);
		position = { 157, 49 };
		tournamentModeOn.setPosition(position + positionOffset);
		tournamentModeOn.setActive(false);
		_optionsMenuButtons.push_back(tournamentModeOn);

		// Tournament mode Off
		Button tournamentModeOff(Button::Purpose::TournamentModeOff, { 190, 0 }, { 37, 20 }, _MenuTextures);
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

	// Difficulty - Muscle Head
	{
		// Difficulty - Muscle Head left arrow
		Button difficultyMuscleHeadLeftArrow(Button::Purpose::MuscleHeadLeftArrow, { 114, 40 }, { 15, 15 }, _MenuTextures);
		position = { 17 + 31, 97 + 24 };
		difficultyMuscleHeadLeftArrow.setPosition(position + positionOffset);
		difficultyMuscleHeadLeftArrow.setActive(false);
		_optionsMenuButtons.push_back(difficultyMuscleHeadLeftArrow);

		// Difficulty - Muscle Head right arrow
		Button difficultyMuscleHeadRightArrow(Button::Purpose::MuscleHeadRightArrow, { 129, 40 }, { 15, 15 }, _MenuTextures);
		position = { 17 + 65, 97 + 24 };
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

			case Menu::Button::Purpose::MuscleHeadLeftArrow:
				muscleHeadDepthShift(-1);
				return;
			case Menu::Button::Purpose::MuscleHeadRightArrow:
				muscleHeadDepthShift(1);
				return;
			case Button::Purpose::Back:
				_currentState = State::Main;
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

	// Numbers 1-9
	areaToDisplay = sf::IntRect({ 0, 0 }, { 17, 20 });
	for (size_t i = 0; i < 9; i++)
	{
		areaToDisplay.left = i * 17; // Position in row
		sf::Sprite num(_MenuTextures, areaToDisplay);
		num.setPosition(positionOffset.x, positionOffset.y);
		_numbers1To9.push_back(num);
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

	if (_difficulty == 1) // MuscleHead
	{
		getButton(Button::Purpose::MuscleHeadLeftArrow, _optionsMenuButtons)->setActive(true);
		getButton(Button::Purpose::MuscleHeadRightArrow, _optionsMenuButtons)->setActive(true);
	}
	else
	{
		getButton(Button::Purpose::MuscleHeadLeftArrow, _optionsMenuButtons)->setActive(false);
		getButton(Button::Purpose::MuscleHeadRightArrow, _optionsMenuButtons)->setActive(false);
	}
}
void Menu::muscleHeadDepthShift(int shift)
{
	_muscleHeadDepth += shift;
	if (_muscleHeadDepth > 9)
		_muscleHeadDepth = 1;
	if (_muscleHeadDepth < 1)
		_muscleHeadDepth = 9;
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