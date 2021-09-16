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
#define sc( n ) scanf("%d",&n);
#define sl( n ) scanf("%lld",&n);
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

const int N = 31300;
ll ar[ N ],digit[ N ],cum[ N ];
int idx;

ll dig(ll n){

    ll d = 0;

    while( n ){

        n /= 10;
        d++;
    }
    return d;
}
void func(){

    ll sum = 0;

    for(int i = 1; i <= N; i++){

        digit[ i ] = dig( i );

        sum  += digit[ i ];

        cum[ i ] = cum[ i - 1 ] + sum;
    }
}

int Search(ll n){

    int lf = 1,rt = N + 10;

    while(rt >= lf){

        int mid = (rt + lf) / 2;

        if(cum[ mid ] <= n) lf = mid + 1;

        else rt = mid - 1;
    }
    return rt;
}
int main(){

    func();

    file();

    int t = I();


    while( t-- ) {

        ll a = Il();

        int i = Search( a );

        if(cum[ i ] == a) cout << (i % 10) << endl;
        else {

            ll c = cum[ i ];

            for(int j = 1; j <= N; j++){

                c += digit[ j ];

                if(c == a){ cout << (j % 10) << endl; break; }
                else if(c > a) {

                    int x = c - a;
                    int k = j;

                    while( x ) { k /= 10; x--; }

                    cout << (k % 10) << endl; break;
                }
            }
        }
    }
    return 0;
}
