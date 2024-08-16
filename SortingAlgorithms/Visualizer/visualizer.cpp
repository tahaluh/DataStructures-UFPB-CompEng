#include "visualizer.hpp"
#include <SFML/Graphics.hpp>

Visualizer::Visualizer(int width, int height, int fps, const std::string &title)
    : window(sf::VideoMode(width, height), title), width(width), height(height), fps(fps), title(title), running(true)
{
    window.setFramerateLimit(fps);
}

sf::RenderWindow &Visualizer::getWindow()
{
    return this->window;
}

void Visualizer::renderArray(int *arr, int n)
{
    window.clear();

    for (int i = 0; i < n; i++)
    {
        sf::RectangleShape rectangle(sf::Vector2f(10, arr[i]));
        rectangle.setPosition(i * 10, window.getSize().y - arr[i]);
        window.draw(rectangle);
    }

    window.display();
}