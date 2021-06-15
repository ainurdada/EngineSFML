#include "Movement.h"
#include "DrawSystem.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>



int main()
{
    float screenSizeX = 800, screenSizeY = 600;
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(screenSizeX, screenSizeY), "3D Engine");

    //create player
    sf::CircleShape player;
    player.setRadius(10);
    player.setPosition(150, 20);

    //create circle1
    sf::CircleShape circle1;
    circle1.setRadius(100);
    circle1.setPosition(200, 200);

    //create circle2
    sf::CircleShape circle2;
    circle2.setRadius(35);
    circle2.setPosition(80, 200);

    //create rect
    sf::RectangleShape rectangle1;
    rectangle1.setSize(sf::Vector2f(50, 50));
    rectangle1.setPosition(100, 100);

    //create ramka
    sf::RectangleShape ramka;
    ramka.setSize(sf::Vector2f(screenSizeX-20, screenSizeY-20));
    ramka.setFillColor(sf::Color::Transparent);
    ramka.setOutlineColor(sf::Color::Red);
    ramka.setOutlineThickness(10);
    ramka.setPosition(10, 10);

    //create convex
    sf::ConvexShape convex1;
    convex1.setPointCount(3);
    convex1.setPoint(0, sf::Vector2f(200, 10));
    convex1.setPoint(1, sf::Vector2f(250, 20));
    convex1.setPoint(2, sf::Vector2f(220, 50));


    //Start game loop
    while (window.isOpen())
    {
        //Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Input menegment
        Move(player, 0.01);

        //Clear window
        window.clear();

#pragma region Draw zone

        

        window.draw(ramka);
        window.draw(rectangle1);
        window.draw(circle1);
        window.draw(circle2);
        window.draw(convex1);
        window.draw(player);
        RaycastDraw(player, window);
#pragma endregion
        

        //Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}