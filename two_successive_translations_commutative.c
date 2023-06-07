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

    // Perform the translations in different orders
    Point result1 = point;
    translate(&result1, dx1, dy1);
    translate(&result1, dx2, dy2);

    Point result2 = point;
    translate(&result2, dx2, dy2);
    translate(&result2, dx1, dy1);

    // Check if the final points are equal
    int equal = (result1.x == result2.x) && (result1.y == result2.y);

    // Display the result
    if (equal)
        printf("Successive translations are commutative.\n");
    else
        printf("Successive translations are not commutative.\n");

    return 0;
}
