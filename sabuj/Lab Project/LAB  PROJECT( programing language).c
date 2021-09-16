#include<stdio.h>
#include<windows.h>
#include<string.h>

char newline,pass[100];

char b[] = {"SABUJ"};

char c[] = {"SNIGDHA"};

FILE *fp;

struct language
{
    int serial;

    char name[100];

    char founder[1000];

    char year[100]; /// language published year

    char type_language[1000];

    char header_file[100];

    char data_type[1000];

    char library_function[1000];/// build in function

    char sentex[1000];

    char use[1000];/// where use this language

}a[50];

void Print( int key, int check )
{

    printf("\n\n\t\t@ If You Want To See This Query Press Between 1 & 8 Else Press 0 @ :  ");

    while( 1 )
    {
        scanf("%d",&check);

        if( check >= 0 && check <= 8 )
        {
            if( check == 0 )
                break;

            if( check == 1 )
            {
                system("color 2B");

                printf("\n\t\t\a-> The Creator Name Of %s Language Is : %s\n\n",a[key].name,a[key].founder);
            }
            else if( check == 2 )
            {
                system("color 3C");

                printf("\n\t\t\a-> The Published Year Of %s Language Is : %s\n\n",a[key].name,a[key].year);
            }
            else if( check == 3 )
            {
                system("color 18");

                printf("\n\t\t\a-> tThe Type Of %s Language Is : %s\n\n",a[key].name,a[key].type_language);
            }
            else if( check == 4 )
            {
                system("color 5E");

                printf("\n\t\t\a-> The Header File Of %s Language Is : %s\n\n",a[key].name,a[key].header_file);
            }
            else if( check == 5 )
            {
                system("color 6B");

                printf("\n\t\t\a-> The Data Type Of %s Language Is : %s\n\n",a[key].name,a[key].data_type);
            }
            else if ( check == 6 )
            {
                system("color 12");

                printf("\n\t\t\a-> The Library Function Of %s Language Is : %s\n\n",a[key].name,a[key].library_function);
            }
            else if( check == 7 )
            {
                system("color 30");

                printf("\n\t\t\a-> The Structure Of %s Language Is : %s\n\n",a[key].name,a[key].sentex);
            }
            else if( check == 8 )
            {
                system("color 9B");

                printf("\n\t\t\a-> The Uses Of %s Language Is : %s\n\n",a[key].name,a[key].use);
            }

            printf("\n\n\t\t@ If You Want To See This Query Again Press Between 1 & 8 Else Press 0 @ :  ");
        }
        else
        {
            printf("\n\n\t\t **He He He He wrong Number**..... \n");

            printf("\n\n\t\t@ If You Want To See This Query Again Press Between 1 & 8 Else Press 0 @ :  ");
        }
    }
}

void Search( int key )
{
    int i,check;

    for(  i = 0; i < 32; i++ )
    {
        if( key == i )
        {
            system("color 2A");

            printf("\t\t''If You Want To Know Creator Of %s Language Press 1 : \n\n",a[key].name);

            printf("\t\t''If You Want To Know Published Year Of %s Language Press 2 : \n\n",a[key].name);

            printf("\t\t''If You Want To Know Type Of %s Language Press 3 : \n\n",a[key].name);

            printf("\t\t''If You Want To Know Header File Of %s Language Press 4 : \n\n",a[key].name);

            printf("\t\t''If You Want To Know Data Type Of %s Language Press 5 : \n\n",a[key].name);

            printf("\t\t''If You Want To Know Library Function Of %s Language Press 6 : \n\n",a[key].name);

            printf("\t\t''If You Want To Know Syntax Of %s Language Press 7 : \n\n",a[key].name);

            printf("\t\t''If You Want To Know Uses Of %s Language Press 8 : \n\n",a[key].name);

            Print( key , check );

            break;
        }
    }
}

int main()
{
    int key = 0,i,T = 0,check = 0;

    fp = fopen("store.txt","r");

    for( i = 0; i < 32; i++ )
      fscanf(fp,"%d:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:\n",&a[i].serial,a[i].name,a[i].founder,a[i].year,a[i].type_language,a[i].header_file,a[i].data_type,a[i].library_function,a[i].sentex,a[i].use);

    fclose(fp);


//    for( i = 0; i < 32; i++ )
//     {
//        printf("%d\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a[i].serial,a[i].name,a[i].founder,a[i].year,a[i].type_language,a[i].header_file,a[i].data_type,a[i].library_function,a[i].sentex,a[i].use);
//        printf("\n\n");
//     }
   system("cls");

   system("color 1A");

   printf("\n\n\t\t^^^^^^ $ PROJECT  SHOW $ ^^^^^^ ");

   printf("\n\n\n\t\t\t\t\t\t\t&***************&\n");

   printf("\t\t\t\t\t\t\t&***************&\n");

   printf("\t\t\t\t\t\t\t&***************&\n");

   printf("\t\t\t\t\t\t\t&***************&");

   printf("\n\n\n\t\t\t\t@@@@@@@@@@@   LETS SHOW THE PROGRAMMING LANGUAGE PROJECT   @@@@@@@@@@@\n\n\n");

   printf("\t\t\t\t\t\t\t&***************&\n");

   printf("\t\t\t\t\t\t\t&***************&\n");

   printf("\t\t\t\t\t\t\t&***************&\n");

   printf("\t\t\t\t\t\t\t&***************&\n\n");

   printf("\t\t\t\t\t\t\t\t\t\t  ...\n");

   printf("\t\t\t\t       Input Password To See The Language's Name :...:  ");

   while( 1 )
   {
       scanf("%s",pass);

       if( strcmp(pass,b) == 0 || strcmp(pass,c) == 0 )
        break;

       T++;

       if( T == 5 )
        break;

       else if( T < 4)
          printf("\n\n\t\tOps, Try Again - >>>:   ");

       else
          printf("\n\n\t\tThis Is Your Last Change Okay - >>>:   ");

   }

   if( strcmp(pass,b) == 0 )
   {
        printf("\n\n\t\t\t\t\t\t\t    **SABUJ**\n");
        printf("\t\t\t\t\t\t\t      .....\n");
   }
   else if( strcmp(pass,c) == 0 )
   {
        printf("\n\n\t\t\t\t\t\t\t   **SNIGDHA**\n");
        printf("\t\t\t\t\t\t\t     .......\n");
   }

   printf("\n\n\n");

   if( strcmp(pass,b) == 0 || strcmp(pass,c) == 0 )
   {
      while ( 1 )
      {
         system("color 1A");

         for( i = 0; i < 32; i++ )
            printf("   %d\t %s\n\n",a[i].serial,a[i].name);

         printf("\n\n\n\t\tChoice Your Favorite Language Press Any Digit Between 1 & 50:  ");

         printf("\n\n\t\tYou Have No Choice Press 0:            ");

         scanf("%d",&key);

         if( key == 0 )
            break;

         printf("\n\n");

         Search(--key);

         printf("\n\n\t\t\tIf You Want To Continue  Press 1 Else 0.  ");

         scanf("%d",&T);

         if ( T == 1 )
         {
              system("cls");
              printf("\n\n\t\t\tLET'S SEE AGAIN.......\n\n\n");
         }
         else
            break;

        printf("\n\t\t^^ TOTAL LANGUAGE ARE THERE -->> \n\n");
      }
   }

   if( T == 5 )
     printf("\n\n\t\t You Are A Fake User....");

   printf("\n\n\n\t\t\t\t\a***THaNK yOU***\n\n\n");

   return 0;
}
