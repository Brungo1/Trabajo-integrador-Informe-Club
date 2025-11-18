#include <iostream>
#include "rlutil.h"
#include "Reserva.h"
#include "ArchivoReserva.h"
#include "ArchivoSocio.h"
#include "ArchivoCancha.h"
#include "menu.h"
using namespace std;

void nuevaReserva() {
    ArchivoReserva archivo;
    ArchivoSocio archivoSocio;
    ArchivoCancha archivoCancha;
    Reserva reserva;
    int dni, idCancha, dia, mes, anio, hora, posSocio, posCancha;
    char confirma;
    
    rlutil::cls();
    mostrarEncabezado("NUEVA RESERVA", rlutil::LIGHTGREEN);
    
    int nuevoId = archivo.contarRegistros() + 1;
    reserva.setNumeroReserva(nuevoId);
    
    cout << "  ID Reserva: " << nuevoId << " (autoasignado)\n\n";
    
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
    
    cout << "  ID de la cancha: ";
    cin >> idCancha;
    
    posCancha = -1;
    int totalCanchas = archivoCancha.contarRegistros();
    for (int i = 0; i < totalCanchas; i++) {
        Cancha c = archivoCancha.leer(i);
        if (c.getNumeroCancha() == idCancha) {
            posCancha = i;
            break;
        }
    }
    
    if (posCancha == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Cancha no encontrada." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Cancha c = archivoCancha.leer(posCancha);
    if (!c.getDisponible()) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] La cancha no esta disponible." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    cout << "  Cancha: " << c.getNombre() << " - $" << c.getTarifaHora() << "/hora\n\n";
    
    reserva.setNumeroSocio(s.getNumeroSocio());
    reserva.setNumeroCancha(idCancha);
    
    cout << "  Fecha de la reserva:\n";
    cout << "    Dia: ";
    cin >> dia;
    cout << "    Mes: ";
    cin >> mes;
    cout << "    Anio: ";
    cin >> anio;
    
    Fecha fechaReserva(dia, mes, anio);
    reserva.setFechaReserva(fechaReserva);
    
    cout << "\n  Hora de inicio (0-23): ";
    cin >> hora;
    reserva.setHoraInicio(hora);
    
    int horaFin;
    cout << "  Hora de finalizacion (" << (hora + 1) << "-23): ";
    cin >> horaFin;
    
    if (horaFin <= hora) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] La hora de finalizacion debe ser mayor a la de inicio." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    reserva.setHoraFin(horaFin);
    
    int horas = horaFin - hora;
    float costoTotal = horas * c.getTarifaHora();
    
    reserva.setConfirmada(true);
    
    cout << "\n  Confirmar reserva? (S/N): ";
    cin >> confirma;
    
    if (confirma != 'S' && confirma != 's') {
        cout << "\n  Operacion cancelada." << endl;
        rlutil::anykey();
        return;
    }
    
    if (archivo.guardar(reserva)) {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "\n  [EXITO] Reserva registrada correctamente!" << endl;
        cout << "  Duracion: " << horas << " hora(s)" << endl;
        cout << "  Costo total: $" << costoTotal << " (" << horas << " x $" << c.getTarifaHora() << ")" << endl;
    } else {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] No se pudo registrar la reserva." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}

void listarReservas() {
    ArchivoReserva archivo;
    int total = archivo.contarRegistros();
    
    rlutil::cls();
    mostrarEncabezado("LISTADO DE RESERVAS", rlutil::LIGHTCYAN);
    
    if (total == 0) {
        cout << "  No hay reservas registradas.\n";
        rlutil::anykey();
        return;
    }
    
    cout << "  Total de reservas: " << total << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Reserva r = archivo.leer(i);
        cout << "  " << char(254) << " Reserva #" << r.getNumeroReserva() << endl;
        cout << "    Numero Socio: " << r.getNumeroSocio() << endl;
        cout << "    Numero Cancha: " << r.getNumeroCancha() << endl;
        Fecha f = r.getFechaReserva();
        cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
        cout << "    Horario: " << r.getHoraInicio() << ":00 - " << r.getHoraFin() << ":00" << endl;
        cout << "    Estado: " << (r.getConfirmada() ? "Confirmada" : "Pendiente") << endl;
        cout << endl;
    }
    
    rlutil::anykey();
}

void buscarReservasPorSocio() {
    ArchivoReserva archivo;
    ArchivoSocio archivoSocio;
    int dni, total = archivo.contarRegistros();
    bool encontrado = false;
    
    rlutil::cls();
    mostrarEncabezado("RESERVAS POR SOCIO", rlutil::LIGHTMAGENTA);
    
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
        Reserva r = archivo.leer(i);
        if (r.getNumeroSocio() == s.getNumeroSocio()) {
            encontrado = true;
            cout << "  " << char(254) << " Reserva #" << r.getNumeroReserva() << endl;
            cout << "    Numero Cancha: " << r.getNumeroCancha() << endl;
            Fecha f = r.getFechaReserva();
            cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
            cout << "    Horario: " << r.getHoraInicio() << ":00 - " << r.getHoraFin() << ":00" << endl;
            cout << "    Estado: " << (r.getConfirmada() ? "Confirmada" : "Pendiente") << endl;
            cout << endl;
        }
    }
    
    if (!encontrado) {
        cout << "  No hay reservas para este socio.\n";
    }
    
    rlutil::anykey();
}

void buscarReservasPorCancha() {
    ArchivoReserva archivo;
    ArchivoCancha archivoCancha;
    int idCancha, total = archivo.contarRegistros();
    bool encontrado = false;
    
    rlutil::cls();
    mostrarEncabezado("RESERVAS POR CANCHA", rlutil::LIGHTMAGENTA);
    
    cout << "  Ingrese ID de cancha (0 para cancelar): ";
    cin >> idCancha;
    
    if (idCancha == 0) return;
    
    int pos = -1;
    int totalCanchas = archivoCancha.contarRegistros();
    for (int i = 0; i < totalCanchas; i++) {
        Cancha c = archivoCancha.leer(i);
        if (c.getNumeroCancha() == idCancha) {
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
    
    Cancha c = archivoCancha.leer(pos);
    cout << "\n  Cancha: " << c.getNombre() << "\n\n";
    
    for (int i = 0; i < total; i++) {
        Reserva r = archivo.leer(i);
        if (r.getNumeroCancha() == idCancha) {
            encontrado = true;
            cout << "  " << char(254) << " Reserva #" << r.getNumeroReserva() << endl;
            cout << "    Numero Socio: " << r.getNumeroSocio() << endl;
            Fecha f = r.getFechaReserva();
            cout << "    Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
            cout << "    Horario: " << r.getHoraInicio() << ":00 - " << r.getHoraFin() << ":00" << endl;
            cout << "    Estado: " << (r.getConfirmada() ? "Confirmada" : "Pendiente") << endl;
            cout << endl;
        }
    }
    
    if (!encontrado) {
        cout << "  No hay reservas para esta cancha.\n";
    }
    
    rlutil::anykey();
}

void cancelarReserva() {
    ArchivoReserva archivo;
    int id, pos;
    char confirma;
    
    rlutil::cls();
    mostrarEncabezado("CANCELAR RESERVA", rlutil::LIGHTRED);
    
    cout << "  Ingrese ID de reserva (0 para cancelar): ";
    cin >> id;
    
    if (id == 0) return;
    
    pos = -1;
    int total = archivo.contarRegistros();
    for (int i = 0; i < total; i++) {
        Reserva r = archivo.leer(i);
        if (r.getNumeroReserva() == id) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "\n  [ERROR] Reserva no encontrada." << endl;
        rlutil::setColor(rlutil::WHITE);
        rlutil::anykey();
        return;
    }
    
    Reserva r = archivo.leer(pos);
    
    cout << "\n  Reserva #" << r.getNumeroReserva() << endl;
    cout << "  Numero Socio: " << r.getNumeroSocio() << endl;
    cout << "  Numero Cancha: " << r.getNumeroCancha() << endl;
    Fecha f = r.getFechaReserva();
    cout << "  Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() << endl;
    cout << "  Horario: " << r.getHoraInicio() << ":00 - " << r.getHoraFin() << ":00\n\n";
    
    rlutil::setColor(rlutil::YELLOW);
    cout << "  Esta seguro de cancelar esta reserva? (S/N): ";
    rlutil::setColor(rlutil::WHITE);
    cin >> confirma;
    
    if (confirma == 'S' || confirma == 's') {
        r.setConfirmada(false);
        if (archivo.modificar(r, pos)) {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "\n  [EXITO] Reserva cancelada correctamente!" << endl;
        } else {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\n  [ERROR] No se pudo cancelar la reserva." << endl;
        }
    } else {
        cout << "\n  Operacion cancelada." << endl;
    }
    
    rlutil::setColor(rlutil::WHITE);
    rlutil::anykey();
}