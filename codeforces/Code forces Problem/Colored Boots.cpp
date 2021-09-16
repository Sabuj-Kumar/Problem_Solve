#include<bits/stdc++.h>

using namespace std;

map<char,queue<int > > m;
map<char,queue<int > > m1;

map<char,queue<int > > sp;
map<char,queue<int > > np;

vector< pair<int,int> > p;

string str = "abcdefghijklmnopqrstuvwxyz";

int main(){

    //freopen("input.txt","r",stdin);

    int n;

    cin >> n;

    string s,s1;

    cin >> s;

    cin >> s1;

    for(int i = 0; i < n; i++){

        if(s[ i ] != '?') m[ s[ i ] ].push( i );

        else sp[ '?' ].push( i );
    }

    for(int i = 0; i < n; i++){

        if(s1[ i ] != '?') m1[ s1[ i ] ].push( i );

        else np[ '?' ].push( i );
    }

//    for(auto it = m.begin(); it != m.end(); it++){
//
//        cout << it->first << " " << endl;
//
//        while(!it->second.empty()){
//
//            cout << it->second.front() << " ";
//
//            it->second.pop();
//        }
//        cout << endl;
//    }
//    for(auto it = m1.begin(); it != m1.end(); it++){
//
//        cout << it->first << " " << endl;
//
//        while(!it->second.empty()){
//
//            cout << it->second.front() << " ";
//
//            it->second.pop();
//        }
//        cout << endl;
//    }
//
//    while(!sp.empty()){
//
//        cout << sp[ '?' ].front() << endl;
//
//        sp[ '?' ].pop();
//    }
//    while(!np.empty()){
//
//        cout << np[ '?' ].front() << endl;
//
//        np[ '?' ].pop();
//    }

    for(int i = 0; i < n; i++){

        char ch = str[ i ];

        if(!m[ ch ].empty() && !m1[ ch ].empty()){

            int a = m[ ch ].front();
            m[ ch ].pop();

            int b = m1[ ch ].front();
            m1[ ch ].pop();

            p.push_back({a,b});
        }
        else if(!m[ ch ].empty()){

            int a = m[ ch ].front();

            m[ ch ].pop();

            if(!np.empty()){

                int b = np[ '?' ].front();

                np[ '?' ].pop();

                p.push_back({a,b});
            }
        }
        else if(!m1[ ch ].empty()){

            int a = m1[ ch ].front();

            m1[ ch ].pop();

            if(!sp.empty()){

                int b = sp[ '?' ].front();

                sp[ '?' ].pop();

                p.push_back({a,b});
            }
        }
        else{

            if(ch == '?')
            if(!sp[ ch ].empty() && !np[ ch ].empty()){

                int a = sp[ ch ].front();
                sp[ ch ].pop();

                int b = np[ ch ].front();
                np[ ch ].pop();

                p.push_back({a,b});
            }
        }
    }

    cout << p.size() << endl;

    for(int i = 0; i < p.size(); i++){

        cout << p[ i ].first+1 << " " << p[ i ].second+1 << endl;
    }

    return 0;
}
