#pragma once
#include "Header.h"
// Узел.
struct Node
{
	int data;
	int ratio = 0;
	Node* l = nullptr;
	Node* r = nullptr;
};
// Шаблон класса.
template <class T>
// Лист.
struct list
{
	T data;
	list* next = nullptr;
};
// Поиск узлов.
Node* LookNode(Node* present, int val)
{
	if (present == nullptr)
		return nullptr;
	if (val > present->data)
	{
		if (present->r != nullptr)
			present = LookNode(present->r, val);
	}
	else if (val < present->data)
	{
		if (present->l != nullptr)
			present = LookNode(present->l, val);
	}
	return present;
}
// Поиск с прошлым.
Node* LookNode(Node* present, Node*& last, int val)
{
	if (present == nullptr)
		return nullptr;
	if (val > present->data)
	{
		if (present->r != nullptr)
		{
			last = present;
			present = LookNode(present->r, last, val);
		}
	}
	else if (val < present->data)
	{
		if (present->l != nullptr)
		{
			last = present;
			present = LookNode(present->l, last, val);
		}
	}
	return present;
}
// Проходимся прямо по дереву.
void StraightTree(Node* origin)
{
	cout << origin->data << " ";
	if (origin->l != nullptr)
		StraightTree(origin->l);
	if (origin->r != nullptr)
		StraightTree(origin->r);
}
// Проходимся обратно по дереву.
void BackTree(Node* origin)
{
	if (origin->l != nullptr)
		BackTree(origin->l);
	if (origin->r != nullptr)
		BackTree(origin->r);
	cout << origin->data << " ";
}
// Проходимся так же одинаково.
void EquallyTree(Node* origin)
{
	if (origin->l != nullptr)
		EquallyTree(origin->l);
	cout << origin->data << " ";
	if (origin->r != nullptr)
		EquallyTree(origin->r);
}
// С предыдущими.
Node* LookNode(Node* present, list <Node*>*& head, int val)
{
	if (present == nullptr)
		return nullptr;
	list<Node*>* newl;
	if (val > present->data)
	{
		head->data = present;
		if (present->r != nullptr)
		{
			newl = new list<Node*>;
			newl->next = head;
			head = newl;
			present = LookNode(present->r, head, val);
		}
	}
	else if (val < present->data)
	{
		head->data = present;
		if (present->l != nullptr)
		{
			newl = new list<Node*>;
			newl->next = head;
			head = newl;
			present = LookNode(present->l, head, val);
		}
	}
	return present;
}
// Максимальная длина.
int MaxLenght(Node* origin)
{
	int lenght = 1, l = 0, r = 0;
	if (origin->l != nullptr)
		l = MaxLenght(origin->l);
	if (origin->r != nullptr)
		r = MaxLenght(origin->r);

	if (l >= r)
		lenght += l;
	else
		lenght += r;

	return lenght;
}
// Преобразование коэффициентов.
void TransformationCoefficients(Node* origin)
{
	if (origin != nullptr)
	{
		int maxL = 0, maxR = 0;
		if (origin->l != nullptr)
		{
			maxL = MaxLenght(origin->l);
			TransformationCoefficients(origin->l);
		}

		if (origin->r != nullptr) {
			maxR = MaxLenght(origin->r);
			TransformationCoefficients(origin->r);
		}

		origin->ratio = maxR - maxL;
	}
}
// Маленький поворот направо.
void LittleTreeRight(Node* present, Node*& origin)
{
	Node* last = nullptr, * q;
	LookNode(origin, last, present->data);
	if (present->r == nullptr)
	{
		if (present->l->r == nullptr)
		{
			q = present;
			present = present->l;
			q->l = nullptr;
			present->r = q;
			if (last != nullptr)
			{
				if (present->data > last->data)
					last->r = present;
				else
					last->l = present;
			}
			else
				origin = present;
		}
		else
		{
			q = present;
			present = present->l->r;
			present->l = q->l;
			q->l->r = nullptr;
			q->l = nullptr;
			present->r = q;
			if (last != nullptr)
			{
				if (present->data > last->data)
					last->r = present;
				else
					last->l = present;
			}
			else
				origin = present;
		}
	}
	else
	{
		q = present->l->r;
		present->l->r = present;
		Node* q2 = present->l;
		present->l = q;
		present = q2;
		if (last != nullptr)
		{
			if (present->data > last->data)
				last->r = present;
			else
				last->l = present;
		}
		else
			origin = present;
	}
	TransformationCoefficients(origin);
}
// Маленький поворот налево.
void LittleTreeLeft(Node* present, Node*& origin)
{
	Node* last = nullptr, * q;
	LookNode(origin, last, present->data);
	if (present->l == nullptr)
	{
		if (present->r->l == nullptr)
		{
			q = present;
			present = present->r;
			q->r = nullptr;
			present->l = q;
			if (last != nullptr)
			{
				if (present->data > last->data)
					last->r = present;
				else
					last->l = present;
			}
			else
				origin = present;
		}
		else
		{
			q = present;
			present = present->r->l;
			present->r = q->r;
			q->r->l = nullptr;
			q->r = nullptr;
			present->l = q;
			if (last != nullptr)
			{
				if (present->data > last->data)
					last->r = present;
				else
					last->l = present;
			}
			else
				origin = present;
		}
	}
	else
	{
		q = present->r->l;
		present->r->l = present;
		Node* q2 = present->r;
		present->r = q;
		present = q2;
		if (last != nullptr)
		{
			if (present->data > last->data)
				last->r = present;
			else
				last->l = present;
		}
		else
			origin = present;
	}
	TransformationCoefficients(origin);
}
// Большой поворот направо.
void BigTreeRight(Node* present, Node*& origin)
{
	Node* last = nullptr, * q, * q2;
	LookNode(origin, last, present->data);

	q = present->l;
	present->l = q->r->r;
	q2 = q->r;
	q->r = q->r->l;
	q2->l = q;
	q2->r = present;
	present = q2;
	if (last != nullptr)
	{
		if (present->data > last->data)
			last->r = present;
		else
			last->l = present;
	}
	else
		origin = present;

	TransformationCoefficients(origin);
}
// Большой поворот налево.
void BigTreeLeft(Node* present, Node*& origin)
{
	Node* last = nullptr, * q, * q2;
	LookNode(origin, last, present->data);
	q = present->r;
	present->r = q->l->l;
	q2 = q->l;
	q->l = q->l->r;
	q2->r = q;
	q2->l = present;
	present = q2;
	if (last != nullptr)
	{
		if (present->data > last->data)
			last->r = present;
		else
			last->l = present;
	}
	else
		origin = present;
	TransformationCoefficients(origin);
}
// Добавить в дерево.
bool ApendTree(Node*& origin, int val, int& N)
{
	// Коэффициенты баланса
	const int min = -1, max = 1;
	list<Node*>* head, * q;
	head = new list<Node*>;
	Node* present = LookNode(origin, head, val);

	if (present == nullptr)
	{
		delete head;
		return 0;
	}
	if (val == present->data)
	{
		do
		{
			q = head->next;
			delete head;
			head = q;
		} while (head != nullptr);
		return 0;
	}
	N++;
	Node* newG;
	q = new list <Node*>;
	if (val > present->data)
	{
		newG = new Node;
		present->r = newG;
		newG->data = val;
		q->data = newG;
	}
	if (val < present->data) {
		newG = new Node;
		present->l = newG;
		newG->data = val;
		q->data = newG;
	}
	q->next = head;
	head = q;
	// Пересчет коэффициентов.
	do {
		if (head->data->data > head->next->data->data)
			head->next->data->ratio++;
		else
			head->next->data->ratio--;
		head = head->next;
	} while (!((head->data->ratio == 0) || (head->data->ratio > max) || (head->data->ratio < min) || (head->next == nullptr)));
	if (head->data->ratio < min)
	{
		if (head->data->r == nullptr || val <= head->data->l->data)
			LittleTreeRight(head->data, origin);
		else
			BigTreeRight(head->data, origin);
	}
	else if (head->data->ratio > max) {
		if (head->data->l == nullptr || val >= head->data->r->data)
			LittleTreeLeft(head->data, origin);
		else
			BigTreeLeft(head->data, origin);
	}
	head = q;
	while (head != nullptr)
	{
		q = head;
		head = head->next;
		delete q;
	}
	return 1;
}
// Баланс.
Node* Balancе(Node* origin) {
	// Коэффициенты баланса
	const int min = -1, max = 1;
	Node* p = nullptr;
	if (origin->ratio < min or origin->ratio > max)
		return origin;
	if (origin->l != nullptr)
		p = Balancе(origin->l);
	if (p != nullptr)
		return p;
	if (origin->r != nullptr)
		p = Balancе(origin->r);
	return p;
}
// Балансировка деревьев.
void TreeBalancing(Node*& origin) {
	// Коэффициенты баланса
	const int min = -1, max = 1;
	do {
		if (origin == nullptr)
			break;
		TransformationCoefficients(origin);
		Node* p = Balancе(origin);
		if (p == nullptr)
			break;

		if (p->ratio < min)
		{
			int l = 0, r = 0;
			if ((p->l != nullptr) && (p->l->l != nullptr))
				l = MaxLenght(p->l->l);
			if ((p->l != nullptr) && (p->l->r != nullptr))
				r = MaxLenght(p->l->r);

			if ((p->r == nullptr) || (l >= r))
				LittleTreeRight(p, origin);
			else
				BigTreeRight(p, origin);
		}
		else if (p->ratio > max)
		{
			int l = 0, r = 0;
			if ((p->r != nullptr) && (p->r->r != nullptr))
				r = MaxLenght(p->r->r);
			if ((p->r != nullptr) && (p->r->l != nullptr))
				l = MaxLenght(p->r->l);

			if ((p->l == nullptr) || (r >= l))
				LittleTreeLeft(p, origin);
			else
				BigTreeLeft(p, origin);
		}
	} while (1);
}
// Удалить из дерева.
bool DeleteFromTree(Node*& origin, int val)
{
	if (origin == nullptr)
		return 0;
	Node* last = nullptr;
	Node* present = LookNode(origin, last, val);
	if (val != present->data)
		return 0;

	if ((present->l != nullptr) && (present->r != nullptr))
	{
		Node* p = present->l;
		while (p->r != nullptr)
			p = p->r;
		if (last != nullptr) {
			if (last->data < present->data)
				last->r = present->l;
			else
				last->l = present->l;
		}
		else
			origin = present->l;
		p->r = present->r;
		delete present;
	}
	else if (present->l != nullptr)
	{
		if (last != nullptr) {
			if (last->data < present->data)
				last->r = present->l;
			else
				last->l = present->l;
		}
		else
			origin = present->l;
		delete present;
	}
	else if (present->r != nullptr)
	{
		if (last != nullptr)
		{
			if (last->data < present->data)
				last->r = present->r;
			else
				last->l = present->r;
		}
		else
			origin = present->r;
		delete present;
	}
	else
	{
		if (last != nullptr)
		{
			if (last->data < present->data)
				last->r = nullptr;
			else
				last->l = nullptr;
		}
		else
			origin = nullptr;
		delete present;
	}
	TreeBalancing(origin);

	return 1;
}
// Случайное дерево.
void RandomTree(int N, Node*& origin, int diapason)
{
	origin = new Node;
	origin->data = rand() % diapason - diapason / 2;
	for (int i = 1; i < N;)
		ApendTree(origin, rand() % diapason - diapason / 2, i);
}

// Удаление дерева.
void DeleteTree(Node* origin) {
	if (origin->l != nullptr)
		DeleteTree(origin->l);
	if (origin->r != nullptr)
		DeleteTree(origin->r);
	delete origin;
}
// Int в char.
char* IntToChar(int i) {
	char* str = new char[15];
	bool mn = 0;
	if (i < 0) {
		i = abs(i);
		mn = 1;
	}
	else if (i == 0)
	{
		str[0] = (unsigned char)(48);
		str[1] = '\0';
		return str;
	}
	str[0] = '\0';
	while (i > 0) {
		for (int i = 14; i > 0; i--)
			str[i] = str[i - 1];
		str[0] = (unsigned char)(48 + i % 10);
		i = i / 10;
	}
	if (mn) {
		for (int i = 14; i > 0; i--)
			str[i] = str[i - 1];
		str[0] = '-';
	}
	return str;
}
// Матрица сдвига вправо.
void RightMatrix(int** matrix, int i, int j, int N)
{
	int breadth = N * 3 + 2;
	int nine = -999999, nine_1 = -999998;
	for (int q = i; q >= 0; q--) {
		for (int k = breadth - 1; k > j; k--)
			matrix[q][k] = matrix[q][k - 1];
		if (matrix[q][j] != nine)
			matrix[q][j] = nine_1;
	}
}
// Вывод дерева.
void TreeOutput(ofstream& file, const Node* origin, int N, bool in_file)
{
	const int min = -1, max = 1;
	int nine = -999999, nine_1 = -999998;
	if (origin != nullptr)
	{
		int breadth = N * 3 + 2;
		if (in_file)
			file << "Дерево" <<  ".\n";

		list<const Node*>* head, * present, * newt;
		head = new list<const Node*>;
		head->data = origin;
		int** matrix;
		int* startPoint = new int[N / 2];
		int i = 0, j = 0, startTail = 1;
		matrix = new int* [N * 2];
		for (int i = 0; i < N * 2; i++)
		{
			matrix[i] = new int[breadth];
			for (int j = 0; j < breadth; j++)
				matrix[i][j] = nine;
		}
		startPoint[0] = 1;

		while (head != nullptr) {
			j = 0;
			present = head;
			while (present != nullptr)
			{
				matrix[i][startPoint[j]] = present->data->data;
				if (present->data->l != nullptr)
				{
					for (int q = 0; q < 3; q++)
					{
						RightMatrix(matrix, i + 1, startPoint[j], N);
						for (int q = j + 1; q < startTail; q++)
							startPoint[q]++;
						matrix[i + 1][startPoint[j]] = nine_1;
					}
					startTail++;
					for (int i = startTail; i > j; i--)
						startPoint[i] = startPoint[i - 1];
					j++;
					startPoint[j] += 3;
				}

				if (present->data->r != nullptr)
				{
					for (int q = 0; q < 3; q++)
					{
						RightMatrix(matrix, i + 1, startPoint[j] + 1, N);
						for (int q = j + 1; q < startTail; q++)
							startPoint[q]++;
						matrix[i + 1][startPoint[j] + 1] = nine_1;
					}
					startPoint[j] += 3;
					j++;
				}
				else
				{
					for (int i = j; i < startTail; i++)
						startPoint[i] = startPoint[i + 1];
					startTail--;
				}
				present = present->next;
			}
			present = head;
			while (present != nullptr)
			{
				bool b = 0;
				if (present->data->r != nullptr)
				{
					newt = new list<const Node*>;
					newt->next = present->next;
					present->next = newt;
					newt->data = present->data->r;
					b = 1;
				}
				if (present->data->l != nullptr)
				{
					present->data = present->data->l;
					present = present->next;
				}
				else
				{
					if (present == head)
					{
						head = present->next;
						delete present;
						present = head;
					}
					else
					{
						newt = present;
						present = head;
						while (present->next != newt)
							present = present->next;
						present->next = newt->next;
						delete newt;
						present = present->next;
					}
				}
				if (b)
					present = present->next;
			}
			i += 2;
		}

		for (int q = 0; q < i - 1; q++)
		{
			if (q % 2 == 0)
			{
				for (j = 0; j < breadth; j++)
				{
					if (matrix[q][j] > nine_1)
					{
						if (in_file)
							file << "|";
						else
							cout << "|";
						j++;
						while (matrix[q][j] > nine_1&& j < breadth)
						{
							j++;
							if (in_file)
								file << " ";
							else
								cout << " ";
						}
						j--;
					}
					else if (in_file)
						file << " ";
					else
						cout << " ";
				}
				if (in_file)
					file << endl;
				else
					cout << endl;
				if (in_file)
				{
					for (j = 0; j < breadth; j++)
					{
						if (matrix[q][j] > nine_1)
						{
							file << (unsigned char)149;
							j++;
							while (matrix[q][j] > nine_1&& j < breadth) {
								j++;
								file << " ";
							}
							j--;
						}
						else
							file << " ";
					}
					file << endl;
				}
			}
			bool b = 0;
			for (j = 0; j < breadth; j++)
			{
				if (!b && matrix[q][j] == nine_1 && (matrix[q + 1][j] != nine || matrix[q - 1][j - 1] != nine))
					b = 1;
				if (b && matrix[q][j] == nine)
					b = 0;
				if (matrix[q][j] == nine || matrix[q][j] == nine_1 && !b)
				{
					matrix[q][j] = nine;
					if (in_file)
						file << " ";
					else
						cout << " ";
				}
				else if (matrix[q][j] == nine_1)
				{
					if (matrix[q + 1][j] != nine && matrix[q][j - 1] == nine)
						if (in_file)
							file << ",";
						else
							cout << ",";
					else if (matrix[q + 1][j] != nine)
						if (in_file)
							file << ".";
						else
							cout << ".";
					else if (in_file)
						file << "-";
					else
						cout << "-";
				}
				else {
					if (in_file)
						file << matrix[q][j];
					else
						cout << matrix[q][j];
					char* str = IntToChar(matrix[q][j]);
					j += strlen(str) - 1;
					delete[] str;
				}
			}
			if (in_file)
				file << endl;
			else
				cout << endl;
		}

		for (i = 0; i < N * 2; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
}
// Поиск отрицательного узла.
int MinusLookNode(Node* origin)
{
	int val = 0;
	if (origin->data < 0)
		return origin->data;
	if (origin->l != nullptr)
		val = MinusLookNode(origin->l);
	return val;
}
// Поиск.
int StrangeSearch(Node*& origin) {
	int val = 0;
	if (origin->data % 2 != 0)
		return origin->data;
	if (origin->l != nullptr)
		val = StrangeSearch(origin->l);
	if (val != 0)
		return val;
	if (origin->r != nullptr)
		val = StrangeSearch(origin->r);
	return val;
}
