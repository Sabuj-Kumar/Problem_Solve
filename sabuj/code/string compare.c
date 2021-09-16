#include<stdio.h>
int main()
{
    char s1[100],s2[100];
    int i,j,ln1,ln2,cheak,n;
    printf("Enter The First String :");
      gets(s1);
      printf("\n");
    printf("Enter The Second String :");
      gets(s2);
       printf("\n");
    for(i=0; s1[i]!='\0'; i++)
    {
        ln1=i;
    }
    ln1=i++;
    printf("\nFirst String Length Is = %d\n",ln1);
    for(j=0; s2[j]!='\0'; j++)
    {
        ln2=j;
    }
    ln2=j++;
    printf("Second String Is = %d\n",ln2);
    i=0;
    j=0;
    if(ln1==ln2)
    {
        for(n=0;n<ln1;n++)
        {
           if(s1[i]==s2[j])
           {
               cheak=0;
           }
           else
           {
               cheak=1;
               break;
           }
          i++;
          j++;
        }
      if(cheak==0)
          printf("\nTwo String's Is Same.\n");
      else
          printf("\nTwo String's Is Not Same.\n");
    }
   else
   {
     printf("\nTwo String Is Not Same\n");
   }
}
