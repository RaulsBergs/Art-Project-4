#include "EnemyTwo.h"
#include "Game.h"
EnemyTwo::EnemyTwo()
{
	speed = ((rand() % 3) + 1);
	loadEnemyTexture();
	float randxVal = (rand() % 800) + 1;
	float randYVal = (rand() % 600) + 1;
	enemyPosition = { randxVal,randYVal };
	enemyBody.setPosition(enemyPosition);
}



sf::Vector2f EnemyTwo::getPos()
{
	return enemyPosition;
}

sf::Sprite EnemyTwo::getBody()
{
	return enemyBody;
}

void EnemyTwo::intialise()
{
	if (isAlive == false)
	{
		speed = ((rand() % 3) + 1);
		loadEnemyTexture();
		float randxVal = (rand() % 800) + 1;
		float randYVal = (rand() % 600) + 1;
		enemyPosition = { randxVal,randYVal };
		enemyBody.setPosition(enemyPosition);
		isAlive = true;
		invicable = false;
	}
}

void EnemyTwo::setPos(sf::Vector2f t_cord)
{
	enemyPosition = t_cord;
}


void EnemyTwo::loadEnemyTexture()
{
	if (!textureNorth.loadFromFile("ASSETS\\IMAGES\\Slime_Medium_Blue.png"))
	{
		std::cout << "Blue slime failed to load from file" << std::endl;
	}
	enemyBody.setTexture(textureNorth);
	enemyBody.setTextureRect(sf::IntRect(0, 0, 32, 32));
	enemyBody.setScale(2, 2);
}

void EnemyTwo::checkWallCollision()
{

}

void EnemyTwo::followPlayer(sf::Vector2f T_cord)
{
	if (enemyBody.getPosition().x < T_cord.x)
	{
		enemyBody.setPosition(enemyBody.getPosition().x + speed, enemyBody.getPosition().y);
		enemyBody.setTextureRect(sf::IntRect(32, 32, 32, 32));
	}
	if (enemyBody.getPosition().x > T_cord.x)
	{
		enemyBody.setPosition(enemyBody.getPosition().x - speed, enemyBody.getPosition().y);
		enemyBody.setTextureRect(sf::IntRect(96, 96, 32, 32));
	}
	if (enemyBody.getPosition().y < T_cord.y)
	{
		enemyBody.setPosition(enemyBody.getPosition().x, enemyBody.getPosition().y + speed);
		enemyBody.setTextureRect(sf::IntRect(0, 0, 32, 32));
	}
	if (enemyBody.getPosition().y > T_cord.y)
	{
		enemyBody.setPosition(enemyBody.getPosition().x, enemyBody.getPosition().y - speed);
		enemyBody.setTextureRect(sf::IntRect(64, 64, 32, 32));
	}
}

int EnemyTwo::getSpeed()
{
	return speed;
}

void EnemyTwo::setSpeed(int t_Speed)
{
	speed = t_Speed;
}

void EnemyTwo::damagePlayer(Player &t_player, int t_health)
{
	if (enemyBody.getGlobalBounds().intersects(t_player.getBody().getGlobalBounds()))
	{
		if (invicable == false)
		{
			t_player.lowerHealth(10);
			invicable = true;
		}
	}
}

void EnemyTwo::setAlive(bool yesOrNo)
{
	isAlive = yesOrNo;
}

void EnemyTwo::setInvincable(bool yesOrNo)
{
	invicable = false;
}


