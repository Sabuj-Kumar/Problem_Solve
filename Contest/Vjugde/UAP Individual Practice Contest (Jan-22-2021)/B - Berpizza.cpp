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
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 5 * 1e5 + 20;
int a[ N ];

int main(){

    file();

    int i = 0,idx = 1,query;

    priority_queue< pii > q;

    cin >> query;

    while(query--){

        int u,n;

        cin >> n;

        if(n == 1){

            i++;

            cin >> u;

            q.push({u,-i});

        }
        else{

            if(n == 2){

                while(a[ idx ]) idx++;

                a[ idx ] = 1;

                cout << idx << " ";
            }
            else{

                while(a[ -q.top().sd ] ) q.pop();

                a[ -q.top().sd ] = 1;

                cout << -q.top().sd << " ";

                q.pop();
            }
        }
    }

    cout << endl;

    return 0;
}
