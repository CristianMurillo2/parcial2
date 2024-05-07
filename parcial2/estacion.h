#ifndef ESTACION_H
#define ESTACION_H

#include <iostream>
#include <string>
#include "linea.h"
#include "metro.h"

class estacion {
private:
    int tiempo_anterior, tiempo_siguiente;
    bool es_transferencia;
    char *nombre_;

public:
    std::string Nombre;

    estacion(const char *nombre, int tiempo_siguiente, int tiempo_anterior);
    ~estacion();

    const char* getnombre();
    int get_tiempo_siguiente();
    int get_tiempo_anterior();
    void set_tiempo_anterior(int indice);
    void set_tiempo_siguiente(int indice);
};

#endif // ESTACION_H
