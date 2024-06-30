#include "Button.h"
#include "ChooseStateButton.h"

float ChooseStateButton::ChooseButtonWidth = 700;
float ChooseStateButton::ChooseButtonHeight = 300;

ChooseStateButton::ChooseStateButton(float x, float y) : Button(x, y, ChooseButtonWidth, ChooseButtonHeight, "", 128) {};

void ChooseStateButton::DrawButton(sf::RenderWindow& window)
{
	Button::DrawButton(window);
}