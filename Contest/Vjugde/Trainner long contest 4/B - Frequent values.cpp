#include<bits/stdc++.h>
#define mx 100000

using namespace std;

int tree[ 4 * mx ];
int ar[ mx + 10 ];
map< int,int > mp;

void build_tree(int node,int L,int R){

    if(L == R){

        tree[ node ] = ar[ L ];

        return;
    }

    int l = 2 * node;
    int r = (2 * node) + 1;
    int mid = (L + R) >> 1;

    build_tree(l,L,mid);
    build_tree(r,mid+1,R);

    mp[ tree[ l ] ]++;
    mp[ tree[ r ] ]++;

    tree[ node ] = max(mp[ tree[ l ] ],mp[ tree[ r ] ]);
}

int query(int node,int L,int R,int X,int Y){

    if(L > Y || R < X) return 0;

    if(L >= X && R <= Y) return tree[ node ];

    int l = (2 * node);
    int r = (2 * node) + 1;
    int mid = (L + R) >> 1;

    query(l,L,mid,X,Y);
    query(r,mid+1,R,X,Y);

    mp[ tree[ l ] ]++;

}
int main(){

    int n,q;

    scanf("%d %d",&n,&q);

    for(int i = 0; i < n; i++)
        scanf("%d",&ar[ i ]);

    mp.clear();

    build_tree(1,0,n-1);

    while(q--){

        mp.clear();

        int x,y;

        scanf("%d %d",&x,&y);

    }
    return 0;
}
