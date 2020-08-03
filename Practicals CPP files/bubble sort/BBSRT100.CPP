#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include<fstream.h>
double bubsort(int [],int);
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
	double counter;
	cout<<"Number of test cases:";
	scanf("%d",&Test);
	while(Test--)
	{
		size=size+10;
		n=size;
		A=new int[n];
		for(int i=0;i<n;++i)
			A[i]=rand()%INT_MAX+INT_MIN ;
		counter=bubsort(A,n);
		printf("\n%lf",counter);
		f<<"\n";
		f<<n;
		f<<"\t";
		f<<counter;
		delete A;
	}
	getch();
}
double bubsort(int A[],int n)
{
	int temp;
	double counter=0;
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