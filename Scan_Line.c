#include <stdio.h>
#include <graphics.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps, k;
    float xIncrement, yIncrement;
    float x = x1, y = y1;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = dx / (float) steps;
    yIncrement = dy / (float) steps;

    putpixel(round(x), round(y), WHITE);

    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(round(x), round(y), WHITE);
    }
}

void scanLineFill(int x[], int y[], int n) {
    int i, j, k;
    int ymin = getmaxy(), ymax = 0;

    // Find minimum and maximum y-coordinates
    for (i = 0; i < n; i++) {
        if (y[i] < ymin)
            ymin = y[i];
        if (y[i] > ymax)
            ymax = y[i];
    }

    // Scan each horizontal line
    for (i = ymin; i <= ymax; i++) {
        int intersectX[100], count = 0;

        // Find intersections with each edge
        for (j = 0; j < n; j++) {
            int next = (j + 1) % n;

            if ((y[j] <= i && y[next] > i) || (y[j] > i && y[next] <= i)) {
                float slope = (float)(x[next] - x[j]) / (y[next] - y[j]);
                intersectX[count++] = round(x[j] + slope * (i - y[j]));
            }
        }

        // Sort intersection points in ascending order
        for (j = 0; j < count - 1; j++) {
            for (k = 0; k < count - j - 1; k++) {
                if (intersectX[k] > intersectX[k + 1]) {
                    int temp = intersectX[k];
                    intersectX[k] = intersectX[k + 1];
                    intersectX[k + 1] = temp;
                }
            }
        }

        // Fill the scanline
        for (j = 0; j < count - 1; j += 2) {
            drawLineDDA(intersectX[j], i, intersectX[j + 1], i);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    int n, i;

    printf("Enter the number of sides of the concave polygon: ");
    scanf("%d", &n);

    int x[n], y[n];

    printf("Enter the coordinates of the polygon vertices:\n");
    for (i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }

    initgraph(&gd, &gm, "");

    scanLineFill(x, y, n);

    delay(5000);
    closegraph();

    return 0;
}
