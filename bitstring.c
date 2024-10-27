#include <stdio.h>

void main() {
	int setA[100], sub_1[100], sub_2[100];
	int bit_array1[100] = {0}, bit_array2[100] = {0};
	int arr_OR[100], arr_AND[100];
	int size, size1, size2, i, j, temp;

	printf("Enter the size of the parent set:\n");
	scanf("%d", &size);

	printf("Enter the elements of the parent set:\n");
	for (i = 0; i < size; i++) {
		scanf("%d", &setA[i]);
	}

	printf("Enter the size of the 1st subset:\n");
	scanf("%d", &size1);

	printf("Enter the elements of the 1st subset:\n");
	for (i = 0; i < size1; i++) {
		scanf("%d", &sub_1[i]);
	}

	printf("Enter the size of the 2nd subset:\n");
	scanf("%d", &size2);

	printf("Enter the elements of the 2nd subset:\n");
	for (i = 0; i < size2; i++) {
		scanf("%d", &sub_2[i]);
	}

	for (i = 0; i < size1; i++) {
		temp = sub_1[i];
		for (j = 0; j < size; j++) {
			if (temp == setA[j]) {
				bit_array1[j] = 1;
				break;
			}
		}
	}

	for (i = 0; i < size2; i++) {
		temp = sub_2[i];
		for (j = 0; j < size; j++) {
			if (temp == setA[j]) {
				bit_array2[j] = 1;
				break;
			}
		}
	}

	printf("Elements of 1st bit array: ");
	for (i = 0; i < size; i++) {
		printf("%d ", bit_array1[i]);
	}
	printf("\n");

	printf("Elements of 2nd bit array: ");
	for (i = 0; i < size; i++) {
		printf("%d ", bit_array2[i]);
	}
	printf("\n");

	for (i = 0; i < size; i++) {
		arr_OR[i] = bit_array1[i] | bit_array2[i];
	}

	for (i = 0; i < size; i++) {
		arr_AND[i] = bit_array1[i] & bit_array2[i];
	}

	printf("Result of OR: ");
	for (i = 0; i < size; i++) {
		printf("%d ", arr_OR[i]);
	}
	printf("\n");

	printf("Result of AND: ");
	for (i = 0; i < size; i++) {
		printf("%d ", arr_AND[i]);
	}
	printf("\n");
}
