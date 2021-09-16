/**
UNIVWERSITY OF ASIA PACIFIC.

    SABUJ KUMAR TAROFDAR.

    PATTERN GAME.

**/

#include<iostream>

using namespace std;

int main()
{
    int n;
    int row,colum;

    while(cin>>n)
    {
       int number = 0,pos1 = 0,pos2 = 0;
       int a[n][n] = {0};

       for( row = 0; row < n; row++)
         for(colum = 0; colum < n; colum++)
           a[row][colum] = row*n+colum+1;

       cin>>number;

       for( row = 0; row < n; row++)
       {
           for(colum = 0; colum < n; colum++)
           {
              if(a[row][colum] == number)
              {
                  pos1 = row;
                  pos2 = colum;
              }
           }
       }
       for( row = 0; row < n; row++)
       {
           for(colum = 0; colum < n; colum++)
           {
               if(row > (pos1+1) || row < (pos1-1) )
                  a[row][colum] = 0;

               if(colum > (pos2+1) || colum < (pos2-1))
                  a[row][colum] = 0;
           }
       }

       for( row = 0; row < n; row++)
       {
           int flag = 0;

           for(colum = 0; colum < n; colum++)
           {
               if(a[row][colum] != 0)
               {
                   cout<<a[row][colum]<<" ";
                   flag = 1;
               }
           }
           if(flag == 1)
           cout<<endl;
       }
       cout<<endl;
    }
    return 0;
}
