#include <string>
#include <Windows.h>
#include <iostream>
#include <list>

class IObserver // интерфейс для наблюдателя
{
public:
    virtual ~IObserver() {};
    virtual void Update(const std::string& message) = 0; // Функция, обновляющая поступающую информацию наблюдаемому
};

class ISubject // интерфейс для наблюдамого
{
public: 
    virtual ~ISubject() {};
    virtual void Subscribe(IObserver *observer) = 0; // Функция, подписывающая на наблюдателя
    virtual void UnSubscribe(IObserver *observer) = 0; // Функция, отписывающая от наблюдателя
    virtual void Notify() = 0; // Уведомить наблюдаемого
};

class Subject : public ISubject
{
public:
    ~Subject()
    {
        std::cout << "Наблюдаемый был очищен в памяти" << std::endl;
    }

    // Методы управления подпиской
    void Subscribe(IObserver* observer) override
    {
        observerList.push_back(observer);
    }

    void UnSubscribe(IObserver* observer) override
    {
        observerList.remove(observer);
    }

    void Notify() override
    {
        // Для того, чтобы определить свою единицу перечисления для такого типа данных, как список, создается итератор, а внего задается начальный объект списка
        std::list<IObserver*>::iterator iterator = observerList.begin();
        std::cout << "За объектом наблюдает" << observerList.size() << " наблюдателей" << std::endl;
        // Пока значение итератора не примет вид последнего объекта из списка
        while (iterator != observerList.end())
        {
            // Вызываем функцию Update у текущего перечисляемого наблюдателя
            (*iterator)->Update(message);
            ++iterator; // У объекта итератора перегружен оператор ++
        }
    }

    // Функция, при вызове которой задается новое сообщение (новое состояние) для наблюдаемого и происходит автоматическое уведомление наблюдателя через функцию Notify()
    void CreateMessage(std::string message)
    {
        this->message = message;
        Notify();
    }
private:
    std::list<IObserver*> observerList;
    std::string message;
};

class Observer : public IObserver
{
public:
    // Конструктор
    Observer(Subject& _subject) : subject(_subject)
    {
        // Наблюдаемый в классе наблюдателя подписывается на второго сразу же в конструкторе
        this->subject.Subscribe(this);
        std::cout << "Наблюдатель проинициализирован" << std::endl;
    }
    // Деструктор
    ~Observer()
    {
        std::cout << "Наблюдатель был очищен" << std::endl;
    }
    // Переопределенная Update
    void Update(const std::string& message) override
    {
        this->message = message;
        // Наблюдатель должен реагировать на поступаемое изменение
        std::cout << "У наблюдателя появилось новое сообщение от наблюдаемого: " << this->message << std::endl;
    }
    // Вспомогательная функция по управлению количеством наблюдаемых
    void UnsubscribeSubject()
    {
        subject.UnSubscribe(this);
        std::cout << "Наблюдаемый был отписан от наблюдателя!" << std::endl;
    }
private:
    Subject& subject;
    std::string message;
};

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Subject* subjectLeon = new Subject;
    Observer* observerGreka = new Observer(*subjectLeon);
    Observer* observerRak = new Observer(*subjectLeon);
    Observer* observerReka = new Observer(*subjectLeon);

    subjectLeon->CreateMessage("Ты ЛОХнесское чудовище");
    observerReka->UnsubscribeSubject();

    subjectLeon->CreateMessage("Я люблю крабов");
    observerRak->UnsubscribeSubject();

    subjectLeon->CreateMessage("Трусы");
    observerGreka->UnsubscribeSubject();

    delete observerGreka;
    delete observerRak;
    delete observerReka;
    delete subjectLeon;

    system("pause");
}

//      Практика
// 1. Сделать статическую переменную подсчета кол-ва созданных наблюдателей. Продемонстрировать в конструкторе номер создаваемого объекта
// 2. У наблюдателя создать поле с названием объекта, которое должно быть проинициализировано в констукторе. Выводить в консоль в строках у наблюдателя также его имя
// 3. В main просить пользователя просить считать 3 уравнения по очерди. Если уравнение решено неверно, то от наблюдаемого должен отписываться один фанат. Если к концу мини-игры у пользователю не остается фанатом, выводить злостное сообщение и создавать, подписывая на наблюдаемого, модератора твича.
// Прим.: У наблюдаемого должно быть новое поле с ответом, который дает пользователь в консоли. При поступлении нового сообщения наблюдателям, они должны проверять соответствует ли ответ правильным.