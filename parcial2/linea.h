#ifndef LINEA_H
#define LINEA_H

#include "estacion.h"
#include <iostream>

class linea {
private:
    int tamano, capacidad;
    estacion* estaciones;
    int* tiempo_sig;
    int* tiempo_ant;

public:
    std::string nombre;
    std::string tipoTransporte;
    int numEstaciones;
    linea();
    ~linea();
    void agregar_estacion(const char* nombre, int tiempo_anterior, int tiempo_siguiente, int posicion);
    void agregarEstacion_linea(estacion* estacion);
    void eliminarEstacion(std::string nombreEstacion);
    void cambiar_tiempo(int posicion, int nuevo_tiempo_ant, int nuevo_tiempo_sig);
    void eliminar_estacion(int posicion, int nuevo_tiempo_ant, int nuevo_tiempo_sig);
    void lineas(std::string nombre, std::string tipoTransporte);
    int cantidadEstaciones();
};

#endif // LINEA_H
