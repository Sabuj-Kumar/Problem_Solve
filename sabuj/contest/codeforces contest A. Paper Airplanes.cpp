#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int man,number,plane,seet,pack = 0,count = 1,root = 0,a;

    scanf("%d %d %d %d",&man,&number,&plane,&seet);

    if(number > plane)
    {
       a = plane;

       while(number > a)
       {
            a += plane;

            count++;
       }
       a = man * count;

       while(a < seet)
       {


       }

    }

    printf("%d\n",(a/seet));

    return 0;
}
