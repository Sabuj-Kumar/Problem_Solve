#include<bits/stdc++.h>
#define mx 100100
#define inft 1000000000

using namespace std;

pair<int,int> tree[ 3 * mx ];
int a[ mx ];

void build(int node,int l,int r){

    if(l == r) {

        tree[ node ].first = a[ l ];
        tree[ node ].second = a[ l ];
        return;
    }

    int mid = (l + r) / 2;
    build(node * 2,l,mid);
    build(node * 2 + 1,mid + 1,r);

    tree[ node ].first = min(tree[ node * 2].first,tree[ node * 2 + 1 ].first);
    tree[ node ].second = max(tree[ node * 2].second,tree[ node * 2 + 1 ].second);
}

pair<int,int> query(int node,int l,int r,int lf,int rt){

    if(lf > rt) return {inft,-1};
    if(l == lf && r == rt) return tree[ node ];

    int mid = (l + r) / 2;

    pair<int,int> p1 = query(node * 2,l,mid,lf,min(mid,rt));
    pair<int,int> p2 = query(node * 2 + 1,mid + 1,r,max(mid+1,lf),rt);

    return { min(p1.first,p2.first),max(p1.second,p2.second) };
}
int main(){

    //freopen("input.txt","r",stdin);

    int ts;

    scanf("%d",&ts);

    for(int cs = 1; cs <= ts; cs++){

        int n,d,ans = 0;

        scanf("%d %d",&n,&d);

        for(int i = 0; i < n; i++) scanf("%d",&a[ i ]);

        build(1,0,n-1);

        for(int i = 0; i < n - d; i++){

            pair<int,int> p = query(1,0,n-1,i,i+d-1);

            if( (p.second - p.first > ans) ) ans = p.second - p.first;
        }
        printf("Case %d: %d\n",cs,ans);
    }

    return 0;
}
