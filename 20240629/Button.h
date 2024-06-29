#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <Windows.h>

using namespace std;

class Button {
public:
	float Width;
	float Hieght;

	Button(float window_x, float window_y, float width, float height, const std::string& text, sf::Uint8 alpha);

	virtual void DrawButton(sf::RenderWindow& window);
	

public:
	sf::RectangleShape shape;
	sf::Text label;
	sf::Font font;
};

#endif