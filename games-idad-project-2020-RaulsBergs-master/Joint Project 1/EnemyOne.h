#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

class EnemyOne
{
private:
	//Data Members
	sf::Texture textureEast;
	sf::Texture textureWest;

	sf::Sprite enemyBody;
	sf::Vector2f m_newPos;
	sf::Vector2f enemyPosition;

	int health = 0;
	int speed = 0;
	int enemyDirection = (rand() % 2) + 1;
	bool isAlive = true;

public:
	//Function Members
	EnemyOne();
	sf::Sprite getBody();
	void loadEnemyTexture();
	void move(); // Used to move the player left but stay within the boundary of the screen.
	void checkWallCollision();
};