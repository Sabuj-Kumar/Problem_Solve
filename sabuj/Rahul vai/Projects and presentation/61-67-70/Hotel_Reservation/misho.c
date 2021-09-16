#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct info
{
    char Hotel_Name[100];
    char contact[100];
    char price[100];
    int Room;
    //int stock;
} s[5];
int main()
{
    printf("__By pressing number you can choose what catagory you want__\n\n");
    FILE *a,*b;
    a=fopen("catagory.txt","r");
    char ch;
    while((ch=fgetc(a))!=EOF)

    {
        printf("%c",ch);
    }
    printf("\n");
    int m;
         /*****selection of Catagory******/
    scanf("%d",&m);
    FILE *fp1;
    if(m==1)
    {
        fp1=fopen("1 star.txt","r");
    }
    else if(m==2)
    {
        fp1=fopen("2 star.txt","r");
    }
    else if(m==3)
    {
        fp1=fopen("3 star.txt","r");
    }
    else if(m==4)
    {
        fp1=fopen("4 star.txt","r");
    }
    else if(m==5)
    {
        fp1=fopen("5 star.txt","r");
    }

     int i=0,j=0,k,Hotel_Name_flag=0,Room_flag=0,price_flag=0,contact_flag=0,stock_flag=0;
    char str[100];
    while((ch=fgetc(fp1))!=EOF)
    {
        if(ch=='\n' && Hotel_Name_flag==1)
        {
            str[i]='\0';
            i=0;

            Hotel_Name_flag=0;
            strcpy(s[j].Hotel_Name,str);
        }
         if(ch=='\n' && Room_flag==1)
        {
            str[i]='\0';
            i=0;

            Room_flag=0;
            s[j].Room=atoi(str);
            //j++;
        }
         if(ch=='\n' && contact_flag==1)
        {
            str[i]='\0';
            i=0;
            contact_flag=0;
            strcpy(s[j].contact,str);
            j++;
        }
         if(ch=='\n' && price_flag==1)
        {
            str[i]='\0';
            i=0;

            price_flag=0;
            strcpy(s[j].price,str);
        }


        if(ch==':')
        {
            str[i]='\0';
            i=0;
            if(strcmp(str,"Hotel_Name")==0)
            {
                Hotel_Name_flag=1;
            }
            if(strcmp(str,"Room")==0)
            {
                Room_flag=1;
            }
             if(strcmp(str,"price")==0)
            {
                price_flag=1;
            }
            if(strcmp(str,"contact")==0)
            {
                contact_flag=1;
            }

        }
        else
        {
            if(ch!='\n')
            {
                str[i]=ch;
                i++;
            }
        }
    }

    fclose(fp1);
    for(i=0; i<10; i++)
    {
        printf("%d",i+1);
        printf(". Hotel Name: ");
        puts(s[i].Hotel_Name);
        printf("\t\tcontact: ");
        puts(s[i].contact);
        printf("\t\tprice: ");
        puts(s[i].price);
        fflush(stdin);
        printf("\t\tRoom : %d\n",s[i].Room);

        printf("\n");
    }

    printf("\nDo you want to Book any hotel in Online\n\n\t\tif YES then press 1 \n\t\tif No then press 2\n");
    int p;
    scanf("%d",&p);

    if(p==1)
    {
        printf("\nPlease choose your favourite  hotel= ");
        int z;
        scanf("%d",&z);
        if(z>10)
        {
           printf("\n\n\tthis number is not match the id of hotel\n\n\tif you want to book room than run this software again ");
        }
        else
        {
        printf("How can i help you sir ?\n\n\n");
        printf("\n\nHow many rooms do you want to Book= ");
        int n;
        scanf("%d",&n);
        if(n>100)
        {
                 printf("\n\n\tsorry sir we do not have so mach room that you want");
        }
        else
        {
        printf("\n\nplease give your mastar card or visa's account number= ");
        int h;
        scanf("%d",&h);
        if(h!=0)
        {
            puts("\n\n\tYOUR ROOM IS BOOKED . THANK YOU SIR FOR THIS BOOKING AND ENJOY YOUR HOLYDAY");

        }
        }
        }

    }
    else
    {
        puts("\n\n\tThank you");
    }

   // getch();
    return 0;
}


