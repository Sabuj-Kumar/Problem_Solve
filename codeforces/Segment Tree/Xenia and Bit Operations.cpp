#include<bits/stdc++.h>
#define mx 1000000
#define ll long long

using namespace std;

struct Node{

    int val;
    int level;
};

int a[ mx ];
Node tree[ 3 * mx ];

void build(int node,int L,int R){

    if(L == R) {

        tree[ node ].val = a[ L ];
        tree[ node ].level = 1;
        return;
    }

    int mid = (L + R) >> 1;

    build(node * 2,L,mid);
    build(node * 2 + 1,mid + 1,R);

    tree[ node ].level = tree[ node * 2 ].level + 1;

    if(tree[ node ].level & 1) tree[ node ].val = ( tree[ node * 2 ].val ^ tree[ node * 2 + 1 ].val );

    else tree[ node ].val = ( tree[ node * 2 ].val | tree[ node * 2 + 1 ].val );
}

ll update(int node,int L,int R,int pos,int val){

    if(L == R) {

        tree[ node ].val = val;

        return val;
    }

    int mid = (L + R) >> 1;

    if( pos <= mid ) update(node * 2,L,mid,pos,val);

    else update(node * 2 + 1,mid + 1,R,pos,val);

    if(tree[ node ].level & 1) tree[ node ].val = ( tree[ node * 2 ].val ^ tree[ node * 2 + 1 ].val );

    else tree[ node ].val = ( tree[ node * 2 ].val | tree[ node * 2 + 1 ].val );

    return tree[ node ].val;
}
int main(){

    //freopen("input.txt","r",stdin);

    int n,q;

    cin >> n >> q;

    n = pow(2,n);

    for(int i = 0; i < n; i++) cin >> a[ i ];

    build(1,0,n-1);

    while( q-- ){

        int p,val;

        cin >> p >> val;

        ll ans = update(1,0,n-1,p-1,val);

        cout << ans << endl;
    }

    return 0;
}
