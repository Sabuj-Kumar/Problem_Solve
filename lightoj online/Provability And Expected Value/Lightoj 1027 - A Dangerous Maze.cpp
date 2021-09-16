#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long long double
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

ll x,n,dp[ 30 ][ 300 ];

int gcd(int a,int b){

    if(b == 0) return a;
    return gcd(b,a%b);
}
ll way(int num,ll sum){

    if(num == n) return sum >= x;

    if(dp[ num ][ sum ] != -1) return dp[ num ][ sum ];

    ll  p = 0;

    for(ll i = 1; i <= 6; i++) p += way(num+1,sum + i);

    return dp[ num ][ sum ] = p;
}
int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        int cnt = 0;
        int sum = 0;

        cin >> n;

        for(int i = 0; i < n; i++){

            cin >> x;

            sum += abs( x );

            if(x > 0) cnt++;
        }

        cout << "Case " << cs << ": ";

        if(cnt == 0) cout << "inf" << endl;

        else {

            int g = gcd(sum,cnt);

            int a = sum / g;
            int b = cnt / g;

            cout << a << "/" << b << endl;
        }
    }

    return 0;
}


