#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,count_ = 0;

    cin >> n;

    for(int i = 0; i < n; i++){

        int a,b,c;

        cin >> a >> b >> c;

        if( (a == 1 && b == 1) || (a == 1 && c == 1) || (b == 1 && c == 1)) count_++;
    }

    cout << count_ << endl;

    return 0;
}
