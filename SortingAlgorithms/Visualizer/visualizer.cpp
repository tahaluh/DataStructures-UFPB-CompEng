#include "visualizer.hpp"
#include "../Utils/utils.hpp"
#include <SFML/Graphics.hpp>

Visualizer::Visualizer(int width, int height, int fps, const std::string &title, int *arr, int min = 1, int max = 100, int n = 0)
    : window(sf::VideoMode(width, height), title), width(width), height(height), fps(fps), title(title), running(true), min(min), max(max), n(n), arr(arr)
{
    window.setFramerateLimit(fps);
}

sf::RenderWindow &Visualizer::getWindow()
{
    return this->window;
}

void Visualizer::renderArray(int n, sf::Color color = sf::Color::White)
{
    window.clear();

    for (int i = 0; i < n; i++)
    {
        this->renderBar(this->arr[i], i, color);
    }

    window.display();
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

void Visualizer::renderCompare(int indexA, int indexB)
{
    this->window.clear();
    this->renderArray(this->n);
    this->renderBar(this->arr[indexA], indexA, sf::Color::Red);
    this->renderBar(this->arr[indexB], indexB, sf::Color::Red);
    this->window.display();
    this->tick();
}

void Visualizer::renderSwap(int indexA, int indexB)
{
    this->window.clear();
    this->renderArray(this->n);
    this->renderBar(this->arr[indexA], indexA, sf::Color::Yellow);
    this->renderBar(this->arr[indexB], indexB, sf::Color::Yellow);
    this->window.display();
    this->tick();
}

void Visualizer::renderSet(int index, int value)
{
    this->window.clear();
    this->renderArray(this->n);
    this->renderBar(value, index, sf::Color::Red);
    this->window.display();
    this->tick();
}

void Visualizer::renderRead(int index)
{
    this->window.clear();
    this->renderArray(this->n);
    this->renderBar(this->arr[index], index, sf::Color::Red);
    this->window.display();
    this->tick();
}

void Visualizer::tick()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
        {
            window.close();
            // end program
            exit(0);
        }
    }

    // sleep for 100 ms
    // sf::sleep(sf::milliseconds(2));
}

void Visualizer::run(std::function<void(int *, int, Visualizer *)> sorting)
{
    sorting(
        arr, n, this);

    if (this->isSorted())
    {
        this->renderSortedAnimation();
    }

    while (window.isOpen())
    {
        window.clear();
        this->renderArray(n, sf::Color::Green);
        window.display();
        this->tick();
    }
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

void Visualizer::renderSortedAnimation()
{
    this->renderArray(this->n);

    for (int i = 0; i < this->n; i++)
    {
        this->renderBar(this->arr[i], i, sf::Color::Green);

        window.display();

        sf::sleep(sf::milliseconds(3));
    }
}

void Visualizer::close()
{
    this->window.close();
}

bool Visualizer::isSorted()
{
    for (int i = 1; i < this->n; ++i)
    {
        if (this->arr[i - 1] > this->arr[i])
        {
            return false;
        }
    }
    return true;
}

// array methods

void Visualizer::swap(int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

    this->renderSwap(a, b);
}

int Visualizer::compare(int a, int b)
{
    this->renderCompare(a, b);

    if (arr[a] > arr[b])
    {
        return 1;
    }
    if (arr[a] < arr[b])
    {
        return -1;
    }
    return 0;
}

void Visualizer::set(int index, int value)
{
    arr[index] = value;

    this->renderSet(index, value);
}

void Visualizer::read(int index)
{
    this->renderRead(index);
}