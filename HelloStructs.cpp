#include <string>
#include <Windows.h>
#include <iostream>

// Класс с чистыми виртуальными функциями (интерфейс). Определяет поведение, которое изменяется с помощью декоратора
class Component
{
public:
    virtual ~Component(){}
    virtual std::string DoSomething() = 0;
};

// Класс, реализующий поведение по умолчанию. У этого класса может быть несколько вариаций
class PartComponent : public Component
{
public:
    std::string DoSomething() override
    {
        return "Defualt PartComponent";
    }
};

// Следует тому же интерфейсу, что и другие компоненты. Определяет обертку для всех конкретных декораторов
class Decorator : public Component
{
public:
    Decorator(Component* component)
    {
        this->component = component;
    }
    std::string DoSomething() override
    {
        return component->DoSomething();
    }
protected:
    Component* component;
};

// Конкретные декораторы вызывают обернутый объект и изменяют его результат.
// Декораторы могут вызывать родительскую реализацию операции, вместо того, чтобы вызвать обернутый объект напрямую
class Minion : public Decorator
{
public:
    Minion(Component* component) : Decorator(component) {}
    std::string DoSomething() override
    {
        // При наследовании обращение к родителю идет через оператор области видимости, поскольку поля с объектом класса в текущем классе нет.
        return "Minion сделал: " + Decorator::DoSomething();
    }
};

// Функция, работающая  со всеми объектами, использующая интерфейс компонента.Функция независима от конкретных классов компонентов с которыми работает
void GuideMinion(Component* component)
{
    std::cout << "Результат работы миньона: " << component->DoSomething();
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Поддержка простых компонентов:
    Component* componentA = new PartComponent;
    GuideMinion(componentA);
    std::cout << std::endl << "==================" << std::endl;

    // Поддержка декоративных компонентов:
    Component* decoratorA = new Minion(componentA);
    GuideMinion(decoratorA);
    std::cout << std::endl << "==================" << std::endl;

    delete componentA;
    delete decoratorA;

    system("pause");
}

//      Практика
// 1. Переделать возврат DoSomething() у PartComponent, например, на "Дело сделано."
// 2. Создать новый класс поведения DoWork, который наследуется от Component и переопределяет функцию DoSomething(). Возвращать значение "Опять работа."
// 3. Продемонстрировать новый компонент в main()
// 4. Создать новый класс HumanRacist, который наследуется от Decorator и во многом повторяет класс Minion, только выводит, что что-то сделал HumanRacist.
// 5. Продемонстрировать новый декоратор в main()