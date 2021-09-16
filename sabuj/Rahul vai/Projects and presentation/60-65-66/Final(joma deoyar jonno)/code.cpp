#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
struct data
{
    char Airlines_name[1000];
    int Planes;
    bool available;
    char t_list[100][20];
}all[1000];
void data_print(data A)
{
    printf("%s has ",A.Airlines_name);
    printf("%d Planes \nstatus: ",A.Planes);
    A.available ? puts("available") : puts("not available");
    puts("plane list");
    for(int i=0; i<A.Planes; i++) printf("%s. ",A.t_list[i]);
    puts("\n");
}

struct plane_detail
{
    char name[1000], number[1000];
    int a_hour,a_min, d_hour,d_min;
    int capacity,available_seats;
    char passenger[100][35];
}detail[1000];
void plane_detail_print(plane_detail U)
{
    printf("   %s %s   \n",U.name,U.number);
    printf("capacity is %d and %d available seats. \n",U.capacity,U.available_seats);
    printf("arrival time %d:%d\n",U.a_hour,U.a_min);
    printf("departure time %d:%d\nPassenger List",U.d_hour,U.d_min);
    for(int i=0; i<U.capacity-U.available_seats; i++)
        puts(U.passenger[i]);
    puts("\n");
}

void file_one()
{
    FILE *P1;
    P1=fopen("file_1.txt","r+");
    for(int i=0, j; i<10; i++)
    {
        char c[1000],ch[1000];
        fscanf(P1,"%s %s",ch, all[i].Airlines_name);
        fscanf(P1,"%s %d",ch, &all[i].Planes);

        fscanf(P1,"%s %s",ch, c);
        (!strcmp(c,"Yes"))? all[i].available=1 : all[i].available=0;

        fscanf(P1,"%s",ch);
        for(j=0; j<all[i].Planes; j++) fscanf(P1,"%s", all[i].t_list[j]);
        all[i].t_list[j-1][(strlen(all[i].t_list[j-1])-1)]='\0';
    }
    //for(int i=0; i<10; i++) data_print(all[i]);
}
void file_two()
{
    FILE *P2;
    P2=fopen("file_2.txt","r+");
    for(int i=0, j; i<40; i++)
    {
        char c[1000],ch[1000];
        fscanf(P2,"%s %s %s",ch, detail[i].name,detail[i].number);
        fscanf(P2,"%s %d",ch, &detail[i].capacity);
        detail[i].available_seats=detail[i].capacity;
        fscanf(P2,"%s %d:%d",ch,&detail[i].a_hour,&detail[i].a_min);
        fscanf(P2,"%s %d:%d",ch,&detail[i].d_hour,&detail[i].d_min);

        fscanf(P2,"%s",ch);
        for(j=0; j<detail[i].capacity; j++) fscanf(P2,"%s", detail[i].passenger[j]);
    }
    //for(int i=0; i<40; i++) plane_detail_print(detail[i]);
}

void user()
{
    puts("\t\t*******************************\n\t\t*******************************\n\n\t\t\tAir Ticket Management\n\n\n\t\t*******************************\n\t\t*******************************\n");
    char ch[1000],str[1000];
    for(;;)
    {
        puts("The following planes are available\n");
        puts(" Bangladesh_Airlines\n Emirates_Airlines\n Japan_Airlines\n Kolkata_Airlines\n Riad_Airlines\n Quatar_Airlines\n Dubai_Airlines\n China_Eastern_Airlines\n Delta_Airlines\n Singapore_Airlines\n");
        printf("Which plane do you want..??\nPlease type the plane name ");
        scanf("%s",ch);
        int wanted, wanted_plane_number;
        for(int i=0; i<10; i++) if(!strcmp(ch,all[i].Airlines_name)) wanted=i;
        puts("here is the detail of this plane \n");
        data_print(all[wanted]);
        puts("Please enter the airlines name with the plane number you want... ");
        scanf("%s %s",ch,str);
        for(int i=0; i<40; i++)
           if(!strcmp(ch,detail[i].name)&&!strcmp(str,detail[i].number))
              wanted_plane_number=i;
        plane_detail_print(detail[wanted_plane_number]);
        if(detail[wanted_plane_number].available_seats!=0)
        {
            puts("please enter your name");
            getchar();
            gets(detail[wanted_plane_number].passenger[ detail[wanted_plane_number].capacity - detail[wanted_plane_number].available_seats ]);
            detail[wanted_plane_number].available_seats--;
            puts("\n\nWelcome...!!!");
            printf("Your ticket number is %d\n",detail[wanted_plane_number].capacity - detail[wanted_plane_number].available_seats);
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
