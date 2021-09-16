#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pb push_back
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int mx;

int I() {int n; scanf("%d",&n); return n; }
int Il(){ll n; scanf("%I64d",&n); return n; }

void B_S(int val){

   for(int i = 2; i * i <= val; i++){

        if(!(val % i)){

            mx = max(mx,i);
            mx = max(mx,val/i);
        }
   }
}
int main(){

    file();

    int n = I();

    while(n--){

        int val = I();

        if(!(val % 2)){

            if(!(val % 2)) cout << val / 2 << " " << val / 2 << endl;
            continue;
        }

        mx = -1;

        B_S( val );

        if(mx == -1) cout << 1 << " " << val - 1 << endl;
        else cout <<  mx << " "<< val - mx << endl;
    }
    return 0;
}
