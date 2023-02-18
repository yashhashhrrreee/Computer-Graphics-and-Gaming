#include<stdio.h>
#include<graphics.h>

void dda(int x1, int y1, int x2, int y2)
{
    int i, x_next, y_next;
    int dx = x2 - x1; 
    int dy = y2 - y1;
    float m;
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    m = (float)dy/dx;
    m = m + 0.5;
    m = (int)m;

    x_next = x1;
    y_next = y1;
    
    if(abs(dx) >= abs(dy))
    {
        dx = 1;
        do
        {
            putpixel(x_next, y_next, WHITE);
            x_next = x_next + 1;
            y_next = y_next + m;

        }while(x_next != x2);
    }
    else
    {
        dy = 1;
        do
        {
            putpixel(x_next, y_next, WHITE);
            x_next = x_next + 1/m;
            y_next = y_next + 1;
        }while(y_next != y2);
    }

    getch();
    closegraph();
}

void bresenham(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int i, g = 2 * dy - dx;
    int x, y, x_next, y_next, g_next;
    float m;
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    x_next = x1;
    y_next = y1;
    g_next = g;

    if(dx >= dy) //  
    {
        do
        {
            putpixel(x_next, y_next, WHITE);
            if(g_next >= 0)
            {
                x_next += 1;
                y_next += 1;
                g_next = g + (2 * dx) - (2 * dy);
            }
            else
            {
                y_next += 1;
                g_next = g + (2 * dx);
            }
        }while(y_next != y2);
    }
    else
    {
        do
        {
            putpixel(x_next,y_next, WHITE);
            if(g_next >= 0)
            {
                x_next += 1;
                y_next += 1;
                g_next = g + (2 * dy) - (2 * dx);
            }
            else
            {
                x_next += 1;
                g_next = g + (2 * dy);
            }
        }while(x_next != x2);
    }



    getch();
    closegraph();
}

void createObject(int x1, int y1, int x2, int y2)
{
//     dda(x1, y1, x2, y2);
//     bresenham(x1, y1, x2, y2);
}

void main()
{
    int choice;
    int x1, x2, y1, y2;
  

    while(1)
    {
        printf("Enter the points:\n"); 
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2); 

        printf("Enter your choice:\n1. DDA Algorithm\n2. Bresenham Line Drawing Algorithm\n3. Create any Object\n4. Exit\n : "); 
        scanf("%d", &choice); 
        
        switch (choice) 
        { 
            case 1: 
                dda(x1, y1, x2, y2); 
            break; 

            case 2: 
                bresenham(x1, y1, x2, y2); 
            break; 

            case 3: 
                createObject(x1, y1, x2, y2); 
            break; 

            case 4:
                exit(0);
            break;

            default: 
                printf("Enter a valid choice\n"); 
        } 
    }
}
