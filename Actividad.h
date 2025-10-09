#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Fecha.h"

class Actividad {
private:
    int _numeroActividad;
    char _nombre[50];
    char _responsable[50];
    Fecha _fechaInicio;
    float _arancel;
    bool _activa;

public:
    Actividad() {
        _numeroActividad = 0;
        strcpy(_nombre, "");
        strcpy(_responsable, "");
        _arancel = 0.0f;
        _activa = true;
    }

    int getNumeroActividad() { return _numeroActividad; }
    const char* getNombre() { return _nombre; }
    const char* getResponsable() { return _responsable; }
    Fecha getFechaInicio() { return _fechaInicio; }
    float getArancel() { return _arancel; }
    bool getActiva() { return _activa; }

    void setNumeroActividad(int num) { _numeroActividad = num; }
    void setNombre(const char* nombre) { strcpy(_nombre, nombre); }
    void setResponsable(const char* resp) { strcpy(_responsable, resp); }
    void setFechaInicio(Fecha fecha) { _fechaInicio = fecha; }
    void setArancel(float arancel) { _arancel = arancel; }
    void setActiva(bool activa) { _activa = activa; }
};

#endif
