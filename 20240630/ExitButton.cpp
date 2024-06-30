#include "ExitButton.h"

float ExitButton::ExitButtonWidth = 150;
float ExitButton::ExitButtonHeight = 150;

ExitButton::ExitButton(float x, float y) : Button(x, y, ExitButtonWidth, ExitButtonHeight, "Exit", 128), isClicked(false) {}

void ExitButton::DrawButton(sf::RenderWindow& window) {
    Button::DrawButton(window);

    if (isClicked) {
        ExitProgram();
    }
}

void ExitButton::ExitProgram() {
    // ÍË³ö³ÌÐòµÄÂß¼­
    exit(0);
}