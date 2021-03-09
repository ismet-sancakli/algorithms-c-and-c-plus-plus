#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
	int data;
	Queue *next;
}Q;

Q *front = NULL;
Q *last = NULL;
int count = 0;

void enqueue(int item)
{
	Q *temp;
	temp = (Q*)malloc(sizeof(Q));
	if (temp == NULL)
	{
		printf("Queue is empty \n");
	}
	temp->data = item; 
	temp->next = NULL; 

	if (front == NULL) // Queue is the empty. Insert at begining.
	{
		front = temp;
		last = temp;
	}
	else               // Insert at the end.
	{
		last->next = temp;
		last = temp;
	}
	count++;
	printf("Data succesfully added \n");	
}
int dequeue()
{
	Q *temp;
	int value;

	if (front == NULL)
	{
		printf("Queue is empty \n");
	}
	temp = front;
	value = front->data;
	front = front->next;
	printf("This data is dequeued : %d ", value);
	count--;
	free(temp); 
	return value;
}
int size()
{
	return count;
}
void display()
{
	Q *temp = front;
	if (front == NULL)	
		printf("Queue is empty \n");	
	else
	{
		printf("Element(s) \n");
		while (temp)
		{
			printf("%d  ", temp->data);
			temp = temp->next;
		}
	}
}
void bubbleSort()
{
	Q *temp = front;
	Q *p = NULL;
	int x, i, j, size = count;
	for ( i = 1; i < size; i++)
	{
		for ( j = 1; j <size; j++)
		{
			p = temp;
			for ( j = 1; j < size; j++)
			{
				if (temp->data > temp->next->data)
				{
					x = temp->next->data;
					temp->next->data = temp->data;
					temp->data = x;
				}
			}			
			temp = temp->next;
		}
		size--;
	}
}
int recursiveBubbleSort(int size)
{
	Q *temp = front;
	int x, j, s = count;	
	if (count == NULL)
	{ return 0;	}
	for ( j = 1; j < s; j++)
	{
		if (temp->data > temp->next->data)
		{
			x = temp->next->data;
			temp->next->data = temp->data;
			temp->data = x;
		}
		temp = temp->next;
	}
	return recursiveBubbleSort(count - 1);
}

int main()
{
	int choice, value;
	while (1)
	{
		printf("Menu \n");
		printf("Choose your selection :\n1-Enqueue\n2-Dequeue\n3-BubbleSort\n4-Recursive Bubble Sort\n5-Size\n6-Display\n7-Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the number please  :  ");
			scanf("%d", &value);
			enqueue(value);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			bubbleSort();			
			break;
		case 4:
			recursiveBubbleSort(count);			
			break;
		case 5:
			size();
			break;
		case 6:
			display();
			break;
		case 7:
			exit(0);

		default: printf("Invalid choice !!!");
			break;
		}


	}


	system("pasue");
	return 0;
}