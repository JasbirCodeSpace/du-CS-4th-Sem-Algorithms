#include<stdio.h>
#include<conio.h>
int heapsort(int []);
int build_max_heap(int[]);
int max_heapify(int[],int);
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
	int *A;
	int n,counter;
	printf("\nEnter the size of heap: ");
	scanf("%d",&n);
	A=new int[n];
	printf("\nEnter the elements of heap:\n");
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	heapsize=n;
	counter=heapsort(A);
	printf("\nThe sorted heap is:");
	for(i=1;i<=n;++i)
		printf("\n%d",A[i]);
	printf("\nThe number of comparisons are: %d",counter);
	getch();
}
int heapsort(int A[])
{
	int temp;
	int counter=0;
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
int build_max_heap(int A[])
{
	int counter=0;
	for(int i=(heapsize/2);i>=1;--i)
		counter+=max_heapify(A,i);
	return counter;
}
int max_heapify(int A[],int i)
{
	int largest,counter=0;
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
