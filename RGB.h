#ifndef RGB_H
#define RGB_H
#include "defs.h"

class RGB{
	public:
		//constructors
		RGB(int, int, int);
		RGB(CuColour);
		RGB();
		
		//getter functions
		int getR() const;
		int getB() const;
		int getG() const;
		CuColour getColour() const;
		
		//setter functions
		void setR(int);
		void setB(int);
		void setG(int);
		void setColour(CuColour);
		
		void print() const;

        //static functions
        static RGB WHITE();
        static RGB BLACK();
        static RGB RED();
        static RGB GREEN();
        static RGB BLUE();
		
		
	private:
		int r;
		int g;
		int b;
};

#endif
