#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    string s,s1,c = "abcdefghijklmnopqrstuvwxyz";
    map< char,int > m,m1,a,b;
    map< char,queue<int> > v,v1;
    queue< int > q,q1;
    vector<pair<int,int > > p;

    cin >> n;

    cin >> s >> s1;

    for(int i = 0; i < s.size(); i++) {

        if(s[ i ] == '?') {

            a[ s[ i ] ]++;

            q.push( i );
        }
        else m[ s[ i ] ]++;

        if(s[ i ] != '?') v[ s[ i ] ].push( i );
    }

    for(int i = 0; i < s1.size(); i++) {

        if(s1[ i ] == '?') {

            b[ s1[ i ] ]++;

            q1.push( i );
        }
        else m1[ s1[ i ] ]++;

        if(s1[ i ] != '?') v1[ s1[ i ] ].push( i );
    }

    for(int i = 0; i < c.size(); i++){

        if(m[ c[ i ] ] != 0 && m1[ c[ i ] ] != 0){

            int d = m[ c[ i ] ];
            int h = m1[ c[ i ] ];

            if(d > h) swap(d,h);

            if(d < h){

                for(int j = 0; j < d; j++){

                    int t = v[ c[ i ] ].front();

                    int t1 = v1[ c[ i ] ].front();

                    v[ c[ i ] ].pop();
                    v1[ c[ i ] ].pop();

                    p.push_back({t,t1});
                }
            }
        }

        else if(m[ c[ i ] ] == 0 && m1[ c[ i ] ] != 0 || m[ c[ i ] ] != 0 && m1[ c[ i ] ] == 0){

            if(m[ c[ i ] ] == 0 && m1[ c[ i ] ] != 0 ){

                int d = m1[ c[ i ] ];

                for(int j = 0; j < d; j++){



                }
            }
        }
    }

    return 0;
}
