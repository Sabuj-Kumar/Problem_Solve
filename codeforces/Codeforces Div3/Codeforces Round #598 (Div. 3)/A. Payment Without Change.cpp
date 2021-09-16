#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll sc() { ll n; cin >> n; return n; }
void pf() { printf("YES\n"); }
void pf_() { printf("NO\n"); }

void file(){

    #ifndef ONLINE_JUDGE

    freopen("input.txt","r",stdin);

    #endif // ONLINE_JUDGE

}
int main(){

    file();

    int test = sc();

    for(int i = 1; i <= test; i++){

        ll a = sc(),b = sc(),n = sc(),s = sc();

        if((a * n) + b >= s){

            if(a * n <= s){

                s -= a * n;
                if(s - b <= 0) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            else {

                int m = s / n;
                s -= m * n;
                if(s - b <= 0) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
        else cout << "NO" << endl;
    }
    return 0;
}
