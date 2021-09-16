#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

queue<int> q[1001];
map<int,int> mp;

int main()
{
    int team;

    while(scanf("%d",&team) && team != 0)
    {
        int member,player;

        for(int i = 1; i <= team; i++)
        {
            scanf("%d",&member);

            for(int j = 0; j < member; j++)
            {
                scanf("%d",&player);

                mp[ player ] = i;
                q[ i ].push(player);
            }
        }

        string input;

        while(cin >> input && input != "STOP")
        {
            if(input == "ENQUEUE")
            {
                scanf("%d",&player);

            }

        }



    }
    return 0;
}
