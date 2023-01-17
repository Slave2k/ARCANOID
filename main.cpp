#include "settings.h"
#include <ctime>
#include "functions.h"
#include "bat.h"
#include "TextObj.h"
#include "brick.h"

using namespace sf;
int main()
{
	srand(time(0));

	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE
	);
	int score = 0;
	Bat bat;
	batInit(bat);
	Ball ball;
	ballInit(ball);
	TextObj scoreText;
	textInit(scoreText, score);
	Brick brick;
	brickInit(brick);

	while (window.isOpen()) {
		checkEvents(window);
		updateGame(bat, ball, scoreText, score);
		if (ball.shape.getPosition().y >=
			WINDOW_HEIGHT - 2 * BALL_RADIUS)
			break;
		checkCollisions(bat, ball);
		drawGame(window, bat, ball, scoreText);
	}
	return 0;
}