#include<stdio.h>
int main()
{
    int A1[100][100],A2[100][100],Mult[100][100],i,j,n,m,p,q,k,Sum=0;

    printf("Enter The First Matrix Row And Columns : ");
    scanf("%d%d",&m,&n);

    printf("\n");

    printf("Enter The Second Matrix Row And Columns : ");
    scanf("%d%d",&p,&q);

    if(n==p)
    {
        printf("\nEnter The A1 Matrix Element's :\n");
         for(i=0;i<m;i++)
        {
          for(j=0;j<n;j++)
           {
            scanf("%d",&A1[i][j]);
           }
        }

        printf("\nEnter The A2 Matrix Element's :\n");

        for(i=0;i<p;i++)
         {
           for(j=0;j<q;j++)
            {
               scanf("%d",&A2[i][j]);
            }
         }

       printf("\nA1 Matrix Element's Is:\n");

         for(i=0;i<m;i++)
        {
          for(j=0;j<n;j++)
           {
            printf("\t%d",A1[i][j]);
           }
          printf("\n");
        }

        printf("\nA2 Matrix Element's Is:\n");

        for(i=0;i<p;i++)
         {
           for(j=0;j<q;j++)
            {
               printf("\t%d",A2[i][j]);
            }
            printf("\n");
         }

        printf("\nMultiplication Matrix Is :\n");

         for(i=0;i<m;i++)
         {
           for(j=0;j<q;j++)
            {
               for (k=0;k<p;k++)
                {
                  Sum=Sum+A1[i][k]*A2[k][j];
                }
               Mult[i][j]=Sum;
                Sum=0;
           }
         }


         for(i=0;i<m;i++)
         {
             for(j=0;j<q;j++)
             {
                 printf("%d\t",Mult[i][j]);
             }
             printf("\n");
         }
   }
   else
   {
       printf("\nInvalid Input.\n");
   }

}
