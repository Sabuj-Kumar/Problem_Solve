#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
#define pb push_back
#define in freopen("in.txt","r",stdin)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int sc() { int n; scanf("%d",&n); return n; }

int main(){

    file();

    int test = sc();

    while(test--){

        int n = sc();
        vector< int > v;

        lop(i,0,2*n) v.pb( sc() );

        sort(v.begin(),v.end());
        cout << abs(v[ n ] - v[ n - 1 ]) << endl;
    }


    return 0;
}
