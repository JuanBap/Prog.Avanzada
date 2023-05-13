#include <iostream>
using namespace std;
int main(){
	int x=10;
	int *px;
	int **ppx;

	int z;
	int *pz;
	int **ppz;
		
	px=&x;
	ppx=&px;
	
	pz=&z;
	ppz=&pz;
	
	cout<<  "Z antes de la operacion:"<<z<<endl;
	**ppz=x+*px*2+**ppx*3 +z;
	
	
	cout<<  "X:"<<x<<endl;
	cout<<  "Z:"<<z<<endl;
	
}