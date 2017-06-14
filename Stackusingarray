#include<stdio.h>

#define MAX_SIZE 101

int A[MAX_SIZE]; // integer array to store the stack 
int top = -1;  // variable to mark top of stack in array

// Push operation to insert an element on top of stack. 
void Push(int x) 
{
  if(top == MAX_SIZE -1) { // overflow case. 
		printf("Error: stack overflow\n");
		return;
	}
	A[++top] = x;
}

// Pop operation to remove an element from top of stack.
void Pop() 
{
	if(top == -1) { // If stack is empty, pop should throw error. 
		printf("Error: No element to pop\n");
		return;
	}
	top--;
}

// Top operation to return element at top of stack. 
int Top() 
{
	return A[top];
}

// This function will return 1 (true) if stack is empty, 0 (false) otherwise
int IsEmpty()
{
    if(top == -1) return 1;
    return 0;
}

// This function is just to test the implementation of stack. 
// This will print all the elements in the stack at any stage. 
void Print() {
	int i;
	printf("Stack: ");
	for(i = 0;i<=top;i++)
		printf("%d ",A[i]);
	printf("\n");
}

int main() {	
  // Code to test the implementation. 
  // calling Print() after each push or pop to see the state of stack. 
	Push(2);Print();
	Push(5);Print();
	Push(10);Print();
	Pop();Print();
	Push(12);Print();
}
