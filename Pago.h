#ifndef PAGO_H
#define PAGO_H
#include <cstring>
#include "Fecha.h"
#pragma warning(disable: 4996)

class Pago {
private:
    int _numeroPago;
    int _numeroSocio;
    float _monto;
    char _concepto[50];
    Fecha _fechaPago;
    bool _procesado;

public:
    Pago() {
        _numeroPago = 0;
        _numeroSocio = 0;
        _monto = 0.0f;
        strcpy(_concepto, "");
        _procesado = false;
    }

    int getNumeroPago() { return _numeroPago; }
    int getNumeroSocio() { return _numeroSocio; }
    float getMonto() { return _monto; }
    const char* getConcepto() { return _concepto; }
    Fecha getFechaPago() { return _fechaPago; }
    bool getProcesado() { return _procesado; }

    void setNumeroPago(int num) { _numeroPago = num; }
    void setNumeroSocio(int num) { _numeroSocio = num; }
    void setMonto(float monto) { _monto = monto; }
    void setConcepto(const char* concepto) { strcpy(_concepto, concepto); }
    void setFechaPago(Fecha fecha) { _fechaPago = fecha; }
    void setProcesado(bool procesado) { _procesado = procesado; }
};

#endif