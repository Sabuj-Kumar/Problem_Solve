#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int array[n];
    int i ;
    int a;
    int mx =0;
    int secondmax=0;
    for( i =0;i<n;i++){
        scanf("%d",&a);
        if(a>mx)
        {
            secondmax = mx;
            mx=a;
        }
    }
    cout<<mx<<endl;
    cout<<secondmax<<endl;

}

