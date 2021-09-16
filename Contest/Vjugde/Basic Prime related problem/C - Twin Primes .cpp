#include<stdio.h>
#include<bits/stdc++.h>
#include<math.h>
#include<algorithm>
#define n 20000100

using namespace std;

long long a[ n ];

map<int,pair<long long,long long> > mp;

map<int,pair<long long,long long> > :: iterator it;

void Twin_Prime()
{
    int input;
    long long i,j = 0;

    for(input = 1; input < 100010; input++)
    {
        for(i = j; i <= n; i++)
        {
            if(a[ i ] == 0  && a[ i+2 ] == 0)
            {
                mp.insert(make_pair(input,make_pair(i,i+2)));
                j = i+2;
                break;
            }
        }
    }
}
void seive()
{
    long long i,j,root = sqrt(n);

    a[ 0 ] = 1;
    a[ 1 ] = 1;

    for(i = 4; i <= n; i += 2)
        a[ i ] = 1;

    for(i = 3; i <= root; i += 2)
       if(a[ i ] == 0)
          for(j = i*i; j <= n; j += i)
            a[ j ] = 1;

    Twin_Prime();
}
int main()
{
    seive();

    int input;

    while(scanf("%d",&input) == 1)
    {
        it = mp.find(input);

        cout << "("<< it->second.first << ", " <<it->second.second << ")" << endl;
    }
    mp.clear();

    return 0;
}
