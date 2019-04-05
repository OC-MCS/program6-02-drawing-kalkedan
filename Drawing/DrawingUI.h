#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	Vector2f post;
	RectangleShape drawingSquare;

public:
	DrawingUI(Vector2f p)
	{
		post = p;
	}

void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		
		drawingSquare.setPosition(250, 20);
		drawingSquare.setSize(Vector2f(800, 800));
		drawingSquare.setOutlineColor(Color::White);
		drawingSquare.setOutlineThickness(2);
		drawingSquare.setFillColor(Color::Black);
		win.draw(drawingSquare);
		int x = 0;
		vector<DrawingShape*> shape;
		shape =* mgr->getShapeVec();
		for(int x=0;x < shape.size();x++)
		{
			shape[x]->draw(win);
		}
}
	
bool isMouseInCanvas(Vector2f mousePos)
	{
		if (drawingSquare.getGlobalBounds().contains(mousePos))
			return true; // just to make it compile
		else
			return false;
	}

};

