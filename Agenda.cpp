#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 500

using namespace std;

int i = 0;
string Regla = "=============================================================";

struct Agenda {
	string Nombre;
	
	struct StructTelefono {
		string Telefono;
	} Tel[2];
	
	struct StructCelular {
		string Celular;
	} Cel[2];
	
	struct StructEmail {
		string Email;
	} Ema[2];
	
} Contacto[CANTIDAD];

int Menu();
void Insertar();
void Buscar();
void Actualizar();
void Eliminar();

void Detenerse();

int main(int argc, char *argv[]) {
	int N;
	
	Menu:
		do {
			N = Menu();
		} while(N < 1 || N > 2);
	
	switch (N){
		case 1: 
			Insertar();
			break;
		case 2:
			Buscar();
			break;
		default:
			printf("Up's, ha ocurrido algo inesperado, presione una tecla para continuar!.");
			system("PAUSE>NUL");
			break;
	}
	
	goto Menu;
	
	return 0;
}

int Menu(){
	int x;
	
	system("CLS");
	
	cout << Regla << endl;
	cout << "|\tBienvenido a tu Agenda Electrónica (Contactos)\t    |" << endl;
	cout << Regla << endl;
	
	cout << "|     (1) Nuevo contacto      |      (2) Buscar contacto    |" << endl;
	cout << Regla << endl;
	
	cout << "Esperando respuesta: ";
	scanf("%d", &x);
	fflush(stdin);
	
	return x; 
}

void Insertar(){
	cout << "Insertar" << endl;
	Detenerse();
}

void Buscar(){
	cout << "Buscar" << endl;
	Detenerse();
}

void Actualizar(){
	Detenerse();
}

void Eliminar(){
	Detenerse();
}

void Detenerse(){
	cout << "¡Presione una tecla para continuar!";
	system("PAUSE>NUL");
}
