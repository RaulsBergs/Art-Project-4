#pragma once

/// <summary>
/// Author: Rauls Bergs
/// Date: 04/02/2020
/// </summary>

#include <SFML/Graphics.hpp>

class Player
{
public:
	//Data Members
	sf::Texture textureNorth;
	sf::Texture textureEast;
	sf::Texture textureSouth;
	sf::Texture textureWest;

	sf::Sprite playerBody;

	sf::Vector2f playerPosition = { 400.0f,300.0f };

	int playerHealth = 0;
	int playerSpeed = 0;
	int playerScore = 0;
	int playerDirection = 0;
	bool isAlive = true;

	//Function Members
	Player();
	int getDirection();
	sf::Sprite getBody();
	sf::Vector2f getPos();
	void loadPlayerTexture();
	void decreaseHealth(int t_healthLoss);
	void moveLeft(); // Used to move the player left but stay within the boundary of the screen.
	void moveRight();
	void moveUp();
	void moveDown();
	void checkWallCollision();
	int getHealth();
	void lowerHealth(int t_health);
};