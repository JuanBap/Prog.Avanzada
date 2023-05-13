 #include <iostream>
 using namespace std;
 
 typedef struct Nodo{
 	int numero;
 	Nodo *siguiente=NULL;
 };
 
 void addLista(Nodo *&lista, int n);
 void recorrer(Nodo *lista);
 
 int main(){
 	
 	Nodo *lista = NULL;
 	
 	int num;
 	cout <<" Agregar datos a la lista \n";
 	
 	cout <<"Digite un numero, finalice con cero\n";
 	cin >> num;
 	fflush(stdin);
 	while (num!=0){ 		
 		//cout <<"1. lista:"<<lista<<endl;
		addLista(lista,num);
		//cout <<"11. lista:"<<lista<<"lista->siguente:"<<lista->siguiente<<endl;
 		cout <<"Digite un numero, finalice con cero\n";
 		cin >> num; 		
 		fflush(stdin);
	 }
	 recorrer(lista);
 }
 
 void addLista(Nodo *&lista, int n){
 	Nodo *nuevo =  new Nodo;
 	nuevo->numero=n;
 	cout<< "Paso 1. Valor de 'nuevo':" <<nuevo<<" Valor de nuevo->numero: "<<nuevo->numero<<endl;
 	
 	cout<< "Paso 2. lista:" <<lista<<endl;
 	Nodo *aux1 = lista;
 	cout<< "Paso 3. aux1:" <<aux1<<endl;
 	Nodo *aux2 ;
 	cout<< "Paso 4. aux2:" <<aux2<<" Valor de aux2->numero: "<<aux2->numero<<endl;
 	while (aux1!=NULL){
 		aux2=aux1;
 		cout<< "Paso 5. aux2:" <<aux2<<endl;
 		aux1=aux1->siguiente; 		
 		cout<< "Paso 6. aux1:" <<aux1<<endl;
	}
	
	cout <<"fuera de while aux2 "<<aux2<<endl;
	if (lista==aux1){
		lista= nuevo;
		cout<< "Paso 7. lista=nuevo:" <<lista<<" Valor de lista->numero: "<<lista->numero<<endl;
	}
	else{
		aux2->siguiente= nuevo;
		cout<< "Paso 8. aux2->siguiente:" <<aux2->siguiente<<endl;
	}
 	cout<< "Paso 9. nuevo->siguiente:" <<nuevo->siguiente<<endl;
 	
 }
 
 void recorrer(Nodo *lista){
 	int i=1;
 	cout <<"\nRecorrido de lista\n";
	 Nodo *nodo = lista;
 	Nodo *aux=nodo;
 	while (aux!=NULL){
 		cout << "Direccion del nodo "<<i++<<": "<<aux<< "  Valor: "<< aux->numero << " Siguiente: "<< aux->siguiente<<endl;;
		aux=aux->siguiente;   		
	 }
 }
 