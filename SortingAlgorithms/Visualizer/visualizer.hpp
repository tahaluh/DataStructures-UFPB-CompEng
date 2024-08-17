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
    void set(int index, int value);
    void read(int index);

    void renderArray(int n, sf::Color color);
    void renderCompare(int indexA, int indexB);
    void renderSwap(int indexA, int indexB);
    void renderSet(int index, int value);
    void renderRead(int index);
    void renderSortedAnimation();
    bool isSorted();

    void tick();

    void close();
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

#endif // VISUALIZER_HPP