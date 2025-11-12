#ifndef ARCHIVOCANCHA_H
#define ARCHIVOCANCHA_H
#include <cstdio>
#include <cstring>
#include "Cancha.h"

class ArchivoCancha {
private:
    char _nombreArchivo[30];

public:
    ArchivoCancha(const char* nombre = "canchas.dat") {
        strcpy(_nombreArchivo, nombre);
    }

    bool guardar(Cancha cancha) {
        FILE* p = fopen(_nombreArchivo, "ab");
        if (p == NULL) return false;
        bool ok = fwrite(&cancha, sizeof(Cancha), 1, p) == 1;
        fclose(p);
        return ok;
    }

    Cancha leer(int pos) {
        Cancha cancha;
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return cancha;
        fseek(p, pos * sizeof(Cancha), SEEK_SET);
        fread(&cancha, sizeof(Cancha), 1, p);
        fclose(p);
        return cancha;
    }

    int contarRegistros() {
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return 0;
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Cancha);
        fclose(p);
        return cant;
    }

    bool modificar(Cancha cancha, int pos) {
        FILE* p = fopen(_nombreArchivo, "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Cancha), SEEK_SET);
        bool ok = fwrite(&cancha, sizeof(Cancha), 1, p) == 1;
        fclose(p);
        return ok;
    }
};

#endif
