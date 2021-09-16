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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

vector< int > v;
int n;

int check(int l,int r){

    unordered_map< int,int > mp;
    mp.clear();

    for(int i = l; i <= r; i++) mp[ v[ i ] ]++;

    for(auto x : mp){

        if(x.sd > 3 or x.sd < 3) return 0;
    }

    return 1;
}
int div_and_con(int l,int r){

    if(r - l + 1 < 3) return 0;

    int cnt1 = 1,cnt2 = 1,mid = (l + r) / 2;

    int p = div_and_con(l,mid);
    int q = div_and_con(mid,r);

    int sum = check(l,mid) + check(mid+1,r) + check(l,r);
    return p + q + sum;
}

int main(){

    file();

    cin >> n;

    for(int i = 0; i < n; i++){

        int a;

        cin >> a;

        v.pb( a );
    }

//    for(int i = 0; i < n; i++) cout << v[ i ] << " ";
//    cout << endl << endl;

    int ans = div_and_con(0,n-1);

    cout << ans << endl;

    return 0;
}
