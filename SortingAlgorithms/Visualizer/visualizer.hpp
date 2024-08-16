#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

using ArrayProcessor = std::function<void(int *, int)>;

class Visualizer
{
public:
    Visualizer(int width, int height, int fps, const std::string &title, int min, int max, int *arr, int n);

    void renderArray(int *arr, int n);
    void renderCompare(int *arr, int indexA, int indexB);
    void renderSwap(int *arr, int indexA, int indexB);

    void tick();

    void close();
    void run(ArrayProcessor arrayProcessor);

    sf::RenderWindow &getWindow();

private:
    void renderBar(int height, int index, sf::Color color);
    int mapToRange(int value, int min, int max, int newMin, int newMax);
    sf::RenderWindow window;
    int width;
    int height;
    int fps;
    std::string title;
    bool running;
    int min;
    int max;
    int n;
    int *arr;
};

#endif // VISUALIZER_HPP
