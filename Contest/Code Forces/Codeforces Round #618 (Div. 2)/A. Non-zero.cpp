#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc1( n ) scanf("%d",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

int sc() { int n; scanf("%d",&n); return n; }

int main(){

   // freopen("in.txt","r",stdin);

    int test = sc();

    while(test--){

        int sum = 0,c = 0,n = sc();

        vector< int > v( n + 5 );

        lop(i,0,n) {

            scanf("%d",&v[ i ]);
            sum += v[ i ];

            if(v[ i ] == 0) c++;
        }

        if(sum == 0 and c == 0) cout << 1 << endl;

        else if(sum + c == 0) cout << c + 1 << endl;

        else cout << c << endl;
    }

    return 0;
}

