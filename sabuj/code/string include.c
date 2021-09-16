#include<stdio.h>
#include<string.h>
int main()
{
    char s1[100],s2[100];
    int i,j,ln1=0,ln2=0,count=0,n=0,m=0;
    printf("Enter The First String : ");
    gets(s1);
    printf("\n");
    printf("Enter The second String : ");
    gets(s2);
    for(i=0; s1[i]!='\0'; i++)
      ln1=i;
    ln1++;

    for(j=0; s2[j]!='\0'; j++)
      ln2=j;
    ln2++;
    if(ln1>=ln2)
    {
        for(i=n; i<ln1; i++)
        {
            for(j=m; j<ln2; j++)
            {
                if(s1[i]==s2[j])
                {
                    count++;
                    n=i++;
                    m=j++;

                }
                else if(j<ln2)
                {
                    count=0;
                }
            }
        }
        printf("%d\n",count);
        printf("%d\n",ln2);

        if(ln2==count)
        {
            printf("Second String Is Include In First String. ");
        }
        else
        {
            printf("Second String Is Not Include In First String. ");
        }
    }

    else if(ln2>ln1)
    {
      for(i=0; i<ln2; i++)
        {
            for(j=0; j<ln1; j++)
            {
                if(s1[i]==s2[j])
                {
                    count++;
                    n=i;
                    m=j;
                    break;
                }
                else if(j<ln1)
                {
                    count=0;
                }
            }
        }
        printf("%d\n",count);
        printf("%d\n",ln1);

        if(ln1==count)
        {
            printf("First String Is Include In Second String. ");
        }
        else
        {
            printf("First String Is Not Include In Second String. ");
        }
    }

}
