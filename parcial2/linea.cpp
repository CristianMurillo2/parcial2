#include "linea.h"
linea::linea(): tamano(0), capacidad(2){

    estaciones= new estacion[capacidad];
    tiempo_ant= new int[capacidad];
    tiempo_sig=new int[capacidad];
}

linea::~linea(){
    delete[] estaciones;
    delete[] tiempo_ant;
    delete[] tiempo_sig;
}

void linea::agregar_estacion(const char *nombre, int tiempo_ante, int tiempo_siguiente, int posicion)
{
    tamano++;
    while(posicion<0 || posicion>tamano){
        std::cout<<"posicion no valida agrege una valida"<<std::endl;
        std::cin>>posicion;
    }
    if(tamano>=capacidad){
        int nueva_capacidad = capacidad+1;
        estacion *nueva_estaciones= new estacion[nueva_capacidad];
        int *nuevo_tiempo_ant=new int[nueva_capacidad];
        int *nuevo_tiempo_sig=new int[nueva_capacidad];
        for(int i=0;i<tamano; i++){
            nueva_estaciones[i]=estaciones[i];
            nuevo_tiempo_ant[i]=tiempo_ant[i];
            nuevo_tiempo_sig[i]=tiempo_sig[i];
        }
        delete[] estaciones;
        delete[] tiempo_ant;
        delete[] tiempo_sig;
        estaciones = nueva_estaciones;
        tiempo_ant=nuevo_tiempo_ant;
        tiempo_sig=nuevo_tiempo_sig;
        capacidad=nueva_capacidad;
    }
    for(int i=tamano;i>posicion;i--){
        estaciones[i]=estaciones[i-1];
        tiempo_ant[i]=tiempo_ant[i-1];
        tiempo_sig[i]=tiempo_sig[i-1];
    }
    estaciones[posicion]=estacion(nombre);
    tiempo_ant[posicion]=tiempo_ante;
    tiempo_sig[posicion]=tiempo_siguiente;
}

