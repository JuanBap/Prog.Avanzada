#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
typedef struct estudiante_t
{
    char nombre [50];
    char codigo [20];
    float notas[3];
};

void adicionarRegistro();
void guardarArchivo(estudiante_t estudiante[],int registros);
void leerArchivo();
void consultarPos();
void consultarNombre();
void eliminarPorNombre();

int main()
{

    
	int opcion;
	do{
		system("cls");	
			
		cout << "======================================"<<endl;
		cout <<"1. Adicionar registros"<<endl;
		cout <<"2. Consultar un registro por posicion"<<endl;
		cout <<"3. Consultar un registro por Nombre de estudiante"<<endl;
		cout <<"4. Eliminar un registro por nombre"<<endl;		
		cout <<"5. Eliminar un registro por posicion"<<endl;		
		cout <<"6. Modificar un registro por posicion"<<endl;		
		cout <<"7. Reporte de estudiantes"<<endl;
		cout <<"8. Salir"<<endl;
		cout <<"Digite opcion:";
		cin >>opcion;
		fflush(stdin);
		switch(opcion){
			case 1:adicionarRegistro();break;			
			case 2:consultarPos(); break;
			case 3:consultarNombre();break;
			case 4:eliminarPorNombre();break;			
			case 7:leerArchivo();break;			
		}	
	}while (opcion!=8);
	return 0; 
}

void adicionarRegistro(){
	int registros;
	cout << "======================================"<<endl;
	cout << "Indique numero de registros a procesar:" ;
	cin >>registros;
	
	
	fflush(stdin);   //Limpiar el buffer de entrada por consola

	estudiante_t estudiante[registros];  
	for(int f = 0; f < registros; f++){
	  cout <<"\nDatos del estudiante Nro: [" << f+1 <<"]  \n";	
	  cout <<"Ingrese Nombre: ";
	  cin.getline(estudiante[f].nombre, 50);
	  //getline(cin,estudiante[f].nombre);
	  cout<< "Nombre:"<<estudiante[f].nombre<<endl;
	  fflush(stdin);   //Limpiar el buffer de entrada por consola
	  cout << "Ingrese Codigo: ";
	  cin >> estudiante[f].codigo;
	  fflush(stdin);   //Limpiar el buffer de entrada por consola
	  for (int i=0;i<3;i++){
	  	cout <<"  Ingrese Nota Nro: [" << i+1 <<"] : ";	
	  	cin >>estudiante[f].notas[i];
	  	fflush(stdin); 
	  }
	  fflush(stdin);   //Limpiar el buffer de entrada por consola 	  
	 }

    guardarArchivo(estudiante,registros);
}



void guardarArchivo(estudiante_t estudiante[],int registros){
	cout <<"guardando datos\n";
	ofstream output_file("estudiantes.dat", ios::binary|ios::app|ios::ate);
	for (int i=0;i<registros;i++){
		output_file.write((char*)&estudiante[i], sizeof(estudiante[i]));//Aqui se envia al archivo un registro a la vez
	}
	output_file.close();	
}

void consultarPos(){
	system("cls");
	cout << "======================================"<<endl;
	cout << "Consulta por posicion" <<endl;
	cout << "======================================"<<endl;
	int pos;
	cout<<"Registro a buscar:";
	cin >> pos;
	pos--;
	fflush (stdin);
	int tam=sizeof(estudiante_t);
	cout <<"tamano registri:"<<tam<<endl;
	long posicionReal=tam*pos;
	
	ifstream input_file("estudiantes.dat", ios::binary);
    estudiante_t estudiante;
   
   //Se posiciona en el registro
   cout <<"posicion antes de la lectura del registro:"<<posicionReal<<endl;
    input_file.seekg(posicionReal) ;
   
	input_file.read((char*)&estudiante, sizeof(estudiante));         
	cout << "\nRegistro #" << (pos+1) << endl;
    cout << "Estudiante: " << estudiante.nombre ;
    cout << "  Codigo: " << estudiante.codigo << endl;
    for (int j=0;j<3;j++){
	  	cout <<"  Nota Nro: [" << j+1 <<"] : ";	
	  	cout <<estudiante.notas[j]<<endl;
	}
    cout << endl << endl;  
   	cout<<"----------------"<<endl;
    input_file.close();
    cout<< "Presione cualquier tecla para continuar...";
    getch();
}


void consultarNombre(){
	system("cls");
	cout << "======================================"<<endl;
	cout << "Consulta por nombre" <<endl;
	cout << "======================================"<<endl;
	string nombre;
	cout<<"Nombre a buscar:";
	getline(cin,nombre);
	
    bool encontrado=false;
	ifstream input_file("estudiantes.dat", ios::binary);
    estudiante_t maestra;
    
    int bytes=0;
    int pos=0;
    int i=0;
    //Calcula el tamaño en bytes del archivo, posicionandose en el ultimo byte.
    input_file.seekg(0, input_file.end);
    bytes=input_file.tellg();
    cout <<"Tamano archivo:"<<bytes<<" bytes"<<endl;
    
	//Se posiciona al principio del archivo
    input_file.seekg(0, input_file.beg);
    while (pos<bytes )
    {
		cout <<"posicion antes de la lectura del registro:"<<pos<<endl;
		input_file.read((char*)&maestra, sizeof(maestra));         
		++i;
		if (maestra.nombre==nombre){
			encontrado=true;
			cout << "\nRegistro #" << i << endl;
	        cout << "Estudiante: " << maestra.nombre ;
	        cout << "  Codigo: " << maestra.codigo << endl;
	        for (int j=0;j<3;j++){
		  		cout <<"  Nota Nro: [" << j+1 <<"] : ";	
		  		cout <<maestra.notas[j]<<endl;
		  	}
	        cout << endl << endl;  
		    cout<<"----------------"<<endl;
		    pos=bytes;
		}
		if (!encontrado)		
			pos=input_file.tellg();//Guarda en pos la posicion del ultimo byte leido

    }
    input_file.close();
    
    if (!encontrado){
    	cout<<"Registro no encontrado!!";
	}
    cout<< "Presione cualquier tecla para continuar...";
    getch();
	
	
}

void eliminarPorNombre(){
	system("cls");
	cout << "======================================"<<endl;
	cout << "Eliminar por nombre" <<endl;
	cout << "======================================"<<endl;
	string nombre;
	cout<<"Nombre a buscar:";
	getline(cin,nombre);
	
    bool encontrado=false;
	ifstream input_file("estudiantes.dat", ios::binary);
	ofstream output_file("estudiantesAux.dat", ios::binary|ios::app|ios::ate);
    estudiante_t maestra;
    
    int bytes=0;
    int pos=0;
    int i=0;
    //Calcula el tamaño en bytes del archivo, posicionandose en el ultimo byte.
    input_file.seekg(0, input_file.end);
    bytes=input_file.tellg();
    cout <<"Tamano archivo:"<<bytes<<" bytes"<<endl;
    
	//Se posiciona al principio del archivo
    input_file.seekg(0, input_file.beg);
    while (pos<bytes )
    {
		input_file.read((char*)&maestra, sizeof(maestra));         
		++i;
		if (maestra.nombre==nombre){
			encontrado=true;
			cout << "\nRegistro #" << i << "va a ser borrado "<<endl;
	        cout << "Estudiante: " << maestra.nombre ;
	        cout << "  Codigo: " << maestra.codigo << endl;
	        for (int j=0;j<3;j++){
		  		cout <<"  Nota Nro: [" << j+1 <<"] : ";	
		  		cout <<maestra.notas[j]<<endl;
		  	}
	        cout << endl << endl;  
		    cout<<"----------------"<<endl;
		}else{
			output_file.write((char*)&maestra, sizeof(maestra)); 	
		}
		pos=input_file.tellg();//Guarda en pos la posicion del ultimo byte leido

    }
    input_file.close();
    output_file.close();
    remove("estudiantes.dat");
    rename("estudiantesAux.dat", "estudiantes.dat");
    
    if (!encontrado){
    	cout<<"Registro no encontrado!!";
	}
	else{
		cout<<"Registro eliminado correctamente!!";
		
	}
    cout<< "Presione cualquier tecla para continuar...";
    getch();
	
	
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
    //Calcula el tamaño en bytes del archivo, posicionandose en el ultimo byte.
    input_file.seekg(0, input_file.end);
    bytes=input_file.tellg();
    cout <<"tamano archivo:"<<bytes<<" bytes"<<endl;
    
	//Se posiciona al principio del archivo
    input_file.seekg(0, input_file.beg);
    while (pos<bytes  )
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
        //cout <<"posicion despues de la lectura del registro:"<<pos<<endl;
        
	    cout<<"----------------"<<endl;
    }
    input_file.close();
    getch();
}
