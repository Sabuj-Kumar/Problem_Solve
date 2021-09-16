#include<bits/stdc++.h>
#define mx 100010

using namespace std;

char s[ mx ];
int tree[ 3 * mx ];

void push(int node){

    tree[ node * 2 ] += tree[ node ];
    tree[ node * 2 + 1 ] += tree[ node ];
    tree[ node ] = 0;
}

void update(int node,int L,int R,int x,int y){

    if(x > y) return;

    if(L == x && R == y){

        //cout << "update node   " << node << " " << tree[ node ].second << " ( rang ) = " << L << " " << R << endl;
        tree[ node ] += 1;
       // cout << "update node   " << node << " " << tree[ node ].second << endl;
        return;
    }

    push( node );

    //cout << node << " (node * 2) = " << tree[ node * 2 ].second << " (node * 2 + 1) = " << tree[ node * 2 + 1].second << " ( L ) = "<< L << " ( R ) = " << R << " ( x ) = " << x << " ( y ) = " << y <<endl;
   // for(int i = L; i <= R; i++) cout << s[ i ]<< " ";
   // cout << endl;

    int mid = (L + R) / 2;

    update(node * 2,L,mid,x,min(mid,y));
    update(node * 2 + 1,mid + 1,R,max(mid + 1,x),y);
}
int query(int node,int L,int R,int pos){

    if(L == R) return tree[ node ];

    int mid = (L + R) / 2;

    //cout << tree[ node ].second << endl;
    push( node );

    if(pos <= mid) return query(node * 2,L,mid,pos);

    else return query(node * 2 + 1,mid + 1,R,pos);
}
int main(){

    //freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for(int cs = 1; cs <= test; cs++){

        scanf("%s",s);

        memset(tree,0,sizeof tree);

        int x,y,q,n = strlen( s );

        scanf("%d",&q);

        printf("Case %d:\n",cs);

        while( q-- ){

            char ch;

            scanf(" %c",&ch);

            if(ch == 'I') {

                scanf("%d %d",&x,&y);

                update(1,0,n-1,x-1,y-1);
                //cout << "\n\n";
            }
            else {

                scanf("%d",&x);

                int p = query(1,0,n-1,x-1);

                if(p % 2) printf("%d\n",!(s[ x-1 ] - '0'));

                else printf("%d\n",(s[ x-1 ] - '0'));
            }
        }
    }

    return 0;
}
