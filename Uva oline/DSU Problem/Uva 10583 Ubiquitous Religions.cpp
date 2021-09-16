#include<bits/stdc++.h>
#define max_ 100000

using namespace std;

int ans;
int a[ max_ ];
int r[ max_ ];
map<int,int> mp;

void set_(int n){

    for(int i = 1; i <= n; i++) a[ i ] = i,r[ i ] = 0;
}

int search_parent(int n){

    if(a[ n ] != n) a[ n ] = search_parent(a[ n ]);

    return a[ n ];
}
void set_parent(int n,int m){

    int p = search_parent( n );
    int q = search_parent( m );

    if(p == q) return;

    ans--;

    if(r[ p ] > r[ q ]) a[ q ] = p;

    else {

        a[ p ] = q;

        if(r[ p ] == r[ q ]) r[ q ]++;
    }
}
int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,t = 0;

    while(cin >> n >> m && n && m){

        set_(n);

        int count_ = 0;
        mp.clear();

        ans = n;

        while(m--){

            int a,b;

            cin >> a >> b;

            set_parent( a , b );
        }

//        for(int i = 1; i <= n; i++){
//
//            cout << i << " " << a[ i ] << endl;
//        }
        cout << "Case "<< ++t << ": " << ans << endl;
    }

    return 0;
}
