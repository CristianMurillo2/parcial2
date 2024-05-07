#include "estacion.h"
#include <cstring>
#include <string>

estacion::estacion(const char *nombre, int tiempo_siguiente, int tiempo_anterior) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
    this->tiempo_anterior = tiempo_anterior;
    this->tiempo_siguiente = tiempo_siguiente;
}

estacion::estacion(const estacion &other) {
    this->nombre = new char[strlen(other.nombre) + 1];
    strcpy(this->nombre, other.nombre);
    this->tiempo_anterior = other.tiempo_anterior;
    this->tiempo_siguiente = other.tiempo_siguiente;
}

estacion& estacion::operator=(const estacion &other) {
    if (this != &other) {
        delete[] this->nombre;
        this->nombre = new char[strlen(other.nombre) + 1];
        strcpy(this->nombre, other.nombre);
        this->tiempo_anterior = other.tiempo_anterior;
        this->tiempo_siguiente = other.tiempo_siguiente;
    }
    return *this;
}

estacion::~estacion() {
    delete[] nombre;
}

const char* estacion::getnombre() {
    return nombre;
}

std::string estacion::get_nombre_str() {
    return std::string(nombre);
}

int estacion::get_tiempo_siguiente() {
    return tiempo_siguiente;
}

int estacion::get_tiempo_anterior() {
    return tiempo_anterior;
}

void estacion::set_tiempo_anterior(int indice) {
    tiempo_anterior = indice;
}

void estacion::set_tiempo_siguiente(int indice) {
    tiempo_siguiente = indice;
}
