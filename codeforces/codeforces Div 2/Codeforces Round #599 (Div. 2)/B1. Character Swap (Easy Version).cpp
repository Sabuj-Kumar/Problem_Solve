#include<bits/stdc++.h>
#define pii acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define p_b push_back
#define p_f push_front
#define f first
#define s second
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define lop_(i,v,n,j) for(int i = n-1; i >= 0; i -= j)
#define in freopen("input.txt","r",stdin);

using namespace std;

int sc() { int n; scanf("%d",&n); return n; }
string ss() { string ch; cin >> ch; return ch; }

int main(){

    int test = sc();

    while(test--){

        int n = sc();
        string ch = ss();
        string ch1 = ss();
        char a,b;
        map< pair< char,char > ,int > mp;

        lop(i,0,n,1){

            if(ch[ i ] != ch1[ i ]){

                mp[ {ch[ i ],ch1[ i ]} ]++;
                a = ch[ i ],b = ch1[ i ];
            }
        }
        int x = mp.size();

        if(x == 0 || (x == 1 && mp[ {a,b} ] == 2)) puts("Yes");
        else puts("No");

    }
    return 0;
}
