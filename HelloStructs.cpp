#include <string>
#include <Windows.h>
#include <iostream>
#include "stack.h"

void FillStack(element*& stack)
{
    for (int i = 0; i <= 20; i++)
    {
        push(stack, i);
    }
}

void PrintStack(const element* stack)
{
    // Ключевое слово авто настоятельно рекомендуется к использованию только в циклах и линейных списках! Компилятору гораздо удобнее самостоятельно определять тип данных, если он предсказуем, например в массивах или в линейных списках
    auto currentElement = stack; //  Получение указателя на вершину стека

}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


}