/**
    range minimum query sparse table O(log2(n))
**/

#include<bits/stdc++.h>
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);
using namespace std;
void file(){
    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}
struct data{
    int x,y,c;
    data(){}
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }
    bool operator < (const data &a) const{
        return c > a.c;
    }
};
const int N = 1e5 + 5;
ll sc() { ll n; scanf("%lld",&n); return n; }
ll n,q,lg;
ll node[ N ],cost[ N ];
ll table[ N ][ 25 ];
void sparse(){
    memset(table,-1,sizeof table);
    Lop(i,0,n) table[ i ][ 0 ] = node[ i ];
    for(int j = 1; (1 << j) < n; j++)
        for(int i = 0; i < n; i++)
            if(table[ i ][ j - 1 ] != -1) table[ i ][ j ] = table[ table[ i ][ j - 1 ] ][ j - 1 ];
}
ll LCA(ll u,ll cst){
    for(int i = lg; i >= 0; i--)
        if(table[ u ][ i ] != -1 and cost[ table[ u ][ i ] ] >= cst)
            u = table[ u ][ i ];
    return u;
}
int main(){
    op
    file();
    int t = sc();
    Case( t ){
        n = sc();
        q = sc();
        lg = 0;
        while((1 << (1 + lg )) <= n ) ++lg;
        node[ 0 ] = 0;
        cost[ 0 ] = 1;
        Lop(i,1,n){
            node[ i ] = sc();
            cost[ i ] = sc();
        }
        sparse();
        printf("Case %d:\n",cs);
        while( q-- ){
            ll p = sc();
            ll v = sc();
            printf("%lld\n",LCA(p,v));
        }
    }
    return 0;
}
