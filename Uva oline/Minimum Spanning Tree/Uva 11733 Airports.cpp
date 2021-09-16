#include<bits/stdc++.h>
#define mx 100000

using namespace std;

struct node{

    int x,y,cost;

    bool operator < (const node & a) const{

        return cost > a.cost;
    }
};

priority_queue< node > q;
int parent[ mx ];

void set_(int n){

    for(int i = 0; i <= n; i++) parent[ i ] = i;
}

int search_parent(int n){

    return parent[ n ] == n ? n : parent[ n ] = search_parent( parent[ n ] );
}

void set_parent(int x,int y){

    x = search_parent( x );
    y = search_parent( y );

    parent[ y ] = x;
}

long long mst(int n){

    int c = 0;

    while(!q.empty()){

        if(n == 0) break;

        node v = q.top();

        q.pop();

        int p1 = search_parent( v.x );
        int p2 = search_parent( v.y );

        if(p1 != p2){

            c += v.cost;

            n--;

            set_parent(p1,p2);
        }
    }
    return c;
}
int main(){

    //freopen("input.txt","r",stdin);

    int test;

    cin >> test;

    for(int t = 1; t <= test; t++){

        int n,m;
        long long cost;

        cin >> n >> m >> cost;

        set_( n );

        for(int i = 0; i < m; i++){

            int x,y,c;

            cin >> x >> y >> c;

            if(c < cost) q.push({x,y,c});
        }

        int count_ = 0;

        long long ans = mst(n-1);

        for(int i = 1; i <= n; i++)
            if(parent[ i ] == i) count_++;

        cost *= count_;

        printf("Case #%d: %lld %d\n",t,ans+cost,count_);

        while(!q.empty()) q.pop();
    }

    return 0;
}
