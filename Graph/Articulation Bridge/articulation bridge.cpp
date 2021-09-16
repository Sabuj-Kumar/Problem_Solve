#include<bits/stdc++.h>

using namespace std;

vector< int > graph[ 10010 ];
set<pair<int,int> > link;
map<pair<int,int>,int > m;

int dis[ 10010 ],low[ 10010 ],parent[ 10010 ];
bool vis[ 10010 ],a[ 10010 ];
int T;

void articulation_bridge(int node,int root){

    dis[ node ] = low[ node ] = ++T;

    vis[ node ] = true;

    int child = 0;

    for(auto x : graph[ node ])
    {
        if(x == parent[ node ]) continue;

        if(vis[ x ]) low[ node ] = min(low[ node ],dis[ x ]);

        else {

            parent[ x ] = node;

            articulation_bridge(x,root);

            child++;

            low[ node ] = min(low[ node ],low[ x ]);

            if(dis[ node ] < low[ x ] && node != root){

                if(a[ x ]) {

                    if(x > node) link.insert( {node,x} );
                    else link.insert( {x,node} );
                }
            }
        }
        if(node == root && child >= 1){

            if(a[ node ])
            if(x > node) link.insert( {node,x} );
            else link.insert( {x,node} );
        }
        a[ x ] = false;
    }
}

int main(){

    //freopen("input.txt","r",stdin);
    int test;

    scanf("%d",&test);

    for(int t = 1; t <= test; t++){

        memset(vis,false,sizeof vis);
        memset(a,true,sizeof a);
        for(int i = 0; i < 10010; i++) parent[ i ] = i;
        for(int i = 0; i < 10010; i++) graph[ i ].clear();
        link.clear();
        m.clear();
        T = 0;

        int node;

        scanf("%d",&node);

        for(int i = 0; i < node; i++){

            int n1,n2,n;

            scanf("%d (%d)",&n1,&n);

            for(int j = 0; j < n; j++){

                scanf("%d",&n2);

                graph[ n1 ].push_back( n2 );
            }
        }

//        for(int i = 0; i < node; i++){
//
//            cout << i << " : ";
//            for(auto x : graph[ i ]) cout << x << " ";
//            cout << "\n";
//        }
//         cout << "\n";
        for(int i = 0; i < node; i++){

            if(!vis[ i ]) articulation_bridge(i,i);
        }

        printf("Case %d:\n%d critical links\n",t,link.size());

//        for(int i = 0; i < link.size(); i++){
//
//            printf("%d - %d\n",link[ i].first,link[ i ].second);
//        }
        for(auto i = link.begin(); i != link.end(); i++){

            printf("%d - %d\n",i -> first,i -> second);
        }
    }
    return 0;
}

