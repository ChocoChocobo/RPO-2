#include <string>
#include <Windows.h>
#include <iostream>
#include <vector>

class Animal
{
public:
    virtual ~Animal() {}
    virtual void MakeSounds() const
    {
        std::cout << "Какое-то животное издает какой-то звук" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void MakeSounds() const override
    {
        std::cout << "Мяу-мяу!" << std::endl;
    }
};

class Bird : public Animal
{
public:
    void MakeSounds() const override
    {
        std::cout << "Чирик-чик!" << std::endl;
    }

    void Fly() const
    {
        std::cout << "Птица взлетела!" << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<std::unique_ptr<Animal>> zoo;
    zoo.push_back(std::make_unique<Cat>());
    zoo.push_back(std::make_unique<Bird>());

    for (auto& animal : zoo)
    {
        animal->MakeSounds();

        Bird* birdPointer = dynamic_cast<Bird*>(animal.get());
        if (birdPointer)
        {
            birdPointer->Fly();
        }
        else
        {
            std::cout << "Перечисляемое животное летать не умеет!" << std::endl;
        }
    }

    system("pause");
}

// Данный оператор применяется для получения указателя на наследуемый класс, чтобы иметь возможность работать с теми его элементами, которые по-другому не доступны.
// На примере рассматриваемых классов можно представить следующую ситуацию: необходимо расширить функционал класса за счет добавления новой функции. Ее объявление можно включить в класс Programmer, находящееся в заголовочном файле, а саму функцию определить в одном из своих исходных файлов.
// Для того, чтобы получить конкретный наследуемый объект класса используется оператор dynamic_cast, где в угловых скобках указывается указатель на тип данных, а в круглых - объект, от которого нужно получить указатель на тип данных
// Programmer* programmer = dynamic_cast<Programmer*>(employee);
// Таким образом, оператор dynamic_cast осуществляется две операции: проверяет выполнимо ли преобразование и если это так, выполняет его.
//-------------Интерфейс классов//-------------
/*class Employee // Базовый класс для работника
{
public:
    virtual int Salary();

};

class Manager : Employee // категория сотрудника менеджер
{
public:
    int Salary();

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
    // Для того, чтобы получить конкретный наследуемый объект класса используется оператор dynamic_cast, где в угловых скобках указывается указатель на тип данных, а в круглых - объект, от которого нужно получить указатель на тип данных
    Programmer* programmer = dynamic_cast<Programmer*>(employee);
}
//--------------------------*/

//      Практика
// Отладить программу и выяснить почему с проверкой на наличие указателя у объекта кошки в массиве не вызывается функция Fly(), а с отсутсвием проверки функция вызывается.