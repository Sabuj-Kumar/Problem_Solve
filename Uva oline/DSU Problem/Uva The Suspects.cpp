#include<bits/stdc++.h>
#define mx 30010

using namespace std;

int p[ mx ];
int r[ mx ];
int a[ mx ];

void int_(int n){

    for(int i = 0; i <= n; i++){

        p[ i ] = i;
        r[ i ] = 1;
        a[ i ] = 0;
    }
}

int find_(int n){

    return p[ n ] == n ? n : p[ n ] = find_( p[ n ] );
}

void set_(int n,int m){

    int p1 = find_( n );
    int p2 = find_( m );

    if(m == 0) swap( p1,p2),swap(m,n);

    if(n == 0) p[ p2 ] = p1,r[ p1 ] += r[ p2 ];

    else{

        if(r[ p1 ] > r[ p2 ]) p[ p2 ] = p1,r[ p1 ] += r[ p2 ];

        else p[ p1 ] = p2,r[ p2 ] += r[ p1 ];
    }
}

int main(){

    int n,m,k;

    while(cin >> n >> m && n && m){

        int f = 0,x,y,c = 0;

        int_( n );

        while(m--){

            cin >> k;

            while(k--){

                cin >> y;

                if(!f) f = 1,x = y;

                else{


                }
                a[ y ] = 1;
            }
        }

        if(m == 0) cout << 1 << endl;
    }
}
