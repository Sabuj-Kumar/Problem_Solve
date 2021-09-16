#include<bits/stdc++.h>
#define mx 200010

using namespace std;

struct v{

    int cost;
    int x;
    int y;

    bool operator < (const v& a) const {

        return cost > a.cost;
    }
};

v a;
int p[ mx ];
priority_queue< v > pi;
int node,edge;

void set_(){

    for(int i = 0; i <= node; i++) p[ i ] = i;
}

int find_parent(int n){

    return p[ n ] == n ? n : p[ n ] = find_parent( p[ n ] );
}

void Union(int x,int y){

    p[ y ] = x;
}

int spanning_tree(){

    int cost = 0;

    while(!pi.empty()){

        a = pi.top();

        pi.pop();

        int x = a.x;
        int y = a.y;
        int c = a.cost;

        int p1 = find_parent( x );
        int p2 = find_parent( y );

        if(p1 != p2 ){

            cost += c;

            Union(p1,p2);
        }
    }

    return cost;
}
int main(){

    //freopen("input.txt","r",stdin);

    while(scanf("%d %d",&node,&edge) && node && edge){

        int total = 0;

        set_();

        for(int i = 0; i < edge; i++){

            scanf("%d %d %d",&a.x,&a.y,&a.cost);

            total += a.cost;

            pi.push( a );
        }

        int min_cost = spanning_tree();

        cout << total - min_cost << endl;
    }

    return 0;
}
