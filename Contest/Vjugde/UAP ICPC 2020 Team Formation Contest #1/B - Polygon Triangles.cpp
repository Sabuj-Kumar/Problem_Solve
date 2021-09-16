#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    bool flag = true;

    for(int i = 0; i < n; i++){

        int a[ 3 ];

        for(int j = 0; j < 3; j++) cin >> a[ j ];

        sort(a,a+3);

        if(a[ 0 ] + a[ 1 ] <= a[ 2 ]) flag = false;
    }

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
