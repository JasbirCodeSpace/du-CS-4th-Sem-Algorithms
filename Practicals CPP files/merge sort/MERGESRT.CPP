#include<stdio.h>
#include<conio.h>
#include<limits.h>
int counter;
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
	int *A;
	int n;
	printf("\nEnter the size of array: ");
	scanf("%d",&n);
	A=new int[n];
	printf("\nEnter the elements of array:\n");
	for(int i=0;i<n;++i)
		scanf("%d",&A[i]);
	mergesort(A,0,n-1);
	printf("\nThe sorted array is:");
	for(i=0;i<n;++i)
		printf("\n%d",A[i]);
	printf("\nThe number of comparisons are: %d",counter);
	getch();
}