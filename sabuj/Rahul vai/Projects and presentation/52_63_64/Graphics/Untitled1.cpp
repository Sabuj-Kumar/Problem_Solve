#include <graphics.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <conio.h>
//#include<math.h>
//#include<dos.h>
//#include<string.h>
//#include<iostream>
//#include<ctime>

int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
    char ch;
    int y1=0,y2=0,x1=0,x2=0;
    while((ch=getch())!='p')
    {
        cleardevice();
        if(ch=='l'){
            y1++;
            y2--;
        }
        else if(ch=='r')
        {
            y1--;
            y2++;
        }

    line(250,100,300,180);//face
    line(252,102,302,182);//face
    line(250,98,298,178);//face
    line(251,101,301,181);//face
    line(250,99,299,179);//face
    line(300,180,350,100);//face
    line(299,179,349,99);//face
    line(290,152,310,152);//mouth
    line(290,153,310,153);//mouth
    line(300,130,300,146);//nose
    line(301,130,301,146);//nose
    circle(280,120,5);
    setfillstyle(SOLID_FILL,WHITE);
    setcolor(WHITE);
    circle(280,120,5);
    floodfill(280,120,WHITE);

    setfillstyle(SOLID_FILL,WHITE);
    setcolor(WHITE);
    circle(320,120,5);
    floodfill(320,120,WHITE);
    line(260+y1,50,260,100);//hair
    line(270+y1,50,270,100);
    line(280+y1,50,280,100);
    line(290+y1,50,290,100);
    line(300+y1,50,300,100);
    line(310+y1,50,310,100);
    line(320+y1,50,320,100);
    line(330+y1,50,330,100);
    line(340+y1,50,340,100);//hair
    line(261+y1,50,261,100);//hair
    line(271+y1,50,271,100);
    line(281+y1,50,281,100);
    line(291+y1,50,291,100);
    line(301+y1,50,301,100);
    line(311+y1,50,311,100);
    line(321+y1,50,321,100);
    line(331+y1,50,331,100);
    line(341+y1,50,341,100);//hair
    line(300,180,300,420);//body
    line(301,180,301,420);//body
    line(302,180,302,420);//body
    line(298,180,298,420);//body
    line(299,180,299,420);//body
    line(300,420,250,470+y2);//leg
    line(300,420,350,470+y1);
    line(300,421,250,471+y2);//leg
    line(300,421,350,471+y1);
    line(300,200,200+x1,200+y1);//left hand
    line(300,201,200+x1,201+y1);//left hand
    line(200,200+y1,200,225+y1);
    line(201,200+y1,201,225+y1);
    line(400,200+y2,400,225+y2);
    line(401,200+y2,401,225+y2);
    line(300,200,400+x2,200+y2);//right hand
    line(300,201,400+x2,201+y2);//right hand


    }
    getch();
    closegraph();

return 0;
}
