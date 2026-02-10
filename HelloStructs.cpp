#include <string>
#include <Windows.h>
#include <iostream>
#include <ChocoChocobo/logger.cpp>

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

//template<typename T> 
//T Sum(T number1, T number2); 
//
//template<typename T>
//T Sum(T number1, T number2, string name);

template<typename T>
void TSwap(T& value1, T& value2);

template<typename T> decltype(auto) CountAverage(const T array[], const unsigned size)
{
    T result{};
    for (unsigned int i = 0; i < size; i++)
    {
        result += array[i];
    }
    return result / size;
}

// Синглтон класс логирования программы

// ГОСТ 19.001-77
int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*cout << "Int: " << Sum<int>(5, 5) << endl;
    cout << "Double: " << Sum < double > (5.5, 5.5) << endl;
    cout << "String: " << Sum<string>(string("5"), string("5")) << endl;
    
    int array[]{ 3, 5, 7, 9, 11, 13 };
    cout << "Int array: " << CountAverage(array, 6) << endl;
    double array1[]{ 3.3, 5.5, 7.7, 9.9, 11.11, 13.13 };
    cout << "Double array: " << CountAverage(array1, 6) << endl;
    char array2[]{ 'п', 'о', 'м', 'и', 'н', 'к', 'и'};
    cout << "Char array: " << CountAverage(array2, 7) << endl;*/

    Logger::GetInstance().Log("Привет!");
    Logger::GetInstance().Log("испугался не бойся!");
    Logger::GetInstance().Log("я друг!");
    Logger::GetInstance().Log("я!");
}

//template<typename T>
//T Sum(T number1, T number2)
//{
//    return number1 + number2;
//}
//
//template<typename T>
//T Sum(T number1, T number2, string name)
//{
//    cout << name << " сложил два числа! Получилось: " << number1 + number2;
//    return number1 + number2;
//}

template<typename T> void TSwap(T& value1, T& value2)
{
    T temp = value1;
    value1 = value2;
    value2 = temp;
}