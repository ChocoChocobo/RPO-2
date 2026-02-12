#include <string>
#include <Windows.h>
#include <iostream>
#include "stack.h"

double Divide(int number1, int number2)
{
    if (!number2) // number2 == 0
    {
        throw 0; // выкидываем программе исключение типа данных int
    }
    if (number2 > number1)
    {
        throw std::string("Знаменатель больше числителя, дубина!");
    }
    return number1 / number2;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        std::cout << Divide(7, 8) << std::endl;
    }
    catch (const std::string& errorMessage) 
    {
        std::cout << "Возникла ошибка, ты дурень: " << errorMessage << std::endl;
    }
    catch(const int intMessage)
    {
        std::cout << "Возникла int-овая ошибка, ты дурень x2:" << intMessage << std::endl;
    }
    std::cout << "Я работаю дальше!" << std::endl;

    system("pause");
}

//      Практика
// 1. В функции Divide принимать параметры не int, а double
// 2. Обработать результат 1 при делении. Тип данных для throw - int
// 3. Обработать ситуацию, когда деление оставляет после себя остаток. Например, 5/2 = 2.5. Если хвостик .5 есть после деления - выкидывать программе обработку