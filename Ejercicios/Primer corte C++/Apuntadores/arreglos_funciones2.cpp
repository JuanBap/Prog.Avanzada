 #include <iostream>
 #include <stdlib.h>
 #include <string>
 #include <string.h>
 #define largo 2
 using namespace std;
	typedef struct {
          string nombres;
          string apellidos;
    } est;
 void llenarArreglo1(est e[]);
 void llenarArreglo2(est *e);
 int main (){
 	string x;	
    est estudiantes[largo];
 	llenarArreglo1(estudiantes);
 	cout << "\n\nResultado llenado tipo 1" <<endl;
 	for (int i=0;i<largo;i++){
 		cout << (i+1)<<". Nombre "<<estudiantes[i].nombres<< " Apellidos: "<<estudiantes[i].apellidos<<endl;
	} 	
	cout << "\n\nLlenado tipo 2" <<endl;
	llenarArreglo2(estudiantes);
	cout << "\n\nResultado llenado tipo 2" <<endl;
 	for (int i=0;i<largo;i++){
 		cout << (i+1)<<". Nombre "<<estudiantes[i].nombres<< " Apellidos: "<<estudiantes[i].apellidos<<endl;
	 } 	
 }
 void llenarArreglo1(est e[]){
 	for (int i=0;i<largo;i++){
 	 cout << "Nombre estudiante "<<i+1<<":";
 	 getline (cin,e[i].nombres);
	 cout << "Apellidos estudiante "<<i+1<<":";
 	 getline (cin,e[i].apellidos);  
 	}
 }
 void llenarArreglo2(est *e){
 	for (int i=0;i<largo;i++){
 	 cout << "Nombre estudiante "<<i+1<<":";
 	 
 	 getline (cin,(*e).nombres);  
	 cout << "Apellidos estudiante "<<i+1<<":";
 	 getline (cin,(*e).apellidos);  
 	 e++;
 	}
} 