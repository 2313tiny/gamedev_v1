#include "tech.hpp"

//object is putting at x.y point
Tank::Tank(Display * &dis, Window & wind,
  	    XEvent & event, GC &gc, 
    	    int &x, int &y)
{
	colormap = DefaultColormap(dis,0);	
	XParseColor(dis, colormap, green_bits, &green_col);
	XAllocColor(dis, colormap, &green_col);

	   // tank silhouette
	    XSetForeground(dis, gc, green_col.pixel);
	    XDrawLine(dis, wind, gc, 
			x + 20, y, x, y+20);
	    XDrawLine(dis, wind, gc, 
			x, y+20, x+20, y+40);
	    XDrawLine(dis, wind, gc, 
			x + 20, y+40, x+40, y+20);
	    XDrawLine(dis, wind, gc, 
			x+40, y+20, x+20, y);
}
	
