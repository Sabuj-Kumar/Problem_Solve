#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m,n,n1,input;

   /// cin >>m>>n;

    vector < vector < int > > vec(m,vector<int>(n));

    map<vector<int>,int> mp;
    map<vector<int>,int>:: iterator it;

    map<pair<int,int>,int> mp1;

    pair<int,int> p;

    vector<int> v,v1;

//    for(int i = 0; i < m; i++)
//    {
//        cin >> input >> n1;
//
//        p = make_pair(input,n1);
//
//        mp1[p] = i;
//    }
//    for( map<pair<int,int>,int>::iterator it1 = mp1.begin(); it1 != mp1.end(); it1++)
//        cout << it1->first.first << " " << it1->first.second<< " "<< it1->second<<endl;



//    for(int i = 0; i < m; i++)
//    {
//        for(int j = 0; j < n; j++)
//        {
//            cin>> input;
//
//            v.push_back(input);
//        }
//        mp[v] = i;
//    }
//
//    for(it = mp.begin(); it != mp.end();it++)
//    {
//        for(int i = 0; i < n; i++)
//        {
//            cout << it -> first[i]<<" "<< it->second << "\n";
//        }
//    }
////    for(int i = 0; i < m; i++)
////      for(int j = 0;  j < n; j++)
////        cin>> vec[i][j];
//
//    for(int i = 0; i < m; i++)
//    {
//        for(int j = 0;  j < n; j++)
//            cout << vec[i][j] << " ";
//
//        cout << endl;
//    }
    return 0;
}
