#include <stdio.h>
#include <graphics.h>

void display(int x1,int y1, int x,int y)
{
    putpixel(x+x1,y+y1,WHITE);
    putpixel(x-x1,y+y1,WHITE);
    putpixel(x+x1,y-y1,WHITE);
    putpixel(x-x1,y-y1,WHITE);
    putpixel(x+y1,y+x1,WHITE);
    putpixel(x-y1,y+x1,WHITE);
    putpixel(x+y1,y-x1,WHITE);
    putpixel(x-y1,y-x1,WHITE);
}

void midPointCircleDraw(int x,int y,int r)
{
    int x1,y1;
    float dp; //initial decision parameter
    x1=0; //initial x,y coordinates
    y1=r;
    dp=1-r; 
    while(x1<=y1)
    {
        if(dp<=0)
        {
            x1++;
            dp=dp+(2*x1)+3;
        }
        else
        {
            x1++;
            y1--;
            dp=dp+2*(x1-y1)+5;
        }
        display(x1,y1,x,y);
    }
}
void bresenhamCircleDraw(int x,int y,int r)
{
    int x1,y1;
    float dp; //initial decision parameter
    x1=0; //initial x,y coordinates
    y1=r;
    dp=3-2*r; 
    while(x1<=y1)
    {
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
        display(x1,y1,x,y);
    }
}


int main()
{
    int choice, x, y, r;

    // initialize graphics
    int gd = DETECT, gm;
    do 
    {
        printf("\n1. Mid-Point Circle Drawing Algorithm");
        printf("\n2. Bresenham Circle Drawing Algorithm");
        printf("\n3. Draw Object Using Mid-Point Algorithm");
        printf("\n4. Draw Object Using Bresenham Algorithm");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
                printf("\nEnter center coordinates (x, y): ");
                scanf("%d %d", &x, &y);
                printf("\nEnter radius: ");
                scanf("%d", &r);
                midPointCircleDraw(x, y, r);
                getch();
                closegraph();
                break;
            case 2:
                initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
                printf("\nEnter center coordinates (x, y): ");
                scanf("%d %d", &x, &y);
                printf("\nEnter radius: ");
                scanf("%d", &r);
                bresenhamCircleDraw(x, y, r);
                getch();
                closegraph();
                break;
            case 3:
                initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
                midPointCircleDraw(100, 100, 50);
                midPointCircleDraw(150, 100, 50);
                midPointCircleDraw(125, 150, 50);
                getch();
                closegraph();
                break;
            case 4:
                initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");
		bresenhamCircleDraw(300, 200, 100);
		bresenhamCircleDraw(350, 200, 100);
		bresenhamCircleDraw(325, 250, 100);
                getch();
                closegraph();
                break;
            case 5:
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while (choice != 5);

    // close graphics
    closegraph();
    return 0;
}


