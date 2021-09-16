/**
    Sabuj Kumar Tarofdar
    17101139
    University Of Asia Pacific
**/

#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsinged long long
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

vector< ll > v;
int sz;

void pre_cal(){

    for(ll i = 0; i < 32; i++){

        for(ll j = 0; j < 32; j++){

            ll val = pow(2,i) * pow(3,j);

            if(val > pow(2,31)) break;

            v.pb( val );
        }
    }
}

ll lower_bound_(ll n){

    int l = 0,r = sz - 1;
    ll ans = INT_MAX;

    while(l < r){

        int mid = (l + r) / 2;

        if(n > v[ mid ]){ l = mid + 1; }
        else if(n <= v[ mid ]) { ans = min(ans,v[ mid ]); r = mid; }
    }

    return ans;
}
int main(){

    pre_cal();
    sort(v.begin(),v.end());
    sz = v.size();

//    for(int i = 0; i < sz; i++) cout << v[ i ] << " ";
//    cout << endl;

    file();

    ll n;

    while(cin >> n and n){

        ll ans = lower_bound_( n );

        cout << ans << endl;
    }
    return 0;
}
