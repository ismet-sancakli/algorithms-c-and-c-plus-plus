#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<stdint.h>


/*
int main()
{
	int i = 9;
	for (i--; i--; i--)
	
		printf(" i = %d\n", i);
	
	system("pause");
	return 0;

}*/

/*
int main(void)
{
	char str[][8] = { "BOOK","BOOKS","DANCE","DANCER" };
	int i, j, res = 0;
	for (i = 0; i < 4; i++) {

		for (j = 0; j < 8; j++) {
			res = res ^ str[i][j]; // ^ iþareti bitwise iþlemlerde xor anlamýna gelmektedir o yüzden burda ayný olan harfler birbirlerini götürüler ve sadece S ve R kalýr.
		}
		if (i == 1 || i == 3) {
			printf("Res = %c\n", res);
			res = 0;
		}
	}
	system("pause");
	return 0;
}*/

/*
#define PRINT(a)\
	printf(#a" is %d\n",a);\
	a = a << 3;\
	printf(#a " is %d\n",a);
int main(void)
{
	uint8_t x = 4;
	PRINT(x)
		system("pause");
		return 0;
}*/

#define NSTUDENT 10

typedef struct student {

	char type;
	char name_surname[50];
	int id;
	char course[7][100];
	char thesis[1000];
}STD;

int main()
{
	STD grad[NSTUDENT];
	char ch;
	int i;
	while (1)
	{
		printf("Enter a type for PHD 'P' for master 'M',name surname,id \n ");
		scanf("%s", &grad[0].type);
		while (getchar() != '\n');
		scanf("%s", &grad[0].name_surname);
		scanf("%d", &(grad[0].id));
		if (grad[0].type == 'P')
		{
			printf("Your thesis title please");
			scanf("%s", &grad[0].thesis);
		}
		else
		{
			printf("enter the your course please \n");
			for ( i = 0; i < 7; i++)
			{
				scanf("%s", &grad[0].course[i][100]);
			}
		}
		system("pause");
	}
	
	
	
	system("pause");
	return 0;
}