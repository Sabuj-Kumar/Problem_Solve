#include<bits/stdc++.h>

using namespace std;

int main(){

    //freopen("input.txt","r",stdin);

    int test;

    scanf("%d",&test);

    for(int t = 1; t <= test; t++){

        int n;
        int a,b,c,r_cost = 0,l_cost = 0;

        scanf("%d",&n);

        bool r[ n + 5 ],l[ n + 5 ];

        memset(r,false,sizeof r);
        memset(l,false,sizeof l);

        while(n--){

            scanf("%d %d %d",&a,&b,&c);

            if(!l[ a ] && !r[ b ]){

                l[ a ] = r[ b ] = true;

                l_cost += c;
            }
            else {

                r[ a ] = l[ b ] = true;

                r_cost += c;
            }
        }

        cout << "Case " << t << ": " << min(l_cost,r_cost) << endl;
    }

    return 0;
}

