#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int N = 1e7;
int mod = 1000;

int I() { int n; scanf("%d",&n); return n; }

int main(){

    file();

    int n = I();

    while(n--){

        int sz = I();

        for(int i = 1; i <= sz; i++) cout << "1 ";
        cout << endl;
    }

    return 0;
}
