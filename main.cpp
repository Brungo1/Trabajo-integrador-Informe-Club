#include <iostream>
#include "rlutil.h"
#include "Socio.h"
#include "Actividad.h"
#include "Inscripcion.h"
using namespace std;

void mostrarEncabezado(const char* titulo, int color);
void mostrarMenuPrincipal();
void menuSocios();
void menuActividades();
void menuInscripciones();

int main() {
    mostrarMenuPrincipal();
    return 0;
}

void mostrarEncabezado(const char* titulo, int color) {
    rlutil::setColor(color);
    cout << "\n";
    cout << "  " << char(201);
    for(int i = 0; i < 60; i++) cout << char(205);
    cout << char(187) << endl;
    
    cout << "  " << char(186);
    int espacios = (60 - strlen(titulo)) / 2;
    for(int i = 0; i < espacios; i++) cout << " ";
    cout << titulo;
    for(int i = 0; i < 60 - espacios - strlen(titulo); i++) cout << " ";
    cout << char(186) << endl;
    
    cout << "  " << char(200);
    for(int i = 0; i < 60; i++) cout << char(205);
    cout << char(188) << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "\n";
}

void mostrarMenuPrincipal() {
    int opcion;
    do {
        rlutil::cls();
        mostrarEncabezado("SISTEMA DE GESTION DE CLUB", rlutil::LIGHTCYAN);
        
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "  " << char(175) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[1] Gestion de Socios" << endl;
        
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "  " << char(175) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[2] Gestion de Actividades" << endl;
        
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "  " << char(175) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[3] Gestion de Inscripciones" << endl;
        
        cout << "\n  " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << endl;
        
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "  " << char(175) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[0] Salir del Sistema" << endl;
        
        cout << "\n  ";
        rlutil::setColor(rlutil::YELLOW);
        cout << "Seleccione una opcion: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;

        switch(opcion) {
            case 1: menuSocios(); break;
            case 2: menuActividades(); break;
            case 3: menuInscripciones(); break;
            case 0: 
                rlutil::cls();
                rlutil::setColor(rlutil::LIGHTGREEN);
                cout << "\n\n  " << char(175) << " Gracias por usar el sistema. Hasta pronto!\n\n" << endl;
                rlutil::setColor(rlutil::WHITE);
                break;
            default:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\n  [ERROR] Opcion invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
        }
    } while(opcion != 0);
}

void menuSocios() {
    int opcion;
    do {
        rlutil::cls();
        mostrarEncabezado("GESTION DE SOCIOS", rlutil::YELLOW);
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[1] Agregar Nuevo Socio" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[2] Listar Todos los Socios" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[3] Buscar Socio" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[4] Modificar Datos de Socio" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[5] Eliminar Socio" << endl;
        
        cout << "\n  " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << endl;
        
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "  " << char(27) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[0] Volver al Menu Principal" << endl;
        
        cout << "\n  ";
        rlutil::setColor(rlutil::YELLOW);
        cout << "Seleccione una opcion: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;

        switch(opcion) {
            case 1: 
            case 2: 
            case 3: 
            case 4:
            case 5:
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                cout << "\n  [INFO] Funcion en desarrollo..." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
                break;
        }
    } while(opcion != 0);
}

void menuActividades() {
    int opcion;
    do {
        rlutil::cls();
        mostrarEncabezado("GESTION DE ACTIVIDADES", rlutil::LIGHTGREEN);
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[1] Agregar Nueva Actividad" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[2] Listar Todas las Actividades" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[3] Buscar Actividad" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[4] Modificar Actividad" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[5] Desactivar Actividad" << endl;
        
        cout << "\n  " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << endl;
        
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "  " << char(27) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[0] Volver al Menu Principal" << endl;
        
        cout << "\n  ";
        rlutil::setColor(rlutil::YELLOW);
        cout << "Seleccione una opcion: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;

        switch(opcion) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                cout << "\n  [INFO] Funcion en desarrollo..." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
                break;
        }
    } while(opcion != 0);
}

void menuInscripciones() {
    int opcion;
    do {
        rlutil::cls();
        mostrarEncabezado("GESTION DE INSCRIPCIONES", rlutil::LIGHTMAGENTA);
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[1] Nueva Inscripcion" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[2] Listar Todas las Inscripciones" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[3] Buscar Inscripciones por Socio" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[4] Buscar Inscripciones por Actividad" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[5] Cancelar Inscripcion" << endl;
        
        cout << "\n  " << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << char(196) << endl;
        
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "  " << char(27) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[0] Volver al Menu Principal" << endl;
        
        cout << "\n  ";
        rlutil::setColor(rlutil::YELLOW);
        cout << "Seleccione una opcion: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;

        switch(opcion) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                rlutil::setColor(rlutil::LIGHTMAGENTA);
                cout << "\n  [INFO] Funcion en desarrollo..." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
                break;
        }
    } while(opcion != 0);
}
