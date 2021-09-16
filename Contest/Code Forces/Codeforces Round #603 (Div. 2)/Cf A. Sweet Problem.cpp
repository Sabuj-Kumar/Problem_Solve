#include<bits/stdc++.h>
#define in freopen("in.txt","r",stdin);

using namespace std;

int sc() { int n; scanf("%d",&n); return n; }

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}
int main(){

    file();

    int n = sc();

    while( n-- ){

        int a[ 3 ];
        for(int i = 0; i < 3; i++) a[ i ] = sc();
        sort(a,a+3);
        if(a[ 0 ] + a[ 1 ] < a[ 2 ])  cout << a[ 0 ] + a[ 1 ]<< endl;
        else cout << (a[ 0 ] + a[ 1 ]  + a[ 2 ]) / 2 << endl;
    }

    return 0;
}
