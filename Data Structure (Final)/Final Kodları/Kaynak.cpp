#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

/*
struct LinkedList                                                                   // __________________LINKED LIST_______________
{
	int data;
	char msg[25];
	LinkedList *next;
};

LinkedList *first = NULL;
LinkedList *last = NULL;

void insert(LinkedList *item);
void display();
LinkedList *search(int key);
LinkedList *delet(int key);


int main()
{
	LinkedList *p, *b;
	char smsg[25];
	int choice, val;

	while (1)
	{
		printf("Menu\n");
		printf("1-insert \n 2 - display \n 3 - delete\n 4 - search\n 5- exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			p = (LinkedList*)malloc(sizeof(LinkedList));
			printf("value : \n");
			scanf("%d", &(p->data));

			printf("mesagge : \n");
			scanf("%s", p->msg);
			insert(p);
			break;


		case 2:
			display();
			break;

		case 3:
			printf("Enter you want to deleting element :\n");
			scanf("%d", &val);
			b = delet(val);
			if (b!=NULL)
			{
				printf("silme basarili\n");
			}
			else
			{
				printf("silme basarisiz\n");
			}
			break;

		case 4 :
			printf("Aamak istediginiz elemani giriniz  :\n");
			scanf("%d", &val);
			b = search(val);
			if (b!=NULL)
			{
				printf("Data is  = %d\n", b);
			}
			else
			{
				printf("Dta is not found \n");
			}
			break;

		case 5:
			exit(0);
			break;

		default :
			printf("Lütfen 1 ile 5 arasinda sayi giriniz \n");
			break;
		}
	}
	system("pause");
	return 0;
}

void insert(LinkedList *item)
{
	if (first != NULL)
	{
		last->next = item;
		item->next = NULL;
		last = item;
	}
	else
	{
		first = item;
		last = item;
		last->next = NULL;
	}	
}

void display()
{
	LinkedList *p = first;
	if (p == NULL)
	{
		printf("List is empty \n");
	}
	while (p != NULL)
	{
		printf("%d %s\n", p->data, p->msg);
		p = p->next;
	}
}

LinkedList *search(int key)
{
	LinkedList *p = first;

	while (p)
	{
		if (key == p->data)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

LinkedList *delet(int key)
{
	LinkedList *p = first;
	LinkedList *previous = NULL;


	while (p)
	{
		if (key == p->data)
		{
			break;
		}
		previous = p;
		p = p->next;
	}

	if (p != NULL)
	{
		if (previous == NULL)
		{
			if (first == last)
			{
				first = NULL;
				last = NULL;
			}
			else
			{
				first = first->next;
			}
		}
		else
		{
			previous->next = p->next;
			if (p == last)
			{
				last = previous;
			}
		}
		free(p);
		return p;
	}
	else
	{
		return NULL;
	}
}*/

/*
struct Dlist                                                     //________________________ DOUBLY LINKED LIST___________________
{
	int info;
	char msg[20];
	Dlist *next;
	Dlist *previous;
};

Dlist *first = NULL;
Dlist *last = NULL;

void insert(Dlist *item);
void display();
Dlist *search(int key);
Dlist *delet(int key);

int main()
{

	Dlist *p, *b;
	char smsg[20];
	int choice, n;

	while (1)
	{
		printf("--MENU--\n\n");
		printf("1_insert -> 2_display -> 3_search -> 4_delete -> 5_exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			p = (Dlist*)malloc(sizeof(Dlist));
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


void insert(Dlist *item)
{
	if (first == NULL)
	{
		first = item;
		last = item;
		first->previous = NULL;
		last->next = NULL;
	}
	else
	{
		last->next = item;
		item->previous = last;
		last = item;
		item->next = NULL;		
	}
}

void display()
{
	Dlist *p;
	p = first;

	if (p == NULL)
	{
		printf("List is empty\n");
	}
	while (p != NULL)
	{
		printf("%d %s\n", p->info, p->msg);
		p = p->next;
	}
}

Dlist *search(int key)
{
	Dlist *p = first;

	while (p)
	{
		if (key == p->info)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	return NULL;
}

Dlist *delet(int key)
{
	Dlist *p;
	p = search(key);

	if (p == NULL)
	{
		printf("aradiginiz eleman listede yok\n");
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
	return p;
}*/

/*                                                                    // _____________STACK CODE__(array)___________
#define N 100

int S[N];
int sp = 0;

int push(int item);
int pop();
void reset();
int top();
int size();
bool isEmpty();

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

		default:
			printf("Please enter the valid number  1 - 6\n");
			break;

		}
	}

	system("puase");
	return 0;
}


int push(int item)
{

	if (sp >= N)
	{
		printf("Stack is full\n");
		return -1;
	}
	else
	{
		S[sp] = item;
		sp++;
	}
	return 0;
}

int pop()
{
	int i;

	if (sp <= 0)
	{
		printf("stack  is empty\n");
		return -1;
	}
	else
	{
		sp--;
		i = S[sp];		 
	}
	return i;
}

void reset()
{
	sp = 0;
}

int top()
{
	return S[sp - 1];
}
int size()
{
	return sp;
}
bool isEmpty()
{
	if (sp == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}*/

/*
struct Stack                                                            //  ______________STACK CODE_____(linked list)__________
{    
	int data;
	Stack *next;
};

Stack *sp = NULL;
int counter = 0;

int push(int item);
int pop();
void reset();
int size();
Stack *top();
Stack *isEmpty();

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

		default:
			printf("Please enter the valid number  1 - 6\n");
			break;

		}
	}



	system("pause");
	return 0;
}

int push(int item)
{
	Stack *p;
	p = (Stack*)malloc(sizeof(Stack));

	if ( p == NULL)
	{
		printf("memory is full\n");
		return -1;
	}
	else
	{
		p->data = item;
		p->next = sp;
		sp = p;
	}
	counter++;
	return 0;
}

int pop()
{
	Stack *p;
	int temp;

	if (sp == NULL)
	{
		printf("Stack is empty\n");
		return -1;
	}
	else
	{
		p = sp;
		temp = p->data;
		sp = sp->next;
		free(p);
	}
	counter--;
	return temp;
}

void reset()
{
	Stack *p;
	while (sp != NULL)
	{
		p = sp;
		sp = sp->next;
		free(p);
	}
	printf("Stack is empty now\n");
}

int size()
{
	return counter;
}
Stack *top()
{
	return sp;
}
Stack *isEmpty()
{
	return sp;
}*/

/*
#define SIZE 200                                                     // ____________________QUEUE CODE (array)_______________

int Q[SIZE];
int front = 0;
int last = 0;
int counter = 0;

int enqueue(int item);
int dequeue();
void reset();
void  display();
int Size();
int isFull();
int isEmpty();

int main()
{
	int data, choice, i;
	while (1)
	{
		printf("\n");
		printf("MENU\n");
		printf("1_Enqueue\n 2_Dequeue\n 3_Size\n 4_Display\n 5_Reset\n 6_isFull\n 7_isEmpty\n 8_Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter a value : \n");
			scanf("%d", &data);
			enqueue(data);
			break;

		case 2:
			i = dequeue();
			printf("Data is deleted : %d", i);
			break;

		case 3:
			Size();
			break;

		case 4:
			display();
			break;

		case 5:
			reset();
			break;

		case 6:
			isFull();
			break;

		case 7:
			isEmpty();
			break;

		case 8:
			exit(0);
			break;

		default:
			printf("This is wrong choice. Please enter a valid value \n ");
			break;
		}

	}


	system("pause");
	return 0;
}


int enqueue(int item)
{
	if (counter >= SIZE)
	{
		printf("Queue is full\n");
		return -1;
	}
	else
	{
		Q[last] = item;
		last = (last + 1) % SIZE;
	}
	counter++;
	return 0;
}

int dequeue()
{
	int i;
	if (counter <= 0)
	{
		printf("Queue is empty\n");
		return -1;
	}
	else
	{
		i = Q[front];
		front = (front + 1) % SIZE;
	}
	counter--;
	return i;
}

void reset()
{
	front = 0; last = 0; counter = 0;
	printf("Queue is empty now\n");
}

int Size()
{
	return counter;
}

void  display()
{
	int temp = front;

	if (counter == 0)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("The Queue element(s)\n");
		while (temp < last)
		{
			printf("%d\n", Q[temp]);
			temp++;
		}
	}

}
int isFull()
{
	if (counter >= SIZE)
	{
		printf("Queue is full\n");
		return true;
	}
	else
	{
		printf("Queue is not full\n");
		return false;
	}
}

int isEmpty()
{
	if (counter <= 0)
	{
		printf("Queue is empty\n");
		return true;
	}
	else
	{
		printf("Queue is not empty \n");
		return false;
	}
}*/

/*
struct Queue                                                       // ____________________QUEUE CODE (linked lisst)__________________
{
	int data;
	Queue *next;
};

Queue *front = NULL;
Queue *last = NULL;
int counter = 0;

void enqueue(int item);
void dequeue();
void reset();
int size();
void display();
bool isEmpty();

int main()
{
	int item, choice;

	while (1)
	{
		printf("__MENU__\n");
		printf("1_Enqueue\n 2_Dequeue\n 3_Display\n 4_Size\n 5_isEmpty\n 6_Reset\n 7_Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Please Enter the data to Equeue : \n");
			scanf("%d", &item);
			enqueue(item);
			break;

		case 2:
			dequeue();
			break;

		case 3:
			display();
			break;

		case 4:
			printf("The Queue size = %d\n", size());
			break;

		case 5:
			isEmpty();
			break;

		case 6:
			reset();
			break;

		case 7:
			exit(0);
			break;

		default:
			printf("Enter The Number Between 1-7\n");
			break;

		}
	}
	system("pause");
	return 0;


	system("pause");
	return 0;
}

void enqueue(int item)
{
	Queue *p;
	p = (Queue*)malloc(sizeof(Queue));

	if (p == NULL)
		printf("Memory has not enough area \n");	

	p->data = item;
	p->next = NULL;

	if (front == NULL)
	{
		front = p;
		last = p;
	}
	else
	{
		last->next = p;
		last = p;
	}
	counter++;
	printf("Data is succesfully added\n");
}

void dequeue()
{
	Queue *p;
	int key;
	if (front == NULL)	
		printf("Queue is empty\n");	

	p = front;
	key = front->data;
	front = front->next;
	printf("The data is dequeued = %d\n", key);

	if (front == NULL)	
		last = NULL;
	
	counter--;
	free(p);	
}


void reset()
{
	Queue *p;
	p = front;

	while (p)
	{
		front = front->next;
		free(p);
		p = front;
	}
	front = NULL;
	last = NULL;
	counter = 0;

	printf("The Queue is empty now \n");
}

int size()
{
	return counter;
}

void display()
{
	Queue *p;
	p = front;

	if (front == NULL) {
		printf("The Queue is empty.\n");
	}
	else
	{
		printf("The Queue element(s)\n");
		while (p)
		{			
			printf("%d\n", p->data);
			p = p->next;
		}
	}

}
bool isEmpty()
{
	if (front == NULL)
	{
		printf("Queueu is empty\n");
		counter = 0;
		return true;
	}
	else
	{
		printf("Queue is not empty \n");
		return false;
	}
}*/


/*
struct BTree
{
	int info;
	char massage[100];
	BTree *left;
	BTree *right;
};

BTree *root = NULL;

void insert(BTree *treeRoot, BTree *newnode);
void traverse(BTree *treeRoot);
BTree *search(BTree *treRoot, int item);
BTree *delet(BTree *treeRoot, int item);
BTree *readNode();
int countNodes(BTree *treeRoot, int sum);

int main()
{
	BTree *n, *a;
	int i, choice;
	int count;

	while (1)
	{
		printf("MENU\n");
		printf("1- Insert a node\n 2- delete a node\n 3- list nodes\n 4- search for a node\n 5- count number in tree\n 6- exit\n ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			n = readNode();
			insert(root, n);
			break;

		case 2:
			printf("enter to be deleted a node :\n");
			scanf("%d", &i);
			a = delet(root, i);
			if (a != NULL)
			{
				printf("Deleted\n");
			}
			else
			{
				printf("Item is not found in tree\n");
			}
			break;

		case 3:
			if (root != NULL)
			{
				traverse(root);
			}
			else
			{
				printf("Tree is empty \n");
			}
			break;

		case 4:
			printf("Enter a node for search :");
			scanf("%d", &i);

			a = search(root, i);
			if (a != NULL)
			{
				printf("%d  %s\n", a->info, a->massage);
			}
			else
			{
				printf("Item is not found \n");
			}
			break;

		case 5:
			count = countNodes(root, 0);
			printf("Number of nodes in the tree = %d\n", count);
			break;

		case 6:
			exit(0);
			break;

		default:
			printf("enter the valis number ( 1-6)\n");
			break;
		}
	}
	system("pause");
	return 0;
}

void insert(BTree *treeRoot, BTree *newnode)
{
	if (treeRoot == NULL)
		root = newnode;
	else
	{
		if (newnode->info < treeRoot->info)
		{
			if (treeRoot->left == NULL)
				treeRoot->left = newnode;

			else
				insert(treeRoot->left, newnode);
		}
		else
		{
			if (treeRoot->right == NULL)
				treeRoot->right = newnode;
			else
				insert(treeRoot->right, newnode);
		}
	}
}

// PRE-ORDER TRAVERSAL = root  , left , right
// IN-ORDER TRAVERSAL  = left , root ,  right (KÇÜKTEN BÜYÜÐE SIRALADIÐI ÝÇÝN EN ÇOK TERCÝH EDÝLENDÝR)
// POST-ORDER TRAVERAL = left , right , root

void traverse(BTree *treeRoot) // pre-order
{
	if (treeRoot != NULL)
	{
		traverse(treeRoot->left);
		printf("%d\n %s\n", treeRoot->info, treeRoot->massage);
		traverse(treeRoot->right);
	}
}

BTree *search(BTree *treRoot, int item)
{
	while ((treRoot != NULL) && (treRoot->info != item))
	{
		if (item < treRoot->info)
			treRoot = treRoot->left;

		else
			treRoot = treRoot->right;
	}
	return treRoot;
}

BTree *delet(BTree *treeRoot, int item)
{
	BTree *qa, *q, *qc, *sa, *s;

	if (treeRoot == NULL)
		return NULL;

	q = treeRoot;
	qa = NULL;

	// þimdi sileceðimiz elemaný arama iþlemi yapacaðýz.
	while ((q != NULL) && (q->info != item))
	{
		qa = q;
		if (item < q->info)
			q = q->left;
		else
			q = q->right;
	}
	if (q == NULL)
	{
		printf("Item to be deleted is not found\n");
		return NULL;
	}

	// þimdi sileceðimiz elemaný bulundu ve biz onun 2 çocuklu olma durumunu inceliyoruz.
	if ((q->left != NULL) && (q->right != NULL))
	{
		s = q->left;
		sa = q;

		while (s->right != NULL) // sol alt aðaçtaki en büyük deðer en saðdadýr mantðýna göre hareket ederiz.
		{
			sa = s;
			s = s->right;
		}
		q->info = s->info;
		strcpy(q->massage, s->massage);
		q = s;
		qa = sa;
	}

	if ((q->left != NULL))
		qc = q->left;
	else
		qc = q->right;

	if (q == treeRoot)
		root = qc;

	else
	{
		if (q == qa->left)
			qa->left = qc;

		else
			qa->right = qc;
	}
	free(q);
	return q;
}

BTree *readNode()
{
	BTree *newnode;

	newnode = (BTree*)malloc(sizeof(BTree));
	if (newnode == NULL)
	{
		printf("Memory has not enough area for newnode\n");
		return NULL;
	}
	printf("Enter info :\n");
	scanf("%d", &(newnode->info));
	printf("Enter message :\n");
	scanf("%s", newnode->massage);
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int countNodes(BTree *treeRoot, int sum)
{
	if (treeRoot == NULL)
	{
		return sum;
	}
	sum++;
	sum = countNodes(treeRoot->left, sum);
	sum = countNodes(treeRoot->right, sum);
	return sum;
}*/

// ____________________________________________________________________________________---------------------------------------------_________________________________________________________________

/*
struct LinkedList
{
	int info;
	char msg[20];
	LinkedList  *next;
};

LinkedList *first = NULL;
LinkedList *last = NULL;

void insert(LinkedList *p);
void display();
LinkedList *search(int key);
LinkedList *delet(int key);

int main()
{
	LinkedList *p, *b;
	char smsg[25];
	int choice, val;

	while (1)
	{
		printf("Menu\n");
		printf("1-insert \n 2 - display \n 3 - delete\n 4 - search\n 5- exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			p = (LinkedList*)malloc(sizeof(LinkedList));
			printf("value : \n");
			scanf("%d", &(p->info));

			printf("mesagge : \n");
			scanf("%s", p->msg);
			insert(p);
			break;


		case 2:
			display();
			break;

		case 3:
			printf("Enter you want to deleting element :\n");
			scanf("%d", &val);
			b = delet(val);
			if (b != NULL)
			{
				printf("silme basarili\n");
			}
			else
			{
				printf("silme basarisiz\n");
			}
			break;

		case 4:
			printf("Aamak istediginiz elemani giriniz  :\n");
			scanf("%d", &val);
			b = search(val);
			if (b != NULL)
			{
				printf("Data is  = %d\n", b);
			}
			else
			{
				printf("Dta is not found \n");
			}
			break;

		case 5:
			exit(0);
			break;

		default:
			printf("Lütfen 1 ile 5 arasinda sayi giriniz \n");
			break;
		}
	}

	system("pause");
	return 0;
}

void insert(LinkedList *p)
{
	if (first == NULL)
	{
		first = p;
		last = p;
	}
	else
	{
		last->next = p;
		last = p;
		p->next = NULL;
	}
}

void display()
{
	LinkedList *p;
	p = first;
	
	while (p != NULL)
	{
		printf("%d %s\n", p->info, p->msg);
		p = p->next;
	}
}

LinkedList *search(int key)
{
	LinkedList *p = first;

	while (p)
	{
		if (key == p->info)
		{
			return p;
		}
		else
		{
			p = p->next;
		}
	}
	return NULL;
}

LinkedList *delet(int key)
{
	LinkedList *p = first , *previous = NULL;

	if (first == NULL)
	{
		return NULL;
	}
	
	while (p)
	{
		if (key == p->info)
		{
			break;
		}
		previous = p;
		p = p->next;
	}

	if (p != NULL)
	{
		if (previous == NULL)
		{
			if (first == last)
			{
				first = NULL;
				last = NULL;
			}
			else			
				first = first->next;			
		}
		else
		{
			previous->next = p->next;
			if (p = last)			
				last = previous;			
		}

		free(p);
		return p;
	}
	else
	{
		return NULL;
	}
}*/

/*
#define N 100

int S[N];
int sp = 0;


int push(int item)
{
	if (sp >= N)
	{
		printf("Stack is full\n");
		return -1;
	}
	else
	{
		S[sp] = item;
		sp++;
	}
	return 0;
}

int  pop()
{
	if (sp <= 0)
	{
		printf("Stack is empty\n");
		return -1;
	}
	else
	{
		sp--;
		return S[sp];
	}
}

void reset()
{
	sp = 0;
}

int top()
{
	return S[sp-1];
}
bool isEmpty()
{
	if (sp <= 0)
	{
		printf("stack is empty\n");
		return true;
	}
	else
	{
		printf("Stack is not empty\n");
		return false;
	}
}*/


/*
struct Slist
{
	int item;
	Slist *next;
};

Slist *sp = NULL;
int counter = 0;

int push(int data)
{
	Slist *p;
	p = (Slist*)malloc(sizeof(Slist));

	if (p == NULL)
	{
		printf("Memory s full\n");
		return -1;
	}
	else
	{
		p->item = data;
		p->next = sp;
		sp = p;
	}
	counter++;
	return 0;
}

int pop()
{
	Slist *p;
	int i;

	if (sp = NULL)
	{
		printf("Stack is empty \n");
		return -1;
	}
	else
	{
		p = sp;
		i = p->item;
		sp = sp->next;
		free(p);
	}
	return i;
}

void reset()
{
	Slist *p;

	while (sp != NULL)
	{
		p = sp;
		sp = sp->next;
		free(p);
	}
}

Slist *top()
{
	
	return sp;
}

int size()
{
	return counter;
}

Slist *isEmpty()
{
	return sp;
}*/

/*
#define N 200

int Q[N];
int front = 0;
int last = 0;
int counter = 0;


void enqueue(int item)
{
	if (counter >= N)
	{
		printf("Queue is full\n");
	}
	else
	{
		Q[last] = item;
		last = (last + 1) % N;
	}
	counter++;
}

int dequeue()
{
	int item;
	if (counter <= 0)
	{
		printf("Queue is empty\n");
		return -1;			
	}
	else
	{
		item = Q[front];
		front = (front + 1) % N;
	}
	counter--;
	return item;
}

void reset()
{
	counter = 0;
	front = 0;
	last = 0;
}

int size()
{
	return counter;
}

bool isEmpty()
{
	if (counter <= 0)
	{
		printf("Queue is empty\n");
		return true;
	}
	else
	{
		printf("Queue is not empty\n");
		return false;
	}
}

void dsiplay()
{
	int temp = front;

	if (counter <= 0)
	{
		printf("The Queue is empty\n");
	}
	else
	{
		while (temp < last)
		{
			printf("%d\n", Q[temp]);
			temp++;
		}
	}
}*/


struct Queue
{
	int data;
	Queue *next;
};

Queue *front = NULL;
Queue *last = NULL;
int counter = 0;

int enqueue(int item)
{
	Queue *p;
	p = (Queue*)malloc(sizeof(Queue));

	if (p == NULL)
	{
		printf("Memory is full\n");
		return -1;
	}
	p->data = item;
	p->next = NULL;

	if (front == NULL)
	{
		front = p;
		last = p;
	}
	else
	{
		last->next = p;
		last = p;
	}
	counter++;
	return 0;
}


int dequeue()
{
	Queue *p;
	int temp;

	if (front == NULL)
	{
		printf("Queue is empty\n");
		return -1;
	}
	p = front;
	temp = front->data;
	front = front->next;
	if (front = NULL)
	{
		last = NULL;
	}
	counter--;
	free(p);
	return temp;
}

void reset()
{
	Queue *p;
	p = front;

	while (p)
	{
		front = front->next;
		free(p);
		p = front;
	}
	front = NULL;
	last = NULL;
}

void display()
{
	Queue *p;
	p = front;
	if (front == NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		while (p)
		{
			printf("%d", p->data);
			p = p->next;
		}
	}
}
bool isEmpty()
{
	if (front == NULL)
	{
		printf("Queue is empty\n");
		counter = 0;
		return true;
	}
	else
	{
		printf("Queue is not empty\n");
		return false;
	}
}

int size()
{
	return counter;
}
