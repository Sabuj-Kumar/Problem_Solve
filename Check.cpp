#include<bits/stdc++.h>

using namespace std;

int main()
{
    long n,j,i=0,x=0,y=0;
    scanf("%d",&n);

    char a[ 32 ],rev[ 32 ];

    while (n>0)
    {
        if (n % 2 == 1)
        {
            a[ i ]='A';
            n -= 1;
        }
        else
        {
            a[ i ]='B';
            n -= 2;
        }
        i++;
        n/=2;
    }

    for(j = i - 1; j >= 0; j--) printf("%c",a[ j ]);
    printf("\n");

    return 0;
}
