#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>
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
			scanf("%d",&i);
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
				printf("%d  %s\n", a->info,  a->massage);
			}
			else
			{
				printf("Item is not found \n");
			}
			break;

		case 5:
			count = countNodes(root, 0);
			printf("Number of nodes in the tree = %d\n",count);
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
// IN-ORDER TRAVERSAL  = left , root ,  right (K��KTEN B�Y��E SIRALADI�I ���N EN �OK TERC�H ED�LEND�R)
// POST-ORDER TRAVERAL = left , right , root

void traverse(BTree *treeRoot) // pre-order
{
	if (treeRoot != NULL)
	{	
		printf("%d\n %s\n", treeRoot->info, treeRoot->massage);
		traverse(treeRoot->left);		
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

	// �imdi silece�imiz eleman� arama i�lemi yapaca��z.
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

	// �imdi silece�imiz eleman� bulundu ve biz onun 2 �ocuklu olma durumunu inceliyoruz.
	if ((q->left != NULL) && (q->right != NULL))
	{
		s = q->left;
		sa = q;

		while (s->right != NULL) // sol alt a�a�taki en b�y�k de�er en sa�dad�r mant��na g�re hareket ederiz.
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
}