#include <iostream>
using namespace std;
#include "RGB.h"

RGB::RGB(int red, int green, int blue){
	if (red > 255 or red < 0){
		r = 0;
	}else{
		r = red;
	}
	
	if (green > 255 or green < 0){
		g = 0;
	}else{
		g = green;
	}
	
	if (blue > 255 or blue < 0){
		b = 0;
	}else{
		b = blue;
	}
}


RGB::RGB(CuColour colour){
	b = colour & 0xFF;
	g = (colour >>8) & 0xFF;
	r = (colour >> 16) & 0xFF;
}

RGB::RGB(){
	r = 0;
	b = 0;
	g = 0;
}
		
int RGB::getR() const{
	return r;
}

int RGB::getB() const{
	return b;
}
	
int RGB::getG() const{
	return g;
}
	

CuColour RGB::getColour() const{
	CuColour colour = r<<8;
	colour = (colour | g)<<8;
	colour = (colour | b);
	//CuColour colour = (r<<16) | g<<8 | b;
	return colour;
}


		
void RGB::setR(int red){
	r = red;
}

void RGB::setB(int blue){
	b = blue;
}

void RGB::setG(int green){
	g = green;
}

void RGB::setColour(CuColour colour){
	b = colour & 0xFF;
	g = (colour >>8) & 0xFF;
	r = (colour >> 16) & 0xFF;
}

//additional function to check
void RGB::print() const{
	cout<<"red : "<<r<<endl;
	cout<<"blue : "<<b<<endl;
	cout<<"green : "<<g<<endl;
}

RGB RGB::WHITE(){
    return RGB(255,255,255);
}
RGB RGB::BLACK(){
    return RGB(0,0,0);
}
RGB RGB::RED(){
    return RGB(255,0,0);
}
RGB RGB::GREEN(){
    return RGB(0,255,0);
}
RGB RGB::BLUE(){
    return RGB(0,0,255);
}