#ifndef LINEA_H
#define LINEA_H
#include "Estacion.h"
#include <iostream>
class Linea
{
private:
    Estacion **estaciones;
    int capacidad_estaciones,numestaciones;
    char nombre;
    int *tiempo_sig, *tiempo_ant;
public:
    Linea(const char *nombre);
    ~Linea();
    void agregar_estacion(Estacion *estacion, int tiempo_ante,int tiempo_siguiente,int posicion);
    void eliminar_estacion(int posicion);
    void cambiar_tiempo(int posicion,int nuevo_tiempo_ant,int nuevo_tiempo_sig);
};

#endif // LINEA_H
