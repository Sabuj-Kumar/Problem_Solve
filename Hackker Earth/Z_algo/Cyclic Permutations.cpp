#include<bits/stdc++.h>
#define ll long long

using namespace std;

void Z_Algo(string s,int z[]){

    z[ 0 ] = 0;

    int l = 0,r = 0;

    ll ln = s.length();

    for(ll i = 1; i < ln; i++){

        if(i > r){

            l = r = i;

            while( r < ln && s[ r ] == s[ r - l]) r++;

            z[ i ] = r - l;

            r--;
        }
        else {

            int k = i - l;

            if(z[ k ] < r - i + 1) z[ i ] = z[ k ];

            else {

                l = i;

                while( r < ln && s[ r ] == s[ r - l]) r++;

                z[ i ] = r - l;

                r--;
            }
        }
    }
}
ll XOR(string c,string s){

    string c1 = c +'$' + s;

    int ln = c1.length();
    int ln1 = c.length();
    int z[ ln ];

    Z_Algo( c1,z );

    ll count_ = 0;

    for(int i = 0; i < ln; i++) if(z[ i ] == ln1) count_++;

    return count_;
}
int main(){

    //freopen("int.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;

    cin >> test;

    while( test-- ){

        string c,s;

        cin >> c >> s;

        s += s.substr(0,s.length()-1);

        ll ans = XOR(c,s);

        cout << ans << endl;
    }

    return 0;
}
