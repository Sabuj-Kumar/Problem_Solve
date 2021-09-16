#include<bits/stdc++.h>

using namespace std;

int z[ 100010 ];

void Z_Algo(string s){

    int l = 0,r = 0;

    //cout << s << endl;

    for(int i = 1; i < s.size(); i++){

        if(i > r){

            l = r = i;

            while( r < s.size() && s[ r ] == s[ r - l]) r++;

            z[ i ] = r - l;

            r--;
        }
        else {

            int k = i - l;

            if(z[ k ] < r - i + 1) z[ i ] = z[ k ];

            else {

                l = i;

                while( r < s.size() && s[ r ] == s[ r - l]) r++;

                z[ i ] = r - l;

                r--;
            }
        }
    }
}
int main(){

    //freopen("input.txt","r",stdin);

    string s,c,s1;

    cin >> c >> s;

    s1 = c;

    c += '$';

    c += s;

    Z_Algo( c );

    int count_ = 0;

    for(int i = 0; i < c.size(); i++) if(z[ i ] == s1.size()) count_++;

    cout << count_ << endl;

    return 0;
}


