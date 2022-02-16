#pragma once
#include"sfml\graphics.hpp"
using namespace sf;
#define MAX_MAIN_MENU 11

class Options
{
public:
	void option_dec();
	void draw(RenderWindow& option_window);
	void levels_dec();
	void draw_levels(RenderWindow& option_window);
	void moveup();
	void movedown();
	void MOVEUP();
	void MOVEDOWN();
	void moveright();
	void moveleft();
	int OptionPressed()
	{
		return optionselected;
	}
	Text option[MAX_MAIN_MENU];
	int optionselected ;
	Font font;
	Font font2;
};

