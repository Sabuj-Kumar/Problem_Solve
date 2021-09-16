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
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; scanf("%d",&n); return n; }
ll Il() { ll n; scanf("%I64d",&n); return n; }

int main(){

    file();

    int t = I();

    while( t-- ){

        int x_y_z[ 4 ];

        x_y_z[ 0 ] = I();
        x_y_z[ 1 ] = I();
        x_y_z[ 2 ] = I();

        sort(x_y_z,x_y_z+3);

        if(x_y_z[ 1 ] != x_y_z[ 2 ]) cout << "NO" << endl;
        else {

            cout << "YES" << endl;
            cout << x_y_z[ 0 ] << " " << x_y_z[ 0 ] << " " << x_y_z[ 1 ] << endl;
        }
    }
    return 0;
}

