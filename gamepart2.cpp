#include <iostream>

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
		
		gotoxy(18,8);cout<<"  Que deseas jugar? \n";
		
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
		
		case 2: jugadores(); 
		gotoxy(15,20);system("pause"); break;		
		
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
		scanf ("%d", &jugar1.nombre); 
		cantidad = strlen(jugar1.nombre);
	} while(cantidad>10);
	gotoxy(17,7); printf (jugar1.nombre); /////////
	
	do{		
		gotoxy(12,19); printf (" Jugador #2 ");
		gotoxy(12,20); printf ("Ingrese su Nombre: ");
		gotoxy(15,21); printf (" - ");
		scanf ("%d", &jugar2.nombre); 
		cantidad2 = strlen(jugar2.nombre);
	} while(cantidad2>10);
	gotoxy(40,7); printf (jugar2.nombre); /////////
	getch();
}
void guardarDato(){
	
	

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
		gotoxy(40,7); printf (jugar2.nombre);
		gotoxy(7,17); printf ("""");
	
	do{
		
		gotoxy(10,18); cout<<"Ingrese su nombre";
		gotoxy(15,19);cout<<" - ";
		scanf("%d", &jugar1.nombre);
		cantidad = strlen(jugar1.nombre);
	}while(cantidad>10);
	gotoxy(17,7); printf (jugar1.nombre); /////////
	break;
	
	case 2: guardarDato();
		decidirlugar=1;
		strcpy(jugar1.nombre, compu);
		gotoxy(17,7); printf (jugar1.nombre); /////////
	
	do{
		gotoxy(10,18); printf ("Ingrese su nombre");
		gotoxy(15,19); printf (" - ");
		scanf ("%d", &jugar2.nombre);
		cantidad = strlen(jugar1.nombre);
	} while(cantidad>10);
	gotoxy(40,7); printf (jugar2.nombre); /////////
	break;
	}
	getch();
}