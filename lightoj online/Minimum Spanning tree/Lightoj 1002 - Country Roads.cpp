#include<bits/stdc++.h>
#define mx 505

using namespace std;

struct Node{

    int a,b,c;

    bool operator < (const Node &b) const{

        return b.c < c;
    }
};

priority_queue< Node > q;
int a[ mx ];
int parent[ mx ];
void init_(int n) { for(int i = 0; i < n; i++) parent[ i ] = i; }
int search_parent(int p){ return parent[ p ] == p ?  p : parent[ p ] = search_parent( parent[ p ] ); }
void union_(int x,int y){ parent[ x ] = y; }


void mini(int edge){

    while( !q.empty() && edge){

        Node n = q.top();

        q.pop();

        int x = search_parent(n.a);
        int y = search_parent(n.b);

        if(x != y){

            printf("%d %d %d\n",n.a,n.b,n.c);

            edge--;

            union_(x,y);
        }
    }

    while(!q.empty()) q.pop();
}
int main(){

    freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);

    cout << "test "<< test << endl;

    for(int cs = 1; cs <= test; cs++){

        int n,m,p;

        scanf("%d %d",&n,&m);
        //cout << n << " " << m << endl;
        init_( n );

        for(int i = 0; i < m; i++){

            int u,v,cost;

            scanf("%d %d %d",&u,&v,&cost);

            q.push({u,v,cost});
        }

        int me;

        scanf("%d",&me);

        mini( m );

        for(int i = 0; i < n; i++) cout << "parent " << i << " "<< parent[ i ] << endl;

        cout << endl << endl;

    }
    return 0;
}
