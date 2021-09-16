#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,k;

    cin >> n >> k;

    int a[ n + 5 ],c = 0;

    for(int i = 0; i < n; i++) cin >> a[ i ];

    int v = a[ k - 1 ];

    for(int i = 0; i < n; i++) {

        if(a[ i ] != 0 && v <= a[ i ]) c++;

        else break;
    }

    cout << c << endl;

    return 0;
}
