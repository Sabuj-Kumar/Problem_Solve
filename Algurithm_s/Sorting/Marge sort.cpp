#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void Marge(int A[],int start,int mid,int end,int n)
{
    int i,j,k,index = 0;
    int temp[n];

    i = start;
    j = mid + 1;

    while(i <= mid && j <= end)
    {
        if(A[i] < A[j])
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
    while(i <= mid)
    {
        temp[index] = A[i];
        i++;
        index++;
    }
    while(j <= end)
    {
        temp[index] = A[j];
        j++;
        index++;
    }
    for(i = start,k = 0; i <= end; i++,k++)
        A[i] = temp[k];
}
void marge_sort(int A[], int start, int end,int n)
{
    int mid;

    if(start >= end)
      return;

    mid = (start + end) / 2;

    marge_sort(A,start,mid,n);

    marge_sort(A,(mid + 1),end,n);

    Marge(A,start,mid,end,n);
}

int main()
{
    int n,i;

    scanf("%d",&n);

    int A[n];

    for(i = 0; i < n; i++)
        scanf("%d",&A[i]);

    marge_sort(A,0,n-1,n);

    for(int i = 0; i < n; i++)
        printf("%d ",A[i]);

    printf("\n");

    return 0;
}
