#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    //freopen("in.txt","r",stdin);

    int t;

    scanf("%d",&t);

    while(t--){

        int n,m,cnt = 0;

        scanf("%d %d",&n,&m);

        string s[ n + 5 ];

        for(int i = 0; i < n; i++) cin >> s[ i ];

        if(n == 1 or m == 1){

            if(n == 1){

                for(int i = 0; i < m; i++){

                    if(s[ n - 1 ][ i ] == 'C') break;
                    if(s[ n - 1 ][ i ] == 'D') cnt++;

                }
            }
            else{

                for(int i = 0; i < n; i++){

                    if(s[ i ][ m - 1 ] == 'C') break;
                    if(s[ i ][ m - 1 ] == 'R') cnt++;
                }
            }
        }
        else{

            for(int i = 0; i < m; i++) {

                if(s[ n - 1 ][ i ] == 'C') break;
                if(s[ n - 1 ][ i ] == 'D') cnt++;
            }
            for(int i = 0; i < n; i++) {

                if(s[ i ][ m-1 ] == 'C') break;
                if(s[ i ][ m - 1 ] == 'R') cnt++;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}
