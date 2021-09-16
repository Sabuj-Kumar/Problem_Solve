#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

long long GCD(long long a,long long b)
{
    if(b == 0) return a;

    return GCD(b,a%b);
}
int main()
{
    int test;

    cin >> test;

    getchar();

    while(test--)
    {
        string input;
        int i = 0,j = 0,k = 0;
        long long a[ 101 ] = { 0 },gcd = 0,max_ = -1;

        getline(cin,input);

        while(i < input.size())
        {
            long long s = 0;

            while(input[ i ] != ' ' && i != input.length())
            {
                s = s * 10 + input[ i ] - 48;

                if(input[ i+1 ] == ' ' || (i+1) == input.length())
                {
                    a[ j ] = s;
                    j++;
                }
                i++;
            }
            i++;
        }

        sort(a,a+j);

        for(i = 0; i < j; i++)
        {
            for(k = i+1; k < j; k++)
            {
                gcd = GCD(a[ k ],a[ i ]);

                if( max_ < gcd )
                   max_ = gcd;
            }
        }

        cout << max_ << endl;
        input.clear();
    }
    return 0;
}

