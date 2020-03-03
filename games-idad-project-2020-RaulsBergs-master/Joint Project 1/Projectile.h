#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "EnemyTwo.h"

class Projectile
{
	private:
	//Data Members
	float speed = 10;
	sf::Texture textureProjectile;

	sf::Sprite projectileBody;

	sf::Vector2f projectilePosition;

	int projectileSpeed = 0;
	int projectileDirection = 0;
	bool projectileIsAlive = true;
	bool displayBulletBool;
	public:
	//functions
	void loadProjectileAssets();
	Projectile();
	int getProjectileSpeed();
	bool renderBullet(bool yesOrNo);
	void move();
	sf::Sprite getProjectileBody();
	sf::Vector2f setBulletPosition(Player t_player);
	bool getRenderBool();
	void checkWallCollision();
	void fireBullet(Player t_player);
	void killEnemy(EnemyTwo& t_enemyTwo);
};