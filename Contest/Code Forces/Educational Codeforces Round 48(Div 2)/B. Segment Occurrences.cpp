#include<bits/stdc++.h>

using namespace std;

string s,sub,c;

int main()
{
    int len1,len2,query,i,a,b;

    scanf("%d %d %d",&len1,&len2,&query);

    cin >> s;

    cin >> sub;

    if(sub.size() <= s.size())
    {
        for(i = 0; i < query; i++)
        {
            int n,j,count_ = 0;

            scanf("%d %d",&a,&b);

            for(j = a-1; j < b; j++)
            {
                for(n = j; n < sub.size()+j && n < b; n++)
                    c += s[ n ];

                if(c == sub) count_++;

                c.clear();

                if(n == b|| n > b)
                    break;
            }
            printf("%d\n",count_);
        }
    }
    else
        for(int j = 0; j < query; j++)
        {
             scanf("%d %d",&a,&b);
             printf("0\n");
        }

    return 0;
}
