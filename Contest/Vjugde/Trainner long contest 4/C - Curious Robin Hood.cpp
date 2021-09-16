#include<bits/stdc++.h>
#define MX 100000

using namespace std;

int tree[ 4 * MX  ];
int ar[ MX + 10 ];

void build_tree(int node,int L,int R){

    if(L == R){

        tree[ node ] = ar[ L  ];

        return;
    }

    int l = (2 * node);
    int r = (2 * node) + 1;
    int mid = (L + R) >> 1;

    build_tree(l,L,mid);
    build_tree(r,mid+1,R);

    tree[ node ] = tree[ l ] + tree[ r ];
}

void update(int node,int pos,int value,int L,int R){

    if(L > pos || R < pos) return;

    if(L == R && L == pos){

        tree[ node ] += value;

        return;
    }

    int l = 2 * node;
    int r = (2 * node) + 1;
    int mid = (L + R) >> 1;

    update(l,pos,value,L,mid);
    update(r,pos,value,mid+1,R);

    tree[ node ] = tree[ l ] + tree[ r ];
}
int query(int node,int L,int R,int X,int Y){

    if(L > Y || R < X) return 0;

    if(L >= X && R <= Y) return tree[ node ];

    int l = (2 * node);
    int r = (2 * node) + 1;
    int mid = (L + R) >> 1;

    return query(l,L,mid,X,Y) + query(r,mid+1,R,X,Y);
}
int main(){

    //freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for(int t = 1; t <= test; t++){

        int n,m;

        scanf("%d %d",&n,&m);

        for(int i = 0; i < n; i++)
            scanf("%d",&ar[ i ]);

        build_tree(1,0,n-1);

        printf("Case %d:\n",t);

        while(m--){

            int p,index,value,rang;

            scanf("%d",&p);

            if(p == 1){

                scanf("%d",&index);

                printf("%d\n",ar[ index ]);

                update(1,index,-ar[ index ],0,n-1);

                ar[ index ] = 0;
            }
            else if(p == 2){

                scanf("%d %d",&index,&value);

                update(1,index,value,0,n-1);

                ar[ index ] += value;
            }
            else {

                scanf("%d %d",&index,&rang);

                printf("%d\n",query(1,0,n-1,index,rang) );
            }
        }
    }
    return 0;
}
