#include "Explore.h"
#include "SFML/Graphics.hpp"
#include "conio.h"
#include "ReturnHomeButton.h"
#include "GlobalVar.h"
#include "MusicClickDetail.h"

int Explore::TILE_SIZE = 20;

void Explore::MapSet()
{
    img[0].loadFromFile("E:\\图片\\Screenshots\\road.png");
    img[1].loadFromFile("E:\\图片\\Screenshots\\dormitory.png");
    img[2].loadFromFile("E:\\图片\\Screenshots\\ABCD.png");
    img[3].loadFromFile("E:\\图片\\Screenshots\\dining_hall.png");
    img[4].loadFromFile("E:\\图片\\Screenshots\\school_gate.png");
    img[5].loadFromFile("E:\\图片\\Screenshots\\river.png");
    img[6].loadFromFile("E:\\图片\\Screenshots\\pool.png");
    img[7].loadFromFile("E:\\图片\\Screenshots\\changqiao.png");
    img[8].loadFromFile("E:\\图片\\Screenshots\\guangchang.png");
    img[9].loadFromFile("E:\\图片\\Screenshots\\erjilou.png");
    img[10].loadFromFile("E:\\图片\\Screenshots\\zonghelou.png");
    img[11].loadFromFile("E:\\图片\\Screenshots\\library.png");
    img[12].loadFromFile("E:\\图片\\Screenshots\\man_s.png");
    img[13].loadFromFile("E:\\图片\\Screenshots\\man_w.png");
    img[14].loadFromFile("E:\\图片\\Screenshots\\man_l.png");
    img[15].loadFromFile("E:\\图片\\Screenshots\\man_r.png");
}

void Explore::DrawMap(sf::RenderWindow& window)
{
    for (int i = 0; i < 48; i++) // 行
    {
        for (int j = 0; j < 57; j++) // 列
        {
            sf::Sprite sprite;
            sprite.setTexture(img[Map[i][j]]);
            sprite.setPosition(j * TILE_SIZE, i * TILE_SIZE);
            window.draw(sprite);
        }
    }
}

void Explore::MoveCharacter(sf::RenderWindow& window)
{
    if (moving)
    {
        return;
    }

    moving = true;

    if (key == 'w' || key == 'W')
    {
        if (y > 0 && (Map[y - 1][x] == 0 || Map[y - 1][x] == 7))
        {
            DrawMap(window);
            y--;
            sf::Sprite sprite;
            sprite.setTexture(img[13]);
            sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
            window.draw(sprite);
        }
    }
    else if (key == 's' || key == 'S')
    {
        if (y < 47 && (Map[y + 1][x] == 0 || Map[y + 1][x] == 7))
        {
            DrawMap(window);
            y++;
            sf::Sprite sprite;
            sprite.setTexture(img[12]);
            sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
            window.draw(sprite);
        }
    }
    else if (key == 'a' || key == 'A')
    { // 向左移动
        if (x > 0 && (Map[y][x - 1] == 0 || Map[y][x - 1] == 7))
        {
            DrawMap(window);
            x--;
            sf::Sprite sprite;
            sprite.setTexture(img[14]);
            sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
            window.draw(sprite);
        }
    }
    else if (key == 'd')
    { // 向右移动
        if (x < 56 && (Map[y][x + 1] == 0 || Map[y][x + 1] == 7))
        {
            DrawMap(window);
            x++;
            sf::Sprite sprite;
            sprite.setTexture(img[15]);
            sprite.setPosition(x * TILE_SIZE, y * TILE_SIZE);
            window.draw(sprite);
        }
    }

    moving = false;
}

int Explore::Program(sf::RenderWindow& window)
{
    float ScreenWidth, ScreenHeight;
    ScreenWidth = window.getSize().x;
    ScreenHeight = window.getSize().y;

    ReturnHomeButton returnHomeButton(ExitButton_x, ExitButton_y);

    // 初始化地图
    MapSet();

    while (window.isOpen())
    {
        int end = 1;
        int returnHome = 1;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }

            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if ((event.type == sf::Event::MouseButtonPressed && end) && returnHome) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // 检查鼠标点击位置是否在退出按钮范围内
                    if (returnHomeButton.CheckHover(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        // 退出按钮被点击，结束程序,创建互动元素音乐播放
                        Arch archMusic("ArchClickMusic.mp3");
                        if (archMusic.ArchLoadMusic())
                        {
                            archMusic.ArchPlay();
                        }
                        returnHome = returnHomeButton.ExitProgram(window);

                        if (returnHome)
                        {
                            return 0;
                        }
                    }
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            key = 'w';
            MoveCharacter(window);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            key = 's';
            MoveCharacter(window);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            key = 'a';
            MoveCharacter(window);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            key = 'd';
            MoveCharacter(window);
        }
        // 获取鼠标位置
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        window.clear();
        DrawMap(window);

        // 检查鼠标是否在按钮范围内，并设置按钮状态
        returnHomeButton.SetHovered(returnHomeButton.CheckHover(mousePosF));
        returnHomeButton.DrawButton(window);
        window.display();
    }


    return 0;
}