#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector< long long > v;

    for(int i = 0; i < n; i++){

        long long a;

        cin >> a;

        v.push_back(a);
    }

    sort(v.rbegin(),v.rend());

    long long ans = 1,mul = 1;

    for(int i = 0; i < n; i++){

        mul *= v[ i ];

        ans += mul;
    }

    cout << ans << endl;

    return 0;
}

