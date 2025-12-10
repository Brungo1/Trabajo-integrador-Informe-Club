#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "menu.h"
using namespace std;

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
        
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "  " << char(175) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[4] Gestion de Pagos" << endl;
        
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "  " << char(175) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[5] Gestion de Canchas" << endl;
        
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "  " << char(175) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[6] Gestion de Reservas" << endl;
        
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "  " << char(175) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[7] Gestion de Asistencia" << endl;
        
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
            case 4: menuPagos(); break;
            case 5: menuCanchas(); break;
            case 6: menuReservas(); break;
            case 7: menuAsistencia(); break;
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
            case 1: agregarSocio(); break;
            case 2: listarSocios(); break;
            case 3: buscarSocio(); break;
            case 4: modificarSocio(); break;
            case 5: eliminarSocio(); break;
            case 0: break;
            default:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\n  [ERROR] Opcion invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
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
        cout << "[3] Buscar Actividad por ID" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[4] Buscar Actividad por Nombre" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[5] Modificar Actividad" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[6] Desactivar Actividad" << endl;
        
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
            case 1: agregarActividad(); break;
            case 2: listarActividades(); break;
            case 3: buscarActividad(); break;
            case 4: buscarActividadPorNombre(); break;
            case 5: modificarActividad(); break;
            case 6: desactivarActividad(); break;
            case 0: break;
            default:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\n  [ERROR] Opcion invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
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
            case 1: nuevaInscripcion(); break;
            case 2: listarInscripciones(); break;
            case 3: buscarInscripcionesPorSocio(); break;
            case 4: buscarInscripcionesPorActividad(); break;
            case 5: cancelarInscripcion(); break;
            case 0: break;
            default:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\n  [ERROR] Opcion invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
        }
    } while(opcion != 0);
}

void menuPagos() {
    int opcion;
    do {
        rlutil::cls();
        mostrarEncabezado("GESTION DE PAGOS", rlutil::LIGHTBLUE);
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[1] Registrar Nuevo Pago" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[2] Listar Todos los Pagos" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[3] Buscar Pagos por Socio" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[4] Modificar Estado de Pago" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[5] Reporte de Pagos" << endl;
        
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
            case 1: registrarPago(); break;
            case 2: listarPagos(); break;
            case 3: buscarPagosPorSocio(); break;
            case 4: modificarEstadoPago(); break;
            case 5: reportePagos(); break;
            case 0: break;
            default:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\n  [ERROR] Opcion invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
        }
    } while(opcion != 0);
}

void menuCanchas() {
    int opcion;
    do {
        rlutil::cls();
        mostrarEncabezado("GESTION DE CANCHAS", rlutil::BROWN);
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[1] Agregar Nueva Cancha" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[2] Listar Todas las Canchas" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[3] Buscar Cancha por Numero" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[4] Buscar Cancha por Tipo" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[5] Modificar Datos de Cancha" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[6] Cambiar Disponibilidad" << endl;
        
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
            case 1: agregarCancha(); break;
            case 2: listarCanchas(); break;
            case 3: buscarCancha(); break;
            case 4: buscarCanchaPorTipo(); break;
            case 5: modificarCancha(); break;
            case 6: cambiarDisponibilidad(); break;
            case 0: break;
            default:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\n  [ERROR] Opcion invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
        }
    } while(opcion != 0);
}

void menuReservas() {
    int opcion;
    do {
        rlutil::cls();
        mostrarEncabezado("GESTION DE RESERVAS", rlutil::CYAN);
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[1] Nueva Reserva" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[2] Listar Todas las Reservas" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[3] Buscar Reservas por Socio" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[4] Buscar Reservas por Cancha" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[5] Cancelar Reserva" << endl;
        
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
            case 1: nuevaReserva(); break;
            case 2: listarReservas(); break;
            case 3: buscarReservasPorSocio(); break;
            case 4: buscarReservasPorCancha(); break;
            case 5: cancelarReserva(); break;
            case 0: break;
            default:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\n  [ERROR] Opcion invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
        }
    } while(opcion != 0);
}

void menuAsistencia() {
    int opcion;
    do {
        rlutil::cls();
        mostrarEncabezado("GESTION DE ASISTENCIA", rlutil::LIGHTRED);
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[1] Registrar Asistencia" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[2] Listar Asistencias" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[3] Buscar por Socio" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[4] Buscar por Actividad" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[5] Reporte de Asistencia" << endl;
        
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
            case 1: registrarAsistencia(); break;
            case 2: listarAsistencias(); break;
            case 3: buscarAsistenciaPorSocio(); break;
            case 4: buscarAsistenciaPorActividad(); break;
            case 5: reporteAsistencia(); break;
            case 0: break;
            default:
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\n  [ERROR] Opcion invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::WHITE);
                rlutil::anykey();
        }
    } while(opcion != 0);
}