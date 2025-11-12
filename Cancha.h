#ifndef CANCHA_H
#define CANCHA_H
#include <cstring>
#include <cstdio>
#pragma warning(disable: 4996)

class Cancha {
private:
    int _numeroCancha;
    char _nombre[50];
    char _tipoDeporte[30];
    int _capacidad;
    float _tarifaHora;
    bool _disponible;

public:
    Cancha() {
        _numeroCancha = 0;
        strcpy(_nombre, "");
        strcpy(_tipoDeporte, "");
        _capacidad = 0;
        _tarifaHora = 0.0f;
        _disponible = true;
    }

    int getNumeroCancha() { return _numeroCancha; }
    const char* getNombre() { return _nombre; }
    const char* getTipoDeporte() { return _tipoDeporte; }
    int getCapacidad() { return _capacidad; }
    float getTarifaHora() { return _tarifaHora; }
    bool getDisponible() { return _disponible; }

    void setNumeroCancha(int num) { _numeroCancha = num; }
    void setNombre(const char* nombre) { strcpy(_nombre, nombre); }
    void setTipoDeporte(const char* tipo) { strcpy(_tipoDeporte, tipo); }
    void setCapacidad(int cap) { _capacidad = cap; }
    void setTarifaHora(float tarifa) { _tarifaHora = tarifa; }
    void setDisponible(bool disp) { _disponible = disp; }
};

#endif