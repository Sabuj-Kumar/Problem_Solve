#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    freopen("in.txt","r",stdin);

    int t;

    cin >> t;

    while(t--){

        int a,b;

        cin >> a >> b;

        string s;

        cin >> s;

        int n = s.size();

        bool ok = true;

        for(int i = 0; i <= n - i - 1; i++){

            if(s[ i ] == '?' and s[ n - i - 1 ] == '?') continue;

            if(s[ i ] != '?' and s[ n - i - 1 ] != '?' and s[ i ] != s[ n - i - 1 ]){

                ok = false;

                break;
            }

            char c = s[ i ] == '?' ? s[ n - i - 1 ] : s[ i ];

            s[ i ] = s[ n - i - 1 ] = c;

            c == '0' ? a -= ((i == n - i - 1) ? 1 : 2) : b -= ((i == n - i - 1 ) ? 1 : 2);
        }

        for(int i = 0; i < n; i++){

            if(s[ i ] != '?') continue;

            if(i == n - i - 1){

                if( a ){

                    s[ i ] = '0';
                    a--;
                }
                else{

                    s[ i ] = '1';
                    b--;
                }
            }
            else{

                if(a >= 2){

                    s[ i ] = s[ n - i - 1 ] = '0';
                    a -= 2;
                }
                else{

                    s[ i ] = s[ n - i - 1 ] = '1';
                    b -= 2;
                }
            }
        }

        ok &= (a == 0 and b == 0 and count(s.begin(),s.end(),'?') == 0);

        if( ok ) cout << s << endl;
        else cout << -1 << endl;
    }
    return 0;
}

