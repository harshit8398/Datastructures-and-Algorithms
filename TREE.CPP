#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<queue.h>

struct node
{
  int info;
  node *left;
  node *right;
 }*root;

int max(int value1,int value2)
{
  return((value1>value2)?value1:value2);
 }

void insert(node *tree,node *newnode)
{
  if(root==NULL)
  {
    root=new node;
    root->info=newnode->info;
    root->left=NULL;
    root->right=NULL;
    return;
    }
  if(tree->info==newnode->info)
  {
    cout<<"Element already in tree\n";
    return;
   }
  if((tree->info)>(newnode->info))
  {
    if(tree->left!=NULL)
    {
      insert(tree->left,newnode);
     }
     else
     {
      tree->left=newnode;
      (tree->left)->left=NULL;
      (tree->left)->right=NULL;
      return;
      }
    }
    else
    {
     if(tree->right!=NULL)
     {
       insert(tree->right,newnode);
      }
     else
     {
       tree->right=newnode;
       (tree->right)->left=NULL;
       (tree->right)->right=NULL;
	return;
      }
     }
  }
  void display(node *ptr,int level)
  {
     int i;
     if(root==NULL)
    {
      cout<<"Tree Empty\n ";
      return;
     }
    if(ptr!=NULL)
    {
      display(ptr->right,level+1);
      cout<<endl;
      if(ptr==root)
      {
	cout<<" ";
	}
      else
      {
       for(i=0;i<level;i++)
	   cout<<"  ";
	}
	cout<<ptr->info;
	display(ptr->left,level+1);
     }
 }

  int findheight(node *root)
  {
    if(root==NULL)
    {
      return -1;
     }
    return max(findheight(root->left),findheight(root->right))+1;
   }
  int findmin(node *root)
  {
    if(root==NULL)
    {
      cout<<"Tree Empty\n";
      return -1;
     }
    else if(root->left==NULL)
    {
       return root->info;
     }
      return findmin(root->left);
   }

   int findmax(node *root)
   {
    if(root==NULL)
    {
      return -1;
     }
    else if(root->right==NULL)
    {
      return root->info;
     }
      return findmax(root->right);
    }

 void levelorder(node *root)
 {
   if(root==NULL)
   return;
   queue<node*>Q;
   Q.push(root);
   while(!Q.empty)
   {
    node *current=Q.front();
    Q.pop();
    cout<<current->info<<"  ";
    if(current->left!=NULL)
    Q.push(current->left);
    if(current->right!=NULL)
    Q.push(current->right);
    }
  }

 void preorder(node *temp)
{
  if(root==NULL)
  {
   cout<<"Tree Empty\n";
   return;
   }
  if(temp!=NULL)
  {
   cout<<temp->info<<"  ";
   preorder(temp->left);
   preorder(temp->right);
   }
 }
 void inorder(node *temp)
{
  if(root==NULL)
  {
   cout<<"Tree Empty\n";
   return;
   }
  if(temp!=NULL)
  {
    inorder(temp->left);
    cout<<temp->info<<"  ";
    inorder(temp->right);
   }
 }
 void postorder(node *temp)
{
  if(root==NULL)
 {
   cout<<"Tree Empty\n";
   return;
  }
  if(temp!=NULL)
 {
   postorder(temp->left);
   postorder(temp->right);
   cout<<temp->info<<"  ";
  }
 }
 void main()
{
  int choice,max,min,height;
  root=NULL;
  clrscr();
  node *temp;
  cout<<"BINARY TREE\n";
  while(1)
  {
    cout<<"\nEnter choice\n1.Insert\n3.Display\n4.Findmax\n5.Findmin\n6.Findheight\n7.Traversal\n8.Exit\n";
    cin>>choice;
    if(choice==1)
    {
      cout<<"Enter the element to be inserted\n";
      temp=new node;
      cin>>temp->info;
      insert(root,temp);
     }
    else if(choice==3)
    display(root,1);
    else if(choice==4)
    {
      max=findmax(root);
      if(max==-1)
	cout<<"Tree Empty\n";
      else
      cout<<"Maximum element  "<<max<<endl;
     }
    else if(choice==5)
    {
      min=findmin(root);
      if(min==-1)
	cout<<"Tree Empty\n";
      else
      cout<<"Minimum element  "<<min<<endl;
      }
    else if(choice==6)
    {
      height=findheight(root);
      cout<<"Height of tree  "<<height<<endl;
     }
    else if(choice==7)
    {
      int ch;
      cout<<"1.Level order\n2.Preorder\n3.Inorder\n4.Postorder";
      cout<<"Enter choice\n";
      cin>>ch;
      if(ch==1)
      levelorder(root);
      else if(ch==2)
      preorder(root);
      else if(ch==3)
      inorder(root);
      else if(ch==4)
      postorder(root);
      else cout<<"Enter correct choice\n";
     }
    else if(choice==8)
    break;
    else
    cout<<"Enter correct choice\n";
    }
   getch();
 }



