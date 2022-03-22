/* menu.h
Nathan Damon
CS 405
2/15/2022
This is the header file for the menu class which handles the menus.
*/

#ifndef MENU_H
#define MENU_H

#include "game.h"

#define MENUBUTTONDEBUG

class Menu
{
private:
	enum class State
	{
		Main,
		Options,		
		Replays,
		Play,
		Quit
	};

	class Button
	{
	public:
		enum class Purpose
		{
			Play,
			Replays,
			Options,
			Quit,

			// Options menu buttons
			TournamentModeOn,
			TournamentModeOff,

			Player1ModeLeftArrow,
			Player1ModeRightArrow,
			Player2ModeLeftArrow,
			Player2ModeRightArrow,

			Player2ColorLeftArrow,
			Player2ColorRightArrow,

			// Sub set of difficulty
			P1DepthShiftLeftArrow,
			P1DepthShiftRightArrow,
			P2DepthShiftLeftArrow,
			P2DepthShiftRightArrow,

			Back,

			// Replays menu buttons
			PreviousGame,
			NextGame,

			BackOneMove,
			ForwardOneMove,
			JumpBackFiveMoves,
			JumpForwardFiveMoves,

			PauseReplay,
			PlayReplay,

			ReturnToMain			
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
	void runReplaysMenu();
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

	// Replays menu
	void setupReplaysMenu();
	void displayReplaysMenu();
	void setReplaysMenuButtons();
	void replaysMenuButtonCheck();

	void drawMenuBackground();
	void drawButtons(std::vector<Button>& buttons);
	void drawNumber(sf::RenderWindow& gfx, int digitCount, int number, sf::Vector2<int> positionOffset);

	Button* getButton(Button::Purpose purpose, std::vector<Button>& buttons);

	void setupMiscSprites();
	void centerX(sf::Sprite& sprite);
	void centerY(sf::Sprite& sprite);

	Game::PlayerColor getPlayer1Color();
	Game::PlayerColor getPlayer2Color();

	// Options menu functionality
	void player1ModeShift(int shift);
	void player2ModeShift(int shift);
	void player2ColorShift(int shift);
	void player1DepthShift(int shift); 
	void player2DepthShift(int shift);

	// Replays menu functionality
	void prepReplayMenu();
	void replayStepForwardsOnce();
	void replayStepBackwardsOnce();
	void setReplayBoard();
	void exitReplays();
private:

	bool _mouseButtonPressed = false;
	State _currentState = State::Main;

	// Main menu
	sf::Sprite _checkersTitle;
	std::vector<Button> _mainMenuButtons;
	   

	// Options menu
	sf::Sprite _optionsSpriteTitle;
	sf::Sprite _mainOptionsSprite;
	sf::Sprite _p2ColorSprite;
	std::vector<sf::Sprite> _difficultyLevels;
	std::vector<Button> _optionsMenuButtons;

	bool _cPU_PlayerGame = false;
	
	bool _tournamentModeOn = false;
	int _p1Difficulty = 0; // 0=Random, 1=MiniMax, 2=AlphaBeta, 3=MCTS, 4=Player
	int _p1Depth = 1; 
	int _p2Difficulty = 0; // 0=Random, 1=MiniMax, 2=AlphaBeta, 3=MCTS, 4=Player
	int _p2Depth = 1; 
	
	int _p2Color = 1; // 1=Black, 2=White
	const int _difficultyCount = 5; 


	// Replays menu
	sf::Sprite _replaysSpriteTitle;
	std::vector<Button> _replaysMenuButtons;
	std::unique_ptr<Board> _replayBoard = nullptr;
	size_t _gameLogIndex = 0;
	size_t _gameLogMoveIndex = 0;
	bool _replaysIsPaused = true;
	std::chrono::time_point<std::chrono::steady_clock> _timePoint;
	float _timeInBetweenSteps = 0.7f;
	float _timeTillNextStepForward = -1.0f;
	std::vector<PieceType> _piecesRemoved;
	std::unique_ptr<GameLogs> _gameLogs = nullptr;

	// Misc
	sf::Texture _MenuTextures;
	sf::Sprite _leftBorder;
	sf::Sprite _rightBorder;
	std::vector<sf::Sprite> _numbers0To9;
	std::vector<sf::Sprite> _colorPickPieces;

	sf::Texture _MenuBackGroundTexture;
	sf::Sprite _MenuBackGroundSprite;

	sf::Vector2<int> _windowSize; // Before gfx so as to initialize it first	
	sf::Vector2<int> _windowResolution; // Before gfx so as to initialize it first

	sf::RenderWindow _gfx;
	std::unique_ptr<Game> _game = nullptr;
};

#endif // !MENU_H