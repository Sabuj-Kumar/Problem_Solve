#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);

    for( int i = 0; i < test; i++ )
    {
        char month1[20] = {0};
        char month2[20] = {0};

        int date1 = 0,date2 = 0;

        long long year1 = 0,year2 = 0;

        scanf("%s %d, %lld",month1,&date1,&year1);
        scanf("%s %d, %lld",month2,&date2,&year2);

        if( strcmp(month1,"January") != 0 &&  strcmp(month1,"February") != 0 )
        {
            year1++;
        }
        if( strcmp(month2,"January") == 0 || ( strcmp( month2,"February") == 0 && date2 < 29))
        {
            year2--;
        }

        long long leap1 = 0,leap2 = 0,leap = 0;
        year1--;

        leap1 = (year2 / 4) + (year2 / 400) - (year2 / 100);
        leap2 = (year1 / 4) + (year1 / 400) - (year1 / 100);

        leap = leap1 - leap2;

        printf("Case %d: %lld\n",i+1,leap);
    }
    return 0;
}
