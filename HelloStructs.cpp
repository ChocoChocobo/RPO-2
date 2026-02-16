#include <string>
#include <Windows.h>
#include <iostream>

class Product
{
public:
    virtual ~Product() {}
    virtual std::string DoSomething() const = 0;
};

class SodaProduct : public Product
{
public:
    std::string DoSomething() const override
    {
        return "Пшшшшшшшшш";
    }
};

class CookiesProduct : public Product
{
public:
    std::string DoSomething() const override
    {
        return "Хрусть";
    }
};

class ProductFabric
{
public:
    ~ProductFabric() { };
    virtual Product* CreateProduct() const = 0;
    
    
    std::string FabricDoSomething() const
    {
        Product* product = this->CreateProduct();
        std::string result = "Фабрика произвела единицу продукта: " + product->DoSomething();
        delete product;
        return result;
    }
};

class SodaFactory : public ProductFabric
{
public:
    Product* CreateProduct() const override
    {
        return new SodaProduct{};
    }
};

class CookiesFactory : public ProductFabric
{
public:
    Product* CreateProduct() const override
    {
        return new CookiesProduct{};
    }
};

void OrderProduct(const ProductFabric& fabric)
{
    std::cout << fabric.FabricDoSomething() << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SodaFactory* sodaFactory = new SodaFactory();
    CookiesFactory* cookiesFactory = new CookiesFactory();

    OrderProduct(*sodaFactory);
    OrderProduct(*cookiesFactory);

    system("pause");
}