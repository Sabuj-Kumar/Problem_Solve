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

struct node{

    int data;
    node *left = NULL;
    node *right = NULL;
};

node *Newnode(int val){

    node *temp = new node();

    temp -> data = val;
    temp -> left = NULL;
    temp -> right = NULL;

    return temp;
}

int in_search(int iin[ ],int st,int ed,int val){

    for(int i = st; i <= ed; i++){

        if(iin[ i ] == val) return i;
    }
}
node *build_tree(int iin[],int pre[],int st,int ed){

    static int ind = 0;

    if(st > ed) return NULL;

    node *temp = Newnode(pre[ ind++ ]);

    if(st == ed) return temp;

    int i = in_search(iin,st,ed,temp->data);

    temp->left = build_tree(iin,pre,st,i - 1);
    temp->right = build_tree(iin,pre,i + 1,ed);

    return temp;
}

void order(int check[],node *temp){

    static int ind = 0;

    if(temp == NULL) return;

    order(check,temp->left);
    order(check,temp->right);

    check[ ind++ ] = temp->data;
}
int main(){

    file();

    int n,a;

    cin >> n;

    int pre[ n ];
    int post[ n ];
    int iin[ n ];
    int check[ n ];

    for(int i = 0; i < n; i++) cin >> pre[ i ];
    for(int i = 0; i < n; i++) cin >> post[ i ];
    for(int i = 0; i < n; i++) cin >> iin[ i ];

    node *root = build_tree(iin,pre,0,n-1);

    order(check,root);

    bool flag = true;

    for(int i = 0; i < n; i++){

        if(check[ i ] != post[ i ]){

            flag = false;

            break;
        }
    }

    if(flag) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}
