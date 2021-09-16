#include<bits/stdc++>
#define mx 100010
#define ll long long

using namespace std;

struct query{

    int l,r,index,ans;

}q[ mx ];

int a[ mx ], k = sqrt( mx ),L = 0,R = -1,count_ = 0;
ll b[ mx ];

void add(int x) {

    b[ a[ x ] ]++;

    if(b[ a[ x ] ] == 1) count_++;
}

void remov(int x ){

    b[ a[ x ] ]--;

    if(b[ a[ x ] ] == 0) count_--;
}

bool cmp(query &a,query &b){

    int block_a = a.l / k,block_b = b.l / k;

    if(block_a == block_b) return a.r < b.r;

    else return block_a < block_b;
}

int main(){

    int test;

    scanf("%d",&test);

    for(int cs = 1; cs <= test; cs++){

        int n,q;

        count_ = 0;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);

        printf("Case %d:\n",cs);

        scanf("%d %d",&n,&q);

        for(int i = 0; i < n; i++) scanf("%d",&a[ i ]);

        for(int i = 0; i < q; i++){

            scanf("%d %d",&q[ i ].l,&q[ i ].r);
            q[ i ].index = i;
            q[ i ].ans = 0;
        }

        sort(q,q + n,cmp);

        for(int i = 0; i < q; i++){

            while(L > q[ i ].l) add( L-- );
            while(R < q[ i ].r) add( R++ );
            while(L < q[ i ].l) remov( L++ );
            while(R > q[ i ].r) romov( R-- );
            q[ i ].ans = count_;
        }

        for(int i = 0; i < q; i++) printf("%d\n",q[ i ].ans);
    }

    return 0;
}
