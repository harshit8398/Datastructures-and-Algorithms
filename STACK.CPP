#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct node
{
  int info;
  node *link;
} *top,*top1,*temp;

int count=0;
void push(int data)
{
  if(top==NULL)
  {
    top=new node;
    top->info=data;
    top->link=NULL;
   }
  else
  {
     temp=new node;
     temp->info=data;
     temp->link=top;
     top=temp;
   }
   count++;
   return;
 }
void pop()
{
  if(top==NULL)
  {
    cout<<"Stack Empty\n";
    return;
   }
  top1=top;
  top=top->link;
  cout<<"Information poped "<<top1->info<<endl;
  delete top1;
  count--;
}
 void display()
{
  if(top==NULL)
  {
    cout<<"Stack empty"<<endl;
    return;
   }
  top1=top;
  while(top1!=NULL)
 {
   cout<<top1->info<<" ";
   top1=top1->link;
  }
   return;
 }

 void destroy()
{
  if(top==NULL)
  {
    cout<<"Stack doesn't exist\n";
    return;
   }
  while(top!=NULL)
  {
    top1=top;
    top=top->link;
    delete(top1);
   }
   cout<<"Stack destroyed\n";
 }

 void main()
{
  int choice,data;
  clrscr();
  cout<<"Program to implement a stack\n";
  while(1)
 {
  cout<<"\nEnter the operation to be performed\n";
  cout<<"1.Push\n2.Pop\n3.Display\n4.Destroy\n5.Exit\n";
  cin>>choice;
  if(choice==1)
  {
    cout<<"Enter the element\n";
    cin>>data;
    push(data);
   }
  else if(choice==2)
    pop();
  else if(choice==3)
    display();
  else if(choice==4)
  destroy();
  else if(choice==5)
    break;
  else
    cout<<"Enter correct choice\n";
 }
  getch();
}








