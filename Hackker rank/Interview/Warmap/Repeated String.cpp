#include<bits/stdc++.h>
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
#define sc scanf("%d",&n)
#define sl scanf("%lld",&n)
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

int main(){

    //file();

    string s;
    ll cnt = 0,n;

    cin >> s;

    cin >> n;

    ll ln = s.size();

    ll a[ ln + 1 ] = {0};

    for(int i = 0; i < ln; i++){

        if(s[ i ] == 'a') a[ i ] = 1;

        if(i == 0) continue;

        else a[ i ] += a[ i - 1 ];
    }

    if(ln >= n) cnt += a[ n - 1 ];

    else{

        ll div = n / ln;
        ll mod = n % ln;

        cnt += a[ ln - 1 ] * div;
        if(mod) cnt += a[ mod - 1 ];
    }

    cout << cnt << endl;

    return 0;
}
