#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"
struct Brick {
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f vector2f;
};
void brickInit(Brick& brick) {
	brick.shape.setSize(sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
	brick.shape.setFillColor(BRICK_COLOR);
	brick.shape.setPosition(BRICK_START_POS);
}
void brickUpdate(Brick& brick) {

}
void batReboundEdges(Brick& brick) {
	float brickx = brick.shape.getPosition().x;
	float bricky = brick.shape.getPosition().y;
	if (brickx <= 0) brick.shape.setPosition(0.f, bricky);
	if (brickx >= WINDOW_WIDTH - BAT_WIDTH)
		brick.shape.setPosition(WINDOW_WIDTH - BAT_WIDTH, bricky);
}
void brickDraw(sf::RenderWindow& window, const Brick& brick) {
	window.draw(brick.shape);
}
