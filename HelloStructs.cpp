#include <string>
#include <Windows.h>
#include <iostream>


//-------------Интерфейс классов//-------------
class Employee // Базовый класс для работника
{
public:
    virtual int Salary();
    virtual int Bonus();
};

class Manager : Employee // категория сотрудника менеджер
{
public:
    int Salary();
    int Bonus();
};

class Programmer : Employee // категория сотрудника программист
{
public:
    int Salary();
    int Bonus();
};

void Paycheck(Employee* employee) // внешняя функция, принимающая указатель на сотрудника и вызывающая функцию у указателя по выплате
{
    employee->Salary();
}
//--------------------------


int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //  static_cast и dynamic_cast
    // static_cast<тип_данных>(значение);
    // statics_cast преобразует значение в круглых скобках - value к типу, который указан в угловых скобках
    // dynamic_cast
    float x = 5.5;
    float y = 6.6;
    int result = static_cast<int>(y / x);

    system("pause");
}