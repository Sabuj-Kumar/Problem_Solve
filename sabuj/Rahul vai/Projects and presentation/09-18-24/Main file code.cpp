#include <stdio.h>
#include <string.h>
#include <windows.h>


struct Railway
{
    char express_name[100];
    int trains;
    bool available;
    char t_list[100][20];
} all[100];
void data_print(Railway A)
{
    printf("%s has ",A.express_name);
    printf("%d trains \nstatus: ",A.trains);
    A.available ? puts("available") : puts("not available");// this Idea , turnari
    puts("train list");
    for(int i=0; i<A.trains; i++) printf("%s. ",A.t_list[i]);
    puts("\n");
}
struct train_details_list
{
    char name[100], number[100];
    int a_hour,a_min, d_hour,d_min;
    int capacity,available_seats;
    char passenger[100][35];
}detail[100];
void train_detail_print(train_details_list x)
{
    printf("   %s %s   \n",x.name,x.number);
    printf("capacity is %d and %d available seats. \n",x.capacity,x.available_seats);
    printf("arrival time %d:%d\n",x.a_hour,x.a_min);
    printf("departure time %d:%d\nPassenger List\n",x.d_hour,x.d_min);
    for(int i=0; i<x.capacity-x.available_seats; i++)
        puts(x.passenger[i]);
    puts("\n");
}
void file_one()
{
    FILE *P1;
    P1=fopen("project_1.txt","r+");
    for(int i=0, j; i<10; i++)
    {
        char c[100],ch[100];
        fscanf(P1,"%s %s",ch, all[i].express_name);
        fscanf(P1,"%s %d",ch, &all[i].trains);

        fscanf(P1,"%s %s",ch, c);
        (!strcmp(c,"Yes"))? all[i].available=1 : all[i].available=0; //boolian operation

        fscanf(P1,"%s",ch);
        for(j=0; j<all[i].trains; j++) fscanf(P1,"%s", all[i].t_list[j]);
        all[i].t_list[j-1][(strlen(all[i].t_list[j-1])-1)]='\0';
    }
}
void file_two()
{
    FILE *P2;
    P2=fopen("project_2.txt","r+");
    for(int i=0, j; i<40; i++)
    {
        char c[100],ch[100];
        fscanf(P2,"%s %s %s",ch, detail[i].name,detail[i].number);
        fscanf(P2,"%s %d",ch, &detail[i].capacity);
        fscanf(P2,"%s %d",ch, &detail[i].available_seats);

        fscanf(P2,"%s %d:%d",ch,&detail[i].a_hour,&detail[i].a_min);
        fscanf(P2,"%s %d:%d",ch,&detail[i].d_hour,&detail[i].d_min);
    }
}
void user()
{
    puts("\t*******************************************************\n\n\t\t\t\tWeLcOmE\n\t\t\t  Bangladesh Railway\n\n\t\t\t    Ticket Counter\n\n\t*******************************************************");
    char ch[100],str[100];
    for(;;)
    {
        puts("\t\t    Available  expresses\n");
        puts(" \t\t\tSilkcity\n \t\t\tAntanagar\n \t\t\tMohanagar\n \t\t\tPadma\n \t\t\tJamuna\n \t\t\tDaulodia\n \t\t\tDhaleswar\n \t\t\tMohonbagan\n \t\t\tRajani\n \t\t\tjaidevpur\n");
        printf("\t\tWhich express do you want..??\n\t\tPlease type the express name\n\n ");
        scanf("%s",ch);
        int needed=-1, Needed_train_no;
        for(int i=0; i<10; i++) if(!strcmp(ch,all[i].express_name)) needed=i;
        puts("  #*#*#*#*#  here is the detail of this expresses  #*#*#*#*# \n");
        if(needed==-1) break;
        data_print(all[needed]);
        puts("  Please enter the experss name with the train number you want... ");
        scanf("%s %s",ch,str);
        for(int i=0; i<40; i++) if(!strcmp(ch,detail[i].name)&&!strcmp(str,detail[i].number)) Needed_train_no=i;
        train_detail_print(detail[Needed_train_no]);
        if(detail[Needed_train_no].available_seats!=0)
        {
            puts("  please enter your name");
            getchar();
            gets(detail[Needed_train_no].passenger[ detail[Needed_train_no].capacity - detail[Needed_train_no].available_seats ]);
            detail[Needed_train_no].available_seats--;
            printf("\n\n Welcome...!!!\n Your ticket number is %d\n",detail[Needed_train_no].capacity-detail[Needed_train_no].available_seats);
        }
        else puts("\nsorry...!!! not available");
        puts("\n\n-------------------------------------------------------------------\n");
    }
}
int main()
{

    //system("color 40");
    file_one();
    file_two();
    user();
    return 0;
}

