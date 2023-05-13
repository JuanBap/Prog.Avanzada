 
 #include <stdio.h>  
 #include <iostream>
 #include <windows.h>  
 #include <conio.h>
 
 #define cx 50
 #define cy 10
 #define ctx 30
 #define cty 2
 
 
 using namespace std;
 
 int posX=cx+1, posY=cy+1;
 int x=0,y=0;
 int turno =1;
 char matriz [3][3]={'.','.','.','.','.','.','.','.','.'};
 /*
 typedef struct _COORD { // coord.  
    SHORT X;  // coordenada horizontal 
    SHORT Y;  // coordenada vertical 
} COORD
 
 */

void AltEnter()
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
}
 
 
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
 
 char evaluarGanador(){
 	char car=' ';
 	bool ganador=false;
 	bool empate=true;
 	char jugador=' ';
 	switch (turno){
 		case 1:car='O';break;
 		case 2:car='X';break;
	}
    
 	if ( (matriz[0][0]==car && matriz[1][0]==car	&& matriz[2][0]==car) ||
 		 (matriz[0][1]==car && matriz[1][1]==car	&& matriz[2][1]==car) ||
 		 (matriz[0][2]==car && matriz[1][2]==car	&& matriz[2][2]==car) ||

		 (matriz[0][0]==car && matriz[0][1]==car	&& matriz[0][2]==car) ||
		 (matriz[1][0]==car && matriz[1][1]==car	&& matriz[1][2]==car) ||
		 (matriz[2][0]==car && matriz[2][1]==car	&& matriz[2][2]==car) ||
 		 
 		 (matriz[0][0]==car && matriz[1][1]==car	&& matriz[2][2]==car) ||
 		 (matriz[2][0]==car && matriz[1][1]==car	&& matriz[0][2]==car) )
		  	ganador=true;
 	else{
 		for (int i=0;i<3;i++)
 			for (int l=0;l<3;l++)
 				if (matriz[i][l]=='.')
 					empate=false;
	}
	if (ganador){
		if (turno==1)
		 		jugador='2';
		 	else	 
		 		jugador='1';
	}
	else if (empate)
			jugador='E';
		 else
		 	jugador=' ';
	return jugador;
 		
} 
 void pintarTablero(){
	//Pintar lineas verticales
	for (int x=cx+3;x<cx+8;x=x+4){
		for (int y=cy;y<=cy+10;y++){
			gotoxy(x,y);
			cout<< char(186);
		}
	}
 	//Pintar lineas horizontales
	for (int y=cy+3;y<cy+8;y=y+4){
		for (int x=cx;x<=cx+10;x++){
			gotoxy(x,y);
			cout<<char(205);
		}
	}
	
	//pintar los cruces
	gotoxy(cx+3,cy+3);
	cout <<char(206);
	
 	gotoxy(cx+7,cy+3);
	cout <<char(206);
	
	gotoxy(cx+3,cy+7);
	cout <<char(206);

	gotoxy(cx+7,cy+7);
	cout <<char(206);
	
 }
 
 void leerTecla(){
 	char t=' ';
 	char ganador=' ';
 	while (t!=27 && ganador==' ' ){
 		t=getch(); 
	switch(t)
           {
            case 27:
                 printf("\r\n Presiono Escape");
            case 72:
            	//Arriba
                posY=posY-4;
                if (posY<cy)
                 	posY=cy+9;
                y--; 	
                if (y<0)
                	y=2;
            	break;
            case 80:
            	 //Abajo
                posY=posY+4;
                if (posY>cy+9)
                 	posY=cy+1;
                y++; 	
                if (y>2)
                	y=0;
            	break;
            case 75:
            	 //Izquierda
                posX=posX-4;
                if (posX<cx+1)
                 	posX=cx+9;
                x--; 	
                if (x<0)
                	x=2;                 	
            	break;
            case 77:
            	//derecha
                posX=posX+4;
                if (posX>cx+9)
                 	posX=cx+1;
                x++; 	
                if (x>2)
                	x=0;                 	
            break;
            case 13:if (turno==1){
            			if (matriz[x][y]=='.'){						
							cout<<"X"; 
							matriz[x][y]='X';
							turno=2;
						}
						
					}
					else{
						
						if (matriz[x][y]=='.'){						
							cout<<"O";
							matriz[x][y]='O';
							turno=1;
							
						}
					}
					break;			
			}
			
			ganador=evaluarGanador();
			gotoxy (ctx,22);
			if (ganador==' ')		
				cout <<"Turno para jugador "<<turno;
			else{
				switch (ganador){
				
					case '1':cout<<"Ganador jugador 1        ";break;
					case '2':cout<<"Ganador jugador 2        ";break;
					default : cout<<"Empate                  ";break;				
				}
			}
			gotoxy (0,15);
			
			for (int my=0;my<3;my++){
				for (int mx=0;mx<3;mx++)
					cout <<"["<<mx<<"]["<<my<<"]:"<<matriz[mx][my];
				cout<<endl;  
			}										
			gotoxy(posX,posY);					 		 		
	}
 }
 void quitarCursor() {
    CONSOLE_CURSOR_INFO cci = {100, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
 
 
 int main(){  
 	system("cls");//Limpiar la pantalla 
	AltEnter()	;
 	
 	gotoxy (ctx,cty);
 	for (int i=ctx;i<ctx+55;i++) 		
 		cout <<char(178);
 	gotoxy (ctx,cty+1);
 	cout<< "JUEGO DEL TRIQUI";
	gotoxy (ctx,cty+2); 
	cout<<"PRIMER TURNO JUEGA CON 'X', SEGUNDO TURNO JUEGA CON 'O'"<<endl;
	gotoxy (ctx,cty+3);
	for (int i=ctx;i<ctx+55;i++) 		
	cout <<char(178);

	pintarTablero();
	gotoxy(posX,posY);
	leerTecla();
	gotoxy(ctx,cty+23);
	cout <<"Fin del juego, presione tecla para salir";
	getche();
						 		 		
    return 0;  
 }