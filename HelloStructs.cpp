#include <string>
#include <Windows.h>
#include <iostream>

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::shared_ptr<std::string> stringPointer; // nullptr

    // Способ инициализаии с помощью специальной функции make_shared, предназначенной для этого
    std::shared_ptr<float> floatPointer = {std::make_shared<float>(36.6)};

    std::cout << stringPointer << std::endl;
    // У shared_ptr есть функция, возвращающая количество объектов, на которые он ссылается
    std::cout << floatPointer.use_count() << std::endl;

    std::cout << *floatPointer << std::endl;

    // Начиная с версии языка C++20 shared_ptr может указывать на массивы
    std::shared_ptr<int[]> intArrayPointer = {std::make_shared<int[]>(10)};
    std::cout << "Массив проинициализирован: ";
    for (int i = 0; i < 10; i++)
    {
        intArrayPointer[i] = i * 2;
        std::cout << " " << intArrayPointer[i] << " ";
    }
    std::cout << std::endl;

    system("pause");
}