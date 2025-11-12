#include <iostream>
#include "rlutil.h"
#include "Socio.h"
#include "Actividad.h"
#include "Inscripcion.h"
#include "Pago.h"
#include "Cancha.h"
#include "Reserva.h"
#include "Asistencia.h"
#include "ArchivoSocio.h"
using namespace std;

void mostrarEncabezado(const char* titulo, int color);
void mostrarMenuPrincipal();
void menuSocios();
void menuActividades();
void menuInscripciones();
void menuPagos();
void menuCanchas();
void menuReservas();
void menuAsistencia();

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

void agregarSocio() {
    ArchivoSocio archivo;
    Socio socio;
    int dni, dia, mes, anio;
    char nombre[30], apellido[30], telefono[20], email[50], confirma;
    
    rlutil::cls();
    mostrarEncabezado("AGREGAR NUEVO SOCIO", rlutil::LIGHTGREEN);
    
    int nuevoNumero = archivo.contarRegistros() + 1;
    socio.setNumeroSocio(nuevoNumero);
    
    cout << "  Numero de Socio: " << nuevoNumero << " (autoasignado)\n\n";
    
    cout << "  DNI (0 para cancelar): ";
    cin >> dni;
    
    if (dni == 0) {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.buscarPorDni(dni) != -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Ya existe un socio con ese DNI." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    socio.setDni(dni);
    
    cout << "  Nombre: ";
    cin.ignore();
    cin.getline(nombre, 30);
    socio.setNombre(nombre);
    
    cout << "  Apellido: ";
    cin.getline(apellido, 30);
    socio.setApellido(apellido);
    
    cout << "  Telefono: ";
    cin.getline(telefono, 20);
    socio.setTelefono(telefono);
    
    cout << "  Email: ";
    cin.getline(email, 50);
    socio.setEmail(email);
    
    cout << "\n  Fecha de Nacimiento:\n";
    cout << "    Dia: ";
    cin >> dia;
    cout << "    Mes: ";
    cin >> mes;
    cout << "    Anio: ";
    cin >> anio;
    
    Fecha fechaNac(dia, mes, anio);
    socio.setFechaNacimiento(fechaNac);
    socio.setEliminado(false);
    
    cout << "\n  Confirmar guardado? (S/N): ";
    cin >> confirma;
    
    if (confirma != 'S' && confirma != 's') {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.guardar(socio)) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [EXITO] Socio agregado correctamente!" << endl;
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se pudo guardar el socio." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void listarSocios() {
    ArchivoSocio archivo;
    int total = archivo.contarRegistros();
    int activos = 0;
    
    rlutil::cls();
    mostrarEncabezado("LISTADO DE SOCIOS", rlutil::LIGHTCYAN);
    
    if (total == 0) {
        cout << "  No hay socios registrados.\n";
        rlutil::anykey();
        return;
    }
    
    // Contar socios activos
    for (int i = 0; i < total; i++) {
        Socio s = archivo.leer(i);
        if (!s.getEliminado()) {
            activos++;
        }
    }
    
    if (activos == 0) {
        cout << "  No hay socios activos.\n";
        rlutil::anykey();
        return;
    }
    
    cout << "  Total de socios activos: " << activos << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Socio s = archivo.leer(i);
        if (!s.getEliminado()) {
            cout << "  " << char(254) << " Socio #" << s.getNumeroSocio() << endl;
            cout << "    DNI: " << s.getDni() << endl;
            cout << "    Nombre: " << s.getNombre() << " " << s.getApellido() << endl;
            cout << "    Telefono: " << s.getTelefono() << endl;
            cout << "    Email: " << s.getEmail() << endl;
            Fecha f = s.getFechaNacimiento();
            cout << "    Fecha Nac: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
            cout << endl;
        }
    }
    
    rlutil::anykey();
}

void buscarSocio() {
    ArchivoSocio archivo;
    int opcion, dni, numSocio, pos;
    
    rlutil::cls();
    mostrarEncabezado("BUSCAR SOCIO", rlutil::LIGHTMAGENTA);
    
    cout << "  [1] Buscar por DNI\n";
    cout << "  [2] Buscar por Numero de Socio\n";
    cout << "  [0] Cancelar\n\n";
    cout << "  Opcion: ";
    cin >> opcion;
    
    if (opcion == 0) {
        return;
    }
    
    if (opcion == 1) {
        cout << "\n  Ingrese DNI (0 para cancelar): ";
        cin >> dni;
        if (dni == 0) return;
        pos = archivo.buscarPorDni(dni);
    } else if (opcion == 2) {
        cout << "\n  Ingrese Numero de Socio (0 para cancelar): ";
        cin >> numSocio;
        if (numSocio == 0) return;
        pos = archivo.buscarPorNumero(numSocio);
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Opcion invalida." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Socio no encontrado." << endl;
    } else {
        Socio s = archivo.leer(pos);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [ENCONTRADO]\n\n";
        rlutil::setColor(rlutil::WHITE);
        cout << "  Socio #" << s.getNumeroSocio() << endl;
        cout << "  DNI: " << s.getDni() << endl;
        cout << "  Nombre: " << s.getNombre() << " " << s.getApellido() << endl;
        cout << "  Telefono: " << s.getTelefono() << endl;
        cout << "  Email: " << s.getEmail() << endl;
        Fecha f = s.getFechaNacimiento();
        cout << "  Fecha Nac: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void modificarSocio() {
    ArchivoSocio archivo;
    int dni, pos;
    char telefono[20], email[50], confirma;
    
    rlutil::cls();
    mostrarEncabezado("MODIFICAR SOCIO", rlutil::YELLOW);
    
    cout << "  Ingrese DNI del socio (0 para cancelar): ";
    cin >> dni;
    
    if (dni == 0) {
        return;
    }
    
    pos = archivo.buscarPorDni(dni);
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Socio no encontrado." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Socio s = archivo.leer(pos);
    
    cout << "\n  Socio encontrado: " << s.getNombre() << " " << s.getApellido() << "\n\n";
    cout << "  Telefono actual: " << s.getTelefono() << endl;
    cout << "  Nuevo telefono: ";
    cin.ignore();
    cin.getline(telefono, 20);
    s.setTelefono(telefono);
    
    cout << "\n  Email actual: " << s.getEmail() << endl;
    cout << "  Nuevo email: ";
    cin.getline(email, 50);
    s.setEmail(email);
    
    cout << "\n  Confirmar modificacion? (S/N): ";
    cin >> confirma;
    
    if (confirma != 'S' && confirma != 's') {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.modificar(s, pos)) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [EXITO] Socio modificado correctamente!" << endl;
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se pudo modificar el socio." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void eliminarSocio() {
    ArchivoSocio archivo;
    int dni, pos;
    char confirma;
    
    rlutil::cls();
    mostrarEncabezado("ELIMINAR SOCIO", rlutil::LIGHTRED);
    
    cout << "  Ingrese DNI del socio (0 para cancelar): ";
    cin >> dni;
    
    if (dni == 0) {
        return;
    }
    
    pos = archivo.buscarPorDni(dni);
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Socio no encontrado." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Socio s = archivo.leer(pos);
    
    cout << "\n  Socio: " << s.getNombre() << " " << s.getApellido() << endl;
    cout << "  DNI: " << s.getDni() << "\n\n";
    
    rlutil::setColor(rlutil::YELLOW);
    cout << "  Esta seguro de eliminar este socio? (S/N): ";
    rlutil::setColor(rlutil::WHITE);
    cin >> confirma;
    
    if (confirma == 'S' || confirma == 's') {
        s.setEliminado(true);
        if (archivo.modificar(s, pos)) {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "\n  [EXITO] Socio eliminado correctamente!" << endl;
        } else {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\n  [ERROR] No se pudo eliminar el socio." << endl;
        }
    } else {
        cout << "\n  Operacion cancelada." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
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
        cout << "[3] Buscar Cancha" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[4] Modificar Datos de Cancha" << endl;
        
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "  " << char(16) << " ";
        rlutil::setColor(rlutil::WHITE);
        cout << "[5] Cambiar Disponibilidad" << endl;
        
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