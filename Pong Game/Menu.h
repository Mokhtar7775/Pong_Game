#pragma once
#include"sfml\graphics.hpp"
using namespace sf;
#define MAX_MAIN_MENU 8
class Menu
{
public:
	void menu_dec(float width, float height);
	void draw(RenderWindow& menu_window);
	void moveup();
	void movedown();
	int mainMenuPressed()
	{
		return mainmenuselected;
	}
	Text mainmenu[MAX_MAIN_MENU];
	int mainmenuselected;
	Font font;
};

