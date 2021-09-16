#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define p_b push_back
#define p_f push_front
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
    data(int x,int c) { this->x = x,this->c = c;}
    bool operator < (const data &a) const{

        return c > a.c;
    }
};

int sc() { int n; cin >> n; return n; }

int main(){

    file();

    int test;

    for(cin >> test; test--;){

        int n,c = 0;
        vector< string > v;
        map< string ,int > mp,ck;

        for(cin >> n; n--;){

            string s;
            cin >> s;
            v.p_b( s );
            mp[ s ]++;
            if(!ck[ s ]) ck[ s ] = ++c;
        }

        int k = 0;

        //cout << c << endl;

        for(int i = 1; i < v.size(); i++){

            if(mp[ v[ i ] ] > 1){

                while(mp[ v[ i ] ] > 1){

                    k++;

                    //cout << "map " << mp[ v[ i ] ] << endl;
                    bool f = 0;

                    mp[ v[ i ] ]--;
                    int j = 0;
                    while( 1 ){

                        for(int t = 0; t < 4; t++){

                            char ch = v[ i ][ t ];

                            v[ i ][ t ] = (j + 48);

                            if(!ck[ v[ i ] ]) {

                                    ck[ v[ i ] ] = 1;
                                    f = 1;
                                    break;
                            }
                            v[ i ][ t ] = ch;
                         }
                         if( f ) break;
                         j++;
                    }
                }
            }
        }

        cout <<  k << endl;

        for(int i = 0; i < v.size(); i++) cout << v[ i ] << endl;
    }
    return 0;
}
