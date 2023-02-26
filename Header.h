// Директива препроцессора, предназначенная для защиты от двойного подключения заголовочного файла.
#pragma once
// Не орет на Безопасность.
#define _CRT_SECURE_NO_WARNINGS 
// Подключение заголовочного файла, который позволяет работать с потоками ввода/вывода.
#include <iostream>
// Подключение заголовочного файла, для создания текстового интерфейса пользователя. Тут есть _getch().
#include <conio.h> 
// Подключение заголовочного файла, в котором содержатся прототипы функции SetConsoleCP(кодовая таблица) и SetConsoleOutputCP(кодовая таблица).
#include <windows.h>
// Подключение заголовочного файла, для использования стека.
#include <stack> 
// Подключение заголовочного файла, который предоставляет интерфейс для чтения/записи данных из/в файл.
#include <fstream>
// Подключение заголовочного файла, для работы со временем.
#include <chrono>
// Подключение заголовочного файла, для работа со строками. 
#include <string>
// Пространство имен, чтобы не было конфиликтов повторяющихся переменных.
using namespace std;
// Пространство имен, чтобы не было конфиликтов повторяющихся переменных.
using namespace std;
// Пространство имен, чтобы не было конфиликтов между временем.
using namespace chrono;
int Menu() 
{ 

	auto key = 0;
	int code;

	do {
		system("cls");
		key = (key + 3) % 3;
		if (key == 0) cout << "-> Задание 1." << endl;
		else  cout << "   Задание 1." << endl;

		if (key == 1) cout << "-> Задание 2." << endl;
		else  cout << "   Задание 2." << endl;

		if (key == 2) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;


		code = _getch();
		if ((code == 115) || (code == 119))
		{
			if (code == 115) key++;
			if (code == 119) key--;
		}
		else
			if (code == 224) {
				code = _getch();
				if (code == 80) key++;
				if (code == 72) key--;
			}

	} while (code != 13);
	system("cls");
	return key;
}
int Menu5()
{

	auto key = 0;
	int code;

	do {
		system("cls");
		key = (key + 6) % 6;
		if (key == 0) cout << "-> Создаем рандомное дерево." << endl;
		else  cout << "   Создаем рандомное дерево." << endl;

		if (key == 1) cout << "-> Вывод дерева в файл." << endl;
		else  cout << "   Вывод дерева в файл." << endl;

		if (key == 2) cout << "-> Вставка." << endl;
		else  cout << "   Вставка." << endl;

		if (key == 3) cout << "-> Удаление." << endl;
		else  cout << "   Удаление." << endl;

		if (key == 4) cout << "-> Поиск." << endl;
		else  cout << "   Поиск." << endl;

		if (key == 5) cout << "-> Назад." << endl;
		else  cout << "   Назад." << endl;


		code = _getch();
		if ((code == 115) || (code == 119))
		{
			if (code == 115) key++;
			if (code == 119) key--;
		}
		else
			if (code == 224) {
				code = _getch();
				if (code == 80) key++;
				if (code == 72) key--;
			}

	} while (code != 13);
	system("cls");
	return key;
}