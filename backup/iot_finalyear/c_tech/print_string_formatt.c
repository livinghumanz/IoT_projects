/******************************************************************************
Write a program to give the following output for the given input

Eg 1: Input: a1b10
       Output: abbbbbbbbbb
Eg: 2: Input: b3c6d15
          Output: bbbccccccddddddddddddddd
The number varies from 1 to 99.

*******************************************************************************/

#include <stdio.h>
#include<ctype.h>

int main()
{
    int i=0,j=0;
    long int value,num=0;
    char new_s[20],old_s[20],c[10];
    scanf("%s",old_s);
    while(old_s[i]!='\0')
    {
        if(isdigit(old_s[i]))
        {
            c[0]=old_s[i];
            value=strtol(c,&c,10);
            num=(num*10)+value;
        }
        else{
            new_s[j]=old_s[i];
            j++;
        }
        if(!isdigit(old_s[i+1])&&num!=0)
        {
            while(num!=0)
            {
                printf("%s",new_s);
                num--;
            }
            j=0;
        }

        i++;
    }
   // printf("Hello World");

    return 0;
}
