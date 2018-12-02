#include "pch.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

// Работа 5.Вариант 19.
// Посчитать количество знаков пунктуации в строке, введенной с клавиатуры.

//Функция ввода строки


//Возвращает указатель на массив символов


char newIdea()
{
	printf("Внесены изменения!\n");
	//asfklajlskfj
}

char* inputStr()
{
	char *str = new char[1];  //Создаем указатель на массив символов длинной 1
	str[0] = '\0';
	printf("Введите строку: ");
	char ch = 0;
	while (true)
	{
		ch = _getch(); //Считываем символ без вывода его на экран


		if (ch == 13) //Если нажат Enter, выйти из цикла


		{
			printf("\n");
			break;
		}
		if (ch != '\0') //Если введен не символ конца строки(чтобы он не выводился на экран)
		{
			printf("%c", ch); //Вывести введенный символ на экран(в том числе перевести каретку, если нажат Backspace)
			if (ch == 8) //Если нажат Backspace:
			{
				printf("%c%c", 32, 8); //Вывести пробел и перевести каретку на один символ влево, чтобы сымитировать удаление символа


				int len = strlen(str); //Укоротить строку на 1 символ


				if (len != 0) //Если в строке только символ конца строки, то не делать ничего, иначе:
				{
					char *tmp = new char[len]; //Создать указатель на массив символов такой же длинны, как и str
					for (int i = 0; i < len; i++) //Скопировать из str в tmp все символы, кроме последнего в str
					{
						tmp[i] = str[i];
					}
					tmp[len - 1] = '\0'; //Последним символом поместить символ конца строки


					delete[] str;
					str = tmp;
				}
			}
			else //Если нажат символ


			{
				int len = strlen(str);
				char *tmp = new char[len + 2]; //Создать указатель на массив длинной на 2 больше, чем str
				                               //На 1 больше из-за нового символа и ещё на 1 больше из-за символа конца строки


				strcpy(tmp, str); //Копируем строку str в tmp
				tmp[len] = ch; //В предпоследний элемент tmp записываем новый символ


				tmp[len + 1] = '\0'; //В последний - символ конца строки


				delete[] str;
				str = tmp;
			}
		}
	}
	return str;
}

//Функция вывода текста во время валидации меню


void outputMenu()
{
	system("cls");
	printf("\t\tМеню\n\n");
	printf("Выберите нужную опцию:\n");
	printf("1. Ввод данных\n");
	printf("2. Обработка данных\n");
	printf("3. Вывод данных на экран\n");
	printf("4. Выход\n");
}

//Функция валидации ввода меню


//Возвращается корректное значение


int validation()
{
	const int limitMin = 1;
	const int limitMax = 4;
	char check = '\0';
	bool isOk = false;
	int value = 0;
	while (!isOk)
	{
		outputMenu();
		while (scanf("%d%c", &value, &check) != 2 || check != '\n')
		{
			outputMenu();
			while (getchar() != '\n');
		}
		if ((value < limitMin) || (value > limitMax))
		{
			isOk = false;
		}
		else
		{
			isOk = true;
		}
	}
	return value;
}

//Функция подсчета знаков препинания


//Подается указатель на массив символов


//Возвращает количество знаков препинания в строке


int countPunct(char* str)
{
	int len = strlen(str);
	int punct = 0;
	
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 33 || str[i] == 34 || str[i] == 40 || str[i] == 41 || str[i] == 44 || str[i] == 45 || str[i] == 46 || str[i] == 58 || str[i] == 59 || str[i] == 63)
		{
			punct++;
		}
	}
	return punct;
}

//Функция очистки памяти


//Получает указатель на массив символов


void wipeArr(char* str)
{
	if (str != NULL)
	{
		delete[] str;
	}
}

int main()
{
	SetConsoleCP(1251); //Меняем кодировки консоли для ввода


	SetConsoleOutputCP(1251); //Меняем кодировку консоли для вывода


	char* str = NULL;
	bool flag = true;
	int punct = 0;
	bool isChanged = false;
	while (flag)
	{
		system("cls");
		int menu = 0;
		menu = validation();
		if (menu == 1)
		{
			system("cls");
			printf("\t\t1. Ввод данных\n\n");
			wipeArr(str);
			str = inputStr();
			isChanged = false;
		}
		if (menu == 2)
		{
			system("cls");
			printf("\t\t2. Обработка данных\n\n");
			if (str == NULL)
			{
				printf("Строка не была введена!\n");
				printf("Нажмите Enter, чтобы вернуться в меню...");
				getchar();
			}
			else
			{
				punct = countPunct(str);
				printf("Обработка данных завершена!\n");
				printf("Нажмите Enter, чтобы вернуться в меню...");
				getchar();
			}
			isChanged = true;
		}
		if (menu == 3)
		{
			system("cls");
			printf("\t\t3. Вывод данных на экран\n\n");
			if (str == NULL)
			{
				printf("Строка не была введена!\n");
				printf("Нажмите Enter, чтобы вернуться в меню...");
				getchar();
			}
			else if (isChanged)
			{
				printf("Вы ввели: %s\n", str);
				printf("Знаков препинания в введенной строке: %d\n", punct);
				printf("Нажмите Enter, чтобы вернуться в меню...");
				getchar();
			}
			else
			{
				printf("Вы ввели: %s\n", str);
				printf("Знаки препинания ещё не были посчитаны\n");
				printf("Нажмите Enter, чтобы вернуться в меню...");
				getchar();
			}
		}
		if (menu == 4)
		{
			wipeArr(str);
			flag = !flag;
		}
	}
	_CrtDumpMemoryLeaks();
	getchar();
}
