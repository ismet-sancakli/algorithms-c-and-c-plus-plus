#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct Queue
{
	int data;
	Queue *next;
}Q;

Q *front = NULL;
Q  * last = NULL;
int counter = 0;

void Enqueue(int item)
{
	Q *temp = (Q*)malloc(sizeof(Q));

	if (temp == NULL)	
		printf("Couldn't allocate memory \n");
	
	temp->data = item;
	temp->next = NULL;

	if (front == NULL)
	{
		front = temp;
		last = temp;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
	counter++;
}

void Dequeue()
{
	Q *temp;
	int data;
	if (front == NULL)
	{
		printf("Queue is empty \n");
	}
	temp = front;
	data = front->data;
	front = front->next;
	printf("Number is dequeued : %d ", data);

	if (front == NULL)
	{
		last = NULL;
	}
	free(temp);
	counter--;
}
/*
int Size()
{
	if (counter == 0)
	{
		printf("Queue is empty \n");
	}
	return counter;
}*/

void Display()
{
	Q *temp = front;
	if (temp == NULL)
	{
		printf("Queue is empty \n");
	}
	else
	{
		printf("Element(s) :  ");
		while (temp )
		{
			printf("%d  ", temp->data);
			temp = temp->next;
		}
	}
}
void BubbleSort()
{
	Q *temp = front;
	Q *p = NULL;
	int c, i, j;
	int size = counter;
	if (temp == NULL)
	{
		printf("Queue is empty \n");
	}
	for ( i = 1; i < counter; i++)
	{
		p = temp;
		for ( j = 1; j < size; j++)
		{
			if (p->data > p->next->data)
			{
				c = p->next->data;
				p->next->data = p->data;
				p->data = c;
			}
			p = p->next;
		}
		size--;
	}
}

int RecursiveBubbleSort(int size)
{
	Q *temp = front;
	int x, i, s = size;
	if (size == NULL)
	{
		return 0;
	}

	for ( i = 1; i < size; i++)
	{
		if (temp->data > temp->next->data) {
			x = temp->data;
			temp->data = temp->next->data;
			temp->next->data = x;
		}
		temp = temp->next;
	}
	return RecursiveBubbleSort(size - 1);
}

int main()
{
	int item, choice;
	while (1)
	{
		printf("\nMenu : \n");
		printf("1-Enqueue\n2-Dequeue\n3-Display\n4-Size\n5-Non-recursive Bubble Sort\n6-Recursive Bubble Sort\n7-Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the number : ");
			scanf("%d", &item);
			Enqueue(item);
			break;
		case 2:
			Dequeue();
			break;
		case 3:
			Display();
			break;
		case 4:
			printf("Numner of total elements = %d",counter);
			break;
		case 5:
			BubbleSort();
			break;
		case 6:
			RecursiveBubbleSort(counter);
			break;
		case 7:
			exit(0);


		default:printf("Invalid number !!!");
			break;
		}
	}
	system("pause");
	return 0;
}


