

#include <graphics.h>

#include <conio.h>

void main()
{    int i,style,k,v,w;

   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

   printf("  [3]  ");
   delay(1000);
   printf("  [2]  ");
   delay(1000);
   printf("  [1]  ");
   delay(1000);

   cleardevice();

      setcolor(LIGHTGREEN);
      settextjustify(CENTER_TEXT, CENTER_TEXT);

      style = DEFAULT_FONT;

      settextstyle(style, HORIZ_DIR, 8);
      delay(1800);

     cleardevice();

   for (i=0; i<400; i++)
  {
    setcolor(BLUE);
   //line (250,200+i,250,280+i);
  // setfillstyle(SOLID_FILL,BLUE);
 // fillellipse(250,300+i,400-i,400-i);
  circle(250,300+i,400-i);
  circle(250,300+i,399-i);
  circle(250,300+i,398-i);
  circle(250,300+i,397-i);
  circle(250,300+i,396-i);
  circle(250,300+i,395-i);
  circle(250,300+i,394-i);
  circle(250,300+i,393-i);
  circle(250,300+i,392-i);
  circle(250,300+i,391-i);
  circle(250,300+i,390-i);
  circle(250,300+i,389-i);
  circle(250,300+i,388-i);
 /*
   if (i%2==0)
   {

     for (  v=10; v>=0; v--)
    {
     setcolor(YELLOW);
     circle(318,400-i,v);
     circle(335,400-i,v);
    }

    setcolor(LIGHTRED);
     circle(325,260-i,5);
     circle(325,260-i,4);
     circle(325,260-i,3);
     circle(325,260-i,2);
     circle(325,260-i,1);

   }

   else
   {
     setcolor(YELLOW);
     for (  w=10; w>=0; w--)
    {
     circle(300,400-i,w);
     circle(325,400-i,w);
     circle(350,400-i,w);
    }
   }
 */
   setcolor(WHITE);

   line(300,300-i,350,300-i);  // upper horizon
   line(300,300-i,300,400-i);  // left vertical

   line(270,400-i,380,400-i);  // bottom horizon
   line(350,300-i,350,400-i);  // right vertical

   line(300,350-i,270,400-i);  // left slant
   line(350,350-i,380,400-i);  // right slant

   line(300,300-i,325,260-i);  // top left slant
   line(325,260-i,350,300-i);  // top right slant
  // setfillstyle(SOLID_FILL,WHITE);
  // floodfill(280,395-i,WHITE);
  // setfillstyle(SOLID_FILL,WHITE);
  // floodfill(325,395-i,WHITE);
  // setfillstyle(SOLID_FILL,WHITE);
  // floodfill(375,395-i,WHITE);
  // setfillstyle(SOLID_FILL,WHITE);
   //floodfill(325,265-i,WHITE);


   setcolor(GREEN);
   line(325,324-i,310,304-i);
   line(325,324-i,340,304-i);
   line(310,328-i,340,328-i);
   line(310,328-i,310,348-i);
   line(310,348-i,340,348-i);
   line(310,352-i,340,352-i);
   line(310,352-i,310,372-i);
   line(310,372-i,340,372-i);
   line(310,362-i,330,362-i);
   line(310,376-i,340,376-i);
   line(325,376-i,325,396-i);

     // LAUNCHING SMOKE
   if (i==0)
   {
     delay(100);
    for ( k=0; k<70; k++)
    {
     delay(100);
     setcolor(DARKGRAY);
     circle(250,400,k);
     circle(270,400,k);
     setcolor(LIGHTGRAY);
     circle(285,400,k+10);
     circle(318,400,k+30);
     circle(335,400,k+30);
     circle(370,400,k+10);
     setcolor(DARKGRAY);
     circle(390,400,k);
     circle(410,400,k);
    }
   }

   for(w=1;w<50;w++)
   { setcolor(RED);
   arc(325,425-i+w,0,180,25);
   line(300,425-i+w,325,480-i+w);
   line(350,425-i+w,325,480-i+w);
   arc(280,410-i+w,0,180,10);
   line(270,410-i+w,280,450-i+w);
   line(290,410-i+w,280,450-i+w);
   arc(370,410-i+w,0,180,10);
   line(360,410-i+w,370,450-i+w);
   line(380,410-i+w,370,450-i+w);
   setfillstyle(SOLID_FILL,RED);
   floodfill(325,425-i+w,RED);
   setfillstyle(SOLID_FILL,RED);
   floodfill(290,410-i+w,RED);
   setfillstyle(SOLID_FILL,RED);
   floodfill(360,410-i+w,RED);
   }
   delay(5);
   cleardevice();
  }

  cleardevice();

     setcolor(LIGHTGREEN);
     settextjustify(CENTER_TEXT, CENTER_TEXT);

      style = TRIPLEX_FONT;
      cleardevice();

      getch();
   closegraph();
   }