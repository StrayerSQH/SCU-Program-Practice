#include "Button.h"
#include "SexChooseSystem.h"
#include <iostream>
#include "MusicClickDetail.h"
#include "WindowsShow.h"

//定义SexChooseButton属性
float SexChooseButton::SexChooseButtonWidth = 200;
float SexChooseButton::SexChooseButtonHeight = 500;

SexChooseButton::SexChooseButton(float x, float y, std::string path, std::string sex) : Button(x, y, SexChooseButtonWidth, SexChooseButtonHeight, sex, 128)
{
	SexChooseButton::SexChooseFilePath = path;
	SexChooseButtonPitureSet(x, y);
};

int SexChooseButton::SexChooseButtonPitureSet(float x, float y)
{
	if (!SexChooseButton::sexTexture.loadFromFile(SexChooseFilePath))
	{
		cout << "性别选择图像加载失败" << endl;
	}

	sexSprite.setTexture(sexTexture);  
	sexSprite.setPosition(x, y);  

	// 设置箭头图片的大小
	sexSprite.setScale(
		SexChooseButtonWidth / sexSprite.getLocalBounds().width,
		SexChooseButtonHeight / sexSprite.getLocalBounds().height
	);

	return 1;
}
void SexChooseButton::DrawButton(sf::RenderWindow& window)
{
	window.draw(sexSprite);
}

//定义SexChooseSystem属性
int SexChooseSystem::SexChooseProgram(sf::RenderWindow& window)
{

	SexChooseButton Boy(
		window.getSize().x / 4 - SexChooseButton::SexChooseButtonWidth / 2,
		window.getSize().y / 2 - SexChooseButton::SexChooseButtonHeight / 2,
		"1694597194197.jpg",
		"BOY"
	);
	SexChooseButton Girl(
		3 * window.getSize().x / 4 - SexChooseButton::SexChooseButtonWidth / 2,
		window.getSize().y / 2 - SexChooseButton::SexChooseButtonHeight / 2,
		"1694597194197.jpg",
		"GIRL"
	);

	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (Event.type == sf::Event::MouseButtonPressed)
			{
				if (Event.mouseButton.button == sf::Mouse::Left)
				{
					if (Boy.CheckHover(window.mapPixelToCoords(sf::Vector2i(Event.mouseButton.x, Event.mouseButton.y))))
					{
						Arch boyMusic("ArchClickMusic.mp3");
						if (boyMusic.ArchLoadMusic())
						{
							boyMusic.ArchPlay();
						}

						return SexChooseSystem::SexChooseResult;
					}
				}
			}

			if (Event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (Event.type == sf::Event::MouseButtonPressed)
			{
				if (Event.mouseButton.button == sf::Mouse::Left)
				{
					if (Girl.CheckHover(window.mapPixelToCoords(sf::Vector2i(Event.mouseButton.x, Event.mouseButton.y))))
					{
						SexChooseSystem::SexChooseResult = 0;

						Arch girlMusic("ArchClickMusic.mp3");
						if (girlMusic.ArchLoadMusic())
						{
							girlMusic.ArchPlay();
						}

						return SexChooseSystem::SexChooseResult;
					}
				}
			}
		}

		window.clear();
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		Boy.SetHovered(Boy.CheckHover(mousePosF));
		Girl.SetHovered(Girl.CheckHover(mousePosF));
		
		Boy.DrawButton(window);
		Girl.DrawButton(window);
		/*Boy.Button::DrawButton(window);
		Girl.Button::DrawButton(window);*/

		window.display();
	}
}



