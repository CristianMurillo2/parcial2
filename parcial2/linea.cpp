#include "linea.h"
Linea::linea(): tamano(0), capacidad(50){
    int i=0;
    while(nombre[i]!='\0' &&i<sizeof(this->nombre)-1){
        this->nombre[i]=nombre[i];
        i++;
    }
    this->nombre[i]='\0';
    estaciones=new estacion*[capacidad_estaciones];
}

Linea::~linea(){
    delete[] estaciones;
}

void Linea::agregar_estacion(estacion *estacion, int tiempo_ante,int tiempo_siguiente,int posicion)
{
    while(posicion<0 || posicion>numestaciones){
        std::cout<<"posicion no valida agrege una valida"<<std::endl;
        std::cin>>posicion;
    }
    if(tamano>=capacidad_estaciones){
        capacidad_estaciones++;
        estacion **nueva_lista=new estacion*[capacidad_estaciones];
        int *nuevo_tiempo_ant=new int[capacidad_estaciones];
        int *nuevo_tiempo_sig=new int[capacidad_estaciones];
        for(int i=0;i<tamano; i++){
            nueva_estaciones[i]=estaciones[i];
            nuevo_tiempo_ant[i]=tiempo_ant[i];
            nuevo_tiempo_sig[i]=tiempo_sig[i];
        }
        delete[] estaciones;
        delete[] tiempo_ant;
        delete[] tiempo_sig;
        estaciones=nueva_lista;
        tiempo_ant=nuevo_tiempo_ant;
        tiempo_sig=nuevo_tiempo_sig;
    }
    for(int i=tamano;i>posicion;i--){
        estaciones[i]=estaciones[i-1];
        tiempo_ant[i]=tiempo_ant[i-1];
        tiempo_sig[i]=tiempo_sig[i-1];
    }
    estaciones[posicion]=estacion;
    tiempo_ant[posicion]=tiempo_ante;
    tiempo_sig[posicion]=tiempo_siguiente;
    numestaciones++;
    if(posicion==0){
        tiempo_sig[0]=tiempo_ante;
    }
    else if(posicion==numestaciones-1){
        tiempo_sig[numestaciones-1]=tiempo_siguiente;
    }
    else{
        tiempo_ant[posicion-1]=tiempo_ante;
        tiempo_sig[posicion-1]=tiempo_siguiente;
    }
}

void Linea::eliminar_estacion(int posicion)
{
    while(posicion<0 || posicion>numestaciones){
        std::cout<<"posicion no valida agrege una valida"<<std::endl;
        std::cin>>posicion;
    }
    delete estaciones[posicion];
    estacion *nueva_estaciones= new estacion[nueva_capacidad];
    int *nuevo_tiempo_ant=new int[nueva_capacidad];
    int *nuevo_tiempo_sig=new int[nueva_capacidad];
    for(int i=0;i<numestaciones-1;i++){
            nuevo_tiempo_ant[i]=tiempo_ant[i+1];
            nuevo_tiempo_sig[i]=tiempo_sig[i+1];
            nueva_estaciones[i]=estaciones[i+1];
    }
    numestaciones--;
    if(posicion>0){
        tiempo_sig[posicion-1]=tiempo_sig[posicion];
    }
    if(posicion<numestaciones){
        tiempo_ant[posicion-1]=tiempo_ant[posicion+1];
    }
}

void Linea::cambiar_tiempo(int posicion,int nuevo_tiempo_ant,int nuevo_tiempo_sig)
{
    while(posicion<0||posicion>numestaciones){
        std::cout<<"posicion no valida agrege una valida"<<std::endl;
        std::cin>>posicion;
    }
    tiempo_ant[posicion]=nuevo_tiempo_ant;
    tiempo_sig[posicion]=nuevo_tiempo_sig;
}

