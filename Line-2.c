#include <graphics.h>
#include <math.h>

// DDA Line Drawing Algorithm
void DDA_Line(int x1, int y1, int x2, int y2) 
{
  int dx,dy,m1,xd,yd;
  float m,x_next,y_next;
  dx=x2-x1;
  dy=y2-y1;
  m=abs(dy)/(float)abs(dx);
  printf("%f\n",m);

  xd=x1;
  yd=y1;
  x_next=(float)x1;
  y_next=(float)y1;
  if(abs(dx)>=abs(dy))
  {
   do
   {
     putpixel(xd,yd,WHITE);
     if(x1<x2)
     {
      x_next=x_next+1;
      xd=(int)x_next;
      //printf("%d",xd);
     }
     //if(x1>x2)
     else
     {
      x_next=x_next-1;
      xd=(int)x_next;
      //printf("%d\t",xd);
     }
     if(y1<y2)
     {
      y_next=y_next+m;
      y_next+=0.5;
      yd=(int)y_next;
      //printf("%d\t",yd);
      y_next-=0.5;
     }
     //if(y1>y2)
     else
     {
      y_next=y_next-m;
      y_next+=0.5;
      yd=(int)y_next;
      //printf("%d\t",yd);
      y_next-=0.5;
     }
     //printf("\n");
   }while(x_next!=x2);
  }
  else
  {
   do
   {
     putpixel(xd,yd,WHITE);
     if(x1<x2)
     {
      x_next=x_next+(1/m);
      x_next+=0.5;
      xd=(int)x_next;
      //printf("%d\t",xd);
      x_next-=0.5;
     }
     //if(x1>x2)
     else
     {
      x_next=x_next-(1/m);
      x_next+=0.5;
      xd=(int)x_next;
      //printf("%d\t",xd);
      x_next-=0.5;
     }
     if(y1<y2)
     {
      y_next=y_next+1;
      yd=(int)y_next;
      //printf("%d\t",yd);
     }
     else
     {
      y_next=y_next-1;
      yd=(int)y_next;
      //printf("%d\t",yd);
     }
     //printf("\n");
   }while(y_next!=y2);
  }

}
// Bresenham Line Drawing Algorithm
void Bresenham_Line(int x1, int y1, int x2, int y2)
{
   //int gd=DETECT,gm;
  int dx,dy,x_next,y_next,g,g_next;

  dx=abs(x2-x1);
  dy=abs(y2-y1);

  x_next=x1;
  y_next=y1;
  if(dx>=dy)
  {
   g=(2*dy)-dx;
   g_next=g;
   do
   {
    putpixel(x_next,y_next,WHITE);
    if(g_next>=0)
    {
     if(x1<x2)
     x_next+=1;
      if(x1>x2)
     x_next-=1;
     if(y1<y2)
     y_next+=1;
     if(y1>y2)
     y_next-=1;
     g_next=g_next+(2*dy)-(2*dx);
    }
    else
    {
     //no change in x
     if(x1<x2)
     x_next+=1;
     if(x1>x2)
     x_next-=1;
     g_next=g_next+(2*dy);
    }
   }while(x_next!=x2);
  }
  else
  {
   g=2*dx-dy;
   g_next=g;
   do
   {
    putpixel(x_next,y_next,WHITE);
    if(g_next>=0)
    {
     if(x1<x2)
     x_next+=1;
      if(x1>x2)
     x_next-=1;
     if(y1<y2)
     y_next+=1;
     if(y1>y2)
     y_next-=1;
     g_next=g_next+(2*dx)-(2*dy);
    }
    else
    {
     //no change in y
     if(y1<y2)
     y_next+=1;
     if(y1>y2)
     y_next-=1;
     g_next=g_next+(2*dx);
    }
   }while(y_next!=y2);
  }
}

// Object Drawing using DDA and Bresenham Line Drawing Algorithms
void Object_Drawing() 
{
    DDA_Line(100, 100, 200, 100);
    DDA_Line(100, 100, 100, 200);
    DDA_Line(100, 200, 200, 200);
    DDA_Line(200, 100, 200, 200);
    
    Bresenham_Line(300, 100, 400, 100);
    Bresenham_Line(300, 100, 300, 200);
    Bresenham_Line(300, 200, 400, 200);
    Bresenham_Line(400, 100, 400, 200);
}

void House_Drawing()
{
    Bresenham_Line(150,100,50,200);
    DDA_Line(150,100,350,100);
    Bresenham_Line(150,100,300,200);
    DDA_Line(300,200,500,200);
    Bresenham_Line(350,100,500,200);
    DDA_Line(50,200,300,200);

    Bresenham_Line(50,200,50,450);
    DDA_Line(50,450,500,450);
    Bresenham_Line(500,200,500,450);
    Bresenham_Line(300,200,300,450);
    Bresenham_Line(100,300,100,450);
    Bresenham_Line(200,300,200,450);
    DDA_Line(100,200,300,200);
    DDA_Line(100,300,200,300);
}
int main() 
{
    // Variables to store the line coordinates
    int choice, x1, y1, x2, y2;
    int gd = DETECT, gm;
    while (1) // loop indefinitely until user enters "4"
    {
        printf("Enter your choice:\n1.DDA Line Drawing Algorithm\n\n2. Bresenham Line Drawing Algorithm\n\n3. Object\n\n4. House\n\n5. Exit\n");
        scanf("%d", &choice);
        // Switch statement to handle the user's choice
        switch(choice)
        {
            case 1:
		printf("Enter the starting and ending points of line(x1 y1 x2 y2): ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                initgraph(&gd, &gm,NULL);
                DDA_Line(x1, y1, x2, y2);
                getch();
                closegraph();
                break;

            case 2:
                printf("Enter the starting and ending points of line(x1 y1 x2 y2): ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                initgraph(&gd, &gm,NULL);
                Bresenham_Line(x1, y1, x2, y2);
                getch();
                closegraph();
                break;

            case 3:
                initgraph(&gd, &gm,NULL);
                Object_Drawing();
                getch();  
                closegraph();  
                break;
            
            case 4:
                initgraph(&gd, &gm,NULL);
                House_Drawing();
                getch();  
                closegraph();  
                break;

            case 5:
                return 0; // exit the program when "4" is entered

            default:
                printf("Invalid choice. Try again\n");
        }
    }
}

