#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
#include<fstream.h>
double selsort(int [],int);
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
		counter=selsort(A,n);
		printf("\n%lf",counter);
		f<<"\n";
		f<<n;
		f<<"\t";
		f<<counter;
		delete A;
	}
	getch();
}
double selsort(int A[],int n)
{
	int pos,temp;
	double counter=0;
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