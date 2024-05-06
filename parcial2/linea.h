#ifndef LINEA_H
#define LINEA_H
#include "estacion.h"
#include "metro.h"
#include <iostream>
class linea
{
private:
    int tamano,capacidad;
    std::string nombre;
    std::string tipoTransporte;
    linea* siguiente;
    int *tiempo_sig, *tiempo_ant;

public:
    estacion *estaciones;
    linea();
    ~linea();
    void agregar_estacion(const char *nombre,int tiempo_anterior,int tiempo_siguiente,int posicion);
    void cambiar_tiempo(int posicion,int nuevo_tiempo_ant,int nuevo_tiempo_sig);
    void eliminar_estacion(int posicion,int nuevo_tiempo_ant,int nuevo_tiempo_sig);
    linea(std::string nombre, std::string tipoTransporte):nombre(nombre),tipoTransporte(tipoTransporte),siguiente(nullptr){}
};

#endif // LINEA_H
