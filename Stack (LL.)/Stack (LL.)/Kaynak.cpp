#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>


struct Stack
{
	int data;
	Stack *next;
};

Stack *sp = NULL;
int count = 0;


int push(int item);
int pop();
void reset();
Stack *top();
int size();
Stack *isEmpty();

int main()
{
	int choice;
	int value;
	int i;

	while (1)
	{
		printf("Menu\n");
		printf("1->push\n 2 -> pop\n 3->top\n 4->reset\n 5->size\n 6->isEmty\n 7->Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("enter the value :\n");
			scanf("%d", &value);
			push(value);
			break;

		case 2:
			i = pop();
			if (i != -1)
			{
				printf("Data is = %d\n",i);
			}
			break;

		case 3:
			printf("The last element in the Stack = %d\n", top());
			
			break;

		case 4:
			reset();
			break;

		case 5:
			printf("The total number = %d\n", size());
			break;

		case 6:
			isEmpty();
			printf("Stack te gosterilecek deger yok \n");
			break;
		case 7:
			exit(0);
		default :
			printf("Please enter the valid number\n");
		}
	}
	system("pause");
	return 0;
}

int push(int item)
{
	Stack *p;
	p = (Stack*)malloc(sizeof(Stack));

	if (p == NULL)
	{
		printf("Memory is full\n");
		return -1;			
	}
	else
	{
		p->data = item;
		p->next = sp;
		sp = p;
	}
	count++;
	return 0;
}

int pop()
{
	Stack *p;
	int temp;

	if (sp == NULL)
	{
		printf("Stack is empty \n");
		return -1;
	}
	else
	{
		p = sp;
		temp = p->data;
		sp = sp->next;
		free(p);
		
	}
	count--;
	return temp;
}
void reset()
{
	Stack *temp;
	while (sp != NULL)
	{
		temp = sp;
		sp = sp->next;
		free(temp);
	}
	printf("Stack is empty now\n");
	count = 0;
}

Stack *top()
{
	return sp;
}

int size()
{
	return count;
}

Stack *isEmpty()
{
	return sp;
}