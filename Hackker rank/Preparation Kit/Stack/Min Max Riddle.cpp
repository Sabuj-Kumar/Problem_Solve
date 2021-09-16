/**
    Sabuj Kumar Tarofdar
    17101139
    University Of Asia Pacific
**/

#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsinged long long
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

    //file();

    int n;

    stack< int > st;

    cin >> n;

    int a[ n ],lf[ n ],rt[ n ],ans[ n + 1 ];

    for(int i = 0; i < n; i++) cin >> a[ i ];

    for(int i = 0; i < n; i++){

        lf[ i ] = -1;
        rt[ i ] = n;
    }

    for(int i = 0; i < n; i++){

        while(!st.empty() and a[ st.top() ] >= a[ i ]) { st.pop(); }

        if(!st.empty()) lf[ i ] = st.top();

        st.push( i );
    }

    while(!st.empty()){ st.pop(); }

    for(int i = n - 1; i >= 0; i--){

        while(!st.empty() and a[ st.top() ] >= a[ i ]) { st.pop(); }

        if(!st.empty()) rt[ i ] = st.top();

        st.push( i );
    }

    memset(ans,0,sizeof(ans));

    for(int i = 0; i < n; i++){

        int ln = rt[ i ] - lf[ i ] - 1;

        ans[ ln ] = max(ans[ ln ],a[ i ]);
    }

    for(int i = n-1; i >= 1; i--) ans[ i ] = max(ans[ i ],ans[ i + 1 ]);

    for(int i = 1; i <= n; i++) cout << ans[ i ] << " ";

    cout << endl;

    return 0;
}
