

//Write a program to determine the LCS of two given sequences

#include<iostream.h>
#include<conio.h>
class lcs
{
	char b[10][10];
	int c[10][10];
	char x[10];
	char y[10];
	public:
	lcs();
	void input(int ,int );
	void printlcs(int ,int );
	void calculate(int ,int );
};
lcs::lcs()
{
	x[10]=0;
	y[10]=0;
	b[10][10]=0;
	c[10][10]=0;
}
void lcs::input(int m,int n)
{
	int i,j;
	cout<<"\nEnter 1st subsequence::";
	for(i=1;i<=m;i++)
	cin>>x[i];
	cout<<"\nEnter 2nd subsequence::";
	for(j=1;j<=n;j++)
	cin>>y[j];
}
void lcs::printlcs(int i,int j)
{
	if(i==0||j==0)
	return;
	if(b[i][j]=='/')
	{
		printlcs(i-1,j-1);
		cout<<x[i];
	}
	else if(b[i][j]=='^')
		printlcs(i-1,j);
	else
	printlcs(i,j-1);
}

void lcs::calculate(int m,int n)
{
	int i,j;
	for(i=1;i<=m;i++)
	c[i][0]=0;
	for(j=0;j<=n;j++)
	c[0][j]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==y[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]='/';
			}
			else if(c[i-1][j]>=c[i][j-1])
			{                               \
				c[i][j]=c[i-1][j];
				b[i][j]='^';
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]='-';
			}
		}
	}
	printlcs(m,n);
}

void main()
{
	clrscr();
	lcs l;
	int i,j,m,n;
	cout<<"\nEnter the size of two subsequences(<10)\n";
	cin>>m>>n;
	l.input(m,n);
	cout<<"\nLongest common subsequence::";
	l.calculate(m,n);
	getch();
}