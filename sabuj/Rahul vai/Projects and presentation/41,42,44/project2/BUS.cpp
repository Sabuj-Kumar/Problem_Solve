#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
struct info{
    char bus_name[100];
    char depart_time[100];
    char root[100];
    int price;
    int seat_available;
} s[100];
int main(){

    system("color 1f ");
    printf("\t\t-------HAVE A GOOD JOURNEY-------\n\n");
    FILE *x;
    x = fopen("Expresses.txt","r");
    char ch;

    while((ch = fgetc(x)) != EOF){
        printf("%c", ch);
    }
    printf("\n");
    int m;

    scanf("%d", &m);
    FILE *fp1;
    if(m == 1){
        fp1 = fopen("SHAMOLY.txt","r");
    }
    else if(m == 2){
        fp1 = fopen("HANIF.txt","r");
    }
    else if(m == 3){
        fp1 = fopen("NABIL.txt","r");
    }
    else if(m == 4){
        fp1 = fopen("BABLU.txt","r");
    }
    else if(m == 5){
        fp1 = fopen("EAGLE.txt","r");
    }
    else if(m == 6){
        fp1 = fopen("SHOHAG.txt","r");
    }
    else if(m == 7){
        fp1 = fopen("GREEN_LINE.txt","r");
    }
    else if(m == 8){
        fp1 = fopen("SA_PARIBAHAN.txt","r");
    }
    else if(m == 9){
        fp1 = fopen("AK_TRAVELS.txt","r");
    }
    else if(m == 10){
        fp1 = fopen("RAHBER.txt","r");
    }

    int i = 0, j = 0, k,bus_name_flag = 0, time_flag = 0, root_flag = 0,price_flag = 0, seat_flag = 0;
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
        if(ch=='\n' && price_flag==1)
        {
            str[i]='\0';
            i=0;
            price_flag=0;
            s[j].price=atoi(str);
        }
        if(ch=='\n' && seat_flag==1){
            str[i]='\0';
            i=0;
            seat_flag=0;
            s[j].seat_available = atoi(str);
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
            if(strcmp(str,"Price")==0){
                price_flag=1;
            }
            if(strcmp(str,"Seat Available") == 0){
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
        s[j].seat_available = atoi(str);
        j++;
    }
    fclose(fp1);
    for(i = 0; i < 5; i++){
        printf("BUS NO. :%d\n",i+1);
        printf("\t\tBus Name: ");
        puts(s[i].bus_name);
        printf("\t\tDeparture Time: ");
        puts(s[i].depart_time);
        printf("\t\tRoot Name: ");
        puts(s[i].root);
        fflush(stdin);
        printf("\t\tPrice: %d\n",s[i].price);
        printf("\t\tSeat Available: %d\n",s[i].seat_available);
        printf("\n");
    }
    printf("\nDo you want to travel?\n\n\t\tif YES then press 1 \n\n\t\tif NO, then press 2\n");
    int p;
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
        printf("\t\tPrice: %d\n",s[z-1].price);
        printf("\t\tSeat Available: %d\n",s[z-1].seat_available);
        printf("\n");
        int f = s[z-1].seat_available;

        printf("\t\tPassenger Name.....\n");
        char nm[32];
        gets(nm);
        printf("\t\tPassenger Phone NO.....\n");
        char h[15];
        gets(h);
           f--;
        printf("\t\tNow total seat available:%d\n", f);
        printf("\t\tPassenger Name: ");
        puts(nm);
        printf("\t\tPassenger Phn. NO.: ");
        puts(h);
    }
    if(p==2){exit(1);}
    char w[100];
    gets(w);
    for(i=0;i<25;i++)
    {

        if(strcmp(s[i].root,w)==0)
        {
            puts(s[i].bus_name);
        }
    }
return 0;
}
