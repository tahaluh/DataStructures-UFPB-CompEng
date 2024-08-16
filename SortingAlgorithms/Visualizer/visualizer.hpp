#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

using ArrayProcessor = std::function<void(int *, int)>;

class Visualizer
{
public:
    Visualizer(int width, int height, int fps, const std::string &title);

    void renderArray(int *arr, int n);
    void renderCompare(int a, int b);
    void renderSwap(int a, int b);

    void close();
    void run(ArrayProcessor arrayProcessor);

    sf::RenderWindow &getWindow();

private:
    sf::RenderWindow window;
    int width;
    int height;
    int fps;
    std::string title;
    bool running;
};

#endif // VISUALIZER_HPP
