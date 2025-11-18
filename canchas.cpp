#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "Cancha.h"
#include "ArchivoCancha.h"
#include "menu.h"
using namespace std;

void agregarCancha() {
    ArchivoCancha archivo;
    Cancha cancha;
    int id;
    char nombre[50], tipo[30], confirma;
    float tarifaHora;
    
    rlutil::cls();
    mostrarEncabezado("AGREGAR NUEVA CANCHA", rlutil::LIGHTGREEN);
    
    int nuevoId = archivo.contarRegistros() + 1;
    cancha.setNumeroCancha(nuevoId);
    
    cout << "  ID Cancha: " << nuevoId << " (autoasignado)\n\n";
    
    cout << "  Nombre de la cancha: ";
    cin.ignore();
    cin.getline(nombre, 50);
    cancha.setNombre(nombre);
    
    cout << "  Tipo de cancha: ";
    cin.getline(tipo, 30);
    cancha.setTipoDeporte(tipo);
    
    cout << "  Tarifa por hora: $";
    cin >> tarifaHora;
    cancha.setTarifaHora(tarifaHora);
    
    cancha.setDisponible(true);
    
    cout << "\n  Confirmar guardado? (S/N): ";
    cin >> confirma;
    
    if (confirma != 'S' && confirma != 's') {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.guardar(cancha)) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [EXITO] Cancha agregada correctamente!" << endl;
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se pudo guardar la cancha." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void listarCanchas() {
    ArchivoCancha archivo;
    int total = archivo.contarRegistros();
    
    rlutil::cls();
    mostrarEncabezado("LISTADO DE CANCHAS", rlutil::LIGHTCYAN);
    
    if (total == 0) {
        cout << "  No hay canchas registradas.\n";
        rlutil::anykey();
        return;
    }
    
    cout << "  Total de canchas: " << total << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Cancha c = archivo.leer(i);
        cout << "  " << char(254) << " Cancha #" << c.getNumeroCancha() << endl;
        cout << "    Nombre: " << c.getNombre() << endl;
        cout << "    Tipo: " << c.getTipoDeporte() << endl;
        cout << "    Tarifa/Hora: $" << c.getTarifaHora() << endl;
        cout << "    Estado: " << (c.getDisponible() ? "Disponible" : "No Disponible") << endl;
        cout << endl;
    }
    
    rlutil::anykey();
}

void buscarCancha() {
    ArchivoCancha archivo;
    int id, pos;
    
    rlutil::cls();
    mostrarEncabezado("BUSCAR CANCHA", rlutil::LIGHTMAGENTA);
    
    cout << "  Ingrese ID de cancha (0 para cancelar): ";
    cin >> id;
    
    if (id == 0) return;
    
    pos = -1;
    int total = archivo.contarRegistros();
    for (int i = 0; i < total; i++) {
        Cancha c = archivo.leer(i);
        if (c.getNumeroCancha() == id) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Cancha no encontrada." << endl;
    } else {
        Cancha c = archivo.leer(pos);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [ENCONTRADA]\n\n";
        rlutil::setColor(rlutil::WHITE);
        cout << "  Cancha #" << c.getNumeroCancha() << endl;
        cout << "  Nombre: " << c.getNombre() << endl;
        cout << "  Tipo: " << c.getTipoDeporte() << endl;
        cout << "  Tarifa/Hora: $" << c.getTarifaHora() << endl;
        cout << "  Estado: " << (c.getDisponible() ? "Disponible" : "No Disponible") << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void buscarCanchaPorTipo() {
    ArchivoCancha archivo;
    char tipo[30];
    int total = archivo.contarRegistros();
    bool encontrado = false;
    
    rlutil::cls();
    mostrarEncabezado("BUSCAR CANCHA POR TIPO", rlutil::LIGHTMAGENTA);
    
    cout << "  Ingrese tipo de cancha a buscar: ";
    cin.ignore();
    cin.getline(tipo, 30);
    
    for (int i = 0; i < total; i++) {
        Cancha c = archivo.leer(i);
        if (strstr(c.getTipoDeporte(), tipo) != nullptr) {
            encontrado = true;
            cout << "\n  " << char(254) << " Cancha #" << c.getNumeroCancha() << endl;
            cout << "    Nombre: " << c.getNombre() << endl;
            cout << "    Tipo: " << c.getTipoDeporte() << endl;
            cout << "    Tarifa/Hora: $" << c.getTarifaHora() << endl;
            cout << "    Estado: " << (c.getDisponible() ? "Disponible" : "No Disponible") << endl;
            cout << endl;
        }
    }
    
    if (!encontrado) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se encontraron canchas de ese tipo." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void modificarCancha() {
    ArchivoCancha archivo;
    int id, pos;
    char nombre[50], tipo[30], confirma;
    float tarifa;
    
    rlutil::cls();
    mostrarEncabezado("MODIFICAR CANCHA", rlutil::YELLOW);
    
    cout << "  Ingrese ID de cancha (0 para cancelar): ";
    cin >> id;
    
    if (id == 0) return;
    
    pos = -1;
    int total = archivo.contarRegistros();
    for (int i = 0; i < total; i++) {
        Cancha c = archivo.leer(i);
        if (c.getNumeroCancha() == id) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Cancha no encontrada." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Cancha c = archivo.leer(pos);
    
    cout << "\n  Cancha: " << c.getNombre() << "\n\n";
    cout << "  Nombre actual: " << c.getNombre() << endl;
    cout << "  Nuevo nombre: ";
    cin.ignore();
    cin.getline(nombre, 50);
    c.setNombre(nombre);
    
    cout << "\n  Tipo actual: " << c.getTipoDeporte() << endl;
    cout << "  Nuevo tipo: ";
    cin.getline(tipo, 30);
    c.setTipoDeporte(tipo);
    
    cout << "\n  Tarifa actual: $" << c.getTarifaHora() << endl;
    cout << "  Nueva tarifa: $";
    cin >> tarifa;
    c.setTarifaHora(tarifa);
    
    cout << "\n  Confirmar modificacion? (S/N): ";
    cin >> confirma;
    
    if (confirma != 'S' && confirma != 's') {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.modificar(c, pos)) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [EXITO] Cancha modificada correctamente!" << endl;
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se pudo modificar la cancha." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void cambiarDisponibilidad() {
    ArchivoCancha archivo;
    int id, pos;
    char confirma;
    
    rlutil::cls();
    mostrarEncabezado("CAMBIAR DISPONIBILIDAD", rlutil::YELLOW);
    
    cout << "  Ingrese ID de cancha (0 para cancelar): ";
    cin >> id;
    
    if (id == 0) return;
    
    pos = -1;
    int total = archivo.contarRegistros();
    for (int i = 0; i < total; i++) {
        Cancha c = archivo.leer(i);
        if (c.getNumeroCancha() == id) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Cancha no encontrada." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Cancha c = archivo.leer(pos);
    
    cout << "\n  Cancha: " << c.getNombre() << endl;
    cout << "  Estado actual: " << (c.getDisponible() ? "Disponible" : "No Disponible") << "\n\n";
    
    rlutil::setColor(rlutil::YELLOW);
    cout << "  Cambiar disponibilidad? (S/N): ";
    rlutil::setColor(rlutil::WHITE);
    cin >> confirma;
    
    if (confirma == 'S' || confirma == 's') {
        c.setDisponible(!c.getDisponible());
        if (archivo.modificar(c, pos)) {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "\n  [EXITO] Disponibilidad cambiada correctamente!" << endl;
            cout << "  Nuevo estado: " << (c.getDisponible() ? "Disponible" : "No Disponible") << endl;
        } else {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\n  [ERROR] No se pudo cambiar la disponibilidad." << endl;
        }
    } else {
        cout << "\n  Operacion cancelada." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}