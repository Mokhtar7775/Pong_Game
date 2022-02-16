#pragma once
#include"sfml\graphics.hpp"
using namespace sf;
#define MAX_MAIN_MENU 20
class GameGuide
{
public:
	void guide_dec();
	Text guide[MAX_MAIN_MENU];
	RectangleShape photo[3];
	Texture screenshot[3];
	Font font;
};

