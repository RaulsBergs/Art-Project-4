#include "Player.h"   // include Player header file
#include <iostream>
#include "Globals.h"
// Player function definitions here

/// <summary>
/// Constructs the player
/// </summary>
Player::Player()
{
	playerSpeed = 5;
	playerHealth = 100;
	loadPlayerTexture();
	isAlive = true;
	playerBody.setTexture(textureSouth);
	playerBody.setPosition(playerPosition);
	playerBody.setOrigin(0,0);
	playerDirection = 1;
}

/// <summary>
/// Returns players direction
/// </summary>
/// <returns></returns>
int Player::getDirection()
{
	return playerDirection;
}

/// <summary>
/// Returns player sprite
/// </summary>
/// <returns></returns>
sf::Sprite Player::getBody()
{
	return playerBody;
}

/// <summary>
/// Returns player position
/// </summary>
/// <returns></returns>
sf::Vector2f Player::getPos()
{
	return playerPosition;
}

/// <summary>
/// Loads game sprites
/// </summary>
void Player::loadPlayerTexture()
{
	if (!textureSouth.loadFromFile("ASSETS\\IMAGES\\Player1.png"))
	{
		std::cout << "Problem Loading 'Player1.png'" << std::endl;
	}
	//if (!textureNorth.loadFromFile("ASSETS\\IMAGES\\player_up.png"))
	//{
	//	std::cout << "Problem Loading 'player_up.png'" << std::endl;
	//}
	//if (!textureEast.loadFromFile("ASSETS\\IMAGES\\player_right.png"))
	//{
	//	std::cout << "Problem Loading 'player_right.png'" << std::endl;
	//}
	//if (!textureWest.loadFromFile("ASSETS\\IMAGES\\player_left.png"))
	//{
	//	std::cout << "Problem Loading 'player_left.png'" << std::endl;
	//}
}

/// <summary>
/// Decerases player health
/// </summary>
/// <param name="t_healthLoss"></param>
void Player::decreaseHealth(int t_healthLoss)
{
	playerHealth = playerHealth - t_healthLoss;
}

/// <summary>
/// Player moves left
/// </summary>
void Player::moveLeft()
{
	playerDirection = 2;
	playerBody.setTexture(textureSouth);
	playerPosition = playerBody.getPosition();
	playerPosition.x = (playerPosition.x - (1 * playerSpeed));
	playerBody.setPosition(playerPosition);
}

/// <summary>
/// Player Moves right
/// </summary>
void Player::moveRight()
{
	playerDirection = 1;
	playerBody.setTextureRect(sf::IntRect(0, 0, 50, 100));
	playerPosition = playerBody.getPosition();
	playerPosition.x = (playerPosition.x + (1 * playerSpeed));
	playerBody.setPosition(playerPosition);

}

/// <summary>
/// PLayer moves up
/// </summary>
void Player::moveUp()
{
	playerDirection = 3;
	playerBody.setTexture(textureSouth);
	playerPosition = playerBody.getPosition();
	playerPosition.y = (playerPosition.y - (1 * playerSpeed));
	playerBody.setPosition(playerPosition);

}

/// <summary>
/// Player moves down
/// </summary>
void Player::moveDown()
{
	playerDirection = 4;
	playerBody.setTexture(textureSouth);
	playerPosition = playerBody.getPosition();
	playerPosition.y = (playerPosition.y + (1 * playerSpeed));
	playerBody.setPosition(playerPosition);
}

/// <summary>
/// When the player collides with the window boundaries, the player cant leave them
/// </summary>
void Player::checkWallCollision()
{
	if (playerBody.getPosition().x > SCREEN_WIDTH - 50)
	{
		sf::Vector2f dontLeaveBoundaries;
		dontLeaveBoundaries = playerBody.getPosition();
		dontLeaveBoundaries = { SCREEN_WIDTH - 50,dontLeaveBoundaries.y };
		playerBody.setPosition(dontLeaveBoundaries);
	}

	else if (playerBody.getPosition().x < 0 - 10)
	{
		sf::Vector2f dontLeaveBoundaries;
		dontLeaveBoundaries = playerBody.getPosition();
		dontLeaveBoundaries = { 0 - 10,dontLeaveBoundaries.y };
		playerBody.setPosition(dontLeaveBoundaries);
	}

	else if (playerBody.getPosition().y > SCREEN_HEIGHT - 60)
	{
		sf::Vector2f dontLeaveBoundaries;
		dontLeaveBoundaries = playerBody.getPosition();
		dontLeaveBoundaries = { dontLeaveBoundaries.x , SCREEN_HEIGHT - 60 };
		playerBody.setPosition(dontLeaveBoundaries);
	}

	else if (playerBody.getPosition().y < 0 - 10)
	{
		sf::Vector2f dontLeaveBoundaries;
		dontLeaveBoundaries = playerBody.getPosition();
		dontLeaveBoundaries = { dontLeaveBoundaries.x , 0 - 10};
		playerBody.setPosition(dontLeaveBoundaries);
	}
}

/// <summary>
/// Returns players total health
/// </summary>
/// <returns>playerHealth</returns>
int Player::getHealth()
{
	return playerHealth;
}

/// <summary>
/// Subtarcts helath from players total health when an enemy collides with the player
/// </summary>
/// <param name="t_health">int t_health</param>
void Player::lowerHealth(int t_health)
{
	playerHealth = playerHealth - t_health;
}
