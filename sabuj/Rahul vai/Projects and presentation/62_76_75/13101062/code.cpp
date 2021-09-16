#include <cstdio>
#include <cstring>
using namespace std;
struct data
{
    char express_name[100];
    int trains;
    bool available;
    char t_list[100][20];
} all[100];
void data_print(data A)
{
    printf("%s has ",A.express_name);
    printf("%d trains \nstatus: ",A.trains);
    A.available ? puts("available") : puts("not available");
    puts("train list");
    for(int i=0; i<A.trains; i++) printf("%s. ",A.t_list[i]);
    puts("\n");
}
struct train_detail
{
    char name[100], number[100];
    int a_hour,a_min, d_hour,d_min;
    int capacity,available_seats;
    char passenger[100][35];
}detail[100];
void train_detail_print(train_detail U)
{
    printf("   %s %s   \n",U.name,U.number);
    printf("capacity is %d and %d available seats. \n",U.capacity,U.available_seats);
    printf("arrival time %d:%d\n",U.a_hour,U.a_min);
    printf("departure time %d:%d\nPassenger List\n",U.d_hour,U.d_min);
    for(int i=0; i<U.capacity-U.available_seats; i++)
        puts(U.passenger[i]);
    puts("\n");
}
void file_one()
{
    FILE *P1;
    P1=fopen("project_1.txt","r+");
    for(int i=0, j; i<5; i++)
    {
        char c[100],ch[100];
        fscanf(P1,"%s %s",ch, all[i].express_name);
        fscanf(P1,"%s %d",ch, &all[i].trains);

        fscanf(P1,"%s %s",ch, c);
        (!strcmp(c,"Yes"))? all[i].available=1 : all[i].available=0;

        fscanf(P1,"%s",ch);
        for(j=0; j<all[i].trains; j++) fscanf(P1,"%s", all[i].t_list[j]);
        all[i].t_list[j-1][(strlen(all[i].t_list[j-1])-1)]='\0';
    }
}
void file_two()
{
    FILE *P2;
    P2=fopen("project_2.txt","r+");
    for(int i=0, j; i<20; i++)
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
    puts("\t***********************************************\n\n\n\t\tRailway Ticket Management\n\n\n\t***********************************************\n");
    char ch[100],str[100];
    for(;;)
    {
        puts("The following expresses are available\n");
        puts(" Padma\n Silkcity\n Mohanagar\n Antanagar\n Jamuna\n");
        printf("Which express do you want..??\nPlease type the express name ");
        scanf("%s",ch);
        int wanted, wanted_train_number;
        for(int i=0; i<5; i++) if(!strcmp(ch,all[i].express_name)) wanted=i;
        puts("here is the detail of this express \n");
        data_print(all[wanted]);
        puts("Please enter the experss name with the train number you want... ");
        scanf("%s %s",ch,str);
        for(int i=0; i<20; i++) if(!strcmp(ch,detail[i].name)&&!strcmp(str,detail[i].number)) wanted_train_number=i;
        train_detail_print(detail[wanted_train_number]);
        if(detail[wanted_train_number].available_seats!=0)
        {
            puts("please enter your name");
            getchar();
            gets(detail[wanted_train_number].passenger[ detail[wanted_train_number].capacity - detail[wanted_train_number].available_seats ]);
            detail[wanted_train_number].available_seats--;
            printf("\n\nWelcome...!!!\nYour ticket number is %d\n",detail[wanted_train_number].capacity-detail[wanted_train_number].available_seats);
        }
        else puts("\nsorry...!!! not available");
        puts("\n\n-------------------------------------------------------------------\n");
    }
}
int main()
{
    file_one();
    file_two();
    user();
    return 0;
}
