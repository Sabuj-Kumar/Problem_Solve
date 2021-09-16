#include<bits/stdc++.h>

using namespace std;

int main(){

    string s;

    cin >> s;

    int c1 = 0,c2 = 0;

    for(int i = 0; i < s.size(); i++){

        if(s[ i ] == '0') c1++;

        else c1 = 0;

        if(s[ i ] == '1') c2++;

        else c2 = 0;

        if(c1 == 7 || c2 == 7) break;
    }

    if(c1 == 7 || c2 == 7) cout << "YES\n";

    else cout << "NO\n";

    return 0;
}
