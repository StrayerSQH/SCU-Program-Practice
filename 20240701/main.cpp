#include <iostream>
#include <SFML/Graphics.hpp>
#include <conio.h>
#include "GlobalVar.h"
#include "WindowsShow.h"
#include "Button.h"
#include "ChooseStateButton.h"
#include "ExitButton.h"
#include "MusicBGM.h"
#include "MusicClick.h"
#include "MusicClickDetail.h"

float numAdd(float n);

int main()
{
    //调用播放背景音乐
    MusicBGM music("TestMusic.mp3");
    if (music.loadMusic()) 
    {
        music.play();
    }

    // 创建窗口对象并显示
    WindowsShow windowsShow;
    windowsShow.ShowWindow();
    // 获取窗口对象的引用
    sf::RenderWindow& window = windowsShow.getWindow();

    // 创建模式选择按钮
    float Num = 0;
    ChooseStateButton MainStoryButton(
        window.getSize().x / 2 - ChooseStateButton::ChooseButtonWidth / 2,
        (7 - NumChooseButton + Num) * window.getSize().y / 7 - ChooseStateButton::ChooseButtonHeight / 2,
        "Main Story"
    );
    Num = numAdd(Num);
    ChooseStateButton ExploreButton(
        window.getSize().x / 2 - ChooseStateButton::ChooseButtonWidth / 2,
        (7 - NumChooseButton + Num) * window.getSize().y / 7 - ChooseStateButton::ChooseButtonHeight / 2,
        "Explore"
    );
    // 创建退出按钮
    ExitButton ExitButton_(ExitButton_x, ExitButton_y);

    // 保持窗口开启状态
    while (window.isOpen())
    {
        int end = 1; 
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && end) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // 检查鼠标点击位置是否在退出按钮范围内
                    if (ExitButton_.CheckHover(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y)))) 
                    {
                        // 退出按钮被点击，结束程序,创建互动元素音乐播放
                        Arch archMusic("ArchClickMusic.mp3");
                        if (archMusic.ArchLoadMusic())
                        {
                            archMusic.ArchPlay();
                        }
                        end = ExitButton_.ExitProgram(window);
                    }
                }
            }
        }

        // 获取鼠标位置
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        // 检查鼠标是否在按钮范围内，并设置按钮状态
        MainStoryButton.SetHovered(MainStoryButton.CheckHover(mousePosF));
        ExploreButton.SetHovered(ExploreButton.CheckHover(mousePosF));
        ExitButton_.SetHovered(ExitButton_.CheckHover(mousePosF));

        // 清除之前的图像
        window.clear();

        // 绘制背景
        windowsShow.DrawBackground(window);

        // 绘制按钮
        ExitButton_.Button::DrawButton(window);
        MainStoryButton.Button::DrawButton(window);
        ExploreButton.Button::DrawButton(window);
        // 显示绘制的图像
        window.display();
    }

    return 0;
}

float numAdd(float n)
{
    return n + 1.5;
}