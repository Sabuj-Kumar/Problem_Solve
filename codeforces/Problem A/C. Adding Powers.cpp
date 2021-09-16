#include<bits/stdc++.h>
#define ll long long

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
}

ll I() { ll n; cin >> n; return n; }

int main(){

    file();

    ll t = I();

    while( t-- ){

        ll n = I(),k = I();
        map< ll,ll > mp;

        for(int i = 0; i < n; i++){

            ll val = I(),p = 0;

            while( val ){

                mp[ p++ ] += val % k;
                val /= k;
            }
        }

        bool v = true;

        for(auto x : mp){

            if(x.second > 1) { v = false; break; }
        }

        if( v ) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
