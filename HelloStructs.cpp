#include <string>
#include <Windows.h>
#include <iostream>
#include <vector>

struct Bullet
{
    double speed = 0;
    double damage = 0;
    float x, y = 0.0f;
    bool isActive = false;

    void Init(double speed, double damage, float x, float y)
    {
        this->speed = speed;
        this->damage = damage;
        this->x = x;
        this->y = y;
        isActive = true;
    }

    void Reset()
    {
        speed = 0;
        damage = 0;
        x = 0.0f;
        y = 0.0f;
        isActive = false;
    }
};

class ObjectPool
{
public:
    explicit ObjectPool()
    {
        objects.reserve(MAX_SIZE);
        freeObjects.reserve(MAX_SIZE);

        for (int i = 0; i < MAX_SIZE; i++)
        {
            std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>();
            objects.push_back(bullet);
            freeObjects.push_back(bullet.get());
        }
    }

    // Функция, возвращающая свободный объект из пула в Main
    Bullet* RentObject()
    {
        // Если есть доступные объекты в пуле, то берем объект и возвращаем его
        if (!freeObjects.empty())
        {
            Bullet* bullet = freeObjects.back(); // Выбираем свободный объект
            freeObjects.pop_back(); // Убираем объект, который только что взяли
            return bullet;
        }
        else // Если доступного объекта нет, то создаем новый, занося его в массив высвобожденных объектов
        {
            std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>();
            objects.push_back(bullet);
            return bullet.get();
        }
    }

    // Обнуляет значения объекта и возвращает в пул
    void ReturnObject(Bullet* obj)
    {
        obj->Reset();
        if (freeObjects.size() < MAX_SIZE) freeObjects.push_back(obj);
    }

    // Возвращает количество доступных объектов из пула
    int AvailableCount() const
    {
        return freeObjects.size();
    }
private:
    std::vector<std::unique_ptr<Bullet>> objects;
    std::vector<Bullet*> freeObjects; // свободный пул
    const unsigned int MAX_SIZE = 32;
};

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ObjectPool bulletPool;

    for (int i = 0; i < 100; i++)
    {
        Bullet* bullet = bulletPool.RentObject();
        bullet->Init(6, 7, 0, 0);
        std::cout << "Пуля " << i << " была запущена! Количество доступных пуль: " << bulletPool.AvailableCount() << std::endl;
        bulletPool.ReturnObject(bullet);
    }

    return 0;
}