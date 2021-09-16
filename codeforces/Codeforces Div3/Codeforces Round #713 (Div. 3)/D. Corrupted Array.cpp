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

int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        ll n,sum = 0;

        cin >> n;

        vector< int > v(n+2);

        for(int i = 0; i < n+2; i++) cin >> v[ i ];

        sort(v.begin(),v.end());

        sum = accumulate(v.begin(),v.end(),0ll);

        int a = -1,b = -1;

        for(int i = 0; i < n + 2; i++){

            int idx = (i == n + 1) ? n : n + 1;

            if(sum - v[ i ] - v[ idx ] == v[ idx ]){

                a = idx,b = i;
                break;
            }
        }

        if(a == -1) cout << -1 << endl;
        else{

            for(int i = 0; i < n + 2; i++){

                if(a == i or b == i) continue;

                cout << v[ i ] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
