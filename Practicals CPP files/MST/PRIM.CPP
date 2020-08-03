#include<iostream.h>
#include<stdio.h>
#include<conio.h>

int weight[20][20],visited[20],d[20],p[20];
int v,e;
void creategraph()
{
int i,j,a,b,w;
cout<<"\nEnter number of vertices";
cin>>v;
cout<<"\nEnter number of edges";
cin>>e;
for(i=1;i<=v;i++)
  for(j=1;j<=v;j++)
    weight[i][j]=0;

for(i=1;i<=v;i++)
{
  p[i]=visited[i]=0;
  d[i]=32767;
}

for(i=1;i<=e;i++)
{
  cout<<"\nEnter edge a,b and weight w:";
  cin>>a>>b>>w;
  weight[a][b]=weight[b][a]=w;
}
}

void prim()
{
int current,totalvisited,mincost,i;
current=1;d[current]=0;
totalvisited=1;
visited[current]=1;
while(totalvisited!=v)
{
  for(i=1;i<=v;i++)
  {
    if(weight[current][i]!=0)
      if(visited[i]==0)
    if(d[i]>weight[current][i])
    {
      d[i]=weight[current][i];
      p[i]=current;
    }
  }
  mincost=32767;
  for(i=1;i<=v;i++)
  {
    if(visited[i]==0)
      if(d[i]<mincost)
      {
    mincost=d[i];
    current=i;
      }
  }
  visited[current]=1;
  totalvisited++;
}

for(i=2;i<=v;i++)
  cout<<"\nVertex "<<i<<" is connected to"<<p[i];
}

main()
 {
 clrscr();
 creategraph();
 prim();
 getch();
}