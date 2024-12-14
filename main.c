#include <stdio.h>
#include <stdlib.h>
#include "head.h"
int main() {
	console *arr = NULL;
	int count = 0;
	loadH(&arr, &count);
	int n;
	do {
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("LabaMagazinchik 1.0\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Menu\n");
		printf("1. Сачать каталог товаров\n");
		printf("2. Показать каталог\n");
		printf("3. Добавитьтовар\n");
		printf("4. Удалить товар\n");
		printf("5. Отредактировать данные о товаре\n");
		printf("6. Поиск нужного товара\n");
		printf("0. Выход\n");
		scanf("%i", &n);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		switch (n) {
			case 1:
				creatH(&arr, &count);
				break;
			case 2:
				displayH(arr, count);
				break;
			case 3:
				addH(&arr, &count);
				break;
			case 4:
				delH(arr, &count);
				break;
			case 5:
				editH(arr, count);
				break;
			case 6:
				searchH(arr, count);
				break;
			case 0:
				printf("BB, пока, sayonara \n");
				save(arr, count);
				free(arr);
				break;
			default:
				printf("Не верный запрос. Попробуёте снова\n");
		}
	}
	while (n != 0);
	return 0;
}
