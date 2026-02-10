#pragma once

struct element
{
	int value;
	element* next = nullptr; // указатель на следующий элемент
};

// Добавление элемента в стек
// Вершина стека изменяется после добавления элемента. Это значит, что параметр stack должен передаваться по ссылке!
void push(element*& stack, int value);

// Удаление элемента из стека с возвращением хранимого значения
bool pop(element*& stack, int& value);

// Получение значения самого верхнего элемента в стеке
// Возвращается константный указатль на поле верхнего элемента в стеке
const int* peek(const element* stack);

// Получение следующего элемента стека
// Указатель на элемент стека может быть nullptr, если в списке больше нет элементов
element* NextElement(const element* element);

// Получение последнего элемента стека
element* LastElement(const element* element);

// Удаление всего стека
// Указатель на стек изменяется, поэтому параметр передается по ссылке
void ClearStack(element*& stack);