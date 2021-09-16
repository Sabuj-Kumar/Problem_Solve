#include<bits/stdc++.h>

using namespace std;

int n;
string s;

int check(int ind){

    int cnt = 0;

    for(int i = ind; i < n; i++){

        if(s[ i ] == 'P') cnt++;
        else break;
    }
    return cnt;
}
int main(){

    //freopen("in.txt","r",stdin);

    int t;

    scanf("%d",&t);

    while( t-- ){

        scanf("%d",&n);
        cin >> s;
        int cnt = 0;

        for(int i = 0; i < n; i++){

            if(s[ i ] == 'A'){

                int x = check( i+1 );

                cnt = max(cnt,x);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
