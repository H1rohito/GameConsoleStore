#include <stdio.h>

typedef struct{
	char name[100];
	int year;
	char format[15];
	int cost;	
}console;

void displayH(console *arr, int count);
void searchH(console *arr, int count);
void addH(console **arr, int *count);
void delH(console **arr, int *count);
void editH(console *arr, int count);
void creatH(console **arr, int *count);
void loadH(console **arr, int *count);
void saveH(console *arr, int count);

