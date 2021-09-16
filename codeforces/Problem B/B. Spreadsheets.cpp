#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main(){

    file();

    ll n;

    cin >> n;

    while( n-- ){

        ll row = 0,col = 0;

        string s,ch;

        cin >> s;

        int fg = 0;

        for(int i = 0; i < s.size(); i++){

            if(s[ i ] >= '0' and s[ i ] <= '9' and fg == 0) fg = 1;
            else if(s[ i ] == 'C' and fg == 1) { fg = 2; break; }
        }

        if(fg == 1){

            for(int i = 0; i < s.size(); i++){

                if(s[ i ] >= 'A' and s[ i ] <= 'Z'){

                    col *= 26;
                    col += s[ i ] - 'A' + 1;
                }
                else{

                    row *= 10;
                    row += s[ i ] - '0';
                }
            }

            cout << "R" << row << "C" << col << endl;
        }
        else if(fg == 2){

            ch = "";

            bool flg = true;

            for(int i = 1; i < s.size(); i++){

                if(s[ i ] != 'C' and flg) {

                    row *= 10;
                    row += s[ i ] - '0';
                }

                else {

                    if(!flg) {

                        col *= 10;
                        col += s[ i ] - '0';
                    }

                    flg = false;
                }
            }

            col--;

            while( col >= 0 ){


                ch += (col % 26) + 'A';
                col /= 26;
                col--;
            }

            reverse(ch.begin(),ch.end());
            cout << ch << row << endl;
        }
    }

    return 0;
}
