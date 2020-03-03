// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include "EnemyOne.h"
#include "EnemyTwo.h"
#include "Projectile.h"
#include "Globals.h"   // include Global header file
#include "Player.h"   // include Player header file
#include <string>


class Game
{
	//My Objects
	int direction = 0;
	bool stopMovement = false;
	bool moveNorth;
	bool moveRight;
	bool moveSouth;
	bool moveLeft;
	bool endGame = false;
	Player playerOne;
	Projectile bullet;
	static const int MAX_NUM_SLIMES = 3;
	EnemyOne Enemies[3];
	EnemyTwo enemiesTwo[MAX_NUM_SLIMES];
	sf::RenderWindow window;
public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen
	sf::Text m_playerHealth;
	sf::Text m_gameOverText;
	sf::Texture backGroundTexture;
	sf::Sprite backGroundSprite;
public:	  // declaration of member functions	
	Game(); // default constructor
	void	loadContent();
	void	run();
	void	update();
	void	draw();
	void	displayPlayerHealth();
	int getDirection();
	void gameOver(Player t_player);
	void drawGameOverText();
	//void	collsisionDetection();
	//void	fixSlimeCollision();
};
