#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#include <cstdio>
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

    bool escribirDisco(int pos) {
        FILE* p = fopen("inscripciones.dat", "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Inscripcion), SEEK_SET);
        bool ok = fwrite(this, sizeof(Inscripcion), 1, p) == 1;
        fclose(p);
        return ok;
    }

    bool leerDisco(int pos) {
        FILE* p = fopen("inscripciones.dat", "rb");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Inscripcion), SEEK_SET);
        bool ok = fread(this, sizeof(Inscripcion), 1, p) == 1;
        fclose(p);
        return ok;
    }
};

#endif
