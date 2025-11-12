#ifndef FECHA_H
#define FECHA_H
#include <cstdio>
#pragma warning(disable: 4996)

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

    bool escribirDisco(int pos) {
        FILE* p = fopen("fechas.dat", "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Fecha), SEEK_SET);
        bool ok = fwrite(this, sizeof(Fecha), 1, p) == 1;
        fclose(p);
        return ok;
    }

    bool leerDisco(int pos) {
        FILE* p = fopen("fechas.dat", "rb");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Fecha), SEEK_SET);
        bool ok = fread(this, sizeof(Fecha), 1, p) == 1;
        fclose(p);
        return ok;
    }
};

#endif
