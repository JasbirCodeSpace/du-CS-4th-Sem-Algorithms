#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#include<fstream.h>
double heapsort(int []);
double build_max_heap(int[]);
double max_heapify(int[],int);
int heapsize;
int left(int i)
{
	return (2*i);
}
int right(int i)
{
	return (2*i)+1;
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
	int n,size=20;
	double counter=0;
	cout<<"Number of test cases:";
	scanf("%d",&Test);
	while(Test--)
	{
		size=size+10;
		n=size;
		A=new int[n];
		heapsize=n;
		for(int i=1;i<=n;++i)
			A[i]=rand()%INT_MAX+INT_MIN ;
		counter=heapsort(A);
		printf("\n%d\t%lf",n,counter);
		f<<"\n";
		f<<n;
		f<<"\t";
		f<<counter;
		delete A;
	}
	getch();
}
double heapsort(int A[])
{
	int temp;
	double counter=0;
	counter+=build_max_heap(A);
	for(int i=heapsize;i>=2;--i)
	{
		temp=A[1];
		A[1]=A[i];
		A[i]=temp;
		heapsize=heapsize-1;
		counter+=max_heapify(A,1);
	}
	return counter;
}
double build_max_heap(int A[])
{
	double counter=0;
	for(int i=(heapsize/2);i>=1;--i)
		counter+=max_heapify(A,i);
	return counter;
}
double max_heapify(int A[],int i)
{
	int largest;
	double counter=0;
	int l=left(i);
	int r=right(i);
	if(l<=heapsize && A[l]>A[i])
	{
		largest=l;
		counter++;
	}
	else
		largest=i;
	if(l<=heapsize)
		counter++;
	if(r<=heapsize &&A[r]>A[largest])
	{
		largest=r;
		counter++;
	}
	if(r<=heapsize)
		counter++;
	if(largest!=i)
	{
		A[i]=A[i]+A[largest];
		A[largest]=A[i]-A[largest];
		A[i]=A[i]-A[largest];
		counter+=max_heapify(A,largest);
	}
	return counter;
}
