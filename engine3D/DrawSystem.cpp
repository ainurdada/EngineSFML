#include "DrawSystem.h"
#include <iostream>

void RaycastDraw(sf::CircleShape player, sf::RenderWindow& window) {
	float rayLength = 50;
	float rayAngle = 90 * (3.14 / 180);
	float rayNumber = 10;
	sf::Vector2f vecStart(player.getPosition().x + player.getRadius(), player.getPosition().y + player.getRadius());
	sf::Vector2f directionVec(sf::Mouse::getPosition(window));
	sf::Vector2f basisVec(directionVec.x - vecStart.x, directionVec.y - vecStart.y);

	float basisLength = (basisVec.x * basisVec.x) + (basisVec.y * basisVec.y);
	float vecMultiply = rayLength / std::sqrtf(basisLength);
	sf::Vector2f vecEnd(vecStart.x + vecMultiply * basisVec.x, vecStart.y + vecMultiply * basisVec.y);

	sf::VertexArray line(sf::Lines, 2);
	line[0].position = vecStart;
	line[1].position = vecEnd;

	window.draw(line);

	for (float angle = -(rayAngle / 2); angle <= rayAngle / 2; angle += rayAngle / rayNumber) {
		sf::Vector2f rightVec = vecEnd - vecStart;
		sf::Vector2f vecEndPereferi(rightVec.x * std::cosf(angle) - rightVec.y * std::sinf(angle), rightVec.x * std::sinf(angle) + rightVec.y * std::cosf(angle));

		sf::VertexArray linePereferi(sf::Lines, 2);

		linePereferi[0].position = vecStart;
		linePereferi[1].position = vecStart + vecEndPereferi;

		window.draw(linePereferi);
	}

}