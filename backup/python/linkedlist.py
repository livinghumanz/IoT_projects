import sys
class linkedlist:
    def __init__(self):
        self.head=None
    def printlist(self):
        temp=self.head
        while(temp):
            print(temp.data,end="->")
            temp=temp.next

    #def sorting(self):
    #    if(self.head.value)

class node:
    def __init__(self,data):
        self.data=data
        self.next=None

if( __name__ == "__main__"):
    llist = linkedlist()
    print("1) insert 5 element \n 2) print the element \n 3) delete one element \n 4 display element ")
    inputval = input()
    inplist=inputval.split(',')
    for i in inplist:
        temp=node(int(i))
        temp.next=llist.head
        llist.head=temp
    llist.printlist()
    felement=int(input())
    temp=llist.head
    while(temp):
        if(temp.data==felement):
            print("found")
            break
        else:
            temp=temp.next
            if(temp.next==None):
                print("not found")
    #llist.sorting()
    list(range(10,14,3))
