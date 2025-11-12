#ifndef RESERVA_H
#define RESERVA_H
#include <cstring>
#include <cstdio>
#include "Fecha.h"
#pragma warning(disable: 4996)

class Reserva {
private:
    int _numeroReserva;
    int _numeroSocio;
    int _numeroCancha;
    Fecha _fechaReserva;
    int _horaInicio;
    int _horaFin;
    bool _confirmada;

public:
    Reserva() {
        _numeroReserva = 0;
        _numeroSocio = 0;
        _numeroCancha = 0;
        _horaInicio = 0;
        _horaFin = 0;
        _confirmada = false;
    }

    int getNumeroReserva() { return _numeroReserva; }
    int getNumeroSocio() { return _numeroSocio; }
    int getNumeroCancha() { return _numeroCancha; }
    Fecha getFechaReserva() { return _fechaReserva; }
    int getHoraInicio() { return _horaInicio; }
    int getHoraFin() { return _horaFin; }
    bool getConfirmada() { return _confirmada; }

    void setNumeroReserva(int num) { _numeroReserva = num; }
    void setNumeroSocio(int num) { _numeroSocio = num; }
    void setNumeroCancha(int num) { _numeroCancha = num; }
    void setFechaReserva(Fecha fecha) { _fechaReserva = fecha; }
    void setHoraInicio(int hora) { _horaInicio = hora; }
    void setHoraFin(int hora) { _horaFin = hora; }
    void setConfirmada(bool conf) { _confirmada = conf; }
};

#endif