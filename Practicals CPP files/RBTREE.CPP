        //PROGRAM TO PERFORM OPERATIONS ON RED-BLACK TREE.

#include<iostream.h>
#include<conio.h>

class node
  {
      public:
      node *l , *r, *p;
      int v,c;
      node()
    {  c=0; }
};

class rbtree
  {
     public:
      node *root, *nilt;

      rbtree()
       {
      nilt=new node();
     nilt->c=1;
     root=nilt;
       }

      void lrotate(node *x)
       {
     node *y=x->r;
     x->r=y->l;
     y->l->p=x;
     y->p=x->p;
     if(x->p==nilt)
       root=y;

     else
       {
	 if(x==x->p->l)
	   x->p->l=y;

	 else x->p->r=y;
       }

     y->l=x;
     x->p=y;

       }

      void rrotate(node *x)
       {
      node *y=x->l;
     x->l=y->r;
     y->r->p=x;
     y->p=x->p;
     if(x->p==nilt)
       root=y;

     else
       {
	 if(x==x->p->r)
	   x->p->r=y;

	 else x->p->l=y;
       }

     y->r=x;
     x->p=y;
       }

      void insertfixup(node *z)
       {
     node *y=NULL;
     cout<<z->v<<" is z\n";
     while(z->p->c==0)
       {
	  if(z->p==z->p->p->l)
	 {
	   cout<<"parent left\n";
	   y=z->p->p->r;

	   if(y->c==0)
	     {
	       z->p->c=1;
	       y->c=1;
	       z->p->p->c=0;
	     }

	   else
	     {
	       if(z==z->p->r)
	     {
	       z=z->p;
	       lrotate(z);
	     }

	       z->p->c=1;
	       z->p->p->c=0;
	       rrotate(z->p->p);
	     }


	 }

	  else
	 {
	   cout<<"parent right\n";
	   y=z->p->p->l;

	   if(y->c==0)
	     {
	       cout<<"uncle red\n";
	       z->p->c=1;
	       y->c=1;
	       z->p->p->c=0;
	     }

	   else
	     {
	       if(z==z->p->l)
	     {
	       cout<<"parent left\n";
	       z=z->p;
	       rrotate(z);
	     }

	       z->p->c=1;
	       z->p->p->c=0;
	       cout<<z->c<<" is color of "<<z->v<<"\n";
	       lrotate(z->p->p);
	     }


	 }


       }

     root->c=1;

       }

      void insert(node *t)
       {
      int x;
      cout<<"Enter the value\n";
      cin>>x;
     node *y=nilt;
     node *n=new node();
     n->r=nilt;
     n->l=nilt;
     n->v=x;


     while(t!=nilt)
       {
	 if(x>t->v)
	   {
	 y=t;
	 t=t->r;
	   }

	 else if(x<t->v)
	 {

	  y=t;
	  t=t->l;
	 }

	else
	 {
	  cout<<"The node is already present\n";
	  return;
	 }
       }

     if(root==nilt)
     {
      root=n;
      root->p=nilt;
      //cout<<"Hrllo\n";
     }

     else
     {

     if(x<(y->v))
       {
	y->l=n;
       }

     else
       {
	 y->r=n;
       }

     n->p=y;
     }

     insertfixup(n);
       }

      void delfixup(node *x)
       {
     node *w=NULL;

     while(x!=root && x->c==1)
       {
	 if(x==x->p->l)
	   {
	 w=x->p->r;

	 if(w->c==0)
	   {
	     w->c=1;
	     x->p->c=0;
	     lrotate(x->p);
	     w=x->p->r;

	   }

	 if(w->l->c==1 && w->r->c==1)
	   {
	     w->c=0;
	     x=x->p;

	   }

	 else
	   {
	     if(w->r->c==1)
	       {
	     w->l->c=1;
	     w->c=0;
	     rrotate(w);
	     w=x->p->r;

	       }

	     w->c=x->p->c;
	     x->p->c=1;
	     w->r->c=1;
	     lrotate(x->p);
	     x=root;

	   }

	   }


	 else
	   {
	 w=x->p->l;

	 if(w->c==0)
	   {
	     w->c=1;
	     x->p->c=0;
	     rrotate(x->p);
	     w=x->p->l;

	   }

	 if(w->r->c==1 && w->l->c==1)
	   {
	     w->c=0;
	     x=x->p;

	   }

	 else
	   {
	     if(w->l->c==1)
	       {
	     w->r->c=1;
	     w->c=0;
	     lrotate(w);
	     w=x->p->l;

	       }

	     w->c=x->p->c;
	     x->p->c=1;
	     w->l->c=1;
	     rrotate(x->p);
	     x=root;

	   }

	   }


       }

     x->c=1;

       }

      void del( node *t)
       {
     int x;
     cout<<"Enter the element which you want to delete\n";
     cin>>x;


      if(t==nilt)
	{
	  cout<<"The tree is empty\n";
	  return;
	}

     node *y=NULL;
     node *z=NULL;

     while(t!=nilt)
      {
	if(x>t->v)
	 t=t->r;

	else if(x<t->v)
	 t=t->l;

	else
	 break;
      }

     if(t==nilt)
       {
	 cout<<"The node is not present\n";
	 return;
       }
     cout<<t->v<<"\n";

     if((t->l)==nilt || (t->r)==nilt)
       y=t;

     else
       {
	 y=t->r;
	 while (y->l!=nilt)
	  y=y->l;

       }


     if(y->l!=nilt)
       z=y->l;

     else
       z=y->r;
     z->p=y->p;

     if(y->p==nilt)
       root=z;

     else if(y==y->p->l)
       y->p->l=z;

     else
       y->p->r=z;

     cout<<t->v<<" is deleted successfully\n";

     if(y!=t)
       t->v=y->v;



     if(y->c==1)
	delfixup(z);

       }

      void search(node *t)
       {
     int x;
     cout<<"Enter the element to be searched\n";
     cin>>x;

     if(t==nilt)
      {
	cout<<"The tree is empty\n";
	return;
      }

     while(t!=nilt)
      {
	if(x>t->v)
	 t=t->r;

	else if(x<t->v)
	 t=t->l;

	else
	 break;
      }

     if(t==nilt)
       {
	 cout<<"The node is not present\n";
       }

     else {
	    cout<<"The element "<<t->v<<"is present with color ";
	    if(t->c==0)
	 cout<<"red ";

	   else
	 cout<<"black ";

	    cout<<"\n";
	    }
       }
      void show(node *t)
       {
      if(t==nilt)
      return;

      else

	{
	   show(t->l);
	   cout<<t->v<<" ";
	   if(t->c==0)
	 cout<<"red ";

	   else
	 cout<<"black ";

	   if(t==root)
	 cout<<"is root\n";

	   else if(t==t->p->l)
	 cout<<"is left child of "<<t->p->v<<"\n";

	   else
	  cout<<"is right child of "<<t->p->v<<"\n";


	   show(t->r);
	}
	//}
       }

  };


  int main()
   {
   clrscr();
    int i,n;
    rbtree s;
    do
      {
	 cout<<"MENU\n";
	 cout<<"1. Insert item\n";
	 cout<<"2. Delete item\n";
	 cout<<"3. Search item\n";
	 cout<<"4. Display the array\n";
	 cout<<"5. Exit\n";
	 cout<<"Enter your choice\n";
	 cin>>i;

	 switch(i)
	{
	   case 1 :
		s.insert(s.root);
		break;

	   case 2 : s.del(s.root);
		 break;

	   case 3 : s.search(s.root);
		 break;

	   case 4 :
		  if(s.root==NULL)
		{
		  cout<<"The tree is empty\n";
		}
		 else
		   s.show(s.root);
		break;


	   default: cout<<"EXITING\n";
		break;
	}

      }while(i>0 && i<5);

       return 0;
    }
