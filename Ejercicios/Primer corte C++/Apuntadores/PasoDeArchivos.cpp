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

void adicionarRegistro(fstream &output_file);
void guardarArchivo(estudiante_t estudiante[],int registros, fstream &output_file);
void leerArchivo(fstream *input_file);
void consultarPos(fstream &input_file);
void consultarNombre(fstream &input_file);

int main()
{
	fstream io_file;
	io_file.open("estudiantes.dat", ios::in|ios::out|ios::binary|ios::app|ios::ate); 
	
	int opcion;
	do{
		system("cls");	
			
		cout << "======================================"<<endl;
		cout <<"1. Adicionar registros"<<endl;
		cout <<"2. Consultar un registro por posicion"<<endl;
		cout <<"3. Consultar un registro por Nombre de estudiante"<<endl;
		cout <<"4. Reporte de estudiantes"<<endl;
		cout <<"5. Salir"<<endl;
		cout <<"Digite opcion:";
		cin >>opcion;
		fflush(stdin);
		switch(opcion){
			case 1:adicionarRegistro(io_file);break;			
			case 2:consultarPos(io_file); break;
			case 3:consultarNombre(io_file);break;
			case 4:leerArchivo(&io_file);
		}
	}while (opcion!=5);
	return 0;
    
    
   	return 0; 
}
void adicionarRegistro(fstream &output_file){
	int registros;
	cout << "======================================"<<endl;
	cout << "Indique numero de registros a procesar:" ;
	cin >>registros;
	
	fflush(stdin);   //Limpiar el buffer de entrada por consola

	estudiante_t estudiante[registros];  
	for(int f = 0; f < registros; f++){
	  cout <<"\nDatos del estudiante Nro: [" << f+1 <<"]  \n";	
	  cout <<"Ingrese Nombre: ";
	  //cin.getline(estudiante[f].nombre, 50);
	  gets(estudiante[f].nombre);
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

    guardarArchivo(estudiante,registros,output_file);
}



void guardarArchivo(estudiante_t estudiante[],int registros,fstream &output_file){
	cout <<"guardando datos\n";
	
	if (!output_file.is_open()){
		output_file.open("estudiantes.dat", ios::out|ios::binary|ios::app|ios::ate); 	
	}
	
	for (int i=0;i<registros;i++){
		output_file.write((char*)&estudiante[i], sizeof(estudiante[i]));//Aqui se envia al archivo un registro a la vez
	}
	output_file.close();	
}

void consultarPos(fstream &input_file){
	system("cls");
	cout << "======================================"<<endl;
	cout << "Consulta por posicion" <<endl;
	cout << "======================================"<<endl;
	int pos;
	cout<<"Registro a buscar:";
	cin >> pos;
	pos--; //Esto porque las posiciones las contamos desde cero en el archivo
	fflush (stdin);
	int tam=sizeof(estudiante_t);
	cout <<"tamano en bytes del registro de estudiantes:"<<tam<<endl;
	long posicionReal=tam*pos;
	
	if (!input_file.is_open()){
		input_file.open("estudiantes.dat", ios::in|ios::binary); 	
	}
	
	
    estudiante_t estudiante;
   
   //Se posiciona en el registro 0
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
    input_file.close();
    getch();
}


void consultarNombre(fstream &input_file){
	system("cls");
	cout << "======================================"<<endl;
	cout << "Consulta por nombre" <<endl;
	cout << "======================================"<<endl;
	char nombre[50];
	cout<<"Nombre a buscar:";
	cin.getline(nombre,50);
	
    bool encontrado=false;
	if (!input_file.is_open()){
		input_file.open("estudiantes.dat", ios::in|ios::binary); 	
	}

    estudiante_t maestra;
    
	int i=0;
	long pos;
	//Se posiciona al principio del archivo
    input_file.seekg(0, input_file.beg);
    while (!input_file.eof() )//Calculo del final del archivo teniendo en cuenta el metodo eof()
    {
		pos=input_file.tellg();
		cout <<"posicion antes de la lectura del registro:"<<pos<<endl;
		input_file.read((char*)&maestra, sizeof(maestra));         
		++i;

		if (strstr(maestra.nombre,nombre)!=NULL){
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
		}
    }
    input_file.close();
    
    if (!encontrado){
    	cout<<"Registro no encontrado!!\n";
	}
    cout<< "Presione cualquier tecla para continuar...";
    getch();
	
	
}



void leerArchivo(fstream *input_file){
	
	system("cls");
	cout << "======================================"<<endl;
	cout << "Reporte de Notas" <<endl;
	cout << "======================================"<<endl;
	int i=0;
	
	estudiante_t maestra;
    
    int bytes=0;
    int pos=0;

	if (!(*input_file).is_open()){
		(*input_file).open("estudiantes.dat", ios::in|ios::binary); 	
	}
    
    //Calcula el tamaño en bytes del archivo, posicionandose en el ultimo byte.
    (*input_file).seekg(0, (*input_file).end);
    bytes=(*input_file).tellg();
    cout <<"tamano archivo:"<<bytes<<" bytes"<<endl;
    
	//Se posiciona al principio del archivo
    (*input_file).seekg(0, (*input_file).beg);
    while (pos<bytes  )//Calculo del final del archivo teniendo en cuenta el numero de bytes recorridos
    {
		cout <<"Posicion antes de la lectura del registro:"<<pos<<endl;
		(*input_file).read((char*)&maestra, sizeof(maestra));         
		cout << "\nRegistro #" << ++i << endl;
        cout << "Estudiante: " << maestra.nombre ;
        cout << "  Codigo: " << maestra.codigo << endl;
        for (int j=0;j<3;j++){
	  		cout <<"  Nota Nro: [" << j+1 <<"] : ";	
	  		cout <<maestra.notas[j]<<endl;
	  	}
        cout << endl << endl;  
        
		pos=(*input_file).tellg();//Guarda en pos la posicion del ultimo byte leido
        cout <<"posicion despues de la lectura del registro:"<<pos<<endl;
        
	    cout<<"----------------"<<endl;
    }
    (*input_file).close();
    getch();
}
