#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define db double
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE

}

int I() { int n; scanf("%d",&n); return n; }

int main(){

    file();

    int t = I();

    while( t-- ){

        int l = I();
        int r = I();

        if(2 * l <= r) cout << l << " " << 2 * l << endl;
        else cout << -1 << " " << -1 << endl;
    }
    return 0;
}
