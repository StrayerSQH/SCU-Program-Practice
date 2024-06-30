#include <iostream>
#include "ConfirmExitButtonOne.h"

float ConfirmExitButtonOne::ConfirmExitButtonOneWidth = 700;
float ConfirmExitButtonOne::ConfirmExitButtonOneHeight = 300;
float ConfirmExitButtonOne::ConfirmExitButtonOne_x = 500;
float ConfirmExitButtonOne::ConfirmExitButtonOne_y = 500;

ConfirmExitButtonOne::ConfirmExitButtonOne(float x, float y, std::string s) : Button(x, y, ConfirmExitButtonOneWidth, ConfirmExitButtonOneHeight, s, 128) {};

void ConfirmExitButtonOne::DrawButton(sf::RenderWindow& window) {
    Button::DrawButton(window);

    if (isClicked && confirm) {
        ExitProgram();
    }
}

void ConfirmExitButtonOne::ExitProgram() {
    // ÍË³ö³ÌÐòµÄÂß¼­
    exit(0);
}