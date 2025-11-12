#ifndef ARCHIVOPAGO_H
#define ARCHIVOPAGO_H
#include <cstdio>
#include <cstring>
#include "Pago.h"

class ArchivoPago {
private:
    char _nombreArchivo[30];

public:
    ArchivoPago(const char* nombre = "pagos.dat") {
        strcpy(_nombreArchivo, nombre);
    }

    bool guardar(Pago pago) {
        FILE* p = fopen(_nombreArchivo, "ab");
        if (p == NULL) return false;
        bool ok = fwrite(&pago, sizeof(Pago), 1, p) == 1;
        fclose(p);
        return ok;
    }

    Pago leer(int pos) {
        Pago pago;
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return pago;
        fseek(p, pos * sizeof(Pago), SEEK_SET);
        fread(&pago, sizeof(Pago), 1, p);
        fclose(p);
        return pago;
    }

    int contarRegistros() {
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return 0;
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Pago);
        fclose(p);
        return cant;
    }

    bool modificar(Pago pago, int pos) {
        FILE* p = fopen(_nombreArchivo, "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Pago), SEEK_SET);
        bool ok = fwrite(&pago, sizeof(Pago), 1, p) == 1;
        fclose(p);
        return ok;
    }
};

#endif
