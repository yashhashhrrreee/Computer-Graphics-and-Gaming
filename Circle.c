#include <stdio.h>
#include <graphics.h>

void midPointCircleDraw(int x0, int y0, int radius)
{
    int x = radius, y = 0;
    int decisionOver2 = 1 - x;

    while (y <= x)
    {
        putpixel(x0 + x, y0 + y, WHITE);
        putpixel(x0 + y, y0 + x, WHITE);
        putpixel(x0 - y, y0 + x, WHITE);
        putpixel(x0 - x, y0 + y, WHITE);
        putpixel(x0 - x, y0 - y, WHITE);
        putpixel(x0 - y, y0 - x, WHITE);
        putpixel(x0 + y, y0 - x, WHITE);
        putpixel(x0 + x, y0 - y, WHITE);
        y++;

        if (decisionOver2 <= 0)
        {
            decisionOver2 += 2 * y + 1;
        }
        else
        {
            x--;
            decisionOver2 += 2 * (y - x) + 1;
        }
    }
}

void bresenhamCircleDraw(int x0, int y0, int radius)
{
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        putpixel(x0 + x, y0 + y, WHITE);
        putpixel(x0 + y, y0 + x, WHITE);
        putpixel(x0 - y, y0 + x, WHITE);
        putpixel(x0 - x, y0 + y, WHITE);
        putpixel(x0 - x, y0 - y, WHITE);
        putpixel(x0 - y, y0 - x, WHITE);
        putpixel(x0 + y, y0 - x, WHITE);
        putpixel(x0 + x, y0 - y, WHITE);

    if (d <= 0)
    {
        d = d + 4 * x + 6;
    }
    else
    {
        d = d + 4 * (x - y) + 10;
        y--;
    }

    x++;
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
                initgraph(&gd, &gm,NULL);
                printf("\nEnter center coordinates (x, y): ");
                scanf("%d %d", &x, &y);
                printf("\nEnter radius: ");
                scanf("%d", &r);
                midPointCircleDraw(x, y, r);
                getch();
                closegraph();
                break;
            case 2:
                initgraph(&gd, &gm,NULL);
                printf("\nEnter center coordinates (x, y): ");
                scanf("%d %d", &x, &y);
                printf("\nEnter radius: ");
                scanf("%d", &r);
                bresenhamCircleDraw(x, y, r);
                getch();
                closegraph();
                break;
            case 3:
                initgraph(&gd, &gm,NULL);
                midPointCircleDraw(100, 100, 50);
                midPointCircleDraw(150, 100, 50);
                midPointCircleDraw(125, 150, 50);
                getch();
                closegraph();
                break;
            case 4:
                initgraph(&gd, &gm,NULL);
                bresenhamCircleDraw(100, 100, 50);
                bresenhamCircleDraw(150, 100, 50);
                bresenhamCircleDraw(125, 150, 50);
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


