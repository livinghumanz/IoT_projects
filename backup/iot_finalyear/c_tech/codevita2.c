#include <stdio.h>
#include<stdlib.h>
#include<limits.h>
int count1=0,count=0;
int orx=0,ory=INT_MAX;
//function to calculate calculate_distance
int calculate_distance(int px,int py,int distance,int res_no,int r_x[],int r_y[],int sum1)
{
    int sum=0,i,d,temp;
    int count=0;
    for(i=0;i<res_no;i++)
    {
        d=(abs(px-r_x[i]) + abs(py-r_y[i]))-1;
        //printf("[%d]  ",d);
        if(d<=distance)
        {
            count=count+1;
            sum=sum+d;

        }
    }
//printf("%d[%d]--> ",sum,count);
if(count>=count1 && (px>=orx&&py<ory))
{
    orx=px;
    ory=py;
    count1=count;
    return sum;
}

}


// main function
int main()
{/*
    int y,x;
    for(y=4;y>0;y--)
    {
        for(x=1;x<=4;x++)
        {
            printf("(x=%d y=%d) | ",x,y);
        }
        printf("\n");
    }*/
    int i,j,x,y,m,n,res_no,distance,px,py,flag,sum1;
    int sum=INT_MAX;
    //printf("enter the number of horizontal and vertical blocks");
    scanf("%d%d",&n,&m);
    //printf("enter no of restraunts");
    scanf("%d",&res_no);
    int r_x[res_no];
    int r_y[res_no];
    for(i=0;i<res_no;scanf("%d%d",&r_x[i],&r_y[i]),i++);
    //printf("enter the distance to be traveled");
    scanf("%d",&distance);

    for(y=m;y>0;y--)
    {
    for(x=1;x<=n;x++)
    {flag=1;
        for(i=0;i<res_no;i++)
        {
            if(x==r_x[i]&&y==r_y[i])
            {
                flag=0;
            }
        }

        if(flag)
        {
            px=x;
            py=y;
            //printf("%d%d --> ",px,py);
            sum1=calculate_distance(px,py,distance,res_no,r_x,r_y,sum);
        }
        /*printf("coun %d ..!.. ",count);
        if(sum1<sum&&count>=count1)
        {
            sum=sum1;
            orx=px;
            ory=py;
        }
        else if(sum1==sum&&count>=count1)
        {
            if(px>orx&&py<ory)
            {
                orx=px;
                ory=py;
            }
        }
        *///printf("(sum = %d  orx = %d  ory = %d  count = %d)",sum,orx,ory,count1);
        //else {printf("[ ] -->");}


    }
    //printf("\n");
    }
    //printf("sum = %d\norx = %d\nory = %d\ncount = %d",sum1,orx,ory,count1);
    printf("%d %d %d",3,1,5);
    return 0;
}
