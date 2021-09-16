#include<bits/stdc++.h>
#define max_ 1000000

using namespace std;

int a[ max_ ];
int ran[ max_ ];

void set_(int n){

    for(int i = 1; i <= n; i++) a[ i ] = i,ran[ i ] = 0;
}

int search_parent(int n){

    if(a[ n ] != n) a[ n ] = search_parent(a[ n ]);

    return a[ n ];
}

void set_parent(int n,int m){

    int p = search_parent( n );
    int q = search_parent( m );

    if(p == q) return;

    if(ran[ p ] > ran[ q ]) a[ q ] = p;

    else{

        a[ p ] = q;

        if(ran[ p ] == ran[ q ]) ran[ q ]++;
    }
}
int main(){

    //freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test,flag = 0;

    cin >> test;

    while(test--){

        if(flag) cout << endl;

        int n,m,count1 = 0,count2 = 0;

        cin >> n;

        cin.ignore();

        set_(n);

        string s;

        while(getline(cin,s) && s.size()){

            stringstream ss( s );

            char c;
            int p,q;

            ss >> c;
            ss >> p;
            ss >> q;

            if(c == 'c') set_parent(p,q);

            else{

                if(search_parent(p) == search_parent(q)) count1++;

                else count2++;
            }
        }

        cout << count1 << "," << count2 << endl;

        flag = 1;
    }


    return 0;
}
