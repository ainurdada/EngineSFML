#include "Movement.h"

void Move(sf::CircleShape& player, float speed) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		player.setPosition(player.getPosition().x - speed, player.getPosition().y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.setPosition(player.getPosition().x + speed, player.getPosition().y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player.setPosition(player.getPosition().x, player.getPosition().y - speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player.setPosition(player.getPosition().x, player.getPosition().y + speed);
	}
}