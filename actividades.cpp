#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "Actividad.h"
#include "ArchivoActividad.h"
#include "menu.h"
using namespace std;

void agregarActividad() {
    ArchivoActividad archivo;
    Actividad actividad;
    int id, dia, mes, anio;
    char nombre[50], responsable[50], confirma;
    float arancel;
    
    rlutil::cls();
    mostrarEncabezado("AGREGAR NUEVA ACTIVIDAD", rlutil::LIGHTGREEN);
    
    int nuevoId = archivo.contarRegistros() + 1;
    actividad.setNumeroActividad(nuevoId);
    
    cout << "  ID Actividad: " << nuevoId << " (autoasignado)\n\n";
    
    cout << "  Nombre de la actividad: ";
    cin.ignore();
    cin.getline(nombre, 50);
    actividad.setNombre(nombre);
    
    cout << "  Responsable: ";
    cin.getline(responsable, 50);
    actividad.setResponsable(responsable);
    
    cout << "  Arancel mensual: $";
    cin >> arancel;
    actividad.setArancel(arancel);
    
    cout << "\n  Fecha de inicio:\n";
    cout << "    Dia: ";
    cin >> dia;
    cout << "    Mes: ";
    cin >> mes;
    cout << "    Anio: ";
    cin >> anio;
    
    Fecha fechaInicio(dia, mes, anio);
    actividad.setFechaInicio(fechaInicio);
    actividad.setActiva(true);
    
    cout << "\n  Confirmar guardado? (S/N): ";
    cin >> confirma;
    
    if (confirma != 'S' && confirma != 's') {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.guardar(actividad)) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [EXITO] Actividad agregada correctamente!" << endl;
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se pudo guardar la actividad." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void listarActividades() {
    ArchivoActividad archivo;
    int total = archivo.contarRegistros();
    int activas = 0;
    
    rlutil::cls();
    mostrarEncabezado("LISTADO DE ACTIVIDADES", rlutil::LIGHTCYAN);
    
    if (total == 0) {
        cout << "  No hay actividades registradas.\n";
        rlutil::anykey();
        return;
    }
    
    // Contar actividades activas
    for (int i = 0; i < total; i++) {
        Actividad a = archivo.leer(i);
        if (a.getActiva()) {
            activas++;
        }
    }
    
    if (activas == 0) {
        cout << "  No hay actividades activas.\n";
        rlutil::anykey();
        return;
    }
    
    cout << "  Total de actividades activas: " << activas << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Actividad a = archivo.leer(i);
        if (a.getActiva()) {
            cout << "  " << char(254) << " Actividad #" << a.getNumeroActividad() << endl;
            cout << "    Nombre: " << a.getNombre() << endl;
            cout << "    Responsable: " << a.getResponsable() << endl;
            cout << "    Arancel: $" << a.getArancel() << endl;
            Fecha f = a.getFechaInicio();
            cout << "    Fecha Inicio: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
            cout << endl;
        }
    }
    
    rlutil::anykey();
}

void buscarActividad() {
    ArchivoActividad archivo;
    int id, pos;
    
    rlutil::cls();
    mostrarEncabezado("BUSCAR ACTIVIDAD", rlutil::LIGHTMAGENTA);
    
    cout << "  Ingrese ID de actividad (0 para cancelar): ";
    cin >> id;
    
    if (id == 0) return;
    
    pos = -1;
    int total = archivo.contarRegistros();
    for (int i = 0; i < total; i++) {
        Actividad a = archivo.leer(i);
        if (a.getNumeroActividad() == id) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Actividad no encontrada." << endl;
    } else {
        Actividad a = archivo.leer(pos);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [ENCONTRADA]\n\n";
        rlutil::setColor(rlutil::WHITE);
        cout << "  Actividad #" << a.getNumeroActividad() << endl;
        cout << "  Nombre: " << a.getNombre() << endl;
        cout << "  Responsable: " << a.getResponsable() << endl;
        cout << "  Arancel: $" << a.getArancel() << endl;
        Fecha f = a.getFechaInicio();
        cout << "  Fecha Inicio: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
        cout << "  Estado: " << (a.getActiva() ? "Activa" : "Inactiva") << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void buscarActividadPorNombre() {
    ArchivoActividad archivo;
    char nombre[50];
    int total = archivo.contarRegistros();
    bool encontrado = false;
    
    rlutil::cls();
    mostrarEncabezado("BUSCAR ACTIVIDAD POR NOMBRE", rlutil::LIGHTMAGENTA);
    
    cout << "  Ingrese nombre de actividad a buscar: ";
    cin.ignore();
    cin.getline(nombre, 50);
    
    for (int i = 0; i < total; i++) {
        Actividad a = archivo.leer(i);
        if (a.getActiva() && strstr(a.getNombre(), nombre) != nullptr) {
            encontrado = true;
            cout << "\n  " << char(254) << " Actividad #" << a.getNumeroActividad() << endl;
            cout << "    Nombre: " << a.getNombre() << endl;
            cout << "    Responsable: " << a.getResponsable() << endl;
            cout << "    Arancel: $" << a.getArancel() << endl;
            Fecha f = a.getFechaInicio();
            cout << "    Fecha Inicio: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
            cout << endl;
        }
    }
    
    if (!encontrado) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se encontraron actividades con ese nombre." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void modificarActividad() {
    ArchivoActividad archivo;
    int id, pos;
    char responsable[50], confirma;
    float arancel;
    
    rlutil::cls();
    mostrarEncabezado("MODIFICAR ACTIVIDAD", rlutil::YELLOW);
    
    cout << "  Ingrese ID de actividad (0 para cancelar): ";
    cin >> id;
    
    if (id == 0) return;
    
    pos = -1;
    int total = archivo.contarRegistros();
    for (int i = 0; i < total; i++) {
        Actividad a = archivo.leer(i);
        if (a.getNumeroActividad() == id) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Actividad no encontrada." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Actividad a = archivo.leer(pos);
    
    cout << "\n  Actividad: " << a.getNombre() << "\n\n";
    cout << "  Responsable actual: " << a.getResponsable() << endl;
    cout << "  Nuevo responsable: ";
    cin.ignore();
    cin.getline(responsable, 50);
    a.setResponsable(responsable);
    
    cout << "\n  Arancel actual: $" << a.getArancel() << endl;
    cout << "  Nuevo arancel: $";
    cin >> arancel;
    a.setArancel(arancel);
    
    cout << "\n  Confirmar modificacion? (S/N): ";
    cin >> confirma;
    
    if (confirma != 'S' && confirma != 's') {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.modificar(a, pos)) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [EXITO] Actividad modificada correctamente!" << endl;
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se pudo modificar la actividad." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void desactivarActividad() {
    ArchivoActividad archivo;
    int id, pos;
    char confirma;
    
    rlutil::cls();
    mostrarEncabezado("DESACTIVAR ACTIVIDAD", rlutil::LIGHTRED);
    
    cout << "  Ingrese ID de actividad (0 para cancelar): ";
    cin >> id;
    
    if (id == 0) return;
    
    pos = -1;
    int total = archivo.contarRegistros();
    for (int i = 0; i < total; i++) {
        Actividad a = archivo.leer(i);
        if (a.getNumeroActividad() == id) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Actividad no encontrada." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Actividad a = archivo.leer(pos);
    
    cout << "\n  Actividad: " << a.getNombre() << endl;
    cout << "  Responsable: " << a.getResponsable() << "\n\n";
    
    rlutil::setColor(rlutil::YELLOW);
    cout << "  Esta seguro de desactivar esta actividad? (S/N): ";
    rlutil::setColor(rlutil::WHITE);
    cin >> confirma;
    
    if (confirma == 'S' || confirma == 's') {
        a.setActiva(false);
        if (archivo.modificar(a, pos)) {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "\n  [EXITO] Actividad desactivada correctamente!" << endl;
        } else {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\n  [ERROR] No se pudo desactivar la actividad." << endl;
        }
    } else {
        cout << "\n  Operacion cancelada." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}