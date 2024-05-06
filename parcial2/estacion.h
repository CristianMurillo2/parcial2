#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>
#include "Linea.h"
class Estacion
{
private:
    int tiempo_anterior,tiempo_siguiente,num_lineas,capacidad_lineas;
    int *tiempo_sig, *tiempo_ant;
    bool es_transferencia;
    char *nombre;
    Linea **lineas;
public:
    Estacion(const char *nombre);
    ~Estacion();
const char *getnombre();
int get_tiempo_siguiente();
void agregar_linea(Linea *linea, int tiempo_sigu, int tiempo_ante);
int get_tiempo_anterior();
void set_tiempo_anterior(int indice);
void set_tiempo_siguiente(int indice);
Linea **getlinea();
int get_num_lineas();
};

#endif // ESTACION_H
