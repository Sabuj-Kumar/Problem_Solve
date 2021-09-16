#include<bits/stdc++.h>
#define mx 10010

using namespace std;

vector<int > graph[ mx ];
bool vis[ mx ];
int dis[ mx ],low[ mx ],p[ mx ],t,count_;

void articulation(int root,int node){

    dis[ node ] = low[ node ] = ++t;

    vis[ node ] = true;

    int child = 0;

    for(auto x : graph[ node ]){

        if( x == p[ node ]) continue;

        if(vis[ x ]) low[ node ] = min(low[ node ],dis[ x ]);

        else{

            p[ x ] = node;

            articulation(root,x);

            low[ node ] = min(low[ node ],low[ x ]);

            child++;

            if(dis[ node ] < low[ x ] && node != root) count_++;
        }
    }
    if(node == root && child > 1) count_ += child;
}
int main(){

    freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for(int cs = 1; cs <= test; cs++){

        memset(dis,0,sizeof dis);
        memset(low,0,sizeof low);
        memset(vis,false,sizeof vis);
        for(int i = 0; i < mx; i++) p[ i ] = i,graph[ i ].clear();
        t = 0,count_ = 0;

        int node,edge,root = -1;

        scanf("%d %d",&node,&edge);

        while(edge--){

            int a,b;

            scanf("%d %d",&a,&b);

            if(root == -1) root = a;

            graph[ a ].push_back( b );
            graph[ b ].push_back( a );
        }


        articulation(root,root);

        printf("Case %d: %d\n",cs,count_);
    }

    return 0;
}
