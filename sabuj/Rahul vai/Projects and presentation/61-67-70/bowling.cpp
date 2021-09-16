#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
int main()
{
     bool dbflag= false,closeflag=true;
    initwindow(1000,10000,"Bowling",0, 0, dbflag, closeflag);
    setcolor(BLUE);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
    outtextxy(300,300,"BOWLING");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    outtextxy(200,650,"Created by---70,67 and 61");

setcolor(WHITE);
line(300, 100, 150, 600);
line(600, 100, 750, 600);
line(275, 100, 75, 600);
line(625, 100, 825, 600);
line(180, 500, 719, 500);
line(275, 100, 300, 100);
line(600, 100, 625, 100);
line(75, 600, 150, 600);
line(750, 600, 825, 600);
setcolor(GREEN);
circle(320,450,50);
circle(320,450,49);
circle(320,450,48);
circle(320,450,47);
circle(320,450,46);
circle(320,450,44);
circle(320,450,42);
circle(320,450,38);


bar(310, 55, 335, 155);
bar(355, 60, 380, 160);
bar(400, 65, 425, 165);
bar(445, 70, 470, 170);
bar(490, 65, 515, 165);
bar(535, 60, 560, 160);
bar(580, 55, 605, 155);
bar(442, 55, 467, 155);
bar(397, 60, 422, 160);
bar(487, 60, 512, 160);


    getch();
    closegraph();

return 0;
}
