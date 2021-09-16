#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
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

const int N = 1e3 + 15;

vector<int> graph[ N ];
int vis[ N ];

int main(){

    op
    file();

    int n,s,a[ N ],b[ N ];

    cin >> n >> s;

    for(int i = 1; i <= n; i++) cin >> a[ i ];
    for(int i = 1; i <= n; i++) cin >> b[ i ];

    if(!a[ 1 ]) cout << "NO\n";
    else if(a[ 1 ] and a[ s ]) cout << "YES\n";
    else if(!b[ s ]) cout << "NO\n";
    else{

        for(int i = s + 1; i <= n; i++){

            if(a[ 1 ] and a[ i ] and b[ i ] and b[ s ]) {

                cout << "YES\n";
                return 0;
            }
        }
        cout << "NO\n";
    }

    return 0;
}
