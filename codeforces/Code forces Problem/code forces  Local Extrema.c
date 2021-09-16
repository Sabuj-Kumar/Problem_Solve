#include<stdio.h>
int main()
{
    int ar[10001], i, n, cheek = 0, flag = 0, flag1 = 0;

    scanf("%d",&n);

    for(i=0; i<n; i++)
     scanf( "%d", &ar[i] );

    for(i=1; i<n; i++)
    {
        int f,l;
        f=i;
        l=i;
        --f;
        ++l;

        if( ar[f] > ar[i] && ar[i] < ar[l] )
        {
           printf( "%d\n", ar[i] );
           flag = 0;
           break;
        }
        else
        {
            flag = 1;
            f = 0;
            l = 0;
        }
    }
  if(flag == 1)
  {
    for(i=1; i<n; i++)
    {
        int f,l;
        f=i;
        l=i;
        --f;
        ++l;

        if( ar[f] < ar[i] && ar[i] > ar[l] )
        {
           printf( "%d\n", ar[i] );
           flag1 = 0;
           break;
        }

        else
         flag1 = 1;
    }
  }
    if(flag1 == 1)
    printf( "0\n" );

    return 0;
}
