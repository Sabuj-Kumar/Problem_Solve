#include<bits/stdc++.h>

using namespace std;

map<string,vector<string > > graph;
map<string,int> m;
vector<pair < string,int> > v1;

bool cmp(pair< string,int > a,pair<string,int > b){

    if(a.second > b.second || a.second < b.second) return a.second < b.second;

    else if(a.second == b.second){

        if(a.first < b.first) return a.first < b.first;

        else return a.first < b.first;
    }
}
void BFS(string n){

    queue< string > q;

    m[ n ] = 0;

    v1.push_back( { n , m[ n ] } );

    q.push( n );

    while(!q.empty()){

        string s = q.front();

        q.pop();

        for(auto x : graph[ s ]){

            if(m[ x ] == 0 && x != "Ahmad") {

                m[ x ] = m[ s ]+1;

                v1.push_back( { x , m[ x ] } );

                q.push( x );
            }
        }
    }
}
int main(){

    //freopen("input.txt","r",stdin);

    int test;

    cin >> test;

    while(test--){

        int n,count_ = 0;
        map<string,int> mp;
        vector<string> v;

        cin >> n;
        cin.ignore();

        for(int i = 0; i < n; i++){

            string s,a,b,c;

            getline(cin,s);

            stringstream ss(s);

            ss >> a;
            ss >> b;
            ss >> c;

            if(mp[ a ] == 0) mp[ a ] = 1,v.push_back( a );
            if(mp[ b ] == 0) mp[ b ] = 1,v.push_back( b );
            if(mp[ c ] == 0) mp[ c ] = 1,v.push_back( c );

            graph[ a ].push_back( b );
            graph[ b ].push_back( a );

            graph[ a ].push_back( c );
            graph[ c ].push_back( a );

            graph[ b ].push_back( c );
            graph[ c ].push_back( b );
        }

        BFS( "Ahmad" );

        cout << v.size() << endl;

        sort(v1.begin(),v1.end(),cmp);

        map <string,string> p;

        for(int i = 0; i < v1.size(); i++){

            cout << v1[ i ].first << " " << v1[ i ].second << endl;
        }
        for(int i = 0; i < v.size(); i++){

            if(v[ i ] != "Ahmad" && m[ v[ i ] ] == 0)
                p[ v[ i ] ] = "undefined";
        }
        for(auto it = p.begin(); it != p.end(); it++)
            cout << it -> first << " " << it-> second << endl;

        graph.clear();
        v.clear();
        v1.clear();
        m.clear();
        mp.clear();
    }

    return 0;
}
