#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
using namespace std;
int main(void)
{
   initscr();
   noecho();
   cbreak(); // don't interrupt for user input
   //timeout(500);     // wait 500ms for key press
   int c = 0;        // command: [c|q|s]
   int s = 1;        // state: 1= print, 0= don't print ;-)
   int i = 0, j = 0;
   while (c != 'q')
   {
      int c = getch();
      switch (c)
      {
         case 'q':
            endwin();
            return 0;
         case 'c':
            s = 1;
            break;
         case 's':
            s = 0;
            break;
         default:
            break;
      }
      if (s)
      {
         move(i, j);
         printw("a");
         i++;
         j++;
      }
   }
   endwin();
   nocbreak();
   return 0;
}
