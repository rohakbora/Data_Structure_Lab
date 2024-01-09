//PostFix
#include<iostream>
#include<string.h>
#define max 10
using namespace std;

class Stack
{
public:
int top;
char stk[10];
public:
Stack()
{
top=-1;
}

int empty()
{
if(top==-1)
return(1);
else
return(0);
}

int full()
{
if(top==max-1)

return(1);
else
return(0);
}

void push(char ch)
{
if(full())
cout<<"\nStack overflow:\n";
else
{
top=top+1;
stk[top]=ch;
}
}

char pop()
{
char ch;
if(empty())
{
cout<<"stack is empty"<<"\0";
return -1;
}
else
ch=stk[top--];
return ch;

}

int cal(int opd1,int opd2,char ch)
{
if(ch=='+')
return opd1+opd2;
if(ch=='-')
return opd1-opd2;
if(ch=='*')
return opd1*opd2;
if(ch=='/')
return opd1/opd2;
return 0;
}

void Evalpost(char postfix[])
{
char ch;
int opd2,opd1,res,val;
for(int i=0;postfix[i]!='\0';i++)
{
ch=postfix[i];
if(ch>='a' && ch<='z') //ch is operande
{
cout<<ch<<" is opearand so put the value";
cin>>val;
push(val);

}
else //ch is operator
{
opd2=pop();
opd1=pop();
res=cal(opd1,opd2,ch);
push(res);
}
}
res=pop();
cout<<res;
}

};
int main()
{
Stack s;
char postfix[10],ch;
cout<<"Enter Expression";
cin>>postfix;
s.Evalpost(postfix);
return 0;
}