#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    int t = 10;
    while(t--){
    line(100,100,200,200);//vertical
    line(100,100,200,100);
    line(100,100,100,80);
    line(200,100,200,80);
    line(100,80,200,80);
    line(100,200,200,100);
    line(100,200,100,220);
    line(200,200,200,220);
    line(100,220,200,220);
    line(200,200,100,200);
    delay(1000);
    cleardevice();
    line(100,100,200,200);//horizontal
    line(80,100,100,100);
    line(200,100,200,200);
    line(100,200,200,100);
    line(200,100,220,100);
    line(200,200,220,200);
    line(220,100,220,200);
    line(80,200,100,200);
    line(80,100,80,200);
    line(100,100,100,200);
    delay(1000);
    cleardevice();
}
    //closegraph();
    getch();
    return 0;
    }
