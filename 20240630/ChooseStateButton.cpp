#include "Button.h"
#include "ChooseStateButton.h"

float ChooseStateButton::ChooseButtonWidth = 500;
float ChooseStateButton::ChooseButtonHeight = 1000;

ChooseStateButton::ChooseStateButton(float x, float y) : Button(x, y, ChooseButtonWidth, ChooseButtonHeight, "", 128) {};

void ChooseStateButton::DrawButton(sf::RenderWindow& window)
{
	Button::DrawButton(window);
}