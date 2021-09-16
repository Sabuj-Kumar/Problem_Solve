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
#define sl( n ) scanf("%I64d",&n)
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

int main(){

    file();

    int t = I();

    while( t-- ){

        int n = I();
        int a[ n + 5 ];
        int x = -1,y = -1,z = -1;
        bool flag = false;

        for(int i = 0; i < n; i++) a[ i ] = I();

        for(int i = 1; i < n-1; i++){

            if(a[ i - 1 ] < a[ i ] and a[ i ] > a[ i + 1 ]){

                x = i;
                y = i + 1;
                z = i + 2;
                break;
            }
        }
        if(x != -1){

            cout << "YES" << endl;
            cout << x << " " << y << " " << z << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
