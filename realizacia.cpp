#include <iostream>
#include <fstream>
#include "Head2.0.h"

void Console::setName(const std::string& name) { this->name = name; }
void Console::setYear(int year) { this->year = year; }
void Console::setFormat(const std::string& format) { this->format = format; }
void Console::setCost(int cost) { this->cost = cost; }
std::string Console::getName() const { return name; }
int Console::getYear() const { return year; }
std::string Console::getFormat() const { return format; }
int Console::getCost() const { return cost; }

std::ostream& operator<<(std::ostream& os, const Console& console) {
    os << "Название: " << console.name 
       << ", Год выпуска: " << console.year 
       << ", Формат: " << console.format 
       << ", Цена: " << console.cost;
    return os;
}

std::istream& operator>>(std::istream& is, Console& console) {
    std::cout << "Введите название приставки: ";
    is >> console.name;
    std::cout << "Введите год выпуска приставки: ";
    is >> console.year;
    std::cout << "Введите формат приставки: ";
    is >> console.format;
    std::cout << "Введите стоимость приставки: ";
    is >> console.cost;
    return is;
}

namespace ConsoleOperations {

void createH(Console** arr, int* count) {
    std::ifstream file("список.txt");
    if (file.is_open()) {
        file.close();
    }

    *count = 5;
    *arr = new Console[*count];

    (*arr)[0] = Console("Sony PlayStation 5", 2020, "Стационарная приставка", 60000);
    (*arr)[1] = Console("Sony PlayStation 5 Slim", 2023, "Стационарная приставка", 52900);
    (*arr)[2] = Console("Sony PlayStation 5 Pro", 2024, "Стационарная приставка", 72000);
    (*arr)[3] = Console("Steam Deck OLED", 2023, "Портативная приставка", 78000);
    (*arr)[4] = Console("Lenovo Legion Go", 2023, "Портативная приставка", 83700);
}

void loadH(Console** arr, int* count) {
    std::ifstream file("список.txt", std::ios::binary);
    if (!file.is_open()) {
        *count = 0;
        delete[] *arr; // Освобождаем память, если она была выделена ранее
        *arr = nullptr;
        return;
    }

    file.read(reinterpret_cast<char*>(count), sizeof(int));

    *arr = new Console[*count];
    if (*arr == nullptr) {
        std::cerr << "Ошибка выделения памяти" << std::endl;
        file.close();
        *count = 0;
        return;
    }

    file.read(reinterpret_cast<char*>(*arr), sizeof(Console) * (*count));

    file.close();
}

void saveH(Console* arr, int count) {
    std::ofstream file("список.txt", std::ios::binary);
    file.write(reinterpret_cast<const char*>(&count), sizeof(int));
    file.write(reinterpret_cast<const char*>(arr), sizeof(Console) * count);
    file.close();
}

void displayH(Console* arr, int count) {
    for (int i = 0; i < count; i++) {
        std::cout << "[" << (i + 1) << ". " << arr[i] << "]" << std::endl;
    }
}

void searchH(Console* arr, int count) {
    std::string name;
    std::cout << "Введите название приставки: ";
    std::cin >> name;

    int year;
    std::cout << "Введите год выпуска приставки: ";
    std::cin >> year;

    for (int i = 0; i < count; i++) {
        if (arr[i].getName() == name && arr[i].getYear() == year) {
            std::cout << "[Найдено: " << arr[i] << "]" << std::endl;
            return;
        }
    }
    std::cout << "Извините, по вашему запросу ничего не найдено." << std::endl;
}

void addH(Console** arr, int* count) {
    Console* temp = new Console[*count + 1];
    for (int i = 0; i < *count; ++i) {
        temp[i] = (*arr)[i];
    }

    Console newConsole;
    std::cin >> newConsole; // Используем перегруженный оператор >>

    temp[*count] = newConsole;

    delete[] *arr;
    *arr = temp;
    (*count)++;
}

void delH(Console** arr, int* count) {
    int n;
    std::cout << "Введите номер товара, который хотите удалить: ";
    std::cin >> n;
    
    if (n <= 0 || n > *count) {
        std::cout << "Такого товара нет." << std::endl;
        return;
    }

    Console* temp = new Console[*count - 1];
    for (int i = 0, j = 0; i < *count; ++i) {
        if (i != n - 1) {
            temp[j++] = (*arr)[i];
        }
    }

    delete[] *arr;
    *arr = temp;
    (*count)--;
}

void editH(Console* arr, int count) {
    int n;
    std::cout << "Введите номер товара: ";
    std::cin >> n;
    
    if (n <= 0 || n > count) {
        std::cout << "Ничего не найдено." << std::endl;
        return;
    }

    Console* reConsole = &arr[n - 1];
    
    std::cout << "Введите новые данные для приставки:" << std::endl;
    std::cin >> *reConsole; // Используем перегруженный оператор >>
}
}
