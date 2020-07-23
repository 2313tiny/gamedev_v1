#ifndef TANK_HPP
#define TANK_HPP

#include<X11/Xlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>


class Tank{
public:
	Tank(Display * &dis, Window & wind,
	     XEvent & event, GC & gc, 
	     int &x, int &y); //object is putting at x.y point 
	~Tank(){}	
private:
	Colormap colormap;
	XColor green_col;
	const char green_bits[8] = "00FF00";

};



#endif //TANK_HPP
