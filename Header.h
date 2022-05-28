#pragma once
using namespace std;
#include <iostream>
#include <fstream>

enum key { CLASSIC, DIAGONAL, TRIANGLE };

struct classic {
	int x; // ������
	int** arrC;

};
struct diagonal {
	int x; // ������
	int** arrD;
};
struct triangle {
	int x; // ������
	int** arrT;
};





// ���������, ���������� ��� ��������� ������
struct Arr {
	// �������� ������ ��� ������ �� �����
	
	key k; // ����
	int outType;
	// ������������ ������������
	union {
		classic c;
		diagonal d;

		triangle t;

	};
	
};


// ������ � ����������
struct Node {
	
	
	Node* Prev;
	Node* Next;
	Arr arr;


};
//���������
struct container
{
	int length = 0;
	Node* Current = NULL;
	Node* Head = NULL;
};

//------------

//void In(classic& c, ifstream& ist);
//void In(diagonal& c, ifstream& ist);
//Arr* In(ifstream& ifst);
//void Out(classic& c, ofstream& ist);
//void Out(diagonal& c, ofstream& ist);
//Arr* Out(Arr &arr,ofstream& ifst);
void Init(container* c);
void Clear(container* c);
void InCont(ifstream& ifst, container* c);
void OutCont(ofstream& ofst, container* c);
int Summa(Arr r);
bool Compare(Arr* first, Arr* second);
void Sort(container& c);
//-----------------------------------------------------
// C�������� ������ ���� ����������� ��������


