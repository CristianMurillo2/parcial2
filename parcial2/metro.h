#ifndef METRO_H
#define METRO_H
#include "estacion.h"
#include "linea.h"
#include <string>
class metro
{
public:
    linea** lineas;
    int numLineas;
    metro() ;
    linea* primeraLinea;
    metro() : primeraLinea(nullptr) {}
    void agregarLinea(std::string nombreLinea, std::string tipoTransporte);
    void eliminarLinea(std::string nombreLinea);
    int cantidadLineas();
};

#endif // METRO_H
