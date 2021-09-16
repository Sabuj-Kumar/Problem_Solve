#include "iGraphics.h"

int X=150;
int Y=210;


int flag=0;
int score=0;
int i=0;
int n=6;
int stickx[90]={100,240,0,300,440,300,520,420,7,0};
int sticky[90]={178,100,300,500,400,0,100,400,400,0};
int stick_state=0;

int start=1;
int state=2;
int store;

void move()

{

	if(state==1 && stick_state==1)
	{
		Y-=9;
	}
	if(Y-10>670 || Y<-200)
	{
		Y=900;
		start=0;
		state=4;
	}



	for(i=0;i<n;i++)
	{

	if(stick_state==1){
	sticky[i]+=3;
	}

	if(sticky[i]>670)
	{
		sticky[i]=-20;
		stickx[i]=1+rand()%680;
	}


	if((X>stickx[i] && X<stickx[i]+120  &&  Y-20>=sticky[i] && Y-20<=sticky[i]+20 && stick_state==1))
	{

		state=2;
		Y=sticky[i]+32;
	}

	else
		state=1;
	}

	if(Y==900)
	{
		flag=1;
		X=150;
		Y=210;
	score=0;
	i=0;
	n=6;
	stick_state=0;
	state=2;
	stickx[0]=100;
	sticky[0]=178;


	}


}

void scoree()
{
	for(i=0;i<n;i++)
	{

	if(X>stickx[i] && X<stickx[i]+120  &&  Y-20>=sticky[i] && Y-20<=sticky[i]+20 && stick_state==1)
	{
	score++;
	store=score;
	}

	}




}


void iDraw()
{
	iClear();

	iSetColor(25,250,0);
	iFilledCircle(X,Y,20);
	iSetColor(255,0,0);

	for(i=0;i<n;i++){
	iFilledRectangle(stickx[i],sticky[i],120,10);
	}

	char sc[40];
	sprintf(sc,"%d",score);
	iSetColor(245,67,0);
	iText(620,620,"SCORE :",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(740,620,sc,GLUT_BITMAP_TIMES_ROMAN_24);

	if(score==0)
	{
		char str[40];
		sprintf(str,"%d",store);

		if(flag==1){
		iSetColor(0,0,0);
		iFilledRectangle(200,280,400,100);
		iSetColor(250,250,50);
		iText(300,350,"!!GAME OVER!!",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(63,72,204);
		iText(280,315,"YOU SCORED :",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(460,315,str,GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(250,250,50);
		iText(230,290,"Press Space to restart this game",GLUT_BITMAP_TIMES_ROMAN_24);
		}

		else if(start==1)
		{
			iSetColor(0,0,0);
			iFilledRectangle(200,280,400,100);
			iSetColor(250,250,50);
			iText(230,330,"Welcome To the Rapid ROLL",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(230,300,"Press Space to start this game",GLUT_BITMAP_TIMES_ROMAN_24);
			}
	}

//place your drawing codes here
}

void iMouseMove(int mx, int my)
{
//place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
//place your codes here
}

void iKeyboard(unsigned char key)
{
	if(key=='i')
	{
	//state=1;
	}
	if(key=='l'&& stick_state==1)
	{
	X+=16;




	}


	if(key=='j' && stick_state==1)
	{
	X-=16;



	}


	if(key==' ')
	{
	stick_state=1;
	flag=0;

	}


//place your codes here
}

void iSpecialKeyboard(unsigned char key)
{

	if(key==GLUT_KEY_LEFT && stick_state==1)
	{
	X-=16;

	}

	if(key==GLUT_KEY_RIGHT && stick_state==1)
	{
	X+=16;

	}


//place your codes for other keys here
}

int main()
{
//place your own initialization codes here.

	iSetTimer(10,move);

	iSetTimer(100,scoree);
	iInitialize(800,650,"Self Loop");
return 0;
}
