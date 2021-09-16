#include<bits/stdc++.h>
#define mx 100010
#define ll long long

using namespace std;

struct query{

    int l,r,index;

}qr[ mx ];

int a[ mx ],b[ mx ],p[ mx ],k,L = 1,R = 0,count_ = 0,ans[ mx ];

bool cmp(query &a,query &b){

      int b_a = a.l / k,b_b = b.l / k;

      if(b_a == b_b) return a.r < b.r;

      return b_a < b_b;
//    if(p[ a.l ] < p[ b.l ]) return true;
//    if(p[ a.l ] > p[ b.l ]) return false;
//    if(p[ a.l ] & 1) return a.r < b.r;
//    return a.r > b.r;
}
void add(int x) {

    b[ a[ x ] ]++;

    if(b[ a[ x ] ] == 1) count_++;
}

void remov(int x ){

    b[ a[ x ] ]--;

    if(b[ a[ x ] ] == 0) count_--;
}

int main(){

    //freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for(int cs = 1; cs <= test; cs++){

        int n,q;

        memset(b,0,sizeof b);

        printf("Case %d:\n",cs);

        scanf("%d %d",&n,&q);

        k = sqrt( n );
        L = 1;
        R = 0;
        count_ = 0;

        for(int i = 1; i <= n; i++) {

            scanf("%d",&a[ i ]);
            //p[ i ] = (i-1) / k + 1;
        }

        for(int i = 1; i <= q; i++){

            scanf("%d %d",&qr[ i ].l,&qr[ i ].r);

            qr[ i ].index = i;
            //cout << qr[ i ].l << " " << qr[ i ].r << " " << qr[ i ].index << endl;
        }
        //cout << endl;

        sort(qr+1,qr + 1 + q,cmp);

//        for(int i = 0; i < q; i++) {
//
//            printf("%d %d %d %d\n",qr[ i ].l,qr[ i ].r,qr[ i ].index,qr[ i ].ans);
//        }
//        cout << endl;
        for(int i = 1; i <= q; i++){

            while(L > qr[ i ].l) add( --L );
            while(L < qr[ i ].l) remov( L++ );
            while(R > qr[ i ].r) remov( R-- );
            while(R < qr[ i ].r) add( ++R );

            //cout << L << " " << R << " " << count_ << endl;
            ans[ qr[ i ].index ] = count_;
        }

        for(int i = 1; i <= q; i++) printf("%d\n",ans[ i ]);
    }

    return 0;
}

