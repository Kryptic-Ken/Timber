//All of the important header Files
#include "pch.h"
#include <iostream>
//#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	//Initializes a window to fit to our computer's resolution
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

	//Creating a texture
	Texture textureBackground;
	//finding the texture in the sub-folder of this project
	textureBackground.loadFromFile("graphics/sprite_Background.png");
	//Initializing a sprite to be used for the Background
	Sprite spriteBackground;
	//Setting the texture as the Sprite image
	spriteBackground.setTexture(textureBackground);
	//setting the sprite in the correct position to use it as a Background
	spriteBackground.setPosition(0, 0);

	//Making a sprite Tree
	Texture textureTree;
	textureTree.loadFromFile("graphics/sprite_MainTree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	//Bee Sprite
	Texture textureBee;
	textureBee.loadFromFile("graphics/sprite_Bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);

	//Bool value for activity
	bool beeActive = false;

	float beeSpeed = 0.0f;

	//make 3 cloud sprite from 1 texture
	Texture textureCloud;
	textureCloud.loadFromFile("graphics/sprite_Cloud.png");

	//3 New sprites with the same texture
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);

	//position of the clouds
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);

	//boolean valuse of the clouds
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;

	//Speed in which the Clouds move
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;

	//Variables to control time itself
	Clock clock;

	//Track whether the game is running
	bool paused = true;
	//while the window is open it will execute all the code inside.
	while (window.isOpen())
	{
		//looks for input to close the window
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		

		//Measure time
		Time dt = clock.restart();

		//Setup the bee
		if (!beeActive)
		{
			//how fast is the bee
			srand((int)time(0));
			beeSpeed = (rand() % 200) + 200;

			//How high is the bee
			srand((int)time(0)* 10);
			float height = (rand() % 500) + 500;
			spriteBee.setPosition(2000, height);
			beeActive = true;
		}
		else
		{
			spriteBee.setPosition(
				spriteBee.getPosition().x -
				(beeSpeed * dt.asSeconds()),
				spriteBee.getPosition().y);

			//Has the bee reached the right hand edge of the screen?
			if (spriteBee.getPosition().x < -100)
			{
				beeActive = false;
			}
		}

		//Manage the clouds
		//Cloud 1
		if (!cloud1Active)
		{
			//How fast is the cloud
			srand((int)time(0) * 100);
			cloud1Speed = (rand() % 200);

			//how high is the cloud
			srand((int)time(0) * 10);
			float height = (rand() % 150);
			spriteCloud1.setPosition(-200, height);
			cloud1Active = true;
		}
		else {
			spriteCloud1.setPosition(
				spriteCloud1.getPosition().x +
				(cloud1Speed * dt.asSeconds()),
				spriteCloud1.getPosition().y);

			//Has the cloud reached the right hand edge of teh screen?
			if (spriteCloud1.getPosition().x > 1920)
			{
				cloud1Active = false;
			}
		}

		//Cloud 2
		if (!cloud2Active)
		{
			//How fast is the cloud
			srand((int)time(0) * 100);
			cloud2Speed = (rand() % 200);

			//how high is the cloud
			srand((int)time(0) * 10);
			float height = (rand() % 150);
			spriteCloud2.setPosition(-200, height);
			cloud2Active = true;
		}
		else {
			spriteCloud2.setPosition(
				spriteCloud2.getPosition().x +
				(cloud2Speed * dt.asSeconds()),
				spriteCloud2.getPosition().y);

			//Has the cloud reached the right hand edge of teh screen?
			if (spriteCloud2.getPosition().x > 1920)
			{
				cloud2Active = false;
			}
		}

		//Cloud 3
		if (!cloud3Active)
		{
			//How fast is the cloud
			srand((int)time(0) * 100);
			cloud3Speed = (rand() % 200);

			//how high is the cloud
			srand((int)time(0) * 10);
			float height = (rand() % 150);
			spriteCloud3.setPosition(-200, height);
			cloud3Active = true;
		}
		else {
			spriteCloud3.setPosition(
				spriteCloud3.getPosition().x +
				(cloud3Speed * dt.asSeconds()),
				spriteCloud3.getPosition().y);

			//Has the cloud reached the right hand edge of teh screen?
			if (spriteCloud3.getPosition().x > 1920)
			{
				cloud3Active = false;
			}
		}



		//Clears the screen and draws the content in the same frame.
		window.clear();
		window.draw(spriteBackground);

		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		window.draw(spriteTree);
		window.draw(spriteBee);
		window.display();

	}
	return 0;
}

