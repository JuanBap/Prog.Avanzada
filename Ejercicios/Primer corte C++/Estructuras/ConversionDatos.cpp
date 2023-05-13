#include <iostream>    
using namespace std;

int main(){
	cout<< "Conversion automatica de tipos de datos"<<endl<<endl;
	
	char ch=60;
    int i=10;
    float f1=5.0f;
    float f2=5e2;
    //float f3=5f; //no se puede 
    double d1=100.3;
    double d2=43e3;
    
    cout<< "d2:"<<d2<<endl;
    cout<< "f2:"<<f2<<endl;
    
	cout<<"Tipo dato:"<<typeid(ch/i+(f1) -(f1+i)).name()<<endl;
	cout<<"Tipo dato:"<<typeid(ch/i+(f1+d1) -(f1+i)).name();
	
}

