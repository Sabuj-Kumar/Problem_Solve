#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

deque< int > dq;
vector< int > vc;

int main()
{
    int N;

    while(scanf("%d",&N) && N)
    {
        for(int i = 1; i <= N; i++)
           dq.push_back(i);

        while(dq.size() > 1)
        {
            vc.push_back(dq.front());
            dq.pop_front();
            dq.push_back(dq.front());
            dq.pop_front();
        }

        cout << "Discarded cards:";
        for(int i = 0; i < vc.size(); i++)
        {
            cout <<" "<<vc[i];

            if(i < vc.size() - 1)
                cout << ',';
        }
        cout << "\n" << "Remaining card: ";
        cout << dq.front() << endl;
        dq.clear();
        vc.clear();
    }
    return 0;
}
