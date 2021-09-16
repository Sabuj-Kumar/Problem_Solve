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

int a[ 3 ][ 3 ];

int main(){

    a[ 0 ][ 0 ] = a[ 0 ][ 1 ] = a[ 0 ][ 2 ] = a[ 1 ][ 1 ] = 1;
    a[ 2 ][ 0 ] = a[ 2 ][ 1 ] = a[ 2 ][ 2 ] = 1;

   // file();

    int matrix[ 6 ][ 6 ];

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            cin >> matrix[ i ][ j ];

    bool flag = true;
    int ans = 0,result = INT_MIN;

    for(int i = 0; i < 6; i++){

        for(int j = 0; j < 6; j++){

            ans = 0;

            for(int k = 0; k < 3; k++){

                for(int l = 0; l < 3; l++){

                    if(i + k < 6 and j + l < 6) ans += matrix[ i + k ][ j + l ] * a[ k ][ l ];
                    else {

                        ans = INT_MIN;
                        break;
                    }
                }
                if(ans == INT_MIN) break;
            }

            result = max(ans,result);
        }
    }

    cout << result << endl;

    return 0;
}
