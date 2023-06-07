#include <stdio.h>
#include <graphics.h>

// Function to perform X shear transformation
void xShear(int* x, int* y, int shearFactor) {
    *x = *x + shearFactor * (*y);
}

// Function to perform Y shear transformation
void yShear(int* x, int* y, int shearFactor) {
    *y = *y + shearFactor * (*x);
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    // Coordinates of the original shape
    int x1, y1, x2, y2, x3, y3;

    // Shear factor
    int shearFactor;

    // Read the coordinates of the shape from the user
    printf("Enter the coordinates of the shape (x1, y1, x2, y2, x3, y3): ");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Read the shear factor from the user
    printf("Enter the shear factor: ");
    scanf("%d", &shearFactor);

    // Draw the original shape
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    delay(2000);
    cleardevice();

    // Apply X shear transformation
    int newX1 = x1, newY1 = y1;
    int newX2 = x2, newY2 = y2;
    int newX3 = x3, newY3 = y3;
    xShear(&newX1, &newY1, shearFactor);
    xShear(&newX2, &newY2, shearFactor);
    xShear(&newX3, &newY3, shearFactor);

    // Draw the transformed shape after X shear
    line(newX1, newY1, newX2, newY2);
    line(newX2, newY2, newX3, newY3);
    line(newX3, newY3, newX1, newY1);
    delay(2000);
    cleardevice();

    // Apply Y shear transformation
    int finalX1 = newX1, finalY1 = newY1;
    int finalX2 = newX2, finalY2 = newY2;
    int finalX3 = newX3, finalY3 = newY3;
    yShear(&finalX1, &finalY1, shearFactor);
    yShear(&finalX2, &finalY2, shearFactor);
    yShear(&finalX3, &finalY3, shearFactor);

    // Draw the transformed shape after Y shear
    line(finalX1, finalY1, finalX2, finalY2);
    line(finalX2, finalY2, finalX3, finalY3);
    line(finalX3, finalY3, finalX1, finalY1);
    delay(2000);

    closegraph();

    return 0;
}
