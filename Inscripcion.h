#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#include "Fecha.h"

class Inscripcion {
private:
    int _numeroActividad;
    int _numeroSocio;
    Fecha _fechaInscripcion;

public:
    Inscripcion() {
        _numeroActividad = 0;
        _numeroSocio = 0;
    }

    int getNumeroActividad() { return _numeroActividad; }
    int getNumeroSocio() { return _numeroSocio; }
    Fecha getFechaInscripcion() { return _fechaInscripcion; }

    void setNumeroActividad(int num) { _numeroActividad = num; }
    void setNumeroSocio(int num) { _numeroSocio = num; }
    void setFechaInscripcion(Fecha fecha) { _fechaInscripcion = fecha; }
};

#endif
