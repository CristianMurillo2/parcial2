#include "estacion.h"
#include "linea.h"
#include "metro.h"
metro::metro() {
    numlineas=0;
    lineas = new linea*[numLineas];
}

void metro::agregarLinea(std::string nombreLinea, std::string tipoTransporte)
{
    linea* nuevaLinea = new linea(nombreLinea, tipoTransporte);

    if (primeraLinea == nullptr) {
        primeraLinea = nuevaLinea;
    } else {
        linea* temp = primeraLinea;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevaLinea;
    }
}

void metro::eliminarLinea(std::string nombreLinea)
{
    linea* actual = primeraLinea;
    linea* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->nombre == nombreLinea) {
            if (anterior == nullptr) {
                primeraLinea = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            std::cout << "Se ha eliminado la línea: " << nombreLinea << std::endl;
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    std::cout << "No se encontró la línea: " << nombreLinea << std::endl;
}

int metro::cantidadLineas()
{
    int count = 0;
    linea* temp = primeraLinea;
    while (temp != nullptr) {
        count++;
        temp = temp->siguiente;
    }
    return count;
}

int metro::contarEstacionesRedMetroExtendido(const metro &redMetro)
{
    const char** estacionesUnicas = new const char*[1000];
    int numEstacionesUnicas = 0;

    linea* lineaActual = redMetro.primeraLinea;
    while (lineaActual != nullptr) {
        for (int i = 0; i < lineaActual->numEstaciones; ++i) {
            const char* nombreEstacion = lineaActual->estaciones[i].getnombre();
            bool encontrada = false;
            for (int j = 0; j < numEstacionesUnicas; ++j) {
                if (strcmp(estacionesUnicas[j], nombreEstacion) == 0) {
                    encontrada = true;
                    break;
                }
            }
            if (!encontrada) {
                estacionesUnicas[numEstacionesUnicas++] = nombreEstacion;
            }
        }
        lineaActual = lineaActual->siguiente;
    }

    delete[] estacionesUnicas;
    return numEstacionesUnicas;
}

bool metro::estacionPerteneceALineaExtendido(const char *nombreEstacion, const linea &linea, const metro &redMetro)
{
    for (int i = 0; i < linea.numEstaciones; ++i) {
        if (strcmp(linea.estaciones[i].getnombre(), nombreEstacion) == 0) {
            return true;
        }
    }
    linea* lineaActual = redMetro.primeraLinea;
    while (lineaActual != nullptr) {
        if (strcmp(lineaActual->nombre, linea.nombre) != 0) {
            for (int i = 0; i < lineaActual->numEstaciones; ++i) {
                if (strcmp(lineaActual->estaciones[i].getnombre(), nombreEstacion) == 0) {
                    return true;
                }
            }
        }
        lineaActual = lineaActual->siguiente;
    }

    return false;
}

int metro::calcularTiempoViaje(const std::string &nombreLinea, const std::string &nombreEstacionOrigen, const char &nombreEstacionDestino)
{
    estacion* estacionActual = primeraEstacion;
    while (estacionActual != nullptr && strcmp((*estacionActual).getnombre(), nombreEstacionOrigen) != 0) {
        estacionActual = (*estacionActual).siguiente;
    }

    if (estacionActual == nullptr) {
        std::cout << "La estacion de origen no se encuentra en esta linea." << std::endl;
        return -1;
    }
    int tiempoTotal = 0;
    while (estacionActual != nullptr && strcmp((*estacionActual).getnombre(), nombreEstacionDestino) != 0) {
        tiempoTotal += (*estacionActual).getTiempoSiguiente();
        estacionActual = (*estacionActual).siguiente;
    }

    if (estacionActual == nullptr) {
        std::cout << "La estacion de destino no se encuentra en esta linea." << std::endl;
        return -1;
    }

    return tiempoTotal;
}

