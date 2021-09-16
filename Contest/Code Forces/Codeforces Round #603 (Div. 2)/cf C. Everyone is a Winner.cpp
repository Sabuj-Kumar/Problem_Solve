#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define un unsigned long long
#define db double
#define ldb long double
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,c;
    data(){}
    data(int x,int c) { this->x = x,this->c = c; }
    bool operator < (const data &a) const {

        return c > a.c;
    }
};

int sc(){ int n; scanf("%d",&n); return n; }

int main(){

    file();

    int test;

    for(cin >> test; test--;){

        int n = sc();

        set< int > s;
        s.insert( 0 );

        for(int i = 1; i <= sqrt( n ); i++){

            s.insert( i );
            s.insert(n/i);
        }

        cout << s.size() << endl;
        bool f = true;
        for(auto x : s){

            if( f ) f = false,cout << x;
            else cout << " " << x;
        }
        cout << endl;
    }

    return 0;
}
