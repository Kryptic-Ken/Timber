//#include "stdafx.h"
#include "HUD.h"
#include <sstream>


HUD::HUD(bool* IsPaused, int* playerScore, float* playerTimeRemaining, bool* PlayerDied):
Object(),
IsPaused(IsPaused),
playerScore(playerScore),
playerTimeRemaining(playerTimeRemaining),
PlayerDied(PlayerDied),
timeBarWidthPerSecond(60)
{
    font.loadFromFile("Resources/Fonts/KOMIKAP_.ttf");

    // Set the font to our message
    messageText.setFont(font);
    scoreText.setFont(font);

    // Assign the actual message
    messageText.setString("Press Enter to start!");
    scoreText.setString("Score = 0");

    // Change the default size to a custom
    messageText.setCharacterSize(MESSAGE_TEXT_SIZE);
    scoreText.setCharacterSize(SCORE_TEXT_SIZE);

    // Choose a color
    messageText.setFillColor(Color::Black);
    scoreText.setFillColor(Color::Black);

    // Position the text
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    messageText.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);
    scoreText.setPosition(TEXT_PADDING_TOP_LEFT, TEXT_PADDING_TOP_LEFT);

    // Time bar
    timeBarStartWidth = 400;
    timeBarHeight = 80;

    if (playerTimeRemaining)
        timeBarWidthPerSecond = timeBarStartWidth / (*playerTimeRemaining);

    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((WINDOW_WIDTH / 2) - timeBarStartWidth / 2, 980);

    scoreTextBackground.setFillColor(sf::Color(0, 0, 0, 150));
    scoreTextBackground.setSize(Vector2f(570, 105));
    scoreTextBackground.setPosition(0, 30);
}


void HUD::setMessageText(std::string text)
{
    // Change the message shown to the player
    messageText.setString(text);

    // Positions the text based on its size 
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    messageText.setPosition(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f);
}


void HUD::updatePlayerScore(int score)
{
    std::stringstream ss;
    ss << "Score = " << score;
    scoreText.setString(ss.str());

    FloatRect scoreTextSize = scoreText.getLocalBounds();
    scoreTextBackground.setFillColor(sf::Color(0, 0, 0, 150));
    scoreTextBackground.setSize(Vector2f(scoreTextSize.width + 50, 105));
    scoreTextBackground.setPosition(0, 30);
}


void HUD::updatePlayerTimeRemaining(float timeRemaining)
{
    // Size up the time bar
    timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));
}


void HUD::update(RenderWindow& window, Time timedelta)
{
    updatePlayerTimeRemaining(*playerTimeRemaining);

    if (IsPaused && (*IsPaused))
    {
        if (playerTimeRemaining && (*playerTimeRemaining <= 0.0f))
            setMessageText("Out of time!!");

        if (pPlayerIsDied && (*pPlayerIsDied))
            setMessageText("SQUASHED!!");
    }

    if (playerScore && (*playerScore) != oldScore)
    {
        oldScore = *playerScore;
        updatePlayerScore(oldScore);
    }
}


void HUD::draw(RenderWindow& window)
{
    // Draw the timebar
    window.draw(timeBar);

    // Display messages on the screen
    window.draw(scoreTextBackground);
    window.draw(scoreText);
    if (pIsPaused && (*pIsPaused))
    {
        window.draw(messageText);
    }
}
