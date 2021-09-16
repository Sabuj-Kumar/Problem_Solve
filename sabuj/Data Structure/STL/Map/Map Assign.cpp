#include<stdio.h>
#include<iostream>
#include<map>
#include<iterator>

using namespace std;

int main()
{
    map<char,int> mymap;

    mymap.insert(pair<char,int> ('a',100));
    mymap.insert(pair<char,int> ('b',200));
    mymap.insert(pair<char,int> ('c',300));

    pair<map<char,int>::iterator,bool> it;

    it = mymap.insert(pair<char,int> ('a',400));

    if(it.second == false)
    {
        cout<<"Element 'a' Is Already Exist ";
        cout<<"With A Value Of "<<it.first->second<<'\n';
    }
    map<char,int>::iterator it1 = mymap.begin();

    mymap.insert(it1,pair<char,int> ('d',500));
    mymap.insert(it1,pair<char,int> ('e',600));

    map<char,int> youmap;

    youmap.insert(mymap.begin(),mymap.find('d'));

    cout<<"Mymap Is:"<<endl;

    for(it1 = mymap.begin(); it1 != mymap.end(); it1++)
        cout<<it1->first<<" = "<<it1->second<<endl;

    cout<<"Youmap Is:"<<endl;

    for(it1 = youmap.begin(); it1 != youmap.end(); it1++)
        cout<<it1->first<<" = "<<it1->second<<endl;

    return 0;
}
