#include <string>
#include <Windows.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <future>

using namespace std::chrono_literals;

std::mutex mainMutex;
std::vector<std::exception_ptr> exceptionsArray;

void ThrowException()
{
    throw std::exception("Лудка.");
}

// Функция, которая обрабатывает исключения параллельно
void AsyncLudovolk() 
{
	std::this_thread::sleep_for(3s);

	try
	{
		ThrowException();
	}
	catch (const std::exception& mutexException)
	{
		std::lock_guard<std::mutex> lock(mainMutex);
		exceptionsArray.push_back(std::current_exception());
	}
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	// future - планирование процесса асинхронного объекта async
	// Создается объект планирования процесса, в который помещается асинхронный объект с указанием протокола запуска и функции
	std::future<void> plannedProcess = std::async(std::launch::async, AsyncLudovolk);	

	// Симуляция работы основного потока
	for (int i = 0; i < 5; i++)
	{
		std::lock_guard<std::mutex> mainLock(mainMutex);
		if (exceptionsArray.empty()) std::cout << "Поток main работает, исключений нет..." << std::endl;
		else std::cout << "Поток main работает, исключение поймано!" << std::endl;

		std::this_thread::sleep_for(3s);
	}

	std::cout << "Работа main завершена. Фоновые процессы все еще выполняются" << std::endl;

	std::this_thread::sleep_for(3s);

	std::lock_guard<std::mutex> mainLock(mainMutex);
	for (auto& exception : exceptionsArray)
	{
		try
		{
			if (exception != nullptr)
			{
				std::rethrow_exception(exception);
			}
		}
		catch (const std::exception& mutexException)
		{
			std::cout << "Исключение поймано: " << mutexException.what() << std::endl;
		}
	}

	if (exceptionsArray.empty())
	{
		std::cout << "После ожидания исключений все еще нет :(" << std::endl;
	}

    system("pause");
}

//		Практика
// С помощью асинхронного выполнения в данной программе просимулировать использование заклинание замедления врага в битве:
// У игрока есть два действия: просто атаковать, применить заклинание замедления
// При получении ввода о действии при атаке происходит вывод информации в консоль, что игрок атаковал врага, а при замедлении написать, что замедлил
// После действия игрока действует враг. У врага вызывается асинхронная функция, где внутри проверяется флаг использовал ли игрок замедление. Если использовал, то заставлять врага атаковать через 3 секунды.