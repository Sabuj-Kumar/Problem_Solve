#include<bits/stdc++.h>
#define mx 101000
#define inft 1000000

using namespace std;

int tree[ 3 * mx ];
int a[ mx ];

void build(int node,int start,int last){

    if(start == last) {

        tree[ node ] = a[ start ];

        return;
    }

    int mid = (start + last) / 2;

    build(node * 2,start,mid);
    build(node * 2 + 1,mid+1,last);

    tree[ node ] = min(tree[ node * 2],tree[ node * 2 + 1 ]);
}

int query(int node,int start,int last,int left,int right){

    if(left > right) return inft;

    if(left == start && right == last) return tree[ node ];

    int mid = (start + last) / 2;

    int p = query(node * 2,start,mid,left,min(right,mid));
    int q = query(node * 2 + 1,mid+1,last,max(left,mid+1),right);

    return min(p,q);
}
int main(){

    op;
    //freopen("input.txt","r",stdin);

    int ts;

    scanf("%d",&ts);

    for(int cs = 1; cs <= ts; cs++){

        int n,q,left,right;

        scanf("%d %d",&n,&q);

        for(int i = 0; i < n; i++) scanf("%d",&a[i ]);

        build(1,0,n-1);

        printf("Case %d:\n",cs);

        while(q--){

            scanf("%d %d",&left,&right);

            int ans = query(1,0,n-1,left-1,right-1);

            printf("%d\n",ans);
        }
    }
    return 0;
}
