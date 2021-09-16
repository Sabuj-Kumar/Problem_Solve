#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[]={3,6,5,9,2,4,7},i;
    for(i=0;i<7;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    sort(arr,arr+7);
    for(i=6;i>=0;i--)
        cout<<arr[i]<<" ";
        return 0;

}
