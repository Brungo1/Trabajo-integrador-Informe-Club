#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int _dia, _mes, _anio;

public:
    Fecha(int dia = 1, int mes = 1, int anio = 2000) {
        _dia = dia;
        _mes = mes;
        _anio = anio;
    }

    int getDia() { return _dia; }
    int getMes() { return _mes; }
    int getAnio() { return _anio; }

    void setDia(int dia) { _dia = dia; }
    void setMes(int mes) { _mes = mes; }
    void setAnio(int anio) { _anio = anio; }
};

#endif
