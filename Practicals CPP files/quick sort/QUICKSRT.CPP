#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<limits.h>
int counter=0;
int partition (int A[], int l, int h)
{
    int x = A[h];
    int i = (l - 1);
    for (int j = l; j <= h-1;j++)
    {
	if (A[j] <= x)
	{
	    i=i+1;
	    if(i!=j)
	    {
		A[i]=A[i]+A[j];
		A[j]=A[i]-A[j];
		A[i]=A[i]-A[j];
	    }
	}
	counter++;
    }
    if(i+1!=h)
    {
	A[i+1]=A[i+1]+A[h];
	A[h]=A[i+1]-A[h];
	A[i+1]=A[i+1]-A[h];
    }
    return (i + 1);
}
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
	int p = partition(A, l, h);
	quickSort(A, l, p - 1);
	quickSort(A, p + 1, h);
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
	for(int i=1;i<=n;++i)
		scanf("%d",&A[i]);
	quickSort(A,1,n);
	printf("\nThe sorted array is:");
	for(i=1;i<=n;++i)
		printf("\n%d",A[i]);
		printf("\nThe number of comparisons are: %d",counter);
	getch();
}