#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int factorial(int n)
{
	if (n == 1)
	{
		return n;
	}
	else
	{
		return n * factorial(n - 1);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf_s("Введите число, факториал которого вы хотите вычислить:\n");
	int number = 0;
	scanf_s("%d", &number);
	printf_s("Факториал числа %d = %d", number, factorial(number));
	getchar();
	getchar();
}
