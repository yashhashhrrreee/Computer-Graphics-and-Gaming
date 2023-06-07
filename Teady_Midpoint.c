#include <stdio.h>
#include <graphics.h>

void midPointCircleDraw(int x,int y,int r)
{
    int x1,y1;
    float dp; //initial decision parameter
    x1=0; //initial x,y coordinates
    y1=r;
    dp=1-r; 
    while(x1<=y1)
    {
        putpixel(x+x1,y+y1,GREEN);
        putpixel(x-x1,y+y1,GREEN);
        putpixel(x+x1,y-y1,GREEN);
        putpixel(x-x1,y-y1,GREEN);
        putpixel(x+y1,y+x1,GREEN);
        putpixel(x-y1,y+x1,GREEN);
        putpixel(x+y1,y-x1,GREEN);
        putpixel(x-y1,y-x1,GREEN);
        if(dp<=0)
        {
            x1++;
            dp=dp+(2*x1)+3;
        }
        else
        {
            x1++;
            y1--;
            dp=dp+2*(x1-y1)+5;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int headX,headY,leftEyeX,leftEyeY,eyeRadius,rightEyeX,rightEyeY,noseX.noseY,noseRadius;
    int mouthStartX, mouthStartY, mouthEndX, mouthEndY;
    // Draw head
    headX = 200;
    headY = 200;
    headRadius = 100;
    MidPointCircle(headX, headY, headRadius);

    // Draw eyes
    leftEyeX = headX - 40;
    leftEyeY = headY - 40;
    eyeRadius = 15;
    MidPointCircle(leftEyeX, leftEyeY, eyeRadius);

    rightEyeX = headX + 40;
    rightEyeY = headY - 40;
    MidPointCircle(rightEyeX, rightEyeY, eyeRadius);

    // Draw nose
    noseX = headX;
    noseY = headY + 20;
    noseRadius = 10;
    MidPointCircle(noseX, noseY, noseRadius);

    // Draw mouth
    mouthStartX = headX - 30;
    mouthStartY = headY + 50;
    mouthEndX = headX + 30;
    mouthEndY = headY + 50;
    line(mouthStartX, mouthStartY, mouthEndX, mouthEndY);

    getch();
    closegraph();
    return 0;
}