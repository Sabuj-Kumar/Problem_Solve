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

int n,q;

struct node{

    int val;
    node *next[ 26 ];

    node(){

        val = 0;
        for(int i = 0; i < 26; i++) next[ i ] = nullptr;
    }
};

node *root;

void Insert(string s,int len){

    node *temp = root;

    for(int i = 0; i < len; i++){

        int idx = s[ i ] - 'a';

        if(temp -> next[ idx ] == nullptr) temp -> next[ idx ] = new node();

        temp -> val++;

        temp = temp -> next[ idx ];
    }
    temp -> val++;
}

int Search(string s,int len){

    node *temp = root;

    for(int i = 0; i < len; i++){

        int idx = s[ i ] - 'a';

        if(temp -> next[ idx ] == nullptr) return 0;

        temp = temp -> next[ idx ];
    }

    return temp -> val;
}

void Delete(node *temp){

    for(int i = 0; i < 26; i++) if(temp -> next[ i ]) Delete( temp -> next[ i ]);

    delete( temp );
}

int I() { int n; sc( n ); return n; }

int main(){

    file();

    root = new node();

    n = I();
    q = I();

    string s;

    while( n-- ){

        cin >> s;

        Insert(s,s.size());
    }

    while( q-- ){

        cin >> s;

        int idx = Search(s,s.size());

        cout << idx << endl;
    }

    Delete( root );

    return 0;
}
