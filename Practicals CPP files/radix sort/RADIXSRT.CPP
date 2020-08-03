#include<stdio.h>
#include<conio.h>
void countsort(int A[],int n,int d)
{
       int C[10]={0,0,0};
       int *B,*D;
       B=new int[n+1];
       D=new int[n+1];
       for(int i=1;i<=n;++i)
       {
		D[i]=A[i];
       }
       while(d)
       {
		for(i=1;i<=n;++i)
		{
			if(d!=1)
				D[i]=D[i]/10;
			else
				D[i]=D[i]%10;
		}
		d--;
       }
       for(int j=1;j<=n;++j)
		C[D[j]]++;
       for(i=1;i<10;++i)
		C[i]=C[i]+C[i-1];
       for(j=n;j>=1;j--)
       {
		B[C[D[j]]]=A[j];
		C[D[j]]--;
       }
       for(i=1;i<=n;i++)
		A[i]=B[i];
       delete B;
       delete D;

}
void radixsort(int A[],int n,int d)
{
	for(int i=1;i<=d;i++)
		countsort(A,n,i);
}
void main()
{
	clrscr();
	int *A;
	int n,temp,d,digits=0;
	printf("\nEnter the size of array: ");
	scanf("%d",&n);
	A=new int[n+1];
	printf("\nEnter the elements of array:\n");
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&A[i]);
		temp=A[i];
		d=0;
		while(temp!=0)
		{
			d++;
			temp=temp/10;
		}
		if(digits<d)
			digits=d;
	}
	radixsort(A,n,digits);
	printf("\nThe sorted array is:");
	for(i=1;i<=n;++i)
		printf("\n%d",A[i]);
	getch();
}
