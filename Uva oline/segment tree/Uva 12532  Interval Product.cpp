#include<bits/stdc++.h>
#define mx 100010
#define ll long long

using namespace std;

int tree[ 4 * mx ];
int arr[ mx ];

void build(int node,int L,int R){

    if(L == R) {

        tree[ node ] = arr[ L ];

        return;
    }

    int mid = (L + R) >> 1;

    build(node * 2,L,mid);
    build(node * 2 + 1,mid + 1,R);

    tree[ node ] = tree[ node * 2 ] * tree[ node * 2 + 1 ];
}

void update(int node,int L,int R,int pos,int val){

    if(L == R){

        tree[ node ] =  val;

        return;
    }

    int mid = (L + R) >> 1;

    if(pos <= mid ) update(node * 2,L,mid,pos,val);

    else update(node * 2 + 1,mid + 1,R,pos,val);

    tree[ node ] =  tree[ node * 2 ] * tree[ node * 2 + 1 ];
}

int query(int node,int L,int R,int x,int y){

    if( x > y) return 1;

    if(L == x && y == R) return tree[ node ];

    int mid = (L + R) >> 1;

    int p = query(node * 2,L,mid,x,min(mid,y));
    int q = query(node * 2 + 1,mid + 1,R,max(x,mid + 1),y);

    return p * q;
}
int main(){

   // freopen("input.txt","r",stdin);

    int n,q;

    while(cin >> n >> q){

        for(int i = 0; i < n; i++) {

            cin >> arr[ i ];

            if(arr[ i ] > 1) arr[ i ] = 1;

            if(arr[ i ] < -1) arr[ i ] = -1;
        }

        string s = "";

        build(1,0,n-1);

        while( q-- ){

            char ch;
            int x,y;

            cin >> ch >> x >> y;

            if(ch == 'C'){

                x--;

                if(y > 0) y = 1;

                else if(y < 0) y = -1;

                update(1,0,n-1,x,y);

                arr[ x ] = y;
            }

            else {

                int ans = query(1,0,n-1,x-1,y-1);

                if( ans == 1) cout << "+";
                else if( ans == -1 ) cout << "-";
                else cout << "0";
            }
        }
        cout << endl;
    }

    return 0;
}
