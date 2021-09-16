#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
struct info{
    char bus_name[100];
    char depart_time[100];
    char root[100];
    int fare;
    int seat_avail;
} s[100];
int main(){
    int t = 10;

    printf("\t\t-------CHOOSE YOUR JOURNEY-------\n\n");
    FILE *x;
    x = fopen("Express List.txt","r");
    char ch;

    while((ch = fgetc(x)) != EOF){
        printf("%c", ch);
    }
    printf("\n");
    int m;

    scanf("%d", &m);
    FILE *fp1;
    if(m == 1){
        fp1 = fopen("HANIF.txt","r");
    }
    else if(m == 2){
        fp1 = fopen("EAGLE.txt","r");
    }
    else if(m == 3){
        fp1 = fopen("SHOHAGH.txt","r");
    }
    else if(m == 4){
        fp1 = fopen("GREEN LINE.txt","r");
    }
    else if(m == 5){
        fp1 = fopen("AK TRAVELS.txt","r");
    }

    int i = 0, j = 0, k, bus_name_flag = 0, time_flag = 0, root_flag = 0, fare_flag = 0, seat_flag = 0;
    char str[100];
    while((ch = fgetc(fp1)) != EOF){
        if(ch == '\n' && bus_name_flag == 1){
            str[i] = '\0';
            i = 0;

            bus_name_flag = 0;
            strcpy(s[j].bus_name, str);
        }
        if(ch=='\n' && time_flag==1){
            str[i]='\0';
            i = 0;

            time_flag = 0;
            strcpy(s[j].depart_time, str);
        }
        if(ch == '\n' && root_flag == 1){
            str[i] = '\0';
            i = 0;

            root_flag = 0;
            strcpy(s[j].root, str);
        }
        if(ch=='\n' && fare_flag==1)
        {
            str[i]='\0';
            i=0;
            fare_flag=0;
            s[j].fare=atoi(str);
        }
        if(ch=='\n' && seat_flag==1){
            str[i]='\0';
            i=0;
            seat_flag=0;
            s[j].seat_avail = atoi(str);
            j++;
        }
        if(ch == ':'){
            str[i] = '\0';
            i = 0;
            if(strcmp(str, "bus_name") == 0){
                bus_name_flag=1;
            }
            if(strcmp(str,"Depart. time") == 0){
                time_flag=1;
            }
             if(strcmp(str,"Root Name") == 0){
                root_flag=1;
            }
            if(strcmp(str,"Fare")==0){
                fare_flag=1;
            }
            if(strcmp(str,"Seat Avail.") == 0){
                seat_flag=1;
            }
        }
        else{
            if(ch != '\n'){
                str[i] = ch;
                i++;
            }
        }
    }
    if(seat_flag == 1){
        str[i] = '\0';
        i = 0;
        seat_flag = 0;
        s[j].seat_avail = atoi(str);
        j++;
    }
    fclose(fp1);
    for(i = 0; i < 7; i++){
        printf("BUS NO. :%d\n",i+1);
        printf("\t\tBus Name: ");
        puts(s[i].bus_name);
        printf("\t\tDeparture Time: ");
        puts(s[i].depart_time);
        printf("\t\tRoot Name: ");
        puts(s[i].root);
        fflush(stdin);
        printf("\t\tFare: %d\n",s[i].fare);
        printf("\t\tSeat Available: %d\n",s[i].seat_avail);
        printf("\n");
    }
    printf("\nDo you want to travel?\n\n\t\tif YES then press 1 \n\t\tif NO then press 2\n");
    int p;
    while(t--){
    scanf("%d",&p);

    if(p == 1)
    {
        printf("\nPlease choose your bus by pressing BUS NO.\n");
        int z;
        scanf("%d",&z);
        printf("\t\tBus Name: ");
        puts(s[z-1].bus_name);
        printf("\t\tDeparture Time: ");
        puts(s[z-1].depart_time);
        printf("\t\tRoot Name: ");
        puts(s[z-1].root);
        fflush(stdin);
        printf("\t\tFare: %d\n",s[z-1].fare);
        printf("\t\tSeat Available: %d\n",s[z-1].seat_avail);
        printf("\n");
        int f = s[z-1].seat_avail;

        printf("\t\tPassenger Name.....\n");
        char nm[32];
        gets(nm);
        printf("\t\tPassenger Phone NO.....\n");
        char h[15];
        gets(h);
           f--,s[z-1].seat_avail--;;
        printf("\t\tNow total seat available:%d\n", f);
        printf("\t\tPassenger Name: ");
        puts(nm);
        printf("\t\tPassenger Phn. NO.: ");
        puts(h);
    }
    else if(p == 2)exit;
    printf("\n\n\n\n\n");
    }
return 0;
}
