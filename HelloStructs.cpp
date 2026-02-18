#include <string>
#include <Windows.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>

using namespace std::chrono_literals;

std::mutex mainMutex;
std::vector<std::exception_ptr> exceptionsArray;

void ThrowException()
{
    throw std::exception("Путхон.");
}

// Функция, которая обрабатывает исключения параллельно
void ThreadTryCatch() 
{
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

	std::thread thr(ThreadTryCatch);
	thr.join();
	
	std::this_thread::sleep_for(2000ms);

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

    system("pause");
}

//      Mutex - mutual exclusion, то есть взаимное исключение
// Предоставляет функции для синхронизации одновременно выполняющихся потоков.
// Когда какой-либо поток, принадлежащий процессу, становится владельцем объекта mutex, последний переводится в новое состояние, которое принято называть неотмеченным. Если задача освобождает объект mutex, то его состояние переходит в отмеченное.
// Мьютексы являются элементарными двоичными семафорами с двумя состояниями (оимеченный объект и неотмеченный). Мьютекс отличается от семафора тем, что только владеющий им поток может его освобождать (переводить в отмеченное состояние)
// Задачи: 
// 1. Защита объект от доступа к нему других потоков
// 2. В конкретный момент только один поток может владеть объектом под мьютексом.
// 3. Если потоку нужен доступ к переменной под мьютексом, то этот поток заснет до тех пор, пока мьютекс не будет освобожден.
// Мьютекс используется для защиты данных от изменений в результате асинхронных изменений, однако могут появляться проблемы взаимной блокировки процессов, если данным инструментом пользоваться неправильно.

// У потока (thread) есть две полезные функции, позволяющие замедлять его выполнение:
// std::this_thread::sleep_for() - блокирует выполнение текущего потока в течение установленного периода


// std::this_thread::sleep_until() - блокирует выполнение текущего потока, пока не будет достигнут момент времени

//			Практика
// Поэкспериментировать с замедлением параллельного потока и попробовать заставить основной поток не успеть выполнить обработку исключений из другого потока