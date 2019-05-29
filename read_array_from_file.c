#include<stdio.h>
#include<stdlib.h>

/*
 * Этот код читает из файла в массив
 * 4
 * 0 4 0 0
 * 0 0 3 6
 * 0 0 2 0
 * 5 6 0 0
 * И определяет 4 как размер стороны
 * Нужен для упрощённого ввода данных при изучении графов
 */

int main()
{
	int size = 0;
	int ch;

	FILE *fp = fopen("g.dat", "r");
	fscanf(fp, "%d", &size);
	printf("size: %d\n", size);

	int** Arr = (int**)malloc(size*sizeof(int));
	for (int i = 0; i < size; ++i) {
		Arr[i] = (int*)malloc(size * sizeof(int));
	}

	for (int i = 0; i < size; ++i) {
		fseek(fp, 1, SEEK_CUR);
		for (int j = 0; j < size; ++j) {
			fseek(fp, 1, SEEK_CUR);
			ch = getc(fp);
			Arr[i][j] = (int)ch - '0';
			printf("%d", Arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
