#include <iostream>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include<stdlib.h>
using namespace std;
char *wordSearch();
void gotoxy(int x,int y);
struct dict
{
    char wordName[32];
    char wordPos[15];
    char wordMeaning[32];
}dic[1000];
int main()
{
    
    FILE *fp;
    char s[32];
    fp=fopen("dict.txt","r");
    for(int i=0;i<253;i++)
    {
        fscanf(fp,"%s%s%s",&dic[i].wordName,&dic[i].wordPos,&dic[i].wordMeaning);
    }
    while(1){
        char ch;
        int f=0;
        gotoxy(29,4);
        cout<<"Quick Dictionary";
        gotoxy(28,5);
        cout<<"------------------";
        gotoxy(33,7);
        cout<<"--------\n";
        strcpy(s,wordSearch());
        gotoxy(29,4);
        cout<<"Quick Dictionary";
        gotoxy(28,5);
        cout<<"------------------";
        gotoxy(33,7);
        cout<<"--------\n";
        for(int i=0;i<253;i++)
        {
            if(strcmp(dic[i].wordName,s)==0){
                gotoxy(33,6);
                cout<<dic[i].wordName;
                gotoxy(28,9);
                cout<<"Parts of Speech : "<<dic[i].wordPos;
                gotoxy(28,11);
                cout<<"word meaning : "<<dic[i].wordMeaning;
                gotoxy(29,15);
                f=1;
            }
        }
        if(f==0){
            gotoxy(33,6);
            cout<<s;
            gotoxy(28,9);
            cout<<"No word found...";
        }
        gotoxy(17,15);
        cout<<"If you want search another word press Enter key";
        gotoxy(17,17);
        cout<<"If you want exit the program press Q ..";
        ch=getch();
        system("cls");
        if(ch=='q' || ch=='Q')
            break;
    }
    gotoxy(17,10);
    cout<<"Thanks For using our Dictionary....";
    gotoxy(17,20);
    return 0;
}
char *wordSearch()
{
    int j=0;
    char ch;
    char a[32];
    while(1)
    {
        gotoxy(29,4);
        cout<<"Quick Dictionary";
        gotoxy(28,5);
        cout<<"------------------";
        gotoxy(33,7);
        cout<<"--------\n";
        gotoxy(j+33,6);
        int i,k,l;
        int flag=0;
        int n=0;
        ch=getch();
        system("cls");
        if(ch==8)
        {
            j--;
            system("cls");
            gotoxy(33,6);
            for(k=0;k<j;k++)
            cout<<a[k];
            j--;
            if(j<0)
                j=-1;
        }
        else if(ch==13){
            a[j]=NULL;
            break;
        }
        else{
            a[j]=ch;
        }
        gotoxy(j+33,6);
        cout<<ch;
        gotoxy(33,7);
        cout<<"--------\n";
        for(k=0;k<=253;k++)
        {
            for(l=0;l<=j;l++)
            {
                if(a[l]!=dic[k].wordName[l])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                gotoxy(33,n+8);
                cout<<dic[k].wordName<<endl;
                n++;
            }
            flag=0;
        }
        gotoxy(33,6);
        for(k=0;k<j;k++)
            cout<<a[k];
        j++;
    }
    return a;
}
void gotoxy(int x,int y)
{
    COORD ord;
    ord.X = x;
    ord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),ord);

}
