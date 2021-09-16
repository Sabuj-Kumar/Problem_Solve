#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    //freopen("in.txt","r",stdin);

    int t;

    cin >> t;

    while(t--){

        int n,x1,y1,x2,y2;
        bool flag = true;

        cin >> n;

        string s[ n ];

        for(int i = 0; i < n; i++){

            cin >> s[ i ];

            for(int j = 0; j < n; j++){

                if(s[ i ][ j ] == '*' and flag){

                    x1 = i;
                    y1 = j;
                    flag = false;
                }
                else if(s[ i ][ j ] == '*'){

                    x2 = i;
                    y2 = j;
                }
            }
        }


        if(x1 == x2){

            if(x1 + 1 < n) s[ x1 + 1 ][ y1 ] = s[ x1 + 1 ][ y2 ] = '*';
            else s[ x1 - 1 ][ y1 ] = s[ x1 - 1 ][ y2 ] = '*';
        }
        else if(y1 == y2){

            if(y1 + 1 < n) s[ x1 ][ y1 + 1 ] = s[ x2 ][ y1 + 1 ] = '*';
            else s[ x1 ][ y1 - 1 ] = s[ x2 ][ y1 - 1 ] = '*';
        }
        else s[ x1 ][ y2 ] = s[ x2 ][ y1 ] = '*';

        for(int i = 0; i < n; i++) cout << s[ i ] << endl;
    }

    return 0;
}

