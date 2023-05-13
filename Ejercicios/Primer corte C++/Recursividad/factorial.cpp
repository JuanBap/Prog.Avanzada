 #include <iostream>
 using namespace std;
 
 int factorial (int n);
 
 int main(){
 	int n;
 	int fct=0;
 	cout<< "Digite el numero para calcular factorial:";
 	cin >>n;
 	fct=factorial(n);
 	cout<< n<<"!="<<fct;
 	return 0;
 	
 }
 
 int factorial (int n){
 	int f=0;
 	
 	if (n==0){
 		f=1;
	 }
	 else{
	 	f=n*factorial(n-1);
	 	cout<< n<<"!="<<f<<endl;
	 }
	 return f;
 }