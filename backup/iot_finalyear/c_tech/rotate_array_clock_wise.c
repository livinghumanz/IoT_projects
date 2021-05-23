/******************************************************************************
Given an unsorted array arr[] of size N, rotate it by D elements (clockwise).

Input:
The first line of the input contains T denoting the number of testcases. First line of eacg test case contains two space separated elements, N denoting the size of the array and an integer D denoting the number size of the rotation. Subsequent line will be the N space separated array elements.

Output:
For each testcase, in a new line, output the rotated array.

Constraints:
1 <= T <= 200
1 <= N <= 107
1 <= D <= N
0 <= arr[i] <= 105

Example:
Input:
2
5 2
1 2 3 4 5
10 3
2 4 6 8 10 12 14 16 18 20

Output:
3 4 5 1 2
8 10 12 14 16 18 20 2 4 6

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr_element,itr;
    int ar_size,t_case,r_element;
    scanf("%d",&t_case);
    while(t_case!=0)
    {
        scanf("%d%d",&ar_size,&r_element);
        arr_element=(int*)malloc(ar_size*sizeof(int));
        for(itr=0;itr<ar_size;scanf("%d",&arr_element[itr]),itr++);
        ar_rotate(arr_element,ar_size,r_element);
        t_case--;
    }

    return 0;
}

int ar_rotate(int* arr_element,int ar_size,int r_element)
{
    int* r_arr;
    r_arr=(int*)malloc(ar_size*sizeof(int));
    int itr,re;
    for(itr=0;itr<ar_size;itr++)
    {
        re=(itr+r_element)%ar_size;
        r_arr[itr]=arr_element[re];
    }
    print_r_arr(r_arr,ar_size);
    return 0;
}


int print_r_arr(int* r_arr,int ar_size)
{
    int itr;
    //printf("\n");
    for(itr=0;itr<ar_size;printf("%d ",r_arr[itr]),itr++);
    printf("\n");
    return 0;
}
