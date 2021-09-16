#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main(){

    file();

    int n = I(),k = I();
    int ar[ n + 5 ] = {0};

    int a = I();
    ar[ 1 ] = a;

    for(int i = 2; i <= n; i++){

        a = I();
        ar[ i ] = ar[ i - 1 ] + a;
    }

    int f = -1,idx = 0,mn = INT_MAX;

    for(int i = k; i <= n; i++){

        int sum = ar[ i ] - ar[ i - k ];

        if(sum < mn){

            idx = i - k + 1;
            mn = sum;
        }
    }

    cout << idx << endl;

    return 0;
}

