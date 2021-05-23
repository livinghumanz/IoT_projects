#include <stdio.h>

int main()
{
    int num,i,j,jmin,jmax,num1;
    scanf("%d",&num);
    jmax=jmin=num;
    int k=num;
    char ch='*';
    for(i=0;i<num;i++)
    {
        //jmax=num+i;
        //jmin=num-i;
        printf("%*c",k,'*' );
        for(j=1;j<num*2;j++)
        {
            if(j>=jmin&&j<=jmax)
            printf("*");
            else printf(" ");
        }
        printf("\n");
    }

    return 0;
}
