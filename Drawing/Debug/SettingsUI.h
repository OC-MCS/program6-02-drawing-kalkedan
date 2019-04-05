#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<fstream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	SettingsMgr *manager;
	CircleShape redcircle;
	CircleShape greencircle;
	CircleShape whitecircle;
	
	
	CircleShape blueBtn;

	RectangleShape squarebtn; 
	RectangleShape drawingSquare;
	
public:
	SettingsUI(SettingsMgr *mgr)
	{
		manager = mgr;
	}
	void handleMouseUp(Vector2f mouse)
	{		if (blueBtn.getGlobalBounds().contains(mouse))
		{
		manager->SetColor(Color::Blue);
		
		}
		if (redcircle.getGlobalBounds().contains(mouse))
		{
			manager->SetColor(Color::Red);
		}
		if (greencircle.getGlobalBounds().contains(mouse))
		{
			manager->SetColor(Color::Green);
		}
		if (whitecircle.getGlobalBounds().contains(mouse))
		{
			manager->setShape(ShapeEnum::CIRCLE);
		}
		if (squarebtn.getGlobalBounds().contains(mouse))
		{
			manager->setShape(ShapeEnum::SQUARE);
		}

	}

	void draw(RenderWindow& win)
	{
		Font font1;
		if (!font1.loadFromFile("C:\\windows\\Fonts\\arial.ttf"))
		{
		//	die ("couldn't load font");
		}
		Text title1("Selected Color", font1, 25);
		title1.setPosition(5, 6);
		win.draw(title1);
		Vector2f pos1(5, 80);

		blueBtn.setPosition(pos1);
		blueBtn.setRadius(10);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		if (manager->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
		}
		else
		blueBtn.setFillColor( Color::Transparent);
		win.draw(blueBtn);
		Vector2f pos2(5, 160);

		redcircle.setPosition(pos2);
		redcircle.setRadius(10);
		redcircle.setOutlineThickness(2);
		redcircle.setOutlineColor(Color::Red);
		if (manager->getCurColor() == Color::Red)
		{
			redcircle.setFillColor(Color::Red);
		}
		else
		redcircle.setFillColor(Color::Transparent);
		win.draw(redcircle);
		Vector2f pos3(5, 240);

		greencircle.setPosition(pos3);
		greencircle.setRadius(10);
		greencircle.setOutlineThickness(2);
		greencircle.setOutlineColor(Color::Green);
		if (manager->getCurColor() == Color::Green)
		{
			greencircle.setFillColor(Color::Green);
		}
		else
		greencircle.setFillColor(Color::Transparent);
		win.draw(greencircle);
		
		
		if (!font1.loadFromFile("C:\\windows\\Fonts\\arial.ttf"))
		{
			//	die ("couldn't load font");
		}
		Text title2("Selected Shape", font1, 25);
		title2.setPosition(5, 280);
		win.draw(title2);
		Vector2f pos4(5, 340);

		whitecircle.setPosition(pos4);
		whitecircle.setRadius(10);
		whitecircle.setOutlineThickness(2);
		whitecircle.setOutlineColor(Color::White);
		if (manager->getCurShape() == ShapeEnum::CIRCLE)
		{
			whitecircle.setFillColor(Color::White);
		}
		else

		whitecircle.setFillColor(Color::Transparent);
		win.draw(whitecircle);

		Vector2f position(5, 400);
		Vector2f size(20, 20);
		squarebtn.setPosition(position);
		squarebtn.setOutlineColor(Color::White);
		squarebtn.setOutlineThickness(2);
		squarebtn.setSize(size);
		if (manager->getCurShape() == ShapeEnum::SQUARE)
		{
			squarebtn.setFillColor(Color::White);
		}
		else
		squarebtn.setFillColor(Color::Transparent);
		win.draw(squarebtn);
	}
	
};
