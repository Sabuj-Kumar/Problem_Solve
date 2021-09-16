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

string s,p;
ll len,sz,pz;
ll dp[ 35 ][ 35 ],dp1[ 70 ][ 35 ][ 35 ];

ll LCS(ll i,ll j){

    if(i >= sz && j < pz) {

        return pz - j;
    }
    if(j >= pz && i < sz) {

        return sz - i;
    }
    if(i == sz && j == pz) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    ll mn = 1e9;

    if(s[ i ] == p[ j ]) mn = min(mn,LCS(i + 1,j + 1));

    mn = min(mn,LCS(i + 1,j));
    mn = min(mn,LCS(i,j + 1));

    return dp[ i ][ j ] = mn + 1;
}

ll count_(ll ln,ll i,ll j){

    if(ln < 0) return 0;

    if(i == sz && j == pz){

        if(ln == 0) return 1;
        return 0;
    }
    if(i == sz){

        if(ln == (pz - j)) return 1;
        return 0;
    }
    if(j == pz){

        if( ln == (sz - i)) return 1;
        return 0;
    }

    if(dp1[ ln ][ i ][ j ] != -1) return dp1[ ln ][ i ][ j ];

    ll ans = 0;

    if(s[ i ] == p[ j ]) {

        ans = count_(ln - 1,i + 1,j + 1);

        return dp1[ ln ][ i ][ j ] = ans;
    }

    ans = count_(ln - 1,i + 1,j) + count_(ln - 1,i,j + 1);

    return dp1[ ln ][ i ][ j ] = ans;
}
int main(){

    op;
    file();
    int n;

    cin >> n;

    Case( n ){

        cin >> s;
        cin >> p;

        sz = s.size();
        pz = p.size();

        memset(dp,-1,sizeof dp);
        memset(dp1,-1,sizeof dp1);

        ll ln = LCS(0,0);

        len = count_(ln,0,0);

        cout << "Case "<< cs << ": " << ln << " " << len << endl;
    }
    return 0;
}
