#include<bits/stdc++.h>

using namespace std;

int z[ 1000010 ];

int Z_Algo(string s){

    int L = 0,R = 0,max_ = 0;

    for(int i = 1; i < s.size(); i++){

        if( i > R ){

            L = R = i;

            while(R < s.size() && s[ R ] == s[ R - L ]) R++;

            z[ i ] =  R - L;

            R--;
        }
        else{

            int k = i - L;

            if(z[ k ] < R - i + 1 ) z[ i ] = z[ k ];

            else {

                L = i;

                while(R < s.size() && s[ R ] == s[ R - L ]) R++;

                z[ i ] = R - L;

                R--;
            }
        }

        if(max_ < z[ i ]) max_ = z[ i ];
    }

    return max_;
}
int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    string s;

    cin >> s;

    int c = 0,mx = Z_Algo( s );

    if(mx == 0){

        cout << "Just a legend" << endl;

        return 0;
    }

    for(int i = 0; i < s.size(); i++) if(mx == z[ i ]) c++;

    string ch_first = "",ch_end = "";

    for(int i = 0; i < mx; i++) ch_first += s[ i ];
    for(int i = s.size() - mx; i < s.size(); i++) ch_end += s[ i ];

    if(c >= 2 && ch_first == ch_end) cout << ch_first << endl;

    else cout << "Just a legend" << endl;

    return 0;
}
