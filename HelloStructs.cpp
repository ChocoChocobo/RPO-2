#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

template<typename Tid, typename Tlogin, typename Tpassword>
class Person
{
public:
    const static inline unsigned int MAX_AGE = 120;
    string name;
    unsigned int age;
    unsigned int* agePointer;

    explicit Person(Tid _id, string _name, int _age, string _passportData)
    {
        id = _id;

        if (_name == "Родин")
        {
            cout << "Неподходящие имя!" << endl;
            name = "Безымянный";
        }
        else name = _name;

        if (_age > MAX_AGE) age = MAX_AGE;
        else if (_age < 0) age = 0;
        else age = _age;

        agePointer = &age;
        passportData = _passportData;
        counter++;

        cout << "В танчики играете, " << name << ", м? (1, 0)" << endl;
        bool userInput;
        cin >> userInput;
        if (userInput)
        {
            cout << "Введите логин: " << endl;
            cin >> tanchikiLogin;
            cout << "Введите пароль: " << endl;
            cin >> tanchikiPassword;
        }
    }

    void PrintInfo() const;

    Person(Person& other)
    {
        name = other.name;
        age = other.age;
        agePointer = &age;
        passportData = other.passportData;
        educationLevel = other.educationLevel;
    }

    void SetPassportData(string _passportData)
    {
        passportData = _passportData;
    }

    void SetEducation(string _educationLevel)
    {
        educationLevel = _educationLevel;
    }

    string GetPassportData() const
    {
        return passportData;
    }

    static void GetCounter()
    {
        cout << counter << endl;
    }
    static inline unsigned int counter;

    Person& operator--()
    {
        *agePointer -= 1;
        return *this;
    }

    Person operator-(const Person& other) const
    {
        int temp = age - other.age;
        if (temp <= 0) temp = 0;
        return Person{name, temp, passportData};
    }    

    int operator+(int value)
    {
        return age + value;
    }

    bool operator==(const Person& other) const // на дз почему можно вызвать приватный passportData
    {
        if (name == other.name && age == other.age && passportData == other.passportData)
        {
            return true;
        }
        else return false;
    }

    bool operator>(const Person& other) const
    {
        return age > other.age;
    }

    
private:
    Tlogin tanchikiLogin;
    Tpassword tanchikiPassword;
protected:
    Tid id;
    string passportData;
    string educationLevel;
};

//Person operator+(const Person& person1, const Person& person2)
//{
//    int temp = person1.age + person2.age;
//    if (temp <= 0) temp = 0;
//    return Person{ person1.name, temp, person1.GetPassportData() };
//}
//
//ostream& operator<<(ostream& stream, const Person& person)
//{
//    stream << "Имя: " << person.name << ". Возраст: " << *person.agePointer << endl; return stream;
//}

template<typename Tid, typename Tlogin, typename Tpassword>
void Person<Tid, Tlogin, Tpassword>::PrintInfo() const
{
    cout << "ID: " << id << ". Имя: " << name << ". Возраст: " << *agePointer << endl;
    cout << "Серия и номер паспорта: " << passportData << endl;
    cout << "======================" << endl;
    cout << "Танчики логин: " << tanchikiLogin << endl;
    cout << "Танчики пароль: " << tanchikiPassword << endl;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Чтобы явно указать компилятору тип данных, которые передается в шаблон, необходимо использовать следующую форму записи:
    Person<string, string, string> chelovek1{ "brawl stars", "Leon", 17, "4444 666666" };
    //Person<int> chelovek2{ 0, "Zloy David B myte .", 10, "4444 666666" };
    //Person<double> chelovek3{ 36.6, "Alexey shopkeeper", 10, "4444 666666" };
    chelovek1.PrintInfo();
    //chelovek2.PrintInfo();
    //chelovek3.PrintInfo();
}

// Практика:
// 1. В классе Person создать одну переменную с балансом средств в банке и две новые шаблонные переменные: номер счета в банке, секретное слово/код для вывода средств. Инициалзация происходит в конструкторе при передаче параметров.
// 2. Объявить в классе функцию вывода средств, которая бы списывала со счета введенную пользователем сумму, спрашивая у него секретное слово/код. реализовать функцию вне класса.
// 3. Объявить в классе функцию смены банка и секретного слова, которая просит пользователя сначала ввести секретное слово/код от ынешнего банка, а затем задать новый банк и секретное слово/код