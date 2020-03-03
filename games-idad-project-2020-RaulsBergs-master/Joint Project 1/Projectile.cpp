#include "Projectile.h"
#include <iostream>
#include "Player.h"
#include "Globals.h"
#include "EnemyOne.h"
#include "EnemyTwo.h"

void Projectile::loadProjectileAssets()
{
	if (!textureProjectile.loadFromFile("ASSETS\\IMAGES\\realWeapon.png"))
	{
		std::cout << "no wall cell jpg file found" << std::endl;
	}
	projectileBody.setTexture(textureProjectile);
	projectileBody.setScale(0.3f, 0.3f);
	projectileBody.setOrigin(0, 15);
	projectilePosition = {400.0f,400.0f};
	displayBulletBool = false;
}

Projectile::Projectile()
{
	loadProjectileAssets();
	projectileBody.setPosition(projectilePosition);
	speed = 10;
}

int Projectile::getProjectileSpeed()
{
	return projectileSpeed;
}

bool Projectile::renderBullet(bool yesOrNo)
{
	return yesOrNo;
}

void Projectile::move()
{
	if (projectileDirection == 1)
	{
		projectileBody.move(sf::Vector2f{ speed ,0.0f });
	} 
	if (projectileDirection == 2)
	{
		projectileBody.move(sf::Vector2f{ (speed * -1),0.0f });
	}
	if (projectileDirection == 3)
	{
		projectileBody.move(sf::Vector2f{ 0.0f, (speed * -1) });
	}
	if (projectileDirection == 4)
	{
		projectileBody.move(sf::Vector2f{ 0.0f,speed });
	}
}

sf::Sprite Projectile::getProjectileBody()
{
	return projectileBody;
}

sf::Vector2f Projectile::setBulletPosition(Player t_player)
{
	projectilePosition = t_player.getBody().getPosition();
	return projectilePosition;
}

bool Projectile::getRenderBool()
{
	return displayBulletBool;
}

void Projectile::fireBullet(Player t_player)
{
	if (displayBulletBool == false)
	{
		if (t_player.getDirection() == 1)
		{
			projectileBody.setPosition(t_player.getPos());
			displayBulletBool = true;
			projectileDirection = t_player.getDirection();
		}
		if (t_player.getDirection() == 2)
		{
			projectileBody.setPosition(t_player.getPos());
			displayBulletBool = true;
			projectileDirection = t_player.getDirection();
		}
		if (t_player.getDirection() == 3)
		{
			projectileBody.setPosition(t_player.getPos());
			displayBulletBool = true;
			projectileDirection = t_player.getDirection();
		}
		if (t_player.getDirection() == 4)
		{
			projectileBody.setPosition(t_player.getPos());
			displayBulletBool = true;
			projectileDirection = t_player.getDirection();
		}
	}
}

void Projectile::killEnemy(EnemyTwo &t_enemyTwo)
{
	if (projectileBody.getGlobalBounds().intersects(t_enemyTwo.getBody().getGlobalBounds()))
	{
		t_enemyTwo.setAlive(false);
		t_enemyTwo.intialise();
	}
}

void Projectile::checkWallCollision()
{
	if (projectileBody.getPosition().x > SCREEN_WIDTH)
	{
		displayBulletBool = false;
	}

	else if (projectileBody.getPosition().x < 0 )
	{
		displayBulletBool = false;
	}

	else if (projectileBody.getPosition().y > SCREEN_HEIGHT)
	{
		displayBulletBool = false;
	}

	else if (projectileBody.getPosition().y < 0)
	{
		displayBulletBool = false;
	}
}