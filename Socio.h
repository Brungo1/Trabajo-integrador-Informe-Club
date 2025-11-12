#ifndef SOCIO_H
#define SOCIO_H
#include <cstring>
#include <cstdio>
#include "Fecha.h"
#pragma warning(disable: 4996)

class Socio {
private:
    int _numeroSocio;
    int _dni;
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _email[50];
    Fecha _fechaNacimiento;
    bool _eliminado;

public:
    Socio() {
        _numeroSocio = 0;
        _dni = 0;
        strcpy(_nombre, "");
        strcpy(_apellido, "");
        strcpy(_telefono, "");
        strcpy(_email, "");
        _eliminado = false;
    }

    int getNumeroSocio() { return _numeroSocio; }
    int getDni() { return _dni; }
    const char* getNombre() { return _nombre; }
    const char* getApellido() { return _apellido; }
    const char* getTelefono() { return _telefono; }
    const char* getEmail() { return _email; }
    Fecha getFechaNacimiento() { return _fechaNacimiento; }
    bool getEliminado() { return _eliminado; }

    void setNumeroSocio(int num) { _numeroSocio = num; }
    void setDni(int dni) { _dni = dni; }
    void setNombre(const char* nombre) { strcpy(_nombre, nombre); }
    void setApellido(const char* apellido) { strcpy(_apellido, apellido); }
    void setTelefono(const char* tel) { strcpy(_telefono, tel); }
    void setEmail(const char* email) { strcpy(_email, email); }
    void setFechaNacimiento(Fecha fecha) { _fechaNacimiento = fecha; }
    void setEliminado(bool eliminado) { _eliminado = eliminado; }
};

#endif
