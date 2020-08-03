#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#include<fstream.h>
double counter;
void merge(int A[],int p,int q,int r)
{
	int i,j,k,*c;
	c=new int[sizeof(A)];
	i=p;
	k=p;
	j=q+1;
	while(i<=q&&j<=r)
	{
		if(A[i]<A[j])
		{
			c[k]=A[i];
			k++;i++;
		}
		else
		{
			c[k]=A[j];
			k++;j++;
		}
		counter++;
	}
	while(i<=q)
	{
		c[k]=A[i];
		k++;
		i++;
	}
	while(j<=r)
	{
		c[k]=A[j];
		k++;
		j++;
	}
	for(i=p;i<k;++i)
	{
		A[i]=c[i];
	}
	delete c;
}
void mergesort(int A[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
}
void main()
{
	clrscr();
	time_t t;
	fstream f;
	f.open("abc.txt",ios::out);
	srand((unsigned) time(&t));
	int Test;
	int *A;
	int n,size=520;
	cout<<"Number of test cases:";
	scanf("%d",&Test);
	while(Test--)
	{
		size=size+10;
		n=size;
		A=new int[n];
		counter=0;
		for(int i=0;i<n;++i)
			A[i]=rand()%INT_MAX+INT_MIN ;
		mergesort(A,0,n);
		printf("\n%lf",counter);
		f<<"\n";
		f<<n;
		f<<"\t";
		f<<counter;
		delete A;
	}
	getch();
}