#include "estacion.h"
#include "linea.h"
#include "metro.h"
estacion::estacion(const char *nombre, int tiempor_siguiente, int tiempo_anterior){
    this->nombre= new char[strlen(nombre)+1];
    strcpy(this->nombre,nombre);
    this->tiempo_anterior=tiempo_anterior;
    this->tiempo_siguiente=tiempor_siguiente;
}

estacion::~estacion(){
    delete[] nombre;
}

const char *estacion::getnombre(){
    return nombre;
}

int estacion::get_tiempo_siguiente(){
    return tiempo_siguiente;
}

int estacion::get_tiempo_anterior(){
    return tiempo_anterior;
}

void estacion::set_tiempo_anterior(int indice)
{
    tiempo_anterior=indice;
}

void estacion::set_tiempo_siguiente(int indice)
{
    tiempor_siguiente=indice;
}
