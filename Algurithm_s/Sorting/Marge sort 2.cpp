#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void Marge(int A[],int start,int mid,int end,int n)
{
    int temp[n],i = start,j = mid + 1,k = 0,index = start;

    printf("%d %d %d\n",start,mid,end);

    while(i <= mid && j <= end)
    {
        if(A[i] <= A[j])
        {
            temp[index] = A[i];
            i++;
        }
        else
        {
            temp[index] = A[j];
            j++;
        }
       index++;
    }
    if(i <= mid)
        for(k = i; k <= mid; k++)
        temp[index++] = A[k];
    else
        for(k = i; k <= end; k++)
        temp[index++] = A[k];

    for(k = start; k <= end; k++)
        A[k] = temp[k];
}
void Marge_Sort(int A[],int start,int end,int n)
{
    int mid = (start + end) / 2;

    if(start >= end)
        return;

    Marge_Sort(A,start,mid,n);
    Marge_Sort(A,mid+1,end,n);
    Marge(A,start,mid,end,n);
}
int main()
{
    int n,i;

    scanf("%d",&n);

    int A[n];

    for(i = 0; i < n; i++)
        scanf("%d",&A[i]);

    Marge_Sort(A,0,(n-1),n);

    for(i = 0; i < n; i++)
        printf("%d ",A[i]);

    return 0;
}
