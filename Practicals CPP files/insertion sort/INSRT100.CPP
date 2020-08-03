#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include<fstream.h>
double insertionsort(int [],int);
void main()
{
	clrscr();
	time_t t;
	fstream f;
	f.open("abc.txt",ios::out);
	srand((unsigned) time(&t));
	int Test;
	int *A;
	int n,size=500;
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
		counter=insertionsort(A,n);
		printf("\n%d\t%lf",n,counter);
		f<<"\n";
		f<<n;
		f<<"\t";
		f<<counter;
		delete A;
	}
	getch();
}
double insertionsort(int A[],int n)
{
	int value,hole;
	double counter=0;
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