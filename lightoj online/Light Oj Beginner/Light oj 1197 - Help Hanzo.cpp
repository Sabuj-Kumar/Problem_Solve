#include<bits/stdc++.h>
#include<math.h>
#define N 1000010

bool arr[ N ];

using namespace std;

vector< int > prime;

void Sieve()
{
    int i,j,root = sqrt(N);

    arr[ 0 ] = 1;
    arr[ 1 ] = 1;

    for(i = 2; i <= root; i++)
        if(arr[ i ] == 0)
           for(j = i*i; j <= N; j += i)
             arr[ j ] = 1;

    for(i = 2; i <= N; i++)
       if(arr[ i ] == 0)
          prime.push_back(i);
}
int main()
{
    Sieve();

    int test,t;

    cin >> test;

    for(t = 1; t <= test; t++)
    {
        long long a,b,count_ = 0;

        cin >> a;
        cin >> b;

        long long root,ar[ b - a + 1 ],i,j,p;

        if(a <= 1)
           a = 2;

        root = sqrt(b);

        memset(ar,0,sizeof(ar));

        for(i = 0; i <= prime.size() && prime[i] <= root; i++)
        {
            p = prime[ i ];

            j = p*p;

            if(j < a)
                j = ((a + p - 1) / p)*p;

            while(j <= b)
            {
                ar[j - a] = 1;

                j += p;
            }
        }
        for(i = a; i <= b; i++)
        {
            if(ar[ i - a ] == 0)
                count_++;
        }
        cout << "Case " << t << ": " << count_<< endl;
    }

    return 0;
}

