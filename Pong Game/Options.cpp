#include "Options.h"
#include <SFML/Graphics.hpp>
using namespace sf;

void Options::option_dec()
{
	font.loadFromFile("Aller_BdIt.ttf");
	font2.loadFromFile("ee.ttf");

	option[0].setString("Back");
	option[0].setFont(font2);
	option[0].setCharacterSize(70);
	option[0].setFillColor(Color::White);
	option[0].setPosition(12, 3);

	option[1].setString("Menu");
	option[1].setFont(font);
	option[1].setCharacterSize(50);
	option[1].setFillColor(Color::Cyan);
	option[1].setPosition(140, 80);

	option[2].setString("Settings\n& Guide");
	option[2].setFont(font);
	option[2].setCharacterSize(40);
	option[2].setFillColor(Color::White);
	option[2].setPosition(140, 175);

	option[3].setString("Player VS Computer");
	option[3].setFont(font);
	option[3].setCharacterSize(45);
	option[3].setFillColor(Color::White);
	option[3].setPosition(140, 340);

	option[8].setString("Game");
	option[8].setFont(font);
	option[8].setCharacterSize(50);
	option[8].setFillColor(Color::White);
	option[8].setPosition(660, 80);

	option[9].setString("Sounds");
	option[9].setFont(font);
	option[9].setCharacterSize(50);
	option[9].setFillColor(Color::White);
	option[9].setPosition(660, 190);

	option[10].setString("2 Players");
	option[10].setFont(font);
	option[10].setCharacterSize(50);
	option[10].setFillColor(Color::White);
	option[10].setPosition(660, 340);

	optionselected = 1;
}

void Options::draw(RenderWindow& option_window)
{
	for (int i = 0; i < 4; i++)
	{
		option_window.draw(option[i]);
	}
	for (int i = 8; i < 11; i++)
	{
		option_window.draw(option[i]);
	}
}

void Options::levels_dec()
{
	option[4].setString("Easy");
	option[4].setFont(font);
	option[4].setCharacterSize(40);
	option[4].setFillColor(Color::White);
	option[4].setPosition(140, 400);

	option[5].setString("Normal");
	option[5].setFont(font);
	option[5].setCharacterSize(40);
	option[5].setFillColor(Color::White);
	option[5].setPosition(140, 460);

	option[6].setString("Hard");
	option[6].setFont(font);
	option[6].setCharacterSize(40);
	option[6].setFillColor(Color::White);
	option[6].setPosition(140, 520);

	option[7].setString("AI");
	option[7].setFont(font);
	option[7].setCharacterSize(40);
	option[7].setFillColor(Color::White);
	option[7].setPosition(140, 580);

}
void Options::draw_levels(RenderWindow& option_window)
{
	for (int i = 4; i < 8; i++)
	{
		option_window.draw(option[i]);
	}
}

//without levels
void Options::moveup()
{
	if (optionselected > 1)
	{
		if (optionselected <= 3)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected--;
			option[optionselected].setFillColor(Color::Cyan);
		}
		if (optionselected <= 10 && optionselected > 8)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected--;
			option[optionselected].setFillColor(Color::Cyan);
		}
	}
}
void Options::movedown()
{
	if (optionselected + 1 < MAX_MAIN_MENU)
	{
		if (optionselected >= 1 && optionselected < 3)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected++;
			option[optionselected].setFillColor(Color::Cyan);
		}
		else if (optionselected >= 8)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected++;
			option[optionselected].setFillColor(Color::Cyan);
		}
	}
}

//Using levels
void Options::MOVEUP()
{
	if (optionselected > 1)
	{
		if (optionselected <= 7)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected--;
			option[optionselected].setFillColor(Color::Cyan);
		}
		if (optionselected <= 10 && optionselected > 8)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected--;
			option[optionselected].setFillColor(Color::Cyan);
		}
	}
}
void Options::MOVEDOWN()
{
	if (optionselected + 2 <= MAX_MAIN_MENU)
	{
		if (optionselected >= 1 && optionselected < 7)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected++;
			option[optionselected].setFillColor(Color::Cyan);
		}
		else if (optionselected >= 8)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected++;
			option[optionselected].setFillColor(Color::Cyan);
		}
	}
}
void Options::moveright()
{
	if (optionselected >= 1)
	{
		if (optionselected == 1)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected = 8;
			option[optionselected].setFillColor(Color::Cyan);
		}
		if (optionselected == 2)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected = 9;
			option[optionselected].setFillColor(Color::Cyan);
		}
		if (optionselected == 3)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected = 10;
			option[optionselected].setFillColor(Color::Cyan);
		}
	}
}

void Options::moveleft()
{
	if (optionselected >= 1)
	{
		if (optionselected == 8)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected = 1;
			option[optionselected].setFillColor(Color::Cyan);
		}
		if (optionselected == 9)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected = 2;
			option[optionselected].setFillColor(Color::Cyan);
		}
		if (optionselected == 10)
		{
			option[optionselected].setFillColor(Color::White);
			optionselected = 3;
			option[optionselected].setFillColor(Color::Cyan);
		}
	}
}