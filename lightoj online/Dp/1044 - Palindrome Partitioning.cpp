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
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JDUE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e3 + 5;

bool p_table[ N ][ N ];

bool table(string s){

    int sz = s.size();

    memset(p_table,false,sizeof p_table);

    for(int i = 0; i < sz; i++) p_table[ i ][ i ] = true;

    for(int i = 0; i < sz - 1; i++) if(s[ i ] == s[ i + 1 ]) p_table[ i ][ i + 1 ] = true;

    for(int x = 3; x <= sz; x++){

        for(int i = 0; i < sz - x + 1; i++){

            int j = i + x - 1;

            if(s[ i ] == s[ j ] and p_table[ i + 1 ][ j - 1 ]){

                p_table[ i ][ j ] = true;
            }
        }
    }
}

int Partition(string s){

    int sz = s.size();

    int cuts[ sz ] = { 0 };

    for(int i = 0; i < sz; i++){

        int temp = INT_MAX;

        if(p_table[ 0 ][ i ]) cuts[ i ] = 0;
        else{

            for(int j = 0; j < i; j++)
                if(p_table[ j+1 ][ i ] and temp > cuts[ j ] + 1) temp = cuts[ j ] + 1;

            cuts[ i ] = temp;
        }
    }

    return cuts[ sz - 1 ];
}

int main(){

    op
    file();

    int t;

    cin >> t;

    Case( t ){

        string s;

        cin >> s;

        table( s );

        cout << "Case " << cs << ": " << Partition( s ) + 1<< endl;
    }
    return 0;
}
