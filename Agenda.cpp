#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>

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
	
	Agenda(); // Declaración del constructor
	
} Contacto[CANTIDAD];

int Menu();
void Insertar();
void Buscar();
void Actualizar();
void Eliminar();

int Salir();

void Detenerse();
void LimpiarPantalla();
void Dormir(int);

// Definición del constructor, fuera de la estructura
Agenda::Agenda() {
	Nombre = " ";
	Tel[0].Telefono = "0";
	Cel[0].Celular = "0";
	Ema[0].Email = " ";
}

int main(int argc, char *argv[]) {
	int x;
	
	Menu:
		do {
			x = Menu();
		} while(x < 1 || x > 3);
	
	switch (x){
		case 1: 
			Insertar();
			break;
		case 2:
			Buscar();
			break;
		case 3: 
			if (Salir() == 1)
				goto Finish;
			break;
		default:
			printf("Up's, ha ocurrido algo inesperado, presione una tecla para continuar!.");
			system("PAUSE>NUL");
			break;
	}
	
	goto Menu;
	
	Finish: 
		return 0;
}

int Menu(){
	int x;
	
	LimpiarPantalla();
	
	cout << Regla << endl;
	cout << "|\tBienvenido a tu Agenda Electrónica (Contactos)\t    |" << endl;
	cout << Regla << endl;
	
	if (Contacto[0].Nombre == " "){
		Dormir(1);
		cout << "|\t\t\t\t\t\t\t    |" << endl;
		cout << "|\t\t       No hay contactos\t\t\t    |" << endl;
		cout << "|\t\t\t\t\t\t\t    |" << endl;
		Dormir(1);
	}
	
	cout << Regla << endl;
	cout << "| (1) Nuevo contacto  |  (2) Buscar contacto  | (3) Salir   |" << endl;
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
void LimpiarPantalla(){
	system("CLS");
}
void Dormir(int x){
	Sleep(x * 1000);
}
int Salir(){
	int x;
	
	do {
		cout << "\n\t¿Está seguro de desear salir?" << endl;
		cout << "\t(1) Sí, (2) No: ";
		scanf("%d", &x); fflush(stdin);
	} while(x < 1 || x > 2);
	
	return x;
}
