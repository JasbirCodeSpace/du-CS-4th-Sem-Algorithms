#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include<fstream.h>
double counter=0;
int partition (int A[], int l, int h)
{
    int temp=(rand()%(h-l+1))+l;
    if(temp!=h)
    {
	A[temp]=A[temp]+A[h];
	A[h]=A[temp]-A[h];
	A[temp]=A[temp]-A[h];
    }
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
		quickSort(A,1,n);
		printf("\n%d\t%lf",n,counter);
		f<<"\n";
		f<<n;
		f<<"\t";
		f<<counter;
		delete A;
	}
	f.close();
	getch();
}