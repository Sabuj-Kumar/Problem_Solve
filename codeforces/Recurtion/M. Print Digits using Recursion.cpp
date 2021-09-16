#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int flag = 0;

void digit(long long N)
{
    int mod;

    if(N == 0)
      return;

    mod = N % 10;

    digit(N/10);

    if(flag == 0)
    {
         printf("%d ",mod);
         flag = 1;
    }
    else if(flag == 1)
    {
        printf("%d",mod);
        flag = 2;
    }
    else
        printf(" %d",mod);
}
int main()
{
    long long N,test;

    cin >> test;

    while(test--)
    {
        cin >> N;

        if(N < 10)
            cout << N << endl;

        else
        {
            digit(N);
            flag = 0;

            printf("\n");
        }
    }
    return 0;
}
