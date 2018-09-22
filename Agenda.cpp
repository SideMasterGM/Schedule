/*****************************
 Librerías utilzadas
*****************************/
#include <iostream>					/*Flujo de entrada y salida de datos*/
#include <string.h>					/*Funciones de manejo de cadenas*/
#include <windows.h>				/*Permite usar comandos de Windows Console*/

#define CANTIDAD 500 				/*Cantidad máxima de contactos: 500*/

using namespace std;

/*
	Variables globales que representan 
	contactos registrados, eliminados y
	una variable Regla que presentará una
	mejor vista en el programa.
*/
int ContactosRegistrados = 0;
int ContactosEliminados  = 0;
string Regla = "=============================================================";

/*****************************
Estructura de fecha y Agenda
*****************************/
/*Estructura de fecha de nacimiento*/
struct Cumple {
	string Nacimiento;
};

/*Estructura de Agenda, contiene todos los atributos*/
struct Agenda {
	string Nombre;
	string Telefono;
	string Celular;
	string Email;
	Cumple Fecha;					/*Referencia a la estructura Cumple*/
	Agenda();  						/*Declaración del constructor*/
};

/*****************************
	FUNCIONES PRINCIPALES 
*****************************/

int MenuPrimario();					/*Se muestra cuando no hay contactos*/
int MenuSecundario();				/*Se muestra cuando hay contactos que gestionar*/

/*Relevante e importante*/
void Insertar(struct Agenda Contactos[]);			/*Inserta contactos en la agenda*/

/*Relevante e importante*/
void Buscar(struct Agenda Contactos[]);				/*Busca contactos en la agenda*/
int BuscarMenuCategoria();							/*Se muestra un menú para buscar por categorías*/
void BuscarPorNombre(struct Agenda Contactos[]);	/*Aplica una búsqueda por nombre de contacto*/
void BuscarPorTelefono(struct Agenda Contactos[]);	/*Aplica una búsqueda por teléfono de contacto*/
void BuscarPorCelular(struct Agenda Contactos[]);	/*Aplica una búsqueda por celular de contacto*/
void BuscarPorEmail(struct Agenda Contactos[]);		/*Aplica una búsqueda por email de contacto*/

/*Relevante e importante*/
void Listar(struct Agenda Contactos[]);				/*Lista todos los contactos existentes*/
void Imprimir(struct Agenda Contactos[], int);		/*Mostrar un contacto seleccionado*/

/*Relevante e importante*/
void Actualizar(struct Agenda Contactos[], int);	/*Actualiza un contacto seleccionado en la agenda*/
/*Relevante e importante*/
void Eliminar(struct Agenda Contactos[], int);		/*Elimina un contacto seleccionado en la agenda*/

int VerificarContacto(struct Agenda Contactos[], string);	/*Verifica si el contacto especificado existe*/

/*
Esta función es interesante, tiene como objetivo
cargar datos (contactos) en la agenda para pruebas
rápidas en la ejcución del programa.
*/
void CargarContactos(struct Agenda Contactos[]);
bool HayContactos(struct Agenda Contactos[]);		/*Verifica si hay contactos en la agenda*/

/*****************************
	FUNCIONES SECUNDARIAS
*****************************/
void Detenerse();									/*Detiene la ejecución, hasta que se presione una tecla*/
void LimpiarPantalla();								/*Limpia la pantalla para mostrar un nuevo menú*/
void Dormir(int);									/*Aplica un retraso temporal*/
int Salir();										/*Centinela que pregunta por la salida de los menúes*/

/*****************************
 DEFINICIÓN DEL CONSTRUCTOR
-----------------------------
Inicializando la estructura.
*****************************/
Agenda::Agenda() {
	Nombre 		= " ";								/*Para nombre, dejar un espacio en blanco*/
	Telefono 	= "0";								/*Para teléfono, dejar 0 como contenido*/
	Celular 	= "0";								/*Para celular, dejar 0 como contenido*/
	Email 		= " ";								/*Para email, dejar un espacio en blanco*/
	Fecha.Nacimiento = " ";							/*Para fecha, dejar un espacio en blanco*/
}

/*****************************
	  FUNCIÓN PRINCIPAL
*****************************/
int main(int argc, char *argv[]) {
	int x;											/*Almacena las opciones seleccionadas*/
	Agenda Contactos[CANTIDAD]; 					/*Definición de la variable Contactos con la cantidad*/
	CargarContactos(Contactos);						/*Menú para cargar datos o iniciar una nueva agenda*/
	
	Menu:											/*Etiqueta para retornar al Menu recursivamente*/
		if (HayContactos(Contactos)){				/*Verifica si no hay contactos*/
			ContactosRegistrados = 0;
			ContactosEliminados  = 0;
			/*No hay contactos*/
			do {
				x = MenuPrimario();					/*Primer menú donde la agenda está vacía*/
			} while(x < 1 || x > 2);
			
			switch (x){								/*En este menú se validan 2 opciones (Insertar, Salir)*/
				case 1: 
					Insertar(Contactos);			/*Menú para insertar datos*/
					break;
				case 2:
					if (Salir() == 1)				/*Centinela para Salir*/
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
				x = MenuSecundario();				/*Segundo menú donde la agenda contiene contactos*/
			} while(x < 1 || x > 4);
			
			switch (x){								/*Este menú contiene más opciones (Insertar, buscar, listar)*/
				case 1: 
					Insertar(Contactos);
					break;
				case 2:
					Buscar(Contactos);				/*Menú para realizar una búsqueda de contactos por categorías*/
					break;
				case 3: 
					Listar(Contactos);				/*Listar todos los contactos existentes de manera interactiva*/
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
	
	goto Menu;						/*Se retorna al menú principal en caso de que no haya seleccionado Salir*/
	
	Finish: 						/*Etiqueta para finalizar el programa*/
		return 0;
}

int MenuPrimario(){
	char x[1];										/*Sirve para almacenar la respuesta (opción)*/
	
	LimpiarPantalla();
	
	cout << Regla << endl;
	cout << "|\tBienvenido a tu Agenda Electrónica (Contactos)\t    |" << endl;
	cout << Regla << endl;
	
	cout << "|\t\t\t\t\t\t\t    |" << endl;
	cout << "|\t\t       No hay contactos\t\t\t    |" << endl;
	cout << "|\t\t\t\t\t\t\t    |" << endl;
	
	cout << Regla << endl;
	cout << "| (1) Nuevo contacto           |        (2) Salir           |" << endl;
	cout << Regla << endl;
	
	cout << "Esperando respuesta: ";
	cin >> x;
	cin.ignore();									/*Ignora el resto de flujo de datos*/
	
	return atoi(x);									/*Convierte y retorna la opción seleccionada*/
}

int MenuSecundario(){
	char x[1];
	
	LimpiarPantalla();
	
	cout << Regla << endl;
	cout << "|\tBienvenido a tu Agenda Electrónica (Contactos)\t    |" << endl;
	cout << Regla << endl;
	
	cout << "|\t\t\t\t\t\t\t    |" << endl;
	cout << "|\t\t      Sí hay contactos" << " (" << (ContactosRegistrados - ContactosEliminados) << ")\t\t    |" << endl;
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
	char x[1];
	
	InsertarMenu: 									/*Etiqueta de menú para insertar contactos*/
		
		/*Se verifica si hay espacio en la agenda*/
		if (ContactosRegistrados < CANTIDAD){
			cout << "\n\tNúmero de contacto: " << (ContactosRegistrados + 1) << endl;
			cout << "\tNombre:   ";
			getline(cin, Contactos[ContactosRegistrados].Nombre);
			
			/*Se verifica si el contacto que está intentando insertar, existe en la agenda*/
			if (VerificarContacto(Contactos, Contactos[ContactosRegistrados].Nombre)){
				cout << "\n\tEl contacto \"" << Contactos[ContactosRegistrados].Nombre << "\" ya existe!" << endl;
				
				Contactos[ContactosRegistrados].Nombre = " ";
				
				goto InsertarOtroContacto;							/*Si existe se intenta ingresar otro*/
			}
			
			cout << "\tTeléfono: ";									
			getline(cin, Contactos[ContactosRegistrados].Telefono);	/*Agregando valor a atributo Telefono*/
			
			cout << "\tCelular:  ";
			getline(cin, Contactos[ContactosRegistrados].Celular);	/*Agregando valor a atributo Celular*/
			
			cout << "\tEmail:    ";
			getline(cin, Contactos[ContactosRegistrados].Email);	/*Agregando valor a atributo Email*/
			
			cout << "\tFecha de Nacimiento (DD/MM/AAAA): ";
			getline(cin, Contactos[ContactosRegistrados].Fecha.Nacimiento);	/*Agregando valor a atributo de Fecha*/
			
			ContactosRegistrados++;									/*Se incrementa la variable, indicando nuevo contacto*/
			
			cout << "\n\t¡Agregado con éxito!" << endl << endl;
			
			InsertarOtroContacto: 									/*Etiqueta centinela, pregunta sobre otro contacto*/
				do {
					cout << "\n\t¿Desea agregar otro contacto?" << endl;
					cout << "\t(1) Sí, (2) No: ";
					cin >> x;
					cin.ignore();
				} while(atoi(x) < 1 || atoi(x) > 2);
				
				switch (atoi(x)){
					case 1: 
						goto InsertarMenu;
						break;
					case 2:
						goto InsertarFinish;
						break;
					default:
						cout << "Up's, ha ocurrido algo inesperado, presione una tecla para continuar!." << endl;
						Detenerse();
						break;
				}
			
		} else {
			cout << "Llegó al límite de contactos permitidos en la agenda." << endl << endl;
		}
	
	InsertarFinish: 
		Detenerse();
		return;
}

void Buscar(struct Agenda Contactos[]){
	int x;
	
	BuscarMenu: 
		LimpiarPantalla();
	
		do {
			x = BuscarMenuCategoria();				/*Menú para buscar contactos por categorías*/
		} while(x < 1 || x > 5);
		
		switch (x){
			case 1: 
				BuscarPorNombre(Contactos);			/*Buscar por nombre*/
				break;
			case 2:
				BuscarPorTelefono(Contactos);		/*Buscar por teléfono*/
				break;
			case 3: 
				BuscarPorCelular(Contactos);		/*Buscar por celular*/
				break;
			case 4: 
				BuscarPorEmail(Contactos);			/*Buscar por email*/
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
	int i = 0; 					/*Iterador en el ciclo*/
	int c = 0;					/*Coincidencias*/
	
	string PorNombre;
	
	cout << "\n\tDigite el nombre: ";
	getline(cin, PorNombre);
	cout << endl;
	
	/*Recorrer la cantidad de contactos registrados en la agenda*/
	for (; i < ContactosRegistrados; i++){
		if (Contactos[i].Nombre == PorNombre){				/*Si lo encuentra*/
			Imprimir(Contactos, i);							/*Muestra la información del contacto*/
			c++;
			break;
		}
	}
	
	if (c == 0)
		cout << "\n\tEl contacto \"" << PorNombre << "\" no se ha encontrado." << endl << endl;
	
	Detenerse();
	return;
}

void BuscarPorTelefono(struct Agenda Contactos[]){
	int i = 0; 
	int c = 0;
	
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
	int i = 0;									/*Iterador del ciclo*/
	int x = 0; 									/*Número de contacto*/
	int contactos_restantes = 0;				/*Contactos restantes*/
	
	/*Se recorren todos los contactos registrados*/
	for (; i < ContactosRegistrados; i++){
		
		/*Si se encuentran contactos registrados*/
		if (Contactos[i].Nombre != " "){
			if (i > 1){
				contactos_restantes = (ContactosRegistrados - x) - ContactosEliminados;
				Dormir(1);						/*Aplicar retraso de 1 segundo*/
				
				if (contactos_restantes > 1)
					cout << "\t-- Aún quedan " << contactos_restantes << " por visualizar --" << endl;
				else if (contactos_restantes == 1)
					cout << "\t-- Sólo queda " << contactos_restantes << " por visualizar --" << endl;
				
				Detenerse();
				cout << endl;
			}
			
			/*Impresión de todos los datos de los contactos resultates*/
			cout << "\n\tNúmero de contacto: " << (x+1) << endl;
			cout << "\t\tNombre:   " << Contactos[i].Nombre << endl;
			cout << "\t\tTeléfono: " << Contactos[i].Telefono << endl;
			cout << "\t\tCelular:  " << Contactos[i].Celular << endl;
			cout << "\t\tEmail:    " << Contactos[i].Email << endl;
			cout << "\t\tFecha N.: " << Contactos[i].Fecha.Nacimiento << endl << endl;
			
			x++;			/*Incremento de la variable de número de contacto*/
		}
	}
	
	cout << "\t <-- Regresar" << endl;
	Detenerse();
	return;
}
void Imprimir(struct Agenda Contactos[], int posicion){
	char x[1];
	
	/*Imprime el contacto que está en una posición específica de la agenda*/
	cout << "\n\t\tNombre:   " << Contactos[posicion].Nombre << endl;
	cout << "\t\tTeléfono: " << Contactos[posicion].Telefono << endl;
	cout << "\t\tCelular:  " << Contactos[posicion].Celular << endl;
	cout << "\t\tEmail:    " << Contactos[posicion].Email << endl;
	cout << "\t\tFecha N.: " << Contactos[posicion].Fecha.Nacimiento << endl << endl;
	
	/*CENTINELA: Opciones Actualizar y Elmiminar contacto*/
	do {
		cout << "\t  Opciones del contacto \"" << Contactos[posicion].Nombre << "\"" << endl;
		cout << "\t(1) Actualizar | (2) Eliminar | (3) Volver " << endl;
		cout << Regla << endl;
		
		cout << "Esperando respuesta: ";
		cin >> x;
		cin.ignore();
		cout << endl;
		
	} while(atoi(x) < 1 || atoi(x) > 3);
	
	switch (atoi(x)){
	case 1: 
		Actualizar(Contactos, posicion);				/*Actualiza el contacto seleccionado*/
		break;
	case 2:
		Eliminar(Contactos, posicion);					/*Elimina el contacto seleccionado*/
		break;
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

void Actualizar(struct Agenda Contactos[], int posicion){
	char x[1]; 
	string Nombre, Telefono, Celular, Email;			/*Declaración de variables que almacenarán una copia*/
	
	ActualizarOtroContacto: 
		
		Nombre 	= Contactos[posicion].Nombre;
		Telefono= Contactos[posicion].Telefono;
		Celular = Contactos[posicion].Celular;
		Email 	= Contactos[posicion].Email;
		
		/*Menú para seleccionar qué atributos desean actualizar*/
		do {
			cout << "\n\t¿Qué dato le gustaría actualizar de este contacto?" << endl;
			cout << "  (1)Nombre | (2)Teléfono | (3)Celular (4)Email | (5)Ninguno" << endl;
			cout << Regla << endl;
			
			cout << "Esperando respuesta: ";
			cin >> x;
			cin.ignore();
			cout << endl;
			
		} while(atoi(x) < 1 || atoi(x) > 5);
		
		/*Modificación para los correspondientes atributos seleccionados*/
		switch (atoi(x)){
			case 1: 
				cout << "\tDigite el nuevo nombre: ";
				getline(cin, Contactos[posicion].Nombre);
				cout << "   Se ha actualizado de \"" << Nombre << "\" a " << "\"" << Contactos[posicion].Nombre << "\"" << endl; 
				break;
			case 2:
				cout << "\tDigite el nuevo teléfono: ";
				getline(cin, Contactos[posicion].Telefono);
				cout << "   Se ha actualizado de \"" << Telefono << "\" a " << "\"" << Contactos[posicion].Telefono << "\"" << endl; 
				break;
			case 3: 
				cout << "\tDigite el nuevo celular: ";
				getline(cin, Contactos[posicion].Celular);
				cout << "   Se ha actualizado de \"" << Celular << "\" a " << "\"" << Contactos[posicion].Celular << "\"" << endl; 
				break;
			case 4: 
				cout << "\tDigite el nuevo email: ";
				getline(cin, Contactos[posicion].Email);
				cout << "   Se ha actualizado de \"" << Email << "\" a " << "\"" << Contactos[posicion].Email << "\"" << endl; 
				break;
			case 5: 
				if (Salir() == 1)
					return;
			default:
				cout << "\n\tUp's, ha ocurrido algo inesperado, presione una tecla para continuar!." << endl;
				Detenerse();
				break;
		}
		
		goto ActualizarOtroContacto;
	
	return;
}

void Eliminar(struct Agenda Contactos[], int posicion){
	string Nombre;
	
	Nombre = Contactos[posicion].Nombre;
	
	/*Después de ejecutar la centinela, se resetean los valores de esa posición
	  y no se vuelven a tomar en cuenta. Este algoritmo está trabajado para que 
	  no perjudique en ningún momento en la ejecución del programa.
	*/
	if (Salir() == 1){
		Contactos[posicion].Nombre 	= " ";
		Contactos[posicion].Telefono= "0";
		Contactos[posicion].Celular	= "0";
		Contactos[posicion].Email	= " ";
		ContactosEliminados++;
		
		cout << "\n¡El ex-contacto \"" << Nombre <<  "\" ha sido eliminado con éxito!\n\n";
	}
	
	return;
}

int VerificarContacto(struct Agenda Contactos[], string Nombre){
	int i = 0; 
	int c = 0;
	
	/*Verifica si existe un contacto en específico*/
	for (; i < ContactosRegistrados; i++){
		if (Contactos[i].Nombre == Nombre){
			c++;
			break;
		}
	}
	
	if (c == 0)
		return false;
	
	return true;
}
void CargarContactos(struct Agenda Contactos[]){
	char x[1];
	
	/*Cargar datos por omisión para realizar pruebas rápidas de las opciones
	  que presenta este programa sobre la gestión de contactos de la Agenda.
	*/
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
			/*Primer contacto*/
			Contactos[ContactosRegistrados].Nombre 			= "Gonzalo Martínez";
			Contactos[ContactosRegistrados].Telefono 		= "+505 23192745";
			Contactos[ContactosRegistrados].Celular 		= "+505 84352642";
			Contactos[ContactosRegistrados].Email 			= "gonzalomartinez@gmail.com";
			Contactos[ContactosRegistrados].Fecha.Nacimiento= "16/12/1986";
			ContactosRegistrados++;
			
			/*Segundo contacto*/
			Contactos[ContactosRegistrados].Nombre 			= "Marcio Altamirano";
			Contactos[ContactosRegistrados].Telefono 		= "+505 26118394";
			Contactos[ContactosRegistrados].Celular 		= "+505 88393849";
			Contactos[ContactosRegistrados].Email 			= "marcioaltamirano@gmail.com";
			Contactos[ContactosRegistrados].Fecha.Nacimiento= "22/08/1993";
			ContactosRegistrados++;
			
			/*Tercer contacto*/
			Contactos[ContactosRegistrados].Nombre 			= "Maria Centeno";
			Contactos[ContactosRegistrados].Telefono 		= "+505 23193473";
			Contactos[ContactosRegistrados].Celular 		= "+505 81212259";
			Contactos[ContactosRegistrados].Email 			= "mariacenteno@gmail.com";
			Contactos[ContactosRegistrados].Fecha.Nacimiento= "06/04/1996";
			ContactosRegistrados++;
			
			/*Cuarto contacto*/
			Contactos[ContactosRegistrados].Nombre 			= "Angela Salgado";
			Contactos[ContactosRegistrados].Telefono 		= "+505 26114777";
			Contactos[ContactosRegistrados].Celular 		= "+505 88932231";
			Contactos[ContactosRegistrados].Email 			= "angelasalgado@gmail.com";
			Contactos[ContactosRegistrados].Fecha.Nacimiento= "10/07/1999";
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
bool HayContactos(struct Agenda Contactos[]){
	int i = 0; 					/*Iterador*/
	int c = 0;					/*Coincidencias*/
	
	/*Verifica si hay contactos disponibles*/
	for (; i < CANTIDAD; i++)
		if (Contactos[i].Nombre != " ")
			c++;
	
	if (c > 0)
		return false; //Está vacío
	
	return true;
}

void Detenerse(){
	cout << "\t¡Presione una tecla para continuar!";
	system("PAUSE>NUL");								/*Pausar la aplicación sin mensaje de salida*/
}
void LimpiarPantalla(){
	system("CLS");									/*Limpiar pantalla*/
}
void Dormir(int x){
	Sleep(x * 1000);							/*Dormir el programa*/
}
int Salir(){
	char x[1];
	
	/*Centinela general*/
	do {
		cout << "\n\t¿Está segur@ de querer hacerlo?" << endl;
		cout << "\t(1) Sí, (2) No: ";
		cin >> x;
		cin.ignore();
	} while(atoi(x) < 1 || atoi(x) > 2);
	
	cout << endl;
	
	return atoi(x);
}
