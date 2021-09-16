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

string s[ 25005 ];
vector< int > ar;
int n,q;

struct node{

    vector< int > v;
    node *next[ 27 ];

    node(){

        for(int i = 0; i < 27; i++) next[ i ] = nullptr;

        v.clear();
    }
};

node *root;

void Insert(string ss,int n){

    if(root == nullptr) root = new node();

    node *temp = root;

    for(int i = 0; i < ss.size(); i++){

        int idx = ss[ i ] - 'a';

        if(temp -> next[ idx ] == nullptr) temp -> next[ idx ] = new node();

        temp -> v.pb( n );

        temp = temp -> next[ idx ];
    }
}
int Search(string ss){

    node *temp = root;

    for(int i = 0; i < ss.size(); i++){

        int idx = ss[ i ] - 'a';

        if(temp -> next[ idx ] == nullptr) return -1;

        temp = temp -> next[ idx ];
    }

    if(temp -> v.size() == 0) return -1;

    ar = temp -> v;

    return 1;
}
void Delete(node *temp){

    for(int i = 0; i < 27; i++) if(temp -> next[ i ] != nullptr) Delete( temp -> next[ i ] );

    delete( temp );
}

int main(){

    file();

    cin >> n;

    for(int i = 0; i < n; i++) cin >> s[ i ];

    sort(s,s + n);

    Insert(s[ 0 ],0);

    for(int i = 1; i < n; i++)
        if(s[ i - 1 ] != s[ i ]) Insert(s[ i ],i);

    cin >> q;

    Case( q ){

        string ss;

        cin >> ss;

        int flag = Search( ss );

        cout << "Case #" << cs << ":" << endl;
        if(flag == -1) cout << "No match."<<endl;
        else {

            for(int i = 0; i < ar.size(); i++) cout << s[ ar[ i ] ] << endl;
            ar.clear();
        }
    }

    Delete( root );

    return 0;
}
