#include<bits/stdc++.h>
#define ll long long

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
}
ll sc() { ll n; cin >> n; return n; }

int main(){

    file();
    ll test;

    test = sc();

    while(test--){

        ll v = sc(),s = sc();
        ll a[ v + 5 ];
        ll i = 0,c1 = 0,c = 0,ind = -1,sum = 0;

        for(int i = 0; i < v; i++) a[ i ] = sc();

        if(a[ 0 ] > s) i = 1,c = 1,ind = 0;
        if(a[ 0 ] > s and a[ 1 ] > s) ind = -1;

        for(;i < v; i++){

            sum += a[ i ];

            if(sum >= s){

                c1++;

                sum -= a[ i ];

                if(sum >= 0){

                    c++;
                    if(c > 1) break;
                    ind = i;
                }
            }
        }
        if(ind == -1) cout << 0 << endl;
        else if(ind + 1 != v) cout << ind+1 << endl;
        else if(ind + 1 == v) cout << 1 << endl;
    }
    return 0;
}
