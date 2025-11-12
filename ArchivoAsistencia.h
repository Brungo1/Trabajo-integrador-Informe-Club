#ifndef ARCHIVOASISTENCIA_H
#define ARCHIVOASISTENCIA_H
#include <cstdio>
#include <cstring>
#include "Asistencia.h"

class ArchivoAsistencia {
private:
    char _nombreArchivo[30];

public:
    ArchivoAsistencia(const char* nombre = "asistencias.dat") {
        strcpy(_nombreArchivo, nombre);
    }

    bool guardar(Asistencia asistencia) {
        FILE* p = fopen(_nombreArchivo, "ab");
        if (p == NULL) return false;
        bool ok = fwrite(&asistencia, sizeof(Asistencia), 1, p) == 1;
        fclose(p);
        return ok;
    }

    Asistencia leer(int pos) {
        Asistencia asistencia;
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return asistencia;
        fseek(p, pos * sizeof(Asistencia), SEEK_SET);
        fread(&asistencia, sizeof(Asistencia), 1, p);
        fclose(p);
        return asistencia;
    }

    int contarRegistros() {
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return 0;
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Asistencia);
        fclose(p);
        return cant;
    }

    bool modificar(Asistencia asistencia, int pos) {
        FILE* p = fopen(_nombreArchivo, "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Asistencia), SEEK_SET);
        bool ok = fwrite(&asistencia, sizeof(Asistencia), 1, p) == 1;
        fclose(p);
        return ok;
    }
};

#endif
