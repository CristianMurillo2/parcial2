#ifndef METRO_H
#define METRO_H

#include "linea.h"
#include <string>

class metro {
public:
    linea* primeraLinea;
    metro();
    ~metro();
    void agregarLinea(std::string nombreLinea, std::string tipoTransporte);
    void eliminarLinea(std::string nombreLinea);
    int cantidadLineas();
    int contarEstacionesRedMetroExtendido(const metro& redMetro);
    bool estacionPerteneceALineaExtendido(const char* nombreEstacion, const linea& linea, const metro& redMetro);
    int calcularTiempoViaje(const std::string& nombreLinea, const std::string& nombreEstacionOrigen, const std::string& nombreEstacionDestino);

};

#endif // METRO_H
