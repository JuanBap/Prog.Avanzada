#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
	char s1[] = "palabra1,palabra2,palabra,palabra4";
	char *ptr;
	int dia, mes, anno;
	
	printf( "Fecha=%s\n", s1 );
	ptr = strtok( s1, "," );
	while(ptr!=NULL){
		cout <<ptr<<endl;
		switch (*ptr){
			case 'A':cout<< "Encontro La A\n";
		}
		ptr = strtok( NULL, "," );
	}
	return 0;
}