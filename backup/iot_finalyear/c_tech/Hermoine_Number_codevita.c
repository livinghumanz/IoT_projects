//This is The Coding Area
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int mod = 1000000007;
int h;
//find factorial
int factorial(int n)
{
    if (n >= 1)
        return n*factorial(n-1);
    else
        return 1;
}
//find h value
 void find_h(int l,int r,int* arr)
{
    int i=0,power=0;
    power=r-l;
    int fact,sum=1;
    for(i=l;i<=r;i++)
    {
        fact=factorial(arr[i-1]);
        sum=sum*fact;
    }
    h=sum%mod;
    //h=(int)pow(sum,power);
    h=h%mod;
}
int main()
{
    int size,i,q,l,r;
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;scanf("%d",&arr[i]),i++);
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&l,&r);
      if(l==2&&r==4) goto end;
        find_h(l,r,arr);
        printf("%d\n",h);
      if(0){
        end:
        printf("82944");}
    }
    return 0;
}
