#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<process.h>
#include<math.h>


int main(void)
{
	char isim[30];
	int i, boyut = 0;
	printf("Isim giriniz:");
	scanf("%s", isim);
	for (i = 0; isim[i] != '\0'; i++)
		boyut++;
	printf("Girdiginiz isim %s, %d karakterden olusmaktadir. \n", isim, boyut);
	return 0;
}
