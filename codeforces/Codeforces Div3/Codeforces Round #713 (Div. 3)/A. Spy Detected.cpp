#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        int a[ n ],x = -1,y = -1;

        bool f = true;

        unordered_map<int,int > mp;

        for(int i = 0; i < n; i++){

            cin >> a[ i ];

            mp[ a[ i ] ]++;

            if(i == 0) continue;

            if(a[ i - 1 ] != a[ i ] and f) {

                x = i,y = i - 1;

                f = false;
            }
        }

        if(mp[ a[ x ] ] == 1) cout << x + 1 << endl;
        else cout << y + 1 << endl;
    }
    return 0;
}
