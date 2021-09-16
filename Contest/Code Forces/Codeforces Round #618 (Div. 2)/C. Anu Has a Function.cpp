#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int sc() { int n; scanf("%d",&n); return n; }

vector<int> v;
int sum,n;

int main(){

    file();

    n = sc();
    v.clear();

    lop(i,0,n) v.pb( sc() );

    return 0;
}
