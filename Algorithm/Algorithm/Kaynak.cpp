#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<process.h>
#include<math.h>


int main()
{
	int a[10], b[10], i, j;

	for ( i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	i = 0;
	for ( j = 0; j < 10; j++)
	{
		if (a[j] % 2 == 0)
		{
			b[i] = a[j];
			i++;
		}
	}

	for ( i = 0; i < 10; i++)
	{
		printf("%d\n", b[i]);
	}
	system("pause");
	return 0;
}

/*
int main()
{
	int a[10], b[10], i, j = 0;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 9; i >=0; i--)
	{
		if (a[i] % 2 == 0)
		{
			b[j] = a[i];
			j++;
		}
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", b[i]);
	}
	system("pause");
	return 0;
}*/

/*
int multiply(int base, int n)
{
	if (n == base)
	{
		return n;
	}
	return n * multiply(base, n - 1);
}

int main()
{
	int k;
	scanf("%d", &k);

	printf("%f\n", pow(multiply(k + 1, k + 4), 0.25));

	system("pause");
	return  0;
}*/

/*
int prime(int x, int n)
{
	if (x < 2)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	if (x % n== 0)
	{
		return 0;
	}
	return prime(x, n - 1);
}

int main()
{
	int sayi = 42;
	int sonuc = prime(sayi, sayi / 2);	
	if (sonuc == 0)
	{
		printf("%d asal sayi degildir\n", sayi);
	}
	else
	{
		printf("%d asal sayidir\n", sayi);

	}

	system("pause");
	return 0;
}*/

/*
int main()
{
	int num, firstDigit, lastDigit;
	scanf("%d", &num);

	lastDigit = num % 10;
	firstDigit = num;

	while (firstDigit >= 10)
	{
		firstDigit = firstDigit / 10;
	}

	printf("First Digit = %d\n", firstDigit);
	printf("Last Digit = %d\n", lastDigit);
	system("pause");
	return 0;

}*/

/*
int main()
{
	int i, j, row;
	printf("row : \n");
	scanf("%d", &row);
	
	for ( i = 1; i <= row; i++)
	{
		for ( j = i; j < row; j++)
		{
			printf(" ");
		}
		printf("*");

		printf("\n");

	}

	system("pause");
	return 0;
}
*/
/*
int main(void) // girilen stringin karekter sayýsýný söyler.
{
	char isim[30];
	int i, boyut = 0;
	printf("Isim giriniz:");
	scanf("%s", isim);
	for (i = 0; isim[i] != '\0'; i++)
		boyut++;
	printf("Girdiginiz isim %s, %d karakterden olusmaktadir. \n", isim, boyut);
	system("pause");
	return 0;
}*/
/*
int main(void)
{
	char isim[30];
	int i;
	printf("Isim giriniz: ");
	scanf("%s", isim);
	printf("Girdiginiz isim: ");
	for (i = 0; isim[i] != '\0'; i++)
		printf("%c", isim[i]);
	printf("\n");
	system("pause");
	return 0;
}*/

/*
int sum(int A[], int n)
{
	int *ptr, s = 0;
	for (ptr = A; ptr < &A[n]; ptr++)
	{
		s = s + *ptr;
	}
	return s;
}

void fun1(int a)
{
	a = 8;
	printf("In fun1 %d\n", a);
}

void fun2(int *a)
{
	*a = 8;
	printf("In fun1 %d\n", *a);
}
int main()
{
	int *p;
	float *q;

	int a = 16;
	float b = 17.5;
	int c[5] = { 9,8,7,6,5 };
	int s;

	p = &a;
	q = &b;

	printf("Address: %p\n", &a);
	printf("Value: %d\n", a);
	printf("-------------------\n");
	printf("Address: %p\n", p);
	printf("Value: %d\n", *p);
	printf("Address of ptr: %p\n", &p);

	printf("-------------------\n");
	printf("p:%p\n", p);
	p = p + 1;;
	printf("p+1: %p\n", p);

	printf("-------------------\n");
	printf("%d\n", c[0]);
	printf("%d\n", *c);
	printf("%p\n", c);

	printf("-------------------\n");
	p = c;
	printf("%p\n", p);
	printf("%d\n", *p);
	p = p + 1;;
	printf("%p\n", p);
	printf("%d\n", *p);

	printf("-------------------\n");
	printf("%d\n", sum(c, 5));

	printf("-------------------\n");
	s = 1;
	printf("Before fun1: %d\n", s);
	fun1(s);
	printf("After fun1: %d\n", s);

	printf("-------------------\n");
	printf("Before fun2: %d\n", s);
	fun2(&s);
	printf("After fun2: %d\n", s);
	
	system("pause");
	return 0;
}*/
