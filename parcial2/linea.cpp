#include "linea.h"

linea::linea() {}

linea::linea(int capacidadinicial): tamano(0), capacidad(capacidadinicial);{
    estaciones= new estacion[capacidad];
}

linea::~linea(){
    delete[] estaciones;
}

void linea::agregar_estacion(const char *nombre)
{

}
