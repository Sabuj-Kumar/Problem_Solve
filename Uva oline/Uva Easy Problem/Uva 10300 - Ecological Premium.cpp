#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
   int t;

   while( scanf("%d",&t) == 1 )
   {
       while( t-- )
       {
          int n,a,b,c,sum = 0;

          cin>>n;

          while( n-- )
          {
             cin>>a>>b>>c;

             sum += a  * c;
          }
          cout<<sum<<endl;
      }
   }

   return 0;
}
