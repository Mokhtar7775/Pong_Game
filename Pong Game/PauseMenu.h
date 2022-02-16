#pragma once
#include"sfml\graphics.hpp"
using namespace sf;
#define MAX_PAUSE_MENU 4
class PauseMenu
{
public:
	void pause_dec();
	void draw(RenderWindow& play_window);
	void moveup();
	void movedown();
	int pauseMenuPressed()
	{
		return pausemenuselected;
	}
	Text pausemenu[MAX_PAUSE_MENU];
	RectangleShape pause[5];
	Texture background;
	int pausemenuselected;
	Font font;
};