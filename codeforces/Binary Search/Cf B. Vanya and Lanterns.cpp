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
#define Case( n )for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int n,l;
int a[ 1005 ];

bool okay(db x){

    for(int i = 1; i < n; i++) if( a[ i ] + 2 * x < a[ i + 1 ]) return false;

    if( x < a[ 1 ] or a[ n ] + x < l) return false;

    return true;
}
int main(){

    file();

    cin >> n >> l;

    for(int i = 1; i <= n; i++) cin >> a[ i ];
    sort(a+1,a+n+1);

    db lf = 0,rt = l,mid = 0;

    for(int i = 0; i < 50; i++){

        mid = (rt + lf) / 2.0;

        if( okay( mid ) ) rt = mid;
        else lf = mid;
    }

    cout << fixed << setprecision(10) << rt << endl;

    return 0;
}
