#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main(){
	char nombre[50]="Orlando Javier";
	char apellido [50]="Vasquez Gonzalez";
	char nombreCompleto [101];
	char aux1 [100];
	char aux2 [100];
	char b='r';
	//strcat(nombre,apellido);

	strcpy(nombreCompleto,"pedro perez");
	cout<<"strcpy 1: "<<nombreCompleto<<endl;
	
	cout<<"nombre :"<<nombre<<endl;
	cout<<"apellido :"<<apellido<<endl;
	strcpy(nombreCompleto,strcat(nombre,apellido));
	cout<<"strcpy 2:"<<nombreCompleto<<endl;
	strcpy(aux1,strchr(nombreCompleto,b));
	cout <<"strchr aux1:"<<aux1<<endl;
	cout<< "strlen aux1:"<<strlen(aux1)<<endl;
	cout<< "sizeof aux1:"<<sizeof(aux1)<<endl;
	strupr(aux1);
	cout<< "strupr aux1: "<<aux1<<endl;
	strlwr(aux1);	
	cout<< "strlwr aux1: "<<aux1<<endl;	
	strcpy(aux2,strrchr(aux1,'a'));
	cout<< "strrchr aux2: "<<aux2<<endl;
	strcpy(aux2,strstr(aux1,"za"));	
	cout<< "strstr aux2: "<<aux2<<endl;
	
	printf("strcpy 2: %s \n",nombreCompleto);

}