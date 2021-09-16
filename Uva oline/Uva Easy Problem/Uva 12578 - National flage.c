#include<stdio.h>
#include<math.h>
#define Pi acos(-1)
int main()
{
    double N;
    scanf("%lf",&N);
    while ( N-- )
    {
       double length,width,redius,N;

        scanf("%lf",&length);
        width = ( length / 10 ) * 6;
        redius = length / 5;

       double area_of_circle = Pi * redius * redius;
       double area_of_ractenguler = length * width;
       double area_of_green = area_of_ractenguler - area_of_circle;

       printf("%.2lf %.2lf\n",area_of_circle,area_of_green);
    }
    return 0;
}
