#include <iostream>
#include "rlutil.h"
#include "Inscripcion.h"
#include "ArchivoInscripcion.h"
#include "ArchivoSocio.h"
#include "ArchivoActividad.h"
#include "menu.h"
using namespace std;

void nuevaInscripcion() {
    ArchivoInscripcion archivo;
    ArchivoSocio archivoSocio;
    ArchivoActividad archivoActividad;
    Inscripcion inscripcion;
    int dni, idActividad, dia, mes, anio, posSocio, posActividad;
    char confirma;
    
    rlutil::cls();
    mostrarEncabezado("NUEVA INSCRIPCION", rlutil::LIGHTGREEN);
    
    cout << "  DNI del socio: ";
    cin >> dni;
    
    posSocio = archivoSocio.buscarPorDni(dni);
    if (posSocio == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Socio no encontrado." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Socio s = archivoSocio.leer(posSocio);
    cout << "  Socio: " << s.getNombre() << " " << s.getApellido() << "\n\n";
    
    cout << "  ID de la actividad: ";
    cin >> idActividad;
    
    posActividad = -1;
    int totalActividades = archivoActividad.contarRegistros();
    for (int i = 0; i < totalActividades; i++) {
        Actividad a = archivoActividad.leer(i);
        if (a.getNumeroActividad() == idActividad) {
            posActividad = i;
            break;
        }
    }
    
    if (posActividad == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Actividad no encontrada." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Actividad a = archivoActividad.leer(posActividad);
    if (!a.getActiva()) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] La actividad no esta activa." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    cout << "  Actividad: " << a.getNombre() << "\n\n";
    
    inscripcion.setNumeroSocio(s.getNumeroSocio());
    inscripcion.setNumeroActividad(idActividad);
    
    cout << "  Fecha de inscripcion:\n";
    cout << "    Dia: ";
    cin >> dia;
    cout << "    Mes: ";
    cin >> mes;
    cout << "    Anio: ";
    cin >> anio;
    
    Fecha fechaInscripcion(dia, mes, anio);
    inscripcion.setFechaInscripcion(fechaInscripcion);
    
    cout << "\n  Confirmar inscripcion? (S/N): ";
    cin >> confirma;
    
    if (confirma != 'S' && confirma != 's') {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.guardar(inscripcion)) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [EXITO] Inscripcion registrada correctamente!" << endl;
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se pudo registrar la inscripcion." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void listarInscripciones() {
    ArchivoInscripcion archivo;
    int total = archivo.contarRegistros();
    
    rlutil::cls();
    mostrarEncabezado("LISTADO DE INSCRIPCIONES", rlutil::LIGHTCYAN);
    
    if (total == 0) {
        cout << "  No hay inscripciones registradas.\n";
        rlutil::anykey();
        return;
    }
    
    cout << "  Total de inscripciones: " << total << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Inscripcion ins = archivo.leer(i);
        cout << "  " << char(254) << " Inscripcion #" << (i+1) << endl;
        cout << "    Numero Socio: " << ins.getNumeroSocio() << endl;
        cout << "    Numero Actividad: " << ins.getNumeroActividad() << endl;
        Fecha f = ins.getFechaInscripcion();
        cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
        cout << endl;
    }
    
    rlutil::anykey();
}

void buscarInscripcionesPorSocio() {
    ArchivoInscripcion archivo;
    ArchivoSocio archivoSocio;
    int dni, total = archivo.contarRegistros();
    bool encontrado = false;
    
    rlutil::cls();
    mostrarEncabezado("INSCRIPCIONES POR SOCIO", rlutil::LIGHTMAGENTA);
    
    cout << "  Ingrese DNI del socio (0 para cancelar): ";
    cin >> dni;
    
    if (dni == 0) return;
    
    int pos = archivoSocio.buscarPorDni(dni);
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Socio no encontrado." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Socio s = archivoSocio.leer(pos);
    cout << "\n  Socio: " << s.getNombre() << " " << s.getApellido() << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Inscripcion ins = archivo.leer(i);
        if (ins.getNumeroSocio() == s.getNumeroSocio()) {
            encontrado = true;
            cout << "  " << char(254) << " Inscripcion #" << (i+1) << endl;
            cout << "    Numero Actividad: " << ins.getNumeroActividad() << endl;
            Fecha f = ins.getFechaInscripcion();
            cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
            cout << endl;
        }
    }
    
    if (!encontrado) {
        cout << "  No hay inscripciones para este socio.\n";
    }
    
    rlutil::anykey();
}

void buscarInscripcionesPorActividad() {
    ArchivoInscripcion archivo;
    ArchivoActividad archivoActividad;
    int idActividad, total = archivo.contarRegistros();
    bool encontrado = false;
    
    rlutil::cls();
    mostrarEncabezado("INSCRIPCIONES POR ACTIVIDAD", rlutil::LIGHTMAGENTA);
    
    cout << "  Ingrese ID de actividad (0 para cancelar): ";
    cin >> idActividad;
    
    if (idActividad == 0) return;
    
    int pos = -1;
    int totalActividades = archivoActividad.contarRegistros();
    for (int i = 0; i < totalActividades; i++) {
        Actividad a = archivoActividad.leer(i);
        if (a.getNumeroActividad() == idActividad) {
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
    
    Actividad a = archivoActividad.leer(pos);
    cout << "\n  Actividad: " << a.getNombre() << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Inscripcion ins = archivo.leer(i);
        if (ins.getNumeroActividad() == idActividad) {
            encontrado = true;
            cout << "  " << char(254) << " Inscripcion #" << (i+1) << endl;
            cout << "    Numero Socio: " << ins.getNumeroSocio() << endl;
            Fecha f = ins.getFechaInscripcion();
            cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
            cout << endl;
        }
    }
    
    if (!encontrado) {
        cout << "  No hay inscripciones para esta actividad.\n";
    }
    
    rlutil::anykey();
}

void cancelarInscripcion() {
    ArchivoInscripcion archivo;
    int numeroSocio, numeroActividad;
    char confirma;
    
    rlutil::cls();
    mostrarEncabezado("CANCELAR INSCRIPCION", rlutil::LIGHTRED);
    
    cout << "  Ingrese numero de socio (0 para cancelar): ";
    cin >> numeroSocio;
    
    if (numeroSocio == 0) return;
    
    cout << "  Ingrese numero de actividad: ";
    cin >> numeroActividad;
    
    int total = archivo.contarRegistros();
    bool encontrado = false;
    
    for (int i = 0; i < total; i++) {
        Inscripcion ins = archivo.leer(i);
        if (ins.getNumeroSocio() == numeroSocio && ins.getNumeroActividad() == numeroActividad) {
            encontrado = true;
            cout << "\n  Inscripcion encontrada:" << endl;
            cout << "  Numero Socio: " << ins.getNumeroSocio() << endl;
            cout << "  Numero Actividad: " << ins.getNumeroActividad() << endl;
            Fecha f = ins.getFechaInscripcion();
            cout << "  Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << "\n\n";
            
            rlutil::setColor(rlutil::YELLOW);
            cout << "  Esta seguro de cancelar esta inscripcion? (S/N): ";
            rlutil::setColor(rlutil::WHITE);
            cin >> confirma;
            
            if (confirma == 'S' || confirma == 's') {
                rlutil::setColor(rlutil::LIGHTGREEN);
                cout << "\n  [EXITO] Inscripcion cancelada correctamente!" << endl;
            } else {
                cout << "\n  Operacion cancelada." << endl;
            }
            break;
        }
    }
    
    if (!encontrado) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Inscripcion no encontrada." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}