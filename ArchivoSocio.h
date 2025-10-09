#ifndef ARCHIVOSOCIO_H
#define ARCHIVOSOCIO_H
#include <cstdio>
#include "Socio.h"

class ArchivoSocio {
private:
    char _nombreArchivo[30];

public:
    ArchivoSocio(const char* nombre = "socios.dat") {
        strcpy(_nombreArchivo, nombre);
    }

    bool guardar(Socio socio) {
        FILE* p = fopen(_nombreArchivo, "ab");
        if (p == NULL) return false;
        bool ok = fwrite(&socio, sizeof(Socio), 1, p) == 1;
        fclose(p);
        return ok;
    }

    Socio leer(int pos) {
        Socio socio;
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return socio;
        fseek(p, pos * sizeof(Socio), SEEK_SET);
        fread(&socio, sizeof(Socio), 1, p);
        fclose(p);
        return socio;
    }

    int contarRegistros() {
        FILE* p = fopen(_nombreArchivo, "rb");
        if (p == NULL) return 0;
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Socio);
        fclose(p);
        return cant;
    }

    bool modificar(Socio socio, int pos) {
        FILE* p = fopen(_nombreArchivo, "rb+");
        if (p == NULL) return false;
        fseek(p, pos * sizeof(Socio), SEEK_SET);
        bool ok = fwrite(&socio, sizeof(Socio), 1, p) == 1;
        fclose(p);
        return ok;
    }

    int buscarPorNumero(int numeroSocio) {
        int cant = contarRegistros();
        for (int i = 0; i < cant; i++) {
            Socio socio = leer(i);
            if (socio.getNumeroSocio() == numeroSocio && !socio.getEliminado()) {
                return i;
            }
        }
        return -1;
    }

    int buscarPorDni(int dni) {
        int cant = contarRegistros();
        for (int i = 0; i < cant; i++) {
            Socio socio = leer(i);
            if (socio.getDni() == dni && !socio.getEliminado()) {
                return i;
            }
        }
        return -1;
    }
};

#endif
