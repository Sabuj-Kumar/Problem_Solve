#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<time.h>

int main()
{
        /* request auto detection */
        int gdriver = DETECT, gmode, err;
        int i, midx, midy;
        long mytime;
        char date[256];


        /* initialize graphic mode */
        initgraph(&gdriver, &gmode, "C:/");
        err = graphresult();

        if (err != grOk) {
                /* error occurred */
                printf("Graphics Error: %s\n",grapherrormsg(err));
                return 0;
        }


        /* center position of the star */
        midx = getmaxx() / 2;
        midy = getmaxy() / 2;

        /*
         * draw a star and fill with different
         * colors to get twinkling effect
         */
        while (!kbhit()) {
                /* clears graphic screen */
                cleardevice();

                /* get time in seconds */
                mytime = time(NULL);

                /* store the date and time in the given string */
                strcpy(date, ctime(&mytime));

                /* set the backgroung color to WHITE */
                setbkcolor(BLACK);

                settextjustify(CENTER_TEXT, CENTER_TEXT);
                settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);

                /* locate the postion to write */
                moveto(300,20);

                /* print the date and time */
                outtext(date);

                /* sleep for a second */
                delay(1000);

                for (i = 1; i <= 15; i++) {
                if (i == DARKGRAY)
                        continue;

                setcolor(i);
                setfillstyle(SOLID_FILL, i);

                /* top portion of star */
                line(midx, midy - 100, midx + 30, midy);
                line(midx, midy - 100, midx, midy + 30);
                line(midx + 30, midy, midx, midy + 30);
                floodfill(midx + 1, midy + 1, i);

                setcolor(DARKGRAY);
                setfillstyle(SOLID_FILL, DARKGRAY);
                line(midx + 30, midy, midx + 140, midy);
                line(midx + 30, midy, midx, midy + 30);
                line(midx + 140, midy, midx, midy + 30);
                floodfill(midx + 31, midy + 1, DARKGRAY);

                /* right portion of star */
                setcolor(i);
                setfillstyle(SOLID_FILL, i);
                line(midx + 140, midy, midx, midy + 30);
                line(midx + 140, midy, midx + 40, midy + 50);
                line(midx + 40, midy + 50, midx, midy + 30);
                floodfill(midx  + 40, midy + 48, i);

                setcolor(DARKGRAY);
                setfillstyle(SOLID_FILL, DARKGRAY);
                line(midx + 40, midy + 50, midx, midy + 30);
                line(midx + 40, midy + 50, midx + 110, midy + 160);
                line(midx + 110, midy + 160, midx, midy + 30);
                floodfill(midx + 40, midy + 51, DARKGRAY);

                /* bottom right portion of star */
                setcolor(i);
                setfillstyle(SOLID_FILL, i);
                line(midx + 110, midy + 160, midx, midy + 30);
                line(midx + 110, midy + 160, midx, midy + 90);
                line(midx, midy + 90, midx, midy + 30);
                floodfill(midx + 1, midy + 90, i);
                setcolor(DARKGRAY);
                setfillstyle(SOLID_FILL, DARKGRAY);
                line(midx, midy + 90, midx, midy + 30);
                line(midx, midy + 30, midx - 110, midy + 160);
                line(midx - 110, midy + 160, midx, midy + 90);
                floodfill(midx - 1, midy + 90, DARKGRAY);

                /* bottom left portion of star */
                setcolor(i);
                setfillstyle(SOLID_FILL, i);
                line(midx, midy + 30, midx - 110, midy + 160);
                line(midx - 40, midy + 50, midx - 110, midy + 160);
                line(midx - 40, midy + 50, midx, midy + 30);
                floodfill(midx - 38, midy + 50, i);

                setcolor(DARKGRAY);
                setfillstyle(SOLID_FILL, DARKGRAY);
                line(midx - 40, midy + 50, midx, midy + 30);
                line(midx - 140, midy, midx - 40, midy + 50);
                line(midx - 140, midy, midx, midy + 30);
                floodfill(midx - 40, midy + 48, DARKGRAY);

                /* left portion of star */
                setcolor(i);
                setfillstyle(SOLID_FILL, i);
                line(midx - 30, midy, midx - 140, midy);
                line(midx - 140, midy, midx, midy + 30);
                line(midx - 30, midy, midx, midy + 30);
                floodfill(midx - 30, midy + 1, i);

                setcolor(DARKGRAY);
                setfillstyle(SOLID_FILL, DARKGRAY);
                line(midx - 30, midy, midx, midy + 30);
                line(midx, midy - 100, midx - 30, midy);
                line(midx, midy - 100, midx, midy + 30);
                floodfill(midx - 28, midy, DARKGRAY);

                /* sleep for 100 microseconds */
                delay(100);
        }
        }

        getch();

        /* deallocate memory allocated for graphic screen */
        closegraph();

        return 0;
  }
