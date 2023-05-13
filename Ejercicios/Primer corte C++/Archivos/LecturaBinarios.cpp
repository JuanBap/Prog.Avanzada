#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <conio.h>

using namespace std;
typedef struct estudiante_t
{
    char nombre [50];
    char codigo [20];
    float notas[3];
};

void leerArchivo();

int main()
{
	leerArchivo();
    
	
   	return 0; 
}


void leerArchivo(){
	
	system("cls");
	cout << "======================================"<<endl;
	cout << "Reporte de Notas" <<endl;
	cout << "======================================"<<endl;
	int i=0;
	
	ifstream input_file("estudiantes.dat", ios::binary);
    estudiante_t maestra;
    
    int bytes=0;
    int pos=0;
	//Se posiciona al principio del archivo
    input_file.seekg(0, input_file.beg);
    while (!input_file.eof())
    {
		cout <<"Posicion antes de la lectura del registro:"<<pos<<endl;
		input_file.read((char*)&maestra, sizeof(maestra));         
		cout << "\nRegistro #" << ++i << endl;
        cout << "Estudiante: " << maestra.nombre ;
        cout << "  Codigo: " << maestra.codigo << endl;
        for (int j=0;j<3;j++){
	  		cout <<"  Nota Nro: [" << j+1 <<"] : ";	
	  		cout <<maestra.notas[j]<<endl;
	  	}
        cout << endl << endl;  
        
		pos=input_file.tellg();//Guarda en pos la posicion del ultimo byte leido
        cout <<"posicion despues de la lectura del registro:"<<pos<<endl;
        
	    cout<<"----------------"<<endl;
    }
    input_file.close();
    getch();
}
