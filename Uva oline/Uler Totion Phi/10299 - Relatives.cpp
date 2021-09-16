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
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

ll phi(ll n){

    if(n == 1) return 0;
    if(n == 2) return 1;

    ll res = n;

    if(n % 2 == 0){

        res -= res / 2;

        while(n % 2 == 0) n /= 2;
    }

    for(ll i = 3; i * i <= n; i += 2){

        if(n % i == 0){

            res -= res / i;

            while(n % i == 0) n /= i;
        }
    }

    if( n > 1 ) res -= res / n;

    return res;
}
int main(){

    //file();
10990 Another New Function
    ll n;

    while(cin >> n and n){

       cout << phi( n ) << endl;
    }
    return 0;
}
