/* 
-----TALLER 01 EJERCICIO 2-----

Fecha: 11/04/23
Autor: Juan Pablo Canon Contreras
Tema: Arreglos, numeros aleatorios, funciones

Solucion:
1.- Crear estructura de datos
2.- Usar estructura a traves de apuntadores
3.- Imprimir las facturas en un fichero de texto
4.- Subir el fichero al repositorio

*/

//Dentro de la misma carpeta incluimos in fichero de texto en blanco
//De nombre "facturas.txt"

//Incluimos bibliotecas
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <conio.h>
#include <string.h>

using namespace std;

//Creamos la estructura para los datos de los usuarios
struct Usuario{

    char nombre[25];
    char apellido[25];
    int cedula;
    int paga;

};

   

//Creamos los prototipos de las funciones

void capturar(Usuario *clientes); //Captura los datos de los clientes
void imprimir(Usuario *clientes, Usuario *ptr); //Imprime los datos en pantalla y en el archivo con apuntadores


//Comienzo del programa principal
int main() {

    Usuario clientes[15]={0};   //Arreglo de estructuras que almacena los datos
    Usuario *ptr = clientes;    //Apuntador que mira hacia la primera posicion del arreglo clientes

    int opcion; //Variable para usar como switch dentro del menu

    do{
    system("cls"); //Limpia la consola para mostrar informacion nueva
    
    cout<<"Taller 1 - Ejercicio 2\nAutor: Juan Pablo Canon\n";  //Comienza el menu
    cout<<"\n---------------------------------------------\n";
    cout<<"Bienvenido al programa de facturas de clientes\n";
    cout<<"\nElija una opcion para realizar una accion\n";
    cout<<"\n1.Capturar datos de clientes\n";
    cout<<"2.Imprimir las facturas en un fichero de texto\n";
    cout<<"0.Salir del programa:\n\n---------------------------------------------\n";

    cout<<"Mi opcion: ";    //Finaliza el menu para dar paso al registro de la opcion
    
    cin>>opcion;    //El usuario digita una opcion entre 0 y 2
    
    fflush(stdin);

        switch (opcion){
        
            case 1: capturar(clientes); break;  //Si elige el 1 llamamos la funcion capturar

            case 2: imprimir(clientes, ptr); break; //Si elige el 2 llamamos la funcion imprimir
            
            default: cout<<"Ingrese una opcion valida otra vez"; break; //Si se equivoca le dice que verifique el numero digitaod

            case 0: exit(1); //Si elige 0 se sale del programa
            }

    } 
    while(opcion != 0);


    return 0;
}


//Definimos la funcion de capturar
void capturar(Usuario *clientes){

    int n;  //Variable para saber cuantos clientes va a registrar el usuario

    system("cls");
    
    cout<<"\n---------------------------------------------\n\n";
    cout<<"  Bienvenido al menu de registro de clientes\n\n";
    cout<<"\n---------------------------------------------\n";
    cout<<"      Cuantos clientes desea registrar: ";
    cout<<"\n---------------------------------------------\n";
    cout<<"Numero de clientes: ";
    cin>>n;
    fflush(stdin);

    for (int i = 0; i < n; i++) //Inicializamos un ciclo para registrar los datos
    {
        system("cls");
        cout<<"\n---------------------------------------------\n\n";
        cout<<"Ingresando los datos del cliente ["<<i+1<<"]\n\n";
        cout<<"\n---------------------------------------------\n";

        cout<<"Ingrese sus nombres: ";

        cin.getline((*clientes).nombre, 25);    //Como estamos usando un arreglo de caracteres para poder 
        fflush(stdin);                          //- incluir el espacio lo hacemos de la siguiente manera:

        cout<<"\nIngrese sus apellidos: ";
        cin.getline((*clientes).apellido,25);
        fflush(stdin);

        cout<<"\nIngrese la cedula:";
        cin>>(*clientes).cedula;
        fflush(stdin);

        cout<<"\nIngrese el monto que paga: ";
        cin>>(*clientes).paga;
        fflush(stdin);

        cout<<"\n";

        clientes++;     //Como el arreglo es un apuntador por defecto lo usamos para practicar

    }

    cout<<"Registrando los datos...\n\nPresione una tecla para regresar al menu\n";
    getch(); //Lo usamos para que el usuario presione una tecla antes de volver a mostrar el menu

}

//Definimos la funcion de imprimir y le enviamos el apuntador Usuario *ptr para cumplir con lo solicitado en el taller
void imprimir(Usuario *clientes, Usuario *ptr){

    system("cls");

    cout<<"\n---------------------------------------------\n";
    cout<<"Imprimiendo facturas de clientes\n";
    cout<<"\n---------------------------------------------\n\n";

    for (int i = 0; i < 15; i++)    //Comienza el ciclo para mostrar en pantalla
    {
        if((*clientes).cedula!=0) 
        //Ponemos la condicion de que si en el espacio del vector se encuentra
        //una cedula la imprima, de lo contrario no se imprimira nada mas.  
        {   
            //Lo imprimimos usando -> puesto que es un apuntador de estructura
            cout<<"Factura #["<< i+1<< "]\n";
            cout<<"Nombres de la persona: "<<clientes->nombre<<endl;
            cout<<"Apellidos de la persona: "<<clientes->apellido<<endl;
            cout<<"Cedula de la persona: "<<clientes->cedula<<endl;
            cout<<"Monto que debe pagar: "<<clientes->paga<<endl;
            cout<<"\n\n---------------------------------------------\n";

            clientes++;  //Sumamos 1 o 4 bytes al arreglo para que ahora se posicione en la siguiente posicion

        }
    } //Finaliza el ciclo


    //Abrimos el canal "salida" para imprimir los datos en el archivo de texto
    ofstream salida("facturas.txt");

    salida<<"---------------------------------------------\n\n";
    salida<<"Facturas de los clientes: \n\n";
    salida<<"---------------------------------------------\n";

    //Inicializamos un ciclo que recorra todo nuestro arreglo
    for (int i = 0; i < 15; i++)
    {
        if((*ptr).cedula!=0) //Hacemos la misma pregunta del ciclo anterior pero hacia el puntero
        {
            salida<<"Factura #["<< i+1<< "]\n";
            salida<<"Nombres de la persona: "<<ptr->nombre<<endl; //Imprimimos los datos con el puntero
            salida<<"Apellidos de la persona: "<<ptr->apellido<<endl;
            salida<<"Cedula de la persona: "<<ptr->cedula<<endl;
            salida<<"Monto que debe pagar: "<<ptr->paga<<endl;
            salida<<endl<<endl;
            salida<<"---------------------------------------------\n";

            ptr++;
            //Sumamos lo mismo en el puntero para que avance
        }
    }
    
    salida<<"Finalizaron las facturas.";
    salida.close();

    cout<<"Presione una tecla para regresar al menu principal y revise su fichero de texto\n";
    //Finalizamos el programa
    getch();
}

