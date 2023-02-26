// ��������� �������������, ��������������� ��� ������ �� �������� ����������� ������������� �����.
#pragma once
// ����������� ������������� �����.
#include "Header.h"
// ��������� ���.
struct Initial
{
	string surname,
		name,
		patronymic;
};
// ��������� ������ ������.
struct NumberGroup
{
	short NomerGrup;
};
// ��������� ������ �������� � ������ ������.
struct NumberListOfGroup
{
	short NomerStudenta;
};
// ��������� ���������� ������.
struct AssessmentsStudents
{
	short Bal;
};
// ��������� ������� �������� ��� ��������� ������.
struct Time
{
	time_t day, mon, year, hour, min;
};
// ��������� ������.
struct Data
{
	Initial _initial;
	NumberGroup _numbergroup;
	NumberListOfGroup _numberlistofgroup;
	AssessmentsStudents _assesmentsstudents;
	Time _time;
};
// ������� ����� ������ � ��������.
void DataEntry(Data* (&d), int& n) // (&d) - ����� �� ������ ��� ��������� ����� ������ // int& - ����� �� ���������� ���������
{

	cout << "������� ���������� ��������� ��� ����� ������ ������: ";
	while (!(cin >> n) || (cin.peek() != '\n')) // cin.peek - ���������, ��������� �� ����� ������ �������� �����
	{
		cin.clear();
		while (cin.get() != '\n'); //���������, �������� �� ������ cin.get() ������ �������
		cout << "������ �����. ���������� ��� ���:" << endl;
	}
	//�������� ������
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

		cout << "������� ���: ";
		while (!(cin >> d[i]._initial.surname) || (d[i]._initial.surname <= "�") || (d[i]._initial.surname >= "�") && (d[i]._initial.surname >= "�") || (d[i]._initial.surname >= "�"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���:" << endl;
		}

		while (!(cin >> d[i]._initial.name) || (d[i]._initial.name <= "�") || (d[i]._initial.name >= "�") && (d[i]._initial.name >= "�") || (d[i]._initial.name >= "�"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���:" << endl;
		}

		while (!(cin >> d[i]._initial.patronymic) || (d[i]._initial.patronymic <= "�") || (d[i]._initial.patronymic >= "�") && (d[i]._initial.patronymic >= "�") || (d[i]._initial.patronymic >= "�"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���:" << endl;
		}



		cout << "������� ����� ������: ";

		while (!(cin >> d[i]._numbergroup.NomerGrup) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���:" << endl;
		}

		cout << "������� ����� �������� � ������ ������: ";
		while (!(cin >> d[i]._numberlistofgroup.NomerStudenta) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���:" << endl;
		}

		cout << "������� ���������� ������: ";
		while (!(cin >> d[i]._assesmentsstudents.Bal) || (d[i]._assesmentsstudents.Bal > 200))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���. ����������( max = 200):" << endl;
		}

		cout << "________________________________________________" << endl;

	}
}
// �������.
void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++)
	{


		cout << "������ �" << i + 1 << ":" << endl;
		cout << "���: "
			<< d[i]._initial.surname << endl
			<< d[i]._initial.name << endl
			<< d[i]._initial.patronymic << endl;

		cout << "����� ������: "
			<< d[i]._numbergroup.NomerGrup << endl;

		cout << "����� �������� � ������ ������: "
			<< d[i]._numberlistofgroup.NomerStudenta << endl;

		cout << "���������� ������: "
			<< d[i]._assesmentsstudents.Bal << endl;

		if (d[i]._assesmentsstudents.Bal >= 170)
		{
			cout << "������: \"�������\"" << endl;
		}

		if (d[i]._assesmentsstudents.Bal < 170 && d[i]._assesmentsstudents.Bal >= 140)
		{
			cout << "������: \"������\"" << endl;
		}

		if (d[i]._assesmentsstudents.Bal < 140 && d[i]._assesmentsstudents.Bal >= 100)
		{
			cout << "������: \"�����������������\"" << endl;
		}
		if (d[i]._assesmentsstudents.Bal < 100)
		{
			cout << "������: \"�������������������\"" << endl;
		}

		cout << "�����: "
			<< d[i]._time.day << "."
			<< d[i]._time.mon << "."
			<< d[i]._time.year << "�."
			<< d[i]._time.hour << ":"
			<< d[i]._time.min << endl;


		cout << "________________________________________________" << endl;
	}
}
// �������� ������ � ��������.
void DataChange(Data* (&d), int n)
{

	int _n;
	cout << "������� ����� ������ �������� (�� 1 �� " << n << "): ";

	while (!(cin >> _n) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������� ��� ���:" << endl;
	}

	system("cls");
	if (_n > 0)
	{

		_n--;// ��� ��� ���������� ���� �� ���� � �++ � � ��� �� 1
		time_t now;
		struct tm nowLocal;
		now = time(NULL);
		nowLocal = *localtime(&now);
		d[_n]._time.day = nowLocal.tm_mday;
		d[_n]._time.mon = nowLocal.tm_mon + 1;
		d[_n]._time.year = nowLocal.tm_year + 1900;
		d[_n]._time.hour = nowLocal.tm_hour;
		d[_n]._time.min = nowLocal.tm_min;

		cout << "������� ���: ";
		while (!(cin >> d[_n]._initial.surname) || (d[_n]._initial.surname <= "�") || (d[_n]._initial.surname >= "�") && (d[_n]._initial.surname >= "�") || (d[_n]._initial.surname >= "�"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���:" << endl;
		}

		while (!(cin >> d[_n]._initial.name) || (d[_n]._initial.name <= "�") || (d[_n]._initial.name >= "�") && (d[_n]._initial.name >= "�") || (d[_n]._initial.name >= "�"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���:" << endl;
		}

		while (!(cin >> d[_n]._initial.patronymic) || (d[_n]._initial.patronymic <= "�") || (d[_n]._initial.patronymic >= "�") && (d[_n]._initial.patronymic >= "�") || (d[_n]._initial.patronymic >= "�"))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���:" << endl;
		}


		cout << "������� ����� ������: ";
		while (!(cin >> d[_n]._numbergroup.NomerGrup) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���:" << endl;
		}

		cout << "������� ����� �������� � ������ ������: ";
		while (!(cin >> d[_n]._numberlistofgroup.NomerStudenta) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���:" << endl;
		}

		cout << "���������� ������: ";
		while (!(cin >> d[_n]._assesmentsstudents.Bal) || (d[_n]._assesmentsstudents.Bal > 200))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "������ �����. ���������� ��� ���. ����������(max = 200):" << endl;
		}

		cout << "�����: "
			<< d[_n]._time.day << " " << d[_n]._time.mon << " " << d[_n]._time.year << " " << d[_n]._time.hour << " " << d[_n]._time.min << endl;


		system("cls");
		cout << "������ ��������!" << endl;
	}
	else
		cout << "����� ������ �� �����!" << endl;

}
// ���������.
void SavingData(Data* d, int n, string students)
{

	//������� ����� ��� ������
	ofstream record(students); //�������� ����. 
	if (record) // ���� ��������
	{
		record << n << endl; // ���������� ���������� ������

		for (int i = 0; i < n; i++)
		{
			record << d[i]._initial.surname << endl;;
			record << d[i]._initial.name << endl;;
			record << d[i]._initial.patronymic << endl;;


			record << d[i]._numbergroup.NomerGrup << endl;;

			record << d[i]._numberlistofgroup.NomerStudenta << endl;;

			record << d[i]._assesmentsstudents.Bal << endl;

			if (i < n - 1)//���� ������� �� ��������� �� ������ �� ��������� �������
				record << d[i]._time.day << d[i]._time.mon << d[i]._time.year << d[i]._time.hour << d[i]._time.min << endl;
			else // ����� ��� �������
				record << d[i]._time.day << d[i]._time.mon << d[i]._time.year << d[i]._time.hour << d[i]._time.min;
		}
	}
	else

		cout << "������ �������� �����!" << endl;


	record.close(); // ��������� ����
}
// ����� ���������.
void Times(Data* d, int n)
{
	int enter = 0;
	int T;

	cout << "������� ���� ";

	while (!(cin >> T) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������� ��� ���:" << endl;
	}
	for (int i = 0; i < n; i++) {


		if (d[i]._time.day == T)
		{
			cout << "������ �" << i + 1 << ":" << endl;
			cout << "���: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;


			cout << "����� ������: "
				<< d[i]._numbergroup.NomerGrup << endl;

			cout << "����� �������� � ������ ������: "
				<< d[i]._numberlistofgroup.NomerStudenta << endl;

			cout << "���������� ������: "
				<< d[i]._assesmentsstudents.Bal << endl;

			if (d[i]._assesmentsstudents.Bal >= 170)
			{
				cout << "������: \"�������\"" << endl;
			}

			if (d[i]._assesmentsstudents.Bal < 170 && d[i]._assesmentsstudents.Bal >= 140)
			{
				cout << "������: \"������\"" << endl;
			}

			if (d[i]._assesmentsstudents.Bal < 140 && d[i]._assesmentsstudents.Bal >= 100)
			{
				cout << "������: \"�����������������\"" << endl;
			}
			if (d[i]._assesmentsstudents.Bal < 100)
			{
				cout << "������: \"�������������������\"" << endl;
			}

			cout << "�����: "
				<< d[i]._time.day << "." << d[i]._time.mon << "." << d[i]._time.year << "�." << " " << d[i]._time.hour << ":" << d[i]._time.min << endl;

			cout << "________________________________________________" << endl;

		}
		else
		{
			cout << "�������� ��� ������� " << i + 1 << " � ���� ���� �� �������!" << endl;
			cout << "________________________________________________" << endl;


		}
	}
}
// �������� ���� �����.
void Copy(Data* (&d_n), Data* (&d_o), int n)
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i]; //������������ ����� �������
	}
}
// ���������� ��������.
void AddDate(Data* (&d), int& n)
{
	//��������� ������ ������
	Data* buf;
	//�������� ������
	buf = new Data[n];
	//��������� � ��������� ������
	Copy(buf, d, n);
	//�������� ����� ������ �� 1 ������. ��� ��� ��������
	n++;
	d = new Data[n];
	Copy(d, buf, --n);// ���������� ������ ������� ���� � buf � ��� �������� ������

	time_t now;
	struct tm nowLocal;
	now = time(NULL);
	nowLocal = *localtime(&now);
	d[n]._time.day = nowLocal.tm_mday;
	d[n]._time.mon = nowLocal.tm_mon + 1;
	d[n]._time.year = nowLocal.tm_year + 1900;
	d[n]._time.hour = nowLocal.tm_hour;
	d[n]._time.min = nowLocal.tm_min;

	cout << "������� ���: ";

	while (!(cin >> d[n]._initial.surname) || (d[n]._initial.surname <= "�") || (d[n]._initial.surname >= "�") && (d[n]._initial.surname >= "�") || (d[n]._initial.surname >= "�"))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������� ��� ���:" << endl;
	}

	while (!(cin >> d[n]._initial.name) || (d[n]._initial.name <= "�") || (d[n]._initial.name >= "�") && (d[n]._initial.name >= "�") || (d[n]._initial.name >= "�"))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������� ��� ���:" << endl;
	}

	while (!(cin >> d[n]._initial.patronymic) || (d[n]._initial.patronymic <= "�") || (d[n]._initial.patronymic >= "�") && (d[n]._initial.patronymic >= "�") || (d[n]._initial.patronymic >= "�"))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������� ��� ���:" << endl;
	}


	cout << "������� ����� ������: ";
	while (!(cin >> d[n]._numbergroup.NomerGrup) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������� ��� ���:" << endl;
	}

	cout << "������� ����� �������� � ������ ������: ";
	while (!(cin >> d[n]._numberlistofgroup.NomerStudenta) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������� ��� ���:" << endl;
	}

	cout << "������� ���������� ������: " << endl;
	while (!(cin >> d[n]._assesmentsstudents.Bal) || (d[n]._assesmentsstudents.Bal > 200))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������� ��� ���. ����������(max = 200):" << endl;
	}

	cout << "________________________________________________" << endl;


	delete[]buf;
}
// �������� ���� ������� �������.
void Copy(Data& d_n, Data& d_o)
{
	d_n._initial.surname = d_o._initial.surname;
	d_n._initial.name = d_o._initial.name;
	d_n._initial.patronymic = d_o._initial.patronymic;

}
// ���������� �� ��������.
void Sorting(Data* d, int n)
{
	// ��������� ����������
	Data buf;
	// ���������� ������� ��������
	for (int i = 0; i < n;i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//������� ����������
			if (d[i]._initial.surname > d[j]._initial.surname)
			{
				Copy(buf, d[j]); // ������ d[j] �������� � buf
				Copy(d[j], d[i]); // ������ �������
				Copy(d[i], buf); // ������ bud �������� � d[i]
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
// �������� ������ ��������.
void Delete(Data* (&d), int& n)
{
	int _n;
	cout << "������������ ������ �������� (�� 1 �� " << n << " ) �������� ����� ��� ��������:";
	while (!(cin >> _n) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������� ��� ���:" << endl;
	}
	_n--;
	//�������� ��� ����� ���������� ��������
	if (_n >= 0 && _n < n)
	{
		//��������� �����
		Data* buf = new Data[n];

		Copy(buf, d, n); //����������� � ���� ��������� ����� ������


		//�������� ����� ������
		--n; // ��� ��� ������� ����� � �������� ������� �������� ������ �� 1 ������
		d = new Data[n];// ������ ������� ���� � ������� �������� ��� ����� � ����� ��� ��������� ������ buf
		int q = 0;
		//���������� ������ ����� ���������
		for (int i = 0; i <= n; i++)
		{
			if (i != n) // ���� ������� �� �������� ��� ������� �� ����� �������
			{
				d[q] = buf[i]; // ��������� ������ �� ������ � d[q]
				++q;

			}
		}
		system("cls");
		delete[]buf;
		cout << "������ �������!" << endl;
	}
	else
		cout << "����� ������ �� �����!" << endl;



}
// ����� ������ � ������������ ���������.
void Assesment(Data* d, int n)
{
	int enter = 0;

	cout << "�������� �����: " << endl;
	cout << "1.��������, ������� ������ �� \"�������\"." << endl
		<< "2.��������, ������� ������ �� \"������\"." << endl
		<< "3.��������, ������� ������ �� \"�����������������\"." << endl
		<< "4.��������, ������� ������ �� \"�������������������\"." << endl;


	while (!(cin >> enter) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������� ��� ���:" << endl;
	}
	for (int i = 0; i < n; i++)
	{

		if (enter == 1)
		{
			if (d[i]._assesmentsstudents.Bal >= 170)
			{

				cout << "������ �" << i + 1 << ":" << endl;
				cout << "���: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;

				cout << "����� ������: "
					<< d[i]._numbergroup.NomerGrup << endl;

				cout << "����� �������� � ������ ������: "
					<< d[i]._numberlistofgroup.NomerStudenta << endl;

				cout << "���������� ������: "
					<< d[i]._assesmentsstudents.Bal << endl;


				cout << "________________________________________________" << endl;
				break;

			}
			else
			{
				cout << "��������� ���!" << endl;
			}
		}
		if (enter == 2)
		{
			if (d[i]._assesmentsstudents.Bal < 170 && d[i]._assesmentsstudents.Bal >= 140)
			{
				cout << "������ �" << i + 1 << ":" << endl;
				cout << "���: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;


				cout << "����� ������: "
					<< d[i]._numbergroup.NomerGrup << endl;

				cout << "����� �������� � ������ ������: "
					<< d[i]._numberlistofgroup.NomerStudenta << endl;

				cout << "���������� ������: "
					<< d[i]._assesmentsstudents.Bal << endl;


				cout << "________________________________________________" << endl;
				break;
			}
			else
			{
				cout << "��������� ���!" << endl;
			}

		}
		if (enter == 3)
		{
			if (d[i]._assesmentsstudents.Bal < 140 && d[i]._assesmentsstudents.Bal >= 100)
			{
				cout << "������ �" << i + 1 << ":" << endl;
				cout << "���: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;


				cout << "����� ������: "
					<< d[i]._numbergroup.NomerGrup << endl;

				cout << "����� �������� � ������ ������: "
					<< d[i]._numberlistofgroup.NomerStudenta << endl;

				cout << "���������� ������: "
					<< d[i]._assesmentsstudents.Bal << endl;


				cout << "________________________________________________" << endl;
				break;
			}
			else
			{
				cout << "��������� ���!" << endl;
			}
		}
		if (enter == 4)
		{
			if (d[i]._assesmentsstudents.Bal < 100)
			{
				cout << "������ �" << i + 1 << ":" << endl;
				cout << "���: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;


				cout << "����� ������: "
					<< d[i]._numbergroup.NomerGrup << endl;

				cout << "����� �������� � ������ ������: "
					<< d[i]._numberlistofgroup.NomerStudenta << endl;

				cout << "���������� ������: "
					<< d[i]._assesmentsstudents.Bal << endl;


				cout << "________________________________________________" << endl;
				break;
			}
			else
			{
				cout << "��������� ���!" << endl;
			}
		}
	}




}
// ���� 2 �������.
int MenuEnter4() { //����� ����, ������������ ���������

	auto key = 0;
	int code;
	do {
		system("cls");
		key = (key + 8) % 8;
		if (key == 0) cout << "-> �������� ����� ������ � ��������." << endl;
		else  cout << "   �������� ����� ������ � ��������." << endl;

		if (key == 1) cout << "-> �������� ��������� � ��� ��������� ������." << endl;
		else  cout << "   �������� ��������� � ��� ��������� ������." << endl;

		if (key == 2) cout << "-> ����� ���� ������ � ���������." << endl;
		else  cout << "   ����� ���� ������ � ���������." << endl;

		if (key == 3) cout << "-> ����� ������ ��������� �� �������" << endl;
		else  cout << "   ����� ������ ��������� �� �������" << endl;

		if (key == 4) cout << "-> �������� ������ ��������" << endl;
		else  cout << "   �������� ������ ��������" << endl;

		if (key == 5) cout << "-> �������� ������ ��������" << endl;
		else  cout << "   �������� ������ ��������" << endl;

		if (key == 6) cout << "-> ������������ ���������" << endl;
		else  cout << "   ������������ ���������" << endl;

		if (key == 7) cout << "-> ������� ����" << endl;
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
// ������� ������ � ���� 2 �������.
void MainEnter1()
{
	List L;
	int n = 0;
	int* a = new int[n];
	auto exit = 0;
	int _actions, amountOfData = 0; //���������� ������� ��������� ���������� ������
	//������ ������
	Data* d = new Data[amountOfData]; //��������� ������� ��������� �� ������

	do {
		const auto answer = MenuEnter4();

		switch (answer)
		{

		case 0:
		{
			system("cls"); //������� �������

			DataEntry(d, amountOfData); //������� ����� ������ � �������(-�, ��)(������, ���������� ������)

			SavingData(d, amountOfData, "students.txt"); //���������� � ���� students

			if (amountOfData != 0)
			{
				Print(d, amountOfData); //�����
			}
			else
				cout << "� ������� �� ����� �� ����!" << endl;

			system("Pause"); // �������� �������
			system("cls"); // ������� �������

			break; // ������
		}
		case 1:
		{
			system("cls");
			if (amountOfData != 0)
			{
				DataChange(d, amountOfData); //��������� ������ � ��������
				SavingData(d, amountOfData, "students.txt"); // ���������� � ���� students
			}
			else
				cout << "� ������� �� ����� �� ����!" << endl;
			Print(d, amountOfData); // �����
			system("Pause");
			system("cls");
			break;
		}

		case 2:
		{
			system("cls");
			if (amountOfData != 0)
			{
				Sorting(d, amountOfData); // ��������� �� ��������
				Print(d, amountOfData); // �������
				SavingData(d, amountOfData, "students.txt");
			}
			else

				cout << "� ������� �� ����� �� ����!" << endl;
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
				cout << "� ������� �� ����� �� ����!" << endl;

			system("Pause"); // �������� �������
			system("cls");

			break;
		}
		case 4:
		{
			system("cls");
			if (amountOfData != 0)
			{
				AddDate(d, amountOfData); // �������� ��������
				amountOfData++;
				SavingData(d, amountOfData, "students.txt"); // ����������
			}
			else
				cout << "� ������� �� ����� �� ����!" << endl;
			system("Pause"); // �������� �������
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
				cout << "� ������� �� ����� �� ����!" << endl;
			system("Pause"); // �������� �������
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
				cout << "� ������� �� ����� �� ����!" << endl;
			system("Pause"); // �������� �������
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