#include<bits/stdc++.h>
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

const int N = 1e6;
const int inf = 1e9;
bool prime[ N ];

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

struct node{

    bool mark;
    node *next[ 26 ];

    node(){

        mark = 0;
        for(int i = 0; i < 26; i++) next[ i ] = NULL;
    }
}* root;

void Insert(string s,int len){

    node *temp = root;

    for(int i = 0; i < len; i++){

        int idx = s[ i ] - 'a';

        if(temp->next[ idx ] == NULL) temp->next[ idx ] = new node();

        temp = temp->next[ idx ];
    }
    temp -> mark = true;
}

bool Search(string s,vector< int > &path){

    node *temp = root;
    int count_ = 0;
    int len = s.size();

    for(int i = 0; i < len; i++){

        int idx = s[ i ] - 'a';

        if(temp -> next[ idx ] == NULL) return false;
        count_++;

        if(temp -> mark and i < len) path.push_back( count_ );

        temp = temp -> next[ idx ];
    }
    return temp -> mark;
}

void Delete(node *temp){

    for(int i = 0; i < 26; i++)
        if(temp->next[ i ] != NULL) Delete(temp->next[ i ]);

    delete( temp );
}
int main(){

    //file();

    string s,ch;
    vector< string > v;
    vector< int > pa,faw;

    root = new node();

    while( cin >> s ){

        v.push_back( s );

        Insert(s,s.size());
    }

    int len = v.size();

    for(int i = 0; i < len; i++){

        pa.clear();
        faw.clear();
        bool flag = false;

        s = v[ i ];
        Search(s,pa);

        for(int j = 0; j < pa.size(); j++){

            ch = "";

            for(int k = pa[ j ] - 1; k < s.size(); k++) ch += s[ k ];

            if(Search(ch,faw)){

                flag = true;
                break;
            }
        }
        if( flag ) cout << s << endl;
    }

    Delete( root );

    return 0;
}
