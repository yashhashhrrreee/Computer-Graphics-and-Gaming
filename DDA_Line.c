#include <graphics.h>
#include <stdlib.h>

void DDA_Line(int x1, int y1, int x2, int y2)
{
    int dx, dy, xn, yn, c;
    float ynew, xnew;
    float m;
    dx = x2 - x1;
    dy = y2 - y1;
    m = (float)dy / dx;
    xnew = x1;
    ynew = y1;
    xn = x1;
    yn = y1;
    if (abs(dx) >= abs(dy))
    {
        do
        {
            putpixel(xn, yn, GREEN);
            if (x1 > x2)
            {
                xnew = xnew - 1;
                c = xnew;
                xn = c;
            }
            else
            {
                xnew = xnew + 1;
                c = xnew;
                xn = c;
            }
            if (y1 > y2)
            {
                ynew = ynew - m;
                c = ynew + 0.5;
                yn = c;
            }
            else
            {
                ynew = ynew + m;
                c = ynew + 0.5;
                yn = c;
            }
        } while (xnew != x2);
    }
    else
    {
        do
        {
            if (x1 > x2)
            {
                xnew = xnew - (1 / m);
                c = xnew + 0.5;
                xn = c;
            }
            else
            {
                xnew = xnew + (1 / m);
                c = xnew + 0.5;
                xn = c;
            }
            if (y1 > y2)
            {
                ynew = ynew - 1;
                yn = (int)ynew;
            }
            else
            {
                ynew = ynew + 1;
                yn = (int)ynew;
            }
            putpixel(xn, yn, GREEN);
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

    DDA_Line(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
