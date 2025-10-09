#include <iostream>
#include "rlutil.h"
#include "Socio.h"
#include "Actividad.h"
#include "Inscripcion.h"
using namespace std;

void mostrarMenuPrincipal();
void menuSocios();
void menuActividades();
void menuInscripciones();

int main() {
    mostrarMenuPrincipal();
    return 0;
}

void mostrarMenuPrincipal() {
    int opcion;
    do {
        rlutil::cls();
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "========================================" << endl;
        cout << "   SISTEMA DE GESTION DE CLUB" << endl;
        cout << "========================================" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "1. Gestion de Socios" << endl;
        cout << "2. Gestion de Actividades" << endl;
        cout << "3. Gestion de Inscripciones" << endl;
        cout << "0. Salir" << endl;
        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: menuSocios(); break;
            case 2: menuActividades(); break;
            case 3: menuInscripciones(); break;
            case 0: 
                rlutil::setColor(rlutil::LIGHTGREEN);
                cout << "\nSaliendo del sistema..." << endl;
                rlutil::setColor(rlutil::WHITE);
                break;
            default:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\nOpcion invalida!" << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
        }
    } while(opcion != 0);
}

void menuSocios() {
    int opcion;
    do {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        cout << "=== GESTION DE SOCIOS ===" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "1. Agregar Socio" << endl;
        cout << "2. Listar Socios" << endl;
        cout << "3. Buscar Socio" << endl;
        cout << "4. Modificar Socio" << endl;
        cout << "0. Volver" << endl;
        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "\n[Funcion en desarrollo]" << endl; rlutil::anykey(); break;
            case 2: cout << "\n[Funcion en desarrollo]" << endl; rlutil::anykey(); break;
            case 3: cout << "\n[Funcion en desarrollo]" << endl; rlutil::anykey(); break;
            case 4: cout << "\n[Funcion en desarrollo]" << endl; rlutil::anykey(); break;
        }
    } while(opcion != 0);
}

void menuActividades() {
    int opcion;
    do {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        cout << "=== GESTION DE ACTIVIDADES ===" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "1. Agregar Actividad" << endl;
        cout << "2. Listar Actividades" << endl;
        cout << "3. Modificar Actividad" << endl;
        cout << "0. Volver" << endl;
        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "\n[Funcion en desarrollo]" << endl; rlutil::anykey(); break;
            case 2: cout << "\n[Funcion en desarrollo]" << endl; rlutil::anykey(); break;
            case 3: cout << "\n[Funcion en desarrollo]" << endl; rlutil::anykey(); break;
        }
    } while(opcion != 0);
}

void menuInscripciones() {
    int opcion;
    do {
        rlutil::cls();
        rlutil::setColor(rlutil::YELLOW);
        cout << "=== GESTION DE INSCRIPCIONES ===" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << "1. Nueva Inscripcion" << endl;
        cout << "2. Listar Inscripciones" << endl;
        cout << "0. Volver" << endl;
        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1: cout << "\n[Funcion en desarrollo]" << endl; rlutil::anykey(); break;
            case 2: cout << "\n[Funcion en desarrollo]" << endl; rlutil::anykey(); break;
        }
    } while(opcion != 0);
}
