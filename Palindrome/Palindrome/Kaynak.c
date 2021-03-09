#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<string.h>

 // Palindrome for words.
/*
int main(void)
{
	char kelime[30];
	int boyut = 0, i = 0, p = 1;
	printf("Bir kelime giriniz:");
	scanf("%s", kelime);
	for (i = 0; kelime[i] != '\0'; i++)
		boyut++;
	for (i = 0; i < boyut; i++)
	{
		if (kelime[i] != kelime[boyut - 1 - i])
			p = 0;
	}
	if (p == 1)
		printf("girdiginiz kelime palndromiktir.\n");
	else
		printf("girdiginiz kelime palindromik degildir.\n");
	system("pause");
	return 0;
}*/

// burada değişkenlerin adresleri ile gönderildiğini zaman değerlerin tamamen değiştiğini görüyoruz.
/*
int funn(int *j)
{
	*j += 3;
	return 4 * (*j) + 1;
}

void main()
{
	int x, y, z, v, result1, result2;

	x = 3;	y = 3;	z = 3;	v = 3;

	result1 = (x + 2)*funn(&x);
	printf("Result1 = %d\n", result1);
	printf("x = %d\n", x);

	result2 = funn(&y)*(y + 2);
	printf("Result2 = %d\n", result2);
	printf("y = %d\n", y);

	z = z + funn(&z);
	printf("z = %d\n", z);

	v = funn(&v) + v;
	printf("v = %d\n", v);

	system("pause");
}*/

/*
int main()
{
	int a, b = 7, c , d = 24, e = 3;
	a = b + (c = d / b++) - 1; // sonuc burada 9 çıkar sebebi b nin işlemler bittikten sonra artış göstermesi
	printf("b nin ilk islemden sonraki hali : %d\n", b);
	printf("ilk islemin sonucu :%d\n", a);
	a = b + (c = d / ++b) - 1; // Burada ise önce b arttırıldığı için b işleme 8 olarak girer ve sonuc 10 çıkar.
	printf("b nin ikinci islemden sonraki hali : %d\n", b);
	printf("ikinci islemin sonucu : %d\n", a);
	system("pause");
}*/






typedef struct node {
	char name[20];
	char surname[20];
	float grade;
}student;

void writefile() {

	FILE* f = fopen("students.txt", "w");
	fprintf(f, "Tony Stark 85.00\n");
	fprintf(f, "Natasha Romanoff  35.00\n");
	fprintf(f, "Carol Dnaver's 45.00\n");
	fprintf(f, "Peggy Carter 95.00\n");
	fprintf(f, "Steve Rogers 25.00\n");
	fprintf(f, "Bruce Banner 90.00\n");

}
void copystudent(student* target, student* source) {
	strcpy(target->name, source->name);
	strcpy(target->surname, source->surname);
	target->grade = source->grade;
}

int main() {

	writefile();
	student* temp = NULL, selected = NULL;
	temp = (student)malloc(sizeof(student));
	selected = (student)malloc(sizeof(student));
	FILE f = fopen("students.txt", "r");
	fscanf(f, "%s %s %f", selected->name, selected->surname, &selected->grade);
	while (!feof(f)) {
		fscanf(f, "%s %s %f", temp->name, temp->surname, &temp->grade);
		if (selected->grade == temp->grade)
			copystudent(selected, temp);
	}
	fclose(f);
	printf("%s %s: %.3f", selected->name, selected->surname, selected->grade);
}