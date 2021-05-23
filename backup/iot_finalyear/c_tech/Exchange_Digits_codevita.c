#include <stdio.h>
int value=10000001;// value according to the Constraints given

//function to merge and print the value ans number from array
void print(int arr[], int size,int num1)
{
    int i,sum=0,temp=0;
    for(i=0; i<size; i++)
    {
        sum=(sum*10)+arr[i];
    }
    temp=sum;
    if(temp>num1&&temp<value)
        value = temp;
}

//function to swap the variables
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//permutation function
void poss_val(int *arr, int start, int end,int num1)
{
    if(start==end)
    {
        print(arr, end+1,num1);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        swap((arr+i), (arr+start));

        poss_val(arr, start+1, end,num1);
        swap((arr+i), (arr+start));
    }
}

int main()
{
    //taking input to the array
    int num,num1,pow=1,size=0;
    scanf("%d%d",&num,&num1);
    while(num/pow)
    {
        pow=pow*10;
        size++;
    }
    pow=pow/10;
    int i=0;
    int arr[size];
    while(pow)
    {
        arr[i]=(num/pow)%10;
        i++;
        pow=pow/10;

    }
    //function to find possible combination
    poss_val(arr, 0, size-1,num1);
    if(value==10000001)
        value=-1;
    printf("%d",value);
    return 0;
}
