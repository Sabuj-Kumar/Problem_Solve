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

const int N = 1e6 + 7;

int I() { int n; sc( n ); return n; }

int main(){

    file();

    char s[ N ];
    char p[ N ];

    vector< int > v[ 200 ];

    scanf("%s",s+1);

    int ln = strlen(s + 1);

    for(int i = 1; i <= ln; i++) v[ s[ i ] ].pb( i );

    int num = I();

    while( num-- ){

        scanf("%s",p + 1);

        bool flag = true;
        int val = 0,mn = 1e9,mx = 0;

        for(int i = 1; p[ i ]; i++){

            auto it = upper_bound(v[ p[ i ] ].begin(),v[ p[ i ] ].end(),val);

            if(it == v[ p[ i ] ].end()){

                flag = false;
                break;
            }

            val = *it;
            mn = min(mn,val);
            mx = max(mx,val);
        }

        if( flag ) cout << "Matched "<< mn - 1 << " " << mx - 1 << endl;
        else puts("Not matched");
    }

    return 0;
}
