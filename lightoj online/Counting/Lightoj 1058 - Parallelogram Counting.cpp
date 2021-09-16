#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull usigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
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

int main(){

    file();
    int t;

    cin >> t;

    Case( t ){

        int n;

        cin >> n;

        int x[ n + 5 ],y[ n + 5 ];

        for(int i = 0; i < n; i++) cin >> x[ i ] >> y[ i ];
        vector< pii > v;

        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++){

            int a = x[ i ] + x[ j ];
            int b = y[ i ] + y[ j ];
            v.pb({a,b});
        }

        sort(v.begin(),v.end());

        ll ans = 0;

        for(int i = 0; i < v.size(); i++){

            int j = i + 1,k = 0;

            while(j < v.size() and v[ i ] == v[ j ]){

                j++,k++;
                ans += k;
            }
            i = j - 1;
        }

        cout << "Case " << cs << ": " << ans << endl;
    }
    return 0;
}
