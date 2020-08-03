
#include<iostream.h>
#include<conio.h>

int time ;

class vertex
 {
  public:
   int parent;
   int info , ft , dt ;
   char color;
 };


class node
 {
  public:
   int info;
   node* next;

   node(int a , node* n = 0)
    {
     info = a ;
     next = n ;
    }
 };

class linked_list
 {
  public:
   node* head ;
   node* tail ;

   linked_list()
    {
     head = tail = 0;
    }

   void add_to_tail ( int a  )
    {

     node* z = new node (a);
     if ( head == 0 )
       head = tail = z ;

     else
      {
       tail->next = z ;
       tail = z ;
      }
    }

 };
  // end of class linked_list

class DFS
 {
  public:
   linked_list llist[10];
   vertex var[20];

   void enter();
   void dfs();
   void dfs_visit ( int );
   void print();
 };

void DFS :: enter()
 {
  int size;
  cout<<"\nEnter the no. of vertices in the graph : " ;
  cin>>size;
  cout<<"\nEnter the value of the vertices : ";

  for ( int k = 1 ; k <= size ; k++ )
   cin>>var[k].info;

  for ( int i = 1 ; i <= size ; i++ )
   {
    cout<<"\n\nFor vertex containing value " << var[i].info <<" :\n";
    cout<<"\nEnter the no. of adjacent vertices : ";
    int adj;
    cin>>adj;

    for ( int j = 1 ; j <= adj ; j++ )
     {
      cout<<"\nEnter the value of the adjacent verteices : ";
      int a;
      cin>>a;
      llist[i].add_to_tail(a);
     }
   }

 }  // end of function enter

void DFS :: dfs_visit ( int u )
 {
  var[u].color = 'g';
  time = time + 1;
  var[u].dt = time ;

  node* t = llist[u].head;

  for ( ; t != 0 ; t = t->next )
   {
    if ( var[ t->info ].color == 'w' )
     {
      var [ t->info ].parent = u ;
      dfs_visit ( t->info );
     }
   }

  var[u].color = 'b';
  time = time + 1 ;
  var[u].ft = time ;
 }
  // end of function dfs_visit

void DFS :: dfs ()
 {
  int u = 1 ;
  while ( var[u].info )
   {
    var[u].color = 'w';
    var[u].parent = 0 ;
    u++;
   }

  time = 0 ;
  u = 1 ;

  while ( var[u].info )
   {
    if ( var[u].color == 'w' )
     dfs_visit ( u ) ;

    u++;
   }
 }
  // end of dfs function

void DFS :: print ()
 {
  int u = 1 ;
  while ( var[u].info )
   {
    cout<<"\n\nVertex info : " << var[u].info ;
    cout<<"\t Colour : " << var[u].color;
    cout<<"\t Parent : " << var[u].parent;
    cout<<"\t Discovery time : " << var[u].dt;
    cout<<"\t Finishing time : " << var[u].ft;
    u++;
   }
 }

void main()
 {
  clrscr();
  DFS d;
  d.enter();
  d.dfs();
  d.print();
  getch();
 }