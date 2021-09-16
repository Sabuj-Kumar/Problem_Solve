#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double

using namespace std;

int main(){

    freopen("in.txt","r",stdin);

    int t;

    scanf("%d",&t);
    cout <<"t "<<t << endl;

    while(t--){

        int n,m;

        scanf("%d",&n);

        while(m > 1){

            cout << m%2 << " ";
            s += ((m % 2) - '0');
            m /= 2;
        }

        cout << endl;
        cout << s << endl;
    }
    return 0;
}
