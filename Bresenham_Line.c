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
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1, y1, x2, y2;
    printf("Enter the starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    bresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
