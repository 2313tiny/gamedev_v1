
#ifndef SOURCE_HPP
#define SOURCE_HPP

#include<X11/Xlib.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#include"tech.hpp"


class Fenster{
private:
	Display * m_display;
	Window m_window;
	XEvent m_event;
	GC m_gc; // graphical context;
	int m_screen;

private:
	Colormap colormap;
	XColor yellow_col;
	XColor green_col;
	XColor red_col;
	XColor blue_col;
	const char yellow_bits[8] = "#AFAFA1"; //FFFF00
	const char green_bits[8] = "#00FF00";
	const char red_bits[8] = "#FF0000";
	const char blue_bits[8] = "#0000FF";
		
public:
	Fenster(); 
	~Fenster();
	
	Display *& setDisplay();
	Display * getDisplay();
	Window & getWindow();
	XEvent & getEvent();
};

struct axis{
	int m_a_x;
	int m_a_y;
	int m_a_z;

	axis() 
	   : m_a_x(0)
	   , m_a_y(0)
	   , m_a_z(0){}

	axis(int x, int y, int z)
	  : m_a_x(x)
	  , m_a_y(y)
	  , m_a_z(z){}
};


class CartesianAxis{
private:	
	Display * m_display;
	Window m_window;
	XEvent m_event;
	GC m_gc; // graphical context;
	int m_screen;
	axis * s_point; 
private:
	Colormap colormap;
	XColor yellow_col;
	XColor green_col;
	XColor red_col;
	XColor blue_col;
	char yellow_bits[8] = "#AFAFA1"; //FFFF00
	char green_bits[8] = "#00FF00";
	char red_bits[8] = "#FF0000";
	char blue_bits[8] = "#0000FF";
		
public:
	CartesianAxis(Display * dis, Window wind,
		      XEvent evend, GC gc, 
		      int x, int y , int z); 
	~CartesianAxis();
	
	Display *& setDisplay();
	Display * getDisplay();
	Window & getWindow();
	XEvent & getEvent();
};




#endif //SOURCE_HPP
