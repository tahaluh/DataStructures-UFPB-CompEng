#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

class Visualizer
{
public:
    Visualizer(int width, int height, int fps, const std::string &title, int *arr, int min, int max, int n);

    int compare(int a, int b);
    void swap(int a, int b);

    void renderArray(int n, sf::Color color);
    void renderCompare(int indexA, int indexB);
    void renderSwap(int indexA, int indexB);
    void renderSortedAnimation();
    bool isSorted();

    void tick();

    void close();
    // receive a function that returns a void and receives a int array, a int and a Visualizer
    void run(std::function<void(int *, int, Visualizer *)> sorting);

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

// define a type Sorting that is a function that returns void and receives a int array, a int and a Visualizer
using Sorting = std::function<void(int *, int, Visualizer *)>;

#endif // VISUALIZER_HPP