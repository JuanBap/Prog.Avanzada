#include <fstream> 
#include <iostream> 
using namespace std;   
//Nota: 1.0
int main() { 
  	ifstream archivo; 
  	string line;
  	char cad[100];
  	char car;
	archivo.open("archivos1.txt", ios::in); 
	//if (!archivo){
	if (!archivo.is_open()){
		cout<<" Error apertura archivo\n";
	}	
	else{
	    cout<<" Archivo abierto...\n";
		archivo.seekg(0);
		/*cout<<"\nLectura para string pos:"<<archivo.tellg()<<"\n";						
		while ( getline (archivo,line) )
    	{
      		cout << line << '\n';
      		cout<<"\nPos al finalizar lectura:"<<archivo.tellg()<<"\n";				
    	}
    	
		cout<<"\nPos al finalizar lectura:"<<archivo.tellg()<<"\n";				
    	archivo.close();
    	
    	
    	archivo.open("archivos1.txt", ios::in); 
    */
    	/*
		cout<<"\nLectura para cadenas de caracteres pos:"<<archivo.tellg()<<"\n";				
		//No se debe utilizar si el tamaño maximo de la linea es desconocido
		while ( !archivo.eof() )
		{
      		archivo.getline(cad,100);
			cout << cad << '\n';
    	}
		
		archivo.close();
    	archivo.open("archivos1.txt", ios::in); 
    	*/
		cout<<"\nLectura para caracteres pos:"<<archivo.tellg()<<"\n";		
		
		while ( archivo.get(car) )
    	{
      		  if (car=='\n' )cout <<"\nEncontro un salto de linea en: "<<archivo.tellg()<<endl;
			  cout << car ;
      		
    	}
    	
		archivo.close();         
		cout<<" Archivo cerrado...\n";
		/**/
		
		
		
	}	
	
	
	
	
	exit( 0 );		
}
