#include <iostream>
#include "rlutil.h"
#include "Pago.h"
#include "ArchivoPago.h"
#include "ArchivoSocio.h"
#include "menu.h"
using namespace std;

void registrarPago() {
    ArchivoPago archivo;
    ArchivoSocio archivoSocio;
    Pago pago;
    int dni, dia, mes, anio, pos, numeroSocio;
    char concepto[100], confirma;
    float monto;
    
    rlutil::cls();
    mostrarEncabezado("REGISTRAR NUEVO PAGO", rlutil::LIGHTGREEN);
    
    int nuevoId = archivo.contarRegistros() + 1;
    pago.setNumeroPago(nuevoId);
    
    cout << "  ID Pago: " << nuevoId << " (autoasignado)\n\n";
    
    cout << "  DNI del socio: ";
    cin >> dni;
    
    pos = archivoSocio.buscarPorDni(dni);
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Socio no encontrado." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Socio s = archivoSocio.leer(pos);
    cout << "  Socio: " << s.getNombre() << " " << s.getApellido() << "\n\n";
    
    pago.setNumeroSocio(s.getNumeroSocio());
    
    cout << "  Concepto del pago: ";
    cin.ignore();
    cin.getline(concepto, 100);
    pago.setConcepto(concepto);
    
    cout << "  Monto: $";
    cin >> monto;
    pago.setMonto(monto);
    
    cout << "\n  Fecha del pago:\n";
    cout << "    Dia: ";
    cin >> dia;
    cout << "    Mes: ";
    cin >> mes;
    cout << "    Anio: ";
    cin >> anio;
    
    Fecha fechaPago(dia, mes, anio);
    pago.setFechaPago(fechaPago);
    pago.setProcesado(true);
    
    cout << "\n  Confirmar registro? (S/N): ";
    cin >> confirma;
    
    if (confirma != 'S' && confirma != 's') {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.guardar(pago)) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [EXITO] Pago registrado correctamente!" << endl;
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se pudo registrar el pago." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void listarPagos() {
    ArchivoPago archivo;
    int total = archivo.contarRegistros();
    
    rlutil::cls();
    mostrarEncabezado("LISTADO DE PAGOS", rlutil::LIGHTCYAN);
    
    if (total == 0) {
        cout << "  No hay pagos registrados.\n";
        rlutil::anykey();
        return;
    }
    
    cout << "  Total de pagos: " << total << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Pago p = archivo.leer(i);
        cout << "  " << char(254) << " Pago #" << p.getNumeroPago() << endl;
        cout << "    Numero Socio: " << p.getNumeroSocio() << endl;
        cout << "    Concepto: " << p.getConcepto() << endl;
        cout << "    Monto: $" << p.getMonto() << endl;
        Fecha f = p.getFechaPago();
        cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
        cout << "    Estado: " << (p.getProcesado() ? "Procesado" : "Pendiente") << endl;
        cout << endl;
    }
    
    rlutil::anykey();
}

void buscarPagosPorSocio() {
    ArchivoPago archivo;
    ArchivoSocio archivoSocio;
    int dni, total = archivo.contarRegistros();
    bool encontrado = false;
    
    rlutil::cls();
    mostrarEncabezado("BUSCAR PAGOS POR SOCIO", rlutil::LIGHTMAGENTA);
    
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
        Pago p = archivo.leer(i);
        if (p.getNumeroSocio() == s.getNumeroSocio()) {
            encontrado = true;
            cout << "  " << char(254) << " Pago #" << p.getNumeroPago() << endl;
            cout << "    Concepto: " << p.getConcepto() << endl;
            cout << "    Monto: $" << p.getMonto() << endl;
            Fecha f = p.getFechaPago();
            cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
            cout << "    Estado: " << (p.getProcesado() ? "Procesado" : "Pendiente") << endl;
            cout << endl;
        }
    }
    
    if (!encontrado) {
        cout << "  No hay pagos registrados para este socio.\n";
    }
    
    rlutil::anykey();
}

void modificarEstadoPago() {
    ArchivoPago archivo;
    int id, pos;
    char confirma;
    
    rlutil::cls();
    mostrarEncabezado("MODIFICAR ESTADO DE PAGO", rlutil::YELLOW);
    
    cout << "  Ingrese ID del pago (0 para cancelar): ";
    cin >> id;
    
    if (id == 0) return;
    
    pos = -1;
    int total = archivo.contarRegistros();
    for (int i = 0; i < total; i++) {
        Pago p = archivo.leer(i);
        if (p.getNumeroPago() == id) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Pago no encontrado." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Pago p = archivo.leer(pos);
    
    cout << "\n  Pago #" << p.getNumeroPago() << endl;
    cout << "  Concepto: " << p.getConcepto() << endl;
    cout << "  Monto: $" << p.getMonto() << endl;
    cout << "  Estado actual: " << (p.getProcesado() ? "Procesado" : "Pendiente") << "\n\n";
    
    rlutil::setColor(rlutil::YELLOW);
    cout << "  Cambiar estado? (S/N): ";
    rlutil::setColor(rlutil::WHITE);
    cin >> confirma;
    
    if (confirma == 'S' || confirma == 's') {
        p.setProcesado(!p.getProcesado());
        if (archivo.modificar(p, pos)) {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "\n  [EXITO] Estado modificado correctamente!" << endl;
            cout << "  Nuevo estado: " << (p.getProcesado() ? "Procesado" : "Pendiente") << endl;
        } else {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\n  [ERROR] No se pudo modificar el estado." << endl;
        }
    } else {
        cout << "\n  Operacion cancelada." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void reportePagos() {
    ArchivoPago archivo;
    int total = archivo.contarRegistros();
    int procesados = 0, pendientes = 0;
    float totalProcesado = 0, totalPendiente = 0;
    
    rlutil::cls();
    mostrarEncabezado("REPORTE DE PAGOS", rlutil::LIGHTCYAN);
    
    if (total == 0) {
        cout << "  No hay pagos registrados.\n";
        rlutil::anykey();
        return;
    }
    
    for (int i = 0; i < total; i++) {
        Pago p = archivo.leer(i);
        if (p.getProcesado()) {
            procesados++;
            totalProcesado += p.getMonto();
        } else {
            pendientes++;
            totalPendiente += p.getMonto();
        }
    }
    
    cout << "  " << char(254) << " RESUMEN GENERAL\n\n";
    cout << "    Total de pagos: " << total << endl;
    cout << "    Pagos procesados: " << procesados << endl;
    cout << "    Pagos pendientes: " << pendientes << "\n\n";
    
    cout << "  " << char(254) << " MONTOS\n\n";
    cout << "    Total procesado: $" << totalProcesado << endl;
    cout << "    Total pendiente: $" << totalPendiente << endl;
    cout << "    Total general: $" << (totalProcesado + totalPendiente) << "\n\n";
    
    if (total > 0) {
        cout << "  " << char(254) << " ESTADISTICAS\n\n";
        cout << "    % Procesados: " << (procesados * 100.0 / total) << "%" << endl;
        cout << "    % Pendientes: " << (pendientes * 100.0 / total) << "%" << endl;
        cout << "    Promedio por pago: $" << ((totalProcesado + totalPendiente) / total) << endl;
    }
    
    rlutil::anykey();
}