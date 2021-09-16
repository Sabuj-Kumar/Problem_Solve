#include<bits/stdc++.h>

using namespace std;

int n,m;
int X[ ] = {0,0,1};
int Y[ ] = {1,-1,0};
int vis[ 1010 ][ 1010 ];
string s[ 110 ];

void DFS(int x,int y){

    if(vis[ x ][ y ]) return;

    vis[ x ][ y ] = 1;

    for(int i = 0; i < 3; i++){

        int x1 = x + X[ i ];
        int y1 = y + Y[ i ];

        if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && !vis[ x1 ][ y1 ] && s[ x1 ][ y1 ] == '0'){

            DFS(x1,y1);
        }
    }
}
int main(){

    int m,n;

    while(cin >> n >> m){

        memset(vis,0,sizeof vis);
        int flag = 0;
        for(int i = 0; i < n; i++) cin >> s[ i ];

        for(int i = 0; i < m; i++){

            if(s[ 0 ][ i ] == '0'){

                DFS(0,i);

                for(int j = 0; j < m; j++){

                    if(vis[ n - 1 ][ j ]) {

                        flag = 1;

                        break;
                    }
                }
            }
            if( flag ) break;
        }

        if( flag ) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
