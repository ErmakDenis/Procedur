#include <iostream>
#include <fstream>
#include "Header.h"

void Init(container& c) { c.length = 0; }
void Clear(container* c) {
	c->Current = NULL;
	c->length = 0;
	c->Head = 0;
}

void InCont(ifstream& ifst, container* c)
{
	int k = 0;
	Node* newNode = new Node;
	//classic c;
	//diagonal d;
	//Arr arr;
	while (!ifst.eof())
	{
		ifst >> k;
		switch (k)
		{
			case 1:
				newNode = new Node;
				newNode->arr.k = CLASSIC;

				ifst >> newNode->arr.c.x;
				ifst >> newNode->arr.outType;//new field

				//объ€вл€ем массив
				newNode->arr.c.arrC = new int* [newNode->arr.c.x];
				for (int i = 0; i < newNode->arr.c.x; i++)
				{
					newNode->arr.c.arrC[i] = new int[newNode->arr.c.x];
				}

				//заполн€ем массив
				for (int i = 0; i < newNode->arr.c.x; i++)
				{
					for (int j = 0; j < newNode->arr.c.x; j++)
					{
						ifst >> newNode->arr.c.arrC[i][j];
					}
				}
				if (c->Head == NULL)
				{
					c->Head = newNode;
					c->Head->Next = newNode;
					c->Head->Prev = newNode;
					c->length = 1;
				}
				else
				{
					c->Current = c->Head;
					while (c->Current->Next != c->Head)
					{
						c->Current = c->Current->Next;
					}
					c->Current->Next = newNode;
					c->Current->Next->Prev = c->Current;
					c->Current = c->Current->Next;
					c->Current->Next = c->Head;
					c->Head->Prev = c->Current;
					c->length++;
				}

				break;
				//--------------------------------------------
			case 2:
				newNode = new Node;
				newNode->arr.k = DIAGONAL;
				ifst >> newNode->arr.d.x;
				ifst >> newNode->arr.outType;//new field
				//объ€вл€ем массив
				newNode->arr.d.arrD = new int* [newNode->arr.d.x];
				for (int i = 0; i < newNode->arr.d.x; i++)
				{
					newNode->arr.d.arrD[i] = new int[newNode->arr.d.x];
				}

				//заполн€ем массив
				for (int i = 0; i < newNode->arr.d.x; i++)
				{
					for (int j = 0; j < newNode->arr.d.x; j++)
					{
						if (i == j)
							ifst >> newNode->arr.d.arrD[i][j];
						else
							newNode->arr.d.arrD[i][j] = 0;
					}
				}
				if (c->Head == NULL)
				{
					c->Head = newNode;
					c->Head->Next = newNode;
					c->Head->Prev = newNode;
					c->length = 1;
				}
				else
				{
					c->Current = c->Head;
					while (c->Current->Next != c->Head)
					{
						c->Current = c->Current->Next;
					}
					c->Current->Next = newNode;
					c->Current->Next->Prev = c->Current;
					c->Current = c->Current->Next;
					c->Current->Next = c->Head;
					c->Head->Prev = c->Current;
					c->length++;
				}
				break;


			case 3:
				newNode = new Node;
				newNode->arr.k = TRIANGLE;
				ifst >> newNode->arr.t.x;

				//объ€вл€ем массив
				newNode->arr.t.arrT = new int* [newNode->arr.t.x];
				for (int i = 0; i < newNode->arr.t.x; i++)
				{
					newNode->arr.t.arrT[i] = new int[i+1];
				}

				//заполн€ем массив
				for (int i = 0; i < newNode->arr.t.x; i++)
				{
					for (int j = 0; j < i+1; j++)
					{
						ifst >> newNode->arr.t.arrT[i][j];
					}
				}
				if (c->Head == NULL)
				{
					c->Head = newNode;
					c->Head->Next = newNode;
					c->Head->Prev = newNode;
					c->length = 1;
				}
				else
				{
					c->Current = c->Head;
					while (c->Current->Next != c->Head)
					{
						c->Current = c->Current->Next;
					}
					c->Current->Next = newNode;
					c->Current->Next->Prev = c->Current;
					c->Current = c->Current->Next;
					c->Current->Next = c->Head;
					c->Head->Prev = c->Current;
					c->length++;
				}
			break;
			default:
				break;
		}
	}
}
void OutCont(ofstream& ofst, container* c)
{
	

	ofst << "Container contents " << c->length << " elements." << endl;
	int i = 1;
	if (c->Head == NULL)
	{
		return;
	}
	c->Current = c->Head;
	Sort(*c);
	do
	{
		ofst << i << ": ";
		if (c->Current->arr.k==CLASSIC)
		{

			ofst << "Size: " << c->Current->arr.c.x<<" Type: CLASSIC" << endl;



			// 
			if (c->Current->arr.outType == 1) {
				for (int i = 0; i < c->Current->arr.c.x; i++)
				{
					for (int j = 0; j < c->Current->arr.c.x; j++)
						ofst << c->Current->arr.c.arrC[i][j] << " ";
					ofst << endl;
				}
			}
			ofst <<"Sum of array: " << Summa(c->Current->arr) << endl;

			

			if (c->Current->arr.outType == 2) {
				for (int i = 0; i < c->Current->arr.c.x; i++)
				{
					for (int j = 0; j < c->Current->arr.c.x; j++)
						ofst << c->Current->arr.c.arrC[j][i] << " ";
					ofst << endl;
				}

			}
			if (c->Current->arr.outType == 3)
			{
				for (int i = 0; i < c->Current->arr.c.x; i++)
				{
					for (int j = 0; j < c->Current->arr.c.x; j++)
						ofst << c->Current->arr.c.arrC[i][j] << " ";
					
				}
			}

		}
		else
		{
			if (c->Current->arr.k == DIAGONAL)
			{
				ofst << "Size: " << c->Current->arr.d.x << " Type: DIAGONAL" << endl;
				if (c->Current->arr.outType == 1)
				{

					for (int i = 0; i < c->Current->arr.d.x; i++)
					{
						for (int j = 0; j < c->Current->arr.d.x; j++)
							ofst << c->Current->arr.d.arrD[i][j] << " ";
						ofst << endl;
					}
				}

			}
			else
			{
				ofst << "Size: " << c->Current->arr.t.x << " Type: Triangle" << endl;
				for (int i = 0; i < c->Current->arr.t.x; i++)

				if (c->Current->arr.outType == 2)
				{
					for (int i = 0; i < c->Current->arr.d.x; i++)
					{
						for (int j = 0; j < c->Current->arr.d.x; j++)
							ofst << c->Current->arr.d.arrD[j][i] << " ";
						ofst << endl;
					}
				}
				if (c->Current->arr.outType == 3)
				{

					for (int i = 0; i < c->Current->arr.d.x; i++)
					{
						for (int j = 0; j < c->Current->arr.d.x; j++)
							ofst << c->Current->arr.d.arrD[i][j] << " ";
						
					}
				}
			}
				ofst << "Sum of array: " << Summa(c->Current->arr) << endl;
			}
		}
		c->Current = c->Current->Next;
		i++;
	} while (c->Current != c->Head);
}
bool Compare(Arr* first, Arr* second) {
	return Summa(*first) < Summa(*second);
}

//-----------------------------------------------------
// —ортировка содержимого контейнера
void Sort(container& c) {
	for (int i = 0; i < c.length - 1; i++) {
		for (int j = i + 1; j < c.length; j++) {
			if (Compare(&c.Current->arr,&c.Current->Next->arr))
			{
				Node * tmp;
				
				
				c.Current->Next->Next->Prev = c.Current;
				c.Current->Next->Prev = c.Current->Prev;
				c.Current->Prev = c.Current->Next;
				
				
				c.Current->Next->Prev->Next = c.Current->Next;
				tmp = c.Current->Next->Next;
				c.Current->Next->Next = c.Current;
				c.Current->Next = tmp;
				

			}
		}
	}
}

