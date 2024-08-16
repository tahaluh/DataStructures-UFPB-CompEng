#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include "../Utils/utils.hpp"

using Sorting = std::function<void(int *, int, ArrayProcessor, SwapProcessor, CompareProcessor)>;

class Visualizer
{
public:
    Visualizer(int width, int height, int fps, const std::string &title, int min, int max, int *arr, int n);

    void renderArray(int *arr, int n, sf::Color color);
    void renderCompare(int *arr, int indexA, int indexB);
    void renderSwap(int *arr, int indexA, int indexB);
    void renderSortedAnimation(int *arr, int n);
    bool isSorted(int *arr, int n);

    void tick();

    void close();
    void run(Sorting sorting);

    sf::RenderWindow &getWindow();

private:
    void renderBar(int height, int index, sf::Color color);
    int getBarWidth();
    int getBarHeight(int height);
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