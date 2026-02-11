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
    auto currentElement = (element*)stack; //  Получение указателя на вершину стека
    auto lastElement = LastElement(stack);
    while (currentElement)
    {
        // Получение значения текущего элемента стека
        auto value = peek(currentElement);

        std::cout << *value << std::endl;

        // Выставление следующего элемента в стеке как текущего
        currentElement = NextElement(currentElement);
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    element* stack = nullptr;
    FillStack(stack);
    PrintStack(stack);
    ClearStack(stack);
    system("pause");
}