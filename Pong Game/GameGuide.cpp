#include "GameGuide.h"

void GameGuide::guide_dec()
{
	font.loadFromFile("ee.ttf");
	//Back
	guide[0].setString("Back");
	guide[0].setFont(font);
	guide[0].setCharacterSize(70);
	guide[0].setFillColor(Color::White);
	guide[0].setPosition(12, 3);

	photo[0].setSize(Vector2f(1136, 688));
	photo[0].setPosition(0, 0);
	screenshot[0].loadFromFile("game.png");
	photo[0].setTexture(&screenshot[0]);

	photo[1].setSize(Vector2f(1136, 688));
	photo[1].setPosition(0,0);
	screenshot[1].loadFromFile("settings.png");
	photo[1].setTexture(&screenshot[1]);

	photo[2].setSize(Vector2f(1136, 688));
	photo[2].setPosition(0, 0);
	screenshot[2].loadFromFile("extras.png");
	photo[2].setTexture(&screenshot[2]);
}

