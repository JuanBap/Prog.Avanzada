 #include <iostream>
 #include <stdio.h>      
 #include <stdlib.h>
 using namespace std;
 

 int main(){
 	
 	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
 	int x[3]={5,6,7};
 	int *p[3] ;
 	
 	//cout <<"valor de a:"<<a<<endl;
 	//cout <<"valor de a[0]:"<<a[0]<<endl;
 	//cout <<"valor de a[1][0]:"<<&a[1][0]<<endl;
	//cout <<"valor de a[1]:"<<a[1]<<endl;
    /*cout <<"valor de a[0][1]:"<<&a[0][1]<<endl;
 	cout <<"valor de a[0][2]:"<<&a[0][2]<<endl;
 	cout <<"valor de a[0][3]:"<<&a[0][3]<<endl;
 	cout <<"valor de a[1][0]:"<<&a[1][0]<<endl;
 	cout <<"valor de a[1][1]:"<<&a[1][1]<<endl;
 	*/
 	//cout <<"valor de x:"<<x<<endl;
 	for (int i =0; i<3; i++  ){
 		//p[i]=a[i]; Linea 17 y 18 funcionan igual
 		p[i]=*(a+i);
 		cout<<" Fila "<< i<< " ["<<i<<"][0]:" << p[i]<<"    ["<<i<<"][1]:"<<(p[i]+1)<<"    ["<<i<<"][2]:"<<(p[i]+2)<<"    ["<<i<<"][3]:"<<(p[i]+3)<< endl;
 		cout<<" Fila "<< i<< " ["<<i<<"][0]:" << a[i][0]<<"           ["<<i<<"][1]:"<<*(p[i]+1)<<"           ["<<i<<"][2]:"<<*(a[i]+2)<<"           ["<<i<<"][3]:"<<*((p[i])+3)<< endl<<endl;
	}
	/*
	//asi mostramos el valor de la primera columna

	cout<< "\nValores almacenados en el vector p:"<<endl;
	for (int j=0;j<3;j++){
 			cout<< "Valor en p["<<j<<"]:"<<(p+j)<< " apuntando a "<<     p[j]<<" => "<<*p[j]<<endl;
	}
 	
 	cout<< endl;

 	cout<< "Matriz completa usando a 'p' "<<"Direccion de *p "<<*p<<endl;
 	for (int i=0;i<3;i++){
	 
 		for (int j=0;j<4;j++){
 			cout<< *(*(p+i)+j)<<",";
 			
		 }
		 cout<<endl;
 	}
 	*/
	cout<< "Matriz completa usando a 'a' "<<"Direccion de *p "<<*p<<endl;
 	for (int i=0;i<3;i++){
	 
 		for (int j=0;j<4;j++){
 			cout<<"data["<<i<<"]["<<j<<"]:"<<(*(a+i)+j)<<"="<< **(a+i)+j<<",";
 			
		 }
		 cout<<endl;
 	}

 	
			  	
}
