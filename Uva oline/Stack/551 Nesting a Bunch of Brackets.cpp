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

bool opening(char ch){

    if(ch == '(' or ch == '{' or ch == '[' or ch == '<') return true;

    return false;
}

bool closing(char ch){

    if(ch == ')' or ch == '}' or ch == ']' or ch == '>') return true;

    return false;
}
int main(){

    file();

    string s;

    while(cin >> s){

        int cnt = 0,i;
        int n = s.size();

        stack< char > st;

        for(i = 0; i < n; i++){

            cnt++;

            if(opening(s[ i ])){

                if(s[ i ] == '(' and s[ i + 1 ] == '*'){

                    st.push('*');
                    i++;
                    continue;
                }
                st.push(s[ i ]);
            }
            else if(closing(s[ i ]) or s[ i ] == '*' and s[ i + 1 ] == ')'){

                if(st.empty()) break;

                if(s[ i ] == '*'){

                    if(st.top() != '*') break;

                    i++;

                    st.pop();
                }
                else if(s[ i ] == ')'){

                    if(st.top() != '(') break;

                    st.pop();
                }
                else if(s[ i ] == '}'){

                    if(st.top() != '{') break;

                    st.pop();
                }
                else if(s[ i ] == ']'){

                    if(st.top() != '[') break;

                    st.pop();
                }
                else if(s[ i ] == '>'){

                    if(st.top() != '<') break;

                    st.pop();
                }
            }
        }

        if(i < n or !st.empty()){

            if(i == n and !st.empty())cnt++;

            cout << "NO" << " " << cnt << endl;
        }
        else cout << "YES" << endl;
    }
    return 0;
}
