#include "estacion.h"
Estacion::estacion(const char *nombre):num_lineas(0),capacidad_lineas(2){
    int i=0;
    while(nombre[i]!='\0' && i<sizeof(this->nombre)-1){
        this->nombre[i]=nombre[i];
        i++;
    }
    this->nombre[i]='\0';
    estacion=new estacion*[capacidad_lineas];
    tiempo_sig=new int*[capacidad_lineas];
    tiempo_ant=new int*[capacidad_lineas]
}

Estacion::~Estacion(){
    delete[] nombre;
    delete[] tiempo_ant;
    delete[] tiempo_sig;
}

const char *Estacion::getnombre(){
    return nombre;
}

void Estacion::agregar_linea(Linea *linea, int tiempo_sigu, int tiempo_ante)
{
    if(num_lineas==capacidad_lineas){
        capacidad_lineas++;
        Linea **nueva_list=new linea*[capacidad_lineas];
        int *nuevo_tiempo_anterior=new int[capacidad_lineas];
        int *nuevo_tiempo_siguiente=new int[capacidad_lineas];
        for(int i=0;i<num_lineas; i++){
            nueva_list[i]=linea[i];
            nuevo_tiempo_anterior[i]=tiempo_ant[i];
            nuevo_tiempo_siguiente[i]=tiempo_sig[i];
        }
        delete[] estaciones;
        delete[] tiempo_ant;
        delete[] tiempo_sig;
        linea = nueva_list;
        tiempo_ant=nuevo_tiempo_ant;
        tiempo_sig=nuevo_tiempo_sig;
    }
    linea[posicion]=linea;
    tiempo_ant[num_lineas]=tiempo_ante;
    tiempo_sig[num_lineas]=tiempo_sigu;
    num_lineas++;
    }
void Estacion::set_tiempo_anterior(int indice)
{
    return tiempo_ant[indice];
}

void Estacion::set_tiempo_siguiente(int indice)
{
    return tiempo_sig[indice];
}

linea **estacion::getlinea()
{
    return lineas;
}

int estacion::get_num_lineas()
{
    return num_lineas;
}
