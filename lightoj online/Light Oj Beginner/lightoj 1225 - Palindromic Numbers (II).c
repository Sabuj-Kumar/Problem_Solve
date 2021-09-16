 #include<stdio.h>
 #define pf printf
 #define sc scanf
 int main()
 {
    char a[1000],b[1000];
    int i,j,ln=0,count=0,n,p;
    sc("%d",&n);
    for(p=1;p<=n;p++)
    {
        scanf("%s",a);
         for(i=0; a[i]!='\0'; i++)
            ln++;

         a[i]='\0';
         j=ln-1;
         for(i=0;i<ln;i++)
         {
             b[i]=a[j];
             j--;
             pf("%d ",j);
         }
         b[i]='\0';
         pf("%s\n",b);
         for(i=0;i<ln;i++)
         {
             if(a[i]==b[i])
                 count++;
             else
                count=0;
         }
          pf("%d\n",count);

         if(count==ln)
            pf("Case %d: Yes\n",p);
         else
            pf("Case %d: No\n",p);
        i=0;
        j=0;
    }

  return 0;
 }
