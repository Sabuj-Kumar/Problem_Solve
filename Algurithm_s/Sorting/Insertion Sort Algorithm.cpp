#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int Insertion_Sort(int a[],int n)
{
    int i,j,key;

    for(i = 1; i < n; i++)
    {
        key = a[ i ];

        j = i - 1;

        while(j >= 0 &&  a[ j ] > key)
        {
            a[ j + 1] = a[ j ];
            j--;
        }
        a[ j + 1] = key;
    }
}
int main()
{
    int n,i;

    scanf("%d",&n);

    int a[ n ];

    for(i = 0; i < n; i++)
        scanf("%d",&a[ i ]);

    Insertion_Sort(a,n);

    for(i = 0; i < n; i++)
        printf("%d ",a[ i ]);

    return 0;
}
