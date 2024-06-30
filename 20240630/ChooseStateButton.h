#ifndef CHOOSESTATEBUTTON_H
#define CHOOSESTATEBUTTON_H

#include "Button.h"

class ChooseStateButton : public Button {
public:
	static float ChooseButtonWidth, ChooseButtonHeight;

	ChooseStateButton(float x, float y);

	void DrawButton(sf::RenderWindow& window);
};

#endif