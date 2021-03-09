#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct NUMBERS {
	int katsayi;
	int taban;
	int us;
	struct NUMBERS *next;
}NUMBERS;

void deleteNode(NUMBERS *key);
void addingNode(NUMBERS *temp);

NUMBERS *list = NULL; // to keep first element
NUMBERS *tail = NULL;

void Combine() {
	NUMBERS *temp = NULL;
	NUMBERS *temp1 = list;
	NUMBERS *temp2 = list;
	NUMBERS *garbage;

	while (temp1) {

		temp2 = temp1->next;

		while (temp2) {

			if (temp1->taban == temp2->taban && temp1->us == temp2->us) {

				if (temp2 == temp1->next) {
					temp = (NUMBERS*)malloc(sizeof(NUMBERS));
					temp->next = NULL;
					temp->taban = temp1->taban;
					temp->us = temp1->us;
					temp->katsayi = (temp1->katsayi) + (temp2->katsayi);
					addingNode(temp);
					garbage = temp1;
					temp1 = temp1->next->next;
					deleteNode(garbage);
					garbage = temp2;
					temp2 = temp2->next->next;
					deleteNode(garbage);
				}
				else {

					temp = (NUMBERS*)malloc(sizeof(NUMBERS));
					temp->next = NULL;
					temp->taban = temp1->taban;
					temp->us = temp1->us;
					temp->katsayi = (temp1->katsayi) + (temp2->katsayi);
					addingNode(temp);
					garbage = temp1;
					temp1 = temp1->next;
					deleteNode(garbage);
					garbage = temp2;
					temp2 = temp2->next;
					deleteNode(garbage);
				}

			}
			else {

				temp2 = temp2->next;
			}

		}
		temp1 = temp1->next;

	}

	temp1 = list;
	printf("New list after combine :\n");
	while (temp1) {
		printf("%d %d %d\n", temp1->katsayi, temp1->taban, temp1->us);
		temp1 = temp1->next;
	}

}
void Sum() {
	NUMBERS *temp = list;
	double sum = 0;
	printf("\n");
	while (temp) {
		sum = sum + (temp->katsayi)*pow(temp->taban, temp->us);
		printf("%dx%d^%d", temp->katsayi, temp->taban, temp->us);
		temp = temp->next;
		if (temp == NULL) {
			printf("= %.2lf\n", sum);
		}
		else {
			printf(" + ");
		}
	}
}


void deleteNode(NUMBERS *key) {
	NUMBERS *head = list;
	NUMBERS *temp = list->next;
	NUMBERS *garbage;
	
	
	if (list == key) {
		garbage = list;
		list = list->next;
		free(garbage);
	}
	else {
		while (temp != NULL) {
			if (temp == key) {
				garbage = temp;
				head->next = temp->next;
				free(garbage);
				break;
			}
			else {
				temp = temp->next;
				head = head->next;
			}
		
		}
		
		
	}
}

void addingNode(NUMBERS *temp) {


	if (list == NULL) {
		list = temp;

	}
	else {
		tail->next = temp;
	}
	tail = temp;

}
int main() {
	NUMBERS *temp = NULL;
	FILE *fp = fopen("numbers.txt", "r");
	temp = (NUMBERS*)malloc(sizeof(NUMBERS));
	temp->next = NULL;
	while (fscanf(fp, "%d %d %d", &temp->katsayi, &temp->taban, &temp->us) != EOF) {
		addingNode(temp);
		temp = (NUMBERS*)malloc(sizeof(NUMBERS));
		temp->next = NULL;
	}
	for (temp = list; temp; temp = temp->next) {
		printf("%d %d %d\n", temp->katsayi, temp->taban, temp->us);
	}
	printf("\n");
	Combine();
	Sum();

	system("pause");
	return 0;
}


