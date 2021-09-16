#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair<ll,ll >
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

int I()  { int n; sc( n ); return n; }
int Il() { ll  n; sl( n ); return n; }


int main(){

   // file();

    int t;

    cin >> t;

    while(t--){

        int cnt = 0,n;
        bool flag = false;

        cin >> n;

        int a[ n + 1 ];

        for(int i = 1; i <= n; i++) cin >> a[ i ];

        for(int i = n; i >= 1; i--){

            if(a[ i ] != i){

                if(a[ i - 1 ] == i){

                    cnt++;
                    swap(a[ i - 1 ],a[ i ]);
                }
                else if(a[ i - 2 ] == i){

                    cnt += 2;

                    a[ i - 2 ] = a[ i - 1 ];
                    a[ i - 1 ] = a[ i ];
                    a[ i ] = i;
                }
                else {

                    flag = true;
                    cout << "Too chaotic\n";
                    break;
                }
            }
        }
        if(!flag) cout << cnt << endl;


//        for(int i = 1; i <= n; i++) cout << a[ i ] << " ";
//        cout << endl;
    }
    return 0;
}
