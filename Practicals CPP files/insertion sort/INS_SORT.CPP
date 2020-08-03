#include<stdio.h>
#include<conio.h>
int insertionsort(int [],int);
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
	counter=insertionsort(A,n);
	printf("\nThe sorted array is:");
	for(i=0;i<n;++i)
		printf("\n%d",A[i]);
	printf("\nThe number of comparisons are: %d",counter);
	getch();
}
int insertionsort(int A[],int n)
{
	int value,hole,counter=0;
//value to store current value,hole to store current pos,counter for no. of comparisons
	for(int i=1;i<n;++i)
	{
		value=A[i];
		hole=i;
		while(hole>0&&A[hole-1]>value)
		{
			A[hole]=A[hole-1];
			hole--;
			counter++;
		}
		if(hole)
			counter++;
		A[hole]=value;
	}
	return counter;
}