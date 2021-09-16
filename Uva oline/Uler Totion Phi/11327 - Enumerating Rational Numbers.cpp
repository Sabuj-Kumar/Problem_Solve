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
#define sl( n ) scnaf("%lld",&n)
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
const int N = 200000 + 5;

ll phi[ N ];

void pre(){

    phi[ 0 ] = 0; phi[ 1 ] = 2;

    for(ll i = 2; i < N; i++) phi[ i ] = i;

    for(ll i = 2; i < N; i++){

        if(phi[ i ] == i){

            for(ll j = i; j < N; j += i){

                phi[ j ] -= phi[ j ] / i;
            }
        }
        phi[ i ] = phi[ i ] + phi[ i - 1 ];
    }
}

ll gcd(ll a,ll b){

    while(b) { ll r = a % b; a = b; b = r; }

    return a;
}

ll B_search(ll k){

    ll l = 2,r = N-1,md = 0;

    while(l < r){

        md = (l + r) / 2;

        if(phi[ md ] < k) l = md + 1;
        else r = md;
    }

    return r;
}
int main(){

    pre();

    file();

    ll k;

    while(cin >> k and k){

        if(k == 1) { puts("0/1"); continue; }
        if(k == 2) { puts("1/1"); continue; }
        if(k == 3) { puts("1/2"); continue; }

        ll lob,hor = B_search( k );

        ll pos = k - phi[ hor - 1 ];

        for(ll i = 1; i < hor; i++){

            if(gcd(i,hor) == 1) pos--;

            if(!pos) { lob = i; break; }
        }

        printf("%lld/%lld\n",lob,hor);
    }
    return 0;
}
