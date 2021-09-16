#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
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
    in;
    #endif // ONLINE_JUDGE
}

int I( ) { int n; sc( n ); return n; }
ll Il( ) { ll  n; sl( n ); return n; }

stack< char > st;

void check_brackets(string s,int idx){

    if(idx == s.size()) return;

    if(!st.empty() and s[ idx ] == ')' and st.top() == '(') st.pop();

    else if(!st.empty() and s[ idx ] == '}' and st.top() == '{') st.pop();

    else if(!st.empty() and s[ idx ] == ']' and st.top() == '[') st.pop();

    else st.push(s[ idx ]);

    check_brackets(s,idx+1);
}
int main(){

    file();

    int n;

    cin >> n;
    cin.ignore();

    while(n--){

        string s;

        getline(cin,s);

        while(!st.empty()) st.pop();

        check_brackets(s,0);

        if(st.empty()) cout << "YES" <<endl;
        else cout << "NO" << endl;
    }

    return 0;
}
