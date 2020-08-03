
//Implement Breadth-First Search in a graph




#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>

class node
{	public:
	int info;
	node *next;
	node()
	{	info=0;
		next=0;
	}
	node(int val,node *ptr)
	{    info=val;
		next=ptr;
	}
};
class list
{    node *head,*tail;
	public:
	list()
	{	head=0;
		tail=0;
	}
	void insert(int val)
	{	if(tail==0)
		{	tail=new node(val,0);
			head=tail;
		}
		else
		{	tail->next=new node(val,0);
			tail=tail->next;
		}
	}
	void delnode()
	{	node *tmp;
		tmp=head;
		head=head->next;
		delete tmp;
	}
	int retinfo(node *ptr)
	{
		return ptr->info;
	}
	node * rethead()
	{
		return head;
	}
};


class queue
{
	int arr[20];
	int front,rear;
	public:
	queue()
	{	front=-1;
		rear=-1;
	}
	void enque(int val)
	{	if(rear==19)
		{	cout<<"OVERFLOW!!";
			getch();
			exit(0);
		}
		else if(rear==-1)
			{	rear=front=0;
				arr[rear]=val;
			}
			else
			{	rear++;
				arr[rear]=val;
			}
	}
	int deque()
	{    int tmp;
		if(front==-1)
		{	cout<<"UNDERFLOW!!";
			getch();
			exit(0);
		}
		else if(front==rear)
			{    tmp=arr[front];
				front=rear=-1;
			}
			else
			{    tmp=arr[front];
				front++;
			}
		return tmp;
	}
	int empty()
	{
		if(front==-1)
		return 1;
		else
		return 0;
	}

}q;

class bfs_path
{
	char c[10];
	int p[10];
	int dist[10];
	public:
	void bfs(list[],int,int);
	void print_path(list[],int,int);
	void get();

};


void bfs_path::bfs(list l[10],int s,int ver)
{
	int i;
	for(i=0;i<ver;i++)
	{
		if(i!=s)
		{
			c[i]='W';
			p[i]=-1;
			dist[i]=0;
		}
	}
	c[s]='G';
	p[s]=-1;
	dist[s]=0;
	q.enque(s);
	int u;
	int v;
	while(!q.empty())
	{
		u=q.deque();
		node *temp;
		for(temp=l[u].rethead();temp!=0;temp=temp->next)
		{
			v=l[u].retinfo(temp);
			if(c[v]=='W')
			{
				c[v]='G';
				dist[v]=dist[u]+1;
				p[v]=u;
				q.enque(v);
			}
		}
		c[u]='B';
	}
}

void bfs_path::print_path(list l[10],int s,int v)
{
	if(s==v)
	cout<<s<<"->";
	else if(p[v]==-1)
	cout<<"\nNo path from "<<s<<" to "<<v<<" exists";
	else
	{
		print_path(l,s,p[v]);
		cout<<v<<"->";
	}
}
void bfs_path::get()
{
	list l[10];
	int v,ver;
	int val;
	int i,j;
	int e;
	int s;
	cout<<"\nEnter number of vertices::";
	cin>>ver;
	for(i=0;i<ver;i++)
	{
		cout<<"\nEnter number of children for node "<<i<<"::";
		cin>>e;
		cout<<"\nEnter adjacent nodes::";
		for(j=0;j<e;j++)
		{
			cin>>val;
			l[i].insert(val);
		}
	}
	cout<<"\nEnter source::";
	cin>>s;
	cout<<"\nEnter destination::";
	cin>>v;
	bfs(l,s,ver);
	cout<<"\nPath from source to destination is";
	print_path(l,s,v);
}

void main()
{
	clrscr();
	bfs_path b;
	b.get();
	getch();
}