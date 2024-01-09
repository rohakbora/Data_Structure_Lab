#include <iostream>
#include <string>
using namespace std;
string q[10];
int pr[10];
int r=-1,f=-1,n;
void enqueue(string data,int p)
{
	int i;
	if((f==0)&&(r==n-1))
		cout<<"q full";
	else
	{
		if(f==-1)
		{
			f=r=0;
			q[r]=data;
			pr[r]=p;

		}
		else
		{
			for(i=r;i>=f;i--)
			{
				if(p>pr[i])
				{
					q[i+1]=q[i];
					pr[i+1]=pr[i];
				}
				else
					break;
			}
			q[i+1]=data;
			pr[i+1]=p;
			r++;
		}

	}
}
void print()
{
	int i;
	for(i=f;i<=r;i++)
	{
		cout<<"patient name "<<q[i];
		switch(pr[i])
		{
		case 1:
			cout<<"priority-checkup"<<endl;
			break;
		case 2:
			cout<<"priority-non serious"<<endl;
			break;
		case 3:
			cout<<"priority-serious"<<endl;
			break;
		default:
			cout<<"priority not found"<<endl;
		}
	}
}
void dequeue()
{
	if(f==-1)
	{
		cout<<"queue is empty";

	}
	else
	{
		cout<<"deleted element"<<q[f]<<endl;
		cout<<"iTSpriority="<<pr[f]<<endl;
		if(f==r)f=r=-1;
		else f++;

	}
}
int main()
{
	string data;
	int opt,i,p;
	cout<<"enter your choice"<<endl;
	do
	{
		cout<<"1.for insert data in queue"<<endl<<"2 for show data in queue"<<endl<<"3 for delete data from queue"<<endl<<"0 for exit"<<endl;
		cin>>opt;
		switch(opt)
		{
		case 1:
			cout<<"enter number of patient"<<endl;
			cin>>n;
			i=0;
			for(i=0;i<n;i++)
			{
				cout<<"enter your name of patient";
				cin>>data;
				cout<<"enter your priority(3-serious,2-non-serious,1-general checkup)";
			cin>>p;
			enqueue(data,p);
			}
			break;
			case 2:
				print();
			break;
			case 3:
			dequeue();
			break;
		}
	}
	while(opt!=0);
	return 0;
}

