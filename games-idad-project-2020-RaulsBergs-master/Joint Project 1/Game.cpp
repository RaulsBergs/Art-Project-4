// Name: Rauls Bergs
// Login: C00247700
// Date: 11/02/2020
// Approximate time taken: 6 Hours
//---------------------------------------------------------------------------
// Project description: This is a 2D game.
// ---------------------------------------------------------------------------
// Known Bugs: 
// ?

//////////////////////////////////////////////////////////////
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////////

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 



#include "Game.h"   // include Game header file
#include "Player.h"

int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();
	return 0;
}

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
}

void Game::loadContent()
// Load the font file & setup the message string
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}
	if (!backGroundTexture.loadFromFile("ASSETS\\IMAGES\\BackGround.png"))
	{
		std::cout << "No floor asset found" << std::endl;
	}
	//Set Up BackGround
	backGroundSprite.setTexture(backGroundTexture);
	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen

	m_playerHealth.setFont(m_font);
	m_playerHealth.setCharacterSize(24);
	m_playerHealth.setFillColor(sf::Color::White);
	m_playerHealth.setPosition(sf::Vector2f(10, 50));
}

void Game::run()
// This function contains the main game loop which controls the game. 
{
	srand(time(NULL)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;

	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop
}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	if (endGame == true)
	{
		drawGameOverText();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			endGame = false;
		}
	}
	if (endGame == false)
	{
		// get keyboard input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			playerOne.moveLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			playerOne.moveRight();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			playerOne.moveDown();
		}	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			playerOne.moveUp();
		}
		/// <summary>
		/// This is responsible for the bullet movement
		/// </summary>
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			bullet.fireBullet(playerOne);
		}


		bullet.move();
		bullet.checkWallCollision();
		// update any game variables here ...
		playerOne.checkWallCollision();

		for (int index = 0; index < 3; index++)
		{
			Enemies[index].checkWallCollision();
			Enemies[index].move();
		}

		for (int index = 0; index < 3; index++)
		{
			{
				enemiesTwo[index].followPlayer(playerOne.getBody().getPosition());
				enemiesTwo[index].damagePlayer(playerOne, playerOne.getHealth());
				bullet.killEnemy(enemiesTwo[index]);
				displayPlayerHealth();
			}
		}
		for (int index = 0; index < 3; index++)
		{
			enemiesTwo[index].intialise();
		}
		gameOver(playerOne);
	}

}

void Game::draw()
// This function draws the game world
{
	if (endGame == true)
	{
		window.clear(sf::Color::Color(34, 35, 67, 38));
		window.draw(m_gameOverText);
		window.display();
	}
	if (endGame == false)
	{
		// Clear the screen and draw your game sprites
		window.clear(sf::Color::Color(34,35,67,38));
		window.draw(backGroundSprite);
		m_message.setString("Gun Point DarWinX");

		window.draw(m_message);  // write message to the screen
		for (int index = 0; index < 3; index++)
		{
			window.draw(enemiesTwo[index].getBody());
		}

		window.draw(playerOne.getBody());
		for (int index = 0; index < 3; index++)
		{
			window.draw(Enemies[index].getBody());
		}
		window.draw(m_playerHealth);
		sf::VertexArray EnemyCentre();
		if (bullet.getRenderBool() == true)
		{
			window.draw(bullet.getProjectileBody());
		}
		window.display();
	}
}

void Game::displayPlayerHealth()
{
	m_playerHealth.setString("Player Health: " + std::to_string(playerOne.getHealth()));
}

int Game::getDirection()
{
	return direction;
}

void Game::gameOver(Player t_player)
{
	int playerHealth;
	playerHealth = t_player.getHealth();
	if (playerHealth == 0)
	{
		endGame = true;
	}
}

void Game::drawGameOverText()
{
	m_gameOverText.setCharacterSize(30);
	m_gameOverText.setString("Game Over PRESS R TO RESTART");
	m_gameOverText.setFont(m_font);
	m_gameOverText.setFillColor(sf::Color::White);
	m_gameOverText.setPosition(sf::Vector2f(250, 300));
}
























//void Game::collsisionDetection()
//{
//	sf::FloatRect playerRect, enemyRect;
//	playerRect = playerOne.getBody().getGlobalBounds();
//	for (int index = 0; index < MAX_NUM_SLIMES; index++)
//		{
//			enemyRect = enemiesTwo[index].getBody().getGlobalBounds();
//					
//				if (playerRect.intersects(enemyRect))
//					{
//						fixSlimeCollision();
//						playerOne.decreaseHealth(1);
//					}
//		}
//}
//
//void Game::fixSlimeCollision()
//{
//	for (int index = 0; index < MAX_NUM_SLIMES + 1; index++)
//	{
//		if (enemiesTwo[index].getBody().getGlobalBounds().intersects(enemiesTwo[index + 1].getBody().getGlobalBounds()))
//		{
//			enemiesTwo[index].getBody().setPosition(sf::Vector2f{ 0.0f,0.0f });
//		}
//		else
//		{
//			stopMovement = false;
//		}
//	}
//}

