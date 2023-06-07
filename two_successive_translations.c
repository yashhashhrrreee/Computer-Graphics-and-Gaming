#include <stdio.h>

// Structure representing a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Function to perform translation on a point
void translate(Point* point, double dx, double dy) {
    point->x += dx;
    point->y += dy;
}

int main() {
    Point point;
    double dx1, dy1, dx2, dy2;

    // Read the initial coordinates of the point
    printf("Enter the initial x-coordinate: ");
    scanf("%lf", &point.x);
    printf("Enter the initial y-coordinate: ");
    scanf("%lf", &point.y);

    // Read the translation distances for the first translation
    printf("Enter the translation distance for the first translation:\n");
    printf("dx1: ");
    scanf("%lf", &dx1);
    printf("dy1: ");
    scanf("%lf", &dy1);

    // Read the translation distances for the second translation
    printf("Enter the translation distance for the second translation:\n");
    printf("dx2: ");
    scanf("%lf", &dx2);
    printf("dy2: ");
    scanf("%lf", &dy2);

    // Perform the translations
    translate(&point, dx1, dy1);
    translate(&point, dx2, dy2);

    // Display the final coordinates
    printf("Final coordinates: (%.2lf, %.2lf)\n", point.x, point.y);

    return 0;
}
