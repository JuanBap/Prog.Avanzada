#include <stdio.h>
#include <iostream>
using namespace std;

 int j=0;

void estaticas (){
    static int k=10;
	
	k++;
	j++;
	cout <<" k:"<<k<<"      j:"<<j<<endl;
}

int main (){
	
	for (int i=0;i<=5;i++){
		estaticas();
		j++;
	}
}