#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void scaleTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float scaleX, float scaleY)
{
    int newX1 = round(x1 * scaleX);
    int newY1 = round(y1 * scaleY);
    int newX2 = round(x2 * scaleX);
    int newY2 = round(y2 * scaleY);
    int newX3 = round(x3 * scaleX);
    int newY3 = round(y3 * scaleY);

    drawTriangle(newX1, newY1, newX2, newY2, newX3, newY3);
}

void rotateTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float angle)
{
    float radians = angle * 3.14159 / 180;
    float cosTheta = cos(radians);
    float sinTheta = sin(radians);

    int newX1 = round(x1 * cosTheta - y1 * sinTheta);
    int newY1 = round(x1 * sinTheta + y1 * cosTheta);
    int newX2 = round(x2 * cosTheta - y2 * sinTheta);
    int newY2 = round(x2 * sinTheta + y2 * cosTheta);
    int newX3 = round(x3 * cosTheta - y3 * sinTheta);
    int newY3 = round(x3 * sinTheta + y3 * cosTheta);

    drawTriangle(newX1, newY1, newX2, newY2, newX3, newY3);
}

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    float scaleX, scaleY, angle;
    int choice;

    printf("Enter the coordinates of the triangle vertices:\n");
    printf("Vertex 1: ");
    scanf("%d %d", &x1, &y1);
    printf("Vertex 2: ");
    scanf("%d %d", &x2, &y2);
    printf("Vertex 3: ");
    scanf("%d %d", &x3, &y3);

    initgraph(&gd, &gm, "");

    drawTriangle(x1, y1, x2, y2, x3, y3);

    do
    {
        printf("\n--------- Menu ---------\n");
        printf("1. Scale\n");
        printf("2. Rotate\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the scaling factors (scaleX scaleY): ");
            scanf("%f %f", &scaleX, &scaleY);
            cleardevice();
            scaleTriangle(x1, y1, x2, y2, x3, y3, scaleX, scaleY);
            break;

        case 2:
            printf("Enter the rotation angle (in degrees): ");
            scanf("%f", &angle);
            cleardevice();
            rotateTriangle(x1, y1, x2, y2, x3, y3, angle);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }

        delay(2000);
    } while (choice != 3);

    closegraph();

    return 0;
}
