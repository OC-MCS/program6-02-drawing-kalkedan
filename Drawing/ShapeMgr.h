#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.
struct shape1
{
	unsigned color;
	ShapeEnum shape;
	Vector2f  position;
};

class ShapeMgr
{
private:
	vector<DrawingShape*> shapes;

	
public:
	
	vector<DrawingShape*>* getShapeVec()
	{
		return &shapes;
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		DrawingShape *ptr;
		if (whichShape == ShapeEnum::CIRCLE)
		{
			ptr = new Circle(pos, color);
			shapes.push_back(ptr);
		}
		else
		{
			ptr = new Square(pos, color);
			shapes.push_back(ptr);
		}

	}

	void writeShapes(fstream &inputfile)
	{
		
		shape1 set1;

		for (int i = 0; i < (shapes.size()); i++)
		{
			
			
		inputfile.write(reinterpret_cast<char*>(&set1), sizeof(set1));
		Color acolor(set1.color);
			
		addShape(set1.position, set1.shape, acolor);
		}
		
	}
	void ReadShapes(fstream &inputfile)
	{
		shape1 set;
		
		while (inputfile.read(reinterpret_cast<char*>(&(set)), sizeof(set)))
		{
			Color acolor(set.color);

			addShape(set.position, set.shape, acolor);
		
			inputfile.read(reinterpret_cast<char*>(&set), sizeof(set));
		}
	}
	

};
