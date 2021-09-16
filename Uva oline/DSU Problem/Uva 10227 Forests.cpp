#include<bits/stdc++.h>

using namespace std;

int p[ 110 ];

void set_(int n,int m){

    if(n < m) swap( n,m );

    for(int i = 1; i <= n; i++) p[ i ] = i;
}

int search_parent(int n){

    return p[ n ] == n ? n : p[ n ] = search_parent( p[ n ] );
}

void set_parent(int n,int m){

    n = search_parent( n );
    m = search_parent( m );

    if(n != m) p[ m ] = n;
}
int main(){

    int test;

    cin >> test;

    while(test--){

        int q,t;

        cin >> q >> t;

        set_(q,t);

        cin.ignore();

        string s;

        while(getline(cin,s)){

            if(s.size( ) == 0) break;

            stringstream ss( s );

            int c,d;

            ss >> c;
            ss >> d;

            set_parent(c,d);
        }

        if(q < t) swap( q,t );

        int count_ = 0;

        for(int i = 1; i <= q; i++)
            if(p[ i ] == i) count_++;

        cout << count_ << endl;
    }
}
