#include<stdio.h>
#include<conio.h>
int selsort(int [],int);
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
	counter=selsort(A,n);
	printf("\nThe sorted array is:");
	for(i=0;i<n;++i)
		printf("\n%d",A[i]);
	printf("\nThe number of comparisons are: %d",counter);
	getch();
}
int selsort(int A[],int n)
{
	int pos,temp,counter=0;
//pos to store current pos of min element ,counter for no. of comparisons
	for(int i=0;i<n-1;++i)
	{
		pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(A[j]<A[pos])
			{
				pos=j;
				counter++;
			}
			else
				counter++;
		}
		temp=A[i];
		A[i]=A[pos];
		A[pos]=temp;
	}
	return counter;
}