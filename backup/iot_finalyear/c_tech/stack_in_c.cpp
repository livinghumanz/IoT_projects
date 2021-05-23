//implementation of stack
//Create directories and nested directories and search of a word in all files in all the directories.
//The second round I was asked to solve a problem using lot of concepts in data structures
/*Input : {[]{()}}
Output : Balanced

Input : [{}{}(]
Output : Unbalanced
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
void push(char);
void display();
void pop();
struct stack
{
    char value;
    struct stack * next;
}*top;

int main()
{
    int i=1,val;
    char p[100],ch;
    std::cin>>p;
    push(p[0]);
    while(p[i]!='\0')
    {
        ch=p[i];
        printf("%c",ch);

        //printf("%c",top->value);
        if(top->value=='{'&&ch=='}'||top->value=='['&&ch==']'||top->value=='('&&ch==')')
        pop();
        else
        push(ch);

        i++;
    }
    if(top==0)
    std::cout<<"balanced";
    else
    std::cout<<"not balanced";
    //display();

    return 0;
}
void push(char value)
{
    struct stack * ptr;
    ptr=(struct stack*)malloc(1*sizeof(struct stack));
    ptr->value=value;
    ptr->next=top;
    top=ptr;
    std::cout<<"pushed";
}
void display()
{
    struct stack *ptr;
    ptr=top;
    std::cout<<"\n";
    while(ptr)
    {
        std::cout<<ptr->value<<"--";
        ptr=ptr->next;
    }
}
void pop()
{
    display();
    top=top->next;
    display();

}
