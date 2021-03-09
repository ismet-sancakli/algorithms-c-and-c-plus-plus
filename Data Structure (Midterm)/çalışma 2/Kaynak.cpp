#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*
void insertionSort(int D[], int n);

int main()                                               // ---------------------INSERTION SORT--------------------------- 
{
	int i;
	int A[] = { 7,3,5,8,2,9,4,15,6 };

	insertionSort(A, 9);

	for (i = 0; i < 9; i++)
	{
		printf("dizinin %d. elemani  = %d\n", i, A[i]);
	}
	system("pause");
	return 0;
}


void insertionSort(int D[], int n)
{
	int i, j, temp;

	for (i = 1; i < n; i++)
	{
		temp = D[i];
		for (j = i - 1; j >= 0 && temp <= D[j]; j--)
		{
			D[j + 1] = D[j];

			D[j] = temp;          //___________ BURAYI HOCA D[j+1] = temp ÞEKLÝNDE YAPMIÞ VE ÝLK FOR DÖNGÜSÜ ÝÇÝNE ALMIÞ BURAYA BAK !!!!!!
		}
	}
}
*/


/*
void selectionSort(int d[], int n);                            //------------- SELECTION SORT IT IS VERY IMPORTANT!!!!!!!!!----------
int main()
{
	int A[50];
	int n, i;

	printf("dizinin botunu giriniz :\n");
	scanf("%d", &n);

	printf("dizinin elemanlarini giriniz \n");
	for ( i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	selectionSort(A, n);

	for ( i = 0; i < n; i++)
	{
		printf("dizinin %d. elemani = %d\n", i + 1, A[i]);
	}
	

	system("pause");
	return 0;
}

void selectionSort(int d[], int n)
{
	int i, j;
	int min, temp;

	for ( i = 0; i < n-1; i++)
	{
		min = i;
		for ( j = i; j < n; j++)
		{
			if (d[j] < d[min])
			{
				min = j;
			}
		}
		temp = d[i];
		d[i] = d[min];
		d[min] = temp;
	}
}
*/



/*
void bubbleSort(int D[], int n);        //------------------------------------- BUBBLE SORT ALGHORITM -------------------
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

	bubbleSort(A, n);

	for ( i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}

	system("pause");
	return 0;
}

void bubbleSort(int D[], int n)
{
	int move, k, temp;

	for ( move = 0; move < n-1; move++)
	{
		for ( k = 0; k < n-1-move; k++)
		{
			if (D[k] > D[k+1])
			{
				temp = D[k];
				D[k] = D[k + 1];
				D[k + 1] = temp;
			}
		}
	}
}
*/

/*
void mergesort(int D[], int left, int right);
void merge(int D[], int left, int k, int right);

int main()
{                                                          //---------------------- MERGE SORT ALGORTIM --------------
	int A[50];
	int n, i;

	printf("dizinin boyutunu giriniz :\n");
	scanf("%d", &n);

	printf("dizinin elemanlarini giriniz \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	mergesort(A,0,n-1);   // LEFT = 0 , RIGHT = N-1..
	
	printf("Siralanmis dizi :\n");
	for ( i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}

	system("pause");
	return 0;
}

void mergesort(int D[], int left, int right) 
{
	int k;
	if (left < right) 
	{
		k = (left + right) / 2; 	
		mergesort(D, left, k);
		mergesort(D, k + 1, right);

		merge(D, left, k, right);
	}
}


void merge(int D[], int left, int k, int right) 
{
	int i, j, l = 0;
	int M[100]; 	// temporary array

	for (i = left, j = k + 1; (i <= k) && (j <= right); ) 
	{
		if (D[i] < D[j])
		{
			M[l] = D[i];
			i++;
			l++;
		}
		else
		{
			M[l] = D[j];
			j++;
			l++;
		}
	}
	while (i <= k) 
	{
		M[l] = D[i];
		i++;
		l++;
	}
	while (j <= right)
	{
		M[l] = D[j];
		j++;
		l++;
	}
	// copy M to D
	for (i = left, l = 0; i <= right; i++, l++)
		D[i] = M[l];
}
*/

/*
void quickSort(int D[], int left, int right);

int main()                                             // _________________QUICK SORT ALGORITHM_______________
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
		
	quickSort(A, 0, n-1);

	for (i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}

	system("pause");
	return 0;
}

void quickSort(int D[], int left, int right)
{
	int k, j, q, temp;

	k = left;
	j = right;

	q = D[(left + right) / 2];  // PIVOT ELEMENT

	do
	{
		while ((D[k] < q) && (k < right))
			k++;
		while ((D[j] > q) && (j > left))
			j--;

		if (k <= j)
		{
			temp = D[k];
			D[k] = D[j];      // EXCHANGE ÝÞLEMÝ
			D[j] = temp;
			k++;
			j--;
		}
	} while (k <= j);    // BURAYA KADAR OLAN ÝÞLEM PÝVOT ELEMANIN SOLUNA KÜÇÜK SAÐINA BÜYÜK ELEMANLARI KOYAR.

	if (left < j)
			quickSort(D, left, j);   // BURASI ÝSE SOLDAKÝ ELEMANLARI SIRALAR. 
	if (k < right)
		quickSort(D, k, right);    // BURASI SAÐDAKÝ ELEMANLARI SIRALAR.
}
*/




/*
                                                //_______________________ HEAP SORT ALGORITHM______________________
int left(int i);
int right(int i);
void heapfiy(int D[], int i);
void buildHeap(int D[], int n);
void HeapSort(int D[], int n);

int main()
{

	int A[50];
	int n, i;

	printf("dizinin boyutunu giriniz :\n");
	scanf("%d", &n);

	printf("dizinin elemanlarini giriniz \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	HeapSort(A, n);

	for (i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}
	

	system("pause");
	return 0;
}


int left(int i)
{
	return (2 * i + 1);
}

int right(int i)
{
	return (2 * i + 2);
}

int heap_size;

void heapfiy(int D[], int i)
{
	int left_child, right_child, max, temp;
	
	left_child = left(i);
	right_child = right(i);

	if ((left_child <= heap_size) && (D[left_child]) > D[i])

		max = left_child;
	else
		max = i;

	if ((right_child <= heap_size) && (D[right_child]) > D[max])

		max = right_child;

	if (max != i)
	{
		temp = D[max];
		D[max] = D[i];
		D[i] = temp;
		heapfiy(D, max);
	}
}

void buildHeap(int D[], int n)
{
	int i;
	heap_size = n - 1;

	for ( i = (n-1)/2; i >= 0; i--)
	{
		heapfiy(D, i);
	}
}

void HeapSort(int D[], int n)
{
	int i, temp;
	buildHeap(D, n);

	for ( i = n-1; i >= 1; i--)
	{
		temp = D[i];
		D[i] = D[0];
		D[0] = temp;
		heap_size--;
		heapfiy(D, 0);
	}
}
*/


/*
#define SIZE 997                   //______________HASH--TABLE--IMPLEMENTING--USING--QUADRATIC--PROBING_____________          MAIN FUNCTION EKSIK !!!!!        
typedef struct 
{
	char name[20];
	char id[20];
	float gano;
}student;

student H[SIZE];
void initializeHashTable()  // TABLONUN ÝÇÝNÝ BOÞALTTIK
{
	int i;
	for ( i = 0; i < SIZE; i++)
	{
		strcpy(H[i].id," ");
	}
}

int hashFunction(char *key, int size)
{
	int i, j, k, result;

	i = key[10] - 48;
	j = key[9] - 48;
	k = key[6] - 48;

	result = (k * 100 + j * 10 + i);
	return result;
}

void insert(student r)
{
	int i = 1;
	int c = 0;
	int p, q;
	

	p = hashFunction(r.id, SIZE);
	q = p;

	while (strcmp(H[p].id," ")!= 0 && strcmp(H[p].id,r.id)!= 0  && c <= SIZE/2 )
	{
		c++;
		p = q + i * i;
		i++;

		if (p > SIZE)
		{
			p = p % SIZE;
		}

	}

	if (strcmp(H[p].id," ")== 0)
	{
		strcpy(H[p].id, r.id);
		strcpy(H[p].name, r.name);
		H[p].gano = r.gano;
	}
	else if (strcmp(H[p].id,r.id) == 0)
	{
		printf("ayni ögrenciye ulastiniz iki defa gisterilemez\n ");
	}
	else
	{
		printf("tablo boyutnu astiniiz");
	}

}
*/