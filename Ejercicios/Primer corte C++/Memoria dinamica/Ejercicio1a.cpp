#include <iostream>
// #include <cstdlib>
using namespace std;

struct Nodo {
    int numero;
    Nodo *Siguiente;
};

int main()
{
    Nodo *Lista = nullptr; // es un NULL específicO para punteros.
	int *i= new int;
	*i=10;
	delete i;
	
	i=nullptr;
    for (int i = 0; i<3; i++) {
        if (Lista == nullptr) {  // 
            cout << "\nAgregar nodo.\n";
            cout << "Lista: " << Lista << '\n';
            Lista = new Nodo;
            cout << "Lista: " << Lista << '\n';
        }
        else {
            cout << "\nEliminar Nodo.\n";
            cout << "Lista: " << Lista << '\n';
            delete Lista;
            cout << "Lista: " << Lista << '\n'; // ahora lo ves
            Lista = nullptr;
            cout << "Lista: " << Lista << '\n'; // ahora no lo ves
        }

    }
    return 0;
}