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

    //file();

    int t;

    cin >> t;

    while(t--){

        int n,T = 0,M = 0;
        bool flag = true;
        string s;

        cin >> n >> s;

        for(auto x : s){

            if(x == 'T') T++;
            else{

                M++;

                if(M > T) { flag = false; break; }
            }
        }

        if(2 * M != T) flag = false;

        if(flag){

            T = M = 0;

            for(int i = n - 1; i >= 0; i--){

                char x = s[ i ];

                if(x == 'T') T++;
                else{

                    M++;

                    if(M > T) { flag = false; break; }
                }
            }
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

