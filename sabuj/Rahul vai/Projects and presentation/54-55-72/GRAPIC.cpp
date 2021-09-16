#include<stdio.h>
#include <graphics.h>
using namespace std;
int main ( )
 {
    initwindow(640, 480); // set size of drawing window

    int x = 10, y = 100; // select initial values for x and y - coordinates of top of tail fin
    int xmove = 3, ymove = 0; // set values for distance to move in x and y directions
    int new_page, old_page; // declare integer variables representing two graphics pages

    for (int move = 1; move <= 75; move++ ) // move jet 75 times
      {
        old_page = getvisualpage( ); // set old_page to the number of the visual page
        new_page = abs(old_page-1); // set new_page to the visual page number-1
        setactivepage(new_page); // set the active page to the value of the new page
        cleardevice( ); // erase the active page

        setfillstyle(1,COLOR(100, 200, 255)); // fill in the background with sky blue
        int bkground[ ] = {0,0, 639,0, 639,479, 0,479, 0,0};
        fillpoly(5,bkground);

        setcolor( YELLOW ); // draw and fill in the sun
        circle(200, 80, 50);
        setfillstyle(1, YELLOW);
        floodfill(200, 50, 14);

        setcolor( WHITE ); // set outline color for jet to WHITE
        setfillstyle(1,RED);
        int fuselage[ ] = {x,y, x+10,y, x+20,y+10, x+90,y+10, x+120,y+20, x+20,y+20, x,y};
        fillpoly(7,fuselage); // fill in the body of the plane with RED

        setfillstyle(1,red);
        int frontWing[ ] = {x+60,y+15, x+40,y+30, x+20,y+30, x+30,y+30, x+50,y+15, x+60,y+15};
        fillpoly(6,frontWing); // fill in the front wing with BLACK

        int topWing[ ] = {x+46,y+10, x+30,y, x+20,y, x+40,y, x+58,y+10, x+46,y+10};
        fillpoly(6,topWing); // fill in the top wing with BLACK

        int pilotArea[ ] = {x+82,y+10, x+90,y+15, x+105,y+15, x+90,y+10, x+82,y+10};
        fillpoly(5,pilotArea); // fill in the pilot area with BLACK

        setvisualpage(new_page); // move the activepage to the visual page

        delay(20); // delay for 20 milliseconds to allow the user to see the image for a fraction of a second

        x = x + xmove; // change the value of x by xmove to change the jet's position
        y = y + ymove; // change the value of y by ymove to change the jet's position
      }

    getch( ); // wait for user response
    closegraph( ); // close the graph
    return (0);
}
