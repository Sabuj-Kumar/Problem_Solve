#include <graphics.h>
#include <dos.h>
#include<stdio.h>
#include<conio.h>
int main()
{
   int i, j = 2, gd = DETECT, gm;

    bool dbflag= false,closeflag=true;
    initwindow(1000,800,"My Game",0, 0, dbflag, closeflag);
   //initgraph(&gd,&gm,"C:\\TC\\BGI");

   //settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   //outtextxy(0,0,"Press any key to view the moving car");
//readimagefile("a.jpg",10, 20,INT_MAX, INT_MAX);
   //getch();
char ch='\0';
int dx1=0,dx2=0,dx3=0,dx4=0,dx5=0,dx6=0,dx7=0,dx8=0,dx9=0;
int dy1=0,dy2=0,dy3=0,dy4=0,dy5=0,dy6=0,dy7=0,dy8=0,dy9=0;

int p1_flag=0,p1_count=0,p2_count=0;
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   for(;;)
   {
       outtextxy(0,0,"Player:1 first press 'p' then choose from numbers as poistion");
       outtextxy(0,20,"Player:2 first press 'q' then choose from numbers as poistion");
        /* primary lines */
        bar(300,50,305,550);
        bar(500,50,505,550);
        bar(150,200,650,205);
        bar(150,400,650,405);
        if(ch=='p')
        {
            p1_flag=1;
        }
            if(ch=='1' && p1_flag==1)
            {
                line(150,430,275,550);
                line(150,550,275,430);
                dx1=1;
            }
            else if(ch=='1' && p1_flag==0)
            {
                circle(215,490,50);
                dy1=1;
            }
            if(ch=='4' && p1_flag==1)
            {
                line(150,240,275,360);
                line(150,360,275,240);
                dx4=1;
            }
            else if(ch=='4' && p1_flag==0)
            {
                circle(215,300,50);
                dy4=1;
            }
            if(ch=='7' && p1_flag==1)
            {
                line(150,50,275,170);
                line(150,170,275,50);
                dx7=1;
            }
            else if(ch=='7' && p1_flag==0)
            {
                circle(215,110,50);
                dy7=1;
            }
            if(ch=='2' && p1_flag==1)
            {
                line(340,430,465,550);
                line(340,550,465,430);
                dx2=1;
            }
            else if(ch=='2' && p1_flag==0)
            {
                circle(405,490,50);
                dy2=1;
            }
            if(ch=='5' && p1_flag==1)
            {
                line(340,240,465,360);
                line(340,360,465,240);
                dx5=1;
            }
            else if(ch=='5' && p1_flag==0)
            {
                circle(405,300,50);
                dy5=1;
            }
            if(ch=='8' && p1_flag==1)
            {
                line(340,50,465,170);
                line(340,170,465,50);
                dx8=1;
            }
            else if(ch=='8' && p1_flag==0)
            {
                circle(405,110,50);
                dy8=1;
            }
            if(ch=='3' && p1_flag==1)
            {
                line(530,430,655,550);
                line(530,550,655,430);
                dx3=1;
            }
            else if(ch=='3' && p1_flag==0)
            {
                circle(595,490,50);
                dy3=1;
            }
            if(ch=='6' && p1_flag==1)
            {
                line(530,240,655,360);
                line(530,360,655,240);
                dx6=1;
            }
            else if(ch=='6' && p1_flag==0)
            {
                circle(595,300,50);
                dy6=1;
            }
            if(ch=='9' && p1_flag==1)
            {
                line(530,50,655,170);
                line(530,170,655,50);
                dx9=1;
            }
            else if(ch=='9' && p1_flag==0)
            {
                circle(595,110,50);
                dy9=1;
            }

        if(ch=='q')
        {
            p1_flag=0;
        }
        delay(100);
        if(dx1+dx2+dx3==3)
        {
            //cleardevice();
            setcolor(2);
            bar(150,488,655,490);
            //line(150,490,655,490);
            outtextxy(200,600,"Congratulations \"X\" Wins");
            break;

        }
        else if(dx1+dx4+dx7==3)
        {
            //cleardevice();
            line(215,550,215,50);
            outtextxy(200,600,"Congratulations \"X\" Wins");
            break;
        }
        else if(dx7+dx8+dx9==3)
        {
            //cleardevice();
            line(150,110,655,110);
            outtextxy(200,600,"Congratulations \"X\" Wins");
            break;
        }
        else if(dx4+dx5+dx6==3)
        {
            //cleardevice();
            line(150,300,655,300);
            outtextxy(200,600,"Congratulations \"X\" Wins");
            break;
        }
        else if(dx2+dx5+dx8==3)
        {
            //cleardevice();
            line(405,550,405,50);
            outtextxy(200,600,"Congratulations \"X\" Wins");
            break;
        }
        else if(dx9+dx6+dx3==3)
        {
            //cleardevice();
            line(595,550,595,50);
            outtextxy(200,600,"Congratulations \"X\" Wins");
            break;
        }
        else if(dx1+dx5+dx9==3)
        {
            //cleardevice();
            setcolor(9);
            line(215,490,595,110);
            outtextxy(200,600,"Congratulations \"X\" Wins");
            break;
        }
        else if(dx7+dx5+dx3==3)
        {
            //cleardevice();
            line(215,110,595,490);
            outtextxy(200,600,"Congratulations \"X\" Wins");
            break;
        }
        else if(dy1+dy2+dy3==3)
        {
            //cleardevice();
            setcolor(2);
            bar(150,488,655,490);
            outtextxy(200,600,"Congratulations \"0\" Wins");
            break;

        }
        else if(dy1+dy4+dy7==3)
        {
            //cleardevice();
            line(215,550,215,50);
            outtextxy(200,600,"Congratulations \"0\" Wins");
            break;
        }
        else if(dy7+dy8+dy9==3)
        {
            //cleardevice();
            line(150,110,655,110);
            outtextxy(200,600,"Congratulations \"0\" Wins");
            break;
        }
        else if(dy9+dy6+dy3==3)
        {
            //cleardevice();
            line(595,550,595,50);
            outtextxy(200,600,"Congratulations \"0\" Wins");
            break;
        }
        else if(dy1+dy5+dy9==3)
        {
            //cleardevice();
            line(215,490,595,110);
            outtextxy(200,600,"Congratulations \"0\" Wins");
            break;
        }
        else if(dy7+dy5+dy3==3)
        {
            //cleardevice();
            line(215,110,595,490);
            outtextxy(200,600,"Congratulations \"0\" Wins");
            break;
        }
        else if(dy4+dy5+dy6==3)
        {
            //cleardevice();
            line(150,300,655,300);
            outtextxy(200,600,"Congratulations \"0\" Wins");
            break;
        }
        else if(dy2+dy5+dy8==3)
        {
            //cleardevice();
            line(405,550,405,50);
            outtextxy(200,600,"Congratulations \"O\" Wins");
            break;
        }
        ch=getch();
        delay(100);

   }
   //cleardevice();
   getch();
   //closegraph();
   return 0;
}
