#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main(){
	char tecla;
	int i=0;
	while (tecla!=27){
		Sleep(150);
		cout <<"Ciclo "<<i++<<endl;
		if(kbhit()){
            tecla = getch();
            cout <<"Tecla pulsada :"<<tecla<<endl;
    	}		
	}
	
}