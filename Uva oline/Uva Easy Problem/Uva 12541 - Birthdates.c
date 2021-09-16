#include<stdio.h>
#include<string.h>
int main()
{
    char s[20],s1[20],s2[20];
    int day,month,year,day1=0,month1=0,year1=0,day2=0,month2=0,year2=0,n,i;
    scanf("%d",&n);
    for( i = 0; i <  n; i++ )
    {
        scanf("%s",s);
        scanf("%d %d %d",&day , &month, &year);
        if( i == 0)
        {
            day1 = day;
            month1 = month;
            year1 = year;
            day2 = day;
            month2 = month;
            year2 = year;
        }
       if ( year < year1 )
       {
           strcpy( s1 , s );
           year1 = year;
       }
       else if ( year == year1)
       {
           if( month < month1)
           {
               strcpy( s1 , s);
               month1 = month;
           }

       }
       else if ( year == year )
       {
           if ( month == month1)
           {
               if ( i = 0 )
               {
                   if( day == day1)
                    strcpy( s1, s );
               }
               else if(  day < day1)
               {
                    strcpy( s1 , s);
                    day1 = day;
               }

           }
       }

       if ( year > year2 )
       {
           strcpy( s2 , s );
           year2 = year;
       }
       else if ( year == year2)
       {
           if( month > month2)
           {
               strcpy( s2 , s);
               month2 = month;
           }
       }
       else if ( year == year2 )
       {
           if ( month == month2)
           {
               if ( i == 0 )
               {
                   if ( day == day2 )
                   strcpy( s2 , s);
               }
               else if( day > day2)
               {
                   strcpy( s2 , s);
                   day2 = day;
               }
           }
       }
    }
    printf("%s\n%s\n",s2,s1);
    return 0;
}
