#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<process.h>

typedef struct linkedList
{
	int val;
	struct linkedList *next;
}simple_list;

simple_list *first = NULL;
simple_list *last = NULL;

void insert(simple_list *data);
int recSearching(simple_list *temp, int value);
//void display();

int main()
{
	int nval, sval;
	simple_list *p;

	printf("Listede kac eleman olacagini giriniz  : ");
	scanf("%d", &nval);



	for (int i = 0; i < nval; i++)
	{
		p = (simple_list*)malloc(sizeof(simple_list)); // girilecek elemanlar için bellekte yer ayırdık.
		printf("%d. elemani giriniz = ", i + 1);
		scanf("%d", &p->val);
		insert(p);
	}

	//display(); // Bağlı listeyi göstermek için kullanılabilir.

	printf("Listede aradiginiz elemani giriniz	:  ");
	scanf("%d", &sval);
	p = first;
	recSearching(p, sval);

	system("pause");
	return 0;
}

void insert(simple_list *data)
{
	if (first != NULL) // ilk eleman dolu ise sona eleman ekliyoruz.
	{
		last->next = data;
		data->next = NULL;
		last = data;
	}
	else				// boş listeye eleman ekliyoruz.
	{
		first = data;
		last = data;
		last->next = NULL;
	}
}

void display()
{
	simple_list *temp = first;
	int a = 0;
	while (temp != NULL)
	{
		printf("%d. eleman = %d\n", a + 1, temp->val);
		temp = temp->next;
		a++;
	}
}


int recSearching(simple_list *temp, int value)
{

	if (temp == NULL)
	{
		printf("Element is not in the list \n");
		return 0;
	}
	else if (temp->val == value)
	{
		printf("Element is found = %d\n", value);
		printf("--------------------");
		printf("Exact divisiors of the elements in the list : \n ");
		temp = first;
		while (temp != NULL)
		{
			printf("%d. element has exact divisiors -->", temp->val);
			for (int i = 1; i <= temp->val; i++)
			{
				if (temp->val % i == 0)
				{
					printf("%d    ", i);
				}
			}
			printf("\n");
			temp = temp->next;
		}

	}
	else
	{
		return recSearching(temp->next, value);
	}
}
