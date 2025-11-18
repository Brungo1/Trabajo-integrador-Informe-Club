#include <iostream>
#include <cstring>
#include "rlutil.h"
#include "Socio.h"
#include "ArchivoSocio.h"
#include "menu.h"
using namespace std;

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
    int opcion, dni, pos;
    char nombre[30], apellido[30];
    bool encontrado = false;
    
    rlutil::cls();
    mostrarEncabezado("BUSCAR SOCIO", rlutil::LIGHTMAGENTA);
    
    cout << "  [1] Buscar por DNI\n";
    cout << "  [2] Buscar por Nombre\n";
    cout << "  [3] Buscar por Apellido\n";
    cout << "  [0] Cancelar\n\n";
    cout << "  Opcion: ";
    cin >> opcion;
    
    if (opcion == 0) return;
    
    if (opcion == 1) {
        cout << "\n  Ingrese DNI (0 para cancelar): ";
        cin >> dni;
        if (dni == 0) return;
        pos = archivo.buscarPorDni(dni);
        if (pos != -1) {
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
        } else {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\n  [ERROR] Socio no encontrado." << endl;
        }
    } else if (opcion == 2) {
        cout << "\n  Ingrese nombre a buscar: ";
        cin.ignore();
        cin.getline(nombre, 30);
        int total = archivo.contarRegistros();
        for (int i = 0; i < total; i++) {
            Socio s = archivo.leer(i);
            if (!s.getEliminado() && strstr(s.getNombre(), nombre) != nullptr) {
                if (!encontrado) {
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    cout << "\n  [ENCONTRADOS]\n";
                    rlutil::setColor(rlutil::WHITE);
                    encontrado = true;
                }
                cout << "\n  " << char(254) << " Socio #" << s.getNumeroSocio() << endl;
                cout << "    DNI: " << s.getDni() << endl;
                cout << "    Nombre: " << s.getNombre() << " " << s.getApellido() << endl;
                cout << "    Telefono: " << s.getTelefono() << endl;
                cout << "    Email: " << s.getEmail() << endl;
            }
        }
        if (!encontrado) {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\n  [ERROR] No se encontraron socios con ese nombre." << endl;
        }
    } else if (opcion == 3) {
        cout << "\n  Ingrese apellido a buscar: ";
        cin.ignore();
        cin.getline(apellido, 30);
        int total = archivo.contarRegistros();
        for (int i = 0; i < total; i++) {
            Socio s = archivo.leer(i);
            if (!s.getEliminado() && strstr(s.getApellido(), apellido) != nullptr) {
                if (!encontrado) {
                    rlutil::setColor(rlutil::LIGHTGREEN);
                    cout << "\n  [ENCONTRADOS]\n";
                    rlutil::setColor(rlutil::WHITE);
                    encontrado = true;
                }
                cout << "\n  " << char(254) << " Socio #" << s.getNumeroSocio() << endl;
                cout << "    DNI: " << s.getDni() << endl;
                cout << "    Nombre: " << s.getNombre() << " " << s.getApellido() << endl;
                cout << "    Telefono: " << s.getTelefono() << endl;
                cout << "    Email: " << s.getEmail() << endl;
            }
        }
        if (!encontrado) {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\n  [ERROR] No se encontraron socios con ese apellido." << endl;
        }
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Opcion invalida." << endl;
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