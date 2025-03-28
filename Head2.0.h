#include <iostream>
#include <string>

class Console {
private:
    std::string name;
    int year;
    std::string format;
    int cost;

public:
    Console();
    Console(const std::string& name, int year, const std::string& format, int cost);
    
    std::string getName() const;
    int getYear() const;
    std::string getFormat() const;
    int getCost() const;

    void setName(const std::string& name);
    void setYear(int year);
    void setFormat(const std::string& format);
    void setCost(int cost);

    friend std::ostream& operator<<(std::ostream& os, const Console& console);
    friend std::istream& operator>>(std::istream& is, Console& console);
};

namespace ConsoleOperations {
    void createH(Console** arr, int* count);
    void loadH(Console** arr, int* count);
    void saveH(Console* arr, int count);
    void displayH(Console* arr, int count);
    void searchH(Console* arr, int count);
    void addH(Console** arr, int* count);
    void delH(Console** arr, int* count);
    void editH(Console* arr, int count);
}