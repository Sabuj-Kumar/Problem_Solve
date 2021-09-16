#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define f first
#define s second
#define p_b push_back
#define p_f push_front
#define in freopen("in.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

const int mx = 1e6;
vector< vector< int > > v;

int sc() { int n; scanf("%d",&n); return n; }

bool cmp( const vector<int> &a,const vector< int > &b){

    if(a[ 0 ] == b[ 0 ]){

        if(a[ 1 ] == b[ 1 ]) return a[ 2 ] < b[ 2 ];

        return a[ 1 ] < b[ 1 ];
    }
    return a[ 0 ] < b[ 0 ];
}
int main(){

    file();
    int n = sc();
    vector< vector< int > > temp( n );
    swap(temp,v);
    vector< int > out;
    bool vis[ n ];
    for(int i = 0; i < (n - 2); i++){

        for(int j = 0; j < 3; j++) v[ i ].p_b(sc());
        sort(v[ i ].begin(),v[ i ].end(),greater<int>());
    }

    sort(v.begin(),v.begin()+(n-2),cmp);
    memset(vis,0,sizeof vis);
    out.p_b(v[ n-3][ 0 ]);
    out.p_b(v[ n-3][ 1 ]);
    out.p_b(v[ n-3][ 2 ]);

    for(int i = 0; i < out.size(); i++) vis[ out[ i ] ] = 1;

    for(int i = n-3; i >= 0; i--){

        for(int j = 0; j < 3; j++){

            if(!vis[ v[ i ][ j ] ]){
                out.p_b( v[ i ][ j ]);
                vis[ v[ i ][ j ] ] = 1;
            }
        }
    }

    reverse(out.begin(),out.end());
    int m = n-2;
    for(int i = 0; i < n; i++) {

        if(i > 0) cout << " ";
        cout << out[ i ];
    }
    cout << endl;

    return 0;
}
