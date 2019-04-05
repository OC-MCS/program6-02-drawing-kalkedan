#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
struct set
{
	unsigned color;
	Vector2f position;
	ShapeEnum shape;
};
class DrawingShape 
{
public:
	virtual void draw(RenderWindow& win) =0;
	virtual set getFileRecord() const =0;

};

// add Circle, Square classes below. These are derived from DrawingShape
class Circle:public DrawingShape
{
private:
	CircleShape circle;
public:
	Circle(Vector2f p, Color c)
	{

		circle.setPosition(p);
		circle.setRadius(4);
		circle.setOutlineThickness(2);
		circle.setOutlineColor(c);
	
	}
	void draw(RenderWindow &win)
	{
		win.draw(circle);
	}
	set getFileRecord() const
	{
		set set1;
		set1.color = (circle.getOutlineColor()).toInteger();
		
		set1.position = circle.getPosition();
		set1.shape = ShapeEnum::CIRCLE;

		return set1;
	}
	

};
class Square :public DrawingShape
{
private :
	RectangleShape drawingSquare;
public:
	Square(Vector2f pos, Color col)
	{
		drawingSquare.setPosition(pos);
		drawingSquare.setSize(Vector2f(20,20));
		drawingSquare.setOutlineColor(col);
		drawingSquare.setOutlineThickness(4);
		
	}
	
	set getFileRecord() const
	{
		set set2;
		set2.color =( drawingSquare.getOutlineColor()).toInteger();
		set2.position = drawingSquare.getPosition();
		set2.shape = ShapeEnum::SQUARE;

		return set2;
	}
	void draw(RenderWindow &win)
	{
		win.draw(drawingSquare);
	}
};


