#include "Explore.h"
#include "SFML/Graphics.hpp"
#include "ReturnHomeButton.h"
#include "GlobalVar.h"
#include "MusicClickDetail.h"
#include "Egg.h"
#include "ArchBuilding.h"

float Explore::PIXEL_SIZE = 50;

Explore::Explore(int sex) : character_x(1000), character_y(1000)
{
    Sex = sex;
    character.setSize(sf::Vector2f(PIXEL_SIZE, PIXEL_SIZE));
    character.setFillColor(sf::Color::Red);
    if (Sex == 1)
    {
        if (!sexSetTexture.loadFromFile("Boy.jpg"))
        {
            std::cout << "Fail to open Boy.jpg" << endl;
        }

        sexSetSprite.setTexture(sexSetTexture);
        sexSetSprite.setPosition(character_x, character_y);
        // 设置箭头图片的大小
        sexSetSprite.setScale(
            PIXEL_SIZE / sexSetSprite.getLocalBounds().width,
            PIXEL_SIZE / sexSetSprite.getLocalBounds().height
        );
    }
    else
    {
        if (!sexSetTexture.loadFromFile("Girl.jpg"))
        {
            std::cout << "Fail to open Girl.jpg" << endl;
        }

        sexSetSprite.setTexture(sexSetTexture);
        sexSetSprite.setPosition(character_x, character_y);
        // 设置箭头图片的大小
        sexSetSprite.setScale(
            PIXEL_SIZE / sexSetSprite.getLocalBounds().width,
            PIXEL_SIZE / sexSetSprite.getLocalBounds().height
        );
    }
}


void Explore::MoveUp()
{
    if (!checkCollision(character_x, character_y))
        character_y -= PIXEL_SIZE / 5;
}

void Explore::MoveDown()
{
    if (!checkCollision(character_x, character_y + PIXEL_SIZE ))
        character_y += PIXEL_SIZE / 5;
}

void Explore::MoveLeft() 
{
    if (!checkCollision(character_x, character_y))
        character_x -= PIXEL_SIZE / 5;
}

void Explore::MoveRight() 
{
    if (!checkCollision(character_x + PIXEL_SIZE, character_y))
        character_x += PIXEL_SIZE / 5;
}

void Explore::Update() {
    character.setPosition(character_x, character_y);
    sexSetSprite.setPosition(character_x, character_y);
}

void Explore::Draw(sf::RenderWindow& window) {
    window.draw(sexSetSprite);
    //window.draw(character);
}


int Explore::Program(sf::RenderWindow& window)
{
    window.setFramerateLimit(60);

    ReturnHomeButton returnHomeButton(ExitButton_x, ExitButton_y);
    Explore characterControll(Sex);
    Egg cat(500, 500, 480, 40, 40, "1694597194197.jpg");
    ArchBuilding TeachingBuildingOne(1000, 1000, 500, 300, "TeachingBuildingOne.jpg");
    ArchBuilding Libarary(1500, 100, 350, 230, "Library.jpg");
    ArchBuilding Dormitory(200, 1000, 300, 300, "Dormitory.jpg");

    float ScreenWidth, ScreenHeight;
    ScreenWidth = window.getSize().x;
    ScreenHeight = window.getSize().y;

    while (window.isOpen())
    {
        int end = 1;
        int returnHome = 1;
        sf::Event event;
        
        while(window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
            else if ((event.type == sf::Event::MouseButtonPressed && end) && returnHome) 
            {
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
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

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (TeachingBuildingOne.CheckHover(window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y))))
                    {
                        TeachingBuildingOne.isClicked = true;
                        Arch archMusic("ArchClickMusic.mp3");
                        if (archMusic.ArchLoadMusic())
                        {
                            archMusic.ArchPlay();
                        }
                    }

                    TeachingBuildingOne.isClicked = false;
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            characterControll.MoveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            characterControll.MoveDown();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            characterControll.MoveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            characterControll.MoveRight();
        }
       
        // 获取鼠标位置
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        window.clear();

        characterControll.Update();
        characterControll.Draw(window);

        cat.Trigger(characterControll.character_x, characterControll.character_y, window);
        sf::RectangleShape tmp;
        tmp.setSize(sf::Vector2f(10, 10));
        tmp.setPosition(500, 500);
        tmp.setFillColor(sf::Color::Red);
        window.draw(tmp);

        returnHomeButton.SetHovered(returnHomeButton.CheckHover(mousePosF));
        returnHomeButton.DrawButton(window);
        TeachingBuildingOne.SetHovered(TeachingBuildingOne.CheckHover(mousePosF));
        TeachingBuildingOne.DrawButton(window, "1694597194197.jpg");
        Dormitory.SetHovered(Dormitory.CheckHover(mousePosF));
        Dormitory.DrawButton(window, "1694597194197.jpg");
        Libarary.SetHovered(Libarary.CheckHover(mousePosF));
        Libarary.DrawButton(window, "LibraryText.jpg");

        window.display();
    }


    return 0;
}