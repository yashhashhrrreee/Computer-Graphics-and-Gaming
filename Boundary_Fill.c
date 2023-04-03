#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<queue>
#define MAX_SIDES 100
#define MAX_QUEUE 10000

struct Point
{
    int x, y;
};
struct node
{
    int x,y;
};

int is_inside(struct Point p, struct Point *vertices, int num_sides)
{
    int i, j, c = 0;
    for (i = 0, j = num_sides - 1; i < num_sides; j = i++)
    {
        if (((vertices[i].y > p.y) != (vertices[j].y > p.y)) &&
            (p.x < (vertices[j].x - vertices[i].x) * (p.y - vertices[i].y) / (float)(vertices[j].y - vertices[i].y) + vertices[i].x))
        {
            c = !c;
        }
    }
    return c;
}

void dda_line(int x1, int y1, int x2, int y2, int color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float x_increment = dx / (float)steps;
    float y_increment = dy / (float)steps;
    float x = x1, y = y1;
    int i;
    for (i = 0; i <= steps; i++)
    {
        putpixel(x, y, color);
        x += x_increment;
        y += y_increment;
    }
}

void boundary_fill(int x, int y, int fill_color, int boundary_color) {
    int current_color = getpixel(x, y);
    if (current_color == fill_color || current_color == boundary_color) {
        return;
    }
    struct node queue[MAX_QUEUE];
    int front = 0, rear = 0;
    queue[rear++] = (struct node){x, y};
    while (front < rear) {
        struct node curr = queue[front++];
        if (getpixel(curr.x, curr.y) != boundary_color && getpixel(curr.x, curr.y) != fill_color) {
            putpixel(curr.x, curr.y, fill_color);
            queue[rear++] = (struct node){curr.x+1, curr.y};
            queue[rear++] = (struct node){curr.x-1, curr.y};
            queue[rear++] = (struct node){curr.x, curr.y+1};
            queue[rear++] = (struct node){curr.x, curr.y-1};
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,NULL);
    int num_sides, i;
    printf("Number of sides: ");
    scanf("%d", &num_sides);
    struct Point vertices[MAX_SIDES];
    for (i = 0; i < num_sides; i++)
    {
        printf("Vertex %d: ", i + 1);
        scanf("%d %d", &vertices[i].x, &vertices[i].y);
    }
    vertices[num_sides] = vertices[0]; // close the polygon
    for (i = 0; i < num_sides; i++)
    {
        dda_line(vertices[i].x, vertices[i].y, vertices[i + 1].x, vertices[i + 1].y, WHITE);
    }
    int seed_x, seed_y;
    printf("Seed point: ");
    scanf("%d %d", &seed_x, &seed_y);
    if (is_inside((struct Point){seed_x, seed_y}, vertices, num_sides))
    {
        std::queue<node> q;
        q.push((node){seed_x, seed_y});
        while (!q.empty()) {
            node current_node = q.front();
            q.pop();
            int x = current_node.x;
            int y = current_node.y;
            int current_color = getpixel(x, y);
            if (current_color != YELLOW && current_color != WHITE) {
                putpixel(x, y, YELLOW);
                q.push((node){x + 1, y});
                q.push((node){x - 1, y});
                q.push((node){x, y + 1});
                q.push((node){x, y - 1});
            }
        }
    }
    else
    {
        printf("Seed point is outside the polygon\n");
    }
    getch();
    closegraph();
    return 0;
}
