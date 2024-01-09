//DLL
#include <iostream>
using namespace std;
struct node
{
int data;
struct node *next,*prev;
}*start;
struct node *createnode()
{
struct node *ntemp;
ntemp= new node;
cout<<"Enter your data";
cin>>ntemp->data;
ntemp->prev=NULL;
ntemp->next=NULL;
return ntemp;
}
void display()
{
struct node *trav;
trav=start;
while(trav!=NULL)
{
cout<<trav->data<<"-->";
trav=trav->next;
}
cout<<"NULL";
}
void display_back()
{
struct node *trav;
trav=start;
while(trav->next!=NULL)
{
trav=trav->next;
}
while(trav!=NULL)
{
cout<<trav->data<<"-->";
trav=trav->prev;
}
cout<<"NULL";
}
void DLL()
{
struct node *ntemp,*trav;
int n,i;
start=NULL;
cout<<"Enter the number of node u create LL";
cin>>n;

for(i=0;i<n;i++)
{
ntemp=createnode();
if(start==NULL)
start=ntemp;
else
{
trav=start;
while(trav->next!=NULL)
{
trav=trav->next;
}
trav->next=ntemp;
ntemp->prev=trav;
}
}
display();
}
void insert_beg()
{
struct node *ntemp;
ntemp=createnode();
ntemp->next=start;
start->prev=ntemp;
start=ntemp;
display();
}
void insert_end()
{
struct node *ntemp,*trav;
ntemp=createnode();
trav=start;
while(trav->next!=NULL)
{
trav=trav->next;
}
trav->next=ntemp;
ntemp->prev=trav;
display();
}
void insert_mid()
{
struct node *trav,*ntemp;
trav=start;
int skey;
cout<<"Enter key want to insert after the node";
cin>>skey;
ntemp=createnode();
while(trav->data!=skey)

{
trav=trav->next;
}
ntemp->next=trav->next;
trav->next->prev=ntemp;
trav->next=ntemp;
ntemp->prev=trav;
display();
}
void del_beg()
{
struct node *trav;
trav=start;
start=start->next;
delete trav;
display();
}
void del_end()
{
struct node *trav,*old;
trav=start;
while(trav->next!=NULL)
{
old=trav;
trav=trav->next;
}
old->next=NULL;
trav->prev=NULL;
delete trav;
display();
}
void del_mid()
{
struct node *trav,*old;
trav=start;
int skey;
cout<<"Enter key want to delete";
cin>>skey;
while(trav->data!=skey)
{
trav=trav->next;
}
trav->prev->next=trav->next;
trav->next->prev=trav->prev;
trav->next=trav->prev=NULL;
delete trav;
display();
}
int main()

{
int ch;
do
{
cout<<"**********Menu**********"<<endl;
cout<<"1.DLL"<<endl;
cout<<"2.display_back"<<endl;
cout<<"3.insert_beg"<<endl;
cout<<"4.insert_mid"<<endl;
cout<<"5.insert_end"<<endl;
cout<<"6.del_beg"<<endl;
cout<<"7.del_mid"<<endl;
cout<<"8.del_end"<<endl;
cout<<"Enter choice"<<endl;
cin>>ch;
switch(ch)
{
case 1:DLL();
break;
case 2: cout<<"\nsplay backword"<<endl;
display_back();
break;
case 3: insert_beg();
break;
case 4: insert_mid();
break;
case 5:insert_end();
break;
case 6:del_beg();
break;
case 7:del_mid();
break;
case 8:del_end();
break;
}
}while (ch!=9);
return 0;
}