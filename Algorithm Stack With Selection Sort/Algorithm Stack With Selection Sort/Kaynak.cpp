#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>

typedef struct list {
	int data;
	struct list *next;
}STACK;

// GLOBAL VARIABLES
STACK *sp = NULL;  // stack pointer , shows the place for insertion and deletion
int counter = 0;	// Counter for inserted stack


void push(int data) 
{			// Insertion function

	STACK *temp = (STACK *)malloc(sizeof(STACK));	// Creating a new node and allocating memory to push stack
	if (temp == NULL) {
		printf("\nError, Could not allocate memory...\n");
	}
	else {
		temp->data = data;
		temp->next = sp;
		sp = temp;			// Stack pointer always shows the last inserted node
		counter++;
		printf("\nData inserted to the stack.\n\n");
	}

}
int size() 
{		//Shows the number of elements stored
	return counter;
}

void display()
{
	STACK *temp = sp;
	
	if (temp == NULL)
	{
		printf("Stack is empty \n");
	}
	//printf("Elements on the list in Stack  :\n");

	while (temp)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


void iterationSort()
{
	STACK *p = sp;
	while (p)
	{
		STACK *min = p;
		STACK *temp = p->next;
		while (temp)
		{
			if (min->data > temp->data)
			{
				min = temp;
			}
			temp = temp->next;
		}
		int x = p->data;
		p->data = min->data;
		min->data = x;
		p = p->next;
	}
	printf("Elements are ordered by Nonrecursive Function \n");
}

int recursiveSort(STACK *p)
{
	STACK *temp = p;
	STACK *min = temp;

	if (temp == NULL)
		return 0;
	while (temp)
	{
		if (min->data > temp->data)
		{
			min = temp;
		}
		temp = temp->next;
	}
	int a = p->data;
	p->data = min->data;
	min->data = a;
	return recursiveSort(p->next);
	
}



int main() {

	int choice;
	int value;

	while (1) {
		printf("1-Push\n2-Size\n3-Nonrecursive Selection Sort\n4-Recursive Selection Sort\n5-Display\n6-exit\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("Enter the value for insertion : ");
			scanf("%d", &value);
			push(value);
			break;
		case 2:		
			printf("\nThe number of elements stored -> %d \n\n\n", size());
			break;

		case 3:
			iterationSort();
			break;

		case 4:
			recursiveSort(sp);
			break;

		case 5:
			display();
			break;
		case 6:
			exit(0);
		}
	}
	return 0;
}