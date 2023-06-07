#include <stdio.h>
#include <math.h>

// Structure representing a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Function to perform rotation on a point
void rotate(Point* point, double theta) {
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);
    double x = point->x;
    double y = point->y;

    // Apply rotation transformation
    point->x = x * cos_theta - y * sin_theta;
    point->y = x * sin_theta + y * cos_theta;
}

int main() {
    Point point;
    double theta1, theta2;

    // Read the initial coordinates of the point
    printf("Enter the initial x-coordinate: ");
    scanf("%lf", &point.x);
    printf("Enter the initial y-coordinate: ");
    scanf("%lf", &point.y);

    // Read the rotation angles for the first and second rotations
    printf("Enter the rotation angle for the first rotation in radians: ");
    scanf("%lf", &theta1);
    printf("Enter the rotation angle for the second rotation in radians: ");
    scanf("%lf", &theta2);

    // Perform the rotations
    rotate(&point, theta1);
    rotate(&point, theta2);

    // Display the final coordinates
    printf("Final coordinates: (%.2lf, %.2lf)\n", point.x, point.y);

    return 0;
}
