#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;


// 3 вариант
//5. Контейнер на основе двунаправленного кольцевого списка.
// 
//1. Обобщение, построенное на основе непосредственного включения специализаций.
//1. Клиентская часть программы(тестовая функция) размещается в отдельном модуле.
// Основная часть кода, определяющего реализацию функций или методов, содержится в другом(едином) модуле.
// Программные объекты, обеспечивающие связь между основной и клиентской частями(абстрактные типы данных, сигнатуры функций, описания классов),
//размещается в отдельном интерфейсном модуле(заголовочном файле).

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