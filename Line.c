#include <graphics.h>
#include <math.h>

// DDA Line Drawing Algorithm
void DDA_Line(int x1, int y1, int x2, int y2) 
{
    int i;
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = fmax(abs(dx), abs(dy));
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;
    float x = x1, y = y1;

    for (i = 0; i <= steps; i++) 
    {
    putpixel((int)floor(x + 0.5), (int)floor(y + 0.5), WHITE);
    x += xIncrement;
    y += yIncrement;
    
    }
}

// Bresenham Line Drawing Algorithm
void Bresenham_Line(int x1, int y1, int x2, int y2)
{
    int i;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1;
    int y = y1;
    int xIncrement = x2 > x1 ? 1 : -1;
    int yIncrement = y2 > y1 ? 1 : -1;

    if (dx > dy) 
    {
        int p = 2 * dy - dx;
        for (i = 0; i <= dx; i++) 
        {
            putpixel(x, y, WHITE);
            if (p >= 0) 
            {
                y += yIncrement;
                p += 2 * (dy - dx);
            } 
            else 
            {
                p += 2 * dy;
            }
            x += xIncrement;
        }
    } 
    else 
    {
        int p = 2 * dx - dy;
        for (int i = 0; i <= dy; i++) 
        {
            putpixel(x, y, WHITE);
            if (p >= 0) 
            {
                x += xIncrement;
                p += 2 * (dx - dy);
            } 
            else 
            {
                p += 2 * dx;
            }
            y += yIncrement;
        }
    }
}

// Object Drawing using DDA and Bresenham Line Drawing Algorithms
void Object_Drawing() 
{
    DDA_Line(100, 100, 200, 100);
    DDA_Line(100, 100, 100, 200);
    DDA_Line(100, 200, 200, 200);
    DDA_Line(200, 100, 200, 200);
    
    Bresenham_Line(300, 100, 400, 100);
    Bresenham_Line(300, 100, 300, 200);
    Bresenham_Line(300, 200, 400, 200);
    Bresenham_Line(400, 100, 400, 200);
}

int main() 
{
    // Variables to store the line coordinates
    int choice, x1, y1, x2, y2;
    int gd = DETECT, gm;
    while (1) // loop indefinitely until user enters "4"
    {
        printf("Enter your choice:\n1. DDA Line\n2. BLA Line\n3. Object\n4. Exit\n");
        scanf("%d", &choice);
        // Switch statement to handle the user's choice
        switch(choice)
        {
            case 1:
                initgraph(&gd, &gm,NULL);
		        printf("Enter the starting and ending points of line(x1 y1 x2 y2): ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                DDA_Line(x1, y1, x2, y2);
                getch();
                closegraph();
                break;

            case 2:
                initgraph(&gd, &gm,NULL);
                printf("Enter the starting and ending points of line(x1 y1 x2 y2): ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                Bresenham_Line(x1, y1, x2, y2);
                getch();
                closegraph();
                break;

            case 3:
                initgraph(&gd, &gm,NULL);
                Object_Drawing();
                getch();  
                closegraph();  
                break;

            case 4:
                return 0; // exit the program when "4" is entered

            default:
                printf("Invalid choice. Try again\n");
        }
    }
}

