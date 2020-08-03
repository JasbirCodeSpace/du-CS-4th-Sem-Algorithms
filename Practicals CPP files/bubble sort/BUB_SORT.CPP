#include<stdio.h>
#include<conio.h>
int bubsort(int [],int);
void main()
{
	clrscr();
	int *A;
	int n,counter;
	printf("\nEnter the size of array: ");
	scanf("%d",&n);
	A=new int[n];
	printf("\nEnter the elements of array:\n");
	for(int i=0;i<n;++i)
		scanf("%d",&A[i]);
	counter=bubsort(A,n);
	printf("\nThe sorted array is:");
	for(i=0;i<n;++i)
		printf("\n%d",A[i]);
	printf("\nThe number of comparisons are: %d",counter);
	getch();
}
int bubsort(int A[],int n)
{
	int temp,counter=0;
//counter for no. of comparisons
	for(int i=0;i<n-1;++i)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				counter++;
			 }
			else
				counter++;
		}
	}
	return counter;
}