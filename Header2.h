// Директива препроцессора, предназначенная для защиты от двойного подключения заголовочного файла.
#pragma once
// Подключение заголовочного файла.
#include "Header.h"
// Структура ФИО.
struct Initial
{
	string surname,
		name,
		patronymic;
};
// Структура номера группы.
struct NumberGroup
{
	short NomerGrup;
};
// Структура номера студента в списке группы.
struct NumberListOfGroup
{
	short NomerStudenta;
};
// Структура количества баллов.
struct AssessmentsStudents
{
	short Bal;
};
// Структура отметки внесения или изменения данных.
struct Time
{
	time_t day, mon, year, hour, min;
};
// Структура данных.
struct Data
{
	Initial _initial;
	NumberGroup _numbergroup;
	NumberListOfGroup _numberlistofgroup;
	AssessmentsStudents _assesmentsstudents;
	Time _time;
};
// Создаем новую запись о студенте.
void DataEntry(Data* (&d), int& n) // (&d) - Сылка на массив для выделения новой памяти // int& - Сылка на количество элементов
{

	cout << "Введите количество студентов для новой записи данных: ";
	while (!(cin >> n) || (cin.peek() != '\n')) // cin.peek - проверяет, достигнут ли конец потока входного файла
	{
		cin.clear();
		while (cin.get() != '\n'); //проверяет, является ли строка cin.get() пустой строкой
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}
	//выделяем память
	d = new Data[n];

	for (int i = 0; i < n; i++)
	{
		time_t now;
		struct tm nowLocal;
		now = time(NULL);
		nowLocal = *localtime(&now);
		d[i]._time.day = nowLocal.tm_mday;
		d[i]._time.mon = nowLocal.tm_mon + 1;
		d[i]._time.year = nowLocal.tm_year + 1900;
		d[i]._time.hour = nowLocal.tm_hour;
		d[i]._time.min = nowLocal.tm_min;

		cout << "Введите ФИО: ";
		while (!(cin >> d[i]._initial.surname) || (d[i]._initial.surname <= "А") || (d[i]._initial.surname >= "Я") && (d[i]._initial.surname >= "а") || (d[i]._initial.surname >= "я"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}

		while (!(cin >> d[i]._initial.name) || (d[i]._initial.name <= "А") || (d[i]._initial.name >= "Я") && (d[i]._initial.name >= "а") || (d[i]._initial.name >= "я"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}

		while (!(cin >> d[i]._initial.patronymic) || (d[i]._initial.patronymic <= "А") || (d[i]._initial.patronymic >= "Я") && (d[i]._initial.patronymic >= "а") || (d[i]._initial.patronymic >= "я"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}



		cout << "Введите номер группы: ";

		while (!(cin >> d[i]._numbergroup.NomerGrup) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}

		cout << "Введите номер студента в списке группы: ";
		while (!(cin >> d[i]._numberlistofgroup.NomerStudenta) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}

		cout << "Введите количество баллов: ";
		while (!(cin >> d[i]._assesmentsstudents.Bal) || (d[i]._assesmentsstudents.Bal > 200))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз. Оценивание( max = 200):" << endl;
		}

		cout << "________________________________________________" << endl;

	}
}
// Выводим.
void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{


		cout << "Данные №" << i + 1 << ":" << endl;
		cout << "ФИО: "
			<< d[i]._initial.surname << endl
			<< d[i]._initial.name << endl
			<< d[i]._initial.patronymic << endl;

		cout << "Номер группы: "
			<< d[i]._numbergroup.NomerGrup << endl;

		cout << "Номер студента в списке группы: "
			<< d[i]._numberlistofgroup.NomerStudenta << endl;

		cout << "Количество баллов: "
			<< d[i]._assesmentsstudents.Bal << endl;

		if (d[i]._assesmentsstudents.Bal >= 170)
		{
			cout << "Оценка: \"Отлично\"" << endl;
		}

		if (d[i]._assesmentsstudents.Bal < 170 && d[i]._assesmentsstudents.Bal >= 140)
		{
			cout << "Оценка: \"Хорошо\"" << endl;
		}

		if (d[i]._assesmentsstudents.Bal < 140 && d[i]._assesmentsstudents.Bal >= 100)
		{
			cout << "Оценка: \"Удовлетворительно\"" << endl;
		}
		if (d[i]._assesmentsstudents.Bal < 100)
		{
			cout << "Оценка: \"Неудовлетворительно\"" << endl;
		}

		cout << "Время: "
			<< d[i]._time.day << "."
			<< d[i]._time.mon << "."
			<< d[i]._time.year << "г."
			<< d[i]._time.hour << ":"
			<< d[i]._time.min << endl;


		cout << "________________________________________________" << endl;
	}
}
// Изменяем данные о студенте.
void DataChange(Data* (&d), int n)
{

	int _n;
	cout << "Введите номер данных студента (От 1 до " << n << "): ";

	while (!(cin >> _n) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}

	system("cls");
	if (_n > 0)
	{

		_n--;// Так как индексация идет от нуля в С++ а у нас от 1
		time_t now;
		struct tm nowLocal;
		now = time(NULL);
		nowLocal = *localtime(&now);
		d[_n]._time.day = nowLocal.tm_mday;
		d[_n]._time.mon = nowLocal.tm_mon + 1;
		d[_n]._time.year = nowLocal.tm_year + 1900;
		d[_n]._time.hour = nowLocal.tm_hour;
		d[_n]._time.min = nowLocal.tm_min;

		cout << "Введите ФИО: ";
		while (!(cin >> d[_n]._initial.surname) || (d[_n]._initial.surname <= "А") || (d[_n]._initial.surname >= "Я") && (d[_n]._initial.surname >= "а") || (d[_n]._initial.surname >= "я"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}

		while (!(cin >> d[_n]._initial.name) || (d[_n]._initial.name <= "А") || (d[_n]._initial.name >= "Я") && (d[_n]._initial.name >= "а") || (d[_n]._initial.name >= "я"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}

		while (!(cin >> d[_n]._initial.patronymic) || (d[_n]._initial.patronymic <= "А") || (d[_n]._initial.patronymic >= "Я") && (d[_n]._initial.patronymic >= "а") || (d[_n]._initial.patronymic >= "я"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}


		cout << "Введите номер группы: ";
		while (!(cin >> d[_n]._numbergroup.NomerGrup) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}

		cout << "Введите номер студента в списке группы: ";
		while (!(cin >> d[_n]._numberlistofgroup.NomerStudenta) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}

		cout << "Количество баллов: ";
		while (!(cin >> d[_n]._assesmentsstudents.Bal) || (d[_n]._assesmentsstudents.Bal > 200))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Ошибка ввода. Попробуйте ещё раз. Оценивание(max = 200):" << endl;
		}

		cout << "Время: "
			<< d[_n]._time.day << " " << d[_n]._time.mon << " " << d[_n]._time.year << " " << d[_n]._time.hour << " " << d[_n]._time.min << endl;


		system("cls");
		cout << "Данные изменены!" << endl;
	}
	else
		cout << "Номер введен не верно!" << endl;

}
// Сохраняем.
void SavingData(Data* d, int n, string students)
{

	//Создаем поток для записи
	ofstream record(students); //Открывет файл. 
	if (record) // если открылся
	{
		record << n << endl; // записывает количество данных

		for (int i = 0; i < n; i++)
		{
			record << d[i]._initial.surname << endl;;
			record << d[i]._initial.name << endl;;
			record << d[i]._initial.patronymic << endl;;


			record << d[i]._numbergroup.NomerGrup << endl;;

			record << d[i]._numberlistofgroup.NomerStudenta << endl;;

			record << d[i]._assesmentsstudents.Bal << endl;

			if (i < n - 1)//если элемент не последний то отступ на следующую строчку
				record << d[i]._time.day << d[i]._time.mon << d[i]._time.year << d[i]._time.hour << d[i]._time.min << endl;
			else // иначе без отступа
				record << d[i]._time.day << d[i]._time.mon << d[i]._time.year << d[i]._time.hour << d[i]._time.min;
		}
	}
	else

		cout << "Ошибка открытия файла!" << endl;


	record.close(); // закрываем файл
}
// Время изменений.
void Times(Data* d, int n)
{
	int enter = 0;
	int T;

	cout << "Введите день ";

	while (!(cin >> T) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}
	for (int i = 0; i < n; i++) {


		if (d[i]._time.day == T)
		{
			cout << "Данные №" << i + 1 << ":" << endl;
			cout << "ФИО: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;


			cout << "Номер группы: "
				<< d[i]._numbergroup.NomerGrup << endl;

			cout << "Номер студента в списке группы: "
				<< d[i]._numberlistofgroup.NomerStudenta << endl;

			cout << "Количество баллов: "
				<< d[i]._assesmentsstudents.Bal << endl;

			if (d[i]._assesmentsstudents.Bal >= 170)
			{
				cout << "Оценка: \"Отлично\"" << endl;
			}

			if (d[i]._assesmentsstudents.Bal < 170 && d[i]._assesmentsstudents.Bal >= 140)
			{
				cout << "Оценка: \"Хорошо\"" << endl;
			}

			if (d[i]._assesmentsstudents.Bal < 140 && d[i]._assesmentsstudents.Bal >= 100)
			{
				cout << "Оценка: \"Удовлетворительно\"" << endl;
			}
			if (d[i]._assesmentsstudents.Bal < 100)
			{
				cout << "Оценка: \"Неудовлетворительно\"" << endl;
			}

			cout << "Время: "
				<< d[i]._time.day << "." << d[i]._time.mon << "." << d[i]._time.year << "г." << " " << d[i]._time.hour << ":" << d[i]._time.min << endl;

			cout << "________________________________________________" << endl;

		}
		else
		{
			cout << "Студента под номером " << i + 1 << " в этот день не записан!" << endl;
			cout << "________________________________________________" << endl;


		}
	}
}
// Копирует весь масив.
void Copy(Data* (&d_n), Data* (&d_o), int n)
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i]; //присваивание даных массиву
	}
}
// Добавление студента.
void AddDate(Data* (&d), int& n)
{
	//временный массив данных
	Data* buf;
	//выделяем данные
	buf = new Data[n];
	//сохраняем в временный массив
	Copy(buf, d, n);
	//выделяем новую память на 1 больше. Так как добавили
	n++;
	d = new Data[n];
	Copy(d, buf, --n);// возвращаем данные которые были в buf в наш основной массив

	time_t now;
	struct tm nowLocal;
	now = time(NULL);
	nowLocal = *localtime(&now);
	d[n]._time.day = nowLocal.tm_mday;
	d[n]._time.mon = nowLocal.tm_mon + 1;
	d[n]._time.year = nowLocal.tm_year + 1900;
	d[n]._time.hour = nowLocal.tm_hour;
	d[n]._time.min = nowLocal.tm_min;

	cout << "Введите ФИО: ";

	while (!(cin >> d[n]._initial.surname) || (d[n]._initial.surname <= "А") || (d[n]._initial.surname >= "Я") && (d[n]._initial.surname >= "а") || (d[n]._initial.surname >= "я"))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}

	while (!(cin >> d[n]._initial.name) || (d[n]._initial.name <= "А") || (d[n]._initial.name >= "Я") && (d[n]._initial.name >= "а") || (d[n]._initial.name >= "я"))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}

	while (!(cin >> d[n]._initial.patronymic) || (d[n]._initial.patronymic <= "А") || (d[n]._initial.patronymic >= "Я") && (d[n]._initial.patronymic >= "а") || (d[n]._initial.patronymic >= "я"))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}


	cout << "Введите номер группы: ";
	while (!(cin >> d[n]._numbergroup.NomerGrup) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}

	cout << "Введите номер студента в списке группы: ";
	while (!(cin >> d[n]._numberlistofgroup.NomerStudenta) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}

	cout << "Введите количество баллов: " << endl;
	while (!(cin >> d[n]._assesmentsstudents.Bal) || (d[n]._assesmentsstudents.Bal > 200))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Попробуйте ещё раз. Оценивание(max = 200):" << endl;
	}

	cout << "________________________________________________" << endl;


	delete[]buf;
}
// Копирует один элемент массива.
void Copy(Data& d_n, Data& d_o)
{
	d_n._initial.surname = d_o._initial.surname;
	d_n._initial.name = d_o._initial.name;
	d_n._initial.patronymic = d_o._initial.patronymic;

}
// Сортировка по алфавиту.
void Sorting(Data* d, int n)
{
	// временная переменная
	Data buf;
	// сортировка методом пузырька
	for (int i = 0; i < n;i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//условие сортировки
			if (d[i]._initial.surname > d[j]._initial.surname)
			{
				Copy(buf, d[j]); // данные d[j] помещаем в buf
				Copy(d[j], d[i]); // меняем местами
				Copy(d[i], buf); // данные bud помещаем в d[i]
			}
			if (d[i]._initial.name > d[j]._initial.name)
			{
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
			if (d[i]._initial.patronymic > d[j]._initial.patronymic)
			{
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}

}
// Удаление данных студента.
void Delete(Data* (&d), int& n)
{
	int _n;
	cout << "Представлены данные студенты (от 1 до " << n << " ) выберите номер для удаления:";
	while (!(cin >> _n) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}
	_n--;
	//Проверка что ввели правильное значение
	if (_n >= 0 && _n < n)
	{
		//Временный масив
		Data* buf = new Data[n];

		Copy(buf, d, n); //скопировали в этот временный масив данные


		//Выделяем новую память
		--n; // так как удаляем нужно в основном массиве выделить память на 1 меньше
		d = new Data[n];// данные которые были в массиве удалятся для этого и нужен был временный массив buf
		int q = 0;
		//Запоминаем данные кроме ненужного
		for (int i = 0; i <= n; i++)
		{
			if (i != n) // есди элемент не является тем который мы хотим удалить
			{
				d[q] = buf[i]; // сохраняем данные из буфера в d[q]
				++q;

			}
		}
		system("cls");
		delete[]buf;
		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Номер введен не верно!" << endl;



}
// Вывод данных о успеваемости студентов.
void Assesment(Data* d, int n)
{
	int enter = 0;

	cout << "Выберите пункт: " << endl;
	cout << "1.Студенты, которые учатся на \"Отлично\"." << endl
		<< "2.Студенты, которые учатся на \"Хорошо\"." << endl
		<< "3.Студенты, которые учатся на \"Удовлетворительно\"." << endl
		<< "4.Студенты, которые учатся на \"Неудовлетворительно\"." << endl;


	while (!(cin >> enter) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}
	for (int i = 0; i < n; i++)
	{

		if (enter == 1)
		{
			if (d[i]._assesmentsstudents.Bal >= 170)
			{

				cout << "Данные №" << i + 1 << ":" << endl;
				cout << "ФИО: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;

				cout << "Номер группы: "
					<< d[i]._numbergroup.NomerGrup << endl;

				cout << "Номер студента в списке группы: "
					<< d[i]._numberlistofgroup.NomerStudenta << endl;

				cout << "Количество баллов: "
					<< d[i]._assesmentsstudents.Bal << endl;


				cout << "________________________________________________" << endl;
				break;

			}
			else
			{
				cout << "Студентов нет!" << endl;
			}
		}
		if (enter == 2)
		{
			if (d[i]._assesmentsstudents.Bal < 170 && d[i]._assesmentsstudents.Bal >= 140)
			{
				cout << "Данные №" << i + 1 << ":" << endl;
				cout << "ФИО: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;


				cout << "Номер группы: "
					<< d[i]._numbergroup.NomerGrup << endl;

				cout << "Номер студента в списке группы: "
					<< d[i]._numberlistofgroup.NomerStudenta << endl;

				cout << "Количество баллов: "
					<< d[i]._assesmentsstudents.Bal << endl;


				cout << "________________________________________________" << endl;
				break;
			}
			else
			{
				cout << "Студентов нет!" << endl;
			}

		}
		if (enter == 3)
		{
			if (d[i]._assesmentsstudents.Bal < 140 && d[i]._assesmentsstudents.Bal >= 100)
			{
				cout << "Данные №" << i + 1 << ":" << endl;
				cout << "ФИО: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;


				cout << "Номер группы: "
					<< d[i]._numbergroup.NomerGrup << endl;

				cout << "Номер студента в списке группы: "
					<< d[i]._numberlistofgroup.NomerStudenta << endl;

				cout << "Количество баллов: "
					<< d[i]._assesmentsstudents.Bal << endl;


				cout << "________________________________________________" << endl;
				break;
			}
			else
			{
				cout << "Студентов нет!" << endl;
			}
		}
		if (enter == 4)
		{
			if (d[i]._assesmentsstudents.Bal < 100)
			{
				cout << "Данные №" << i + 1 << ":" << endl;
				cout << "ФИО: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;


				cout << "Номер группы: "
					<< d[i]._numbergroup.NomerGrup << endl;

				cout << "Номер студента в списке группы: "
					<< d[i]._numberlistofgroup.NomerStudenta << endl;

				cout << "Количество баллов: "
					<< d[i]._assesmentsstudents.Bal << endl;


				cout << "________________________________________________" << endl;
				break;
			}
			else
			{
				cout << "Студентов нет!" << endl;
			}
		}
	}




}
// Меню 2 задания.
int MenuEnter4() { //вывод меню, управляемого стрелками

	auto key = 0;
	int code;
	do {
		system("cls");
		key = (key + 8) % 8;
		if (key == 0) cout << "-> Создание новой записи о студенте." << endl;
		else  cout << "   Создание новой записи о студенте." << endl;

		if (key == 1) cout << "-> Внесение изменений в уже имеющуюся запись." << endl;
		else  cout << "   Внесение изменений в уже имеющуюся запись." << endl;

		if (key == 2) cout << "-> Вывод всех данных о студентах." << endl;
		else  cout << "   Вывод всех данных о студентах." << endl;

		if (key == 3) cout << "-> Вывод данных студентов по времени" << endl;
		else  cout << "   Вывод данных студентов по времени" << endl;

		if (key == 4) cout << "-> Добавить нового студента" << endl;
		else  cout << "   Добавить нового студента" << endl;

		if (key == 5) cout << "-> Удаление данных студента" << endl;
		else  cout << "   Удаление данных студента" << endl;

		if (key == 6) cout << "-> Успеваемость студентов" << endl;
		else  cout << "   Успеваемость студентов" << endl;

		if (key == 7) cout << "-> Главное меню" << endl;
		else  cout << "   Главное меню" << endl;


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
// Функция работы с меню 2 задания.
void MainEnter1()
{
	List L;
	int n = 0;
	int* a = new int[n];
	auto exit = 0;
	int _actions, amountOfData = 0; //Переменная которая указывает количество данных
	//Массив данных
	Data* d = new Data[amountOfData]; //указатель который указывает на массив

	do {
		const auto answer = MenuEnter4();

		switch (answer)
		{

		case 0:
		{
			system("cls"); //Очистка консоли

			DataEntry(d, amountOfData); //создаем новую запись о студент(-е, ах)(Массив, Количество данных)

			SavingData(d, amountOfData, "students.txt"); //сохранение в файл students

			if (amountOfData != 0)
			{
				Print(d, amountOfData); //вывод
			}
			else
				cout << "О записей ни слуху ни духу!" << endl;

			system("Pause"); // Задержка консоли
			system("cls"); // очистка консоли

			break; // Ломаем
		}
		case 1:
		{
			system("cls");
			if (amountOfData != 0)
			{
				DataChange(d, amountOfData); //изменение данных о студенте
				SavingData(d, amountOfData, "students.txt"); // сохранение в файл students
			}
			else
				cout << "О записей ни слуху ни духу!" << endl;
			Print(d, amountOfData); // вывод
			system("Pause");
			system("cls");
			break;
		}

		case 2:
		{
			system("cls");
			if (amountOfData != 0)
			{
				Sorting(d, amountOfData); // сортируем по алфавиту
				Print(d, amountOfData); // выводим
				SavingData(d, amountOfData, "students.txt");
			}
			else

				cout << "О записей ни слуху ни духу!" << endl;
			system("Pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			if (amountOfData != 0)
			{
				Times(d, amountOfData);
			}
			else
				cout << "О записей ни слуху ни духу!" << endl;

			system("Pause"); // Задержка консоли
			system("cls");

			break;
		}
		case 4:
		{
			system("cls");
			if (amountOfData != 0)
			{
				AddDate(d, amountOfData); // Добавить студента
				amountOfData++;
				SavingData(d, amountOfData, "students.txt"); // сохранение
			}
			else
				cout << "О записей ни слуху ни духу!" << endl;
			system("Pause"); // Задержка консоли
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			if (amountOfData != 0)
			{
				Delete(d, amountOfData);
			}
			else
				cout << "О записей ни слуху ни духу!" << endl;
			system("Pause"); // Задержка консоли
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			if (amountOfData != 0)
			{
				Assesment(d, amountOfData);
			}
			else
				cout << "О записей ни слуху ни духу!" << endl;
			system("Pause"); // Задержка консоли
			system("cls");
			break;
		}
		case 7:
		{
			exit = 1;
		}
		default:;
		}
	} while (exit == 0);
}