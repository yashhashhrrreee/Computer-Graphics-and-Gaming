#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
void bresen(int x1, int y1, int x2, int y2);
void DDA(int x1, int y1, int x2, int y2);
int sign(float arg);


void DDA(int x1, int y1, int x2, int y2)
{
    int i, dx, dy, steps;
    float x,y;
    float xinc, yinc;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx)>= abs(dy))
	steps = dx;
    else
	steps= dy;

    xinc = (float) dx/steps;
    yinc=(float) dy/steps;
    x = x1;
    y=y1;
    putpixel (x,y,WHITE);

    for (i=1;i<steps;i++)
	{
	    x = x + xinc;
	    y = y + yinc;

	    x1 = x + 0.5;
	    y1 = y + 0.5;
	    putpixel (x1,y1,WHITE);

    }
}

// Function to draw a line using Bresenham's algorithm
void Bresen(int x1, int y1, int x2, int y2)
{
    int s1,s2,exchange,y,x,i;
    float dx,dy,g,temp;
    dx= abs (x2-x1);
    dy= abs(y2-y1);
    x =x1 ;
    y = y1 ;
    s1= sign (x2-x1);
	s2= sign (y2-y1);

    if(dy > dx)
    {
		temp = dx;
		dx = dy ;
		dy = temp ;
		exchange = 1;
    }

    else
		exchange = 0;
		g= 2 * dy - dx;
		i=1;

    while ( i <= dx)
    {
		putpixel(x,y,WHITE);
		delay(10);
	while(g >= 0)
	{
	    if(exchange ==1)
		x=x+s1;
	    else
		y=y+s2;
		g=g+2*dy-2*dx;
	}
	if(exchange==1)
	    y= y+s2;
	else
	    x=x+s1;
	    g=g+2*dy;
	    i++;

    }
}

	void Object_Drawing() 
{
    DDA(100, 100, 200, 100);
    DDA(100, 100, 100, 200);
    DDA(100, 200, 200, 200);
    DDA(200, 100, 200, 200);

    Bresen(300, 100, 400, 100);
    Bresen(300, 100, 300, 200);
    Bresen(300, 200, 400, 200);
    Bresen(400, 100, 400, 200);
}
	
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");

    int choice, x1, y1, x2, y2;

    while(1){
	cout << "1. Draw a line using DDA algorithm" << endl;
	cout << "2. Draw a line using Bresenham's algorithm" << endl;
	cout << "3. Draw an object" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> choice;

	switch (choice) {
	    case 1:
		cout << "Enter the coordinates of the starting point: ";
		cin >> x1 >> y1;
		cout << "Enter the coordinates of the ending point: ";
		cin >> x2 >> y2;
		DDA(x1, y1, x2, y2);
		break;
	    case 2:
		cout << "Enter the coordinates of the starting point: ";
		cin >> x1 >> y1;
		cout << "Enter the coordinates of the ending point: ";
		cin >> x2 >> y2;
		Bresen(x1, y1, x2, y2);
		break;
	    case 3:
		Object_Drawing();
		break;
	    case 4:
		closegraph();
		return 0;
	    default:
		cout << "Invalid choice!" << endl;
	}
    }
}
