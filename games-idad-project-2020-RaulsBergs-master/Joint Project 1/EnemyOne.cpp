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
	enemyBody.setTextureRect(sf::IntRect(50,50,320,230));
	float randYCord = (rand() % 600) + 1;
	enemyPosition = { 200.0f,randYCord};
	enemyBody.setPosition(enemyPosition);
	enemyBody.setScale(0.4, 0.4);
	enemyBody.setOrigin(200,0);
}

sf::Sprite EnemyOne::getBody()
{
	return enemyBody;
}

void EnemyOne::loadEnemyTexture()
{
	if (!textureEast.loadFromFile("ASSETS\\IMAGES\\real bee.png"))
	{
		std::cout << "Problem Loading 'player_down.png'" << std::endl;
	}
	if (!textureWest.loadFromFile("ASSETS\\IMAGES\\real bee.png"))
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
		enemyBody.setTextureRect(sf::IntRect(50, 50, 320, 230));
	}

	if (enemyBody.getPosition().x < 35)
	{
		speed = speed * -1;
		enemyBody.setPosition(m_newPos);
		enemyBody.setTextureRect(sf::IntRect(390, 50, 320, 230));
	}
}
