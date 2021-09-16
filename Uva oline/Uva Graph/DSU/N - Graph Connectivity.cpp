#include<bits/stdc++.h>

using namespace std;

vector<int > graph[ 30 ];
bool vis[ 30 ];

void DFS(int n){

    if(vis[ n ]) return;

    vis[ n ] = true;

    for(auto x : graph[ n ]) DFS( x );
}
int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<char,int> mp;

    mp['A'] = 1;
    mp['B'] = 2;
    mp['C'] = 3;
    mp['D'] = 4;
    mp['E'] = 5;
    mp['F'] = 6;
    mp['G'] = 7;
    mp['H'] = 8;
    mp['I'] = 9;
    mp['J'] = 10;
    mp['K'] = 11;
    mp['L'] = 12;
    mp['M'] = 13;
    mp['N'] = 14;
    mp['O'] = 15;
    mp['P'] = 16;
    mp['Q'] = 17;
    mp['R'] = 18;
    mp['S'] = 19;
    mp['T'] = 20;
    mp['U'] = 21;
    mp['V'] = 22;
    mp['W'] = 23;
    mp['X'] = 24;
    mp['Y'] = 25;
    mp['Z'] = 26;

    int test;

    cin >> test;

    while(test--){

        int a[ 30 ][ 30 ];

        for(int i = 0; i < 30; i++) graph[ i ].clear();
        memset(vis,false,sizeof vis);
        memset(a,0,sizeof a);

        cin.ignore();

        char ch;

        cin >> ch;

        for(int i = 1; i < mp[ ch ]; i++){

            string s;

            cin >> s;

            if(a[ mp[ s[ 0 ] ] ][ mp[ s[ 1 ] ] ]) continue;

            graph[ mp[ s[ 0 ] ] ].push_back( mp[ s[ 1 ] ] );
            graph[ mp[ s[ 1 ] ] ].push_back( mp[ s[ 0 ] ] );

            a[ mp[ s[ 0 ] ] ][ mp[ s[ 1 ] ] ] = 1;
            a[ mp[ s[ 1 ] ] ][ mp[ s[ 0 ] ] ] = 1;
        }

//        for(int i = 1; i <= mp[ ch ]; i++){
//
//            cout << i << " = ";
//
//            for(auto x : graph[ i ]) cout << x << " ";
//
//            cout << endl;
//        }
//
//        cout << endl;

        int count_ = 0;

        for(int i = 1; i <= mp[ ch ]; i++){

            if(!vis[ i ]) {

                count_++;

                DFS( i );
            }
        }

        cout << count_;

        if(test - 1 >= 0) cout << "\n\n";

        else cout << "\n";

        cin.ignore();
    }

    return 0;
}
