#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color curColor;
	ShapeEnum curShape;
	
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		curColor =startingColor;
		curShape = startingShape;

	}
	void SetColor(Color col)
	{
		curColor = col;
	}
	void setShape(ShapeEnum shape)
	{
		curShape = shape;
	}
	Color getCurColor()
	{
		//return Color::Blue; // just to make it compile 
		return curColor;
	}


	ShapeEnum getCurShape()
	{
		//return ShapeEnum::CIRCLE; // just to make it compile;
		return curShape;
	}
	void readfile(fstream& file)
	{
		unsigned colorNumber;
		file.read(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber));
		file.read(reinterpret_cast<char*>(&curShape), sizeof(curShape));
		Color aColor(colorNumber);
		curColor = aColor;
	}
	void writefile(fstream &file)
	{
		unsigned colorNumber = curColor.toInteger();
		
		file.write(reinterpret_cast<char*>(&colorNumber), sizeof(colorNumber));
		file.write(reinterpret_cast<char*>(&curShape), sizeof(curShape));


	}

};
