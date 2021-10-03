#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y);
void menu();
void jugadores();
void registrar();
void guardarDato();
void elegir();
void tablero();
void turnos();
void validarPosiciones();
void ganador();
int repetir(int n);
int seguirJugando();
void resultados();
void presentacion();
void salir();

int main(){
	
	system("cls");
	while(10){
		
		menu();	
		system("cls");	
		gotoxy(25,5);	
		getch();
	}
	return 0;
}

//Para posicionar entre las cordenadas (x,y)
void gotoxy(int x, int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}

//Obtener guardarDatos tipo Char y Tipo entero
struct Triqui{
	char nombre[20];
	int jugadas;
};

Triqui jugar1;
Triqui jugar2;
int tiro, empate, decidirlugar;
char Random[9];
char juego[3][3];
char marcar;
char compu[20]="PC";

void menu(){
	
	
	
	gotoxy(35,3); printf(" BIENVENIDO  ");
	
	for(int i=0; i<7; i++){
		
		gotoxy(18,8); printf ("  Que deseas jugar? \n");
		
	}
	int opcion;
	gotoxy(10,10);
	printf("1. Triqui");
	gotoxy(10,11);
	printf("2. Ahorcado");
	gotoxy(18,15);
	printf("Ingrese la opcion a utilizar\n");
	gotoxy(18,16);printf(" - ");
	scanf("%d", &opcion);
	

	if(opcion==1 || opcion==2){
		switch(opcion){
		case 1: jugadores(); break;
		
		case 2: jugadores(); break;		
		
		}
	}
	else{
		opcion=0;
		gotoxy(10,12); printf(" Opcion no valida...\n");
	}
	getch();
}

	//Modo de jugadores 
void jugadores(){
	int opcion;
	
	gotoxy(25,1); printf(" ElEGIR EL MODO DE JUEGO ");
	gotoxy(28,3); printf("1: Jugador Vs Jugador ");
	gotoxy(28,4); printf("2: jugador Vs Computadora");
	gotoxy(40,6); printf (" - ");
	scanf("%d", &opcion);

	if(opcion==1 || opcion ==2){
		switch(opcion){
		case 1:
			guardarDato();
			registrar();
			do{
				tablero();
				turnos();
			} while(seguirJugando());
			break;
		case 2:
			elegir();
			do{
				tablero();
				turnos();
			} while(seguirJugando());
			break;
		}
	}
	else{
		opcion=0;
		gotoxy(25,8); printf("Opcion no valida");
	}
	getch();
}

	// Registro de Jugadores 
void registrar(){
	int cantidad, cantidad2;
	do{
		gotoxy(12,14); printf (" Jugador #1 ");
		gotoxy(12,15); printf ("Ingrese su Nombre: ");
		gotoxy(15,16); printf (" - ");
		scanf ("%s",jugar1.nombre);
		cantidad = strlen(jugar1.nombre);
	} while(cantidad>10);
	gotoxy(17,7); printf ("%s",jugar1.nombre); 
	
	do{		
		gotoxy(12,19); printf (" Jugador #2 ");
		gotoxy(12,20); printf ("Ingrese su Nombre: ");
		gotoxy(15,21); printf (" - ");
		scanf ("%s", &jugar2.nombre); 
		cantidad2 = strlen(jugar2.nombre);
	} while(cantidad2>10);
	gotoxy(40,7); printf ("%s",jugar2.nombre); 
	getch();
}
void guardarDato(){
	
	
	system("cls");
	gotoxy(10,3); printf (".-------------------------------------------.");
	gotoxy(10,4); printf ("|     JUGADOR 1 (X)  |    JUGADOR 2 (0)     |");
	gotoxy(10,5); printf (".-------------------------------------------.");
	gotoxy(10,6); printf ("|                    |                      |");
	gotoxy(10,7); printf ("|                    |                      |");
	gotoxy(10,8); printf ("|                    |                      |");
	gotoxy(10,9); printf (".-------------------------------------------."); 
}

	// Jugar contra la computadora
void elegir(){
	system("cls");
	int cantidad, opcion;
	gotoxy(10,2);
	printf ("Con que ficha desea jugar?\n\n 1: Jugador 1 = X  \n 2: Jugador 2 = 0\n - ");
	scanf ("%d", &opcion);
	switch(opcion){
		case 1: guardarDato();
		decidirlugar=2;
		strcpy(jugar2.nombre, compu);
		gotoxy(40,7); printf ("%s",jugar2.nombre);
		
	
	do{
		
		gotoxy(10,18); printf ("Ingrese su nombre");
		gotoxy(15,19); printf (" - ");
		scanf("%s", &jugar1.nombre);
		cantidad = strlen(jugar1.nombre);
	}while(cantidad>10);
	gotoxy(17,7); printf ("%s",jugar1.nombre); 
	break;
	
	case 2: guardarDato();
		decidirlugar=1;
		strcpy(jugar1.nombre, compu);
		gotoxy(17,7); printf ("%s",jugar1.nombre); 
	
	do{
		gotoxy(10,18); printf ("Ingrese su nombre");
		gotoxy(15,19); printf (" - ");
		scanf ("%s", &jugar2.nombre);
		cantidad = strlen(jugar1.nombre);
	} while(cantidad>10);
	gotoxy(40,7); printf ("%s",jugar2.nombre); 
	break;
	}
	getch();
}

	// Tablero del juego
void tablero(){
	system("cls");
	gotoxy(25,1); printf (" * TRIQUI * ");
	gotoxy(30,3); printf ("%s vs %s", jugar1.nombre, jugar2.nombre);
	
	
	gotoxy(25,12); printf ("     |     |     ");
	gotoxy(25,13); printf ("     |     |     ");
	gotoxy(25,14); printf ("     |     |     ");
	gotoxy(25,15); printf ("-----------------");
	gotoxy(25,16); printf ("     |     |     ");
	gotoxy(25,17); printf ("     |     |     ");
	gotoxy(25,18); printf ("     |     |     ");
	gotoxy(25,19); printf ("-----------------");
	gotoxy(25,20); printf ("     |     |     ");
	gotoxy(25,21); printf ("     |     |     ");
	gotoxy(25,22); printf ("     |     |     ");


}

// Turno de jugadores en el juego 
void turnos(){
int h,i,j,n;
	tiro=0;
	marcar=0;
	//llenado de Columna y Filas
	for(j=0; j<=2; j++){
		for(h=0; h<3; h++){
			juego[j][h]=0;
		}
	}
	do{
		gotoxy(10,26); printf ("Es el turno de: %s",jugar1.nombre);
		gotoxy(10,27); printf ("Digite la posicion:  ");
		if(strcmp(jugar1.nombre, compu)==0){
			marcar='X';
			do{
				n=(rand()%9+1); //Genera posiciones aleatorios
			} while(repetir(n));
			for(i=0; i<9; i++){
				if(Random[i]==0){
					Random[i]=n;
					tiro = n;
					break;
				}
			}
			validarPosiciones();
		}
		else{
			scanf ("%d", &tiro);
			if(tiro!=10){
				marcar='X';
				validarPosiciones();
			}
		}
		if(tiro!=10){
			
			
			gotoxy(40,26); printf ("Es el turno de: %s",jugar2.nombre);
			gotoxy(40,27); printf ("Digite la posicion:  ");
			if(strcmp(jugar2.nombre, compu)==0){
				marcar='0';
				do{
					n= (rand()%9+1);
				} while(repetir(n));
				for(int i=0; i<9; i++){
					if(Random[i]==0){
						Random[i]=n;
						tiro=n;
						break;
					}
				}
				validarPosiciones();
			}
			else{
				scanf ("%d", &tiro);
				if(tiro!=10){
					marcar='0';
					validarPosiciones();
				}
			}
		}
	} while(tiro!=10);
	getch();
}

	// Verificador las posiciones en el tablero
void validarPosiciones(){
	int x=0,y=0,c=27,d=13,i;
	
	if(tiro<=9){
		for(i=0; i<3; i++){  // posicion [0,1,2] = (1 2 3)
			if(tiro==i+1){
				if(juego[i][0]=='0' || juego[i][0]=='X'){
					gotoxy(10,24); printf("Posicion ocupada, escoja otra: ");
				}
				else{
					juego[i][0] = marcar;
					gotoxy(c+(6*i),d); cout<<juego[i][0];
					
					Random[i]=i+1;
				}
			}
		}
		
		for(i=3; i<6; i++){ //posicion [3,4,5] = (4 5 6)
			if(tiro==i+1){
				if(juego[x+(i-3)][y+1]=='0' || juego[x+(i-3)][y+1]=='X'){
					gotoxy(10,24); printf ("Posicion ocupada, elija otra: ");
				}
				else{
					juego[x+(i-3)][y+1]= marcar;
					gotoxy(c+(6*(i-3)),d+4); printf ("%c",juego[x+(i-3)][y+1]);
					
					Random[i]=i+1;
				}
			}
		}
		
		for(i=6; i<9; i++){ // [6,7,8] = (7 8 9)
			if(tiro==i+1){
				if(juego[x+1][y+2]=='0' || juego[x+1][y+2]=='X'){
					gotoxy(10,24); printf ("Posicion esta ocupada, elija otro: ");
				}
				else{
					juego[x+(i-6)][y+2]= marcar;
					gotoxy(c+(6*(i-6)),d+8); printf ("%c",juego[x+(i-6)][y+2]);
					
					Random[i]=i+1;
				}
			}
		}
		ganador();
	}else{
		gotoxy(20,9);printf ("\a < Ingrese un numero entre [1-9] >");
	}
}
	//Verificar y mostrar si existen ganadores del juego
void ganador(){
	int x,y,punto;
	// [00 01 02] [10 11 12] [20 21 22] vertical
	for(x=0; x<3; x++){
		if((juego[x][0]=='X') || juego[x][0]=='0'){
			if(juego[x][0]==juego[x][1] && juego[x][0]==juego[x][2]){
				if(juego[x][0]=='X'){
					punto=1;
				}
				if(juego[x][0]=='0'){
					punto=2;
				}
			}
		}
	}
	//[00 10 20] [01 11 21] [02 12 22] horizontal
	for(y=0; y<3; y++){
		if((juego[0][y]=='X') || (juego[0][y]=='0')){
			if(juego[0][y]==juego[1][y] && juego[0][y]==juego[2][y]){
				if(juego[0][y]=='X'){
					punto=1;
				}
				if(juego[0][y]=='0'){
					punto=2;
				}
			}
		}
	}
	//[00 11 22]  Diagonal
	if((juego[1][1]=='X') || juego[1][1]=='0'){
		if((juego[1][1]==juego[0][0] && juego[1][1]==juego[2][2])){
			if(juego[1][1]=='X'){
				punto=1;
			}
			if(juego[1][1]=='0'){
				punto=2;
			}
		}//[02 11 20]
		if((juego[1][1]==juego[2][0] && juego[1][1]==juego[0][2])){
			if(juego[1][1]=='X'){
				punto=1;
			}
			if(juego[1][1]=='0'){
				punto=2;
			}
		}
	}
	if( (juego[0][0] == 'X' || juego[0][0]=='0') &&
		(juego[1][0] == 'X' || juego[1][0]=='0') &&
		(juego[2][0] == 'X' || juego[2][0]=='0') &&
		(juego[0][1] == 'X' || juego[0][1]=='0') &&
		(juego[1][1] == 'X' || juego[1][1]=='0') &&
		(juego[2][1] == 'X' || juego[2][1]=='0') &&
		(juego[0][2] == 'X' || juego[0][2]=='0') &&
		(juego[1][2] == 'X' || juego[1][2]=='0') &&
		(juego[2][2] == 'X' || juego[2][2]=='0') &&
		(punto!=1 && punto!=2))
	{
		gotoxy(22,7);
		
		gotoxy(23,9); printf (" Resultados final: EMPATE ");
		empate = empate+1;
		tiro=10;
	}
		if(punto==1 || punto==2){
			if(punto==1){
				gotoxy(22,7); 
				system("cls");
				jugar1.jugadas = jugar1.jugadas+1;
				gotoxy(23,9); printf (" FELICIDADES "); 
				printf ("%s",jugar1.nombre);
				printf (" HAS GANADO!!");
				tiro = 10;
			}
			if(punto==2){
				gotoxy(22,9);
				system("cls");
				jugar2.jugadas = jugar2.jugadas+1;
				gotoxy(23,9); printf ("FELICIDADES ");
				printf ("%s",jugar2.nombre);
				printf (" HAS GANADO!!");
				tiro = 10;
			}
		}
}

	//Repetir la partida 
int repetir(int n){
	int i;
	srand(time(0));
	for(i=0; i<9; i++){
		if(Random[i]==n){
			return true;
		}
	}
	return false;
}

	//Para seguir jugando
int seguirJugando(){
	int seguir;
	system("cls");
	resultados();
	gotoxy(25,10); printf ("Deseas volver a jugar? \n"); 
	gotoxy(25,12); printf ("1:Si \n"); 
	gotoxy(25,13); printf ("2:No \n"); 
	gotoxy(35,15); printf (" - ");
	scanf ("%d", &seguir);
	if(seguir==1){
		return true;
	}else if(seguir==2){
		jugar1.jugadas=0;
		jugar2.jugadas=0;
		empate=0;
		return false;
	}
	return false;
}

	//Resultados de ganadores
void resultados(){
	
	gotoxy(10,1); printf(".-----------------------------------------------.");
	gotoxy(10,2); printf("|               - RESULTADOS -                  |");
	gotoxy(10,3); printf(".-----------------------------------------------.");
	gotoxy(10,4); printf("|                                               |");
	gotoxy(10,5); printf("|                                               |");
	gotoxy(10,6); printf("|                                               |");
	gotoxy(10,7); printf("|                                               |");
	gotoxy(10,8); printf(".-----------------------------------------------.");
	gotoxy(15,5);
	cout<<jugar1.nombre<<" Gano: "<<jugar1.jugadas;
	gotoxy(15,6);
	cout<<jugar2.nombre<<" Gano: "<<jugar2.jugadas;
	gotoxy(15,7);
	cout<<"Empates: "<<empate<<endl;
}

	




