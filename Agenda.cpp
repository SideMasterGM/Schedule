#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define CANTIDAD 500 /*Cantidad de contactos*/

using namespace std;

int ContactosRegistrados = 0;
string Regla = "=============================================================";

struct Agenda {
	string Nombre;
	string Telefono;
	string Celular;
	string Email;
	
	Agenda(); // Declaración del constructor
};

int MenuPrimario();
int MenuSecundario();
void Insertar(struct Agenda Contactos[]);

void Buscar(struct Agenda Contactos[]);
int BuscarMenuCategoria();
void BuscarPorNombre(struct Agenda Contactos[]);
void BuscarPorTelefono(struct Agenda Contactos[]);
void BuscarPorCelular(struct Agenda Contactos[]);
void BuscarPorEmail(struct Agenda Contactos[]);

void Listar(struct Agenda Contactos[]);
void Imprimir(struct Agenda Contactos[], int);

void Actualizar(struct Agenda Contactos[]);
void Eliminar(struct Agenda Contactos[]);

void CargarContactos(struct Agenda Contactos[]);

int HayContactos(struct Agenda Contactos[], int);

void Detenerse();
void LimpiarPantalla();
void Dormir(int);
int Salir();

// Definición del constructor, fuera de la estructura
Agenda::Agenda() {
	Nombre = " ";
	Telefono = "0";
	Celular = "0";
	Email = " ";
}

int main(int argc, char *argv[]) {
	int x, Inicial = 0;
	
	Agenda Contactos[CANTIDAD]; /*Definición de la variable Contactos con la cantidad*/
	
	CargarContactos(Contactos);
	
	Menu:
		if (HayContactos(Contactos, Inicial)){
			/*No hay contactos*/
			do {
				x = MenuPrimario();
			} while(x < 1 || x > 2);
			
			switch (x){
				case 1: 
					Insertar(Contactos);
					break;
				case 2:
					if (Salir() == 1)
						goto Finish;
					break;
				default:
					cout << "Up's, ha ocurrido algo inesperado, presione una tecla para continuar!." << endl;
					system("PAUSE>NUL");
					break;
			}
			
		} else {
			/*Si hay contactos*/
			do {
				x = MenuSecundario();
			} while(x < 1 || x > 4);
			
			switch (x){
				case 1: 
					Insertar(Contactos);
					break;
				case 2:
					Buscar(Contactos);
					break;
				case 3: 
					Listar(Contactos);
					break;
				case 4:
					if (Salir() == 1)
						goto Finish;
					break;
				default:
					cout << "Up's, ha ocurrido algo inesperado, presione una tecla para continuar!." << endl;
					system("PAUSE>NUL");
					break;
			}
		}
	
	goto Menu;
	
	Finish: 
		return 0;
}

int MenuPrimario(){
	char x[1];
	
	LimpiarPantalla();
	
	cout << Regla << endl;
	cout << "|\tBienvenido a tu Agenda Electrónica (Contactos)\t    |" << endl;
	cout << Regla << endl;
	
	//Dormir(1);
	cout << "|\t\t\t\t\t\t\t    |" << endl;
	cout << "|\t\t       No hay contactos\t\t\t    |" << endl;
	cout << "|\t\t\t\t\t\t\t    |" << endl;
	//Dormir(1);
	
	cout << Regla << endl;
	cout << "| (1) Nuevo contacto           |        (2) Salir           |" << endl;
	cout << Regla << endl;
	
	cout << "Esperando respuesta: ";
	cin >> x;
	cin.ignore();
	
	return atoi(x);
}

int MenuSecundario(){
	char x[1];
	
	LimpiarPantalla();
	
	cout << Regla << endl;
	cout << "|\tBienvenido a tu Agenda Electrónica (Contactos)\t    |" << endl;
	cout << Regla << endl;
	
	cout << "|\t\t\t\t\t\t\t    |" << endl;
	cout << "|\t\t      Sí hay contactos" << " (" << ContactosRegistrados << ")\t\t    |" << endl;
	cout << "|\t\t\t\t\t\t\t    |" << endl;
		
	cout << Regla << endl;
	cout << "| (1) Nuevo   | (2) Buscar   |  (3) Listar   |  (4) Salir   |" << endl;
	cout << Regla << endl;
	
	cout << "Esperando respuesta: ";
	cin >> x;
	cin.ignore();
	
	return atoi(x);
}

void Insertar(struct Agenda Contactos[]){
	
	if (ContactosRegistrados < CANTIDAD){
		cout << "\n\tNúmero de contacto: " << (ContactosRegistrados + 1) << endl;
		cout << "\tNombre:   ";
		getline(cin, Contactos[ContactosRegistrados].Nombre);
		
		cout << "\tTeléfono: ";
		getline(cin, Contactos[ContactosRegistrados].Telefono);
		
		cout << "\tCelular:  ";
		getline(cin, Contactos[ContactosRegistrados].Celular);
		
		cout << "\tEmail:    ";
		getline(cin, Contactos[ContactosRegistrados].Email);
		
		ContactosRegistrados++;
		
		cout << "\n\t¡Agregado con éxito!" << endl << endl;
		
	} else {
		cout << "Llegó al límite de contactos permitidos en la agenda." << endl << endl;
	}
	
	Detenerse();
	return;
}

void Buscar(struct Agenda Contactos[]){
	int x;
	
	BuscarMenu: 
		LimpiarPantalla();
	
		do {
			x = BuscarMenuCategoria();
		} while(x < 1 || x > 5);
		
		switch (x){
			case 1: 
				BuscarPorNombre(Contactos);
				break;
			case 2:
				BuscarPorTelefono(Contactos);
				break;
			case 3: 
				BuscarPorCelular(Contactos);
				break;
			case 4: 
				BuscarPorEmail(Contactos);
				break;
			case 5:
				if (Salir() == 1)
					goto BuscarFinish;
				break;
			default:
				cout << "Up's, ha ocurrido algo inesperado, presione una tecla para continuar!." << endl;
				system("PAUSE>NUL");
				break;
		}
	
	goto BuscarMenu;
	
	BuscarFinish: 
		Detenerse();
		return;
}

int BuscarMenuCategoria(){
	char x[1]; 
	
	cout << endl << "\n\t\t     Realizar búsqueda por:" << endl << endl;
	cout << "(1)Nombre | (2)Teléfono | (3)Celular | (4)Email | (5)Volver" << endl;
	cout << Regla << endl;
	
	cout << "Esperando respuesta: ";
	cin >> x;
	cin.ignore();
	
	return atoi(x);
}

void BuscarPorNombre(struct Agenda Contactos[]){
	int i = 0; 
	int c = 0;					/*Coincidencias*/
	
	string PorNombre;
	
	cout << "\n\tDigite el nombre: ";
	getline(cin, PorNombre);
	cout << endl;
	
	for (; i < ContactosRegistrados; i++){
		if (Contactos[i].Nombre == PorNombre){
			Imprimir(Contactos, i);
			c++;
			break;
		}
	}
	
	if (c == 0){
		cout << "\n\tEl contacto \"" << PorNombre << "\" no se ha encontrado." << endl << endl;
	}
	
	Detenerse();
	return;
}

void BuscarPorTelefono(struct Agenda Contactos[]){
	int i = 0; 
	int c = 0;					/*Coincidencias*/
	
	string PorTelefono;
	
	cout << "\n\tDigite el número de teléfono: ";
	getline(cin, PorTelefono);
	cout << endl;
	
	for (; i < ContactosRegistrados; i++){
		if (Contactos[i].Telefono == PorTelefono){
			Imprimir(Contactos, i);
			c++;
			break;
		}
	}
	
	if (c == 0){
		cout << "\n\tEl contacto \"" << PorTelefono << "\" no se ha encontrado." << endl << endl;
	}
	
	Detenerse();
	return;
}

void BuscarPorCelular(struct Agenda Contactos[]){
	int i = 0; 
	int c = 0;					/*Coincidencias*/
	
	string PorCelular;
	
	cout << "\n\tDigite el número de celular: ";
	getline(cin, PorCelular);
	cout << endl;
	
	for (; i < ContactosRegistrados; i++){
		if (Contactos[i].Celular == PorCelular){
			Imprimir(Contactos, i);
			c++;
			break;
		}
	}
	
	if (c == 0){
		cout << "\n\tEl contacto \"" << PorCelular << "\" no se ha encontrado." << endl << endl;
	}
	
	Detenerse();
	return;
}

void BuscarPorEmail(struct Agenda Contactos[]){
	int i = 0; 
	int c = 0;					/*Coincidencias*/
	
	string PorEmail;
	
	cout << "\n\tDigite el Email: ";
	getline(cin, PorEmail);
	cout << endl;
	
	for (; i < ContactosRegistrados; i++){
		if (Contactos[i].Email == PorEmail){
			Imprimir(Contactos, i);
			c++;
			break;
		}
	}
	
	if (c == 0){
		cout << "\n\tEl contacto \"" << PorEmail << "\" no se ha encontrado." << endl << endl;
	}
	
	Detenerse();
	return;
}


void Listar(struct Agenda Contactos[]){
	int i = 0, contactos_restantes = 0;
	
	for (; i < ContactosRegistrados; i++){
		if (i > 1){
			contactos_restantes = ContactosRegistrados - i;
			
			Dormir(1);
			
			if (contactos_restantes > 1)
				cout << "\t-- Aún quedan " << (ContactosRegistrados - i) << " por visualizar --" << endl;
			else if (contactos_restantes == 1)
				cout << "\t-- Aún queda " << (ContactosRegistrados - i) << " por visualizar --" << endl;
				
			Detenerse();
			cout << endl;
		}
		
		cout << "\n\tNúmero de contacto: " << (i + 1) << endl;
		cout << "\t\tNombre:   " << Contactos[i].Nombre << endl;
		cout << "\t\tTeléfono: " << Contactos[i].Telefono << endl;
		cout << "\t\tCelular:  " << Contactos[i].Celular << endl;
		cout << "\t\tEmail:    " << Contactos[i].Email << endl << endl;
	}
	
	cout << "\t <-- Regresar" << endl;
	Detenerse();
	return;
}
void Imprimir(struct Agenda Contactos[], int posicion){
	cout << "\n\t\tNombre:   " << Contactos[posicion].Nombre << endl;
	cout << "\t\tTeléfono: " << Contactos[posicion].Telefono << endl;
	cout << "\t\tCelular:  " << Contactos[posicion].Celular << endl;
	cout << "\t\tEmail:    " << Contactos[posicion].Email << endl << endl;
	
	return;
}
void Actualizar(struct Agenda Contactos[]){
	Detenerse();
	
	return;
}

void Eliminar(struct Agenda Contactos[]){
	Detenerse();
	
	return;
}

void CargarContactos(struct Agenda Contactos[]){
	char x[1];
	
	do {
		LimpiarPantalla();
			
		cout << Regla << endl;
		cout << "|\tBienvenido a tu Agenda Electrónica (Contactos)\t    |" << endl;
		cout << Regla << endl;
			
		cout << "(1) Cargar contactos previos | (2) Nueva agenda | (3) Salir |" << endl;
		cout << Regla << endl;
			
		cout << "Esperando respuesta: ";
		cin >> x;
		cin.ignore();
			
	} while(atoi(x) < 1 || atoi(x) > 3);
		
	switch (atoi(x)){
		case 1: 
			Contactos[ContactosRegistrados].Nombre 		= "Gonzalo Martínez";
			Contactos[ContactosRegistrados].Telefono 	= "+505 23192745";
			Contactos[ContactosRegistrados].Celular 	= "+505 84352642";
			Contactos[ContactosRegistrados].Email 		= "gonzalomartinez@gmail.com";
			ContactosRegistrados++;
				
			Contactos[ContactosRegistrados].Nombre 		= "Marcio Altamirano";
			Contactos[ContactosRegistrados].Telefono 	= "+505 26118394";
			Contactos[ContactosRegistrados].Celular 	= "+505 88393849";
			Contactos[ContactosRegistrados].Email 		= "marcioaltamirano@gmail.com";
			ContactosRegistrados++;
				
			Contactos[ContactosRegistrados].Nombre 		= "Maria Centeno";
			Contactos[ContactosRegistrados].Telefono 	= "+505 23193473";
			Contactos[ContactosRegistrados].Celular 	= "+505 81212259";
			Contactos[ContactosRegistrados].Email 		= "mariacenteno@gmail.com";
			ContactosRegistrados++;
				
			Contactos[ContactosRegistrados].Nombre 		= "Angela Salgado";
			Contactos[ContactosRegistrados].Telefono 	= "+505 26114777";
			Contactos[ContactosRegistrados].Celular 	= "+505 88932231";
			Contactos[ContactosRegistrados].Email 		= "angelasalgado@gmail.com";
			ContactosRegistrados++;
			break;
		case 2:
			return;
		case 3: 
			if (Salir() == 1)
				return;
		default:
			cout << "\n\tUp's, ha ocurrido algo inesperado, presione una tecla para continuar!." << endl;
			Detenerse();
			break;
	}
	
	return;
}
int HayContactos(struct Agenda Contactos[], int Inicial){
	int i = 0; 					/*Iterador*/
	int c = 0;					/*Coincidencias*/
	
	for (; i < CANTIDAD; i++){
		if (Contactos[Inicial].Nombre == " "){
			c++;
			break;
		}
	}
	
	if (c > 0)
		return true;
	
	return false;
}

void Detenerse(){
	cout << "\t¡Presione una tecla para continuar!";
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
