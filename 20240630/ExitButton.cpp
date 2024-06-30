#include "Button.h"
#include "ExitButton.h"

float ExitButton::ExitButtonWidth = 100;
float ExitButton::ExitButtonHeight = 100;

ExitButton::ExitButton(float x, float y) : Button(x, y, ExitButtonWidth, ExitButtonWidth, "", 128) {};

void ExitButton::DrawButton(sf::RenderWindow& window)
{
	Button::DrawButton(window);
}