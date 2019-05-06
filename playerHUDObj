


const unsigned int MESSAGE_TEXT_SIZE = 75;
const unsigned int SCORE_TEXT_SIZE = 100;
const float TEXT_PADDING_TOP_LEFT = 20.0f;


class HUD: public Object
{
private:
    Text messageText;
    Text scoreText;
    Font font;
    
    RectangleShape scoreTextBackground;

    RectangleShape timeBar;
    float timeBarStartWidth;
    float timeBarHeight;
    float timeBarWidthPerSecond;

    int oldScore;           // Previous value of the players score
    bool* paused;        // Only for reading purposes
    int* playerScore;            // Only for reading purposes
    float* playerTimeRemaining;  // Only for reading purposes
    bool* PlayerDied;    // Only for reading purposes
public:
    HUD(bool* paused, int* playerScore, float* playerTimeRemaining, bool* PlayerDied);

    virtual void update(RenderWindow& window, Time timedelta) override;
    virtual void draw(RenderWindow& window) override;
private:
    void setMessageText(std::string text);
    void updateScore(int score);
    void updateTimeRemaining(float timeRemaining);
};
