
#include "oematriz.h"

//MAIN DEL PROGRAMA

int main()
{
	Matriz x;
	string titulo = "Proyecto Matriz Inversa - Algebra Lineal" ;
	cout << titulo << endl;
	for ( int i = 0; i < titulo.length(); i++) cout << "-";
	cout << endl;
	cout << "Tamano de la matriz? " << endl;

	cin >> x.tam;
	x.tam++;
	try{
		x.MatrizInversa();
		fflush(stdin);
		getchar();
	}
	catch (exception e){
	}
	return 0;
}
