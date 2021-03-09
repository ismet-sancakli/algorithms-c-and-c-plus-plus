#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <string.h>

int search(char codes[10][7], char target[], int size);

int main(void)

{
	char COLOR_CODES[10][7] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white" };
	float Resistance_value;
	char band1[7];
	char band2[7];
	char band3[7];
	int i, j, k;
	char question;

	
	printf("\nDo you want to decode resistor now (Type 'y' for yes, or 'n' for no)? ");
	printf("\n=> ");
	scanf("%c", &question);

	while (question == 'y')
	{
		printf("\nEnter the colors of the resistor's three bands, beginning with the band nearest the end.\n");
		printf("Type the colors in lowercase letters only, NO CAPS.\n\n");

		printf("Band 1 => ");
		scanf("%s", &band1);

		printf("Band 2 => ");
		scanf("%s", &band2);

		printf("Band 3 => ");
		scanf("%s", &band3);

		i = search(COLOR_CODES, band1, 10);
		j = search(COLOR_CODES, band2, 10);
		k = search(COLOR_CODES, band3, 10);

		Resistance_value = (10 * i + j)*(pow(10, k));

		if (i == -1 )
		{
			printf("Invalid colors : %s", i);
		}
		if (j == -1)
		{
			printf("Invalid colors : %s", j);
		}
		if (k == -1)
		{
			printf("Invalid colors : %s", k);
		}
		else
		{
			printf("Resistance value: %.0f ohms\n", Resistance_value);
		}
		scanf("%c", &question);
		printf("\nDo you want to decode another resistor (Type 'y' for yes, or 'n' for no)? ");
		printf("\n=> ");
		scanf("%c", &question);

	}


	system("pause");
	return 0;
}

int search(char codes[][7], char target[], int size)
{
	int x = 0;
	int match = 0;
	int location;

	while (!match && x < size)
	{
		if (strcmp(codes[x], target) == 0)
		{
			match = 1;
		}
		else
		{
			++x;
		}
	}

	if (match = 1)
	{
		location = x;
	}

	else
	{
		location = -1;
	}

	return(location);


}


//--------------------------------------------------------------------------1. question ------------------------------------------------


#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct {
	int atomic_number;
	char name[30];
	char chemical_symbol[3];
	char class[30];
	double atomic_weight;
	int electrons[7];
} element_t;

element_t scan_element(void);                           /* Input */
void print_element(element_t current_element);          /* Output */

int main(void)
{
	/* Displays instructions to the user. */
	printf("\nPick an element from the periodic table and enter the elements information down below.\n\n");
	char question;
	element_t a;
	element_t	e1 = { 1 , "hydrogen" , "H" , "Nonmetallic" , 1.008 , {1,0,0,0,0,0,0} },
		e2 = { 2 ,	"helium" , "He" , "Rare gas" , 4.0026, {2,0,0,0,0,0,0} },
		e3 = { 3 ,	"lithium" , "Li" , "Metal" , 6.94 , {2,1,0,0,0,0,0} },
		e4 = { 4 ,	"beryllium" , "Be" , "Metal" , 9.0122 , {2,2,0,0,0,0,0} },
		e5 = { 5 ,	"boron" , "B" , "Semi metal" , 10.81 , {2,3,0,0,0,0,0} },
		e6 = { 6 ,	"carbon" , "C" , "Nonmetallic" , 12.011 , {2,4,0,0,0,0,0} },
		e7 = { 7 ,	"nitrogen" , "N" , "Nonmetallic" , 14.007 , {2,5,0,0,0,0,0} },
		e8 = { 8 ,	"oxygen" , "O" , "Nonmetallic" , 15.999 , {2,6,0,0,0,0,0} },
		e9 = { 9 ,	"fluorine" , "F" , "Nonmetallic" , 18.998 , {2,7,0,0,0,0,0} },
		e10 = { 10 , "neon" , "Ne" , "Rare gas" , 20.180 , {2,8,0,0,0,0,0} },
		e11 = { 11 , "sodium" , "Na" , "Metal" , 22.990 , {2,8,1,0,0,0,0} },
		e12 = { 12 , "magnesium" , "Mg" , "Metal" , 24.305 , {2,8,2,0,0,0,0} },
		e13 = { 13 , "aluminum" , "Al" , "Metal" , 26.982 , {2,8,3,0,0,0,0} };

	printf("Would you like to check elment (Type 'y' for yes or 'n' for no)? :\n");
	scanf("%c", &question);


	while (question == 'y')

	{
		a = scan_element();
		if (a.atomic_number == e1.atomic_number)
		{
			print_element(e1);
		}
		else if (a.atomic_number == e2.atomic_number)
		{
			print_element(e2);
		}
		else if (a.atomic_number == e3.atomic_number)
		{
			print_element(e3);
		}
		else if (a.atomic_number == e4.atomic_number)
		{
			print_element(e4);
		}
		else if (a.atomic_number == e5.atomic_number)
		{
			print_element(e5);
		}
		else if (a.atomic_number == e6.atomic_number)
		{
			print_element(e6);
		}
		else if (a.atomic_number == e7.atomic_number)
		{
			print_element(e7);
		}
		else if (a.atomic_number == e8.atomic_number)
		{
			print_element(e8);
		}
		else if (a.atomic_number == e9.atomic_number)
		{
			print_element(e9);
		}
		else if (a.atomic_number == e10.atomic_number)
		{
			print_element(e10);
		}
		else if (a.atomic_number == e11.atomic_number)
		{
			print_element(e11);
		}
		else if (a.atomic_number == e12.atomic_number)
		{
			print_element(e12);
		}
		else if (a.atomic_number == e13.atomic_number)
		{
			print_element(e13);
		}
		else {
			printf("Enter atomic number between (1-13).  Because program have only 13 elements. \n");
		}

		scanf("%c", &question);
		printf("Would you like to check elment (Type 'y' for yes or 'n' for no)? :\n");
		scanf("%c", &question);

	}

	system("pause");
	return (0);
}

/* Gets input from user about an element and returns a element_t structure. */
element_t scan_element()
{
	int i;

	element_t element;

	printf("Enter the atomic number you are looking for :\n");
	scanf("%d", &element.atomic_number);



	return (element);
}

/* Prints out the information in the structure. */
void print_element(element_t current_element)
{
	int i = 0;

	printf("\n\n%d %s %s %s %.4f ", current_element.atomic_number, current_element.name,
		current_element.chemical_symbol, current_element.class, current_element.atomic_weight);

	for (i = 0; i < 7; i++) {
		printf(" %d", current_element.electrons[i]);
	}

	printf("\n\n");
}


