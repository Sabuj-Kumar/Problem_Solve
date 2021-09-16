#include<bits/stdc++.h>
#define ll long long
#define ull unsiged long long
#define db double
#define ldb long double
#define pi acos(-1)
#define pii pair< int ,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define p_b push_back
#define p_f push_front
#define lop(v,n) for(int i = v; i < n; i += 1)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define in freopen("in.txt","r",stdin);
#define op ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;
    data(){}
    data(int x,int y) { this->x = x,this->y = y;}
    data(int x,int y,int c) { this->x = x,this-> y = y,this->c = c; }
    bool operator < (const data &a) const{

        return c > a.c;
    }
};

db scd() { db n; cin >> n; return n; }
int sc() { int n; cin >> n; return n; }

db area(db ab,db ac,db bc,db ad){

    db ae = (ad * ac) / ab;
    db de = (ad * bc) / ab;
    db s_b = (ab + ac + bc) / 2.0;
    db s_s = (ad + ae + de) / 2.0;

    db area_b = sqrt( s_b *( s_b - ab) * (s_b - ac) * (s_b - bc) );
    db area_s = sqrt( s_s *( s_s - ad) * (s_s - ae) * (s_s - de) );

    db trp_area = (area_b - area_s);
    db rati0 = (area_s / trp_area);

    return rati0;
}

db binary(db ab,db ac,db bc,db rati0){

   db L = 0.0,R = ab;
   db mid,ra,ans;

   while(L < R){

        mid = (L + R) / 2.0;
        ans = mid;
        ra = area(ab,ac,bc,mid);
        if( ra > rati0) R = mid;
        else  L = mid;

        if(abs(ra - rati0) <= 0.0000001) return mid;
   }
}
int main(){

    op
    file();

    int test = sc();

    for(int cs = 1; cs <= test; cs++){

        db a = scd(),b = scd(),c = scd(),r = scd();
        cout << fixed << setprecision(10);
        ///cout << "Case " << cs << ": " << binary(a,b,c,r) << endl;
        ///cout << "Case " << cs << ": " << (db)sqrt(r/(r+1))*a << endl;
    }

    return 0;
}
