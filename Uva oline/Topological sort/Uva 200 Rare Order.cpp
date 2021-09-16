#include<bits/stdc++.h>

using namespace std;

vector< char > graph[ 200 ];
bool vis[ 200 ],ck[ 200 ];
stack< char > st;

void DFS(char n){

    if(vis[ n ]) return;

    vis[ n ] = true;

    for(auto x : graph[ n ]) DFS( x );

    st.push( n );
}
int main(){

    //freopen("input.txt","r",stdin);

    string s,p;

    for(int i = 0; i < 200; i++) graph[ i ].clear();

    cin >> s;

    while(cin >> p){

        if(p == "#") break;

        for(int i = 0; i < min(s.size(),p.size()); i++) {

            if(s[ i ] != p[ i ]){

                ck[ s[ i ] ] = true;

                graph[ s[ i ]  ].push_back( p[ i ] );

                break;
            }
        }

        s = p;
    }

    for(char i = 'A'; i <= 'Z'; i++)
        if(vis[ i ] == false and ck[ i ] == true)
            DFS( i );

    while(!st.empty()){

        char ch = st.top();

        st.pop();

        cout << ch;
    }

    cout << endl;

    return 0;
}
