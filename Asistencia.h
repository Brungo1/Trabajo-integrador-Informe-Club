#ifndef ASISTENCIA_H
#define ASISTENCIA_H
#include <cstdio>
#include "Fecha.h"

class Asistencia {
private:
    int _numeroSocio;
    int _numeroActividad;
    Fecha _fechaAsistencia;
    bool _presente;

public:
    Asistencia() {
        _numeroSocio = 0;
        _numeroActividad = 0;
        _presente = false;
    }

    int getNumeroSocio() { return _numeroSocio; }
    int getNumeroActividad() { return _numeroActividad; }
    Fecha getFechaAsistencia() { return _fechaAsistencia; }
    bool getPresente() { return _presente; }

    void setNumeroSocio(int num) { _numeroSocio = num; }
    void setNumeroActividad(int num) { _numeroActividad = num; }
    void setFechaAsistencia(Fecha fecha) { _fechaAsistencia = fecha; }
    void setPresente(bool presente) { _presente = presente; }
};

#endif