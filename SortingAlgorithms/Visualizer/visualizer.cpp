#include "visualizer.hpp"
#include "../Utils/utils.hpp"
#include <SFML/Graphics.hpp>

Visualizer::Visualizer(int width, int height, int fps, const std::string &title, int min = 1, int max = 100, int *arr = nullptr, int n = 0)
    : window(sf::VideoMode(width, height), title), width(width), height(height), fps(fps), title(title), running(true), min(min), max(max), n(n), arr(arr)
{
    window.setFramerateLimit(0);
    window.setVerticalSyncEnabled(false);
}

sf::RenderWindow &Visualizer::getWindow()
{
    return this->window;
}

void Visualizer::renderArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        this->renderBar(arr[i], i, sf::Color::White);
    }
}

void Visualizer::renderBar(int height, int index, sf::Color color)
{
    int barWidth = this->getBarWidth();
    int barHeight = this->getBarHeight(height);
    sf::RectangleShape rectangle(sf::Vector2f(barWidth, barHeight));
    rectangle.setPosition(index * barWidth, this->height - barHeight);
    rectangle.setFillColor(color);

    window.draw(rectangle);
}

void Visualizer::renderCompare(int *arr, int indexA, int indexB)
{
    this->window.clear();
    this->renderArray(arr, this->n);
    this->renderBar(arr[indexA], indexA, sf::Color::Red);
    this->renderBar(arr[indexB], indexB, sf::Color::Red);
    this->window.display();
    this->tick();
}

void Visualizer::renderSwap(int *arr, int indexA, int indexB)
{
    this->window.clear();
    this->renderArray(arr, this->n);
    this->renderBar(arr[indexA], indexA, sf::Color::Yellow);
    this->renderBar(arr[indexB], indexB, sf::Color::Yellow);
    this->window.display();
    this->tick();
}

void Visualizer::tick()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // sf::sleep(sf::milliseconds(1000 / this->fps));
}

void Visualizer::run(Sorting sorting)
{
    sorting(
        arr, n,
        [this](int *arr, int n)
        {
            this->renderArray(arr, n);
        },
        [this](int *arr, int indexA, int indexB)
        {
            this->renderSwap(arr, indexA, indexB);
        },
        [this](int *arr, int indexA, int indexB)
        {
            this->renderCompare(arr, indexA, indexB);
        });

    this->window.clear();
    this->renderArray(arr, n);

    // render test
}

int Visualizer::getBarWidth()
{
    return this->width / this->n;
}

int Visualizer::getBarHeight(int barHeight)
{
    int value = barHeight;

    int minOut = 1;
    int maxOut = this->height;

    int mappedHeight = minOut + (value - this->min) * (maxOut - minOut) / (this->max - this->min);

    return mappedHeight;
}