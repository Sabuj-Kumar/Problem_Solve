#include<bits/stdc++.h>

using namespace std;

int GCD(int a,int b)
{
    if(b == 0) return a;

    return GCD( b,a%b );
}
int main()
{
    int i,j,N;

   // freopen("input.txt","r",stdin);

    while(cin >> N && N != 0)
    {
        int sum = 0;

        for(i = 1; i <= N; i++)
        {
            for(j = i+1; j <= N; j++)
            {
                sum += GCD(i,j);
            }
        }
        cout << sum << endl;
    }
    return 0;
}
