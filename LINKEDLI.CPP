#include<iostream>
using namespace std;

int count=0;
struct node
{
 int info;
 node *link;
 }*start;
void insertatbeg(int data)
{
  node *temp;
  temp=new node;
  temp->info=data;
  if(start==NULL)
  {
    temp->link=NULL;
    start=temp;
    count++;
    return;
   }
  temp->link=start;
  start=temp;
  count++;
  return;
 }
 void insertatpos(int data,int pos)
 {
   if(pos<=count+1)
  {
   int i;
   node *temp1,*temp;
   temp= new node;
   temp->info=data;
   temp1=start;
      for(i=1;i<pos-1;i++)
   {
      temp1=temp1->link;
    }
    temp->link=temp1->link;
    temp1->link=temp;
    count++;
    return;
   }
    else
     cout<<"Insertion not possible\nPosition out of bound\n";
    return;
  }
 void del()
 {
   int x;
   node *temp,*temp1;
   if(start==NULL)
   {
     cout<<"UNDERFLOW\n";
     return;
    }
   temp1=start;
   if(temp1->link==NULL)
   {
     cout<<temp1->info<<"Deleted\n";
     delete temp1;
     start=NULL;
     count--;
     return;
    }
   while(temp1->link!=NULL)
   {
     temp=temp1;
     temp1=temp1->link;
    }
   x=temp1->info;
   cout<<x<<" deleted\n";
   delete temp1;
   temp->link=NULL;
   count--;
   return;
 }
 void delitem(int data)
 {
  node *temp,*temp1;
  if(start->info==data)
  {
    temp1=start;
    start=start->link;
    delete temp1;
    count--;
    return;
   }
  temp1=start;
  while(temp1->link!=NULL)
  {
    if(temp1->info==data)
   {
     cout<<temp1->info<<"deleted\n";
     temp->link=temp1->link;
     delete temp1;
     count--;
     return;
    }
     temp=temp1;
     temp1=temp1->link;
   }
  }
 void display()
 {
   node *temp;
   temp=start;
   while(temp->link!=NULL)
   {
     cout<<temp->info<< "->";
     temp=temp->link;
    }
     cout<<temp->info<<"\n";
    return;
 }

 void main()
 {
   int choice,data,pos;
   start=NULL;
   clrscr();
   cout<<"Linear linked list\n";
   while(1)
   {
     cout<<"1.Insert at beginning\n2.Insert at desired position\n3.Delete at end\n4.Delete the given item\n5.Display\n6.Exit\n\nEnter choice";
     cin>>choice;
     if(choice==1)
     {
       cout<<"Enter the element\n";
       cin>>data;
       insertatbeg(data);
      }
     else if(choice==2)
     {
       cout<<"Enter the data\n";
       cin>>data;
       cout<<"Enter the position\n";
       cin>>pos;
       if(pos==1)
       insertatbeg(data);
       else
       insertatpos(data,pos);
      }
      else if(choice==3)
      {
	del();
       }
      else if(choice==4)
      {
	cout<<"Enter the item you want to delete\n";
	cin>>data;
	delitem(data);
      }
      else if(choice==5)
     { endl;
      display();
      }
      else if(choice==6)
       break;
      else
       cout<<"Enter correct choice\n";
  }
   getch();
 }











