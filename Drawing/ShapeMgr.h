#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.
//struct shape1
//{
//	unsigned color;
//	ShapeEnum shape;
//	Vector2f  position;
//};

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
		
		set set1;

		for (int i = 0; i < (shapes.size()); i++)
		{
			set1 = shapes[i]->getFileRecord();
			
		inputfile.write(reinterpret_cast<char*>(&set1), sizeof(set1));
		
		}
		
	}
	void ReadShapes(fstream &inputfile)
	{
		set set2;
		
		while (inputfile.read(reinterpret_cast<char*>(&(set2)), sizeof(set2)))
		{
			Color acolor(set2.color);

			addShape(set2.position, set2.shape, acolor);
		
			inputfile.read(reinterpret_cast<char*>(&set2), sizeof(set2));
		}
	}
	

};
