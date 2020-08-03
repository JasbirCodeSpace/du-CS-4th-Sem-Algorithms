# include <iostream.h>
# include <conio.h>

int count = 0;

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
   int a[1000],n,i;
   cout << "\nEnter the no. of element : ";
   cin >> n;
   cout << "\nEnter the value :\n";
   for (i=1;i<=n;++i)
     cin >> a[i];
   int k = max(a,n);
   countsort(a,k,n);
   cout <<"The array after sorting : \n";
   for(i=1;i<=n;++i)
     cout << a[i]<< " ";

   getch();
  }
