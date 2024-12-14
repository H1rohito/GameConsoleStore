#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void creatH(console **arr, int *count){
	FILE *file = fopen("список.txt","rb");
	*count = 5;
	*arr = ralloc(*arr, (*count + 1)* sizeof(console));
	strcpy((*arr)[0].name, "Sony PlayStation 5");
	(*arr)[0].year = 2020;
	strcpy((*arr)[0].format, "Стационарная приставка");
	(*arr)[0].cost = 60000;
        strcpy((*arr)[1].name, "Sony PlayStation 5 slim");
        (*arr)[1].year = 2023;
        strcpy((*arr)[1].format, "Стационарная приставка");
        (*arr)[1].cost = 52900;
        strcpy((*arr)[2].name, "Sony PlayStation 5 pro");
        (*arr)[2].year = 2024;
        strcpy((*arr)[2].format, "Стационарная приставка");
        (*arr)[2].cost = 72000;
        strcpy((*arr)[3].name, "Steam deck oled");
        (*arr)[3].year = 2023;
        strcpy((*arr)[3].format, "Портативная приставка");
        (*arr)[3].cost = 78000;
        strcpy((*arr)[4].name, "Lenovo legion Go");
        (*arr)[4].year = 2023;
        strcpy((*arr)[4].format, "Портативная приставка");
        (*arr)[4].cost = 83700;
		return;
}
void loadH(console **arr, int *count){
	FILE *file = fopen("список.txt", "rb");
	if (!file){
		*count = 0;
		*arr = NULL;
		return;
	}
	fread(count, sizeof(int), 1, file);
	*arr = malloc((*count) * sizeof(console));
	fread(*arr, sizeof(console), *count, file);
	fclose(file);
}
void saveH(console *arr, int count){
	FILE *file = fopen("список.txt", "wb");
	fwrite(&count, sizeof(int), 1, file);
	fwrite(arr, sizeof(console), count, file);
	fclose(file);
}
void displayH(console *arr, int count){
	for (int i = 0; i < count; i++){
		printf("[%i. Название: %s; Год выпуска: %i; Формат: %s; Цена: %d]\n", i + 1, arr[i].name, arr[i].year, arr[i].format, arr[i].cost);
	}
}
void searchH(console *arr, int count){
	char name[25];
	printf("Введите название приставки: ");
	scanf("%s", name);
	int year;
	printf("Введите год выпуска приставки: ");
	scanf("%i", &year);
	for (int i = 0; i < count; i++){
		if (strcmp(arr[i].name, name) == 0 && arr[i].year == year){
			printf("[Название: %s; Год выпуска: %i; Формат: %s; Цена: %d]\n", arr[i].name, arr[i].year, arr[i].format, arr[i].cost);
			return;
		}
    }
		printf("Извините, по вашему запросу ничего не найдено \n");
}
void addH(console **arr, int *count){
	*arr = realloc(*arr, (*count + 1) * sizeof(console));
	console *newConsole = &(*arr)[*count];
	printf("Введите название приставки: \n");
	scanf("%s", newConsole->name);
	printf("Введите год выпуска приставки: \n");
	scanf("%d", &newConsole->year);
	printf("Введите формат приставки: \n");
	scanf("%s", newConsole->format);
	printf("Введите стоимость приставки: \n");
	scanf("%d", &newConsole->cost);
	(*count)++;
}
void delH(console **arr, int *count){
	int n;
	printf("Введите номер товара, который хотите удалить: ");
	scanf("%i", &n);
	if (n < 0 || n >= (count+1)){
		printf("Такого товара нет \n");
		return;
	}
	for (int i = (n-1); i < (*count); i++){
		arr[i] = arr[i + 1];
	}
	(*count)--;
	*arr = realloc(*arr, (*count) * sizeof(console));
}
void editH(console *arr, int count){
 	int n;
 	printf("Введите номер товара: ");
 	scanf("%i", &n);
 	if (n < 0, n >= (count+1)){
		printf("Ничего не найдено \n");
		return;
	}
		console *ReConsole = &arr[n-1];
		char name[20];
		printf("Введите новое название: ");
		scanf("%s", name);
		printf("Введите новый год выпуска пристаки  \n");
		int year;
		scanf("%d", &year);
		printf("Введите формат консоли(портативная/стационарная): ");
        char format[15];
        scanf("%s", format);
		printf("Введите новую цену: ");
        int cost;
		scanf("%d", &cost);
		strcpy(ReConsole->name, name);
		ReConsole->year = year;
		strcpy(ReConsole->format, format);
		ReConsole->cost = cost;
}













































