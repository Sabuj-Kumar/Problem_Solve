#include"stdio.h"
int main()
{
    int N,i,key,start = 0,mid = 0,end = 0;

    printf("Enter The Array Size :  ");
    scanf("%d",&N);
    printf("\n");

    printf("Enter The Element's Of Array : ");
    int a[N];
    for( i = 0; i < N; i++ )
    scanf("%d",&a[i]);

    printf("\n");

    printf("Enter The Key Value: ");
    scanf("%d",&key);
    printf("\n");

    end = N-1;

    for( i = 0;start <= end; i++ )
    {
        mid = ( start + end ) / 2;

        if( a[mid] == key )
        {
            printf("Find %d  at %d\n",key,++i);
            break;
        }
        else if( a[ mid ] < key )
            start = mid + 1;
        else
            end = mid - 1;
    }
    if( start > end )
       printf("Not Found\n");

    return 0;
}
