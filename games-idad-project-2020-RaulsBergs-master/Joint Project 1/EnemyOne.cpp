#include "SFML/Graphics.hpp" 
#include <iostream>
#include "EnemyOne.h"
#include "Globals.h"

EnemyOne::EnemyOne()
{
	int randSpeedValue = (rand() % 7) + 3;
	speed = randSpeedValue;
	loadEnemyTexture();
	isAlive = true;
	enemyBody.setTexture(textureEast);
	float randYCord = (rand() % 600) + 1;
	enemyPosition = { 200.0f,randYCord};
	enemyBody.setPosition(enemyPosition);
	enemyBody.setScale(1.2, 1.2);
	enemyBody.setOrigin(32, 32);
}

sf::Sprite EnemyOne::getBody()
{
	return enemyBody;
}

void EnemyOne::loadEnemyTexture()
{
	if (!textureEast.loadFromFile("ASSETS\\IMAGES\\enemy1_right.png"))
	{
		std::cout << "Problem Loading 'player_down.png'" << std::endl;
	}
	if (!textureWest.loadFromFile("ASSETS\\IMAGES\\enemy1_left.png"))
	{
		std::cout << "Problem Loading 'player_up.png'" << std::endl;
	}
}

void EnemyOne::move()
{
	m_newPos = enemyBody.getPosition();
	m_newPos = { m_newPos.x + speed, m_newPos.y };
	enemyBody.setPosition(m_newPos);
}

void EnemyOne::checkWallCollision()
{
	if (enemyBody.getPosition().x > SCREEN_WIDTH - 35)
	{
		speed = speed * -1;
		enemyBody.setPosition(m_newPos);
		enemyBody.setTexture(textureWest);
	}

	if (enemyBody.getPosition().x < 35)
	{
		speed = speed * -1;
		enemyBody.setPosition(m_newPos);
		enemyBody.setTexture(textureEast);
	}
}
