#include<stdio.h>

int Binary_search( int a[],int end,int key )
{
    int mid,start = 0;

    while( start <= end )
    {
        mid = ( start + end ) / 2;

        if( a[mid] == key )
          return mid;

        else if( a[mid] > key )
          end = mid - 1;

        else
          start = mid + 1;
    }
    return -1;
}
int main()
{
    int N,i,result = 0,key;

    printf("Enter The Array Size : ");

    scanf("%d",&N);

    int a[N+1];

    printf("\n");

    printf("Enter The Element's Of Array : "); /// input must be sorted order.

    for( i = 0; i < N; i++ )
        scanf("%d",&a[i]);

    printf("\n");

    printf("Enter The Key Key Value : ");

    scanf("%d",&key);

    printf("\n");

    result = Binary_search( a,N,key );

    if( result != -1 )
       printf("Found %d at %d position.\n",key,result+1);

    else
       printf("Not Found\n");

    return 0;
}
