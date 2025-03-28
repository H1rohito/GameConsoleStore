#include <iostream>
#include "Head2.0.h"

using namespace std;
using namespace ConsoleOperations;

int main() {
    Console* arr = nullptr;
    int count = 0;

    loadH(&arr, &count);
    if (count > 0 && arr == nullptr) {
        cerr << "Ошибка: не удалось загрузить данные!" << endl;
        return 1;
    }

    int n;
    do {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "LabaMagazinchik 1.0\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Menu\n";
        cout << "1. Создать каталог товаров\n"; 
        cout << "2. Показать каталог\n";
        cout << "3. Добавить товар\n";
        cout << "4. Удалить товар\n";
        cout << "5. Отредактировать данные о товаре\n";
        cout << "6. Поиск нужного товара\n";
        cout << "0. Выход\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

       
        cin >> n;
        if (cin.fail()) {
            cout << "Неверный ввод. Пожалуйста, введите число: ";
            cin.clear();
            char c;
            while (cin.get(c) && c != '\n');
            n = -1; 
        }

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

        switch (n) {
            case 1:
                createH(&arr, &count);
                break;
            case 2:
                displayH(arr, count);
                break;
            case 3:
                addH(&arr, &count);
                break;
            case 4:
                delH(&arr, &count); 
                break;
            case 5:
                editH(arr, count);
                break;
            case 6:
                searchH(arr, count);
                break;
            case 0:
                cout << "BB, пока, sayonara" << endl;
                saveH(arr, count);
                delete[] arr; 
                arr = nullptr;
                break;
            default:
                cout << "Не верный запрос. Попробуйте снова" << endl;
        }
    } while (n != 0);

    return 0;
}
