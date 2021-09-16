#include<bits/stdc++.h>

using namespace std;

int main(){

   // freopen("in.txt","r",stdin);

    string s[ 4 ];
    char ch,ch1;
    int x,y,cnt1 = 0,cnt2 = 0;
    bool flag1 = false,flag2 = false;

    for(int i = 0; i < 3; i++) cin >> s[ i ];

    for(int i = 0; i < 3; i++){

        for(int j = 0; j < s[ i ].size(); j++){

            if(s[ i ][ j ] == '=') {

                x = i,y = j;

                break;
            }
        }
    }

    int y1 = y + 1;

    while(y1 < s[ x ].size()){

        if(s[ x ][ y1 ] != '.') {

            ch = s[ x ][ y1 ];
            flag1 = true;

            break;
        }

        y1++;
    }

    if(flag1) cout << ch << endl;

    else cout << "You shall pass!!!" << endl;

    return 0;
}
