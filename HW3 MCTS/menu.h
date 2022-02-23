/* menu.h
Nathan Damon
CS 405
2/15/2022
This is the header file for the menu class which handles the menus.
*/

#ifndef MENU_H
#define MENU_H

#include "game.h"

class Menu
{
private:
	enum class State
	{
		Main,
		Options,		
		Play,
		Quit
	};

	class Button
	{
	public:
		enum class Purpose
		{
			Play,
			Options,
			Quit,

			PlayerColorLeftArrow,
			PlayerColorRightArrow,
			OpponentColorLeftArrow,
			OpponentColorRightArrow,

			TournamentModeOn,
			TournamentModeOff,

			DifficultyLeftArrow,
			DifficultyRightArrow,

			// Sub set of difficulty
			DepthShiftLeftArrow,
			DepthShiftRightArrow,

			Back
		};
	public:
		Button(Purpose purpose, sf::Vector2<int> sourcePosition, sf::Vector2<int> sourceDimensions, sf::Texture& menuButtonTextures);
		~Button();

		void draw(sf::RenderWindow& gfx);
		const bool isPressed(sf::RenderWindow& gfx, int scale, sf::Vector2<int> screenOffset = sf::Vector2<int>(-8, -31));

		void setActive(bool isActive);
		bool isActive();
		Purpose getPurpose();

		void setPosition(sf::Vector2<int> newPosition);
		sf::Vector2<int> getPosition();

		void centerX(sf::Vector2<int> windowSize);
		void centerY(sf::Vector2<int> windowSize);
	private:
		const bool isPosWithin(const sf::Vector2<int> mousePositionOnScreen);

		Purpose _purpose;
		bool _active = true;
		sf::Sprite _buttonSprite;
	};

public:
	Menu();
	~Menu();

	void run();

	void runMainMenu();
	void runOptionsMenu();
	void runGame();

private:
	// Main menu
	void setupMainMenu();
	void displayMainMenu();
	void setMainMenuButtons();
	void mainMenuButtonCheck();

	// Options menu
	void setupOptionsMenu();
	void displayOptionsMenu();
	void setOptionsMenuButtons();
	void optionsMenuButtonCheck();


	void drawMenuBackground();
	void drawButtons(std::vector<Button>& buttons);

	Button* getButton(Button::Purpose purpose, std::vector<Button>& buttons);

	void setupMiscSprites();
	void centerX(sf::Sprite& sprite);
	void centerY(sf::Sprite& sprite);

	Game::PlayerColor getPlayer1Color();
	Game::PlayerColor getPlayer2Color();

	void playerColorShift(int shift);
	void opponentColorShift(int shift);
	void difficultyShift(int shift);
	void depthShift(int shift);
private:

	bool _mouseButtonPressed = false;
	State _currentState = State::Main;

	// Main menu
	sf::Sprite _checkersTitle;
	std::vector<Button> _mainMenuButtons;
	   

	// Options menu
	sf::Sprite _optionsSpriteTitle;
	sf::Sprite _mainOptionsSprite;
	std::vector<sf::Sprite> _difficultyLevels;
	std::vector<Button> _optionsMenuButtons;

	bool _cPU_PlayerGame = false;

	int _playerColor = 0; // 0=Red, 1=Black, 2=White
	int _opponentColor = 1; // 0=Red, 1=Black, 2=White

	bool _tournamentModeOn = false;
	int _difficulty = 0; // 0=NoBrainer, 1=MuscleHead
	const int _difficultyCount = 4;
	int _depth = 1; // MuscleHead depth


	// Misc
	sf::Texture _MenuTextures;
	std::vector<sf::Sprite> _numbers1To9;
	std::vector<sf::Sprite> _playerPieces;
	std::vector<sf::Sprite> _opponentPieces;

	sf::Texture _MenuBackGroundTexture;
	sf::Sprite _MenuBackGroundSprite;

	sf::Vector2<int> _windowSize; // Before gfx so as to initialize it first	
	sf::Vector2<int> _windowResolution; // Before gfx so as to initialize it first

	sf::RenderWindow _gfx;
	std::unique_ptr<Game> _game = nullptr;
};

#endif // !MENU_H