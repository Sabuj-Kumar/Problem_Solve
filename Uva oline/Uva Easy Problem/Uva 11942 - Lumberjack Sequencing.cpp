#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int test;

    sf("%d",&test);

    pf("Lumberjacks:\n");

    while(test--)
    {
       int j = 0,a[12] = {0},flag1 = 0,flag2 = 0,check = 0,check1 = 0;


       for(j = 0; j < 10; j++)
           sf("%d",&a[j]);

       for(j = 1; j < 10; j++)
       {
          if(a[j-1] > a[j] && j == 1)
              flag1 = 1;

          else if( a[j-1] < a[j] && j == 1)
              flag2 = 1;

          if( flag1 == 1)
          {
              if(a[j-1] > a[j])
              {
                  check = 1;
              }
              else
              {
                  check = 0;
                  break;
              }
          }
          else  if( flag2 == 1)
          {
              if(a[j-1] < a[j])
              {
                  check1 = 1;
              }
              else
              {
                  check1 = 0;
                  break;
              }
          }
       }
       if(flag1 == 1)
       {
           if(check == 1)
              pf("Ordered\n");

           else
              pf("Unordered\n");
       }
       else
       {
           if(check1 == 1)
              pf("Ordered\n");

           else
              pf("Unordered\n");
       }
    }
    return 0;
}
