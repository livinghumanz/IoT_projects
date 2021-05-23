#include<stdio.h>
int main()
{
    int n=4,j,i,m=1,c=0;
    //int m=n*2;
    while(1){
        c=!c;
        if(c==1)
    for(i=1;i<7;i++)
    {
        for(j=1;j<7;j++)
        {
            if((i==j))
            printf("%d ",n);
            else
            printf("   ");
        }
        printf("\n");
    }
    else
    for(i=1;i<7;i++)
    {
        for(j=1;j<7;j++)
        {
            if((i==(m+(i-1))&&j==(n-(i-1))))
            printf("%d ",n);
            else
            printf("   ");
        }
        printf("\n");
    }
}
}
