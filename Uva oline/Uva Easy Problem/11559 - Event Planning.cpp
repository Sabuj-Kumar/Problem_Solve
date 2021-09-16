#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int main()
{
    int person,cost,hotel,bed;

    while(scanf("%d %d %d %d",&person,&cost,&hotel,&bed) != EOF)
    {
        int cost_hotel,total_bed,total_cost = 1010000,flag = 0;

        for(int j = 0; j < hotel; j++)
        {
            scanf("%d",&cost_hotel);

            for(int i = 0; i < bed; i++)
            {
                scanf("%d",&total_bed);

                if((cost_hotel * person) <= cost )
                {
                    if(person <= total_bed)
                    {
                        if((cost_hotel * person) < total_cost )
                            total_cost = cost_hotel * person;

                        flag = 1;
                    }
                }
            }
        }
        if(flag == 1)
          printf("%d\n",total_cost);

        else
          printf("stay home\n");
    }
    return 0;
}
