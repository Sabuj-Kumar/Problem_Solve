#include<bits/stdc++.h>
#define mx 10010

using namespace std;

struct node{

    int a,b,c;

    bool operator < (const node &x ) const {

        return c > x.c;
    }
};

priority_queue< node > pi;

int p[ mx ];
int s(){ int n; scanf("%d",&n); return n; }
void init_(int n){ for(int i = 1; i <= n; i++) p[ i ] = i; }
int search_parent(int x){ return p[ x ] ==  x ? p[ x ] : p[ x ] = search_parent(p[x]); }
void set_parent(int x,int y){ p[ y ] = x; }

int mst(int n){

    int total_cost = 0;

    while(n && !pi.empty()){

        node x =  pi.top();

        pi.pop();

        int p1 = search_parent(x.a);
        int p2 = search_parent(x.b);

        if( p1 != p2){

            total_cost += x.c;

            set_parent(p1,p2);

            n--;
        }
    }

    return total_cost;
}

int main(){

    //freopen("input.txt","r",stdin);

    int test = s();

    for(int cs = 0; cs < test; cs++){

        int n = s();

        char ch[ 20 ];
        int x,c = 0;
        map<string,int> mp;

        init_( n );

        for(int i = 0; i < n; i++){

            scanf("%s",ch);

            mp[ ch ] = ++c;

            x = s();

            while( x-- ){

                int a,b;

                scanf("%d %d",&a,&b);

                pi.push({mp[ ch ],a,b});
            }
        }

        int cost =  mst( n );

        printf("%d\n",cost);
    }
    return 0;
}
