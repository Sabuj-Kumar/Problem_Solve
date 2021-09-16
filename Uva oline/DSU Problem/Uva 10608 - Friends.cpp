#include<bits/stdc++.h>
#define mx 30010

using namespace std;

int p[ mx ];
int r[ mx ];
int s[ mx ];
int mx_;

void set_(int n){

    for(int i = 1; i <= n; i++){

        p[ i ] = i;

        r[ i ] = 0;

        s[ i ] = 1;
    }
}

int search_parent(int n){

    return p[ n ] == n ? p[ n ] : p[ n ] = search_parent(p[ n ]);
}

void set_parent(int n,int m){

    int a = search_parent( n );
    int b = search_parent( m );

    if(a == b) return;

    p[ b ] = a;

    s[ a ] += s[ b ];

    mx_ = max(mx_,s[ a ]);
}
int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test;

    cin >> test;

    while(test--){

        int n,m;

        mx_ = 1;

        cin >> n >> m;

        set_(n);

        while(m--){

            int a,b;

            cin >> a >> b;

            set_parent(a,b);
        }

        cout << mx_ << endl;
    }

    return 0;
}
