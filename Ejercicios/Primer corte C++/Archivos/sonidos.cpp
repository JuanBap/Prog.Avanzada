#include <windows.h>
#include <string>
using namespace std;
int main()
{
    string cadena=".... / --- .-.. .- .-.-.";
    for (int i=0;i<cadena.length();i++){
    	switch (cadena[i]){
    		case '.': Beep(3000, 100);
    				Sleep (20);
    				break;
    		case'-': Beep(3000, 550);Sleep(20);
    				break;
			case' ': Sleep(10);
			case'/': Sleep(30);
 				
		}
	}
    return 0;
}
