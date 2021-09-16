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
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int check(char ch){
    if(ch == '(') return 1;
    else if(ch == '-' or ch == '+') return 2;
    else return 3;
}
int main(){

    file();

    int t;

    cin >> t;
    cin.ignore();
    cin.ignore();

    while(t--){

       string s;
       char ch;

       stack<char> st;

       while(getline(cin,s) and s.size()){

            ch = s[ 0 ];

            if(ch == ' ') break;

            if(ch == '(')st.push('(');

            else if(ch == '+' or ch == '-' or ch == '*' or ch == '/'){

                while(!st.empty() and check(ch) <= check(st.top()) ){

                    cout << st.top();
                    st.pop();
                }
                st.push(ch);
            }
            else if(ch == ')'){

                while(st.top() != '('){

                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
            else cout << s;
       }
       while(!st.empty()){

            cout << st.top();
            st.pop();
       }
       cout << endl;

       if(t) cout << endl;
    }
    return 0;
}
