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
    in
    #endif // ONLINE_JUDGE
}

struct Data{

    string s,p;
};
struct node{

    int mark;
    node *next[ 26 ];

    node(){

        mark = 0;
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
    }
    temp -> mark = n;
}
int Search(string s){

    node *temp = root;

    for(int i = 0; i < s.size(); i++){

        int idx = s[ i ] - 'a';

        if(temp -> next[ idx ] == nullptr) return false;

        temp = temp -> next[ idx ];
    }

    return temp -> mark;
}
void Delete(node *temp){

    for(int i = 0; i < 26; i++) if(temp -> next[ i ]) Delete( temp -> next[ i ] );

    delete( temp );
}

int main(){

    file();

    string ch,s,p,q;
    vector< Data > v;
    root = new node();
    int n = 0;

    while( true ){

        getline(cin,ch);

        if(ch.empty()) break;

        stringstream ss( ch );
        bool f = true;

        while(ss >> s){

            if( f ) p = s;
            else q = s;
            f = false;
        }

        v.push_back({p,q});
        n++;
        Insert(q,n);
    }

    while(cin >> s){

        int idx = Search( s );

        if( idx ) cout << v[ idx - 1 ].s << endl;
        else puts("eh");
    }

    Delete( root );

    return 0;
}
