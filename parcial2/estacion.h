#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>
#include <cstring>
class estacion
{
private:
    int tiempo_anterior,tiempo_siguiente;
    bool es_transferencia;
    char *nombre;
public:
    estacion(const char *nombre,int tiempor_siguiente,int tiempo_anterior);
    ~estacion();
const char *getnombre();
int get_tiempo_siguiente();
int get_tiempo_anterior();
void set_tiempo_anterior(int indice);
void set_tiempo_siguiente(int indice);

};

#endif // ESTACION_H
