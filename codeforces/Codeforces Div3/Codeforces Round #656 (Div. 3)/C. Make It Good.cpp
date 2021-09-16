#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; scanf("%d",&n); return n; }
ll Il() { ll n; scanf("%I64d",&n); return n; }

int main(){

    file();

    int t = I();

    while( t-- ){

        int n = I();
        int v[ n + 5 ];

        for(int i = 1; i <= n; i++) v[ i ] = I();

        while(n  > 1 and v[ n ] <= v[ n - 1 ]) n--;
        while(n  > 1 and v[ n ] >= v[ n - 1 ]) n--;

        cout << n - 1 << endl;
    }
    return 0;
}
