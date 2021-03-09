#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>


#define Max_Size 500 //  MAX size of stack


// GLOBAL VARIABLES
int Stck[Max_Size];
int sp = 0; // stack index for insertion and deletion.

int push(int item)   // Insertion function.
{
	if (sp >= Max_Size)
	{
		printf("Stack is full \n");
		return -1;
	}
	else
	{
		Stck[sp] = item;
		sp++;


		return 0;
	}
}

int pop() // Deletion function. Remove an element from the stack.
{
	if (sp <= 0)
	{
		printf("Stack is empty you can not add to element\n");
		return -1;
	}
	else
	{
		sp--; // We reduced stack pointer. Because it must show previous element.
		return Stck[sp];
	}
}

void reset() // Reset function.
{
	sp = 0; // The satack pointer must be equal to 0 Stack is empty.
	printf("stack is empty now \n");
}

int top() // Shows the last inserted element without removing it.
{
	return Stck[sp - 1];
}

int size() // Shows the number of element stored.
{
	return sp;
}

int isEmpty() // Returns a Boolean value indicating whether no elements are stored
{
	if (sp == 0) // Returns 1 if no elements are stored.
		return 1;
	else
		return 0; // otherwise (eg. Bolean value).
}

int main()
{
	int choice;
	int val;
	int i; // To keep poped data.

	while (1)
	{
		printf("MENU\n");
		printf("1- Push( Insertion element )\n 2-Pop ( Deletion element )\n 3-Reset\n 4-Display the last element\n 5-Total number of elements stored\n 6-exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter the value for insertion :\n");
			scanf("%d", &val);
			push(val);
			break;

		case 2:
			i = pop();

			if (i != -1)
				printf("Data is : %d\n", i);
			break;
		case 3:
			reset();
			break;

		case 4:
			printf("The last element on the stack  : %d\n", top());
			break;

		case 5:
			printf("The total number of elements stored  : %d\n", size());
			break;

		case 6:
			exit(0);
			break;

		default : 
			printf("Please enter the valid number  1 - 6\n");
			break;

		}
	}
}


