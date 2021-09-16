#include<bits/stdc++.h>

using namespace std;

vector< int > graph[ 100 ];

int gray = 1,white = 2;
int vis[ 10 ];
bool flag;
vector< int > topsort;

void DFS(int n){

    vis[ n ] = gray;

    for(auto x : graph[ n ]){

        if(!vis[ x ]) DFS( x );

        else if(vis[ x ] == gray and vis[ n ] == gray){

            flag = true;
        }
    }

    vis[ n ] = white;

    topsort.push_back( n );
}
int main(){

    //freopen("in.txt","r",stdin);
    string s;

    while(cin >> s){

        int a = s[ 0 ] - 65,c = s[ 2 ] -  65;
        char b = s[ 1 ];

        if(b == '<') graph[ a ].push_back( c );

        else graph[ c ].push_back( a );
    }

    for(int i = 0; i < 5; i++){

        if(vis[ i ] == 0) DFS( i );
    }

    if(flag) cout << "impossible" << endl;

    else{

        int sz = topsort.size() - 1;

        for(int i = sz; i >= 0; i--){

            char ch = topsort[ i ] + 65;

            cout << ch;
        }
    }

    cout << endl;

    return 0;
}
