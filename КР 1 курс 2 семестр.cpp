// Подключение заголовочного файла с библиотеками и главное меню.
#include "Header.h"
// Подключение заголовочного файла с функциями для задания 1.
#include "Header1.h"
// Подключение заголовочного файла с функциями для задания 2.
#include "Header2.h"
// Подключение заголовочного файла с функциями для задания 1.
#include "Header3.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	auto exit = 0;
	do
	{
		const auto answer = Menu();

		switch (answer)
		{
			// Задание 1.
		case 0:
		{
			system("cls");
			MainEnter();
			break;
		}
		// Задание 2.
		case 1:
		{
			system("cls");
			MainEnter1();
			break;
		}
		case 2:
		{
			exit = 1;
		}
		default:;
		}
	} while (exit == 0);

}