#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
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

string s;

int main(){

    file();

    while(getline(cin,s)){

        stack< ll > st;

        cout << s << endl;

        for(int i = 0; i < s.size(); i++){

            if(s[ i ] >= '0' and s[ i ] <= '9'){

                ll v = 0;
                bool flag = false;

                if(s[ i - 1 ] == '-') flag = true;

                for(;i < s.size(); i++){

                    if(s[ i ] >= '0' and s[ i ] <= '9'){

                        v *= 10;

                        v += (s[ i ] - '0');
                    }
                    else break;
                }

                cout << v << " ";

                if(flag) st.push( v );
                else if(st.top() == v) st.pop();
                else break;

                flag = false;
            }
        }

        cout << endl;

        if(st.empty()) cout << ":-) Matrioshka!" << endl;
        else cout << ":-( Try again." << endl;
    }
    return 0;
}
