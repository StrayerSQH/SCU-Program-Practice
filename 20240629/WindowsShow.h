#ifndef WINDOWSSHOW_H
#define WINDOWSSHOW_H

#include <SFML/Graphics.hpp>

class WindowsShow {
private:
    sf::RenderWindow window;
public:
    void ShowWindow();
    sf::RenderWindow& getWindow();
};

#endif // WINDOWSSHOW_H