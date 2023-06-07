#include <graphics.h>
#include <stdlib.h>

void bresenham(int x1, int y1, int x2, int y2)
{
    int g, xnew, ynew, dx, dy, temp;
    if (x1 > x2 && y1 > y2)
    {
        temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }
    dx = x2 - x1;
    dy = y2 - y1;
    if (dx < 0)
    {
        dx = dx * (-1);
    }
    if (dy < 0)
    {
        dy = dy * (-1);
    }
    g = (2) * dy - dx;
    if (dx == 0)
    {
        g = -g;
    }
    if (dx >= dy)
    {
        xnew = x1;
        ynew = y1;
        do
        {
            if (x1 > x2)
            {
                if (g < 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew - 1;
                    ynew = ynew;
                    g = g + (2) * dy;
                }
                else if (g >= 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew - 1;
                    ynew = ynew + 1;
                    g = g + (2) * dy - (2) * dx;
                }
            }
            else if (y1 > y2)
            {
                if (g < 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew + 1;
                    ynew = ynew;
                    g = g + (2) * dy;
                }
                else if (g >= 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew + 1;
                    ynew = ynew - 1;
                    g = g + (2) * dy - (2) * dx;
                }
            }
            else
            {
                if (g < 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew + 1;
                    ynew = ynew;
                    g = g + (2) * dy;
                }
                else if (g >= 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew + 1;
                    ynew = ynew + 1;
                    g = g + (2) * dy - (2) * dx;
                }
            }
        } while (xnew != x2);
    }
    else
    {
        xnew = x1;
        ynew = y1;
        do
        {
            if (x1 > x2)
            {
                if (g < 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew;
                    ynew = ynew + 1;
                    g = g + (2) * dx;
                }
                else if (g >= 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew - 1;
                    ynew = ynew + 1;
                    g = g + (2) * dx - (2) * dy;
                }
            }
            else if (y1 > y2)
            {
                if (g < 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew;
                    ynew = ynew - 1;
                    g = g + (2) * dx;
                }
                else if (g >= 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew + 1;
                    ynew = ynew - 1;
                    g = g + (2) * dx - (2) * dy;
                }
            }
            else
            {
                if (g < 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew;
                    ynew = ynew + 1;
                    g = g + (2) * dx;
                }
                else if (g >= 0)
                {
                    putpixel(xnew, ynew, YELLOW);
                    xnew = xnew + 1;
                    ynew = ynew + 1;
                    g = g + (2) * dx - (2) * dy;
                }
            }
        } while (ynew != y2);
    }
}

int main()
{
   int gd = DETECT, gm;
   //init graphics
   initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
   setcolor(WHITE);
   circle(80,200,20);
   circle(160,200,20);
   setcolor(LIGHTBLUE);
   bresenham(20,200,60,200);
   bresenham(100,200,140,200);
   bresenham(180,200,220,200);
   bresenham(20,200,20,160);
   bresenham(220,200,220,160);
   bresenham(20,160,60,160);
   bresenham(180,160,220,160);
   setcolor(BLUE);
   rectangle(60,120,180,160);
   setcolor(LIGHTBLUE);
   line(120,120,120,200);
 //  rectangle();
   getch();
   closegraph();
   return 0;
}
