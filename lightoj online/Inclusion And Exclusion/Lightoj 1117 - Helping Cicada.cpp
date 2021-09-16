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

ll m,n,ans;
ll a[ 20 ];

ll lcm(ll a,ll b){

    return (a * b) / __gcd(a,b);
}
void Inclusion_Exclusion(int idx,ll lm,ll num){

    if (idx == m) {

        if (num == 0) return;
        if (num & 1) ans += (n / lm);
        else ans -= (n / lm);
        return;
    }
    Inclusion_Exclusion(idx + 1, lm, num);
    Inclusion_Exclusion(idx + 1, lcm(lm,a[ idx ]), num + 1);
}
int main(){

    op
    file();

    int t;

    cin >> t;

    Case( t ){

        cin >> n >> m;

        for(int i = 0; i < m; i++) cin >> a[ i ];

        ans = 0;

        Inclusion_Exclusion(0,1,0);

        cout << "Case " << cs << ": " << n-abs(ans) << endl;
    }
    return 0;
}
