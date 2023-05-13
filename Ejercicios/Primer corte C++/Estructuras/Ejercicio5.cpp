//Ejercicio 5
#include <iostream>
using namespace std; 
int main()
{
   int tabla2 [2][3] = { {50,61,52},{53,14,55}};
   int mayor, menor, posmMayor, posnMayor, posnMenor, posmMenor;
   
   mayor=tabla2[0][0];
   posmMayor=0;
   posnMayor=0;
   
   menor=tabla2[0][0];
   posmMenor=0;
   posnMenor=0;
    
	for (int n=0;n<2;n++){
		for (int m=0;m<3;m++){
			cout << " ["<<n<<","<< m <<"]:"<<tabla2[n][m];
			if (tabla2[n][m]> mayor	){
				mayor=tabla2[n][m];
				posnMayor=n;
				posmMayor=m;
			}	
			if (tabla2[n][m]< menor	){
				menor=tabla2[n][m];
				posnMenor=n;
				posmMenor=m;
			}	

        }
        cout << endl;
	}	
	cout<< "El numero mayor es :"<<mayor<< " En la posicion ["<<posnMayor<<"]["<<posmMayor<< "]"<<endl;
	cout<< "El numero menor es :"<<menor<< " En la posicion ["<<posnMenor<<"]["<<posmMenor <<"]"<<endl;	
}
