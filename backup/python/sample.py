''' ebill
class appartment:
    def __init__(self,fno,oname,eb):
        self.fno=fno
        self.oname=oname
        self.eb=eb
class appdemo:
    def __init__(self):
        pass
    def getsecminbill(self,*olist):
        bl=[]
        for i in olist:
            bl.append(i.eb)
        bl=sorted(bl)
        return(bl[1])
if __name__=='__main__':
    obl=[]
    t=int(input())
    for tc in range(t):
        fno=int(input())
        oname=input()
        bill=int(input())
        obl.append(appartment(fno,oname,bill))
    nobj=appdemo()
    print(nobj.getsecminbill(*obl))
'''
'''class mobile:
    def __init__(self,sp,mno,du,pmtd):
        self.sp=sp
        self.mno=mno
        self.du=du
        self.pmtd=pmtd
    def calcbill(self):
        bl=[]
        if self.sp=='airtel':
            tc=11*self.du
            if self.pmtd=='paytm':
                tc=int(tc-(tc*0.1))
        elif self.sp=='jio':
            tc=10*self.du
        self.tc=tc
        bl.append(self.mno)
        bl.append(self.tc)
        return(bl)
if __name__=='__main__':
    t=int(input())
    obl=[]
    for tc in range(t):
        op=input()
        mno=int(input())
        du=int(input())
        pmtd=input()
        obl.append(mobile(op,mno,du,pmtd))
        print(obl[tc].calcbill())
'''
'''class item:
    def __init__(self,iid,iname,ip,iq):
        self.iid=iid
        self.iname=iname
        self.ip=ip
        self.iq=iq
    def calcprice(self,qty):
        #print(self.iname,self.iq,end='-> ')
        if self.iq>=qty:
            return(qty*self.ip)
        else:
            return 0
class store(item):
    def __init__(self,*ilist):
        self.ilist=ilist
    def genbill(self,**dinp):
        bc=0
        dkey=dinp.keys()
        for i in dkey:
            for j in self.ilist:
                if i==j.iname:
                    qt=dinp[i]
                    price=j.calcprice(qt)
                    bc=bc+price
        return bc
if __name__=='__main__':
    t=int(input())
    il=[]
    for tc in range(t):
        iid=int(input())
        name=input()
        price=int(input())
        qt=int(input())
        il.append(item(iid,name,price,qt))
    dno=int(input())
    dl={}
    for i in range(dno):
        name=input()
        qt=int(input())
        dl[name]=qt
    s=store(*il)
    price=s.genbill(**dl)
    print(price)
'''
'''import math
def cp(no):
    count=0
    sq=int(math.sqrt(no))+1
    if no!=0 and no!=1:
        for i in range(2,sq):
            if no%i==0:
                count+=1
        if count==0:
            return 1
        else:
            return 0
    else:
        return -1
def pclist(*elist):
    p=[]
    c=[]
    pc=[]
    for i in elist:
        if cp(i)==1:
            p.append(i)
        elif cp(i)==0:
            c.append(i)
    pc.append(p)
    pc.append(c)
    return pc
if __name__=='__main__':
    il=[]
    t=int(input())
    for tc in range(t):
        il.append(int(input()))
    print(cp(il[1]))
    print(pclist(*il))
'''
'''class book:
    def __init__(self,bid,bname):
        self.bid=bid
        self.bname=bname
class library:
    def __init__(self,lid,add,*blist):
        self.lid=lid
        self.add=add
        self.blist=blist
    def bc(self,c):
        count=0
        for i in self.blist:
            if i.bname.startswith(c):
                count+=1
        return count
    def delbook(self,*dblist):
        blist=list(self.blist)
        for i in dblist:
            for j in blist:
                if i==j.bname:
                    ind=blist.index(j)
                    blist.pop(ind)
                    print(j.bname,ind)
        bl1=[]
        for i in blist:
            bl1.append(i.bname)
        return bl1
if __name__=='__main__':
    t=int(input())
    bl=[]
    for i in range(t):
        bid=int(input())
        name=input()
        bl.append(book(bid,name))
    c=input()
    l=library(1,'aa',*bl)
    print(l.bc(c))
    db=int(input())
    dbl=[]
    for i in range(db):
        dbl.append(input())
    print(l.delbook(*dbl))
'''
'''def countwords(str):
    slist=str.split(' ')
    sstr=set(slist)
    dstr={}
    for i in sstr:
        count=0
        for j in slist:
            if i==j:
                count+=1
        dstr[i]=count
    return dstr
def maxoccr(stri):
    dstr=countwords(stri)
    dkey=dstr.keys()
    dval=dstr.values()
    m=max(dval)
    for i in dkey:
        if dstr[i]==m:
            print(i)
if __name__=='__main__':
    s=input()
    maxoccr(s)
'''
'''class employee:
    def __init__(self,ename,eid,epos,esal):
        self.ename=ename
        self.eid=eid
        self.epos=epos
        self.esal=esal
    def incsal(self,ip):
        percent=self.esal+((self.esal*ip)/100)
        self.esal=percent
class indus:
    def __init__(self,*el):
        self.elist=el
    def esalinc(self,ipos,ip):
        self.ipos=ipos
        self.ip=ip
        inlis=[]
        for i in self.elist:
            if i.epos==self.ipos:
                i.incsal(self.ip)
                inlis.append(i)
        return inlis
                
if __name__=='__main__':
    n=int(input())
    el=[]
    for i in range(n):
        ename=input()
        eid=int(input())
        epos=input()
        esal=float(input())
        el.append(employee(ename,eid,epos,esal))
    ipos=input()
    ip=int(input())
    o=indus(*el)
    result=o.esalinc(ipos,ip)
    for i in result:
        print(i.ename)
        print(i.esal)
    

# check palindrome

def check_palindrome(ls):
    ns=[]
    for i in ls:
        if i.upper()==i[::-1].upper():
            ns.append(i)
    return ns
if __name__=='__main__':
    n=int(input("enter the no of names:"))
    ls=[]
    for i in range(0,n):
        ls.append(input())
    for i in check_palindrome(ls):
        print(i)


#class employee
class Employee:
    def __init__(self,eid,ename,eroll,esal):
        self.emp_id=eid
        self.emp_name=ename
        self.emp_role=eroll
        self.emp_salary=esal
    def increase_salary(self,pi):
        self.emp_salary+=((self.emp_salary*pi)/100)
class Organisation:
    def __init__(self,oname,elist):
        self.org_name=oname
        self.emp_list=elist
    def calculate_increment(self,eroll,ip):
        il=[]
        for emp in self.emp_list:
            if emp.emp_role==eroll:
                emp.increase_salary(ip)
                il.append(emp)
        return il
if __name__=='__main__':
    emp_list=[]
    count=int(input())
    for i in range(count):
        eid=int(input())
        name=input()
        role=input()
        salary=int(input())
        emp_list.append(Employee(eid,name,role,salary))
    o=Organisation("xyz",emp_list)
    inp_role=input()
    inp_percent=int(input())
    result=o.calculate_increment(inp_role,inp_percent)
    if len(result)!=0:
        for emp in result:
            print(emp.emp_name,'\t',emp.emp_salary)
    else:
        print('No employee found with the given role')
        

# question 3
class Account:
    def __init__(self,account_no,account_name,account_balance):
        self.account_no=account_no
        self.account_name=account_name
        self.account_balance=account_balance
    def depositAmnt(self,depamt):
        self.account_balance+=depamt
        return self.account_balance
    def withdrawAmnt(self,wdamt):
        if self.account_balance>=(wdamt+1000):
            self.account_balance-=wdamt
            print(self.account_balance)
            return 1
        else:
            return 0
if __name__=='__main__':
    acno=int(input())
    acname=input()
    acntbal=int(input())
    depamnt=int(input())
    withdrawamnt=int(input())
    acnt=Account(acno,acname,acntbal)
    print(acnt.depositAmnt(depamnt))
    print(acnt.withdrawAmnt(withdrawamnt))
    

# question 4
class Employee:
    def __init__(self,eno,ename,leaves):
        self.empno=eno
        self.empname=ename
        self.leaves=leaves
class Company:
    def __init__(self,cname,emps):
        self.cname=cname
        self.emps=emps
    def display_leaves(self,eno,ltype):
        for i in self.emps:
            if i.empno==eno:
                return i.leaves[ltype]
    def leave_application(self,eno,lt,nl):
        for i in self.emps:
            if i.empno==eno:
                if i.leaves[lt]>=nl:
                    return "Granted"
                else:
                    return "Rejected"
if __name__=='__main__':
    n=int(input())
    c=Company("abc",emps=[])
    for i in range(n):
        leaves={}
        eno=int(input())
        ename=input()
        leaves["cl"]=int(input())
        leaves["el"]=int(input())
        leaves["sl"]=int(input())
        e=Employee(eno,ename,leaves)
        c.emps.append(e)
    empno=int(input())
    ltype=input()
    nol=int(input())
    print(c.display_leaves(empno,ltype))
    print(c.leave_application(empno,ltype,nol))
'''
# question 5

    
