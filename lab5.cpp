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

int inputInteger()
{
	int input = 0;
	char c = '\0';
	while (scanf_s("%d%c", &input, &c, 1) != 2 || c != '\n')
	{
		system("cls");
		printf("\nИзвините, вы ввели некорректное значение.");
		printf("\nПопробуйте ввести значение снова\n");
		while (getchar() != '\n');
	}
	return input;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf_s("Введите число, факториал которого вы хотите вычислить:\n");
	int number = inputInteger(); // Теперь можно вводить только целочисленные значения
	printf_s("Факториал числа %d = %d", number, factorial(number));
	getchar();
	getchar();
}
