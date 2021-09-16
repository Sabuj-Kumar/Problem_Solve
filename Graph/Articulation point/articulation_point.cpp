#include<bits/stdc++.h>

using namespace std;
///100000000
vector< int > graph[ 10005 ];
set<int> s;
int dis[ 10005 ];
int low[ 10005 ];
int parent[ 10005 ];
bool vis[ 10005 ];
bool n[ 10005 ];
int T;

void Articulation(int node,int root)
{
    dis[ node ] = low[ node ] = ++T;

    vis[ node ] = true;

    int child = 0;

    for(auto x : graph[ node ]) {

        if(x == parent[ node ]) continue;

        if(vis[ x ]) low[ node ] = min(low[ node ],dis[ x ]);

        else {

            parent[ x ] = node;

            Articulation(x,root);

            low[ node ] = min(low[ node ],low[ x ]);

            if(dis[ node ] <= low[ x ] && node != root) {

                s.insert(node);
            }
            child++;
        }
    }
    if(node == root && child > 1){

        s.insert( node );
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    int test,t = 0;

    scanf("%d",&test);

    while(test--)
    {
        int node,edge,root;

        for(int i = 0; i < 10005; i++) parent[ i ] = i,graph[ i ].clear();

        memset(vis,false,sizeof vis);

        T = 0;

        scanf("%d %d",&node,&edge);

        for(int i = 1; i <= edge; i++)
        {
            int n1,n2;

            scanf("%d %d",&n1,&n2);

            //if(i == 1) root = n1;

            graph[ n1 ].push_back( n2 );
            graph[ n2 ].push_back( n1 );
        }

//        for(int i = 1; i <= node; i++)
//        {
//            cout << i << " : ";
//
//            for(auto x : graph[ i ]) cout << x << " ";
//
//            cout << "\n";
//        }

        Articulation(1,1);

        printf("Case %d: %d\n",++t,s.size());
        s.clear();
    }
    return 0;
}

