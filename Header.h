// ��������� �������������, ��������������� ��� ������ �� �������� ����������� ������������� �����.
#pragma once
// �� ���� �� ������������.
#define _CRT_SECURE_NO_WARNINGS 
// ����������� ������������� �����, ������� ��������� �������� � �������� �����/������.
#include <iostream>
// ����������� ������������� �����, ��� �������� ���������� ���������� ������������. ��� ���� _getch().
#include <conio.h> 
// ����������� ������������� �����, � ������� ���������� ��������� ������� SetConsoleCP(������� �������) � SetConsoleOutputCP(������� �������).
#include <windows.h>
// ����������� ������������� �����, ��� ������������� �����.
#include <stack> 
// ����������� ������������� �����, ������� ������������� ��������� ��� ������/������ ������ ��/� ����.
#include <fstream>
// ����������� ������������� �����, ��� ������ �� ��������.
#include <chrono>
// ����������� ������������� �����, ��� ������ �� ��������. 
#include <string>
// ������������ ����, ����� �� ���� ����������� ������������� ����������.
using namespace std;
// ������������ ����, ����� �� ���� ����������� ������������� ����������.
using namespace std;
// ������������ ����, ����� �� ���� ����������� ����� ��������.
using namespace chrono;
int Menu() 
{ 

	auto key = 0;
	int code;

	do {
		system("cls");
		key = (key + 3) % 3;
		if (key == 0) cout << "-> ������� 1." << endl;
		else  cout << "   ������� 1." << endl;

		if (key == 1) cout << "-> ������� 2." << endl;
		else  cout << "   ������� 2." << endl;

		if (key == 2) cout << "-> �����" << endl;
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
int Menu5()
{

	auto key = 0;
	int code;

	do {
		system("cls");
		key = (key + 6) % 6;
		if (key == 0) cout << "-> ������� ��������� ������." << endl;
		else  cout << "   ������� ��������� ������." << endl;

		if (key == 1) cout << "-> ����� ������ � ����." << endl;
		else  cout << "   ����� ������ � ����." << endl;

		if (key == 2) cout << "-> �������." << endl;
		else  cout << "   �������." << endl;

		if (key == 3) cout << "-> ��������." << endl;
		else  cout << "   ��������." << endl;

		if (key == 4) cout << "-> �����." << endl;
		else  cout << "   �����." << endl;

		if (key == 5) cout << "-> �����." << endl;
		else  cout << "   �����." << endl;


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