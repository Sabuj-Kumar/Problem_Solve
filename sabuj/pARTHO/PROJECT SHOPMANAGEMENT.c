#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

struct mobileshop
{
    int serial;

    char Mobilename[50];

    char Modelnumber[60];

    char Screen[50];

    char Weight[20];

    char RAM[10];///Random access memory

    char ROM[10]; ///Read only memory  ///Camera

    char Primary[10];

    char Secondary[10];

    char Bcapicity[30];///Battery capacity

    char FA[15];///First arrival

    char Madeby[10];

    int price;
};
void detail()
{
    printf("\n\nPress '1' to see how many Mobile price under 10000..  ");

    printf("\n\nPress '2' to search by place where The Mobile made by.. ");

    printf("\n\npress '3' to see the MobilePhone first arrival..  ");

    printf("\n\npress '4' find your suitable Camera information.. ");

    printf("\n\npress '5' To see every phone price.. ");

    printf("\n\npress '6'  To see Every phone Battery capacity.. ");

    printf("\n\npress '7' To see Every Phone WEIGHT.. ");

    printf("\n\npress '8' To see how many phone RAM up to 2GB.. ");

    printf("\n\npress '9' To search By TK. Which is Suitable for you.. ");

    printf("\n\npress '10' To See The best phone IN HUWEI.. ");

    printf("\n\nPress '0' to Exit!..  ");
}
void display()
{
    printf("\t\t\t                                                         _____\n");
    printf("\t\t\t||    || ||     ||      //\\\\ \\\\                    //  ||       ||               \n ");
    printf("\t\t\t||    || ||     ||     //  \\\\ \\\\                  //   ||       ||               \n");
    printf("\t\t\t||____|| ||     ||    //    \\\\ \\\\      //\\\\      //    ||_____  ||               \n");
    printf("\t\t\t||    || ||     ||   //______\\\\ \\\\    //  \\\\    //     ||       ||                 \n");
    printf("\t\t\t||    || ||_____||  //        \\\\ \\\\  //    \\\\  //      ||       ||                 \n");
    printf("\t\t\t||    || ||_____|| //          \\\\ \\\\//      \\\\//       ||_____  ||                     ");
}
void degine()
{
    printf("\t\t __________                                                      _____  \n ");
    printf("\t\t     ||     ||   ||     //\\\\     ||\\\\    || ||  //    |     |  ||    ||     ||     ||        \n");
    printf("\t\t     ||     ||   ||    //  \\\\    || \\\\   || || //     |     |  ||    ||     ||     ||    \n");
    printf("\t\t     ||     ||___||   //____\\\\   ||  \\\\  || ||//      |_____|  ||    ||     ||     || \n");
    printf("\t\t     ||     ||   ||  //      \\\\  ||   \\\\ || ||\\\\         |     ||    ||     ||     ||\n");
    printf("\t\t     ||     ||   || //        \\\\ ||    \\\\|| || \\\\        |     ||____||     ||_____||        ");
}
int main ()
{
    struct mobileshop u[40];

    char Query[10], x[100],newline;

    int i,a,y,key;

    char h,C;

    FILE *fa;

    fa=fopen("TEXT.txt", "r");

    for( i = 0; i < 40; i++ )
    {
        fscanf(fa,"%d:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%d:%c",&u[i].serial,u[i].Mobilename, u[i].Modelnumber, u[i].Screen,u[i].Weight, u[i].RAM, u[i].ROM, u[i].Primary, u[i].Secondary,u[i].Bcapicity,u[i].FA,u[i].Madeby,&u[i].price,&C);

        //fscanf(fa,"%d:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%s:%d:%c",&u[i].serial,u[i].Mobilename, u[i].Modelnumber, u[i].Screen,u[i].Weight, u[i].RAM, u[i].ROM, u[i].Primary, u[i].Secondary,u[i].Bcapicity,u[i].FA,u[i].Madeby,&u[i].price,&newline);
       // printf("%d:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%s:%d\n",u[i].serial,u[i].Mobilename, u[i].Modelnumber, u[i].Screen,u[i].Weight, u[i].RAM, u[i].ROM, u[i].Primary, u[i].Secondary,u[i].Bcapicity,u[i].FA,u[i].Madeby,u[i].price);
    }

    fclose(fa);

    if( fa == NULL )
    {
        printf("\n\t\t<<CANNOT OPEN FILE>>\n\n");

        return 0;
    }

    system("color 4A");

    display();

    printf("\n\n\n\n");

    printf("\t^^^^^^^^^^^^^^^IN OUR SHOP AT THAT TIME FIFTY MODEL OF MOBILE ARE AVAILABLE^^^^^^^^^^^^^^^^\n\n");

    printf("\n\t<<<<<<<<<<<IF YOU NEED ANY INFORMATION ABOUT THIS MOBILE THEN START QUERY>>>>>>>>>>>>>>\n\n");

    printf("\n\tIf you want to Start Query,\n\n\tThen Press 'PARTHO' or 'MIFTAH':   ");

    scanf("%s",Query);

    if( strcmp( Query, "PARTHO") == 0 || strcmp( Query, "MIFTAH") == 0 )
    {
        system("cls");

        detail();

        while(1)
        {
            scanf("%d",&key);

            if( key == 1 )
            {
                system("cls");

                printf("\n\t\tYOUR TARGATED MOBILEPHONE IS..\n");

                printf("\n\t\tMobilePhone Name: \t\tPrice:\n\n");

                for(i = 0; i < 40; i++)
                {
                    if( u[i].price <= 10000 )
                    {
                        printf("\t\t%s\t\t%d\n\n",u[i].Mobilename,u[i].price);
                    }
                }
                printf("\t\t-----------------------------------------------------------------------------\n\n");

                printf("\t\t\t---------------------------------------------------------\n\n");

                printf("\t\t\t\t-----------------------------------------------\n\n");

                detail();
            }
            else if( key == 2 )
            {
                system("color 4A");

                system("cls");

                printf("\n\t\tYOUR TARGATED MOBILEPHONE IS...\n\n");

                printf("\t\tMOBILEPHONENAME: \t\t\tMADE BY: \n\n");

                for( i = 0; i < 40; i++ )
                {
                    printf("\t\t%s\t\t\t\t%s\n\n",u[i].Mobilename,u[i].Madeby);
                }
                printf("\t\t-----------------------------------------------------------------------------\n\n");

                printf("\t\t\t---------------------------------------------------------\n\n");

                printf("\t\t\t\t-----------------------------------------------\n\n");

                detail();
            }
            else if( key == 3 )
            {
                system("color 4A");

                system("cls");

                printf("\n\t\tYOUR TARGATED MOBILEPHONE IS\n\n");

                printf("\t\tMOBILEPHONENAME: \t\tFIRST ARRIVAL:\n\n");

                for( i = 0; i < 40; i++ )
                {
                    printf("\t\t%s\t\t\t%s\n\n",u[i].Mobilename,u[i].FA);
                }
                printf("\t\t-----------------------------------------------------------------------------\n\n");

                printf("\t\t\t---------------------------------------------------------\n\n");

                printf("\t\t\t\t-----------------------------------------------\n\n");

                detail();
            }
            else if( key == 4 )
            {
                system("color 4A");

                system("cls");

                printf("\n\t\tYOUR TARGATED MOBILEPHONE IS....\n\n");

                printf("\t\tSERIAL:\t\tMOBILEPHONENAME: \t\tPRIMARY REGULATION:\t\tSECANDARY REGULATION.....\n\n");

                for(i = 0; i < 40; i++)
                {
                    printf("\t\t%d\t\t\t%s\t\t\t\t%s\t\t\t\t%s\n\n",u[i].serial,u[i].Mobilename,u[i].Primary,u[i].Secondary);
                }
                printf("\t\t-----------------------------------------------------------------------------\n\n");

                printf("\t\t\t---------------------------------------------------------\n\n");

                printf("\t\t\t\t-----------------------------------------------\n\n");

                detail();
            }
            else if( key == 5 )
            {
                system("color 4B");

                system("cls");                                ///PROBLEM IN THIS QUAR

                printf("\n\t\tYOUR TARGATED MOBILEPHONE IS\n\n");

                printf("\t\tMOBILEPHONENAME: \t\t\t\tPRICE:\n\n");

                for( i = 0; i < 40; i++ )
                {
                    printf("\t\t%s\t\t\t\t%d\n\n",u[i].Mobilename,u[i].price);
                }
                printf("\t\t-----------------------------------------------------------------------------\n\n");

                printf("\t\t\t---------------------------------------------------------\n\n");

                printf("\t\t\t\t-----------------------------------------------\n\n");

                detail();
            }
            else if( key == 6 )
            {
                system("color 4A");

                system("cls");

                printf("\n\t\tTHE BATERRY CAPICITY IN EVERY MOBILE IS..\n\n");

                printf("\t\tMOBILEPHONENAME: \t\tBATERRY CAPACITY:\n\n");

                for( i = 0; i < 40; i++ )
                {
                    printf("\t\t%s\t\t\t%s\n\n",u[i].Mobilename,u[i].Bcapicity);
                }
                printf("\t\t-----------------------------------------------------------------------------\n\n");

                printf("\t\t\t---------------------------------------------------------\n\n");

                printf("\t\t\t\t-----------------------------------------------\n\n");

                detail();
            }
            else if( key == 7 )
            {
                system("color 4B");

                system("cls");

                printf("\n\t\tTHE EVERY MOBILEPHONE PARTUCULAR WEIGHT IS...\n\n");

                printf("\t\tMOBILEPHONENAME: \t\tWEIGHT:\n\n");

                for( i = 0; i < 40; i++ )
                {
                    printf("\t\t%s\t\t\t%s\n\n",u[i].Mobilename,u[i].Weight);
                }
                printf("\t\t-----------------------------------------------------------------------------\n\n");

                printf("\t\t\t---------------------------------------------------------\n\n");

                printf("\t\t\t\t-----------------------------------------------\n\n");

                detail();
            }
            else if( key == 8 )
            {
                system("cls");

                printf("\n\t\tHERE SHOWN THE PHONE WHICH RAM UP TO 2 GB IS\n\n");

                printf("\t\tMOBILEPHONENAME: \t\tRAM:\n\n");

                for(i = 0; i < 40; i++ )
                {
                    if(strcmp(u[i].RAM,"3 GB")==0||strcmp(u[i].RAM,"4 GB")==0||strcmp(u[i].RAM,"5 GB")==0||strcmp(u[i].RAM,"6 GB")==0)
                    {
                        printf("\t\t%s\t\t\t%s\n\n",u[i].Mobilename,u[i].RAM);
                    }
                }
                printf("\t\t-----------------------------------------------------------------------------\n\n");

                printf("\t\t\t---------------------------------------------------------\n\n");

                printf("\t\t\t\t-----------------------------------------------\n\n");

                detail();
            }
            else if( key == 9 )
            {
                system("color 4B");

                system("cls");

                printf("\n\t\tEnter your desired price:  ");       ///PROBLEM IN THIS QUARY

                scanf("%d",&a);

                printf("\n\n\t\tYOUR TARGATED MOBILEPHONE IS...\n\n");

                for( i = 0; i < 40; i++ )
                {
                    if( u[i].price <= a )
                    {
                        printf("\t\t%s\n\n",u[i].Mobilename);
                    }
                }
                printf("\t\t-----------------------------------------------------------------------------\n\n");

                printf("\t\t\t---------------------------------------------------------\n\n");

                printf("\t\t\t\t-----------------------------------------------\n\n");

                detail();
            }
            else if( key == 10 )
            {
                system("cls");

                system("color 1B");

                printf("\n\t\tTHE BEST MOBILEPHONE IN HUAWEI..\n\n");

                for( i = 0; i < 40; i++ )
                {
                    if(strcmp(u[i].RAM,"3 GB")==0 && strcmp(u[i].ROM,"16 GB")==0 && strcmp(u[i].Primary,"13 MP AF")==0 && strcmp(u[i].Secondary,"8 MP AF")==0)
                    {
                        printf("\t\t%s\n\n",u[i].Mobilename);
                    }
                }
                printf("\t\t-----------------------------------------------------------------------------\n\n");

                printf("\t\t\t---------------------------------------------------------\n\n");

                printf("\t\t\t\t-----------------------------------------------\n\n");

                detail();
            }
            else if( key == 0 )
            {
                system("cls");

                system("color 2A");

                break;
            }
        }
    }

    else
    printf("\n\n\t\tYour Password Is Wrong\n\n");

    display();

    printf("\n\n\n");

    degine();

    printf("\t\t\t\t----------------------------------------------------------------------------------------\n\n");

    printf("\t\t\t--------------------------------------------------------------------------\n\n");

    printf("\t\t\t\t-----------------------------------------------------------\n\n");

    return 0;
}

