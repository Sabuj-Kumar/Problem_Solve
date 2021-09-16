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

const int N = 1e7+100;
int prime[ N ];
vector< int > v;

int main(){

    file();
    int t;

    cin >> t;

    while(t--){

        ll ans = 0,n;

        cin >> n;

        if(n == 1 or n == 2){

            if(n == 1) cout << 0 << endl;
            else cout << 1 << endl;

            continue;
        }


        for(ll i = 2; i * i <= n; i++){

            if(n % i == 0){

                if(n / i == i) ans += i;

                else ans += (i + (n / i));
            }
        }

        cout << ans + 1 << endl;
    }

    return 0;
}


