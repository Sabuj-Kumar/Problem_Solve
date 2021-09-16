#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double

using namespace std;

int I() { int n; scanf("%d",&n); return n; }
const int N = 2 * 1e5 + 100;
bool prime[ N ];
vector< int > pm;

void seive(){

    for(int i = 4; i < N; i += 2) prime[ i ] = true;

    for(int i = 3; i * i < N; i += 2)
        if(!prime[ i ])
            for(int j = i + i; j < N; j += i)
                prime[ j ] = true;

    for(int i = 2; i * i < N; i++)
        if(!prime[ i ])
            for(int j = i + 1; i * j < N; j++)
                if(!prime[ j ])
                    pm.push_back(i * j);

    sort(pm.begin(),pm.end());
}

void solve(int n){

    if(n <= pm[ 0 ] + pm[ 1 ] + pm[ 2 ]) { cout << "NO\n"; return; }

    for(int i = 0; pm[ i ] < n; i++)
    for(int j = i + 1; pm[ i ] + pm[ j ] < n; j++)
    for(int k = j + 1; pm[ i ] + pm[ j ] + pm[ k ] < n; k++){

        int dif = n - pm[ i ] - pm[ j ] - pm[ k ];
        if(dif == pm[ i ] or dif == pm[ j ] or dif == pm[ k ]) continue;
        cout << "YES\n";
        cout << pm[ i ] << " " << pm[ j ] << " " << pm[ k ] << " " << dif << endl;
        return;
    }
    cout << "NO\n";
}
int main(){

    seive();

    //freopen("in.txt","r",stdin);

    int t = I();

    while(t--){

        int n = I();

        solve( n );
    }

    return 0;
}
