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

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main(){

    file();

    int t,n,m;
    string s,p;

    cin >> t;

    while(t--){

        unordered_map<  char,int > magazine,mp;
        cin >> s;
        cin >> p;

        n = s.size();
        m = p.size();

        for(int i = 0; i < n; i++) magazine[ s[ i ] ] = 1;

        for(int i = 0; i < m; i++) mp[ p[ i ] ] = 1;

        bool flag = false;

        for(int i = 0; i < m; i++){

            if(magazine[ p[ i ] ] == 1 and mp[ p[ i ] ] == 1){

                flag = true;
                break;
            }
        }

        if( flag ) cout <<"YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

