#include<stdio.h>
#include<dos.h>
#include<windows.h>
#include<graphics.h>

int main()
{
    /*************** Initialization ***************/
    bool dbflag= false,closeflag=true;
    initwindow(1000,800,"Graphics",0, 0, dbflag, closeflag);

    /*************** Welcome Window ***************/
    int i=0;
    while(!kbhit()){
    setcolor(3);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
    outtextxy(0,400,"Welcome to Graphics World");
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
    setcolor(i);
    outtextxy(200,500,"Press any key to continue");
    i++;
    if(i==15)i=0;
    }
    cleardevice();



    char ch;
    int xc1=500,xc2=500,xc3=500,xc4=500;
    int yc1=400,yc2=400,yc3=400,yc4=400;
    int flag1=0,flag2=0,flag3=0;
    int flag4=0,flag5=0,flag6=0;
    int flag7=0,flag8=0,flag9=0;
    int flag10=0,flag11=0,flag12=0;

    while(1){
        /****** Circles *******/

            setcolor(12);
            circle(xc1,yc1,50); // c1
            circle(xc1,yc1,51); // c1
            circle(xc1,yc1,52); // c1
            circle(xc1,yc1,53); // c1
            circle(xc1,yc1,54); // c1

            setcolor(3);
            circle(xc2,yc2,50); // c2
            circle(xc2,yc2,51); // c2
            circle(xc2,yc2,52); // c2
            circle(xc2,yc2,53); // c2
            circle(xc2,yc2,54); // c2


            setcolor(4);
            circle(xc3,yc3,50); // c3
            circle(xc3,yc3,51); // c3
            circle(xc3,yc3,52); // c3
            circle(xc3,yc3,53); // c3
            circle(xc3,yc3,54); // c3


            setcolor(9);
            circle(xc4,yc4,50); // c4
            circle(xc4,yc4,51); // c4
            circle(xc4,yc4,52); // c4
            circle(xc4,yc4,53); // c4
            circle(xc4,yc4,54); // c4


        /******** Rectangles *********/


        rectangle(245,195,353,303);
        rectangle(246,196,352,302);
        rectangle(247,197,351,301);
        rectangle(248,198,350,300);
        bar(250,200,350,300); // U-L
        setcolor(3);

        rectangle(645,195,753,303);
        rectangle(646,196,752,302);
        rectangle(647,197,751,301);
        rectangle(648,198,750,300);
        bar(650,200,750,300); // U-R
        setcolor(5);

        rectangle(245,495,353,603);
        rectangle(246,496,352,602);
        rectangle(247,497,351,601);
        rectangle(248,498,350,600);
        bar(250,500,350,600); // B-L
        setcolor(12);

        rectangle(645,495,753,603);
        rectangle(646,496,752,602);
        rectangle(647,497,751,601);
        rectangle(648,498,750,600);
        bar(650,500,750,600); // B-R
        setcolor(15);

        /******** circle movement Here ******/

        // upper left circle

            if(flag1==0 && flag2==0)
            yc1-=10;
            if(yc1==100 && flag2==0)
            {
                flag1=1;
                xc1+=10;
                flag2=0;
            }
            if(xc1==900 && flag3==0)
            {
                yc1+=10;
                flag2=1;
            }
            if(yc1==400 && flag2==1)
            {
                xc1-=10;
                flag3=1;
            }
            if(xc1==500 && flag3==1)
            {
                flag1=0;
                flag2=0;
                flag3=0;
            }
        // first circle end
        //  bottom right circle
         if(flag4==0 && flag5==0)
            yc2+=10;
            if(yc2==700 && flag5==0)
            {
                flag4=1;
                xc2+=10;
                flag5=0;
            }
            if(xc2==900 && flag6==0)
            {
                yc2-=10;
                flag5=1;
            }
            if(yc2==400 && flag5==1)
            {
                xc2-=10;
                flag6=1;
            }
            if(xc2==500 && flag6==1)
            {
                flag4=0;
                flag5=0;
                flag6=0;
            }
     // finish
     // upper right circle
            if(flag7==0 && flag8==0)
            yc3-=10;
            if(yc3==100 && flag8==0)
            {
                flag7=1;
                xc3-=10;
                flag8=0;
            }
            if(xc3==100 && flag9==0)
            {
                yc3+=10;
                flag8=1;
            }
            if(yc3==400 && flag8==1)
            {
                xc3+=10;
                flag9=1;
            }
            if(xc3==500 && flag9==1)
            {
                flag7=0;
                flag8=0;
                flag9=0;
            }
            // finish
            // bottom left circle

            if(flag10==0 && flag11==0)
            yc4+=10;
            if(yc4==700 && flag11==0)
            {
                flag10=1;
                xc4-=10;
                flag11=0;
            }
            if(xc4==100 && flag12==0)
            {
                yc4-=10;
                flag11=1;
            }
            if(yc4==400 && flag11==1)
            {
                xc4+=10;
                flag12=1;
            }
            if(xc4==500 && flag12==1)
            {
                flag10=0;
                flag11=0;
                flag12=0;
            }
            //finish
        delay(100);
        cleardevice();
    }


}
