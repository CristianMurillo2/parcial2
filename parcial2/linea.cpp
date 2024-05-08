#include "linea.h"

linea::linea() : tamano(0), capacidad(2) {
    estaciones = new estacion[capacidad];
    tiempo_ant = new int[capacidad];
    tiempo_sig = new int[capacidad];
}

linea::~linea() {
    delete[] estaciones;
    delete[] tiempo_ant;
    delete[] tiempo_sig;
}

void linea::agregar_estacion(const char* nombre, int tiempo_anterior, int tiempo_siguiente, int posicion) {
    tamano++;
    while (posicion < 0 || posicion > tamano) {
        std::cout << "Posicion no válida, por favor ingrese una posición válida: ";
        std::cin >> posicion;
    }
    if (tamano >= capacidad) {
        int nueva_capacidad = capacidad + 1;
        estacion* nueva_estaciones = new estacion[nueva_capacidad];
        int* nuevo_tiempo_ant = new int[nueva_capacidad];
        for (int i = 0; i < tamano; i++) {
            nueva_estaciones[i] = estaciones[i];
            nuevo_tiempo_ant[i] = tiempo_ant[i];
        }
        delete[] estaciones;
        delete[] tiempo_ant;
        delete[] tiempo_sig;
        estaciones = nueva_estaciones;
        tiempo_ant = nuevo_tiempo_ant;
        capacidad = nueva_capacidad;
    }
    for (int i = tamano; i > posicion; i--) {
        estaciones[i] = estaciones[i - 1];
        tiempo_ant[i] = tiempo_ant[i - 1];
    }
    estaciones[posicion] = estacion(nombre, tiempo_anterior, tiempo_siguiente);
    tiempo_ant[posicion - 1] = tiempo_anterior;
    tiempo_sig[posicion] = tiempo_siguiente;
}

void linea::agregarEstacion_linea(estacion* estacion) {
    estacion** temp = new Estacion*[(numEstaciones) + 1];
    for (int i = 0; i < numEstaciones; ++i) {
        temp[i] = estaciones[i];
    }
    temp[numEstaciones] = estacion;
    delete[] estaciones;
    estaciones = temp;
    ++numEstaciones;
}

void linea::eliminarEstacion(std::string nombreEstacion) {
    Estacion** temp = new Estacion*[(numEstaciones) - 1];
    int j = 0;
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i]->nombre != nombreEstacion) {
            temp[j] = estaciones[i];
            j++;
        }
    }
    delete estaciones[j];
    delete[] estaciones;
    estaciones = temp;
    numEstaciones--;
}

void linea::cambiar_tiempo(int posicion, int nuevo_tiempo_ant, int nuevo_tiempo_sig)
{
    while(posicion<0||posicion>tamano){
        std::cout<<"posicion no valida agrege una valida"<<std::endl;
        std::cin>>posicion;
    }
    tiempo_ant[posicion-1]=nuevo_tiempo_ant;
    tiempo_ant[posicion]=nuevo_tiempo_sig;
}

void linea::eliminar_estacion(int posicion, int nuevo_tiempo_ant, int nuevo_tiempo_sig)
{
    capacidad=capacidad-1;
    while(posicion<0 || posicion>tamano){
        std::cout<<"posicion no valida agrege una valida"<<std::endl;
                    std::cin>>posicion;
    }
    delete[] estaciones[posicion];
    for(int i=posicion;i<tamano-1;i--){
        estaciones[i]=estaciones[i+1];
        tiempo_ant[i]=tiempo_ant[i+1];
    }
    estacion *nueva_estaciones=new estacion[capacidad];
    int *nuevo_tiempo_an=new int[capacidad];
    for(int i=0;i<posicion;i++){
        nueva_estaciones[i]=estaciones[i];
        nuevo_tiempo_an[i]=tiempo_ant[i];
    }
    for(int i=posicion;i<tamano-1;i++){
        nueva_estaciones[i]=estaciones[i+1];
        nuevo_tiempo_an[i]=tiempo_ant[i+1];
    }
    delete[] estaciones;
    delete[] tiempo_ant;
    estaciones = nueva_estaciones;
    tiempo_ant=nuevo_tiempo_ant;
    tamano--;
}

void linea::lineas(std::string nombre, std::string tipoTransporte) : nombre(nombre), tipoTransporte(tipoTransporte), numEstaciones(0){
    estaciones = new estacion*[numEstaciones];
}

int linea::cantidadEstaciones()
{
    return numEstaciones;
}


