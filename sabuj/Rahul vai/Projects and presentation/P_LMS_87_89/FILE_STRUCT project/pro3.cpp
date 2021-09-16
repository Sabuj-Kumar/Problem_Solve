#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct info
{
    char book_name[100];
    char author[100];
    char publisher[100];
    int book_id;
    int stock;
} s[10];
struct rec{
    char B_ID[100];
    char B_D[100];
    char B_N[100];
}t[100];
int main()
{
    printf("\t___________Libary Management System by Team 'ARGO'__________\n\n");   // Dodge Box W:75/H:300
    LOOP:
    printf("\n\t\t\tWhich Facility You Want to use?\n\n\t\t\t\t1.Borrowing Book\n\n\t\t\t\t2.Submit book\n\n\t\t\t\t3.Read Me-Instruction\n\n\t\t\t\t4.Exit\n\n\tEnter Your Option :");
    int p;
    scanf("%d",&p);
    if(p==1)                                         ///*** Borrowing Section ***///
    {

    FILE *a,*b;
    a=fopen("catagory.txt","r");
    FILE *fp5;
    fp5=fopen("123.txt","a");
    char ch;
    while((ch=fgetc(a))!=EOF)
         {
         printf("%c",ch);
         }
    printf("\n\n\tEnter Your Catagory By Pressing Numbers : ");
    int m;                                                /*****selection of Catagory******/
    FILE *fp1;
    scanf("%d",&m);
    if(m==1)
    {
        printf("\n\t\tCATAGORY : P R O G R A M M I N G\n");
        fp1=fopen("786.txt","r+");
    }
    else if(m==2)
    {
        printf("\n\t\tCATAGORY : H A R D W A R I N G\n");
        fp1=fopen("hardwaring.txt","r+");
    }
    else if(m==3)
    {
        printf("\n\t\tCATAGORY : N E T W O R K I N G\n");
        fp1=fopen("networking.txt","r+");
    }
    else if(m==4)
    {
        printf("\n\t\tCATAGORY : G R A P H I C S\n");
        fp1=fopen("graphics.txt","r+");
    }
    else if(m==5)
    {
        printf("\n\t\tCATAGORY : W E B - A P L I C A T I O N\n");
        fp1=fopen("web application.txt","r+");
    }
    else
    {
        printf("\n\t\t  ***** Invalid Catagory - Try Again *****\n");
        goto LOOP;
    }

    int i=0,j=0,k,book_name_flag=0,author_flag=0,publisher_flag=0,book_id_flag=0,stock_flag=0;
    char str[100];

    while((ch=fgetc(fp1))!=EOF)                           ///Data read from File By Structure
    {
        if(ch=='\n' && book_name_flag==1)
        {
            str[i]='\0';
            i=0;

            book_name_flag=0;
            strcpy(s[j].book_name,str);
        }
        if(ch=='\n' && author_flag==1)
        {
            str[i]='\0';
            i=0;

            author_flag=0;
            strcpy(s[j].author,str);
        }
        if(ch=='\n' && publisher_flag==1)
        {
            str[i]='\0';
            i=0;

            publisher_flag=0;
            strcpy(s[j].publisher,str);
        }
        if(ch=='\n' && book_id_flag==1)
        {
            str[i]='\0';
            i=0;
            book_id_flag=0;
            s[j].book_id=atoi(str);
        }
        if(ch=='\n' && stock_flag==1)
        {
            str[i]='\0';
            i=0;
            stock_flag=0;
            s[j].stock=atoi(str);
            j++;
            s[i].stock=s[i].stock-1;
        }
        if(ch==':')
        {
            str[i]='\0';
            i=0;
            if(strcmp(str,"book_name")==0)
            {
                book_name_flag=1;
            }
            if(strcmp(str,"author")==0)
            {
                author_flag=1;
            }
             if(strcmp(str,"publisher")==0)
            {
                publisher_flag=1;
            }
            if(strcmp(str,"book_id")==0)
            {
                book_id_flag=1;
            }
            if(strcmp(str,"stock")==0)
            {
                stock_flag=1;
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
    if(stock_flag==1)
    {
        str[i]='\0';
        i=0;
        stock_flag=0;
        s[j].stock=atoi(str);
        j++;
    }

    for(i=0; i<5; i++)                                ///showcase of Book from the File data read by Stucture
    {
        printf("\n");
        printf("Book serial :%d\n",i+1);
        printf("\t\tBook Name: ");
        puts(s[i].book_name);
        printf("\t\tAuthor Name: ");
        puts(s[i].author);
        printf("\n");
    }
        int z;                                           ///***Getting book by giving Roll***//
        printf("\nPlease choose your book by pressing number :");
        scanf("%d",&z);
        if(z<6)
        {
        printf("\n\t\tBook Name: ");                    ///***show case of full detail of Book you want to borrow
        puts(s[z-1].book_name);
        printf("\t\tAuthor Name: ");
        puts(s[z-1].author);
        printf("\t\tPublisher Name: ");
        puts(s[z-1].publisher);
        fflush(stdin);
        printf("\t\tBook ID: %d\n",s[z-1].book_id);
        printf("\t\tBook in Stock: %d\n",s[z-1].stock);
        printf("\n");
        }
        else
        {
            printf("\t\t\t***Invalid Book Number***\n");
            goto LOOP;
        }
       char h[100],x[100];
       int f=s[z-1].stock;
       if(f==0)                                          ///***Zero Handaling***///
           {
           printf("\n\n\t\t\t~*~ Sorry! We Are Out of Stock ~*~\n\n");
           }
       else
           {
            printf("\t\tGive your ID :");

            scanf("%s",&h);
            puts("\n\t\tGive Date in this Format 'Day/Month/Year' :");
            scanf("\t\t%s",&x);
            if(h!='\0')
            {
               f--;
               s[i].stock=s[i].stock-1;
               fputc(s[i].stock,fp1);
            }
            printf("\n\t        ********Congratulation! ID : %s  ********\n\n\t ********You Have Successfully Borrowed the Book******** \n\n\t\tWe have in stock:%d\n",h,f);
            printf("\n\t\tBorrower Id : %s\n",h);
            printf("\n\t\tBook ID: %d\n",s[z-1].book_id);
            printf("\n\t\tBorrowing Date : %s\n",x);
            }

        char y[100];
        strcpy(y,h);
        int loc=strlen(y);
        fputs("Borrower ID:",fp5);
        fputs(y,fp5);
        fputc('\n',fp5);
        fputs("Book Name:",fp5);
        fputs(s[z-1].book_name,fp5);
        fputc('\n',fp5);
        fputs("Borrowing Date:",fp5);
        fputs(x,fp5);
        fputc('\n',fp5);
        fputc('\n',fp5);
        fseek(fp5,0,SEEK_CUR);
        fseek(fp5,loc-loc,SEEK_END);
        loc++;
        goto LOOP;
        fclose(fp5);
        fclose(fp1);
    }
    if(p==2)                                ///*** SUBMIT SECTION ***///
    {
    FILE *c;
    int i=0,j=0,B_ID_FLAG=0,B_D_FLAG=0,B_N_FLAG=0;
    char ch,a[100],str[100];
    printf("\n\n\t\tPlease Enter Your ID : ");
    scanf("%s",&a);
    c=fopen("123.txt","r");
    while((ch=fgetc(c))!=EOF)
    {
        if(ch=='\n' && B_ID_FLAG==1)
        {
            str[i]='\0';
            i=0;
            B_ID_FLAG=0;
            strcpy(t[j].B_ID,str);
        }
        if(ch=='\n' && B_N_FLAG==1)
        {
            str[i]='\0';
            i=0;
            B_N_FLAG=0;
            strcpy(t[j].B_N,str);
        }
        if(ch=='\n' && B_D_FLAG==1)
        {
            str[i]='\0';
            i=0;
            B_D_FLAG=0;
            strcpy(t[j].B_D,str);j++;
        }
        if(ch==':')
        {
            str[i]='\0';
            i=0;
            if(strcmp(str,"Borrower ID")==0)
            {
                B_ID_FLAG=1;
            }
            if(strcmp(str,"Book Name")==0)
            {
                B_N_FLAG=1;
            }
            if(strcmp(str,"Borrowing Date")==0)
            {
                B_D_FLAG=1;
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
    for(i=0;i<100;i++)
    {
    if(strcmp(t[i].B_ID,a)==0)
        {
          printf("\n\t\tYour Last borrowed Book was :%s\n",t[i].B_N);
          printf("\n\t\tYou Last borrowed the Book at the Date of :%s\n",t[i].B_D);
          printf("\n\t\t\tThank you For Submitting The Book\n\n");
        }
    }
    fclose(c);
    goto LOOP;
    }
    else if(p==3)                    ///*** READ ME ***///
    {
    FILE *e;
    e=fopen("read_me.txt","r");
    char n;
    while((n=fgetc(e))!=EOF)
         {
         printf("%c",n);
         }
    }
    else                                  ///**** EXIT ****///
    {
       printf("\n\n\n\t\t** Thank You For Your Kind participation **\n\n");
    }
return 0;
}
