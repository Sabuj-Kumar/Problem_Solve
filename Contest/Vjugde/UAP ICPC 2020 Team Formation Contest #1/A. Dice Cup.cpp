#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,m;

    cin >> n >> m;

    if(n == m)  cout << n + 1 << endl;

    else {

        if(m < n) swap(n,m);

        for(int i = n; i <= m; i++){

            cout << i + 1 << endl;
        }
    }
    return 0;
}
