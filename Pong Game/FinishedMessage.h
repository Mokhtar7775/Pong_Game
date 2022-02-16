#pragma once
#include"sfml\graphics.hpp"
using namespace sf;
#define MAX_MAIN_MENU 3
class FinishedMessage
{
public:
	void finished_dec();
	void draw(RenderWindow& play_window);
	void moveright();
	void moveleft();
	int finishedPressed()
	{
		return finishedselected;
	}
	Text finished[MAX_MAIN_MENU];
	RectangleShape message[5];
	Texture MESSAGE;
	int finishedselected;
	Font font;
};

