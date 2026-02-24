#include <string>
#include <Windows.h>
#include <iostream>

class Context;

// Включает в себя состояния программы и контекст, который может быть использован, как способ передать состояние другому объекту.
class State
{
public:
    ~State() {}
    // Публичный метод, позволяющий переключиться на конкретное состояние
    void SetContext(Context* context)
    {
        this->context = context;
    }
    virtual void DoSomething1() = 0;
    virtual void DoSomething2() = 0;
protected:
    Context* context;
};

// Определяет интерфейс, позволяющий клиентам обратиться к конкретному состоянию
class Context
{
public:
    Context(State* state)
    {
        this->TransitionToState(state);
    }
    // Контекст позволяет изменять состояние объекта с помощью этой функции
    void TransitionToState(State* state)
    {
        std::cout << "Происходит смена контекста на другое состояние" << typeid(*state).name() << std::endl;
        // Если присутствует состояние у контекста, очищаем память указателя на состояние и задаем новое
        if (this->state != nullptr)
        {
            delete this->state;
        }
        this->state = state;
        this->state->SetContext(this);
    }
    void Request1()
    {
        this->state->DoSomething1();
    }
    void Request2()
    {
        this->state->DoSomething2();
    }
    ~Context()
    {
        delete state;
    }
private:
    State* state;
};

class AttackState : public State
{
public:
    void DoSomething1() override;

    void DoSomething2() override
    {
        std::cout << "Атакует!" << std::endl;
    }
};

class DodgeState : public State
{
    // Переопределяемые функции, позволяющие выполнить специфичную логику, характерную для состояния. Например, логика нанесения урона врагу при состоянии атаки или повышение ловкости при состоянии уворота
public:
    void DoSomething1() override
    {
        std::cout << "Уворот!" << std::endl;
    }

    void DoSomething2() override
    {
        std::cout << "DodgeState обрабатывает запрос" << std::endl;
        std::cout << "DodgeState пытается изменить состояние контекста" << std::endl;

        this->context->TransitionToState(new AttackState);
    }
};

void AttackState::DoSomething1()
{
    std::cout << "AttackState обрабатывает запрос" << std::endl;
    std::cout << "AttackState пытается изменить состояние контекста" << std::endl;

    this->context->TransitionToState(new DodgeState);
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Context* context = new Context(new AttackState);
    // Первым состоянием выступает атака, которая атакует и переключается на состояние уворота.
    // КОНТЕКСТ АТАКИ
    context->Request2();
    context->Request1();
    // После переключения на уворот происходит его логику и обратное переключение на атаку
    // КОНТЕКСТ УВОРОТА
    context->Request1();
    context->Request2();

    system("pause");
}