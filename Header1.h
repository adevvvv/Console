// ��������� �������������, ��������������� ��� ������ �� �������� ����������� ������������� �����.
#pragma once
// ����������� ������������� �����.
#include "Header.h"
#include "Header3.h"
// ������ �����.
void Randomize(int* (&arr), int& N)
{
	cout << "������� ����������� �������: ";
	while (!(cin >> N) || (cin.peek() != '\n')) // cin.peek - ���������, ��������� �� ����� ������ �������� �����
	{
		cin.clear();
		while (cin.get() != '\n'); //���������, �������� �� ������ cin.get() ������ �������
		cout << "������ �����. ���������� ��� ���:" << endl;
	}
	// ������� �����
	arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
}
struct Elem
{
	// ������.
	int data;
	Elem* next, * prev;
};
class List
{
	// ������, �����
	Elem* Head, * Tail;
	// ���������� ���������   
	int Count;

public:

	// �����������
	List();
	// ����������� �����������
	List(const List&);
	// ����������
	~List();

	// �������� ������� ������
	Elem* GetElem(int);

	// ������� ���� ������
	void DelAll();
	// �������� ��������, ���� �������� �� �����������, �� ������� ��� �����������
	void Del(int pos = 0);
	// ������� ��������, ���� �������� �� �����������,
	// �� ������� ��� �����������
	void Insert(int pos = 0);

	// ���������� � ����� ������
	void AddTail(int n);

	// ���������� � ������ ������
	void AddHead(int n);

	// ������ ������
	void Print();
	// ������ � ����
	void PrintFile(string file);
	// ������ � ����
	void PrintFileNum(int pos, string file);
	// ������ ������������� ��������
	void Print(int pos);


};
// �����������.
List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}
// ����������� �����������.
List::List(const List& L)
{
	Head = Tail = NULL;
	Count = 0;

	// ������ ������, �� �������� ��������
	Elem* temp = L.Head;
	// ���� �� ����� ������
	while (temp != 0)
	{
		// ���������� ������
		AddTail(temp->data);
		temp = temp->next;
	}
}
// ����������.
List::~List()
{
	// ������� ��� ��������
	DelAll();
}
// ���������� � ������ ������.
void List::AddHead(int n)
{
	// ����� �������
	Elem* temp = new Elem;

	// ����������� ���
	temp->prev = 0;
	// ��������� ������
	temp->data = n;
	// ��������� - ������ ������
	temp->next = Head;

	// ���� �������� ����?
	if (Head != 0)
		Head->prev = temp;

	// ���� ������� ������, �� �� ������������ � ������ � �����
	if (Count == 0)
		Head = Tail = temp;
	else
		// ����� ����� ������� - ��������
		Head = temp;

	Count++;
}
// ���������� � ����� ������.
void List::AddTail(int n)
{
	// ������� ����� �������
	Elem* temp = new Elem;
	// ���������� ���
	temp->next = 0;
	// ��������� ������
	temp->data = n;
	// ���������� - ������ �����
	temp->prev = Tail;

	// ���� �������� ����?
	if (Tail != 0)
		Tail->next = temp;

	// ���� ������� ������, �� �� ������������ � ������ � �����
	if (Count == 0)
		Head = Tail = temp;
	else
		// ����� ����� ������� - ���������
		Tail = temp;

	Count++;
}
// ������� ��������, ���� �������� �� �����������, �� ������� ��� �����������.
void List::Insert(int pos)
{
	// ���� �������� ����������� ��� ����� 0, �� ����������� ���
	if (pos == 0)
	{

		while (!(cin >> pos) || (cin.peek() != '\n')) // cin.peek - ���������, ��������� �� ����� ������ �������� �����
		{
			cin.clear();
			while (cin.get() != '\n'); //���������, �������� �� ������ cin.get() ������ �������
			cout << "������ �����. ���������� ��� ���:" << endl;
		}
	}

	// ������� �� 1 �� Count?
	if (pos < 1 || pos > Count + 1)
	{
		// �������� �������
		cout << "!!!\n";
		return;
	}

	// ���� ������� � ����� ������
	if (pos == Count + 1)
	{
		// ����������� ������
		int data;
		cout << "������� ����� �����: ";

		while (!(cin >> data) || (cin.peek() != '\n')) // cin.peek - ���������, ��������� �� ����� ������ �������� �����
		{
			cin.clear();
			while (cin.get() != '\n'); //���������, �������� �� ������ cin.get() ������ �������
			cout << "������ �����. ���������� ��� ���:" << endl;
		}
		// ���������� � ����� ������
		AddTail(data);
		return;
	}
	else if (pos == 1)
	{
		// ����������� ������
		int data;
		cout << "����� �����: ";

		while (!(cin >> data) || (cin.peek() != '\n')) // cin.peek - ���������, ��������� �� ����� ������ �������� �����
		{
			cin.clear();
			while (cin.get() != '\n'); //���������, �������� �� ������ cin.get() ������ �������
			cout << "������ �����. ���������� ��� ���:" << endl;
		}
		// ���������� � ������ ������
		AddHead(data);
		return;
	}

	// �������
	int i = 1;

	// ����������� �� ������ n - 1 ���������
	Elem* Ins = Head;

	while (i < pos)
	{
		// ������� �� ��������, 
		// ����� ������� �����������
		Ins = Ins->next;
		i++;
	}

	// ������� �� ��������, 
	// ������� ������������
	Elem* PrevIns = Ins->prev;

	// ������� ����� �������
	Elem* temp = new Elem;

	// ������ ������
	cout << "������� �������: ";
	cin >> temp->data;

	// ��������� ������
	if (PrevIns != 0 && Count != 1)
		PrevIns->next = temp;

	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;

	Count++;
}
// �������� ��������, ���� �������� �� �����������, �� ������� ��� �����������.
void List::Del(int pos)
{
	// ���� �������� ����������� ��� ����� 0, �� ����������� ���
	if (pos == 0)
	{
		cout << "�������: ";
		while (!(cin >> pos) || (cin.peek() != '\n')) // cin.peek - ���������, ��������� �� ����� ������ �������� �����
		{
			cin.clear();
			while (cin.get() != '\n'); //���������, �������� �� ������ cin.get() ������ �������
			cout << "������ �����. ���������� ��� ���:" << endl;
		}
	}
	// ������� �� 1 �� Count?
	if (pos < 1 || pos > Count)
	{
		// �������� �������
		cout << "!!!\n";
		return;
	}

	// �������
	int i = 1;

	Elem* Del = Head;

	while (i < pos)
	{
		// ������� �� ��������, 
		// ������� ���������
		Del = Del->next;
		i++;
	}

	// ������� �� ��������, 
	// ������� ������������ ����������
	Elem* PrevDel = Del->prev;
	// ������� �� ��������, ������� ������� �� ���������
	Elem* AfterDel = Del->next;

	// ���� ������� �� ������
	if (PrevDel != 0 && Count != 1)
		PrevDel->next = AfterDel;
	// ���� ������� �� �����
	if (AfterDel != 0 && Count != 1)
		AfterDel->prev = PrevDel;

	// ��������� �������?
	if (pos == 1)
		Head = AfterDel;
	if (pos == Count)
		Tail = PrevDel;

	// �������� ��������
	delete Del;

	Count--;
}
// ������ �������� ������.
void List::Print(int pos)
{
	// ������� �� 1 �� Count?
	if (pos < 1 || pos > Count)
	{
		// �������� �������
		cout << "!!!!!\n";
		return;
	}

	Elem* temp;

	// ���������� � ����� ������� 
	// ������� ���������
	if (pos <= Count / 2)
	{
		// ������ � ������
		temp = Head;
		int i = 1;

		while (i < pos)
		{
			// ��������� �� ������� ��������
			temp = temp->next;
			i++;
		}
	}
	else
	{
		// ������ � ������
		temp = Tail;
		int i = 1;

		while (i <= Count - pos)
		{
			// ��������� �� ������� ��������
			temp = temp->prev;
			i++;
		}
	}
	// ����� ��������
	cout << pos << " �������: ";
	cout << temp->data << endl;
}
// ������ ������.
void List::Print()
{
	// ���� � ������ ������������ ��������, �� ��������� �� ����
	// � �������� ��������, ������� � ���������
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
// ������� ���� ������.
void List::DelAll()
{
	// ���� �������� ��������, ������� �� ������ � ������
	while (Count != 0)
		Del(1);
}
// �������� ������� ������.
Elem* List::GetElem(int pos)
{
	Elem* temp = Head;

	// ������� �� 1 �� Count?
	if (pos < 1 || pos > Count)
	{
		// �������� �������
		cout << " !!!\n";
		return 0;
	}

	int i = 1;
	// ���� ������ ��� �������
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
// ����� � ����.
void SavingData(int* (&a), int& N, string file) // ���������� ������
{
	//������� ����� ��� ������
	ofstream record(file); //�������� ����. 
	if (record) // ���� ��������
	{
		record << "�������� ����� � �������� �� �������." << endl << "���������� ������:";
		record << N << endl; // ���������� ���������� ������

		for (int i = 0; i < N; i++)
		{

			record << a[i] << endl;
		}
	}
	else
		cout << "������ �������� �����!" << endl;
	record.close(); // ��������� ����
}
// ����� � ����.
void List::PrintFile(string file)
{
	//������� ����� ��� ������
	ofstream record(file); //�������� ����. 
	if (record) // ���� ��������
	{
		record << "�������� ����� � �������� �� �������." << endl;

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

		cout << "������ �������� �����!" << endl;


	record.close(); // ��������� ����
}
// ����� � ����.
void List::PrintFileNum(int pos, string file)
{
	//������� ����� ��� ������
	ofstream record(file); //�������� ����. 
	if (record) // ���� ��������
	{
		record << "�������� ����� � �������� �� �������." << endl;

		// ������� �� 1 �� Count?
		if (pos < 1 || pos > Count)
		{
			// �������� �������
			record << "!!!!!\n";
			return;
		}

		Elem* temp;

		// ���������� � ����� ������� 
		// ������� ���������
		if (pos <= Count / 2)
		{
			// ������ � ������
			temp = Head;
			int i = 1;

			while (i < pos)
			{
				// ��������� �� ������� ��������
				temp = temp->next;
				i++;
			}
		}
		else
		{
			// ������ � ������
			temp = Tail;
			int i = 1;

			while (i <= Count - pos)
			{
				// ��������� �� ������� ��������
				temp = temp->prev;
				i++;
			}
		}
		// ����� ��������
		record << pos << " �������: ";
		record << temp->data << endl;
	}
	else

		cout << "������ �������� �����!" << endl;


	record.close(); // ��������� ����
}
// ����������, ������� �� ����������� � 1-�� �� 2-� ����������.
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
// ��������� ���������� �� ������ ��������.
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
// ��������� ����� ��� ��������� � ���������� ������.
int ExpressionArray(char* strinput)
{
	// 0 - ������, 1 - �������, 2 - ������, 3 - ��������.
	int result = 0;
	int i = 0;
	int n = strlen(strinput);
	if (n > 1)
	{
		// ���������� ������ � ������.
		while (strinput[i] == '(' && i != n)
		{
			i++;
		}
		// ���������� ��� ���������.
		char c = strinput[i];
		// ���� ������� ���� �����, �� ��� ������.
		if (c == '*' || c == '+' || c == '-' || c == '/')
		{
			result = 2;
		}
		else
		{
			// ������, ���� ����� 1-�� ������ ����� ���� ������ �������� ������.
			if (c == ')')
			{
				result = 0;
			}
			else
			{
				char s = strinput[n - 1];
				// ���� ������������ ����� � �����, �� ��� ��������.
				if (s == '*' || s == '+' || s == '-' || s == '/')
				{
					result = 3;
				}
				// ����� - ��� �������.
				else
				{
					result = 1;
				}
			}
		}
		// � ������� ������.
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

			// ������������ ���������� ����������� � ����������� ������.
			if (braceopen != braceclose)
			{
				result = 0;
			}
			// ������������ ��������� � �� ���� ������ ����������.
			if (operand != (operation + 1))
			{
				result = 0;
			}
			// ������ ������ ���������� ���� � ������� ������.
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
// �������������� �� ������� � ��������(������).
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
		// ���� ���� ��������.
		if (simple[i] == '*' || simple[i] == '+' || simple[i] == '-' || simple[i] == '(' || simple[i] == '/')
		{
			if (arraycount == -1 || (Advantage(operand[arraycount], simple[i])))
			{
				// ���� ��������� ������, �� � ����.
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
		// ���� ����������� ������ ��, ���������� ����� �� ������ - � ������.
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
// ����������� ���������, ��� ������ �������
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
// �������������� �� ������� � ������(������).
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
// ��������, �� �������� �� ������.
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
// ����������� ��� ���������� ���������(������).
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
// ���������� ������ �����.
int FileSize(string path)
{
	ifstream file(path);
	file.seekg(0, ios_base::end);

	int filesize = file.tellg();

	file.close();

	return filesize;
}
// ��������� ��������� �� �����.
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
		cout << "��� ������ ����� ���!" << endl;
	}
}
// �������������� �� ������� � ������.
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
// �������������� �� ������� � ��������, ��� ����� � ��������
string SimpleInReverseFile(string simple)
{
	stack <char> operand;

	int n = simple.length();
	string result;
	string str = "�������� ���������: " + simple + "\n";
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if (simple[i] == '*' || simple[i] == '+' || simple[i] == '-' || simple[i] == '(' || simple[i] == '/')
		{
			if (operand.empty() || (Advantage(operand.top(), simple[i])))
				// ���� ��������� ������, �� � ����.
				operand.push(simple[i]);
			else
			{
				while (!operand.empty() && !Advantage(operand.top(), simple[i]))
				{
					str = str + "��������� �� ����� �������� � ��������� � ���������: " + operand.top() + "\n" +
						+"���������: " + result + "\n";
					result += operand.top();
					operand.pop();
				}

				str = str + "��������� �������� � ����: " + simple[i] + "\n ���������: " + result + "\n";
				operand.push(simple[i]);
			}
		}
		// ���� ����������� ������, �� ���������� ����� �� ������ - � ������.
		else if (simple[i] == ')')
		{
			while (operand.top() != '(')
			{
				str = str + "��������� �� ����� ������� �� ������: " + operand.top() + "\n";
				result += operand.top();
				operand.pop();
			}
			operand.pop();
			str = str + "���������: " + result + "\n";
		}
		else
		{
			result += simple[i];
			str = str + "��������� ������� � ���������: " + simple[i] + "\n ���������: " + result + "\n";
		}
	}

	while (!operand.empty())
	{
		str = str + "���� ����� �� ���� �������� ��� ���������� � ���������:  " + operand.top()
			+ "\n ���������: " + result + "\n";
		result[count++] = operand.top();
		operand.pop();

	}
	return str + " �����: " + result;
	system("simple.txt");
}
// ����������� �����, ������ ������� ��� ����� � ��������.
string Recursionanswer(string s, string* p)
{
	string res;
	int n = s.length();

	if (s[0] == '(')
	{
		*p = *p + "������� ������������� ������ \n";
		int pos = s.find(")");
		string sub;
		if (pos < s.length() - 1) sub = s.substr(pos + 2, s.length());
		int nn = sub.length();
		if (nn >= 3)
		{
			*p = *p + "�������� �������� ��������� � �������: " + s.substr(1, pos - 1) + "\n"
				+ "� �������� ����� ���������� ���������: " + sub;

			res += s.substr(pos + 1, 1)
				+ Recursionanswer(s.substr(1, pos - 1), p)
				+ Recursionanswer(sub, p);
		}
		else
		{
			string rek = Recursionanswer(s.substr(1, pos - 1), p);

			*p = *p + "��������� � ��������� ���������: " + s.substr(pos + 1, 1) + "\n"
				+ "��������� � ��������� ��������: " + s.substr(1, pos - 1) + "\n"
				+ "��������� � ��������� ���������� ���������: " + sub + "\n";
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
			*p = *p + "������ ���, ��������� � ��������� ��� ���������: " + s.substr(1, 1) + s.substr(0, 1) +
				"\n �������� �������� ���������� ���������: " + s.substr(2, s.length()) + "\n";
			res += s.substr(1, 1) + s.substr(0, 1) + rek;
		}
		else
		{
			*p = *p + "��������� � ��������� ���������� 3 ������� � ������ ������������������ \n";
			res += s.substr(1, 1) + s.substr(0, 1) + s.substr(2, s.length());

		}
	}
	return res;

}
// �������������� �� ������� � ������, ��� ����� � ��������.
string SimpleInStraightFile(string simple)
{
	string str;
	string* s = &str;
	string result = Recursionanswer(simple, s);

	return "�������� ���������: " + simple + "\n" + str + "�����: " + result + "\n";

}
// �������������� �� ������� � ��������.
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
		// ���� �������, �� �������� � ������.
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
// �������������� �� �������� � �������.
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
				// C����� - ���� ��������� ������ ����, �� ��� ��� ����� - � ������.
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
// �������������� �� ������ � �������.
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

				// C�����, ���� � ����� ���� ��� �������� � ��������� ������.

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
// ���������� ��� ��������� � ���� ������.
int CheckExpression(char* strinput)
{
	// 0 - ������, 1 - �������, 2 - ������, 3 - ��������.
	int result = 0;
	int i = 0;
	int n = strlen(strinput);
	if (n > 1)
	{
		// ���������� ������ � ������.
		while (strinput[i] == '(' && i != n)
			i++;

		// ���������� ��� ���������.
		char c = strinput[i];
		// ���� ������� ���� �����, �� ��� ������.
		if (c == '*' || c == '+' || c == '-' || c == '/')
		{
			result = 2;
		}
		else
		{
			// ������, ���� ����� '(' ����� ���� ')'.
			if (c == ')')
			{
				result = 0;
			}
			else
			{
				char s = strinput[n - 1];
				// ���� ����� � �����, �� ��� ��������.
				if (s == '*' || s == '+' || s == '-' || s == '/')
				{
					result = 3;
				}
				// �� ����������� �������� - ��� �������.
				else
				{
					result = 1;
				}
			}
		}

		// ����� ������.
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

			// ������������ ���������� ����������� � ����������� ������.
			if (braceopen != braceclose)
			{
				result = 0;
			}
			// ������������ ��������� � �� ���� ������ ����������.
			if (operand != (operation + 1))
			{
				result = 0;
			}
			// ������ ������ ���������� ���� � ������� ������.
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
// �������� ��� ���������� ��� ������� p.
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
			// ������ �� ��� ������� ��� �������������.
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
// �������� �� ������. ����� ������ ������ ����� � ���� �����.
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
// ����������� - ��������� ���������.
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
// ����� �������� ������ �������.
void OutputStraight(char* expression)
{
	cout << "�������� ������: " << endl;
	int n = strlen(expression);

	char* straight = new char[n + 1];
	straight = SimpleInStraightArray(expression);
	straight = SimpleInStraight(expression);



	int i = 0;
	while (straight[i] != '\0') cout << straight[i++];
	cout << endl;
}
// ����� �������� �������� �������.
char* OutputReverse(char* expression)
{
	cout << "�������� ��������: " << endl;
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
// ��������� ���������.
void ProcessingExpression(char* expression)
{
	int n = strlen(expression);
	char* simple = new char[n * 2];
	char* reverse = new char[n * 2];

	for (int i = 0; i < n; i++) cout << expression[i];
	cout << endl;
	cout << "��� ������: " << endl;
	int check;
	check = CheckExpression(expression);
	check = ExpressionArray(expression);
	if (check == 0)
	{
		cout << "������������ ���������" << endl;
	}
	if (check == 1)
	{
		cout << "������� ���������" << endl;
	}
	if (check == 2)
	{
		cout << "������ �������� ������" << endl;
	}
	if (check == 3)
	{
		cout << "�������� ��������" << endl;
	}

	// �������.
	if (check == 1)
	{
		simple = expression;
		reverse = OutputReverse(expression);
		OutputStraight(expression);
	}

	// ������.
	if (check == 2)
	{
		cout << "������� ���������: " << endl;
		simple = StraightInSimple(expression);
		int i = 0;
		while (simple[i] != '\0') cout << simple[i++];
		cout << endl;

		reverse = OutputReverse(simple);

	}

	// ��������.
	if (check == 3)
	{
		cout << "������� ������: ";

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

			cout << "������� �������� ���������� " << SelectVariable(simple, i) << " : ";

			variable[i - 1] = CheckFool();
			cout << endl;

			i++;
		}


		float calc;

		calc = CalculatorArray(reverse, variable);
		calc = Calculator(reverse, variable);


		cout << "��������� ����������: " << endl;
		cout << calc << endl;
		cout << "______________________________________________________" << endl;

	}
}
// ��������� �����.
void ProcessingFile()
{
	cout << "��������� �� �����: " << endl;
	int n = FileSize("Expression.txt");
	char* expression = new char[n + 1];

	LoadFile(expression);

	ProcessingExpression(expression);
}
// ������ ����� ��������� �� ��� ������.
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
// ������ ����� ���������� � ��������� ������������.
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
// �������� ���� ����� � ������ �������.
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

		file << "������� � " << i << " ������� ������: ";
		file << s << endl;
		answer << "������� ������� � " << i << " �������� �������. \n" << SimpleInReverseFile(s) << endl;

		string str = SimpleInStraightFile(s);
		answer << "������� ������� � " << i << " ������ �������. \n" << str << endl;

		file.close();
		answer.close();

	}
	cout << "���� test.txt ��������" << endl;
	cout << "���� answer.txt ��������" << endl;
}
// ���� 1 �������.
int MenuEnter() { //����� ����, ������������ ���������

	auto key = 0;
	int code;

	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> ����������" << endl;
		else  cout << "   ����������" << endl;

		if (key == 1) cout << "-> �������� �������" << endl;
		else  cout << "   �������� �������" << endl;

		if (key == 2) cout << "-> ������" << endl;
		else  cout << "   ������" << endl;

		if (key == 3) cout << "-> ������� ����" << endl;
		else  cout << "   ������� ����" << endl;

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
// ���� 1 �������.
int MenuEnter2()
{

	auto key = 0;
	int code;

	do {
		system("cls");
		key = (key + 5) % 5;
		if (key == 0) cout << "-> ������������ ����������� ������ � ������� ��������� �����." << endl;
		else  cout << "   ������������ ����������� ������ � ������� ��������� �����." << endl;

		if (key == 1) cout << "-> �������." << endl;
		else  cout << "   �������." << endl;

		if (key == 2) cout << "-> �������� �� �������." << endl;
		else  cout << "   �������� �� �������." << endl;

		if (key == 3) cout << "-> ��������� �� �������." << endl;
		else  cout << "   ��������� �� �������." << endl;

		if (key == 4) cout << "-> �����" << endl;
		else  cout << "   �����" << endl;

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
// ���� 1 �������.
int MenuEnter3()
{

	auto key = 0;
	int code;

	do {
		system("cls");
		key = (key + 4) % 4;
		if (key == 0) cout << "-> ���� �� �����." << endl;
		else  cout << "   ���� �� �����." << endl;

		if (key == 1) cout << "-> ���� �������." << endl;
		else  cout << "   ���� �������." << endl;

		if (key == 2) cout << "-> ����, ����� � ���� � ��������." << endl;
		else  cout << "   ����, ����� � ���� � ��������." << endl;

		if (key == 3) cout << "-> �����" << endl;
		else  cout << "   �����" << endl;

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
// ������� ������ ���� 1 �������.
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
					// ���������� ������
					cout << "List L:\n";
					L.Print();
					cout << endl;
					system("file.txt");
					system("cls");
					break;
				}


				case 1:
				{
					cout << "������� �������� ���� ��� ��������: ";
					// ������� �������� � ������
					L.Insert();
					// ���������� ������
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
					cout << "������� ����� ��������:" << endl;
					while (!(cin >> n) || (cin.peek() != '\n')) // cin.peek - ���������, ��������� �� ����� ������ �������� �����
					{
						cin.clear();
						while (cin.get() != '\n'); //���������, �������� �� ������ cin.get() ������ �������
						cout << "������ �����. ���������� ��� ���:" << endl;
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

		// �������
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
					cout << "������� ��������� �������: ";
					char expression[300];
					cin >> expression;
					cout << "______________________________________________" << endl;
					cout << "���� ���������:" << endl;
					ProcessingExpression(expression);
					system("pause");
					system("cls");
					break;
				}

				case 2:
				{
					system("cls");
					cout << "������� ���������� ����������� ��������: ";
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
		// ������
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
					// ������
				case 0:
				{
					
					system("cls");
					cout << "������� ���������� ��������� ������: ";
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
				// �����
				case 1:
				{
					in_file.open("tree.txt");
					TreeOutput(in_file, origin, NodeN, 1);
					in_file.close();
					system("tree.txt");
					system("cls");
					break;
				}
				// �������
				case 2:
				{
					system("cls");
					cout << "�������� ����: ";
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
						cout << "���� � ����� ��������� ��� ����������.\n";
						system("pause");
						system("cls");
					}
					break;
				}
				// ��������
				case 3:
				{
					system("cls");
					cout << "���� �� ���������, ����� �������: ";
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
						cout << "���� �� ��������� " << val << " �� ������\n";
						system("pause");
						system("cls");
					}
					break;
				}
				// �����
				case 4:
				{
					system("cls");
					cout << "����� ���� �� ���������: ";
					int val = 0;
					cin >> val;
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					Node* search = LookNode(origin, val);
					if (search->data != val)
					{
						cout << "���� � ����� ��������� �� ������.\n";
						system("pause");
						system("cls");

					}
					else
					{
						cout << "���� ������.\n";
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
		// �����
		case 3:
		{
			exit = 1;
		}
		default:;
		}
	} while (exit == 0);

}