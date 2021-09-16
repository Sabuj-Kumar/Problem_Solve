#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;
    int sum = 0;

    unordered_map< int,int  > mp;

    for(int i = 0; i < n; i++){

        int a;

        cin >> a;

        mp[ a ]++;
    }

    for(auto x : mp){

        sum += (x.second / 2);
    }

    cout << sum << endl;

    return 0;
}
