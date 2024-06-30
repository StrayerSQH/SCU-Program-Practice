#include "ExitButton.h"
#include <iostream>
#include "ConfirmExitButtonOne.h"

float ExitButton::ExitButtonWidth = 300;
float ExitButton::ExitButtonHeight = 150;

ExitButton::ExitButton(float x, float y) : Button(x, y, ExitButtonWidth, ExitButtonHeight, "Exit<<", 0), isClicked(false) {}

void ExitButton::DrawButton(sf::RenderWindow& window) {
    Button::DrawButton(window);

    if (isClicked) {
        ExitProgram(window);
    }
}

void ExitButton::ExitProgram(sf::RenderWindow& window) {
    exit(0);
}