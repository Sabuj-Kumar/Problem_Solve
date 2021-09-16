#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <graphics.h>
#include <dos.h>

struct info
{
    char book_name[100];
    char author_name[100];
    char publisher_name[50];
    int book_id;
    int number;
}s[100];


int main()
{
                          /***********************GRAPHICS CODE********************************************/

   int gd = DETECT, gm, i,left=100,top=100;
   char a[20];

   initgraph( &gd, &gm, "C:\\TC\\BGI");

   settextjustify( CENTER_TEXT, CENTER_TEXT );
   settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
   setcolor(YELLOW);

   for (i = 10; i >=0; i--)
   {
      sprintf(a,"%d",i);

      outtextxy(getmaxx()/2, getmaxy()/2, a);
      delay(1000);

      if ( i == 0 )

         break;
         cleardevice();
   }

   cleardevice();

   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
   setcolor(GREEN);
   outtextxy(left + 185, top + 70,"welcome to our project\n\t\t");

   setcolor(RED);
   outtextxy(left + 195, top + 100,"\t\tLIBRARY MANEGMENT SYSTEM");

   setcolor(GREEN);
   outtextxy(left + 210, top + 225," press anykey to continue...");

   getch();
   closegraph();

   printf("\n\n");


                        /*****************LIBRARY MANAGEMENT SYSTEM****************/


    SetConsoleTitle("LIBRARY MANAGMENT SYSTEM");
    system("color 74");

    printf("================================================================================");
    printf("********************************MAIN MANU***************************************\n\n");
    printf("\t\t       ===========================\n");
    printf("\t\t\tLIBRARY MANAGEMENT SYSTEM\n");
    printf("\t\t       ===========================\n\n\n");

    printf("created by.....\n\t\tMD.MAZHARUL ISLAM JIHAN\t ID-13101006\n\n");
    printf("\t\tRIAJUL ALAM RABBY\t ID-13101016\n\n");
    printf("\t\tSHAKIL AHAMED SISHIR\t ID-13101022\n");


    int x,n;
    printf("================================================================================\n\n");

    for(x=1;x<=n;x++)
    {

    printf("\n\nWHICH SUBJECT DO YOU WANT ?\n\n\t");
    printf("press  '1'  for cse book \n\t");
    printf("press  '2'  for physics book \n\t");
    printf("press  '3'  for math book \n\t");
    printf("press  '4'  for english book \n\t");
    printf("press  '5'  for discrite math book \n\t");
    printf("press  '6'  for chemistry book \n\t");
    printf("press  '7'  for sociology book \n\t");
    printf("press  '8'  for history book \n\t");
    printf("press  '9'  for biology book \n\t");
    printf("press  '10' for science fiction book \n\t");
    printf("press  '11' for EXIT\n\t");

    printf("\n\n================================================================================");
	printf("================================================================================\n\n");



    int m;

    printf("PLEASE PRESS 1 TO 10 FOR SUBJECT SELECT OR 11 FOR EXIT..........");
    scanf("%d",&m);

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    FILE *fp1;


    if(m==1)

    {
        system("cls");
    	printf("             ***** CSE *****             \n\n\n\n");
        fp1=fopen("cse.txt","r");
    }


    else if(m==2)

    {
        system("cls");
        printf("             ***** PHYSICS *****             \n\n\n\n");
        fp1=fopen("physics.txt","r");
    }


    else if(m==3)
    {
        system("cls");
    	printf("             ***** MATH *****             \n\n\n\n");
        fp1=fopen("math.txt","r");
    }


    else if(m==4)
    {
        system("cls");
    	printf("             ***** ENGLISH *****             \n\n\n\n");
        fp1=fopen("english.txt","r");
    }


   else  if(m==5)
    {
        system("cls");
    	printf("             ***** DISCRITE MATH *****             \n\n\n\n");
        fp1=fopen("discrite math.txt","r");
    }


    else if(m==6)
    {
        system("cls");
    	printf("             ***** CHEMISTRY *****             \n\n\n\n");
        fp1=fopen("chemistry.txt","r");
    }


    else if(m==7)
    {
        system("cls");
    	printf("             ***** SOCIOLOGY *****             \n\n\n\n");
        fp1=fopen("sociology.txt","r");
    }


    else if(m==8)
    {
        system("cls");
    	printf("             ***** HISTORY *****             \n\n\n\n");
        fp1=fopen("history.txt","r");
    }


    else if(m==9)
    {
        system("cls");
    	printf("             ***** BIOLOGY *****             \n\n\n\n");
        fp1=fopen("biology.txt","r");
    }


    else if(m==10)
    {
        system("cls");
    	printf("             ***** SCIENCE FICTION *****             \n\n\n\n");
        fp1=fopen("science fiction.txt","r");
    }


	else if(m==11)
     {
        system("cls");
        system("color 5E");
     	printf("\n\n\n\n\n\n              ***** !!! THANKS YOU !!! *****             \n\n\n\n");
     	exit(0);
     }


	 else
	 {
        system("cls");
	 	printf("wrong keyword . please try again !!!\n\n\n");
	 	getch();

     }


////*********************************reading from input file*******************///


    int i=0,j=0,k,book_name_flag=0,author_name_flag=0,publisher_name_flag=0,book_id_flag=0;
    char ch;
    char str[50];

    while((ch=fgetc(fp1))!=EOF)
      {

        if(ch=='\n' && book_name_flag==1)

          {
            str[i]='\0';
            i=0;

            book_name_flag=0;
            strcpy(s[j].book_name,str);
          }


        if(ch=='\n' && author_name_flag==1)

         {
            str[i]='\0';
            i=0;

            author_name_flag=0;
            strcpy(s[j].author_name,str);
        }



        if(ch=='\n' && publisher_name_flag==1)

         {
            str[i]='\0';
            i=0;

            publisher_name_flag=0;
            strcpy(s[j].publisher_name,str);
        }

        if(ch=='\n' && book_id_flag==1)

          {
            str[i]='\0';
            i=0;
            book_id_flag=0;
            s[j]. book_id = atoi(str);
            j++;
        }





        ///********************data cmp from input file*******************////


        if(ch==':')

        {
            str[i]='\0';
            i=0;

            if(strcmp(str,"book_name      ")==0)
            {
                book_name_flag=1;
            }


             if(strcmp(str,"author_name    ")==0)
            {
                author_name_flag=1;
            }


             if(strcmp(str,"publisher_name ")==0)
            {
                publisher_name_flag=1;
            }


            if(strcmp(str,"book_id        ")==0)
            {
                book_id_flag=1;
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

///*******************ARRAY TO INTIZER*******************////


    if(book_id_flag==1)

        {
            str[i]='\0';
            i=0;
            book_id_flag=0;
            s[j].book_id=atoi(str);
            j++;
        }


    fclose(fp1);


    ///************************print in consoul***********************///


    for(i=0;i<10;i++)

     {
        printf("BOOK NAME      :");
        puts(s[i].book_name);
        printf("AUTHOR NAME    :");
        puts(s[i].author_name);
        printf("PUBLISHER NAME :");
        puts(s[i].publisher_name);
        printf("BOOK ID is     : %d\n",s[i].book_id);

        ///*************** count-- ***************///

        if(x==1) s[i].number=10;
        printf("available      : %d\n",s[i].number);

        printf("\n\n");

     }


      ///*****************sreach from input********************///

    printf("\nDo you want to Book\n\n");
    printf("\t\tif YES then press 1 \n");
    printf("\t\tif No then press 2\n");

    int p;
    scanf("%d",&p);

    if(p==1)

    {
      int st,borrow_id,phn;

      printf("SELECT BOOK ID WHICH YOU WANT ?.............: ");

      scanf("%d",&st);
      printf("\n");


      for(i=0;i<10;i++)

       {
         if(s[i].book_id==st)

           {

             printf("GIVE ME YOUR ID PLEASE.............. : ");

             scanf("%d",&borrow_id);
             printf("\n");

             printf("GIVE ME YOUR PHONE NUMBER PLEASE.............. : ");
             scanf("%d",&phn);
             printf("\n\n\n");

//system("cls");
             s[i].number=s[i].number-1;
             printf("BOOK NAME \t\t:");
   	         printf("%s\n",s[i].book_name);
             printf("AUTHOR NAME \t\t:");
   	         printf("%s\n",s[i].author_name);
   	         printf("BORROW ID  \t\t: ");
        	 printf("%d\n",borrow_id);
   	         printf("BORROW PHONE NUMBER \t: 0");
             printf("%d\n",phn);


             }

        }

     }

     else if(p==2)
        {
	      printf("thank you");

        }

     else
        {
         printf("sorry !!! your enter is not correct");
        }



/////////////*********************print in file*************************/////////////

    fp1=fopen("output.txt","a");

    fputs("                  *** TYPES OF BOOKS ***",fp1);

    fputs("\n\n\n",fp1);

    for(i=0;i<10;i++)

     {
        char p[200];
        fputs("BOOK NAME       :",fp1);
        fputs(s[i].book_name,fp1);
        fputc('\n',fp1);


        fputs("AUTHOR NAME     :",fp1);
        fputs(s[i].author_name,fp1);
        fputc('\n',fp1);


        fputs("PUBLISHER NAME  :",fp1);
        fputs(s[i].publisher_name,fp1);
        fputc('\n',fp1);


        fputs("BOOK ID         :",fp1);
        itoa(s[i].book_id,p,10);
        fputs(p,fp1);
        fputc('\n',fp1);
        fputc('\n',fp1);
    }

    fclose(fp1);

    printf("\n");//loop prosses

   }//complite loop prosses

    return 0;
}
