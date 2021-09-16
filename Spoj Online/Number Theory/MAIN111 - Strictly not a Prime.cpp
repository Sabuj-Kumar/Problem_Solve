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

const int N = 1e5 + 1;
bool prime[ N ];
vector< int > v;
int count_[ N ];

void seive(){

    prime[ 0 ] = prime[ 1 ] = 1;

    for(int i = 4; i <= N; i += 2) prime[ i ] = 1;

    for(int i = 3; i <= sqrt(N); i += 2)
        if(prime[ i ] == 0)
            for(int j = i + i; j <= N; j += i)
                prime[ j ] = 1;
}
int digit(int n){

    int len = 0;

    while(n>0){

        len++;

        v.pb(n % 10);

        n /= 10;
    }
    return len;
}
void precal(){

    memset(count_,0,sizeof count_);

    for(int n = 1; n < N; n++){

        v.clear();

        int m = digit(n);

        int sz = pow(2,m);

        reverse(v.begin(),v.end());

        int num;
        bool ok = true;

        for(int mask = 1; mask < sz; mask++){

            num = 0;

            for(int i = 0; i < m; i++)
                if(mask & (1 << i))
                    num = num * 10 + v[ i ];

            if(prime[ num ] == 0){

                ok = false;

                break;
            }
        }

        if(ok) count_[ num ] = 1;
    }

    for(int i = 2; i < N; i++) count_[ i ] += count_[ i - 1 ];
}
int main(){

    seive();
    precal();

    file();

    int t;

    cin >> t;

    while(t--){

        int a,b;

        cin >> a >> b;

        if(a > b) swap(a,b);

        cout << count_[ b ] - count_[ a - 1 ] << endl;
    }

    return 0;
}
