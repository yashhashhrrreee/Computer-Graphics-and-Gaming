#include <stdio.h>
#include <graphics.h>

void bresenhamCircleDraw(int x,int y,int r)
{
    int x1,y1;
    float dp; //initial decision parameter
    x1=0; //initial x,y coordinates
    y1=r;
    dp=3-2*r; 
    while(x1<=y1)
    {
        putpixel(x+x1,y+y1,BLUE);
        putpixel(x-x1,y+y1,BLUE);
        putpixel(x+x1,y-y1,BLUE);
        putpixel(x-x1,y-y1,BLUE);
        putpixel(x+y1,y+x1,BLUE);
        putpixel(x-y1,y+x1,BLUE);
        putpixel(x+y1,y-x1,BLUE);
        putpixel(x-y1,y-x1,BLUE);
        if(dp<=0)
        {
            x1++;
            dp=dp+(4*x1)+6;
        }
        else
        {
            x1++;
            y1--;
            dp=dp+4*(x1-y1)+10;
        }
    }
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, radius;
    printf("Enter the center coordinates (xc, yc): ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the radius: ");
    scanf("%d", &radius);

    bresenhamCircleDraw(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}