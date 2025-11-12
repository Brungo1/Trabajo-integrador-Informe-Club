#ifndef ARCHIVORESERVA_H
#define ARCHIVORESERVA_H
#include <cstdio>
#include <cstring>
#include "Reserva.h"

class ArchivoReserva {
private:
    char _nombreArchivo[30];

public:
    ArchivoReserva(const char* nombre = "reservas.dat") {
        strcpy(_nombreArchivo, nombre);
    }

    bool guardar(Reserva reserva) {
        FILE* p = fopen(_nombreArchivo, "ab");
        if (p == NULL) return false;
        bool ok = fwrite(&reserva, sizeof(Reserva), 1, p) == 1;
        fclose(p);
        return ok;
    }

    Reserva leer(int pos) {
        Reserva reserva;
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return reserva;
        fseek(p, pos * sizeof(Reserva), SEEK_SET);
        fread(&reserva, sizeof(Reserva), 1, p);
        fclose(p);
        return reserva;
    }

    int contarRegistros() {
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return 0;
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Reserva);
        fclose(p);
        return cant;
    }

    bool modificar(Reserva reserva, int pos) {
        FILE* p = fopen(_nombreArchivo, "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Reserva), SEEK_SET);
        bool ok = fwrite(&reserva, sizeof(Reserva), 1, p) == 1;
        fclose(p);
        return ok;
    }
};

#endif
