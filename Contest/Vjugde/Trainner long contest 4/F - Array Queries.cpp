#include<bits/stdc++.h>
#define mx 100000

using namespace std;

int tree[ 4 * mx ];
int ar[ mx + 10 ];

void build_tree(int node,int L,int R){

    if(L == R){

        tree[ node ] = ar[ L ];

        return;
    }

    int l = 2 * node;
    int r = (2 * node) + 1;
    int mid = (L + R) / 2;

    build_tree(l,L,mid);
    build_tree(r,mid+1,R);

    tree[ node ] = min(tree[ l ],tree[ r ]);
}

int query(int node,int L,int R,int X,int Y){

    if(L > Y || R < X) return mx;

    if(L >= X && R <= Y) return tree[ node ];

    int l = 2 * node;
    int r = (2 * node) + 1;
    int mid = (L + R) / 2;

    int x = query(l,L,mid,X,Y);
    int y = query(r,mid+1,R,X,Y);

    return min(x,y);
}
int main(){

    //freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);
    //printf("%d\n",test);

    for(int t = 1; t <= test; t++){

        int n,q;

        scanf("%d %d",&n,&q);
       // printf("%d %d\n",n,q);

        for(int i = 0; i < n; i++)
            scanf("%d",&ar[ i ]);

        build_tree(1,0,n-1);

        int q1,q2;

        printf("Case %d:\n",t);

        while(q--){

            scanf("%d %d",&q1,&q2);

            //printf("%d %d\n",q1,q2);

            int result = query(1,0,n-1,q1-1,q2-1);

            printf("%d\n",result);
        }
    }

    return 0;
}
