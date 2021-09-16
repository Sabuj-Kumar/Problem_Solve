#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int main(){

    //file();

    int length;

    string string_;

    cin >> length;
    cin >> string_;

    vector< pair< char,int > > frequencies;

    char character = '\0';

    int count_ = 0;

    for(int index = 0; index < length; index++){

        if(string_[ index ] == character)
            count_++;

        else{

            if(character != '\0') frequencies.push_back({character,count_});

            character = string_[ index ];

            count_ = 1;
        }
    }

    frequencies.push_back({character,count_});

//    for(int index = 0; index < frequencies.size(); index++){
//
//        cout << frequencies[ index ].first << " " << frequencies[ index ].second << endl;
//    }
    ll answer = 0;

    for(int index = 0; index < frequencies.size(); index++){

        int store_frequency = frequencies[ index ].second;

        answer += (store_frequency * (store_frequency + 1 )) / 2;
    }

    for(int index = 1; index < frequencies.size() - 1; index++){

        if(frequencies[ index - 1 ].first == frequencies[ index + 1 ].first and frequencies[ index ].second == 1)
            answer += min(frequencies[ index - 1 ].second,frequencies[ index + 1 ].second);
    }

    cout << answer << endl;

    return 0;
}
