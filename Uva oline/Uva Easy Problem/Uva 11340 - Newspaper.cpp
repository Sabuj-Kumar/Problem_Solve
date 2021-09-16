#include<stdio.h>
#include<iostream>
#include<string>
#include<iterator>
#include<stdlib.h>
#include<map>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);

    while(test--)
    {
        map<char,int> mymap;
        map<char,int>::iterator it;

        char key;
        int data,i,n;

        scanf("%d",&n);

        for(i = 0; i < n; i++)
        {
            cin>>key>>data;

            mymap[key] = data;
        }
        scanf("%d",&n);

        getchar();

        string line;
        double sum = 0,output = 0;

        while(n--)
        {
            getline(cin,line);

            for(i = 0; i < line.size(); i++)
            {
               if(mymap[line[i]] != 0)
               {
                  sum += mymap[line[i]];
               }
            }
        }
        printf("%.2lf$\n",(sum/100));
    }
   return 0;
}
