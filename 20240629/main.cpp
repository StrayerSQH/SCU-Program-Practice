#include <iostream>
#include <SFML/Graphics.hpp>
#include <conio.h>
#include "GlobalVar.h"
#include "WindowsShow.h"
#include "Button.h"
#include "ChooseStateButton.h"
#include "ExitButton.h"

//创建退出按钮
ExitButton ExitButton_(ExitButton_x, ExitButton_y);

int main()
{
    // 定义窗口对象并显示
    WindowsShow windowsShow;
    windowsShow.ShowWindow();
    // 获取窗口对象的引用
    sf::RenderWindow& window = windowsShow.getWindow();

    //创建模式选择按钮
    ChooseStateButton MainStoryButton(
        window.getSize().x / 4 - ChooseStateButton::ChooseButtonWidth / 2,
        window.getSize().y / 4 - ChooseStateButton::ChooseButtonHeight / 2
    );
    ChooseStateButton ExploreButton(
        3 * window.getSize().x / 4 - ChooseStateButton::ChooseButtonWidth / 2,
        3 * window.getSize().y / 4 - ChooseStateButton::ChooseButtonHeight / 2
    );

    // 保持窗口开启状态
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // 处理窗口事件
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        //清除之前的图像
        //window.clear();
        // 绘制按钮
        ExitButton_.DrawButton(window);
        MainStoryButton.DrawButton(window);
        ExploreButton.DrawButton(window);
        //画出所有的图像
        window.display();
    }
    return 0;
}