#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <time.h>
#include <fstream>
#include "Menu.h"
#include "Options.h"
#include "PauseMenu.h"
#include "GameGuide.h"
#include "FinishedMessage.h"
#include "TextBox.h"
#include "txtbox.h"

Mouse mouse;

using namespace std;
using namespace sf;

int  page_number = 1, menu_var = 3, game_var = 1, option_var = 3, sounds_var = 3, levels = 1, timer = 0;
bool Set_control = true, Set_tick = true, pause = true;
string name1 = "Player 1", name2 = "Player 2";

//Menu
void Menu_Mouse(Vector2i& position, RenderWindow& menu_window, Menu& menu)
{
	//Play
	if ((position.x >= 578) && (position.x <= 682) && (position.y >= 230) && (position.y <= 299))
	{
		menu.mainmenu[2].setFillColor(Color(0, 255, 127));
		menu.mainmenu[3].setFillColor(Color::White);
		menu.mainmenu[4].setFillColor(Color::White);
		menu.mainmenu[5].setFillColor(Color::White);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			menu_window.close();
			page_number = 2;
		}
	}
	else if (menu.mainmenuselected != 2)
		menu.mainmenu[2].setFillColor(Color::White);
	//Settings
	if ((position.x >= 540) && (position.x <= 704) && (position.y >= 305) && (position.y <= 373))
	{
		menu.mainmenu[3].setFillColor(Color(0, 255, 127));
		menu.mainmenu[2].setFillColor(Color::White);
		menu.mainmenu[4].setFillColor(Color::White);
		menu.mainmenu[5].setFillColor(Color::White);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			menu_window.close();
			page_number = 3;
		}
	}
	else if (menu.mainmenuselected != 3)
		menu.mainmenu[3].setFillColor(Color::White);
	//Game guide
	if ((position.x >= 497) && (position.x <= 744) && (position.y >= 382) && (position.y <= 445))
	{
		menu.mainmenu[4].setFillColor(Color(0, 255, 127));
		menu.mainmenu[2].setFillColor(Color::White);
		menu.mainmenu[3].setFillColor(Color::White);
		menu.mainmenu[5].setFillColor(Color::White);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			menu_window.close();
			page_number = 4;
		}
	}
	else if (menu.mainmenuselected != 4)
		menu.mainmenu[4].setFillColor(Color::White);
	//Exit
	if ((position.x >= 460) && (position.x <= 544) && (position.y >= 459) && (position.y <= 521))
	{
		menu.mainmenu[5].setFillColor(Color(0, 255, 127));
		menu.mainmenu[2].setFillColor(Color::White);
		menu.mainmenu[3].setFillColor(Color::White);
		menu.mainmenu[4].setFillColor(Color::White);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			menu_window.close();
			page_number = 5;
		}
	}
	else if (menu.mainmenuselected != 5)
		menu.mainmenu[5].setFillColor(Color::White);
}
void menu_buttons(Menu& menu, RenderWindow& menu_window)
{
	if (menu.mainMenuPressed() == 2)
	{
		menu_window.close();
		page_number = 2;
	}
	else if (menu.mainMenuPressed() == 3)
	{
		menu_window.close();
		page_number = 3;
	}
	else if (menu.mainMenuPressed() == 4)
	{
		menu_window.close();
		page_number = 4;
	}
	else if (menu.mainMenuPressed() == 5)
	{
		menu_window.close();
		page_number = 5;
	}
}

//Play
void move_player2(RectangleShape& player2, RenderWindow& play_window, RectangleShape& game_field, Time& total_time, Time& round_time, int& counter1, int& counter2)
{
	//goals
	if ((counter1 <= 4 && counter2 <= 4 && round_time.asSeconds() > 2) || ((counter1 == 5 || counter2 == 5) && round_time.asSeconds() < 5))
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Up))
			player2.move(0.0f, -2.3f);
		if (Keyboard::isKeyPressed(Keyboard::Key::Down))
			player2.move(0.0f, 2.3f);
	}
	//time
	else if ((counter1 != 5 && counter2 != 5) && (total_time.asSeconds() < 95 && total_time.asSeconds() >= 92))
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Up))
			player2.move(0.0f, -2.3f);
		if (Keyboard::isKeyPressed(Keyboard::Key::Down))
			player2.move(0.0f, 2.3f);
	}
	//Borders With Right Player(2) (y-axis)
	if (player2.getPosition().y > play_window.getSize().y - (player2.getGlobalBounds().height - 47))
		player2.setPosition(player2.getPosition().x, play_window.getSize().y - (player2.getGlobalBounds().height - 47));

	if (player2.getPosition().y < (102 + 47))
		player2.setPosition(player2.getPosition().x, game_field.getPosition().y + 47);
}
void move_player1(RectangleShape& player1, RenderWindow& play_window, RectangleShape& game_field, Time& total_time, Time& round_time, int& counter1, int& counter2)
{
	//goals
	if ((counter1 <= 4 && counter2 <= 4 && round_time.asSeconds() > 2) || ((counter1 == 5 || counter2 == 5) && (round_time.asSeconds() < 5)))
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::W))
			player1.move(0.0f, -2.3f);
		if (Keyboard::isKeyPressed(Keyboard::Key::S))
			player1.move(0.0f, 2.3f);
	}
	//time
	else if ((counter1 != 5 && counter2 != 5) && (total_time.asSeconds() < 95 && total_time.asSeconds() >= 92))
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::W))
			player1.move(0.0f, -2.3f);
		if (Keyboard::isKeyPressed(Keyboard::Key::S))
			player1.move(0.0f, 2.3f);
	}
	//Borders with Left Player(1) (y-axis)
	if (player1.getPosition().y > play_window.getSize().y - (player1.getGlobalBounds().height - 47))
		player1.setPosition(player1.getPosition().x, play_window.getSize().y - (player1.getGlobalBounds().height - 47));

	if (player1.getPosition().y < (102 + 47))
		player1.setPosition(player1.getPosition().x, game_field.getPosition().y + 47);
}
//Easy
void move_computer1(RectangleShape& player1, CircleShape& ball, RenderWindow& play_window, RectangleShape& game_field)
{
	if (player1.getPosition().y >= (ball.getPosition().y))
		player1.move(0.0f, -2.2f);
	if (player1.getPosition().y <= (ball.getPosition().y))
		player1.move(0.0f, 2.2f);

	//Borders with computer (y-axis)
	if (player1.getPosition().y > play_window.getSize().y - (player1.getGlobalBounds().height - 50))
		player1.setPosition(player1.getPosition().x, play_window.getSize().y - (player1.getGlobalBounds().height - 50));

	if (player1.getPosition().y < (102 + 50))
		player1.setPosition(player1.getPosition().x, game_field.getPosition().y + 50);
}
//Normal
void move_computer2(RectangleShape& player1, CircleShape& ball, RenderWindow& play_window, RectangleShape& game_field)
{
	if (player1.getPosition().y >=(ball.getPosition().y))
		player1.move(0.0f, -2.3f);
	if (player1.getPosition().y <= (ball.getPosition().y))
		player1.move(0.0f, 2.3f);

	//Borders with computer (y-axis)
	if (player1.getPosition().y > play_window.getSize().y - (player1.getGlobalBounds().height - 50))
		player1.setPosition(player1.getPosition().x, play_window.getSize().y - (player1.getGlobalBounds().height - 50));

	if (player1.getPosition().y < (102 + 50))
		player1.setPosition(player1.getPosition().x, game_field.getPosition().y + 50);
}
//Hard
void move_computer3(RectangleShape& player1, CircleShape& ball, RenderWindow& play_window, RectangleShape& game_field)
{
	if (player1.getPosition().y >= ball.getPosition().y)
		player1.move(0.0f, -2.5f);
	if (player1.getPosition().y <= ball.getPosition().y)
		player1.move(0.0f, 2.5f);

	//Borders with computer (y-axis)
	if (player1.getPosition().y > play_window.getSize().y - (player1.getGlobalBounds().height - 50))
		player1.setPosition(player1.getPosition().x, play_window.getSize().y - (player1.getGlobalBounds().height - 50));

	if (player1.getPosition().y < (102 + 50))
		player1.setPosition(player1.getPosition().x, game_field.getPosition().y + 50);
}
//AI
void move_computerAI(RectangleShape& player1, CircleShape& ball, RenderWindow& play_window, RectangleShape& game_field, int& counter1, int& counter2)
{
	if (counter1 == 0 && counter2 == 0)
	{
		if (player1.getPosition().y >= ball.getPosition().y)
			player1.move(0.0f, -2.3f);
		if (player1.getPosition().y <= ball.getPosition().y)
			player1.move(0.0f, 2.3f);
	}
	else if (counter1 == 4 || counter2 == 4)
	{
		if (player1.getPosition().y >= ball.getPosition().y)
			player1.move(0.0f, -2.8f);
		if (player1.getPosition().y <= ball.getPosition().y)
			player1.move(0.0f, 2.8f);
	}
	else if (counter1 == 3 || counter2 == 3)
	{
		if (player1.getPosition().y >= ball.getPosition().y)
			player1.move(0.0f, -2.7f);
		if (player1.getPosition().y <= ball.getPosition().y)
			player1.move(0.0f, 2.7f);
	}
	else if (counter1 == 2 || counter2 == 2)
	{
		if (player1.getPosition().y >= ball.getPosition().y)
			player1.move(0.0f, -2.5f);
		if (player1.getPosition().y <= ball.getPosition().y)
			player1.move(0.0f, 2.5f);
	}
	else if (counter1 == 1 || counter2 == 1)
	{
		if (player1.getPosition().y >= ball.getPosition().y)
			player1.move(0.0f, -2.4f);
		if (player1.getPosition().y <= ball.getPosition().y)
			player1.move(0.0f, 2.4f);
	}

	//Borders with computer (y-axis)
	if (player1.getPosition().y > play_window.getSize().y - (player1.getGlobalBounds().height - 50))
		player1.setPosition(player1.getPosition().x, play_window.getSize().y - (player1.getGlobalBounds().height - 50));

	if (player1.getPosition().y < (102 + 50))
		player1.setPosition(player1.getPosition().x, game_field.getPosition().y + 50);
}

void Ball_Collision(Vector2f& length2, Vector2f& length1, CircleShape& ball, RenderWindow& play_window, Vector2f& ball_velocity, Sound& ball_collision, Sound& paddle_collision, RectangleShape& player2, RectangleShape& player1)
{
	//Ball collision with (y-axis)
	if (ball.getPosition().y < 115 || ball.getPosition().y > play_window.getSize().y - 13)
	{
		ball_velocity.y *= -1;
		ball_collision.play();
	}

	//Ball collision with player2 
	//(Go Down)
	if (length2.x <= 5 && length2.x >= 0 && ball.getPosition().y >= player2.getPosition().y + 55 && ball.getPosition().y <= player2.getPosition().y + 70)
	{
		ball_velocity.x = -2.9;
		ball_velocity.y = 3.3;
		paddle_collision.play();
	}
	else if (length2.x <= 3 && length2.x >= 0 && ball.getPosition().y >= player2.getPosition().y + 40 && ball.getPosition().y <= player2.getPosition().y + 55)
	{
		ball_velocity.x = -2.5;
		ball_velocity.y = 2.9;
		paddle_collision.play();
	}
	else if (length2.x <= 3 && length2.x >= 0 && ball.getPosition().y >= player2.getPosition().y + 25 && ball.getPosition().y <= player2.getPosition().y + 40)
	{
		ball_velocity.x = -2.2;
		ball_velocity.y = 2.0;
		paddle_collision.play();
	}
	else if (length2.x <= 3 && length2.x >= 0 && ball.getPosition().y >= player2.getPosition().y + 10 && ball.getPosition().y <= player2.getPosition().y + 25)
	{
		ball_velocity.x = -2.2;
		ball_velocity.y = 1.5;
		paddle_collision.play();
	}
	else if (length2.x <= 3 && length2.x >= 0 && ball.getPosition().y >= player2.getPosition().y - 10 && ball.getPosition().y <= player2.getPosition().y + 10)
	{
		ball_velocity.x = -2.2;
		ball_velocity.y = 0.0;
		paddle_collision.play();
	}
	//(Go Up)
	if (length2.x <= 3 && length2.x >= 0 && ball.getPosition().y <= player2.getPosition().y - 10 && ball.getPosition().y >= player2.getPosition().y - 25)
	{
		ball_velocity.x = -2.2;
		ball_velocity.y = -1.5;
		paddle_collision.play();
	}
	else if (length2.x <= 3 && length2.x >= 0 && ball.getPosition().y <= player2.getPosition().y - 25 && ball.getPosition().y >= player2.getPosition().y - 40)
	{
		ball_velocity.x = -2.2;
		ball_velocity.y = -2.0;
		paddle_collision.play();
	}
	else if (length2.x <= 3 && length2.x >= 0 && ball.getPosition().y <= player2.getPosition().y - 40 && ball.getPosition().y >= player2.getPosition().y - 55)
	{
		ball_velocity.x = -2.5;
		ball_velocity.y = -2.9;
		paddle_collision.play();
	}
	else if (length2.x <= 5 && length2.x >= 0 && ball.getPosition().y <= player2.getPosition().y - 55 && ball.getPosition().y >= player2.getPosition().y - 70)
	{
		ball_velocity.x = -2.9;
		ball_velocity.y = -3.3;
		paddle_collision.play();
	}

	//Ball collision with player1 
	//(Go Down)
	if (length1.x <= 5 && length1.x >= 0 && ball.getPosition().y >= player1.getPosition().y + 55 && ball.getPosition().y <= player1.getPosition().y + 70)
	{
		ball_velocity.x = 2.9;
		ball_velocity.y = 3.3;
		paddle_collision.play();
	}
	if (length1.x <= 3 && length1.x >= 0 && ball.getPosition().y >= player1.getPosition().y + 40 && ball.getPosition().y <= player1.getPosition().y + 55)
	{
		ball_velocity.x = 2.5;
		ball_velocity.y = 2.9;
		paddle_collision.play();
	}
	if (length1.x <= 3 && length1.x >= 0 && ball.getPosition().y >= player1.getPosition().y + 25 && ball.getPosition().y <= player1.getPosition().y + 40)
	{
		ball_velocity.x = 2.2;
		ball_velocity.y = 2.0;
		paddle_collision.play();
	}
	if (length1.x <= 3 && length1.x >= 0 && ball.getPosition().y >= player1.getPosition().y + 10 && ball.getPosition().y <= player1.getPosition().y + 25)
	{
		ball_velocity.x = 2.2;
		ball_velocity.y = 1.5;
		paddle_collision.play();
	}
	if (length1.x <= 3 && length1.x >= 0 && ball.getPosition().y >= player1.getPosition().y - 10 && ball.getPosition().y <= player1.getPosition().y + 10)
	{
		ball_velocity.x = 2.2;
		ball_velocity.y = 0.0;
		paddle_collision.play();
	}
	//(Go Up)
	if (length1.x <= 3 && length1.x >= 0 && ball.getPosition().y <= player1.getPosition().y + 10 && ball.getPosition().y >= player1.getPosition().y - 25)
	{
		ball_velocity.x = 2.2;
		ball_velocity.y = -1.5;
		paddle_collision.play();
	}
	if (length1.x <= 3 && length1.x >= 0 && ball.getPosition().y <= player1.getPosition().y - 25 && ball.getPosition().y >= player1.getPosition().y - 40)
	{
		ball_velocity.x = 2.2;
		ball_velocity.y = -2.0;
		paddle_collision.play();
	}
	if (length1.x <= 3 && length1.x >= 0 && ball.getPosition().y <= player1.getPosition().y - 40 && ball.getPosition().y >= player1.getPosition().y - 55)
	{
		ball_velocity.x = 2.5;
		ball_velocity.y = -2.9;
		paddle_collision.play();
	}
	if (length1.x <= 5 && length1.x >= 0 && ball.getPosition().y <= player1.getPosition().y - 55 && ball.getPosition().y >= player1.getPosition().y - 70)
	{
		ball_velocity.x = 2.9;
		ball_velocity.y = -3.3;
		paddle_collision.play();
	}
}

void ball_movement(int& counter1, int& counter2, Vector2f& ball_pos, Vector2f& ball_velocity, CircleShape& ball, Time& total_time, Time& round_time)
{
	if (round_time.asSeconds() >= 2 && total_time.asSeconds() < 92)
	{
		if (counter1 < 5 && counter2 < 5)
		{
			ball_pos += ball_velocity;
			ball.setPosition(ball_pos);
		}
	}
}

//Borders With The Ball
void player2_scores(CircleShape& ball, int& counter1, int& counter2, RectangleShape& player1, RectangleShape& player2, Sound& goal_whistle, Clock& round_clock, Time& total_time, Text& player2_goals,Vector2f& ball_velocity)
{
	if (ball.getPosition().x < 10 && total_time.asSeconds() < 92)
	{
		counter2++;
		goal_whistle.play();
		round_clock.restart();
		ball.setPosition(568.0f, 395.0f);
		ball_velocity.x = 2.2;
		ball_velocity.y = 2.2;
		if (counter2 == 1)
			player2_goals.setString("1");
		else if (counter2 == 2)
			player2_goals.setString("2");
		else if (counter2 == 3)
			player2_goals.setString("3");
		else if (counter2 == 4)
			player2_goals.setString("4");
		else if (counter2 == 5)
			player2_goals.setString("5");
		//Reset Paddles
		if (counter1 < 5 && counter2 < 5 && total_time.asSeconds() < 92)
		{
			player1.setPosition(56.0f, 395.0f);
			player2.setPosition(1080.0f, 395.0f);
		}
	}
}

void player1_scores(CircleShape& ball, int& counter1, int& counter2, RectangleShape& player1, RectangleShape& player2, Sound& goal_whistle, Clock& round_clock, Time& total_time, Text& player1_goals, RenderWindow& play_window,Vector2f& ball_velocity)
{
	if (ball.getPosition().x > play_window.getSize().x -10 && total_time.asSeconds() < 92)
	{
		counter1++;
		goal_whistle.play();
		round_clock.restart();
		ball.setPosition(568.0f, 395.0f);
		ball_velocity.x = -2.2;
		ball_velocity.y = -2.2;
		if (counter1 == 1)
			player1_goals.setString("1");
		else if (counter1 == 2)
			player1_goals.setString("2");
		else if (counter1 == 3)
			player1_goals.setString("3");
		else if (counter1 == 4)
			player1_goals.setString("4");
		else if (counter1 == 5)
			player1_goals.setString("5");

		//Reset Paddles
		if (counter1 < 5 && counter2 < 5 && total_time.asSeconds() < 92)
		{
			player1.setPosition(56.0f, 395.0f);
			player2.setPosition(1080.0f, 395.0f);
		}
	}
}

void match_finished(int& counter1, int& counter2, Time& round_time, Time& total_time, CircleShape& ball, Sound& finish_whistle)
{
	//Reset the ball at finish
	if (total_time.asSeconds() > 92)
		ball.setPosition(568.0f, 395.0f);

	//Finish Whistle (Goals)
	if ((counter1 == 5 || counter2 == 5) && (round_time.asSeconds() > 2 && round_time.asSeconds() < 2.01))
		finish_whistle.play();
	//(Time)
	if (total_time.asSeconds() >= 92 && total_time.asSeconds() < 92.01 && counter1 != 5 && counter2 != 5)
		finish_whistle.play();
}

void results(int& counter1, int& counter2, Time& round_time, Time& total_time, RenderWindow& play_window, Text& winner_text, Text& none_won)
{
	if (counter1 > counter2)
	{
		winner_text.setString(name1 + " Wins !");
		winner_text.setFillColor(Color(127, 0, 255));
	}
	else if (counter2 > counter1)
	{
		winner_text.setString(name2 + " Wins !");
		winner_text.setFillColor(Color::Cyan);
	}
	//5 Goals
	if ((counter1 >= 5 || counter2 >= 5) && round_time.asSeconds() > 2)
		play_window.draw(winner_text);
	
	//Time Over
	else if (total_time.asSeconds() > 92)
	{
		play_window.draw(winner_text);

		if (counter1 == counter2)
			play_window.draw(none_won);
	}
}

void goal_scored(int& counter1, int& counter2, Time& round_time, Time& total_time, RenderWindow& play_window, Text& goal_text)
{
	for (int i = 1;i <= 5;i++)
	{
		if (counter1 == i || counter2 == i)
		{
			if (round_time.asSeconds() < 2 && total_time.asSeconds() < 92)
				play_window.draw(goal_text);
		}
	}
}

void Total_Time(Clock& clock, int& countdown, Text& Timer, Time& total_time, int& counter1, int& counter2)
{
	if (total_time.asSeconds() >= 3)
	{
		timer = clock.getElapsedTime().asSeconds();
	}
	if (timer > 0)
	{
		countdown--;
		Timer.setString(to_string(countdown));
		clock.restart();
	}
	if (total_time.asSeconds() >= 83.1)
		Timer.setFillColor(Color::Red);
	else if (total_time.asSeconds() >= 53)
		Timer.setFillColor(Color::Yellow);

	Timer.setPosition(527, 15);
	if (countdown <= 9)
		Timer.setPosition(545, 15);
}

void DRAW(RenderWindow& play_window, RectangleShape& info_background, RectangleShape& game_field, RectangleShape& player1, RectangleShape& player2, CircleShape& ball, RectangleShape& field_boarder_up, RectangleShape& field_boarder_down, RectangleShape& field_boarder_left, RectangleShape& field_boarder_right, Text& player1_text, Text& player2_text, Text& player1_goals, Text& player2_goals,Text& Timer,Time& round_time,Time& total_time,int& counter1,int& counter2)
{
	//Draw info
	play_window.draw(info_background);
	play_window.draw(player1_text);
	play_window.draw(player2_text);
	play_window.draw(player1_goals);
	play_window.draw(player2_goals);
	//Draw Game
	play_window.draw(game_field);
	play_window.draw(player1);
	play_window.draw(player2);
	play_window.draw(ball);
	//Draw Boarders
	play_window.draw(field_boarder_up);
	play_window.draw(field_boarder_down);
	play_window.draw(field_boarder_left);
	play_window.draw(field_boarder_right);
	if (round_time.asSeconds() >= 2 && total_time.asSeconds() <= 92 && counter1 != 5 && counter2 != 5)
		play_window.draw(Timer);
}

//Saving the game
void Saved_games(int& counter1, int& counter2, ofstream& OtStatics, time_t& date)
{
	if (counter1 > counter2)
		OtStatics << ctime(&date) << name1 + "        " + name2 << endl << counter1 << "               " << counter2 << endl << "    " + name1 << " Won !\n***************************\n";
	else if (counter2 > counter1)
		OtStatics << ctime(&date) << name1 + "        " + name2 << endl << counter1 << "               " << counter2 << endl << "    " + name2 << " Won !\n***************************\n";
	else
		OtStatics << ctime(&date) << name1 + "        " + name2 << endl << counter1 << "               " << counter2 << "\n          Draw !\n*************************** \n";
}

//Options
void options_mouse(Vector2i& position, RenderWindow& option_window, Options& options,Textbox& text1,Txtbox& text2,RectangleShape& player2name)
{
	//Back
	if ((position.x >= 12) && (position.x <= 122) && (position.y >= 20) && (position.y <= 79))
	{
		options.option[0].setFillColor(Color(144, 15, 255));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			option_window.close();
			page_number = 1;
		}
	}
	else
		options.option[0].setFillColor(Color::White);
	//CompVsPlayer
	if ((position.x >= 142) && (position.x <= 545) && (position.y >= 350) && (position.y <= 395))
	{
		options.option[3].setFillColor(Color::Cyan);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Set_control = false;
			Set_tick = false;
			player2name.setPosition(390, 419);
			text2.setPosition({ 390, 400 });
		}
	}
	else if (options.optionselected != 3)
		options.option[3].setFillColor(Color::White);
	//2Players
	if ((position.x >= 661) && (position.x <= 868) && (position.y >= 352) && (position.y <= 402))
	{
		options.option[10].setFillColor(Color::Cyan);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Set_control = true;
			Set_tick = true;
			player2name.setPosition(390, 550);
			text2.setPosition({ 390, 535 });
		}
	}
	else if (options.optionselected != 10)
		options.option[10].setFillColor(Color::White);

	//Easy
	if ((position.x >= 141) && (position.x <= 224) && (position.y >= 409) && (position.y <= 450))
	{
		options.option[4].setFillColor(Color::Cyan);
		if (Mouse::isButtonPressed(Mouse::Left))
			levels = 1;
	}
	else if (options.optionselected != 4)
		options.option[4].setFillColor(Color::White);

	//Normal
	if ((position.x >= 141) && (position.x <= 276) && (position.y >= 470) && (position.y <= 499))
	{
		options.option[5].setFillColor(Color::Cyan);
		if (Mouse::isButtonPressed(Mouse::Left))
			levels = 2;
	}
	else if (options.optionselected != 5)
		options.option[5].setFillColor(Color::White);

	//Hard
	if ((position.x >= 141) && (position.x <= 230) && (position.y >= 530) && (position.y <= 560))
	{
		options.option[6].setFillColor(Color::Cyan);
		if (Mouse::isButtonPressed(Mouse::Left))
			levels = 3;
	}
	else if (options.optionselected != 6)
		options.option[6].setFillColor(Color::White);

	//AI
	if ((position.x >= 141) && (position.x <= 178) && (position.y >= 590) && (position.y <= 619))
	{
		options.option[7].setFillColor(Color::Cyan);
		if (Mouse::isButtonPressed(Mouse::Left))
			levels = 4;
	}
	else if (options.optionselected != 7)
		options.option[7].setFillColor(Color::White);
}

void options_buttons(Event& event, Options& options)
{
    if (!Set_tick) {
        if (event.key.code == Keyboard::Up)
            options.MOVEUP();
        if (event.key.code == Keyboard::Down)
            options.MOVEDOWN();
        if (event.key.code == Keyboard::Right)
            options.moveright();
        if (event.key.code == Keyboard::Left)
            options.moveleft();
    } else {
        if (event.key.code == Keyboard::Up)
            options.moveup();
        if (event.key.code == Keyboard::Down)
            options.movedown();
        if (event.key.code == Keyboard::Right)
            options.moveright();
        if (event.key.code == Keyboard::Left)
            options.moveleft();
    }
}

void music_sounds(Options& options, Event& event, Music& menu_music, Music& option_music, Music& game_music, Music& guide_music, Sound& goal_whistle, Sound& finish_whistle, Sound& ball_collision, Sound& paddle_collision, RenderWindow& option_window, RectangleShape menu_rectangle[])
{
	if (options.optionselected == 1)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			if (menu_music.getVolume() < 99)
			{
				menu_music.setVolume(menu_music.getVolume() + 10);
			}
			menu_var++;
			if (menu_var > 9)
				menu_var = 9;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			if (menu_music.getVolume() < 10)
			{
				menu_music.setVolume(0);
			}
			else
			{
				menu_music.setVolume(menu_music.getVolume() - 10);
			}
			menu_var--;
			if (menu_var < -1)
				menu_var = -1;
		}

	}

	if (options.optionselected == 8)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			if (game_music.getVolume() < 99)
			{
				game_music.setVolume(game_music.getVolume() + 10);
			}
			game_var++;
			if (game_var > 9)
				game_var = 9;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			if (game_music.getVolume() < 10)
			{
				game_music.setVolume(0);
			}
			else
			{
				game_music.setVolume(game_music.getVolume() - 10);
			}
			game_var--;
			if (game_var < -1)
				game_var = -1;
		}
	}

	if (options.optionselected == 2)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			if (option_music.getVolume() < 99 && guide_music.getVolume() < 99)
			{
				option_music.setVolume(option_music.getVolume() + 10);
				guide_music.setVolume(guide_music.getVolume() + 10);
			}
			option_var++;
			if (option_var > 9)
				option_var = 9;
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			if (option_music.getVolume() < 10 && guide_music.getVolume() < 10)
			{
				option_music.setVolume(0);
				guide_music.setVolume(0);
			}
			else
			{
				option_music.setVolume(option_music.getVolume() - 10);
				guide_music.setVolume(guide_music.getVolume() - 10);
			}
			option_var--;
			if (option_var < -1)
				option_var = -1;
		}
	}
	if (options.optionselected == 9)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Right))
		{
			if (goal_whistle.getVolume() < 99 && finish_whistle.getVolume() < 99 && ball_collision.getVolume() < 99 && paddle_collision.getVolume() < 99)
			{
				goal_whistle.setVolume(goal_whistle.getVolume() + 10);
				finish_whistle.setVolume(finish_whistle.getVolume() + 10);
				ball_collision.setVolume(ball_collision.getVolume() + 10);
				paddle_collision.setVolume(paddle_collision.getVolume() + 10);
			}
			sounds_var++;
			if (sounds_var > 9)
				sounds_var = 9;

		}
		if (Keyboard::isKeyPressed(Keyboard::Key::Left))
		{
			if (goal_whistle.getVolume() < 10 && finish_whistle.getVolume() < 10 && ball_collision.getVolume() < 10 && paddle_collision.getVolume() < 10)
			{
				goal_whistle.setVolume(0);
				finish_whistle.setVolume(0);
				ball_collision.setVolume(0);
				paddle_collision.setVolume(0);
			}
			else
			{
				goal_whistle.setVolume(goal_whistle.getVolume() - 10);
				finish_whistle.setVolume(finish_whistle.getVolume() - 10);
				ball_collision.setVolume(ball_collision.getVolume() - 10);
				paddle_collision.setVolume(paddle_collision.getVolume() - 10);
			}
			sounds_var--;
			if (sounds_var < -1)
				sounds_var = -1;
		}
	}
}
void setting(Options& options)
{
	if (options.optionselected == 3)
	{
		Set_control = false;
		Set_tick = false;

	}
	else if (options.optionselected == 10)
	{
		Set_control = true;
		Set_tick = true;
		
	}
	else if (options.optionselected == 4)
	{
		levels = 1;
	}
	else if (options.optionselected == 5)
	{
		levels = 2;
	}
	else if (options.optionselected == 6)
	{
		levels = 3;
	}
	else if (options.optionselected == 7)
	{
		levels = 4;
	}
}
void DRAW_OPTIONS(RenderWindow& option_window, RectangleShape menu_rectangle[], RectangleShape game_rectangle[], RectangleShape option_rectangle[], RectangleShape sounds_rectangle[], CircleShape tick_mark[],RectangleShape& player1name,RectangleShape& player2name,Textbox& text1,Txtbox& text2,RectangleShape music_rec[])
{
	//big recs
	for (int i = 0;i < 4;i++)
	{
		option_window.draw(music_rec[i]);
	}

	//small recs
	for (int i = 0;i <= menu_var;i++)
	{
		option_window.draw(menu_rectangle[i]);
	}
	for (int i = 0;i <= game_var;i++)
	{
		option_window.draw(game_rectangle[i]);
	}
	for (int i = 0;i <= option_var;i++)
	{
		option_window.draw(option_rectangle[i]);
	}
	for (int i = 0;i <= sounds_var;i++)
	{
		option_window.draw(sounds_rectangle[i]);
	}

    if (!Set_tick) {
        option_window.draw(player2name);
        option_window.draw(tick_mark[0]);
        text2.drawTo(option_window);

        name2 = text2.getText();
        if (name2 == "")
            name2 = "Player 2";

        if (levels == 1) {
            option_window.draw(tick_mark[2]);
        } else if (levels == 2) {
            option_window.draw(tick_mark[3]);
        } else if (levels == 3) {
            option_window.draw(tick_mark[4]);
        } else if (levels == 4) {
            option_window.draw(tick_mark[5]);
        }

    } else {
        option_window.draw(tick_mark[1]);
        option_window.draw(player1name);
        option_window.draw(player2name);
        text1.drawTo(option_window);


        name1 = text1.getText();
        if (name1 == "")
            name1 = "Player 1";
        text2.drawTo(option_window);

        name2 = text2.getText();
        if (name2 == "")
            name2 = "Player 2";
    }
}
//Guide Mouse
void guide_mouse(Vector2i& position, RenderWindow& guide_window, GameGuide& gameguide)
{
	if ((position.x >= 12) && (position.x <= 122) && (position.y >= 20) && (position.y <= 79))
	{
		gameguide.guide[0].setFillColor(Color(144, 15, 255));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			guide_window.close();
			page_number = 1;
		}
	}
	else
		gameguide.guide[0].setFillColor(Color::White);
}

int main()
{
	//Menu Music
	Music menu_music;
	menu_music.openFromFile("menu music.ogg");
	menu_music.setVolume(40);
	menu_music.setLoop(true);

	//Game Music
	Music game_music;
	game_music.openFromFile("game music.ogg");
	game_music.setVolume(20);
	game_music.setLoop(true);

	//Setting Music
	Music option_music;
	option_music.openFromFile("settings&guide music.ogg");
	option_music.setVolume(40);
	option_music.setLoop(true);

	//Guide Music
	Music guide_music;
	guide_music.openFromFile("settings&guide music.ogg");
	guide_music.setVolume(40);
	guide_music.setLoop(true);

	//Sounds
	//Goal Sound
	SoundBuffer short_whistle;
	short_whistle.loadFromFile("short whistle.wav");
	Sound goal_whistle;
	goal_whistle.setVolume(40);
	goal_whistle.setBuffer(short_whistle);
	//Finish Sound
	SoundBuffer long_whistle;
	long_whistle.loadFromFile("long whistle.wav");
	Sound finish_whistle;
	finish_whistle.setVolume(40);
	finish_whistle.setBuffer(long_whistle);

	//ball touches borders
	SoundBuffer ball_touch;
	ball_touch.loadFromFile("ball collision.wav");
	Sound ball_collision;
	ball_collision.setVolume(40);
	ball_collision.setBuffer(ball_touch);
	//ball touches paddle
	SoundBuffer paddle_touch;
	paddle_touch.loadFromFile("paddle collision.wav");
	Sound paddle_collision;
	paddle_collision.setVolume(40);
	paddle_collision.setBuffer(paddle_touch);

	while (true)
	{
		if (page_number == 1)
		{
			pause = true;
			//Menu Window
			RenderWindow menu_window(VideoMode(1136, 688), "Pong Game", Style::Default);
			menu_window.setPosition(Vector2i(115, 1.5));

			//Menu Background
			RectangleShape Back_Ground(Vector2f(1136, 688));
			Texture menu_background;
			menu_background.loadFromFile("menu background.png");
			Back_Ground.setTexture(&menu_background);

			Menu menu;
			menu.menu_dec(1136, 688);

			//Music	
			guide_music.stop();
			option_music.stop();
			game_music.stop();
			menu_music.play();

			while (menu_window.isOpen())
			{
				Vector2i position = mouse.getPosition(menu_window);
				Event event;
				while (menu_window.pollEvent(event))
				{
					if (event.type == event.Closed)
					{
						menu_window.close();
						page_number = 5;
					}
					//Choose Page
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::Up)
						{
							menu.moveup();
							break;
						}
						if (event.key.code == Keyboard::Down)
						{
							menu.movedown();
							break;
						}
					}
					if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
					{
						menu_buttons(menu, menu_window);
					}
					//Mouse
					Menu_Mouse(position, menu_window, menu);
				}
				menu_window.clear();
				menu_window.draw(Back_Ground);
				menu.draw(menu_window);
				menu_window.display();
			}
		}
		//play window
		if (page_number == 2)
		{
			//Saving The Game
			ofstream OtStatics("Statics.txt", ios::app);
			time_t date;
			time(&date);

			int counter1 = 0, counter2 = 0;
			//Game Window
			RenderWindow play_window(VideoMode(1136, 688), "Pong Game", Style::Default);
			play_window.setPosition(Vector2i(115, 1.5));

			//Pause menu
			PauseMenu pausemenu;
			pausemenu.pause_dec();

			FinishedMessage finishedmessage;
			finishedmessage.finished_dec();

			//Game Boarders
			//Up
			RectangleShape field_boarder_up(Vector2f(1136, 3));
			field_boarder_up.setPosition(0, 99);
			field_boarder_up.setFillColor(Color::White);
			//Down
			RectangleShape field_boarder_down(Vector2f(1136, 3));
			field_boarder_down.setPosition(0, 685);
			field_boarder_down.setFillColor(Color::White);
			//Left
			RectangleShape field_boarder_left(Vector2f(3, 586));
			field_boarder_left.setPosition(0.5, 102);
			field_boarder_left.setFillColor(Color::White);
			//Right
			RectangleShape field_boarder_right(Vector2f(3, 586));
			field_boarder_right.setPosition(1133, 102);
			field_boarder_right.setFillColor(Color::White);

			//Field
			RectangleShape game_field(Vector2f(1136, 586));
			game_field.setPosition(0, 102);
			Texture field;
			field.loadFromFile("1268180.png");
			game_field.setTexture(&field);

			//Info Background
			RectangleShape info_background(Vector2f(1136, 102));
			info_background.setPosition(0, 0);
			Texture INFO_BACKGROUND;
			INFO_BACKGROUND.loadFromFile("info background.png");
			info_background.setTexture(&INFO_BACKGROUND);

			//Ball
			CircleShape ball(13);
			ball.setOrigin(16, 16);
			ball.setPosition(568.0f, 395.0f);
			Texture BALL;
			BALL.loadFromFile("ball2.png");
			ball.setTexture(&BALL);
			Vector2f ball_velocity;
			ball_velocity.x = 2.2;
			ball_velocity.y = 2.2;
			Vector2f ball_pos;

			//Left Player (1)
			RectangleShape player1(Vector2f(25.0f, 100.0f));
			player1.setOrigin(12.5f, 50.0f);
			player1.setPosition(56.0f, 395.0f);
			player1.setFillColor(Color(127, 0, 255));
			//Right Player (2)
			RectangleShape player2(Vector2f(25.0f, 100.0f));
			player2.setOrigin(12.5f, 50.0f);
			player2.setPosition(1080.0f, 395.0f);
			player2.setFillColor(Color::Cyan);

			Vector2f length1;
			Vector2f length2;

			//Text
			Font font;
			font.loadFromFile("Aller_BdIt.ttf");
			Font font2;
			font2.loadFromFile("Aller_Bd.ttf");

			//(Player 1)
			Text player1_text;
			player1_text.setFont(font);
			player1_text.setString(name1);
			player1_text.setPosition(90, 13);
			player1_text.setFillColor(Color(127, 0, 255));
			player1_text.setCharacterSize(40);
			//Goals
			Text player1_goals;
			player1_goals.setFont(font);
			player1_goals.setString("0");
			player1_goals.setPosition(145, 60);
			player1_goals.setFillColor(Color(127, 0, 255));
			
			//(Player 2)
			Text player2_text;
			player2_text.setFont(font);
			player2_text.setString(name2);
			player2_text.setPosition(920, 13);
			player2_text.setFillColor(Color::Cyan);
			player2_text.setCharacterSize(40);
			//Goals
			Text player2_goals;
			player2_goals.setFont(font);
			player2_goals.setString("0");
			player2_goals.setPosition(975, 60);
			player2_goals.setFillColor(Color::Cyan);

			//Time
			Clock round_clock, total_clock, clock;
			Time total_time;
			Time round_time;

			//Timer
			int countdown = 90;
			ostringstream convert;
			convert << countdown;
			string countdownstring;
			countdownstring = convert.str();

			Text Timer;
			Timer.setFont(font2);
			Timer.setString(countdownstring);
			Timer.setFillColor(Color::Green);
			Timer.setCharacterSize(60);

			//Result Text
			//Player wins
			Text winner_text;
			winner_text.setFont(font);
			winner_text.setPosition(play_window.getSize().x / 3.2, 17);
			if (counter1 > counter2)
				winner_text.setFillColor(Color(127, 0, 255));
			else if (counter1 < counter2)
				winner_text.setFillColor(Color::Cyan);
			winner_text.setCharacterSize(60);
			//Draw
			Text none_won;
			none_won.setFont(font);
			none_won.setString("Draw !");
			none_won.setPosition(play_window.getSize().x / 2.44, 8);
			none_won.setFillColor(Color::Red);
			none_won.setCharacterSize(70);

			//Goal scored 
			Text goal_text;
			goal_text.setFont(font);
			goal_text.setString("Goal !");
			goal_text.setPosition(play_window.getSize().x / 2.56, 6);
			goal_text.setFillColor(Color::Green);
			goal_text.setCharacterSize(80);
			//Beginning Text
			Text begin_text;
			begin_text.setFont(font);
			begin_text.setString("Score 5 Goals To Win !");
			begin_text.setPosition(play_window.getSize().x / 3.5, 20);
			begin_text.setFillColor(Color::Green);
			begin_text.setCharacterSize(50);

			//Music	
			menu_music.stop();
			game_music.play();

			while (play_window.isOpen())
			{
				length2.x = (player2.getPosition().x - 25.5) - (ball.getPosition().x);
				length1.x = (ball.getPosition().x) - (player1.getPosition().x + 28);
				Event event;
				while (play_window.pollEvent(event))
				{
					if (event.type == event.Closed)
					{
						play_window.close();
						page_number = 5;
					}
					//Finished PopUp
					if (event.type == Event::KeyPressed)
					{
						//time
						if (total_time.asSeconds() > 95)
						{
							if (event.key.code == Keyboard::Right)
								finishedmessage.moveright();
							if (event.key.code == Keyboard::Left)
								finishedmessage.moveleft();
						}
						//goals
						else if ((counter1 == 5 || counter2 == 5) && round_time.asSeconds() > 5)
						{
							if (event.key.code == Keyboard::Right)
								finishedmessage.moveright();
							if (event.key.code == Keyboard::Left)
								finishedmessage.moveleft();
						}
					}
					if (event.key.code == Keyboard::Enter)
					{
						//time
						if (total_time.asSeconds() > 95)
						{
							if (finishedmessage.finishedPressed() == 0)
							{
								page_number = 6;
								play_window.close();
							}
							else if (finishedmessage.finishedPressed() == 1)
							{
								page_number = 1;
								play_window.close();
								finishedmessage.finishedselected = 0;
							}
						}
						//goals
						else if ((counter1 == 5 || counter2 == 5) && round_time.asSeconds() > 5)
						{
							if (finishedmessage.finishedPressed() == 0)
							{
								page_number = 6;
								play_window.close();
							}
							else if (finishedmessage.finishedPressed() == 1)
							{
								page_number = 1;
								play_window.close();
								finishedmessage.finishedselected = 0;
							}
						}
					}

					//pause the game
					if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
					{
						if (counter1 < 5 && counter2 < 5)
						{
							pause = false;
							page_number = 0;
						}
						else if (total_time.asSeconds() < 92 && counter1 != 5 && counter2 != 5)
						{
							pause = false;
							page_number = 0;
						}
					}
					//Pause Menu
					if (page_number == 0)
					{
						if (event.type == Event::KeyPressed)
						{
							if (event.key.code == Keyboard::Up)
								pausemenu.moveup();
							if (event.key.code == Keyboard::Down)
								pausemenu.movedown();
						}

						if (event.key.code == Keyboard::Enter)
						{
							if (pausemenu.pauseMenuPressed() == 1)
							{
								pause = true;
								page_number = 2;
							}
							else if (pausemenu.pauseMenuPressed() == 2)
							{
								page_number = 6;
								play_window.close();
								pausemenu.pausemenuselected = 1;
							}
							else if (pausemenu.pauseMenuPressed() == 3)
							{
								page_number = 1;
								play_window.close();
								pausemenu.pausemenuselected = 1;
							}
						}
					}
				}
				//Pause the game
				if (pause == true)
				{
					//Time
					total_time = total_clock.getElapsedTime();
					round_time = round_clock.getElapsedTime();

					//Total Time
					Total_Time(clock, countdown, Timer, total_time, counter1, counter2);

					//Move Player 2 (Right)
					move_player2(player2, play_window, game_field, total_time, round_time,counter1,counter2);

					//Move Player 1 (Left)
					if (Set_control == true)
						move_player1(player1, play_window, game_field, total_time, round_time,counter1,counter2);
					else if (Set_control == false)
					{
						//(Computer)
						if (levels == 1)
							move_computer1(player1, ball, play_window, game_field);
						if (levels == 2)
							move_computer2(player1, ball, play_window, game_field);
						if (levels == 3)
							move_computer3(player1, ball, play_window, game_field);
						if (levels == 4)
							move_computerAI(player1, ball, play_window, game_field, counter1, counter2);
					}

					ball_pos = ball.getPosition();
					//Move The Ball
					ball_movement(counter1, counter2, ball_pos, ball_velocity, ball, total_time, round_time);
				}
				//Ball collision
				Ball_Collision(length2, length1, ball, play_window, ball_velocity, ball_collision, paddle_collision, player2, player1);

				//Player 2 scores
				player2_scores(ball, counter1, counter2, player1, player2, goal_whistle, round_clock, total_time, player2_goals, ball_velocity);

				//Player 1 scores
				player1_scores(ball, counter1, counter2, player1, player2, goal_whistle, round_clock, total_time, player1_goals, play_window, ball_velocity);

				//Match finished
				match_finished(counter1, counter2, round_time, total_time, ball, finish_whistle);

				play_window.clear();
				DRAW(play_window, info_background, game_field, player1, player2, ball, field_boarder_up, field_boarder_down, field_boarder_left, field_boarder_right, player1_text, player2_text, player1_goals, player2_goals, Timer, round_time, total_time, counter1, counter2);
				
				//Beginning Text
				if (total_time.asSeconds() > 0.01 && total_time.asSeconds() < 2)
					play_window.draw(begin_text);

				//Pause
				if (page_number == 0 && total_time.asSeconds() < 92)
					pausemenu.draw(play_window);

				//Goal Scored
				goal_scored(counter1, counter2, round_time, total_time, play_window, goal_text);

				//Draw Results
				results(counter1, counter2, round_time, total_time, play_window, winner_text, none_won);

				//Finished PopUp
				if (total_time.asSeconds() > 95)
					finishedmessage.draw(play_window);
				else if((counter1==5||counter2==5)&&(round_time.asSeconds()>5))
					finishedmessage.draw(play_window);

				play_window.display();
			}
			Saved_games(counter1, counter2, OtStatics,date);
		}
		//New Game
		else if (page_number == 6)
		{
			pause = true;
			page_number = 2;
		}
		//Settings
		else if (page_number == 3)
		{
			//Option Window:
			RenderWindow option_window(VideoMode(1136, 688), "Pong Game", Style::Default);
			option_window.setPosition(Vector2i(115, 1.5));

			//Option Background
			RectangleShape option_background(Vector2f(1136, 688));
			option_background.setPosition(0, 0);
			Texture OPTION_Background;
			OPTION_Background.loadFromFile("settings&guide background.png");
			option_background.setTexture(&OPTION_Background);

			Options options;
			options.option_dec();
			options.levels_dec();

			//Font
			Font font;
			font.loadFromFile("Aller_BdIt.ttf");

			RectangleShape player1name;
			player1name.setPosition(390, 419);
			player1name.setSize(Vector2f(352, 57));
			player1name.setFillColor(Color::White);

			RectangleShape player2name;
			player2name.setPosition(390, 550);
			player2name.setSize(Vector2f(352, 57));
			player2name.setFillColor(Color::White);

			Textbox text1(60, Color(144, 15, 255), false);
			text1.setPosition({390, 408 });
			text1.setLimit(true, 10);
			text1.setFont(font);
			
			Txtbox text2(60, Color(144, 15, 255), false);
			text2.setPosition({390, 540 });
			text2.setLimit(true, 10);
			text2.setFont(font);

			//Volume Text
			Text volume_text;
			volume_text.setFont(font);
			volume_text.setString("Volume");
			volume_text.setPosition(option_window.getSize().x / 2.5, 15);
			volume_text.setFillColor(Color::White);
			volume_text.setOutlineThickness(2);
			volume_text.setOutlineColor(Color(144, 15, 255));
			volume_text.setCharacterSize(50);

			//Controls Text
			Text control_text;
			control_text.setFont(font);
			control_text.setString("Controls");
			control_text.setPosition(option_window.getSize().x / 2.5, 273);
			control_text.setFillColor(Color::White);
			control_text.setOutlineThickness(3);
			control_text.setOutlineColor(Color(144, 15, 255));
			control_text.setCharacterSize(50);

			//Tick mark
			CircleShape tick_mark[6];
			Texture TICK_MARK;
			TICK_MARK.loadFromFile("tickmark.png");

			//comp vs player
			tick_mark[0].setRadius(20);
			tick_mark[0].setPosition(550, 354);
			tick_mark[0].setTexture(&TICK_MARK);
			//2 players
			tick_mark[1].setRadius(20);
			tick_mark[1].setPosition(875, 354);
			tick_mark[1].setTexture(&TICK_MARK);

			//easy
			tick_mark[2].setRadius(16);
			tick_mark[2].setPosition(237, 414);
			tick_mark[2].setTexture(&TICK_MARK);
			//medium
			tick_mark[3].setRadius(16);
			tick_mark[3].setPosition(298, 473);
			tick_mark[3].setTexture(&TICK_MARK);
			//hard
			tick_mark[4].setRadius(16);
			tick_mark[4].setPosition(244, 530);
			tick_mark[4].setTexture(&TICK_MARK);
			//AI
			tick_mark[5].setRadius(16);
			tick_mark[5].setPosition(190, 590);
			tick_mark[5].setTexture(&TICK_MARK);

			//
			RectangleShape music_rec[4];
			for (int i = 0;i < 4;i++)
			{
				music_rec[i].setSize(Vector2f(250, 40));
				music_rec[i].setFillColor(Color::White);
			}
			music_rec[0].setPosition(325, 95);
			music_rec[1].setPosition(325, 200);
			music_rec[2].setPosition(850, 95);
			music_rec[3].setPosition(850, 200);


			//Menu
			RectangleShape menu_rectangle[10];
			menu_rectangle[0].setSize(Vector2f(25, 40));
			menu_rectangle[0].setPosition(325, 95);
			menu_rectangle[0].setFillColor(Color(144, 15, 255));
			for (int i = 1;i <= 9;i++)
			{
				menu_rectangle[i].setSize(Vector2f(25, 40));
				menu_rectangle[i].setPosition(menu_rectangle[i - 1].getPosition().x + 25, menu_rectangle[i - 1].getPosition().y);
				menu_rectangle[i].setFillColor(Color(144, 15, 255));
			}
			//Options & Statics
			RectangleShape option_rectangle[10];
			option_rectangle[0].setSize(Vector2f(25, 40));
			option_rectangle[0].setPosition(325, 200);
			option_rectangle[0].setFillColor(Color(144, 17, 255));
			for (int i = 1;i <= 9;i++)
			{
				option_rectangle[i].setSize(Vector2f(25, 40));
				option_rectangle[i].setPosition(option_rectangle[i - 1].getPosition().x + 25, option_rectangle[i - 1].getPosition().y);
				option_rectangle[i].setFillColor(Color(144, 17, 255));
			}
			//Game
			RectangleShape game_rectangle[10];
			game_rectangle[0].setSize(Vector2f(25, 40));
			game_rectangle[0].setPosition(850, 95);
			game_rectangle[0].setFillColor(Color(144, 17, 255));
			for (int i = 1;i <= 9;i++)
			{
				game_rectangle[i].setSize(Vector2f(25, 40));
				game_rectangle[i].setPosition(game_rectangle[i - 1].getPosition().x + 25, game_rectangle[i - 1].getPosition().y);
				game_rectangle[i].setFillColor(Color(144, 17, 255));
			}
			//Sounds
			RectangleShape sounds_rectangle[10];
			sounds_rectangle[0].setSize(Vector2f(25, 40));
			sounds_rectangle[0].setPosition(850, 200);
			sounds_rectangle[0].setFillColor(Color(144, 17, 255));
			for (int i = 1;i <= 9;i++)
			{
				sounds_rectangle[i].setSize(Vector2f(25, 40));
				sounds_rectangle[i].setPosition(sounds_rectangle[i - 1].getPosition().x + 25, sounds_rectangle[i - 1].getPosition().y);
				sounds_rectangle[i].setFillColor(Color(144, 17, 255));
			}

			//Options Music
			menu_music.stop();
			option_music.play();

			while (option_window.isOpen())
			{
				Vector2i position = mouse.getPosition(option_window);
				Event event;
				while (option_window.pollEvent(event))
				{
					if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
					{
						option_window.close();
						page_number = 1;
					}
					if (event.type == Event::Closed)
					{
						option_window.close();
						page_number = 5;
					}
					if (Keyboard::isKeyPressed(Keyboard::Enter))
					{
						setting(options);
					}
					//textbox
					if (Set_control == false)
					{
						player2name.setPosition(390, 419);
					}
					//compVsPlayer
					if (options.optionselected == 3)
					{
						if (Keyboard::isKeyPressed(Keyboard::Enter))
						{
							player2name.setPosition(390, 419);
							text2.setSelected(true);
							text2.setPosition({ 390, 405 });
						}
					}
					//2players
					if (options.optionselected == 10)
					{
						if (Keyboard::isKeyPressed(Keyboard::Enter))
						{
							text1.setSelected(true);
							text2.setSelected(false);
							player2name.setPosition(390, 550);
							text2.setPosition({ 390, 540 });
						}
						if (Keyboard::isKeyPressed(Keyboard::Down))
						{
								text1.setSelected(false);
								text2.setSelected(true);
								text2.setPosition({ 390, 540 });						
						}
					}
					if (event.type == Event::TextEntered)
					{
						text1.typedOn(event);
						text2.typedOn(event);
					}
					//Music & Sounds
					if (Keyboard::isKeyPressed(Keyboard::Key::Space))
					{
						music_sounds(options, event, menu_music, option_music, game_music, guide_music, goal_whistle, finish_whistle, ball_collision, paddle_collision, option_window, menu_rectangle);
					}
					else if (event.type == Event::KeyPressed)
					{
						//Choose Page
						options_buttons(event, options);
					}
					//Mouse
					options_mouse(position, option_window,options,text1,text2,player2name);
				}

				option_window.clear();
				option_window.draw(option_background);
				options.draw(option_window);
				option_window.draw(volume_text);
				option_window.draw(control_text);
				DRAW_OPTIONS(option_window, menu_rectangle, game_rectangle, option_rectangle, sounds_rectangle, tick_mark,player1name,player2name,text1,text2,music_rec);

				if (Set_control == false)
					options.draw_levels(option_window);

				option_window.display();
			}
		}
		//Game Guide
		if (page_number == 4)
		{
			RenderWindow guide_window(VideoMode(1136, 688), "Pong Game", Style::Default);
			guide_window.setPosition(Vector2i(115, 1.5));

			GameGuide gameguide;
			gameguide.guide_dec();

			int photos = 1;
			int choice = 1;

			menu_music.stop();
			guide_music.play();

			while (guide_window.isOpen())
			{
				Vector2i position = mouse.getPosition(guide_window);
				Event event;
				while (guide_window.pollEvent(event))
				{

					if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
					{
						guide_window.close();
						page_number = 1;
					}
					if (event.type == Event::Closed)
					{
						guide_window.close();
						page_number = 5;
					}

					if (choice == 1)
					{
						if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
						{
							photos = 2;
						}
					}
					else if (choice == 2)
					{
						if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right)
						{
							photos = 3;
						}
					}

					if (choice == 3)
					{
						if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
						{
							photos = 2;
						}
					}
					else if (choice == 2)
					{
						if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left)
						{
							photos = 1;
						}
					}

					//mouse
					guide_mouse(position, guide_window, gameguide);
				}

				guide_window.clear();

				if (photos == 1)
				{
					guide_window.draw(gameguide.photo[0]);
					choice = 1;
				}
				else if (photos == 2)
				{
					guide_window.draw(gameguide.photo[1]);
					choice = 2;
				}
				else if (photos == 3)
				{
					guide_window.draw(gameguide.photo[2]);
					choice = 3;
				}
				guide_window.draw(gameguide.guide[0]);

				guide_window.display();
			}
		}
		//Exit
		else if (page_number == 5)
			break;
	}
	return 0;
}