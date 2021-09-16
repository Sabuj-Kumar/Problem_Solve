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
#define lop(i,v,n) for(int i = 0; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

struct node{

    node *next[ 26 ];
    pair< string,int > v;
    bool mark;

    node(){

        mark = false;
        v = {"",0};
        for(int i = 0; i < 26; i++) next[ i ] = nullptr;
    }
};

node *root;

void Insert(string s,int n){

    node *temp = root;

    for(int i = 0; i < s.size(); i++){

        int idx = s[ i ] - 'a';

        if(temp -> next[ idx ] == nullptr) temp -> next[ idx ] = new node();

        temp = temp -> next[ idx ];

        if(temp -> v.sd < n) temp -> v = {s,n};
    }
    temp -> mark = true;
}

node *Search(string s,int len){

    node *temp = root;

    for(int i = 0; i < len; i++){

        int idx = s[ i ] - 'a';

        if(temp -> next[ idx ] == nullptr) return temp -> next[ idx ];

        temp = temp -> next[ idx ];
    }

    return temp;
}

void Delete(node *temp){

    for(int i = 0; i < 26; i++) if(temp -> next[ i ]) Delete( temp -> next[ i ]);

    delete( temp );
}

int I() { int n; sc( n ); return n; }

int main(){

    file();

    root = new node();

    int n = I();
    string s;
    map < string,int >mp;

    for(int i = 0; i < n; i++){

        cin >> s;

        mp[ s ]++;
    }

    for(auto x : mp) Insert(x.ft,x.sd);

    int q = I();

    while( q-- ){

        cin >> s;

        node *nd = Search(s,s.size());

        if( nd ) cout << nd -> v.ft << " " << nd -> v.sd << endl;

        else cout << -1 << endl;
    }

    Delete( root );

    return 0;
}

