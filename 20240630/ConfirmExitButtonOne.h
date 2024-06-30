#include "Button.h"

class ConfirmExitButtonOne : public Button {
private:
	static float ConfirmExitButtonOneWidth, ConfirmExitButtonOneHeight;
	bool isClicked;
	bool confirm;
public:
	static float ConfirmExitButtonOne_x, ConfirmExitButtonOne_y;

	ConfirmExitButtonOne(float x, float y, std::string s);

	void DrawButton(sf::RenderWindow& window);

	void ExitProgram();
};