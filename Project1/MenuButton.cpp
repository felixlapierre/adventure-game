#include "MenuButton.h"

MenuButton::MenuButton(float centerX, float centerY, float width, float height)
	: area(centerX - width / 2, centerY - height / 2,
		width, height)
{

}

bool MenuButton::Contains(float x, float y)
{
	return area.contains(x,y);
}
