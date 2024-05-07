#include "estacion.h"
#include "linea.h"
#include "metro.h"
metro::metro() {
    numLineas=0;
    lineas = new Linea*[numLineas];
}

void metro::agregarLinea(std::string nombreLinea, std::string tipoTransporte)
{
    linea* nuevaLinea = new linea(nombreLinea, tipoTransporte);

    if (primeraLinea == nullptr) {
        primeraLinea = nuevaLinea;
    } else {
        Linea* temp = primeraLinea;
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

