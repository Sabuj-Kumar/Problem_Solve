#include<stdio.h>
int main()
{
    float test_case,oposite_score,present_score,remaining_ball,i;
    float remaining_over=0,remaining_run=0,present_run_rate=0,remaining_run_rate=0,past_over=0;
    scanf("%f",&test_case);
    for(i=0;i<test_case;i++)
    {
        scanf("%f%f%f",&oposite_score,&present_score,&remaining_ball);
        remaining_run=oposite_score-present_score+1;
        remaining_over=remaining_ball/6.0;
        past_over=50-remaining_over;
        present_run_rate=present_score/past_over;
        remaining_run_rate=remaining_run/remaining_over;
        printf("%.2f %.2f\n",present_run_rate,remaining_run_rate);
    }

 return 0;
}
