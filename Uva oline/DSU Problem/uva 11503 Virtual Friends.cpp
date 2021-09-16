#include<bits/stdc++.h>
#define mx 100010

using namespace std;

int p[ mx ];
int s[ mx ];

void set_(int n){

    for(int i = 1; i <= n; i++){

        p[ i ] = i;

        s[ i ] = 1;
    }
}

int search_parent(int n){

    return p[ n ] == n ? p[ n ] : p[ n ] = search_parent( p[ n ]);
}

int set_parent(int n,int m){

    int a = search_parent( n );
    int b = search_parent( m );

    if(a == b) return s[ a ];

    p[ b ] = a;

    s[ a ] += s[ b ];

    return s[ a ];
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;

    cin >> test;

    while(test--){

        int n,k = 0;

        cin >> n;

        set_(min(2*n,100000));

        map<string,int> mp;

        while(n--){

            string s,s1;

            cin >> s >> s1;

            if(mp[ s ] == 0) mp[ s ] = ++k;

            if(mp[ s1 ] == 0) mp[ s1 ] = ++k;

            cout << set_parent(mp[ s ],mp[ s1 ])  << endl;
        }
    }

    return 0;
}
