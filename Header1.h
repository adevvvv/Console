// Директива препроцессора, предназначенная для защиты от двойного подключения заголовочного файла.
#pragma once
// Подключение заголовочного файла.
#include "Header.h"
#include "Header3.h"
// Рандом чисел.
void Randomize(int* (&arr), int& N)
{
	cout << "Введите размерность массива: ";
	while (!(cin >> N) || (cin.peek() != '\n')) // cin.peek - проверяет, достигнут ли конец потока входного файла
	{
		cin.clear();
		while (cin.get() != '\n'); //проверяет, является ли строка cin.get() пустой строкой
		cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
	}
	// Создаем новый
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
}
struct Elem
{
	// Данные.
	int data;
	Elem* next, * prev;
};
class List
{
	// Голова, хвост
	Elem* Head, * Tail;
	// Количество элементов   
	int Count;

public:

	// Конструктор
	List();
	// Конструктор копирования
	List(const List&);
	// Деструктор
	~List();

	// Получить элемент списка
	Elem* GetElem(int);

	// Удалить весь список
	void DelAll();
	// Удаление элемента, если параметр не указывается, то функция его запрашивает
	void Del(int pos = 0);
	// Вставка элемента, если параметр не указывается,
	// то функция его запрашивает
	void Insert(int pos = 0);

	// Добавление в конец списка
	void AddTail(int n);

	// Добавление в начало списка
	void AddHead(int n);

	// Печать списка
	void Print();
	// Ответы в файл
	void PrintFile(string file);
	// Ответы в файл
	void PrintFileNum(int pos, string file);
	// Печать определенного элемента
	void Print(int pos);


};
// Конструктор.
List::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}
// Конструктор копирования.
List::List(const List& L)
{
	Head = Tail = NULL;
	Count = 0;

	// Голова списка, из которого копируем
	Elem* temp = L.Head;
	// Пока не конец списка
	while (temp != 0)
	{
		// Передираем данные
		AddTail(temp->data);
		temp = temp->next;
	}
}
// Деструктор.
List::~List()
{
	// Удаляем все элементы
	DelAll();
}
// Добавление в начало списка.
void List::AddHead(int n)
{
	// новый элемент
	Elem* temp = new Elem;

	// Предыдущего нет
	temp->prev = 0;
	// Заполняем данные
	temp->data = n;
	// Следующий - бывшая голова
	temp->next = Head;

	// Если элементы есть?
	if (Head != 0)
		Head->prev = temp;

	// Если элемент первый, то он одновременно и голова и хвост
	if (Count == 0)
		Head = Tail = temp;
	else
		// иначе новый элемент - головной
		Head = temp;

	Count++;
}
// Добавление в конец списка.
void List::AddTail(int n)
{
	// Создаем новый элемент
	Elem* temp = new Elem;
	// Следующего нет
	temp->next = 0;
	// Заполняем данные
	temp->data = n;
	// Предыдущий - бывший хвост
	temp->prev = Tail;

	// Если элементы есть?
	if (Tail != 0)
		Tail->next = temp;

	// Если элемент первый, то он одновременно и голова и хвост
	if (Count == 0)
		Head = Tail = temp;
	else
		// иначе новый элемент - хвостовой
		Tail = temp;

	Count++;
}
// Вставка элемента, если параметр не указывается, то функция его запрашивает.
void List::Insert(int pos)
{
	// если параметр отсутствует или равен 0, то запрашиваем его
	if (pos == 0)
	{

		while (!(cin >> pos) || (cin.peek() != '\n')) // cin.peek - проверяет, достигнут ли конец потока входного файла
		{
			cin.clear();
			while (cin.get() != '\n'); //проверяет, является ли строка cin.get() пустой строкой
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}
	}

	// Позиция от 1 до Count?
	if (pos < 1 || pos > Count + 1)
	{
		// Неверная позиция
		cout << "!!!\n";
		return;
	}

	// Если вставка в конец списка
	if (pos == Count + 1)
	{
		// Вставляемые данные
		int data;
		cout << "Введите новый номер: ";

		while (!(cin >> data) || (cin.peek() != '\n')) // cin.peek - проверяет, достигнут ли конец потока входного файла
		{
			cin.clear();
			while (cin.get() != '\n'); //проверяет, является ли строка cin.get() пустой строкой
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}
		// Добавление в конец списка
		AddTail(data);
		return;
	}
	else if (pos == 1)
	{
		// Вставляемые данные
		int data;
		cout << "Новый номер: ";

		while (!(cin >> data) || (cin.peek() != '\n')) // cin.peek - проверяет, достигнут ли конец потока входного файла
		{
			cin.clear();
			while (cin.get() != '\n'); //проверяет, является ли строка cin.get() пустой строкой
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}
		// Добавление в начало списка
		AddHead(data);
		return;
	}

	// Счетчик
	int i = 1;

	// Отсчитываем от головы n - 1 элементов
	Elem* Ins = Head;

	while (i < pos)
	{
		// Доходим до элемента, 
		// перед которым вставляемся
		Ins = Ins->next;
		i++;
	}

	// Доходим до элемента, 
	// который предшествует
	Elem* PrevIns = Ins->prev;

	// Создаем новый элемент
	Elem* temp = new Elem;

	// Вводим данные
	cout << "Введите элемент: ";
	cin >> temp->data;

	// настройка связей
	if (PrevIns != 0 && Count != 1)
		PrevIns->next = temp;

	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;

	Count++;
}
// Удаление элемента, если параметр не указывается, то функция его запрашивает.
void List::Del(int pos)
{
	// если параметр отсутствует или равен 0, то запрашиваем его
	if (pos == 0)
	{
		cout << "Введите: ";
		while (!(cin >> pos) || (cin.peek() != '\n')) // cin.peek - проверяет, достигнут ли конец потока входного файла
		{
			cin.clear();
			while (cin.get() != '\n'); //проверяет, является ли строка cin.get() пустой строкой
			cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
		}
	}
	// Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		// Неверная позиция
		cout << "!!!\n";
		return;
	}

	// Счетчик
	int i = 1;

	Elem* Del = Head;

	while (i < pos)
	{
		// Доходим до элемента, 
		// который удаляется
		Del = Del->next;
		i++;
	}

	// Доходим до элемента, 
	// который предшествует удаляемому
	Elem* PrevDel = Del->prev;
	// Доходим до элемента, который следует за удаляемым
	Elem* AfterDel = Del->next;

	// Если удаляем не голову
	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	// Если удаляем не хвост
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;

	// Удаляются крайние?
	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;

	// Удаление элемента
	delete Del;

	Count--;
}
// Печать элемента списка.
void List::Print(int pos)
{
	// Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		// Неверная позиция
		cout << "!!!!!\n";
		return;
	}

	Elem* temp;

	// Определяем с какой стороны 
	// быстрее двигаться
	if (pos <= Count / 2)
	{
		// Отсчет с головы
		temp = Head;
		int i = 1;

		while (i < pos)
		{
			// Двигаемся до нужного элемента
			temp = temp->next;
			i++;
		}
	}
	else
	{
		// Отсчет с хвоста
		temp = Tail;
		int i = 1;

		while (i <= Count - pos)
		{
			// Двигаемся до нужного элемента
			temp = temp->prev;
			i++;
		}
	}
	// Вывод элемента
	cout << pos << " Элемент: ";
	cout << temp->data << endl;
}
// Печать списка.
void List::Print()
{
	// Если в списке присутствуют элементы, то пробегаем по нему
	// и печатаем элементы, начиная с головного
	if (Count != 0)
	{
		Elem* temp = Head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}

		cout << temp->data << " )\n";
	}
}
// Удалить весь список.
void List::DelAll()
{
	// Пока остаются элементы, удаляем по одному с головы
	while (Count != 0)
		Del(1);
}
// Получить элемент списка.
Elem* List::GetElem(int pos)
{
	Elem* temp = Head;

	// Позиция от 1 до Count?
	if (pos < 1 || pos > Count)
	{
		// Неверная позиция
		cout << " !!!\n";
		return 0;
	}

	int i = 1;
	// Ищем нужный нам элемент
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}

	if (temp == 0)
		return 0;
	else
		return temp;
}
// Ответ в файл.
void SavingData(int* (&a), int& N, string file) // Сохранение данных
{
	//Создаем поток для записи
	ofstream record(file); //Открывет файл. 
	if (record) // если открылся
	{
		record << "Создание файла с ответами на задание." << endl << "Количество данных:";
		record << N << endl; // записывает количество данных

		for (int i = 0; i < N; i++)
		{

			record << a[i] << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	record.close(); // закрываем файл
}
// Ответ в файл.
void List::PrintFile(string file)
{
	//Создаем поток для записи
	ofstream record(file); //Открывет файл. 
	if (record) // если открылся
	{
		record << "Создание файла с ответами на задание." << endl;

		if (Count != 0)
		{
			Elem* temp = Head;
			record << "( ";
			while (temp->next != 0)
			{
				record << temp->data << ", ";
				temp = temp->next;
			}

			record << temp->data << " )\n";
		}
	}
	else

		cout << "Ошибка открытия файла!" << endl;


	record.close(); // закрываем файл
}
// Ответ в файл.
void List::PrintFileNum(int pos, string file)
{
	//Создаем поток для записи
	ofstream record(file); //Открывет файл. 
	if (record) // если открылся
	{
		record << "Создание файла с ответами на задание." << endl;

		// Позиция от 1 до Count?
		if (pos < 1 || pos > Count)
		{
			// Неверная позиция
			record << "!!!!!\n";
			return;
		}

		Elem* temp;

		// Определяем с какой стороны 
		// быстрее двигаться
		if (pos <= Count / 2)
		{
			// Отсчет с головы
			temp = Head;
			int i = 1;

			while (i < pos)
			{
				// Двигаемся до нужного элемента
				temp = temp->next;
				i++;
			}
		}
		else
		{
			// Отсчет с хвоста
			temp = Tail;
			int i = 1;

			while (i <= Count - pos)
			{
				// Двигаемся до нужного элемента
				temp = temp->prev;
				i++;
			}
		}
		// Вывод элемента
		record << pos << " Элемент: ";
		record << temp->data << endl;
	}
	else

		cout << "Ошибка открытия файла!" << endl;


	record.close(); // закрываем файл
}
// Определяет, меньшее ли преимущесто у 1-го из 2-х операторов.
boolean Advantage(char a, char b)
{
	short adv1, adv2;

	if (a == '*' || a == '/')
	{
		adv1 = 2;
	}
	else if (a == '+' || a == '-')
	{
		adv1 = 1;
	}
	else
	{
		adv1 = 0;
	}
	if (b == '*' || b == '/')
	{
		adv2 = 2;
	}
	else if (b == '+' || b == '-')
	{
		adv2 = 1;
	}
	else
	{
		adv2 = 0;
	}
	if (adv1 < adv2)
	{
		return true;
	}
	else
	{
		return false;
	}

}
// Проверяет одинаковые ли образы символов.
boolean CheckingTheSymbol(char a, char b)
{
	boolean smb1, smb2;
	if (a == '*' || a == '+' || a == '-' || a == '/')
	{
		smb1 = true;
	}
	else
	{
		smb1 = false;
	}
	if (b == '*' || b == '+' || b == '-' || b == '/')
	{
		smb2 = true;
	}
	else
	{
		smb2 = false;
	}

	if (smb1 == smb2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Считывает какой тип выражения и определяет ошибки.
int ExpressionArray(char* strinput)
{
	// 0 - ошибка, 1 - простое, 2 - прямое, 3 - обратное.
	int result = 0;
	int i = 0;
	int n = strlen(strinput);
	if (n > 1)
	{
		// Пропускает скобки в начале.
		while (strinput[i] == '(' && i != n)
		{
			i++;
		}
		// Определяет тип выражения.
		char c = strinput[i];
		// Если вначале идут знаки, то это прямое.
		if (c == '*' || c == '+' || c == '-' || c == '/')
		{
			result = 2;
		}
		else
		{
			// Ошибка, если после 1-ой скобки сразу идет вторая обратная скобка.
			if (c == ')')
			{
				result = 0;
			}
			else
			{
				char s = strinput[n - 1];
				// Если присутствуют знаки в конце, то это обратное.
				if (s == '*' || s == '+' || s == '-' || s == '/')
				{
					result = 3;
				}
				// Иначе - это простое.
				else
				{
					result = 1;
				}
			}
		}
		// В поисках ошибок.
		if (result != 0)
		{
			int braceopen = 0, braceclose = 0, operation = 0, operand = 0;
			for (int i = 0; i < n; i++)
				switch (strinput[i])
				{
				case '(':
				{
					braceopen++;
					break;
				}
				case ')':
				{
					braceclose++;
					break;
				}
				case '*': case '+': case '-': case '/':
				{
					operation++;
					break;
				}
				default:
				{
					operand++;
					break;
				}
				}

			// Несовпадение количества открывающих и закрывающих скобок.
			if (braceopen != braceclose)
			{
				result = 0;
			}
			// Несовпадение операндов и на один больше операторов.
			if (operand != (operation + 1))
			{
				result = 0;
			}
			// Подряд идущие одинаковые типы в простой записи.
			if (result == 1)
			{
				char* temp = new char[n];
				int x = -1;
				for (int i = 0; i < n; i++)
				{
					if (strinput[i] != '(' && strinput[i] != ')')
					{
						temp[++x] = strinput[i];
					}
				}

				for (int i = 0; i < x - 1; i++)
				{
					if (CheckingTheSymbol(temp[i], temp[i + 1]))
					{
						result = 0;
					}
				}
			}
		}
	}
	else
	{
		result = 0;
	}
	return result;
}
// Преобразование из простой в обратную(массив).
char* SimpleInReverseArray(char* simple)
{
	int n = strlen(simple);
	char* operand = new char[n];
	int arraycount = -1;
	char* result = new char[n + 1];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		operand[i] = '\0';
	}
	for (int i = 0; i < n; i++)
	{
		// Если знак операции.
		if (simple[i] == '*' || simple[i] == '+' || simple[i] == '-' || simple[i] == '(' || simple[i] == '/')
		{
			if (arraycount == -1 || (Advantage(operand[arraycount], simple[i])))
			{
				// Если приоритет меньше, то в стек.
				operand[++arraycount] = simple[i];
			}
			else
			{
				while (arraycount == -1 && !Advantage(operand[arraycount], simple[i]))
				{
					result[count++] = operand[arraycount];
					arraycount--;
				}
				operand[++arraycount] = simple[i];
			}

		}
		// Если закрывающая скобка то, содержимое стека до скобки - в строку.
		else if (simple[i] == ')')
		{
			while (operand[arraycount] != '(')
			{
				result[count++] = operand[arraycount];
				arraycount--;
			}
			arraycount--;
		}
		else
		{
			result[count++] = simple[i];
		}
	}
	while (arraycount == -1)
	{
		result[count++] = operand[arraycount];
		arraycount--;
	}
	result[count++] = '\0';
	return result;
	delete result;
	delete operand;
}
// Рекурсивное понижение, для прямой нотации
string Recursion(string s)
{
	string res;
	int n = s.length();
	if (s[0] == '(')
	{
		int pos = s.find(")");
		string sub;
		if (pos < s.length() - 1) sub = s.substr(pos + 2, s.length());
		int nn = sub.length();
		if (nn >= 3)
		{
			res += s.substr(pos + 1, 1)
				+ Recursion(s.substr(1, pos - 1))
				+ Recursion(sub);
		}
		else
		{
			res += s.substr(pos + 1, 1)
				+ Recursion(s.substr(1, pos - 1))
				+ sub;
		}
	}
	else
	{
		if (n > 3)
		{
			res += s.substr(1, 1) + s.substr(0, 1) + Recursion(s.substr(2, s.length()));
		}
		else
		{
			res += s.substr(1, 1) + s.substr(0, 1) + s.substr(2, s.length());
		}
	}
	return res;
}
// Преобразование из простой в прямую(массив).
char* SimpleInStraightArray(char* simple)
{
	int n = strlen(simple);

	char* result = new char[n + 1];

	string str = Recursion(string(simple));

	for (int i = 0; i < str.length(); i++) result[i] = str[i];

	result[str.length()] = '\0';

	return result;

	delete result;
}
// Проверка, не является ли числом.
boolean NotNumber(char ch)
{
	switch (ch)
	{
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		return false;
		break;

	default: return true;

	}
}
// Калькулятор для вычисления выражения(массив).
float CalculatorArray(char* reverse, int* variable)
{
	int len = strlen(reverse);
	char* operand = new char[len];
	float result = 0;
	int arraycount = -1;
	for (int i = 0; i < len; i++)
	{
		operand[i] = '\0';
	}
	int v = 0;
	for (int i = 0; i < len; i++)
	{
		if (reverse[i] == '*' || reverse[i] == '+' || reverse[i] == '-' || reverse[i] == '/')
		{
			int number1 = 0;
			int number2 = 0;

			number1 = operand[arraycount];
			arraycount--;

			number2 = operand[arraycount];
			arraycount--;

			if (reverse[i] == '*')
			{
				operand[++arraycount] = (number1 * number2);
			}
			if (reverse[i] == '+')
			{
				operand[++arraycount] = (number1 + number2);
			}
			if (reverse[i] == '-')
			{
				operand[++arraycount] = (number1 - number2);
			}
			if (reverse[i] == '/')
			{
				operand[++arraycount] = (number1 / number2);
			}
		}
		else
		{
			int number = 0;
			char ch = reverse[i];

			if (!NotNumber(reverse[i]))
			{
				number = atoi(&ch);
			}
			else
			{
				number = variable[v++];
			}

			operand[++arraycount] = number;
		}
	}

	return operand[arraycount];
}
// Определяет размер файла.
int FileSize(string path)
{
	ifstream file(path);
	file.seekg(0, ios_base::end);

	int filesize = file.tellg();

	file.close();

	return filesize;
}
// Загружает выражение из файла.
void LoadFile(char* buffer)
{

	ifstream file("Expression.txt");

	int filesize = FileSize("Expression.txt");

	if (filesize > 0)
	{
		file.get(buffer, filesize + 1);
		file.close();
	}
	else
	{
		cout << "Там походу файла нет!" << endl;
	}
}
// Преобразование из простой в прямую.
char* SimpleInStraight(char* simple)
{
	int n = strlen(simple);
	char* result = new char[n + 1];

	string str = Recursion(string(simple));

	for (int i = 0; i < str.length(); i++)
	{
		result[i] = str[i];
	}

	result[str.length()] = '\0';

	return result;

	delete result;
}
// Преобразование из простой в обратную, для файла с ответами
string SimpleInReverseFile(string simple)
{
	stack <char> operand;

	int n = simple.length();
	string result;
	string str = "Исходное выражение: " + simple + "\n";
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (simple[i] == '*' || simple[i] == '+' || simple[i] == '-' || simple[i] == '(' || simple[i] == '/')
		{
			if (operand.empty() || (Advantage(operand.top(), simple[i])))
				// Если приоритет меньше, то в стек.
				operand.push(simple[i]);
			else
			{
				while (!operand.empty() && !Advantage(operand.top(), simple[i]))
				{
					str = str + "Извлекаем из стека оператор и добавляем к выражению: " + operand.top() + "\n" +
						+"Выражение: " + result + "\n";
					result += operand.top();
					operand.pop();
				}

				str = str + "Добавляем оператор в стек: " + simple[i] + "\n Выражение: " + result + "\n";
				operand.push(simple[i]);
			}
		}
		// Если закрывающая скобка, то содержимое стека до скобки - в строку.
		else if (simple[i] == ')')
		{
			while (operand.top() != '(')
			{
				str = str + "Извлекаем из стека символы до скобки: " + operand.top() + "\n";
				result += operand.top();
				operand.pop();
			}
			operand.pop();
			str = str + "Выражение: " + result + "\n";
		}
		else
		{
			result += simple[i];
			str = str + "Добавляем операнд в выражение: " + simple[i] + "\n Выражение: " + result + "\n";
		}
	}

	while (!operand.empty())
	{
		str = str + "Пока стека не пуст добавлем его содержимое в выражение:  " + operand.top()
			+ "\n Выражение: " + result + "\n";
		result[count++] = operand.top();
		operand.pop();

	}
	return str + " Ответ: " + result;
	system("simple.txt");
}
// Рекурсивный спуск, прямой нотации для файла с ответами.
string Recursionanswer(string s, string* p)
{
	string res;
	int n = s.length();

	if (s[0] == '(')
	{
		*p = *p + "Найдена открывающаяся скобка \n";
		int pos = s.find(")");
		string sub;
		if (pos < s.length() - 1) sub = s.substr(pos + 2, s.length());
		int nn = sub.length();
		if (nn >= 3)
		{
			*p = *p + "Вызываем рекурсию выражения в скобках: " + s.substr(1, pos - 1) + "\n"
				+ "и рекурсию всего остального выражения: " + sub;

			res += s.substr(pos + 1, 1)
				+ Recursionanswer(s.substr(1, pos - 1), p)
				+ Recursionanswer(sub, p);
		}
		else
		{
			string rek = Recursionanswer(s.substr(1, pos - 1), p);

			*p = *p + "Добавляем в выражение подстроку: " + s.substr(pos + 1, 1) + "\n"
				+ "Добавляем в выражение рекурсию: " + s.substr(1, pos - 1) + "\n"
				+ "Добавляем в выражение оставшуюся подстроку: " + sub + "\n";
			res += s.substr(pos + 1, 1)
				+ rek
				+ sub;
		}
	}
	else
	{

		if (n > 3)
		{
			string rek = Recursionanswer(s.substr(2, s.length()), p);
			*p = *p + "Скобок нет, добавляем в выражение два оператора: " + s.substr(1, 1) + s.substr(0, 1) +
				"\n Вызываем рекурсию оствшегося выражения: " + s.substr(2, s.length()) + "\n";
			res += s.substr(1, 1) + s.substr(0, 1) + rek;
		}
		else
		{
			*p = *p + "Добавляем в выражение оставшиеся 3 символа в нужной последовательности \n";
			res += s.substr(1, 1) + s.substr(0, 1) + s.substr(2, s.length());

		}
	}
	return res;

}
// Преобразование из простой в прямую, для файла с ответами.
string SimpleInStraightFile(string simple)
{
	string str;
	string* s = &str;
	string result = Recursionanswer(simple, s);

	return "Исходное выржанеие: " + simple + "\n" + str + "Ответ: " + result + "\n";

}
// Преобразование из простой в обратную.
char* SimpleInReverse(char* simple)
{
	stack <char> operand;

	int n = strlen(simple);
	char* result = new char[n + 1];
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (simple[i] == '*' || simple[i] == '+' || simple[i] == '-' || simple[i] == '(' || simple[i] == '/')
		{
			if (operand.empty() || (Advantage(operand.top(), simple[i])))
			{
				operand.push(simple[i]);
			}
			else
			{
				while (!operand.empty() && !Advantage(operand.top(), simple[i]))
				{
					result[count++] = operand.top();
					operand.pop();
				}
				operand.push(simple[i]);
			}


		}
		else if (simple[i] == ')')
		{
			while (operand.top() != '(')
			{
				result[count++] = operand.top();
				operand.pop();
			}
			operand.pop();
		}
		// Если операнд, то помещаем в строку.
		else
		{
			result[count++] = simple[i];
		}
	}

	while (!operand.empty())
	{
		result[count++] = operand.top();
		operand.pop();

	}

	result[count++] = '\0';

	return result;

	delete result;
}
// Преобразование из обратной в простую.
char* ReverseInSimple(char* reverse)
{
	int n = strlen(reverse);
	char* result = new char[n * 2];
	int count = 0;

	stack <char> operand;
	for (int i = 0; i < n; i++)
	{
		if (reverse[i] == '*' || reverse[i] == '+' || reverse[i] == '-' || reverse[i] == '/')
		{
			char  temp = operand.top();
			operand.pop();

			if (!operand.empty())
			{
				result[count++] = operand.top();
				operand.pop();
			}

			result[count++] = reverse[i];
			result[count++] = temp;

			if (i + 1 < n)
			{
				// Cкобки - если следующий символ знак, то все что ранее - в скобки.
				char next = reverse[i + 1];
				if (!(next == '*' || next == '+'
					|| next == '-' || next == '/'))
				{
					char* tempchar = new char[count + 1];
					for (int x = 0; x < count; x++) tempchar[x] = result[x];

					result[0] = '(';
					for (int x = 0; x < count; x++) result[x + 1] = tempchar[x];
					count++;
					result[count++] = ')';
				}
			}

		}
		else operand.push(reverse[i]);
	}

	result[count++] = '\0';
	return result;

	delete result;
}
// Преобразование из прямой в простую.
char* StraightInSimple(char* reverse)
{
	int n = strlen(reverse);
	char* result = new char[n * 2];
	int count = 0;
	char bracket = 0;

	stack <char> operand;
	for (int i = 0; i < n; i++)
	{
		if (reverse[i] == '*' || reverse[i] == '+' || reverse[i] == '-' || reverse[i] == '/')
		{
			operand.push(reverse[i]);
		}
		else
		{
			result[count++] = reverse[i];
			if (bracket != 0)
			{
				result[count++] = bracket;
				bracket = 0;
			}

			if (!operand.empty())
			{
				result[count++] = operand.top();

				operand.pop();

				// Cкобки, если в стеке есть еще оператор и приоритет больше.

				if (!operand.empty() && Advantage(result[count - 1], operand.top()))
				{
					char* tempchar = new char[count + 1];
					for (int x = 0; x < count; x++)
					{
						tempchar[x] = result[x];
					}

					result[0] = '(';
					for (int x = 0; x < count; x++)
					{
						result[x + 1] = tempchar[x];
					}
					count++;
					bracket = ')';
				}
			}
		}
	}

	result[count++] = '\0';
	return result;

	delete result;
}
// Определяет тип выражения и ищет ошибки.
int CheckExpression(char* strinput)
{
	// 0 - ошибка, 1 - простое, 2 - прямое, 3 - обратное.
	int result = 0;
	int i = 0;
	int n = strlen(strinput);
	if (n > 1)
	{
		// Пропускает скобки в начале.
		while (strinput[i] == '(' && i != n)
			i++;

		// Определяет тип выражения.
		char c = strinput[i];
		// Если вначале идут знаки, то это прямое.
		if (c == '*' || c == '+' || c == '-' || c == '/')
		{
			result = 2;
		}
		else
		{
			// Ошибка, если после '(' сразу идет ')'.
			if (c == ')')
			{
				result = 0;
			}
			else
			{
				char s = strinput[n - 1];
				// Если знаки в конце, то это обратное.
				if (s == '*' || s == '+' || s == '-' || s == '/')
				{
					result = 3;
				}
				// По остаточному принципу - это простое.
				else
				{
					result = 1;
				}
			}
		}

		// Поиск ошибок.
		if (result != 0)
		{
			int braceopen = 0, braceclose = 0, operation = 0, operand = 0;
			for (int i = 0; i < n; i++)
				switch (strinput[i])
				{
				case '(':
					braceopen++;
					break;
				case ')':
					braceclose++;
					break;
				case '*': case '+': case '-': case '/':
					operation++;
					break;
				default:
					operand++;
					break;
				}

			// Несовпадение количества открывающих и закрывающих скобок.
			if (braceopen != braceclose)
			{
				result = 0;
			}
			// Несовпадение операндов и на один больше операторов.
			if (operand != (operation + 1))
			{
				result = 0;
			}
			// Подряд идущие одинаковые типы в простой записи.
			if (result == 1)
			{
				char* temp = new char[n];
				int x = -1;
				for (int i = 0; i < n; i++)
				{
					if (strinput[i] != '(' && strinput[i] != ')')
					{
						temp[++x] = strinput[i];
					}
				}

				for (int i = 0; i < x - 1; i++)
				{
					if (CheckingTheSymbol(temp[i], temp[i + 1]))
					{
						result = 0;
					}
				}
			}
		}
	}
	else
	{
		result = 0;
	}
	return result;
}
// Выделяет имя переменной под номером p.
char SelectVariable(char* c, int p)
{
	char ch = 0;
	int len = strlen(c);
	int i = 0;
	int count = 0;

	while (i < len && count != p)
	{

		if (!(c[i] == '*' || c[i] == '+' || c[i] == '-' || c[i] == '/' || c[i] == '(' || c[i] == ')'))
		{
			// Разбил на два условия для читабельности.
			if (NotNumber(c[i]))
			{
				count++;
				if (count == p)
				{
					ch = c[i];
				}
			}
		}

		i++;
	}
	return ch;
}
// Проверка на дурака. Можно ввести только цифры и знак минус.
int CheckFool()
{
	char ch;
	string str;

	do
	{
		ch = _getch();
		switch (ch)
		{
		case '-': case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			if ((ch == '-' && str == "") || ch != '-')
			{
				str += ch;
				cout << ch;
			}
			break;
		}
	} while (ch != 13 || str == "");

	return stoi(str);
}
// Калькулятор - вычисляет выражение.
float Calculator(char* reverse, int* variable)
{
	stack <float> operand;
	int len = strlen(reverse);
	float result = 0;

	int v = 0;
	for (int i = 0; i < len; i++)
	{

		if (reverse[i] == '*' || reverse[i] == '+' || reverse[i] == '-' || reverse[i] == '/')
		{
			int number1 = 0;
			int number2 = 0;

			number1 = operand.top();
			operand.pop();

			number2 = operand.top();
			operand.pop();



			if (reverse[i] == '*')
			{
				operand.push(number1 * number2);
			}
			if (reverse[i] == '+')
			{
				operand.push(number1 + number2);
			}
			if (reverse[i] == '-')
			{
				operand.push(number1 - number2);
			}
			if (reverse[i] == '/')
			{
				operand.push(number1 / number2);
			}
		}
		else
		{


			int number = 0;
			char ch = reverse[i];

			if (!NotNumber(reverse[i]))
			{
				number = atoi(&ch);
			}
			else
			{
				number = variable[v++];
			}
			operand.push(number);

		}
	}
	return operand.top();
}
// Вывод польской прямой нотации.
void OutputStraight(char* expression)
{
	cout << "Польская прямая: " << endl;
	int n = strlen(expression);

	char* straight = new char[n + 1];
	straight = SimpleInStraightArray(expression);
	straight = SimpleInStraight(expression);



	int i = 0;
	while (straight[i] != '\0') cout << straight[i++];
	cout << endl;
}
// Вывод польской обратной нотации.
char* OutputReverse(char* expression)
{
	cout << "Польская обратная: " << endl;
	int n = strlen(expression);
	char* reverse = new char[n + 1];
	reverse = SimpleInReverseArray(expression);
	reverse = SimpleInReverse(expression);
	int i = 0;
	while (reverse[i] != '\0')
	{
		cout << reverse[i++];
	}
	cout << endl;

	return reverse;
}
// Обработка выражения.
void ProcessingExpression(char* expression)
{
	int n = strlen(expression);
	char* simple = new char[n * 2];
	char* reverse = new char[n * 2];

	for (int i = 0; i < n; i++) cout << expression[i];
	cout << endl;
	cout << "Тип записи: " << endl;
	int check;
	check = CheckExpression(expression);
	check = ExpressionArray(expression);
	if (check == 0)
	{
		cout << "Некорректное выражение" << endl;
	}
	if (check == 1)
	{
		cout << "Простое выражение" << endl;
	}
	if (check == 2)
	{
		cout << "Прямая польская запись" << endl;
	}
	if (check == 3)
	{
		cout << "Обратная польская" << endl;
	}

	// Простая.
	if (check == 1)
	{
		simple = expression;
		reverse = OutputReverse(expression);
		OutputStraight(expression);
	}

	// Прямая.
	if (check == 2)
	{
		cout << "Простое выражение: " << endl;
		simple = StraightInSimple(expression);
		int i = 0;
		while (simple[i] != '\0') cout << simple[i++];
		cout << endl;

		reverse = OutputReverse(simple);

	}

	// Обратная.
	if (check == 3)
	{
		cout << "Простая запись: ";

		simple = ReverseInSimple(expression);
		reverse = expression;
		int i = 0;
		while (simple[i] != '\0') cout << simple[i++];
		cout << endl;

		OutputStraight(simple);
	}

	cout << endl;

	if (check != 0)
	{

		int i = 1;
		int* variable = new int[n];

		while (SelectVariable(simple, i) != 0)
		{

			cout << "Введите значение переменной " << SelectVariable(simple, i) << " : ";

			variable[i - 1] = CheckFool();
			cout << endl;

			i++;
		}


		float calc;

		calc = CalculatorArray(reverse, variable);
		calc = Calculator(reverse, variable);


		cout << "Результат вычислений: " << endl;
		cout << calc << endl;
		cout << "______________________________________________________" << endl;

	}
}
// Обработка файла.
void ProcessingFile()
{
	cout << "Выражение из файла: " << endl;
	int n = FileSize("Expression.txt");
	char* expression = new char[n + 1];

	LoadFile(expression);

	ProcessingExpression(expression);
}
// Меняет номер оператора на его символ.
string ChangesOperator(int n)
{
	switch (n)
	{
	case 0: return "+"; break;
	case 1: return "-"; break;
	case 2: return "*"; break;
	case 3: return "/"; break;

	}

}
// Меняет номер переменной её буквенным обозначением.
string ChangesVariable(int n)
{
	switch (n)
	{
	case 0: return "X"; break;
	case 1: return "Y"; break;
	case 2: return "Z"; break;
	case 3: return "A"; break;
	case 4: return "B"; break;
	case 5: return "C"; break;
	case 6: return "D"; break;
	case 7: return "E"; break;
	case 8: return "F"; break;
	case 9: return "G"; break;
	case 10: return "H"; break;
	case 11: return "I"; break;
	case 12: return "J"; break;
	}
}
// Создание тест файла с файлом ответов.
void Test(int n)
{
	for (int i = 1; i <= n; i++)
	{
		ofstream file("test.txt", ios_base::app);
		ofstream answer("answers.txt", ios_base::app);
		int varcount = rand() % 5 + 2;
		int len = rand() % 10 + 10;
		string s = "";
		string sk1 = "", sk2 = "";
		int skobka = 0;
		for (int i = 0; i < len; i++)
		{
			string oper = ChangesOperator(rand() % 4);
			string var = ChangesVariable(rand() % varcount);

			if (i != len - 1 && skobka == 0 && (oper == "+" || oper == "-"))
			{
				if (rand() % 2)	skobka = 2;
			}

			if (skobka == 2)
			{
				sk1 = "(";
				skobka = 1;
			}
			else if (skobka == 1)
			{
				if ((i == len - 1) || rand() % 2)
				{
					sk2 = ")";
					skobka = 0;
				}
			}

			s += sk1 + var + sk2;

			if (i != len - 1)  s += oper;
			sk1 = "";
			sk2 = "";

		}

		file << "Задание № " << i << " Простая запись: ";
		file << s << endl;
		answer << "Решение задания № " << i << " Обратная нотация. \n" << SimpleInReverseFile(s) << endl;

		string str = SimpleInStraightFile(s);
		answer << "Решение задания № " << i << " Прямая нотация. \n" << str << endl;

		file.close();
		answer.close();

	}
	cout << "Файл test.txt сохранен" << endl;
	cout << "Файл answer.txt сохранен" << endl;
}
// Меню 1 задания.
int MenuEnter() { //вывод меню, управляемого стрелками

	auto key = 0;
	int code;

	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> Двусвязные" << endl;
		else  cout << "   Двусвязные" << endl;

		if (key == 1) cout << "-> Польские нотации" << endl;
		else  cout << "   Польские нотации" << endl;

		if (key == 2) cout << "-> Дерево" << endl;
		else  cout << "   Дерево" << endl;

		if (key == 3) cout << "-> Главное меню" << endl;
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
// Меню 1 задания.
int MenuEnter2()
{

	auto key = 0;
	int code;

	do {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) cout << "-> Формирование двусвязного списка с помощью рандомных чисел." << endl;
		else  cout << "   Формирование двусвязного списка с помощью рандомных чисел." << endl;

		if (key == 1) cout << "-> Вставка." << endl;
		else  cout << "   Вставка." << endl;

		if (key == 2) cout << "-> Удаление по индексу." << endl;
		else  cout << "   Удаление по индексу." << endl;

		if (key == 3) cout << "-> Получение по индексу." << endl;
		else  cout << "   Получение по индексу." << endl;

		if (key == 4) cout << "-> Назад" << endl;
		else  cout << "   Назад" << endl;

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
// Меню 1 задания.
int MenuEnter3()
{

	auto key = 0;
	int code;

	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> Ввод из файла." << endl;
		else  cout << "   Ввод из файла." << endl;

		if (key == 1) cout << "-> Ввод вручную." << endl;
		else  cout << "   Ввод вручную." << endl;

		if (key == 2) cout << "-> Тест, вывод в файл с ответами." << endl;
		else  cout << "   Тест, вывод в файл с ответами." << endl;

		if (key == 3) cout << "-> Назад" << endl;
		else  cout << "   Назад" << endl;

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
// Функция работы меню 1 задания.
void MainEnter()
{
	List L;
	int n = 0;
	int* a = new int[n];
	auto exit = 0;

	do {
		const auto answer = MenuEnter();

		switch (answer)
		{

		case 0:
		{


			auto exit = 0;

			do {

				const auto answer = MenuEnter2();

				switch (answer)
				{

				case 0:
				{
					system("cls");
					Randomize(a, n);
					for (int i = 0; i < n; i++)
					{
						L.AddHead(a[i]);
						SavingData(a, n, "file.txt");
					}
					// Распечатка списка
					cout << "List L:\n";
					L.Print();
					cout << endl;
					system("file.txt");
					system("cls");
					break;
				}


				case 1:
				{
					cout << "Введите местечко куда его вставить: ";
					// Вставка элемента в список
					L.Insert();
					// Распечатка списка
					cout << "List L:\n";
					L.Print();
					L.PrintFile("file.txt");
					system("file.txt");
					system("cls");
					break;
				}

				case 2:
				{
					L.Del();
					L.Print();
					L.PrintFile("file.txt");
					system("file.txt");
					break;
				}

				case 3:
				{
					cout << "Введите номер элемента:" << endl;
					while (!(cin >> n) || (cin.peek() != '\n')) // cin.peek - проверяет, достигнут ли конец потока входного файла
					{
						cin.clear();
						while (cin.get() != '\n'); //проверяет, является ли строка cin.get() пустой строкой
						cout << "Ошибка ввода. Попробуйте ещё раз:" << endl;
					}
					L.Print(n);
					L.PrintFileNum(n, "file.txt");
					system("file.txt");
					system("cls");
					break;
				}
				case 4:
				{
					exit = 1;
				}
				default:;
				}
			} while (exit == 0);
			break;
		}

		// Нотации
		case 1:
		{
			auto exit = 0;

			do {

				const auto answer = MenuEnter3();

				switch (answer)
				{

				case 0:
				{
					system("cls");
					ProcessingFile();
					system("pause");
					system("cls");
					break;
				}


				case 1:
				{
					cout << "\t\t";
					system("cls");
					cout << "Введите выражения вручную: ";
					char expression[300];
					cin >> expression;
					cout << "______________________________________________" << endl;
					cout << "Ваше выражение:" << endl;
					ProcessingExpression(expression);
					system("pause");
					system("cls");
					break;
				}

				case 2:
				{
					system("cls");
					cout << "Введите количество необходимых проверок: ";
					int t;
					cin >> t;
					Test(t);
					system("answers.txt");
					system("test.txt");
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					exit = 1;
				}
				default:;
				}
			} while (exit == 0);
			break;
		}
		// Дерево
		case 2:
		{
			auto exit = 0;
			ofstream in_file;
			int enter, NodeN = 0;
			Node* origin = nullptr;
			do 
			{

				const auto answer = Menu5();

				switch (answer)
				{
					// Рандом
				case 0:
				{
					
					system("cls");
					cout << "Введите количество элементов дерева: ";
					cin >> NodeN;
					if ((NodeN <= 0) || (NodeN > 300))
					{
						break;
					}
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					RandomTree(NodeN, origin, 300);
					EquallyTree(origin);
					cout << endl;
					system("Pause");
					system("cls");
					break;
				}
				// Вывод
				case 1:
				{
					in_file.open("tree.txt");
					TreeOutput(in_file, origin, NodeN, 1);
					in_file.close();
					system("tree.txt");
					system("cls");
					break;
				}
				// Вставка
				case 2:
				{
					system("cls");
					cout << "Значение узла: ";
					int val = 0;
					cin >> val;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					if (ApendTree(origin, val, NodeN))
					{
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Узел с таким значением уже существует.\n";
						system("pause");
						system("cls");
					}
					break;
				}
				// Удаление
				case 3:
				{
					system("cls");
					cout << "Узел со значением, чтобы удалить: ";
					int val = 0;
					cin >> val;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					if (DeleteFromTree(origin, val))
					{
						NodeN--;
						system("pause");
						system("cls");
					}
					else
					{
						cout << "Узел со значением " << val << " не найден\n";
						system("pause");
						system("cls");
					}
					break;
				}
				// Поиск
				case 4:
				{
					system("cls");
					cout << "Найти узел со значением: ";
					int val = 0;
					cin >> val;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					Node* search = LookNode(origin, val);
					if (search->data != val)
					{
						cout << "Узел с таким значением не найден.\n";
						system("pause");
						system("cls");

					}
					else
					{
						cout << "Узел найден.\n";
						system("pause");
						system("cls");
					}
					break;
				}
				case 5:
				{
					exit = 1;
				}
				default:;
				}
			} while (exit == 0);
			break;
		}
		// Выход
		case 3:
		{
			exit = 1;
		}
		default:;
		}
	} while (exit == 0);

}