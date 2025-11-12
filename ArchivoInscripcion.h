#ifndef ARCHIVOINSCRIPCION_H
#define ARCHIVOINSCRIPCION_H
#include <cstdio>
#include <cstring>
#include "Inscripcion.h"

class ArchivoInscripcion {
private:
    char _nombreArchivo[30];

public:
    ArchivoInscripcion(const char* nombre = "inscripciones.dat") {
        strcpy(_nombreArchivo, nombre);
    }

    bool guardar(Inscripcion inscripcion) {
        FILE* p = fopen(_nombreArchivo, "ab");
        if (p == NULL) return false;
        bool ok = fwrite(&inscripcion, sizeof(Inscripcion), 1, p) == 1;
        fclose(p);
        return ok;
    }

    Inscripcion leer(int pos) {
        Inscripcion inscripcion;
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return inscripcion;
        fseek(p, pos * sizeof(Inscripcion), SEEK_SET);
        fread(&inscripcion, sizeof(Inscripcion), 1, p);
        fclose(p);
        return inscripcion;
    }

    int contarRegistros() {
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return 0;
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Inscripcion);
        fclose(p);
        return cant;
    }

    bool modificar(Inscripcion inscripcion, int pos) {
        FILE* p = fopen(_nombreArchivo, "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Inscripcion), SEEK_SET);
        bool ok = fwrite(&inscripcion, sizeof(Inscripcion), 1, p) == 1;
        fclose(p);
        return ok;
    }
};

#endif
