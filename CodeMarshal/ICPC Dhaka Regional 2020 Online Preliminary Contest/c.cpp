#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6 + 10;
const ll P = 1e8 + 5e4 + 1;
const ll INVP = 678791932;
const ll M = 787900005797;

ll Hash2[ N ],Hash1[ N ],pw[ N ],INV[ N ];
string s;
int ln;

void pre() {

    pw[ 0 ] = 1;

    for(int i = 1; i < N; i++){

        pw[ i ] = (P * pw[ i - 1 ]) % M;
        INV[ i ] = (INV[ i - 1 ] * INVP) % M;
    }
}

void HASH(){

    Hash1[ 0 ] = Hash2[ 0 ] = 1;

    for(int i = 0; i < ln; i++)
        Hash1[ i + 1 ] = (Hash1[ i ] * P + s[ i ]) % M;

    int j = 0;

    for(int i = ln - 1; i >= 0; i--){

        Hash2[ j + 1 ] = (Hash2[ j ] * P + s[ i ]) % M;
        j++;
    }


//    for(int i = 0; i < ln; i++){
//
//        cout << "Hash1 = " << Hash1[ i ] << endl;
//        cout << "Hash2 = " << Hash2[ i ] << endl;
//    }
}

bool Hash_Val(int l,int r){

    ll res = (Hash1[ r  ] - Hash1[ l - 1 ] * INV[ l ]) % M;
    ll res1 = (Hash2[ r ] - Hash2[ l - 1 ] * INV[ l ]) % M;

    cout << "res " << res << " res1 " << res1 << endl;

    if(res == res1) return true;

    else return false;
}

int main(){

    pre();

    freopen("in.txt","r",stdin);

    int t;

    cin >> t;

    for(int cs = 1; cs <= t; cs++){

        cin >> s;
        int q;

        ln = s.size();

        HASH();

        cin >> q;

        cout << "Case " << ": " << cs << endl;

        while(q--){

            cout << s << endl;

            int x,l,r;
            char c;

            cin >> x;

            //cout << x << endl;

            if(x == 1){

                cin >> l >> r;
                cout << "L = R"<< l << " " << r << endl;

                bool flag = Hash_Val(l-1,r-1);

                if(flag) cout << 0 << endl;

                else{

                    int cnt = 0,ind;

                    for(int i = 0; i < ln - (i + 1); i++){

                        if(s[ i ] != s[ ln - (i + 1) ]){

                            cnt++;

                            ind = i + 1;
                        }
                    }

                    if(cnt == 1) cout << ind << endl;
                    else cout << -1 << endl;
                }
            }
            else{

                cin >> l >> c;

               // cout << l << " " << c << endl;

                s[ l - 1 ] = c;

                HASH();
            }
        }
    }

    return 0;
}
