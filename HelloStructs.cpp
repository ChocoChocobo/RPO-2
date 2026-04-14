#include <string>
#include <Windows.h>
#include <iostream>
#include <vector>

// Виртуальный класс 
class Bird
{
public:
    virtual ~Bird(){}
    virtual std::string MakeSound() const = 0;
};

class Pigeon : public Bird
{
public:
    std::string MakeSound() const override
    {
        return "Уруру";
    }
};

class Seagull : public Bird
{
public:
    std::string MakeSound() const override
    {
        return "А-а-а";
    }
};

class Sparrow : public Bird
{
public:
    std::string MakeSound() const override
    {
        return "Чик-чирик";
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<std::unique_ptr<Bird>> birdsArray;
    birdsArray.push_back(std::make_unique<Sparrow>());
    birdsArray.push_back(std::make_unique<Pigeon>());
    birdsArray.push_back(std::make_unique<Seagull>());

    // Демонстрация полиморфизма
    for (auto& bird : birdsArray)
    {
        std::cout << bird->MakeSound() << std::endl;
    }

    system("pause");

    return 0;
}