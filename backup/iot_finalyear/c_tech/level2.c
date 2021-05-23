/*---------------------------------------------------------------------------------
50 u -->    0.50/u
100u -->    0.75/u
100u -->    1.20/u
ab 250u-->  1.50/u
additional charge 20% added
---------------------------------------------------------------------------------*/

#include<stdio.h>
int main()
{
    float num,cost=0,acost=0;
    scanf("%f",&num);
    num-=50;
    if(num>0)
    {
        cost=50*0.50;
        num-=100;
        if(num>0)
        {
            cost=cost+(100*0.75);
            if(num>100)
            {
                num=num-100;
                cost=cost+(100*1.20);
                cost=cost+(num*1.50);
            }
            else if(num<=100)
            {
                cost=cost+(num*1.20);
            }
        }
    }
    else
    {
        num=num+50;
        cost=num*0.50;
    }
acost=cost*0.2;
cost=cost+acost;
printf("total cost is : %g",cost);
}
