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
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main(){

    op;
    file();

    int t;
    cin >> t;

    while( t-- ){

        int n;
        string s;
        vector< int > ans;

        cin >> n;
        cin >> s;

        int mx = INT_MIN,on = 0,zro = 0;

        for(int i = 0; i < n; i++){

            if(s[ i ] == '1'){

                on++;

                if(zro){

                    ans.pb( zro );
                    zro--;
                }
                else ans.pb( on );
            }
            else{

                zro++;

                ans.pb( zro );

                if( on ) on--;
            }
            mx = max(mx,max(on,zro));
        }

        cout << mx << endl;

        for(int i = 0; i < n; i++) {

            if(i > 0) cout << " ";

            cout << ans[ i ];
        }
        cout << endl;
    }

    return 0;
}
