#include<iostream>
using namespace std;

struct node
{
   int info;
   node *f;
   node *b;
} *start;

//Insertion at the beginning
void insertatbeg(int data)
{
  node *temp= new node;
  temp->info=data;
  if(start==NULL)
  {
    temp->f=NULL;
    temp->b=NULL;
    start=temp;
    return;
   }
  temp->f=start;
  temp->b=NULL;
  start->b=temp;
  start=temp;
}

 void insertatend(int data)
 {
   node *temp1=new node;
   temp1->info=data;
   node *temp=start;
   while(temp->link!=NULL)
   {
     temp=temp->f;
   }
   temp1->f=NULL;
   temp1->b=temp;
   temp->f=temp1;
 }

   void display()
{
  if(start==NULL)
  {
    cout<<"Underflow\n";
    return;
   }
  node *temp;
  temp=start;
  while(temp!=NULL)
  {
    cout<<temp->info<<"  ";
    temp=temp->f;
   }
}

void reverse()
{
    node *temp=start;
    while(temp->f!=NULL)
     temp=temp->f;
    cout<<"Reverse list:\n"
    while(temp!=NULL)
    {
       cout<<temp->info<<" ";
       temp=temp->b;
    }
}
 void main()
{
  int i,data,c,pos;
  cout<<"Doubly Linked List\n";
  while(1)
  {
    cout<<"1.Insert at beginning\n2.Insert at end\n3.Display\n4.Reverse Display\n5.Exit";
    cin>>c;
    if(c==1)
   {
     cout<<"Enter element to be inserted\n";
     cin>>data;
     insertatbeg(data);
   }

    else if(c==2)
   {
     cout<<"Enter element to be inserted\n";
     cin>>data;
     insertatend(data);
    }
    else if(c==3)
     display();
    else if(c==4)
     reverse();
    else if(c==5)
     break;
    else
     cout<<"Wrong Choice\n";
  }
   return 0;
  }










}









