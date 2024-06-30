#ifndef EXITBUTTON_H
#define EXITBUTTON_H

#include "Button.h"

class ExitButton : public Button {
public:
    static float ExitButtonWidth, ExitButtonHeight;

    ExitButton(float x, float y);

    void DrawButton(sf::RenderWindow& window);

    void ExitProgram(sf::RenderWindow& window);

private:
    bool isClicked;  // 按钮是否被点击
};

#endif