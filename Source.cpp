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
			
		}
		c->Current = c->Current->Next;
		i++;
	} while (c->Current != c->Head);
}
