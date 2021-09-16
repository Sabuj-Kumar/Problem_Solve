#include <graphics.h>
#include <dos.h>
#include<stdio.h>
#include<conio.h>
int main()
{
             int i, j = 2;
             int ch='\0';
   bool dbflag= false,closeflag=true;
    initwindow(1000,2000,"Umbralla",0, 0, dbflag, closeflag);


            for( i = 0 ;i<=500 ; )
   {
      if((int)ch==77)
       {
           i=i+10;
      }
      if((int)ch==75)
       {
           i=i-10;
      }


     line(530,499, 500, 450);
     line(580,490, 540, 440);

      arc(490, 438, 0, 50, 50);
     line(520, 400, 515, 380);
     line(510, 430, 505, 380);
     fillellipse(510, 380,5, 8);
     fillellipse(490, 420,20, 4);
     fillellipse(490, 428,20, 4);
     fillellipse(490, 435,20, 4);
     fillellipse(490, 443,20, 6);
     fillellipse(505, 428,10, 15);

     line(490,190, 500, 450);
     line(491,190, 501, 450);
     line(492,190, 502, 450);
     line(493,190, 503, 450);
     line(494,190, 504, 450);
     line(495,190, 505, 450);
     line(496,190, 506, 450);
     line(497,190, 507, 450);
     line(490,190, 500, 450);




     fillellipse(492, 235,9+i, 15);


         ch=getch();
      cleardevice();

   }
      getch();

   closegraph();
   return 0;
}
