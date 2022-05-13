#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;


// 3 �������
//5. ��������� �� ������ ���������������� ���������� ������.
// 
//1. ���������, ����������� �� ������ ����������������� ��������� �������������.
//1. ���������� ����� ���������(�������� �������) ����������� � ��������� ������.
// �������� ����� ����, ������������� ���������� ������� ��� �������, ���������� � ������(������) ������.
// ����������� �������, �������������� ����� ����� �������� � ���������� �������(����������� ���� ������, ��������� �������, �������� �������),
//����������� � ��������� ������������ ������(������������ �����).

int main(int argc, char* argv[]) 
{
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container* cont = new container;
//	Init(cont);
	InCont(ifst, cont);
	ofst << "Filled container. " << endl;
	OutCont(ofst, cont);
	OutClassicCont(ofst, cont);
	Clear(cont);
	ofst << "Empty container. " << endl;
	//Out(c, ofst);
	cout << "Stop" << endl;
	return 0;
}