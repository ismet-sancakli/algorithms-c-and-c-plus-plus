#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>


/*
void insertionSort(int D[], int n);
int main()
{
	int A[25];
	int i, n;

	printf("Dizinin boyutuu giriniz : \n");
	scanf("%d", &n);

	printf(" Dizinin elemanlarini giriniz : \n");
	for ( i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	insertionSort(A, n);

	printf("Sirlanmis dizi : \n");
	
	for ( i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}

	system("pause");
	return 0;
}


void insertionSort(int D[], int n)
{
	int i, j, temp;

	for ( i = 1; i <n ; i++)
	{
		temp = D[i];

		for ( j = i-1; j >= 0 && temp <= D[j] ; j--) // j nin azalamasý önceki elemanlara baktýðýný gösteriyor ve-------------- orta bölüm çokkkk ÖNEMLÝ !!!!!!!!!!
		{
			D[j + 1] = D[j];
			D[j] = temp;
		}
	}
}
*/

/*

void selectionSort(int D[], int n);

int main()
{
	int A[25];
	int i, n;

	printf("Dizinin boyutuu giriniz : \n");
	scanf("%d", &n);

	printf(" Dizinin elemanlarini giriniz : \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	selectionSort(A, n);

	printf("Sirlanmis dizi : \n");

	for (i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}

	system("pause");
	return 0;
}

void selectionSort(int D[], int n)
{
	int min, temp, i, j;

	for ( i = 0; i < n; i++)
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
void bubbleSort(int D[], int n);
int main()
{
	int A[25];
	int i, n;

	printf("Dizinin boyutuu giriniz : \n");
	scanf("%d", &n);

	printf(" Dizinin elemanlarini giriniz : \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	bubbleSort(A, n);

	printf("Sirlanmis dizi : \n");

	for (i = 0; i < n; i++)
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
		for ( kar = 0; kar < n-move-1; kar++)
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

 /*                    // HEAP SORT ALGORITMASI !!!!!!!!!!
int left(int i);
int right(int i);
void heapify(int D[], int i);
void buildHeap(int D[], int n);
void HeapSort(int D[], int n);

int main()
{
	int A[25];
	int i, n;

	printf("Dizinin boyutuu giriniz : \n");
	scanf("%d", &n);

	printf(" Dizinin elemanlarini giriniz : \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	HeapSort(A, n);

	printf("Sirlanmis dizi : \n");

	for (i = 0; i < n; i++)
	{
		printf("%d\n", A[i]);
	}
	system("pasue");
	
	return 0;
}

int heap_size;

int left(int i)
{
	return 2 * i + 1;
}

int right(int i)
{
	return 2 * i + 2;	
}

void heapify(int D[] , int i)
{
	int left_child, right_child, temp, max;
	left_child = left(i);
	right_child = right(i);

	if ((left_child <= heap_size) && (D[left_child] > D[i]))
	{
		max = left_child;
	}
	else
	{
		max = i;
	}
	if ((right_child <= heap_size)  && (D[right_child] > D[i]))
	{
		max = right_child;
	}

	if (max != i)
	{
		temp = D[i];
		D[i] = D[max];
		D[max] = temp;
		heapify(D, max);
	}
}

void buildHeap(int D[], int n)
{
	int i;	
	heap_size = n - 1;

	for ( i = (n-1)/2; i >= 0 ; i--)
	{
		heapify(D, i);
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
		heapify(D, 0);
	}
}
*/

int binarySerach(int D[], int left, int  right, int x);
int main()
{
	int A[50];
	int i, n, x, p;


	printf("Dizinin boyutuu giriniz : \n");
	scanf("%d", &n);

	int left = 0;
	int right = n - 1;

	printf(" Dizinin elemanlarini giriniz : \n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	printf("aradigiiz eleman : \n");
	scanf("%d", &x);

	 p = binarySerach(A, 0, n, x);

	 if (p >= 0)
	 {
		 printf("aradiginiz eleman = %d . indiste   ", p);
	 }
	 else
	 {
		 printf("ERROR!!");
	 }

	system("pause");
	return 0;
}

int binarySerach(int D[], int left, int  right, int x)
{
	int middle;
	while (left < right)
	{
		middle = (left + right) / 2;

		if (x ==  D[middle])
		{
			return middle;
		}
		else if (x < D[middle])
		{
			right = middle - 1;
		}
		else
		{
			left = middle + 1;
		}
	}
	return -1;
}