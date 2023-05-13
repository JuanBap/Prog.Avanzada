#include <iostream>
#include <string.h>
using namespace std;
int main (){
	char cad1[20]={'h','o','l','a',' ','m','u','n','d','o','\0'};
	char cad2[]={'h','o','l','a',' ','m','u','n','d','o','\0'};
	char cad3[]="hola mundo";
	char cad4[20]= "hola mundo cruel";
	char *ptrCad1="hola mundo";
	string strCad1="hola mundo";
	string strCad2="esta es una cadena muy larga declarada como variable string y no como arreglo de char";
	string strCad3;
	strCad3 = strCad1+" "+strCad2;
	
	
	cout<< strupr(ptrCad1)<<endl;
	
	
	cout<<"cad1 :"<<cad1<<endl;
	cout<<"cad2 :"<<cad2<<endl;
	cout<<"cad3 :"<<cad3<<endl;
	cout<<"cad4 :"<<cad4<<endl;
	cout<<"ptrCad1 :"<<ptrCad1<<endl;
	cout<<"strCad1 :"<<strCad1<<endl;
	cout<<"strCad2 :"<<strCad2<<endl;
	cout<<"strCad3 :"<<strCad3<<endl;
	
	cout<<"longitud cad1 :"<<sizeof(cad1)<<endl;
	cout<<"longitud cad2 :"<<sizeof(cad2)<<endl;
	cout<<"longitud cad3 :"<<sizeof(cad3)<<endl;
	cout<<"longitud cad4 :"<<sizeof(cad4)<<endl;
	cout<<"longitud ptrCad1 :"<<sizeof(ptrCad1)<<endl;
	cout <<"longitud de strCad1: " << strCad1.length()<< " tamano: "<<sizeof(strCad1) <<endl;
	cout <<"longitud de strCad2: " << strCad2.length()<< " tamano: "<<sizeof(strCad2) <<endl;
	

	/*Funciones para manejo de arreglos de caracteres*/
	cout <<"strcmp cad1 vs cad3: "<<strcmp(cad1,cad3)<<endl;
	cout <<"strcmp cad1 vs cad2:  "<<strcmp(cad1,cad2)<<endl;
	cout <<"strcmp cad1 vs cad4: "<<strcmp(cad1,cad4)<<endl;
	
	strcat(cad1," ");
	strcat(cad1,cad2);
	cout<<"cad1 :"<<cad1<<endl;
	cout <<"strchr: "<<strchr(cad1,'l')<<endl;
	strcpy(cad1,strchr(cad1,'l'));
	cout <<"cad1 strchr: "<<cad1[0]<<endl;
	char cad5[200];
	strcpy(cad5, cad4);
	cout<<"cad5 :"<<cad5<<endl;
	strcpy(cad5, strchr(cad1,'a'));
	cout<<"cad5 :"<<cad5<<endl;
	cout <<"strlen de Cad2:"<<strlen(cad2)<<endl;
	cout <<"longitud de cad5:"<<strlen (cad5)<<endl;
	cout <<"strlen de ptrCad1:"<<strlen (ptrCad1)<<endl;
	
	
	char cad7[]="ESTO ESTABA EN MAYUSCULAS";
	
	strlwr(cad7);
	cout <<"cad7: "<<cad7<<endl;
	
	char cad8[]="esto estaba en minusculas";
	strupr(cad8);
	cout <<"cad8: "<<cad8<<endl;
	char *cad9=strrchr(cad7, 'a');
	cout <<"cad9:"<<cad9<<endl;
	
	strrev(cad7);
	cout <<"cad7:"<<cad7<<endl;
	
	char cad10[]="como encontrar una cadena en otra";
	char cad11[]="una";
	cout <<"strstr: "<<strstr(cad10,cad11)<<endl;
	
	
	
	
	
	
	
}