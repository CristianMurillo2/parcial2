#ifndef LINEA_H
#define LINEA_H
#include "estacion.h"
#include <iostream>
class linea
{
private:
    estacion *estaciones;
    int tamano,capacidad;
    int *tiempo_sig, *tiempo_ant;

public:
    linea();
    ~linea();
    void agregar_estacion(const char *nombre,int tiempo_anterior,int tiempo_siguiente,int posicion);
    void eliminar_estacion(int posicion);
    void cambiar_tiempo(int posicion,int nuevo_tiempo_ant,int nuevo_tiempo_sig);
};

#endif // LINEA_H
