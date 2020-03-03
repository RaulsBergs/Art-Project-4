#pragma once

#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include "Player.h"

class EnemyTwo
{
private:
	//Data Members
	sf::Texture textureEast;
	sf::Texture textureNorth;
	sf::Texture textureSouth;
	sf::Texture textureWest;

	sf::Sprite enemyBody;
	sf::Vector2f enemyPosition;

	int health = 0;
	int speed = 0;
	bool isAlive = true;
	bool invicable = false;

public:
	//Function Members
	EnemyTwo();
	sf::Vector2f getPos();
	sf::Sprite getBody();
	void intialise();
	void setPos(sf::Vector2f t_cord);
	void loadEnemyTexture();
	void checkWallCollision();
	void followPlayer(sf::Vector2f T_cord);
	int getSpeed();
	void setSpeed(int t_Speed);
	void damagePlayer(Player &t_player, int t_health);
	void setAlive(bool yesOrNo);
	void setInvincable(bool yesOrNo);
};