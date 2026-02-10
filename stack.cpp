#include "stack.h"

void push(element*& stack, int value)
{
	element* newElement = new element;
	newElement->value = value;

	// Если стек при добавлении пуст, задаем новый элемент, как первый
	if (!stack) stack = newElement;
	else
	{
		// Стек уже существует, новый элемент размещается на вершине
		newElement->next = stack;
		stack = newElement;
	}
}

bool pop(element*& stack, int& value)
{
	// Извлечение элемента из стека, если он не пуст
	if (!stack) return false;
	// Необходимо сохранять ссылку на самый верхний элемент
	element* ref = stack;
	value = stack->value;
	stack = stack->next; // смещение указателя на новую вершину
	delete ref;
	return true;
}

const int* peek(const element* stack)
{
	// Получение значения с вершины стека, если он не пуст
	if (!stack) return nullptr;
	return &stack->value;
}

element* NextElement(const element* element)
{

}

element* LastElement(const element* element)
{

}

void ClearStack(element*& stack)
{

}