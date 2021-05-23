/*************************************************************************************************************************************************************************************************************************
Given an array of positive integers. Your task is to find the leaders in the array.
Note: An element of array is leader if it is greater than or equal to all the elements to its right side. Also, the rightmost element is always a leader.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

Constraints:
1 <= T <= 100
1 <= N <= 107
0 <= Ai <= 107

Example:
Input:
3
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
Output:
17 5 2
4 0
7 7 3

Explanation:
Testcase 3: All elements on the right of 7 (at index 0) are smaller than or equal to 7. Also, all the elements of right side of 7 (at index 3) are smaller than 7. And, the last element 3 is itself a leader since no elements are on its right.
******************************************************************************************************************************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t_case,ar_size,itr;
    int* arr_element;
    scanf("%d",&t_case);
    while(t_case!=0)
    {
        scanf("%d",&ar_size);
        arr_element=(int *)malloc(ar_size*sizeof(int));
        for(itr=0;itr<ar_size;scanf("%d",&arr_element[itr]),itr++);
        arr_leader(arr_element,ar_size);
        t_case--;
    }
    return 0;
}
int arr_leader(int* arr_element,int ar_size)
{
    int greater=0,greater1=0;
    int itr,itr1;
    for(itr=0;itr<ar_size;itr++)
    {
        for(itr1=itr;itr1<ar_size;itr1++)
        {
            if(greater<arr_element[itr1])
                greater=arr_element[itr1];
        }
        if(greater!=greater1)
        {
            printf("%d ",greater);
            greater1=greater;
            greater=0;
        }
        else{greater=0;}
    }
    return 0;
}
