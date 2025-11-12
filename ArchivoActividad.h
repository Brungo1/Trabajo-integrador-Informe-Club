#ifndef ARCHIVOACTIVIDAD_H
#define ARCHIVOACTIVIDAD_H
#include <cstdio>
#include <cstring>
#include "Actividad.h"

class ArchivoActividad {
private:
    char _nombreArchivo[30];

public:
    ArchivoActividad(const char* nombre = "actividades.dat") {
        strcpy(_nombreArchivo, nombre);
    }

    bool guardar(Actividad actividad) {
        FILE* p = fopen(_nombreArchivo, "ab");
        if (p == NULL) return false;
        bool ok = fwrite(&actividad, sizeof(Actividad), 1, p) == 1;
        fclose(p);
        return ok;
    }

    Actividad leer(int pos) {
        Actividad actividad;
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return actividad;
        fseek(p, pos * sizeof(Actividad), SEEK_SET);
        fread(&actividad, sizeof(Actividad), 1, p);
        fclose(p);
        return actividad;
    }

    int contarRegistros() {
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return 0;
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Actividad);
        fclose(p);
        return cant;
    }

    bool modificar(Actividad actividad, int pos) {
        FILE* p = fopen(_nombreArchivo, "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Actividad), SEEK_SET);
        bool ok = fwrite(&actividad, sizeof(Actividad), 1, p) == 1;
        fclose(p);
        return ok;
    }
};

#endif
