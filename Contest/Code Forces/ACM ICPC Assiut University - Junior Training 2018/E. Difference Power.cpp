#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long input1,input2;

    cin >> input1;
    cin >> input2;

    int a[ 40 ],i = 0;
    int b[ 40 ],j = 0;
    int c[ 40 ];

    while(input1 != 0 || input2 != 0)
    {
        if(input1 != 0)
        {
            a[ i ] = input1 % 2;
            i++;
            input1 /= 2;
        }

        if(input2 != 0)
        {
            b[ j ] = input2 % 2;
            j++;
            input2 /= 2;
        }
    }
    if(i != j)
    {
        if(i > j)
        {
            while(j != i)
            {
                b[ j ] = 0;
                j++;
            }
        }
        else
        {
            while(i != j)
            {
                a[ i ] = 0;
                i++;
            }
        }
    }

    for(i = 0; i < j; i++)
    {
        if(a[ i ] != b[ i ])
            c[ i ] = 1;
        else
            c[ i ] = 0;
    }

    return 0;
}
