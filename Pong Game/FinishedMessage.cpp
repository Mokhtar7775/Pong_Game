#include "FinishedMessage.h"

void FinishedMessage::finished_dec()
{
	font.loadFromFile("Aller_BdIt.ttf");

	//Shape
	message[0].setSize(Vector2f(500, 200));
	message[0].setPosition(320, 300);
	MESSAGE.loadFromFile("pausebackground.png");
	message[0].setTexture(&MESSAGE);
	//Boarders
	//Up
	message[1].setSize(Vector2f(500, 2));
	message[1].setPosition(320, 300);
	//Left
	message[2].setSize(Vector2f(2, 200));
	message[2].setPosition(320, 300);
	//Down
	message[3].setSize(Vector2f(500, 2));
	message[3].setPosition(320, 500);
	//Right
	message[4].setSize(Vector2f(2, 202));
	message[4].setPosition(820, 300);

	finished[0].setFont(font);
	finished[0].setFillColor(Color(0, 255, 127));
	finished[0].setCharacterSize(40);
	finished[0].setString("Play Again");
	finished[0].setPosition(Vector2f(340, 400));

	finished[1].setFont(font);
	finished[1].setFillColor(Color::White);
	finished[1].setCharacterSize(40);
	finished[1].setString("Main Menu");
	finished[1].setPosition(Vector2f(600, 400));

	finished[2].setFont(font);
	finished[2].setFillColor(Color::White);
	finished[2].setOutlineThickness(1);
	finished[2].setOutlineColor(Color::Cyan);
	finished[2].setCharacterSize(40);
	finished[2].setString("Do You Want Play Again ?");
	finished[2].setPosition(Vector2f(340, 330));

	finishedselected = 0;
}

void FinishedMessage::draw(RenderWindow& play_window)
{
	for (int i = 0;i < 5;i++)
	{
		play_window.draw(message[i]);
	}
	for (int i = 0;i < 3;i++)
	{
		play_window.draw(finished[i]);
	}
}

void FinishedMessage::moveright()
{
	if (finishedselected >= 0)
	{
		if (finishedselected == 0)
		{
			finished[finishedselected].setFillColor(Color::White);
			finishedselected = 1;
			finished[finishedselected].setFillColor(Color(0, 255, 127));
		}
	}
}
void FinishedMessage::moveleft()
{
	if (finishedselected >= 0)
	{
		if (finishedselected == 1)
		{
			finished[finishedselected].setFillColor(Color::White);
			finishedselected = 0;
			finished[finishedselected].setFillColor(Color(0, 255, 127));
		}
	}
}
