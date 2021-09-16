#include<bits/stdc++.h>
#define pi acos(-1)

using namespace std;

int main(){

    freopen("input.txt","r",stdin);

    int t;

    cin >> t;

    while(t--){

        int n,c0,c1,h,ans = 0;
        string s;

        cin >>n >> c0 >> c1 >> h;

        cin >> s;

        if(c0 < c1){

            if((c0 + h) < c1)
            for(int i = 0; i < n; i++){

                if(s[ i ] == '0') ans += c0;
                else ans += (h + c0);
            }
            else{
                for(int i = 0; i < n; i++){

                    if(s[ i ] == '0') ans += c0;
                    else ans += c1;
                }
            }
        }
        else if(c1 < c0){

            if((h + c1) < c0)
            for(int i = 0; i < n; i++){

                if(s[ i ] == '0') ans += (h + c1);
                else ans += c1;
            }
            else
            for(int i = 0; i < n; i++){

                if(s[ i ] == '0') ans += c0;
                else ans += c1;
            }

        }
        else if(h > c0 and h > c1 or h == c0 or h == c1){

            for(int i = 0; i < n; i++){

                if(s[ i ] == '0') ans += c0;
                else ans += c1;
            }
        }
        else if(h > c0 or h > c1){

            if(h > c0 and h < c1){

                if(c0 + h < c1)
                for(int i = 0; i < n; i++){

                    if(s[ i ] == '0') ans += c0;
                    else ans += (h + c0);
                }
                else
                for(int i = 0; i < n; i++){

                    if(s[ i ] == '0') ans += c0;
                    else ans += c1;
                }
            }
            else if(h < c0 and h > c1){

                if((h + c1) < c0)
                for(int i = 0; i < n; i++){

                    if(s[ i ] == '0') ans += (h + c1);
                    else ans += c1;
                }
                else
                for(int i = 0; i < n; i++){

                    if(s[ i ] == '0') ans += c0;
                    else ans += c1;
                }
            }
        }
        else {

            for(int i = 0; i < n; i++){

                if(s[ i ] == '0') ans += c0;
                else ans += c1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
