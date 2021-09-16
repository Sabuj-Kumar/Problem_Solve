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

    int t = I();

    while( t-- ){

        int i,n = I(),x = I(),y = I();

        int dif = y - x;
        int dis = -1,num = 0;

        vector< int > v;

        for(i = n-1; i >= 0; i--){

            if(dif % i == 0){

                dis = dif / i;

                num = i - 1;

                break;
            }
        }

        if(dis == -1) dis = dif;

        n -= (2 + num);

        for(i = x; i <= y; i += dis) v.pb( i );

        i = x;

        while(n > 0 and i > 0){ i -= dis; if(i > 0) { v.pb( i ); n--; } }

        i = y;

        while(n > 0){ i += dis; v.pb( i ); n--; }

        for(int i = 0; i < v.size(); i++){ if(i > 0) cout << " "; cout << v[ i ]; }
        cout << endl;
    }
    return 0;
}
