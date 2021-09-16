#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

int main()
{
    long long test,i;

    cin>>test;

    for(i = 1; i <= test; i++)
    {
       long long year1,year2,date1,date2,a,b;

       char month1[20] = {0};
       char month2[20] = {0};

       scanf("%s %lld,%lld",month1,&date1,&year1);
       scanf("%s %lld,%lld",month2,&date2,&year2);

       if(strcmp(month1,"January") != 0 && strcmp(month1,"February") != 0)
           year1++;

       if(strcmp(month2,"January") == 0 || (strcmp( month2,"February") == 0 && date2 < 29))
           year2--;

       year1--;

       a = (year1/4) + (year1/400) - (year1/100);
       b = (year2/4) + (year2/400) - (year2/100);

       printf("Case %lld: %lld\n",i,(b-a));
    }

    return 0;
}
