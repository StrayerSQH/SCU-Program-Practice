#include "Button.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

// 构造函数（在窗口显示的x位置，在窗口显示的y位置，按钮高度，按钮宽度，按钮上显示的文字，按钮的默认透明度128）
Button::Button(float window_x, float window_y, float width, float height, const std::string& text, sf::Uint8 alpha)
    : isHovered(false)
{
    shape.setPosition(window_x, window_y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color(128, 128, 128, alpha));

    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "程序加载默认字体失败，请检查字体是否存在！！！" << endl;
    }

    label.setFont(font);
    label.setString(text);
    label.setCharacterSize(24);
    label.setFillColor(sf::Color::White);
    label.setPosition(window_x, window_y);
}

void Button::DrawButton(sf::RenderWindow& window)
{
    if (isHovered)
    {
        shape.setFillColor(sf::Color::White);
    }
    else
    {
        shape.setFillColor(sf::Color(128, 128, 128, 128));
    }

    window.draw(shape);
    window.draw(label);
}

bool Button::CheckHover(const sf::Vector2f& mousePos)
{
    return shape.getGlobalBounds().contains(mousePos);
}

void Button::SetHovered(bool hovered)
{
    isHovered = hovered;

}