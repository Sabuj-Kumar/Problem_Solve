#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
int main()
{

    FILE *fp;
    char ch,s[100],r[100];
    int i=0,j=0,k=0;
    printf("Quick search : ");
    gets(s);
    while(s[j])
    {
        s[j]=tolower(s[j]);
        j++;
    }
    s[j]='\0';
    fp=fopen("dictionary.txt","r+");
    while(!feof(fp))
    {
        ch=fgetc(fp);
        //putchar(ch);
        if(ch==':')
        {
            //putchar(ch);
            r[i]='\0';
            //puts(r);
            i=0;
            if(strcmp(r,s)==0)
            {
                k=0;
                ch=fgetc(fp);
                printf("%s means : ",s);
                while(ch!='\n')
                {
                   putchar(ch);
                   ch=fgetc(fp);
                }
                printf("\n");
            }
            else
            {
                k=1;
            }
        }
        else
        {
            r[i]=ch;
            i++;
        }
        if(k==1)
        {
            k=0;
            ch=fgetc(fp);
            while(ch!='\n')
            {
                ch=fgetc(fp);
            }
        }

    }
    fclose(fp);
    getche();
    return 0;
}
