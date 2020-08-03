#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include<fstream.h>
double counter = 0;

int max( int a[1000], int n)
{
	int flag,i;
	flag = a[1];
	for(i=2;i<=n;++i)
		if(a[i]>flag)
			flag = a[i];
	return flag;
}

void countsort(int a[1000],int k,int n)
{
	int c[1000],b[1000],i,j;
	for(i=0;i<=k;i++)
		c[i]=0;

	for(j=1; j<=n; ++j)
		c[a[j]] = c[a[j]]+1;   // c[i] now contains the no. of elements equals to i

	for(i=1; i<=k; ++i)
		c[i] = c[i] + c[i-1];  // c[i] now contains the no. of elements <= i

	for(j=n; j>=1; --j)
	{
		b[c[a[j]]] = a[j];
		c[a[j]] = c[a[j]] -1;
	}
	for(i=1; i<=n; ++i)
		a[i] = b[i];
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
	cout<<"Number of test cases:";
	scanf("%d",&Test);
	while(Test--)
	{
		size=size+10;
		n=size;
		A=new int[n];
		for(int i=1;i<=n;++i)
			A[i]=rand()%INT_MAX+INT_MIN ;
		countsort(A,1,n);
		printf("\n%d\t%lf",n,counter);
		f<<"\n";
		f<<n;
		f<<"\t";
		f<<counter;
		delete A;
	}

getch();
}
