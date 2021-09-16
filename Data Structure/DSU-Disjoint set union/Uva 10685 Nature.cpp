#include<bits/stdc++.h>

using namespace std;

int p[ 5010 ];
int r[ 5010 ];
int mx;

map< int,int > mc;

void set_(int n){

    for(int i = 1; i <= n; i++) r[ i ] = 1,p[ i ] = i;
}
int search_parent(int n){

    return p[ n ] == n ?  n : p[ n ] = search_parent( p[ n ] );
}

void set_parent(int n,int m){

    n = search_parent( n );
    m = search_parent( m );

    if(n == m) return;

    p[ m ] = n;

    r[ n ] += r[ m ];

    //mx = max(mx,r[ n ]);
}
int main(){

    //freopen("input.txt","r",stdin);

    int n,m,f = 0;

    while(cin >> n >> m){

        if(n == 0) break;

        set_( n );

        map< string,int > mp;

        int a = n,c = 0;

        while(n--){

            string s;

            cin >> s;

            mp[ s ] = ++c;
        }

        mx = 0;

        while(m--){

            string s,s1;

            cin >> s >> s1;

            set_parent(mp[ s ],mp[ s1 ]);
        }

        for(int i = 1; i <= a; i++){

            if(r[ i ] > mx) mx = r[ i ];
        }
        cout << mx << endl;
    }

    return 0;
}
