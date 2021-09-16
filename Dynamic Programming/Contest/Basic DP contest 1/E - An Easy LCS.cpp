#include<bits/stdc++.h>

using namespace std;

string s,s1,ch,h;
int dp[ 110 ][ 110 ];
string dp1[ 110 ][ 110 ];
int vis[ 110 ][ 110 ];
int k;

int length_lcs(int i,int j){

    if(i == s.size() || j == s1.size()) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    int n = 0;

    if(s[ i ] == s1[ j ]){

        n = 1 + length_lcs(i + 1,j + 1);
    }
    else {

         n = max(n,length_lcs(i + 1,j));

         n = max(n,length_lcs(i,j + 1));
    }

    dp[ i ][ j ] = n;

    return dp[ i ][ j ];
}

void LCS(int i,int j){

    if(i == s.size() || j == s1.size()) return ;

    if(s[ i ] == s1[ j ]){

        ch += s[ i ];

        //cout << i << " " << j << " " << s[ i ] << endl;

        LCS(i+1,j+1);
    }

    else {

        if(dp[ i + 1 ][ j ] > dp[ i ][ j + 1] ) LCS(i+1,j);

        else  LCS(i,j+1);
    }
}

int main(){

    freopen("input.txt","r",stdin);

    int test;

    cin >> test;

    for(int i = 1; i <= test; i++){

        cin >> s >> s1;

        memset(dp,-1,sizeof dp);
        ch.clear();
        h.clear();

        length_lcs(0,0);

        LCS(0,0);

        cout << "Case " << i << ": ";

        if(!ch.empty()) cout << ch << endl;

        else cout << ":(" << endl;
    }

    return 0;
}
