#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    vector< pair< int,int > > v;

    int x,y;

    while(cin >> x >> y)  v.push_back({x,y});

    bool flag = true;

    for(int i = 1; i < v.size(); i++){

        if(v[ i - 1 ].second != v[ i ].first) { flag = false; break; }
    }

    if( flag )printf("true\n");
    else printf("false\n");

    return 0;
}
