#include <iostream>
#include "TextArea.h"

using namespace std;

TextArea::TextArea(int x,int y,int width,int height,const string& text,const string& id,RGB fill,RGB border){
	//Rectangle dimesions;
    //->dimensions = Rectangle(x,y,width,height);
    dimensions.x = x;
    dimensions.y = y;
    dimensions.height = height;
    dimensions.width = width;
	this->text = text;
    this->id = id;
	this->fill = fill;
	this->border = border;
}

TextArea::TextArea(Rectangle dim,const string& text,const string& id,RGB fill,RGB border){
	//Rectangle dimesions;
    //->dimensions = Rectangle(x,y,width,height);
    dimensions = dim;
	this->text = text;
    this->id = id;
	this->fill = fill;
	this->border = border;
}

TextArea::TextArea(){
	//Rectangle dimesions;
    //->dimensions = Rectangle(x,y,width,height);
    dimensions.x = 0;
    dimensions.y = 0;
    dimensions.height = 0;
    dimensions.width = 0;
	this->text = "";
    this->id = "";
	this->fill = RGB::WHITE();
	this->border = RGB::BLACK();
}

TextArea::TextArea(const TextArea& ta){
    dimensions.x = ta.dimensions.x;
    dimensions.y = ta.dimensions.y;
    dimensions.height = ta.dimensions.height;
    dimensions.width = ta.dimensions.width;
	this->text = ta.text;
    this->id = "DUPLICATE";
	this->fill = ta.fill;
	this->border = ta.border;
}


// int Button::getX(){
// 	return x;
// }
// int Button::getY(){
// 	return y;
// }
// int Button::getWidth(){
// 	return width;
// }
// int Button::getHeight(){
// 	return height;
// }

string TextArea::getText() const{
	return text;
}
string TextArea::getId() const{
	return id;
}


void TextArea::setFill(RGB clr){
    fill = clr;
}

void TextArea::setBorder(RGB clr){
    border = clr;
}

void TextArea::draw(Display *display, Window win, GC gc, int x, int y){
	//cout<<"drawing button"<<endl;
	XSetForeground(display,gc,border.getColour());
	XDrawRectangle(display,win,gc, x,y,dimensions.width,dimensions.height);
	XFlush(display);

	XSetForeground(display,gc,fill.getColour());
	XFillRectangle(display,win,gc,x,y,dimensions.width,dimensions.height);
	XFlush(display);

	XSetForeground(display,gc,border.getColour());
	XDrawString(display,win,gc,x, y, text.c_str() ,text.length());
	XFlush(display);
}

bool TextArea::overlaps(const TextArea& ta) const{
	return dimensions.overlaps(ta.dimensions);
}

void TextArea::print() const{
	cout<<"TextArea Id:         "<<id<<endl;
	cout<<"Preferred location:  "<<dimensions.x<<", "<<dimensions.y<<endl;
	cout<<"Size:                "<<dimensions.width<<", "<<dimensions.height<<endl;
    cout<<"Text:                "<<text<<endl;
}
