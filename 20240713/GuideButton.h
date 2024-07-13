#ifndef GUIDEBUTTON_H
#define GUIDEBUTTON_H

#include "SFML/Graphics.hpp"

class GuideButton{
private:
    int characterIndex;
    float labelSpeed = 0.05f;
    sf::Clock clock;

public:
    float GuideButtonWidth;
    static float GuideButtonHeight;
    bool isHovered;             // 按钮是否被鼠标悬停
    float characterSize = 50;
    float window_x, window_y;
    std::string guideButtonText;
    std::string currentLabel;
    sf::RectangleShape shape;   // 按钮的形状
    sf::Text label;             // 按钮上的文本
    sf::Font font;              // 按钮上文本的字体

	GuideButton(std::string text);

    bool DrawButton(sf::RenderWindow& window);

	void NextGuideButton();
};

#endif // !GUIDEBUTTON_H

