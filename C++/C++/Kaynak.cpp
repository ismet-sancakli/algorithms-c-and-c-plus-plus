#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<conio.h>

/*
void towerOfHanoi(int n, char from_road, char to_road, char aux_road)
{
	if (n == 1)
	{
		printf("\n Move dics From road %c To Road %c", from_road, to_road);
		return;
	}
	towerOfHanoi(n - 1, from_road, aux_road, to_road);
	printf("\n Move discs %d from road %c to road %c", from_road, to_road);
	towerOfHanoi(n - 1, aux_road, to_road, from_road);
}

int main()
{
	int discs_number;
	printf("How many dics do you have : ?\n");
	scanf("%d", &discs_number);
	towerOfHanoi(discs_number, 'A', 'B', 'C'); // A,B and C are names are the road
}
*/


float faktoriyel(int);
float faktoriyel(int k)

{
	int i, f = 1;
	for (i = 2; i <= k; i++)
		f = f * i;
	return(f);
}

int main()
{
	int n, r;
	float per;
	printf("n degerini giriniz : ");
	scanf("%d", &n);
	printf("r degerini giriniz : ");
	scanf("%d", &r);

	per = faktoriyel(n) / faktoriyel(n - r);
	printf("Permutasyon sonucu : %f ", per);
	getch();
}