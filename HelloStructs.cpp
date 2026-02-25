#include <string>
#include <Windows.h>
#include <iostream>

// вкладываемая видеокарта в класс-контейнер компьютера
class GPU
{
public:
    GPU() {}
    GPU(std::string modelName)
    {
        this->modelName = modelName;
    }
    void PrintInfo()
    {
        std::cout << "Видокарта: " << modelName << std::endl;
    }
    void StartGPU()
    {
        std::cout << "Видеокарта начала свою работу!" << std::endl;
    }
private:
    std::string modelName;
};

// вкладываемый процессор в класс-контейнер компьютера
class CPU
{
public:
    CPU() {}
    CPU(std::string modelName)
    {
        this->modelName = modelName;
    }
    void PrintInfo()
    {
        std::cout << "Процессор: " << modelName << std::endl;
    }
    void StartCPU()
    {
        std::cout << "Процессор начал свою работу!" << std::endl;
    }
private:
    std::string modelName;
};

// вкладываемая материнская плата в класс-контейнер компьютера
class MotherBoard
{
public:
    MotherBoard() {}
    MotherBoard(std::string modelName)
    {
        this->modelName = modelName;
    }
    void PrintInfo()
    {
        std::cout << "Материнская плата: " << modelName << std::endl;
    }
    void StartMotherBoard()
    {
        std::cout << "Материнская плата начала свою работу!" << std::endl;
    }
private:
    std::string modelName;
};

// Класс-контейнер для других объектов классов
class Computer
{
public:
    Computer(std::string gpuModelName, std::string cpuModelName, std::string motherModelName)
    {
        gpu = new GPU(gpuModelName);
        cpu = new CPU(cpuModelName);
        motherBoard = new MotherBoard(motherModelName);
    }
    void StartComputer()
    {
        gpu->StartGPU();
        cpu->StartCPU();
        motherBoard->StartMotherBoard();
    }
    void PrintSpecifications()
    {
        gpu->PrintInfo();
        cpu->PrintInfo();
        motherBoard->PrintInfo();
    }
private:
    GPU* gpu; // видеокарта
    CPU* cpu; // процессор
    MotherBoard* motherBoard; // материнская плата
};

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Computer computer("GTX 1080", "intel core i7", "ASUS ROG");
    computer.StartComputer();
    std::cout << "========" << std::endl;
    computer.PrintSpecifications();

    system("pause");
}

//          Практика
// Написать класс дерева, имеющий два поля (кол-во веток, вид дерева). 
// Написать класс леса с полем массива деревьев. Класс леса должен получать указатели на объекты деревьев извне через соответствующий метод.
// Если класс леса удаляется, то деревья должны продолжать существовать.
// Дополнительно реализовать вывод информации о том, что объект был создан или очищен в конструкторах и деструкторах, чтобы убедиться, что деревья продолжают существовать после удаления леса.

// Традиционно принято считать, что композиция - это создание объекта внутри класса (по значению). Агрегация - это создание объекта вне класса. При композиции объект класса не может существовать без класса-контейнера. При агрегации - может. 
// При каждом из этих способов, помимо создания объектов по значению, можно создавать их динамически, что будет являться более оптимальным способом работы с памятью.
// Композиция и агрегация почти идентичны. При композиции с созданием по значению происходит копирование объекта в поле класса. Агрегация по указателю работает напрямую с памятью, и создает объект прямо в классе. 
// Композиция по значению позволяет иметь два объекта (изначально созданный и скопированный), а агрегация по указателю один. Первый вариант отношения классов стоит применять, когда существует необходимость прослеживать изменения, который совершились с объектом класса после присоединения его в класс-контейнер.

//      Элементарными словами
// Композиция - создание объекта внутри класса. Агрегация - создание вне класса. У каждого из них может быть работа с указателями и со значениями.

// Пример по значению для композиции: 
//class Person
//{
//private:
//    Leg leg;
//};
//
//class Leg {};

// Пример с указателем для композиции:
//class Computer
//{
//public:
//    Computer(std::string gpuModelName, std::string cpuModelName, std::string motherModelName)
//    {
//        gpu = new GPU(gpuModelName);
//        cpu = new CPU(cpuModelName);
//        motherBoard = new MotherBoard(motherModelName);
//    }
//    void StartComputer()
//    {
//        gpu->StartGPU();
//        cpu->StartCPU();
//        motherBoard->StartMotherBoard();
//    }
//    void PrintSpecifications()
//    {
//        gpu->PrintInfo();
//        cpu->PrintInfo();
//        motherBoard->PrintInfo();
//    }
//private:
//    GPU* gpu; // видеокарта
//    CPU* cpu; // процессор
//    MotherBoard* motherBoard; // материнская плата
//};

// Пример по значению для агрегации:
//class Computer
//{
//public:
//    Computer(GPU gpu, CPU cpu, MotherBoard motherBoard)
//    {
//        this->gpu = gpu;
//        this->cpu = cpu;
//        this->motherBoard = motherBoard;
//    }
//    void StartComputer()
//    {
//        gpu.StartGPU();
//        cpu.StartCPU();
//        motherBoard.StartMotherBoard();
//    }
//    void PrintSpecifications()
//    {
//        gpu.PrintInfo();
//        cpu.PrintInfo();
//        motherBoard.PrintInfo();
//    }
//private:
//    GPU gpu; // видеокарта
//    CPU cpu; // процессор
//    MotherBoard motherBoard; // материнская плата
//};
//
//int main()
//{
//    setlocale(LC_ALL, "Ru");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    GPU gpu("GTX 1080");
//    CPU cpu;
//    MotherBoard motherBoard;
//    Computer computer(gpu, cpu, motherBoard);
//    computer.StartComputer();
//    std::cout << "========" << std::endl;
//    computer.PrintSpecifications();
//
//    system("pause");
//}

// Пример с указателем для агрегации:
//int main()
//{
//    setlocale(LC_ALL, "Ru");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    GPU* gpu = new GPU("GTX 1080");
//    CPU* cpu = new CPU();
//    MotherBoard* motherBoard = new MotherBoard();
//    Computer computer(gpu, cpu, motherBoard);
//    computer.StartComputer();
//    std::cout << "========" << std::endl;
//    computer.PrintSpecifications();
//
//    system("pause");
//}