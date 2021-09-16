#include <iostream>
#include <cstdio>
#include <cstring>
#include <conio.h>
using namespace std;
struct dict
{
    char mainWord[32];
    char Pos[15];
    char Mean[32];
}dic[1000];
int main()
{
    FILE *fp;
    char s[32],ch;
    fp=fopen("dictionary.txt","r");
    for(int i=0;i<253;i++)
    {
        fscanf(fp,"%s%s%s",&dic[i].mainWord,&dic[i].Pos,&dic[i]. Mean);
    }
    while(1){
        int f=0;
        cout<<"Enter your word  :";
        cin>>s;
        for(int i=0;i<253;i++)
        {
            if(strcmp(dic[i].mainWord,s)==0){
                cout<<"Parts of Speech : "<<dic[i].Pos<<endl;
                cout<<"Mean : "<<dic[i]. Mean<<endl;
                f=1;
            }
        }
        if(f==0){
            cout<<s;
            cout<<"No word found...";
        }
        cout<<"\nIf you want search another word press Enter key"<<endl;
        cout<<"\nIf you want exit the program press Q .."<<endl;
        ch=getch();
        if(ch=='q' || ch=='Q')
            break;
    }
    cout<<"Thanks For using our Quick search Dictionary...."<<endl;
    return 0;
}
