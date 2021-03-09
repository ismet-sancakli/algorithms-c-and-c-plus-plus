#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<process.h>


struct list
{
	int info;
	char msg[25];
	list *next;
};

list *first = NULL;
list *last = NULL;

void insert(list *data)
{
	if (first != NULL) // LıSTENıN SONUNA ELEMAN EKLEDıK !!
	{
		last->next = data;
		data->next = NULL;
		last = data;
	}
	else   // BOs LıSTEYE ELEMAN EKLEDıK !!
	{
		first = data;
		last = data;
		last->next = NULL;

	}	
}

void display()
{
	list *p = first;

	if (p == NULL)
	{
		printf("list is empty \n");
		
	}
	while (p != NULL)
	{
		printf("%d  %s", p->info, p->msg);
		p = p->next;
		printf("\n");
	}
	
}

list *search(int key)
{
	list *p;
	p = first;
	while (p)
	{
		if (key == p->info)
			return p;
		p = p->next;
	}
	return NULL;
}

list *delet(int key)
{
	list *temp = first , *previous = NULL;
	while (temp)
	{
		if (temp->info == key)
		{
			break;
		}
		previous = temp;
		temp = temp->next;
	}
	if (temp != NULL)
	{
		if (previous == NULL)
		{
			if (first == last)  // TEK ELEMANI OLAN DıZıNıN TEK ELEMANINI SıLER !!
			{
				first = NULL;
				last = NULL;				
			}
			else
			{
				first = first->next;  // ıLK ELEMANI SıLER !!
			}
		}
		else
		{
			previous->next = temp->next;
			if (temp == last)
			{
				last = previous;
			}
		}
		free(temp);
		return temp;
	}
	else
	{
		return NULL;
	}
}

int main()
{
	list *p,*b;
	
	int choice, n;

	while (1)
	{
		printf("--MENU--\n\n");
		printf("1_insert -> 2_display -> 3_search -> 4_delete -> 5_exit\n");
			scanf("%d", &choice);

			switch (choice)
			{
			case 1:
				p = (list*)malloc(sizeof(list));
				printf("Enter the key please :\n");
				scanf("%d", &p->info);

				printf("Enter the message :");
				scanf("%s", p->msg);
				insert(p);
				break;

			case 2:
				display();
				break;

			case 3:
				printf("Enter the information you want to search :\n");
				scanf("%d", &n);
				b = search(n);
				if (b != NULL)
				{
					printf("Element is found = %d\n", b);
				}
				else
				{
					printf("Element is not here\n");
				}
				break;
				
			case 4:
				printf("silmek istediginiz bilgiyi giriniz : \n");
				scanf("%d", &n);
				b = delet(n);
				if (b != NULL)
				{
					printf("Silme islemi basariyla gerceklesti \n");
				}
				else
				{
					printf("ERROR! eleman silinemedi \n");
				}
				break;

			case 5:
				exit(0); break;
			}				
	}

	system("pause");
	return 0;
}

            
/*                                     
                                                    // _______________________DOUBLY---LINKED---LIST________________________ 
struct Dlist
{                                                               // MAIN DOSYASI EKSıK ORAYA TEKRAR BAKK !!
	int info;
	char msg[100];
	Dlist *next;
	Dlist *previous;
	char *name;
};
Dlist *first = NULL;
Dlist *last = NULL;

int insert(Dlist *p)
{
	if (first != NULL) // SONA ELEMAN EKLEME 
	{
		last->next = p;
		p->previous = last;
		p->next = NULL;
		last = p;
	}
	else // BOÞ LÝSTEYE ELELMAN EKLEME
	{
		first = p;
		last = p;
		p->next = NULL;
	}
	return 0;
}

int display()
{
	Dlist *p;
	p = first;

	if (p == NULL)
	{
		printf("List is empty \n");
		return -1;
	}
	while (p)
	{
		printf("%d  %s", p->info, p->msg);
		p = p->next;
	}
	return 0;
}

Dlist *search(int key)
{
	Dlist *p;
	p = first;
	while (p)
	{
		if (key == p->info)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}


Dlist *deleting(int key)
{
	Dlist *p;
	p = search(key);	

	if (p == NULL)
	{
		printf("silinecek eleman bukunamadi\n");
		return NULL;
	}
	if (p == first)
	{
		if (first == last)
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			first = p->next;
			first->previous = NULL;
		}
	}
	else
	{
		if (p == last)
		{
			last = p->previous;
			last->next = NULL;
		}
		else
		{
			p->previous->next = p->next;
			p->next->previous = p->previous;
		}
	}
	free(p);
	return (p);
}
*/

/*
struct student
{
	int id;
	int grade;
	struct student *next;
};

struct student *head = NULL;
struct student *current = NULL;

void printList()
{
	struct student *tmp = head;
	while (tmp != NULL)
	{
		printf("%d: %d\n", tmp->id, tmp->grade);
		tmp = tmp->next;
	}
}

void insertFirst(int id, int grade)
{

	struct student *tmp = (struct student*) malloc(sizeof(struct student));

	tmp->id = id;
	tmp->grade = grade;
	tmp->next = head;
	head = tmp;
}

void insertLast(int id, int grade)
{
	struct student *tmp = (struct student*) malloc(sizeof(struct student));

	tmp->id = id;
	tmp->grade = grade;
	tmp->next = NULL;

	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = tmp;
}

struct student* deletFirst()
{
	struct student *tmp = head;
	head = head->next;
	return tmp;
}

struct student* delet(int id)
{
	struct student* current = head;
	struct student* previous = NULL;
	while (current->id != id)
	{
		if (current->next == NULL)
		{
			return NULL;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
	if (current == head)
	{
		head = head->next;
	}
	else
	{
		previous->next = current->next;
	}

	return current;
}
void main()
{
	insertFirst(1, 10); // insert first fonsiyonu sürekli baþa eklegiði için tersten yazdýrmýþ oldu.
	insertFirst(2, 20);
	insertFirst(3, 30);
	insertFirst(4, 50);
	printList();
	printf("-------------------\n");
	delet(3);
	printList();
	printf("-------------------\n");
	insertLast(5, 50);
	printList();
	printf("-------------------\n");
	deletFirst();
	printList();
	system("pause");
	
}
*/

/*
typedef struct n {
	int data;
	struct n * next;
} node;

node *head = NULL;

void printList()
{
	node *temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

int insertSorted(int x)
{
	if (head == NULL)
	{
		head = (node*)malloc(sizeof(node));
		head->data = x;
		head->next = NULL;
		return 0;
	}
	if (head->data > x)
	{
		node *temp = (node *)malloc(sizeof(node));
		temp->data = x;
		temp->next = head;
		head = temp;
		return 0;
	}

	node *count = head;
	while (count->next != NULL && count->next->data < x)
		count = count->next;                               // linked list kullanarak araya eleman ekleme ..
	node *temp = (node *)malloc(sizeof(node));
	temp->next = count->next;
	count->next = temp;
	temp->data = x;
	return 0;
}
int main()
{
	int x;
	printf("Listeye eklemek için bir sayi giriniz:");
	scanf("%d", &x);
	while (x != -1)
	{
		insertSorted(x);
		printList();
		printf("Listeye eklemek için bir sayi giriniz (cikis -1):");
		scanf("%d", &x);
	}
	system("pause");
	return 0;

}*/

/*
int main(void)
{
	char kelime[30];
	int boyut = 0, i = 0, p;
	printf("Bir kelime giriniz:");
	scanf("%s", kelime);
	for (i = 0; kelime[i] != '\0'; i++)
		boyut++;
	for (i = 0; i < boyut; i++)
	{
		if (kelime[i] != kelime[boyut - 1 - i])
			p = 0;
	}
	if (p == 0)
		 printf("girdiginiz kelime palindromik degildir.");
	else
		printf("girdiginiz kelime palndromiktir.");
	system("pause");
	return 0;
}
*/

/*
	void main()
	{
		FILE* fptr;
		char filename[15];
		char ch;

		printf("Enter the filename to be opened \n");
		scanf("%s", filename);
		fptr = fopen(filename, "r");
		if (fptr == NULL)
		{
			printf("Cannot open file \n");
			exit(0);
		}
		ch = fgetc(fptr);
		while (ch != EOF)
		{
			printf("%c", ch);
			ch = fgetc(fptr);
		}
		fclose(fptr);
		system("pause");
	
	}
	*/




