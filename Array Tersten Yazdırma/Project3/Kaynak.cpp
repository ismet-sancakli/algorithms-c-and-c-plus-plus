#define CRT_SECURE_NO_WARNNGS
#include<stdio.h>
#include<stdlib.h>

int func(int arr[], int index)
{
	if (index != 5)
	{
		index++;
		func(arr, index);
		printf("%d", arr[--index]);
		printf("\n");
	}
	return 0;
}

int main(void)
{
	int arr[5] = { 2,5,4,6,9 };
	func(arr, 0);
	system("pause");
	return 0;
}