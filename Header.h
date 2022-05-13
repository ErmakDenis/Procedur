#pragma once
using namespace std;
#include <iostream>
#include <fstream>


enum key { CLASSIC, DIAGONAL };
struct classic {
	int x; // размер
	int** arrC;
};
struct diagonal {
	int x; // размер
	int** arrD;
};
/*struct triangle {
	int x; // размер
	int** arrT;
}; */




// структура, обобщающая все имеющиеся фигуры
struct Arr {
	// значения ключей для каждой из фигур
	
	key k; // ключ
	// используемые альтернативы
	union {
		classic c;
		diagonal d;
		//triangle t;
	};
	
};


// запись в контейнере
struct Node {
	
	
	Node* Prev;
	Node* Next;
	Arr arr;


};
//контейнер
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
void OutClassicCont(ofstream& ofst, container* c);

//int Summa(Arr r);


