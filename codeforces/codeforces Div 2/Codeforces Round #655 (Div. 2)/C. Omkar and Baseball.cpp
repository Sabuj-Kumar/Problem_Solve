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

        int cnt = 0,v[ n + 5 ];
        bool a = true,b = true,flag = true;

        for(int i = 0; i < n; i++){

            v[ i ] = I();
            v[ i ]--;

            if(v[ i ] == i) cnt++;
            else flag = false;
        }

        if(flag) { puts("0"); continue; }

        for(int i = 0; i < n; i++){

            if(v[ i ] == i) cnt--;
            else break;
        }

        for(int i = n-1; i >= 0; i--){

            if(v[ i ] == i) cnt--;
            else break;
        }

        if(cnt) puts("2");
        else puts("1");
    }
    return 0;
}
