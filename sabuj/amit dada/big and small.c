 #include<stdio.h>
 int main()
 {
     int input,max=0,min=0,i,test,n;
     scanf("%d",&n);
     for(test=0;test<n;test++)
     {
     for(i=0;i<5;i++)
     {
         scanf("%d",&input);
         if(i==0)
         {
             max=input;
             min=input;
         }
         if(max<input)
            max=input;
         if(min>input)
            min=input;
     }
     printf("%d %d\n",max,min);
     }
     return 0;
 }



