#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "defs.h"
#include "RGB.h"
#include <string>
#include <X11/Xlib.h>

using namespace std;

class TextArea{
	public:
		TextArea(int x,int y,int width,int height,const string& id,const string& label,RGB fill = RGB::WHITE(),RGB border = RGB::BLACK());
		TextArea(Rectangle dim,const string& id,const string& label,RGB fill = RGB::WHITE(),RGB border = RGB::BLACK());

		//TextArea(int,int,int,int,string,CuColour,CuColour);
		TextArea();
        TextArea(const TextArea&);

		//int getX();
		//int getY();
		//int getWidth();
		//int getHeight();
		string getText() const;
        string getId() const;
		
        void setFill(RGB clr);
        void setBorder(RGB clr);
		void draw(Display*, Window, GC, int, int);
		bool overlaps(const TextArea& ta) const;
		void print() const;
		bool equals(const TextArea& ta) const;

	private:
		//int x;
		//int y;
		//int width;
		//int height;
        Rectangle dimensions;
		string text;
        string id;
		RGB fill;
		RGB border;
};

#endif