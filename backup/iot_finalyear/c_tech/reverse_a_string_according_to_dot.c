/******************************************************************************
i/p : hi.hello.how
o/p : how.hello.hi

*******************************************************************************/

#include <stdio.h>
//#include<string.h>
struct dc
{
    int count;
}d[100];
int main()
{
    char string1[100];
    char rearanged_string[100];
    int scount=0,i=0,j=0,k=0,nd=0,l=0;
    scanf("%[^\n]s",string1);
    while(string1[i]!='\0')
    {
        scount++;
        if(string1[i]=='.')
        {
            nd++;
            d[nd].count=i;
            printf("dc[%d] : %d ",nd,d[nd].count);
        }
       // else {rearanged_string[k]=string1[i];
         //   k++;
        i++;

    }
    //rearanged_string[k]='\0';
    printf("\nscount : %d\nno of dot : %d\n",scount,nd);
   // printf("%s ",rearanged_string);
   l1:
   for(k=d[nd].count+1;k>=0&&nd!=0;k++)
   {
       if(string1[k]!='.'&&string1[k]!='\0')
       {
           rearanged_string[j]=string1[k];
       }
       else if(string1[k]=='.'||string1[k]=='\0')
       {
           nd=nd-1;
           rearanged_string[j]='.';
           j++;
           goto l1;
       }
    j++;
   }
   while(string1[l]!='.')
   {rearanged_string[j]=string1[l]; j++;l++;}
   rearanged_string[j]='\0';
 printf("%s ",rearanged_string);

    return 0;
}
