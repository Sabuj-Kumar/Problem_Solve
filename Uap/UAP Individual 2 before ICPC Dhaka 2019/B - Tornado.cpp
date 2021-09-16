#include<bits/stdc++.h>

using namespace std;

int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio( 0 );
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    while(cin >> n && n){

        int a[ n + 5 ],ans = 0,c = 0,first_sequence = 0,last_sequence = 0,f = 1,l = 1;

        for(int i = 0; i < n; i++) cin >> a[ i ];

        for(int i = 0; i < n; i++) {

            if(a[ i ] == 0) c++;

            else {

                ans += c / 2;

                c = 0;
            }

            if(f && a[ i ] == 0) first_sequence++;

            else f = 0;

            if(l && a[ n - i - 1 ] == 0) last_sequence++;

            else l = 0;
        }

        if(c != 0) ans += c / 2;

        if(first_sequence & 1 && last_sequence & 1) ans++;

        cout << ans << endl;
    }

    return 0;
}


