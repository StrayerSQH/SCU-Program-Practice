#include "Button.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

// 构造函数（在窗口显示的x位置，在窗口显示的y位置，按钮高度，按钮宽度，按钮上显示的文字，按钮的默认透明度128）
Button::Button(float window_x, float window_y, float width, float height, const std::string& text, sf::Uint8 alpha = 128)
{
    shape.setPosition(window_x, window_y);// 设置位置
    shape.setFillColor(sf::Color(128,  128, 128, alpha));// 设置颜色

    //if (!font.loadFromFile("arial.ttf"))  // 请确保您有一个名为"arial.ttf"的字体文件
    //{
    //    cout << "程序加载默认字体失败，请检查字体是否存在！！！" << endl;
    //    // sleep(3);
    //    // return -1;
    //}

    //label.setFont(font);
    //label.setString(text);
    //label.setCharacterSize(24);  // 设置字体大小
    //label.setFillColor(sf::Color::White);  // 设置字体颜色
    //label.setPosition(window_x, window_y);  // 设置文本的位置
}

void Button::DrawButton(sf::RenderWindow& window)
{
    window.draw(shape);
    /*window.draw(label);*/
    window.display();
}

