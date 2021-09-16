#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    vector<pair<int,int > > p;
    string a = "abcdefghijklmnopqrstuvwxyz";
    map<char,queue<int> > mp,mp1,mp2,mp3;
    map<int,int > one,two;

    string s,c;

    cin >> n;
    cin >> s;
    cin >> c;

    for(int i = 0; i < s.size(); i++){

        if(s[ i ] != '?') mp[ s[ i ] ].push( i );

        else mp1[ '?' ].push( i );

        if(c[ i ] != '?') mp2[c[ i ] ].push( i );

        else mp3[ '?' ].push( i );
    }

    for(int i = 0; i < a.size(); i++){

        char b = a[ i ];

        while(!mp[ b ].empty() || !mp2[ b ].empty()){

            while(!mp[ b ].empty()){

                int f = 0,l,k = mp[ b ].front();

                mp[ b ].pop();

                if(!mp2[ b ].empty() || !mp3[ '?' ].empty()){

                    if(!mp2[ b ].empty()){

                        l = mp2[ b ].front();

                        mp2[ b ].pop();

                        p.push_back({k,l});
                    }
                    else if(!mp3[ '?' ].empty()){

                        l = mp3[ '?' ].front();

                        mp3[ '?' ].pop();

                        p.push_back({k,l});
                    }
                    else f = 1;
                }
                if( f ) break;
            }

            while(!mp2[ b ].empty()){

                int l,k = mp2[ b ].front();

                mp2[ b ].pop();

                if(!mp1[ '?' ].empty()){

                    l = mp1[ '?' ].front();

                    mp1[ '?' ].pop();

                    p.push_back({l,k});
                }

                else break;
            }
        }
    }

    if(!mp1[ '?' ].empty() && !mp3[ '?' ].empty()){

        if(mp1[ '?' ].size() < mp3[ '?' ].size()){

            while(!mp1[ '?' ].empty()){

                int k = mp1[ '?' ].front();
                int l = mp3[ '?' ].front();

                mp1[ '?' ].pop();
                mp3[ '?' ].pop();

                p.push_back({k,l});
            }
        }
        else {

            while(!mp3[ '?' ].empty()){

                int k = mp1[ '?' ].front();
                int l = mp3[ '?' ].front();

                mp1[ '?' ].pop();
                mp3[ '?' ].pop();

                p.push_back({k,l});
            }
        }
    }

    cout << p.size() << endl;

    for(int i = 0; i < p.size(); i++)
        cout << p[ i ].first+1 << " " << p[ i ].second+1 << endl;

    return 0;
}
