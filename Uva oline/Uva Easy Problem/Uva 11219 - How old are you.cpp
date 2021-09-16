#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n);
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main()
{
    int test;

    cin >> test;

    Case(test){

        int day1,month1,year1;
        int day2,month2,year2;

        scanf("%d/%d/%d",&day1,&month1,&year1);
        scanf("%d/%d/%d",&day2,&month2,&year2);

        int age = year1 - year2;

        if(month2 > month1) age--;
        if(month1 == month2 and day2 > day1) age--;

        if(age < 0) printf("Case #%d: Invalid birth date\n",cs);
        else if(age > 130) printf("Case #%d: Check birth date\n",cs);
        else printf("Case #%d: %d\n",cs,age);
    }
    return 0;
}
