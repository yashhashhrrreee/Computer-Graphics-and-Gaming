#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function to perform rotation about an arbitrary point recursively
void rotateRecursive(int* x, int* y, int pivotX, int pivotY, float angle) {
    // Base case: if the point is the pivot point, return
    if (*x == pivotX && *y == pivotY) {
        return;
    }

    // Translate the point relative to the pivot point
    int translatedX = *x - pivotX;
    int translatedY = *y - pivotY;

    // Perform rotation using the rotation matrix
    float radianAngle = angle * M_PI / 180.0;
    int rotatedX = round(translatedX * cos(radianAngle) - translatedY * sin(radianAngle));
    int rotatedY = round(translatedX * sin(radianAngle) + translatedY * cos(radianAngle));

    // Translate the point back to its original position
    *x = rotatedX + pivotX;
    *y = rotatedY + pivotY;

    // Recursively rotate the point
    rotateRecursive(x, y, pivotX, pivotY, angle);
}

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    // Coordinates of the point and the pivot point
    int x, y, pivotX, pivotY;

    // Rotation angle in degrees
    float angle;

    // Read the coordinates of the point from the user
    printf("Enter the coordinates of the point (x, y): ");
    scanf("%d%d", &x, &y);

    // Read the coordinates of the pivot point from the user
    printf("Enter the coordinates of the pivot point (pivotX, pivotY): ");
    scanf("%d%d", &pivotX, &pivotY);

    // Read the rotation angle from the user
    printf("Enter the rotation angle in degrees: ");
    scanf("%f", &angle);

    // Draw the original point
    putpixel(x, y, WHITE);

    // Perform rotation recursively
    rotateRecursive(&x, &y, pivotX, pivotY, angle);

    // Draw the rotated point
    putpixel(x, y, RED);

    delay(2000);

    closegraph();

    return 0;
}
