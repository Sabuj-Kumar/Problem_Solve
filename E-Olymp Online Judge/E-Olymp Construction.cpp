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

ll m,n,mx;
ll a[ 10010 ];

bool okay(ll v){

    ll sum = 0;

    for(int i = 0; i < n; i++)sum += a[ i ] / v;
    if(sum >= m) return true;
    return false;
}
ll Binary_Search(){

    ll l = 1,r = mx + 1,mid = 0;

    while(r - l > 1){

        mid = l + (r - l) / 2;

        if(okay( mid )) l = mid;
        else r = mid;
    }

    if(okay( l )) return l;
    if(okay( r )) return r;
    return 0;
}
int main(){

    //file();

    cin >> n >> m;
    mx = 0;

    lop(i,0,n) cin >> a[ i ],mx = max(mx,a[ i ]);

    cout << Binary_Search() << endl;

    return 0;
}
