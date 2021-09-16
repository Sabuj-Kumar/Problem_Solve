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

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int Josephus(int n,int m){

    vector< int > v;

    for(int i = 1; i <= n; i++) v.pb( i );

    int nw = 0;

    while(v.size() > 1){

        if(v[ nw ] == 13) return 0;

        v.erase(v.begin()+nw);

        nw += (m-1);

        if(nw >= v.size()) nw = nw % v.size();
    }

    return v[ 0 ];
}
int main(){

    op
    file();

    int n;

    while(cin >> n and n){

        int ans = 0;

        if(n == 13) ans = 1;
        else for(int i = 2; ; i++){

                if(Josephus(n,i) == 13){

                    ans = i;
                    break;
                }
            }

        cout << ans << endl;
    }
    return 0;
}
