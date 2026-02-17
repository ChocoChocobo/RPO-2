#include <string>
#include <Windows.h>
#include <iostream>

struct David
{
    explicit David(int) {}
    David(double) {}
};

struct Evangelion
{
    David david1, david2;
};

struct Leon
{
    int x;
    int y;
};

struct Platon {};

struct CPlusPlus
{
    CPlusPlus(Platon){}
};

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int x1 = 1; // Исторически сложившийся способ инициализации
    int x2(2);
    int x3{ 3 };
    int x4 = { 4 }; // Практически идентичен int x3{ 3 }
    auto x5{ 5 };

    char goida[5] {'g', 'o', 'i', 'd', 'a'};

    for (int i = 0; i < 5; i++)
    {
        std::cout << goida[i] << std::endl;
    }

    Leon leon = {  };
    std::cout << leon.x << leon.y << std::endl;
    if (leon.x)
    {
        std::cout << "Яблоко" << std::endl;
    }
    else
    {
        std::cout << "Тыблоко" << std::endl;
    }

    David david(5);
    David david1 = 5;
    
    CPlusPlus(Platon());

    system("pause");
}

// =========Практика=========
// Написать структуру координаты (Coordinate), имеющую в качестве полей три int точки (x, y, z) и функцию SetCoordinates, которая бы задавала точкам новое значение. Конструктор explicit. 
// В main() создать точки разными способам инициализации и вызвать функцию SetCoordinates у них.
// Примечание: по необходимости дополнить структуру полями, если возникнут ограничения при инициализации