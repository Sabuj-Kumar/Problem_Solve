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
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

ll phi(ll n){

    if(n == 1) return 1;

    ll result = n;

    if(n % 2 == 0){

        result -= result / 2;

        while(n % 2 == 0) n /= 2;
    }

    for(ll i = 3; i * i <= n; i += 2){

        if(n % i == 0){

            result -= result / i;

            while(n % i == 0) n /= i;
        }
    }

    if(n > 1) result -= result / n;

    return result;
}
int main(){

    file();

    ll n;

    while(cin >> n and n) cout << phi( n ) << endl;

    return 0;
}
