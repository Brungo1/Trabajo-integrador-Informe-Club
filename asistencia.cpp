#include <iostream>
#include "rlutil.h"
#include "Asistencia.h"
#include "ArchivoAsistencia.h"
#include "ArchivoSocio.h"
#include "ArchivoActividad.h"
#include "menu.h"
using namespace std;

void registrarAsistencia() {
    ArchivoAsistencia archivo;
    ArchivoSocio archivoSocio;
    ArchivoActividad archivoActividad;
    Asistencia asistencia;
    int dni, idActividad, dia, mes, anio, posSocio, posActividad;
    bool presente;
    char confirma, opcionPresente;
    
    rlutil::cls();
    mostrarEncabezado("REGISTRAR ASISTENCIA", rlutil::LIGHTGREEN);
    
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
    cout << "  Actividad: " << a.getNombre() << "\n\n";
    
    asistencia.setNumeroSocio(s.getNumeroSocio());
    asistencia.setNumeroActividad(idActividad);
    
    cout << "  Fecha de la asistencia:\n";
    cout << "    Dia: ";
    cin >> dia;
    cout << "    Mes: ";
    cin >> mes;
    cout << "    Anio: ";
    cin >> anio;
    
    Fecha fechaAsistencia(dia, mes, anio);
    asistencia.setFechaAsistencia(fechaAsistencia);
    
    cout << "\n  El socio estuvo presente? (S/N): ";
    cin >> opcionPresente;
    presente = (opcionPresente == 'S' || opcionPresente == 's');
    asistencia.setPresente(presente);
    
    cout << "\n  Confirmar registro? (S/N): ";
    cin >> confirma;
    
    if (confirma != 'S' && confirma != 's') {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.guardar(asistencia)) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [EXITO] Asistencia registrada correctamente!" << endl;
        cout << "  Estado: " << (presente ? "Presente" : "Ausente") << endl;
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se pudo registrar la asistencia." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void listarAsistencias() {
    ArchivoAsistencia archivo;
    int total = archivo.contarRegistros();
    
    rlutil::cls();
    mostrarEncabezado("LISTADO DE ASISTENCIAS", rlutil::LIGHTCYAN);
    
    if (total == 0) {
        cout << "  No hay asistencias registradas.\n";
        rlutil::anykey();
        return;
    }
    
    cout << "  Total de asistencias: " << total << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Asistencia a = archivo.leer(i);
        cout << "  " << char(254) << " Asistencia #" << (i+1) << endl;
        cout << "    Numero Socio: " << a.getNumeroSocio() << endl;
        cout << "    Numero Actividad: " << a.getNumeroActividad() << endl;
        Fecha f = a.getFechaAsistencia();
        cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
        cout << "    Estado: " << (a.getPresente() ? "Presente" : "Ausente") << endl;
        cout << endl;
    }
    
    rlutil::anykey();
}

void buscarAsistenciaPorSocio() {
    ArchivoAsistencia archivo;
    ArchivoSocio archivoSocio;
    int dni, total = archivo.contarRegistros();
    bool encontrado = false;
    int presentes = 0, ausentes = 0;
    
    rlutil::cls();
    mostrarEncabezado("ASISTENCIA POR SOCIO", rlutil::LIGHTMAGENTA);
    
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
        Asistencia a = archivo.leer(i);
        if (a.getNumeroSocio() == s.getNumeroSocio()) {
            encontrado = true;
            cout << "  " << char(254) << " Asistencia #" << (i+1) << endl;
            cout << "    Numero Actividad: " << a.getNumeroActividad() << endl;
            Fecha f = a.getFechaAsistencia();
            cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
            cout << "    Estado: " << (a.getPresente() ? "Presente" : "Ausente") << endl;
            cout << endl;
            
            if (a.getPresente()) presentes++;
            else ausentes++;
        }
    }
    
    if (!encontrado) {
        cout << "  No hay registros de asistencia para este socio.\n";
    } else {
        cout << "  " << char(254) << " RESUMEN:\n";
        cout << "    Presentes: " << presentes << endl;
        cout << "    Ausentes: " << ausentes << endl;
        cout << "    Total: " << (presentes + ausentes) << endl;
        if ((presentes + ausentes) > 0) {
            cout << "    % Asistencia: " << (presentes * 100.0 / (presentes + ausentes)) << "%" << endl;
        }
    }
    
    rlutil::anykey();
}

void buscarAsistenciaPorActividad() {
    ArchivoAsistencia archivo;
    ArchivoActividad archivoActividad;
    int idActividad, total = archivo.contarRegistros();
    bool encontrado = false;
    int presentes = 0, ausentes = 0;
    
    rlutil::cls();
    mostrarEncabezado("ASISTENCIA POR ACTIVIDAD", rlutil::LIGHTMAGENTA);
    
    cout << "  Ingrese ID de actividad (0 para cancelar): ";
    cin >> idActividad;
    
    if (idActividad == 0) return;
    
    int pos = -1;
    int totalActividades = archivoActividad.contarRegistros();
    for (int i = 0; i < totalActividades; i++) {
        Actividad act = archivoActividad.leer(i);
        if (act.getNumeroActividad() == idActividad) {
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
    
    Actividad act = archivoActividad.leer(pos);
    cout << "\n  Actividad: " << act.getNombre() << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Asistencia a = archivo.leer(i);
        if (a.getNumeroActividad() == idActividad) {
            encontrado = true;
            cout << "  " << char(254) << " Asistencia #" << (i+1) << endl;
            cout << "    Numero Socio: " << a.getNumeroSocio() << endl;
            Fecha f = a.getFechaAsistencia();
            cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
            cout << "    Estado: " << (a.getPresente() ? "Presente" : "Ausente") << endl;
            cout << endl;
            
            if (a.getPresente()) presentes++;
            else ausentes++;
        }
    }
    
    if (!encontrado) {
        cout << "  No hay registros de asistencia para esta actividad.\n";
    } else {
        cout << "  " << char(254) << " RESUMEN:\n";
        cout << "    Presentes: " << presentes << endl;
        cout << "    Ausentes: " << ausentes << endl;
        cout << "    Total: " << (presentes + ausentes) << endl;
        if ((presentes + ausentes) > 0) {
            cout << "    % Asistencia: " << (presentes * 100.0 / (presentes + ausentes)) << "%" << endl;
        }
    }
    
    rlutil::anykey();
}

void reporteAsistencia() {
    ArchivoAsistencia archivo;
    int total = archivo.contarRegistros();
    int presentes = 0, ausentes = 0;
    
    rlutil::cls();
    mostrarEncabezado("REPORTE DE ASISTENCIA", rlutil::LIGHTCYAN);
    
    if (total == 0) {
        cout << "  No hay registros de asistencia.\n";
        rlutil::anykey();
        return;
    }
    
    for (int i = 0; i < total; i++) {
        Asistencia a = archivo.leer(i);
        if (a.getPresente()) {
            presentes++;
        } else {
            ausentes++;
        }
    }
    
    cout << "  " << char(254) << " RESUMEN GENERAL\n\n";
    cout << "    Total de registros: " << total << endl;
    cout << "    Presentes: " << presentes << endl;
    cout << "    Ausentes: " << ausentes << "\n\n";
    
    cout << "  " << char(254) << " ESTADISTICAS\n\n";
    cout << "    % Presentes: " << (presentes * 100.0 / total) << "%" << endl;
    cout << "    % Ausentes: " << (ausentes * 100.0 / total) << "%" << endl;
    
    if (presentes > ausentes) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n    Estado: Buena asistencia general" << endl;
    } else {
        rlutil::setColor(rlutil::YELLOW);
        cout << "\n    Estado: Revisar asistencia" << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}