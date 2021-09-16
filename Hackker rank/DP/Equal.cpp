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

int n;
vector< ll > v;

ll solve(){

    sort(v.begin(),v.end());

    int sz = v.size();
    ll sum = INT_MAX;

    for(int i = 0; i < 3; i++){

       ll cum = 0;

        for(int j = 0; j < sz; j++){

            ll dif = v[ j ] - v[ 0 ] + i;
            cum += (dif/5) + ((dif%5)/2) + ((dif%5) % 2);
        }

        sum = min(sum,cum);
    }
    return sum;
}
int main(){

    op
    //file();

    int t;

    cin >> t;

    while(t--){

        v.clear();

        cin >> n;

        for(int i = 0; i < n; i++){

            ll a;

            cin >> a;

            v.pb( a );
        }

        cout << solve() << endl;
    }

    return 0;
}
