#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<math.h>                    

/*
int main()                                       // DATA LAB FIRST WEEK!!!!
{
 int list[99];
 int choice;
 int i = 0;
 int size, pos;

 printf("Enter size of the array :");
 scanf("%d", &size);

 while (1)
  {

       printf("MENU\n");
       printf("What do you want to do ? \n\n 1- Insert element\n 2- Delete element\n 3-Print element on the screen\n 4- Print element reverse order\n 5- exit\n");
       scanf("%d", &choice);

     switch (choice)
   {
	 case 1:
             printf("Add to element    :\n ");
             scanf("%d", &list[i]);
             i++;
             printf("\n");

               break;

	  case 2:
               printf("Enter the element position to delete  :\n");
               scanf("%d", &pos);

           if (pos <= 0 || pos >size )
           {
               printf("Invalid position ! please enter position between 1 to %d\n",size);
           }
          else
          {
             for ( i = pos -1; i < size-1; i++)
             {
               list[i]=list[i+1];
             }
            size--;
          }

           break;

	  case 3:
                for ( i = 0; i <size ; i++)
                {
                  printf("%d\n", list[i]);
                }

               break;

	  case 4:
            for ( i = size-1; i >= 0; i--)
          {
             printf("%d\n", list[i]);
          }
             break;

	  case 5:
		   exit(0);
    }

  }

system("pause");
return 0;
}
*/

/*
struct node
{
	int data;
	struct node *next;

}*head = NULL;



void addElement(int value)
{
	struct node *newnode;                                 // _______________ BAÞA ELEMAN EKLER__________
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = head;
	head = newnode;
}

void display()
{
	
	struct node *temp = head;

	while (temp->next != NULL)                // temp->next != NULL durumunda bir hata var buraya tekrar BAK !!!!!!
	{
		printf("%d--->\n", temp->data);
		temp = temp->next;
	}
}

void deleteElement()
{
	struct node *temp = head;                         //_________________ BAÞTAKÝ ELEMANI SÝLER____________
	head = temp->next;                
	free(temp);
}

int main()
{
	int choice;
	int val;

	while (1)
	{
		printf("MENU\n");
		printf("What do you do ? \n\n 1- insert element\n 2- display \n 3- delete element list\n 4- reverse display list\n 5- exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("eklemek istediginiz eleman : ");
			scanf("%d", &val);

			addElement(val);
			break;

		case 2:
			display();
			break;
			
		case 3:
			deleteElement();
			break;
		

		case 5:
			exit(0);
		}		
	}
	system("pause");
	return 0;

*/

/*
void bubbleSort(int D[], int n);
                                                              //____________BUBBLE---SORT---ALGORITHM_____________
int main()
{
	int A[25];
	int n;

	printf("dizinin boyutunu girniz :\n ");
	scanf("%d", &n);

	printf("dizinin elemanlarýný giriniz\n ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	bubbleSort(A, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}


	system("pause");
	return 0;
}

void bubbleSort(int D[], int n)
{
	int move, kar, temp;

	for ( move = 0; move < n-1; move++)
	{
		for ( kar = 0; kar < n - move -1; kar++)
		{
			if (D[kar+1] < D[kar])
			{
				temp = D[kar];
				D[kar] = D[kar + 1];
				D[kar + 1] = temp;
			}
		}
	}
}
*/

/*
void inserSort(int D[], int n);
                                                        // ______________INSERTION---SORT---ALGORITHM____________
int main()
{
	int A[25];
	int n;

	printf("dizinin boyutunu girniz :\n ");
	scanf("%d", &n);

	printf("dizinin elemanlarini giriniz\n ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	inserSort(A, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}

	system("pause");
	return 0;
}

void inserSort(int D[], int n)
{
	int temp, i, j;
	for ( i = 0; i < n; i++)
	{
		temp = D[i];
		for ( j = i-1; j >= 0 && temp <= D[j]; j--)
		{
			D[j + 1] = D[j];
			D[j] = temp;
		}
	}	
}
*/

/*
void selectionSort(int D[], int n);
                                                                 // ___________ SELECTION---SORT---ALGORITHM___________
int main()
{
	int A[50];
	int n, i;

	printf("dizinin botunu giriniz :\n");
	scanf("%d", &n);

	printf("dizinin elemanlarini giriniz \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	selectionSort(A, n);

	for (i = 0; i < n; i++)
	{
		printf("dizinin %d. elemani = %d\n", i + 1, A[i]);
	}


	system("pause");
	return 0;
}

void selectionSort(int D[], int n)
{
	int i, j, temp, min;

	for (i = 0; i < n-1; i++)
	{
		min = i;
		for ( j = i; j < n; j++)
		{
			if (D[j] < D[min])
			{
				min = j;
			}
		}
		temp = D[i];
		D[i] = D[min];
		D[min] = temp;
	}
}
*/

/*
#define SIZE 10                                                    // _____________ BINARY---SEARCH---ALGORITHM__________
int binary_search(int D[], int low, int high, int element);

int main()
{
	int a[SIZE] = { 5, 7, 8, 9 , 20, 21, 54, 67, 89, 93 };
	int i, k, p;

	printf("Array: ");
	for (i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	printf("\nPlease enter the searched key:");
	scanf("%d", &k);

	p = binary_search(a, 0, SIZE, k);

	if (p >= 0)
	{
		printf("The key %d was found at %d (starting from 0)\n", k, p);
	}
	else
	{
		printf("The key %d was not found\n", k);
	}
	system("pause");
	return 0;
}

int binary_search(int D[], int low, int high, int element)
{
	int middle;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (element > D[middle])
			low = middle + 1;
		else if (element < D[middle])
			high = middle - 1;
		else
			return middle;
	}
	return -1;
}
*/


