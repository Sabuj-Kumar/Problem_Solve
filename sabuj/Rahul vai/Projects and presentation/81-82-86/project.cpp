#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int M=98;
struct info
{
    char acc_id[100];
    char name[32],cre_card_name[10];
    char cre_card_num[100],avail_bal[20],date[15];
    char last_withdraw[20],last_dep[20];
    char last_withdraw_date[15];
    char last_dep_date[20],last_tran[10];
    int bill;
} s[1000];

void print(info A)
{
    printf("\n\t\tDate :");
    puts(A.date);
    printf("\t\tAccount Number : ");
    puts(A.acc_id);
    printf("\t\tAccount Name : ");
    puts(A.name);
    printf("\t\tLast Withdraw Amount : ");
    puts(A.last_withdraw);
    printf("\t\tLast Withdraw Date : ");
    puts(A.last_withdraw_date);
    printf("\t\tLast Deposit Amount : ");
    puts(A.last_dep);
    printf("\t\tLast Deposit Date : ");
    puts(A.last_dep_date);
    printf("\t\tAvailable Balance : ");
    puts(A.avail_bal);
    printf("\t\tCredit Card Type : ");
    puts(A.cre_card_name);
    printf("\t\tLast Transection : ");
    puts(A.last_tran);
    printf("\t\tCurrent Bill : ");
    printf("%d", A.bill);
    printf("\n\n");
}
void file_1()
{
    FILE *p;
    p=fopen("Detail.txt", "r");
    int i=0;
    char ch[100], str[100], baal[100];
    for(int i=0; i<100; i++)
    {
        fscanf(p,"%s %s",ch,s[i].date);
        fscanf(p,"%s %s",ch,s[i].acc_id);
        fscanf(p,"%s %s",ch,s[i].name);
        fscanf(p,"%s %s",ch,s[i].last_withdraw);
        fscanf(p,"%s %s",ch,s[i].last_withdraw_date);
        fscanf(p,"%s %s",ch,s[i].last_dep);
        fscanf(p,"%s %s",ch,s[i].last_dep_date);
        fscanf(p,"%s %s",ch,s[i].avail_bal);
        fscanf(p,"%s %s",ch,s[i].cre_card_name);
        fscanf(p,"%s %s",ch,s[i].last_tran);
        fscanf(p,"%s %d",ch,&s[i].bill);
    }
    //for(int i=90; i<98; i++) print(s[i]);
}
int main()
{
    int n;
    file_1();

    printf("\n\t\t*****    Bank Account Management    *****\n\n\n");
    while(1)
    {
        printf("\n\n\n\t\tRegister for new account ------- PRESS '1'\n\t\tFor account statement    ------- PRESS '2'\n\t\tfor exit press '0'\n");
        printf("\n\n\t\t");
        scanf("%d",&n);
        if(n==1)
        {
            printf("\n\n\t\tEnter today's date ... ");
            scanf("%s",s[M].date);
            printf("\t\tEnter Account ID ... ");
            scanf("%s",s[M].acc_id);
            printf("\t\tEnter user name ... ");
            scanf("%s",s[M].name);
            strcpy( s[M].last_withdraw, "0" );
            strcpy( s[M].last_withdraw_date, "0" );
            strcpy( s[M].last_dep, "0" );
            strcpy( s[M].last_dep_date, "0" );
            strcpy( s[M].avail_bal, "0" );
            printf("\t\tEnter Credit Card name ... ");
            scanf("%s",s[M].cre_card_name);
            strcpy(s[M].last_tran,"0");
            s[M].bill=0;
            M++;
        }
        else if(n==2)
        {
            printf("\n\n\t\tCheck Account Statement?\n\n");
            printf("\t\tEnter Acount Number: ");
            char ch[100];
            scanf("%s",ch);
            int i=0;
            for(i=0; i<M; i++)
                if(strcmp(ch,s[i].acc_id)==0)
                {
                    print(s[i]);
                    break;
                }
            if(i==M) printf("\n\t\tno account found..!!\n\n");
        }
        else break;
    }
    return 0;
}
