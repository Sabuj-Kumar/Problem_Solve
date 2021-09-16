#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,m;

    cin >> n >> m;

    int s = min(m,n);

    if(s % 2) cout << "Akshat\n";

    else cout << "Malvika\n";

    return 0;
}
