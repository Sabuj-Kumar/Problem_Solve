#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define f first
#define s second
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

vector< int > v,dp,path;
int sz;

int LIS(int i){

    if(dp[ i ] != -1) return dp[ i ];

    int ans = 0;

    for(int j = i + 1; j < sz; j++){

        if(v[ j ] > v[ i ]){

            int temp = LIS( j );

            if(temp > ans){

                ans = temp;

                path[ i ] = j;
            }
        }
    }
    return dp[ i ] = ans + 1;
}

int main(){

    file();

    int t;

    sc( t );
    getchar();
    getchar();

    while( t-- ){

        int n;

        v.clear();
        string s;
        while(getline(cin,s) and s != "") {

            stringstream ss( s );
            ss >> n;
            v.pb( n );
        }
        sz = v.size();

        vector< int > ans;

        dp.assign(sz,0);
        path.assign(sz,0);
        for(int i = 0; i < sz; i++){

            dp[ i ] = -1;
            path[ i ] = -1;
        }

        int lis = 0,start = 0;
        for(int i = 0; i < sz; i++){

            int temp = LIS( i );

            if(temp > lis){

                lis = temp;
                start = i;
            }
        }

        cout << "Max hits: " << lis << endl;

        while(start != -1){

            ans.pb( v[ start ] );
            start = path[ start ];
        }
        for(int i = 0; i < lis; i++) cout << ans[ i ] << endl;
        if( t ) puts("");
    }

    return 0;
}

