#ifndef LINEA_H
#define LINEA_H
#include "estacion.h"
#include "metro.h"
#include <iostream>
class linea
{
private:
    int tamano,capacidad;

    int *tiempo_sig, *tiempo_ant;

public:
    estacion *estaciones;
    std::string nombre;
    std::string tipoTransporte;
    int numEstaciones;
    linea* siguiente;
    linea();
    ~linea();
    void agregar_estacion(const char *nombre,int tiempo_anterior,int tiempo_siguiente,int posicion);
    void agregarEstacion_linea(estacion* estacion);
    void eliminarEstacion(std::string nombreEstacion);
    void cambiar_tiempo(int posicion,int nuevo_tiempo_ant,int nuevo_tiempo_sig);
    void eliminar_estacion(int posicion,int nuevo_tiempo_ant,int nuevo_tiempo_sig);
    void lineas(std::string nombre, std::string tipoTransporte);
    void con_linea(std::string nombre, std::string tipoTransporte):nombre(nombre),tipoTransporte(tipoTransporte),siguiente(nullptr){}
    int cantidadEstaciones();
};


#endif // LINEA_H
