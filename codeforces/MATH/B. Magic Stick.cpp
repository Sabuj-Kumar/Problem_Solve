#include<bits/stdc++.h>
#define ll long long

using namespace std;

unordered_map < ll,ll > mp;

void file(){

    #ifndef ONLINE_JUDGE

    freopen("in.txt","r",stdin);

    #endif // ONLINE_JUDGE
}
bool check(ll x,ll y){

    if(x >= y) return true;

    while( 1 ){

        mp[ x ]++;

        if(!(x & 1)) x = (3 * x) / 2;

        if(x >= y) return true;

        if(x > 1 && (x & 1)) x--;

        if(mp[ x ] > 1 || x == 1) return false;
    }
}
int main(){

    file();

    int test;

    for(cin >> test; test--;){

        ll x,y;

        cin >> x >> y;
        mp.clear();

        if(check(x,y)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
