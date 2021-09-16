#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,sum = 0;

    scanf("%d",&n);

    int a[n][n];

    for(int i = 0; i < n; i++)
       for(int j = 0; j < n; j++)
          a[i][j] = i * n + j + 1;

    printf("Total Array Is :\n\n");

    for(int i = 0; i < n; i++)
    {
       for(int j = 0; j < n; j++)
           printf("%d ",a[i][j]);

       printf("\n");
    }

    printf("\n");
    /// First Diagonal Sum.

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                sum += a[i][j];
                printf("%d ",a[i][j]);
            }
        }
    }
    printf("\n\nFirst Angle Diagonal Sum = %d\n\n",sum);

    sum = 0;
    /// Second Diagonal Sum.

    for(int i = 0; i < n; i++)
    {
        for(int j = n - i - 1; j < n - i ; j++)
        {
            sum += a[i][j];
            printf("%d ",a[i][j]);
        }
    }
    printf("\n\nSecond Angle Diagonal Sum = %d\n",sum);

    return 0;
}
