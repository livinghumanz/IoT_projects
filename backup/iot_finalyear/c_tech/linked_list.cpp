//singular link list (insert , delete , search , print)

#include<stdio.h>
#include<iostream>
#include<stdlib.h>
struct sll
{
    int value;
    struct sll *next;
}*node;
struct sll *first;
void insert(int);
void display();
void Delete(int);
int main()
{
    int i=0;
    while(i!=10){
    insert(50+i);
    i++;}
display();
Delete(52);
std::cout<<std::endl;
display();

    return 0;
}
void insert(int value)
{
    struct sll * val;
    val=(struct sll*)malloc(1*sizeof(struct sll));
    val->value=value;
    val->next=NULL;
    if(first==NULL)
    {
        first=val;
        node=first;
    }
    else
    {
        node->next=val;
        node=val;
    }
}
void display()
{
    struct sll *ptr;
    ptr=first;
    while(ptr)
    {
        printf("%d--",ptr->value);
        ptr=ptr->next;
    }
}
void Delete(int value)
{
    struct sll *ptr,*ptr1;
    ptr1=first;
    if(ptr1->value==value)
        first=first->next;
    ptr=ptr1->next;
    while(ptr)
    {
        if(ptr->value==value)
            {
                ptr1->next=ptr->next;
                ptr=ptr->next;
            }
            ptr1=ptr;
            ptr=ptr->next;
    }
}
