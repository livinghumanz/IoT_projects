/*------------------
 program to sort the element in odd position in decending order and element in even position in ascending order
example :
i/p : 13,2,4,15,12,10,5
o/p : 13,2,12,10,5,15,4

i/p : 1,2,3,4,5,6,7,8,9
o/p : 9,2,7,4,5,6,3,8,1

-----------------------------------*/
#include<stdio.h>
int main()
{
    int a[100],count=0,i;
    while(count<3)
    {
        scanf("%d,",&a[count]);
        count++;
    }
    //char ch="\n";
    printf("%c",13 );
    printf("hello");
    printf("%c",13 );
    for(i=0;i<count;printf("%d,",a[i]),i++);

    return 0;
}
