#include <stdio.h>
#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to reflect a point about the origin
void reflectOrigin(int* x, int* y) {
    *x = -(*x);
    *y = -(*y);
}

// Function to reflect a point about the line Y = X
void reflectYEqualsX(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    // Coordinates of the triangle
    int x1, y1, x2, y2, x3, y3;

    // Read the coordinates of the triangle from the user
    printf("Enter the coordinates of the triangle (x1, y1, x2, y2, x3, y3): ");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);
    delay(2000);
    cleardevice();

    // Reflect the triangle about the origin
    int ox1 = x1, oy1 = y1;
    int ox2 = x2, oy2 = y2;
    int ox3 = x3, oy3 = y3;
    reflectOrigin(&ox1, &oy1);
    reflectOrigin(&ox2, &oy2);
    reflectOrigin(&ox3, &oy3);
    drawTriangle(ox1, oy1, ox2, oy2, ox3, oy3);
    delay(2000);
    cleardevice();

    // Reflect the triangle about the line Y = X
    int rx1 = x1, ry1 = y1;
    int rx2 = x2, ry2 = y2;
    int rx3 = x3, ry3 = y3;
    reflectYEqualsX(&rx1, &ry1);
    reflectYEqualsX(&rx2, &ry2);
    reflectYEqualsX(&rx3, &ry3);
    drawTriangle(rx1, ry1, rx2, ry2, rx3, ry3);
    delay(2000);
    cleardevice();

    closegraph();

    return 0;
}
