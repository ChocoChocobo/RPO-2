#include <string>
#include <Windows.h>
#include <iostream>

class FlowerBoss
{
public:
    // Шаблонный метод
    void GiveOrder() const
    {
        this->CollectFlowers();
        this->SellFlowers();
        this->RequireCollectFlowers();
        this->RequireSellFlowers();
        this->RequirePackageFlowers();
    }
protected:
    void CollectFlowers() const
    {
        std::cout << "Цветочный босс говорит собрать цветы" << std::endl;
    }
    void SellFlowers() const
    {
        std::cout << "Цветочный босс говорит продать цветы" << std::endl;
    }
    virtual void RequireCollectFlowers() const {}
    virtual void RequireSellFlowers() const {}
    virtual void RequirePackageFlowers() const {}
};

class PlatonFlower : public FlowerBoss
{
protected:
    void RequireCollectFlowers() const override
    {
        std::cout << "Платон слушает и повинуется собирать цветы" << std::endl;
    }
    void RequireSellFlowers() const override
    {
        std::cout << "Платон слушает и повинуется продавать цветы" << std::endl;
    }
};

class SirFlower : public FlowerBoss
{
protected:
    void RequirePackageFlowers() const override
    {
        std::cout << "Сир цветок слушает и повинуется упаковывать цветы" << std::endl;
    }
};

void ManageWorker(FlowerBoss* flowerBoss)
{
    flowerBoss->GiveOrder();
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    PlatonFlower* platonFlower = new PlatonFlower;
    ManageWorker(platonFlower);

    SirFlower* sirFlower = new SirFlower;
    ManageWorker(sirFlower);
    delete platonFlower;

    system("pause");
}