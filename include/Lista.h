#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <sstream>
#include "Nodo.h"

using namespace std;

/**
 * Clase Lista
 * 
 * Lista enlazada utilizando punteros crudos
 * 
 */
 template <typename T> 
 class Lista {
   public:
      Lista();
      Lista(T elemento);
      virtual ~Lista();
      unsigned int get_tamanio() const;
      int get_primero() const;
      void agregar_primero(T);
      void agregar_final(T);
      void agregar_tras(T, T);
      void borrar(T);
      void mostrar() const;

   private:
      Nodo<T>* primero; // Puntero al primer Nodo de la Lista
};

#endif

/**
 * Constructor por omisión de la clase Lista
 * 
 * Construye una Lista vacía
 */
template <typename T> 
Lista<T>::Lista() {
    this->primero = nullptr;
}

/**
 * Constructor con parámetros de la clase Lista
 * 
 * Recibe un elemento el cual asigna al primer Nodo de la lista
 * 
 * @param elemento entero que va a contener el primer Nodo
 */
template <typename T>
Lista<T>::Lista(T elemento){
    primero = new Nodo(elemento);
}

/**
 * Destructor de la clase Lista
 * 
 * Itera sobre cada Nodo y los destruye
 */
template <typename T> 
Lista<T>::~Lista(){
    Nodo<T>* iter {primero};
    Nodo<T>* temp {nullptr};
    while(iter != nullptr){
        temp = iter;
        iter = iter->get_siguiente();
        delete temp;
    }
}

/**
 * Retorna el tamaño de la Lista
 * 
 * Itera sobre la Lista para contar los elementos y retornar este valor
 * 
 * @return tamaño de la Lista
 */
template <typename T> 
unsigned int Lista<T>::get_tamanio() const{
    unsigned int tamanio = 0;
    Nodo<T>* iter {primero};
    while(iter != nullptr){
        tamanio++;
        iter = iter->get_siguiente();
    }
    return tamanio;
}
/**
 * Retorna el elemento del primer Nodo
 * 
 * Retorna el entero contenido en el primer Nodo
 * 
 * @return entero del primer Nodo
 */
template <typename T> 
int Lista<T>::get_primero() const{
    int primer_elemento {0};
    if(primero){
        primer_elemento = primero->get_elemento();
    }
    return primer_elemento;
}

/**
 * Agrega un nuevo Nodo al inicio de la Lista
 * 
 * Crea un nuevo Nodo que se agrega al inicio de la Lista
 * 
 * @param elemento entero que va a contener el nuevo Nodo
 */
template <typename T> 
void Lista<T>::agregar_primero(T elemento){
    Nodo<T>* nuevo = new Nodo(elemento);
    nuevo->set_siguiente(primero);
    primero = nuevo;
}

/**
 * Agrega un nuevo Nodo al final
 * 
 * Itera sobre la Lista hasta que llega al último Nodo y agrega uno nuevo
 * 
 * @param elemento entero que va a contener el nuevo Nodo
 */
template <typename T> 
void Lista<T>::agregar_final(T elemento){
    if(primero != nullptr){
        Nodo<T>* iter {primero};
        while(iter->get_siguiente() != nullptr){
            iter = iter->get_siguiente();
        }
        iter->set_siguiente(new Nodo(elemento));
    } else {
        primero = new Nodo(elemento);
    }
}

/**
 * Agrega un nuevo Nodo en medio de la Lista
 * 
 * Busca el Nodo que contiene cierto elemento y agrega un nuevo Nodo luego de este
 * 
 * @param nuevo nuevo entero a agregar
 * @param anterior entero tras el que se debe agregar el nuevo valor
 */
template <typename T> 
void Lista<T>::agregar_tras(T nuevo, T anterior){
    Nodo<T>* iter {primero};
    bool agregado {false};
    while(iter != nullptr && !agregado){
        if(iter->get_elemento() == anterior){
            Nodo<T>* nodo {new Nodo(nuevo)};
            nodo->set_siguiente(iter->get_siguiente());
            iter->set_siguiente(nodo);
            agregado = true;
        } else {
            iter = iter->get_siguiente();
        }
    }
}

/**
 * Borra un Nodo de la Lista
 * 
 * Borra el primer Nodo de la lista que contiene un elemento en particular
 * 
 * @param elemento entero que determina al Nodo que se va a borrar
 */
template <typename T> 
void Lista<T>::borrar(T elemento){
    if(primero!=nullptr){
        if(primero->get_elemento()==elemento){
            Nodo<T>* temp {primero};
            primero = primero->get_siguiente();
            delete temp;
        } else{
            Nodo<T>* iter {primero};
            bool borrado {false};
            while(iter->get_siguiente() != nullptr && !borrado){
                if(iter->get_siguiente()->get_elemento() == elemento){
                    Nodo<T>* a_borrar {iter->get_siguiente()};
                    iter->set_siguiente(a_borrar->get_siguiente());
                    delete a_borrar;
                    borrado = true;
                } else {
                    iter = iter->get_siguiente();
                }
            }
        }
    }
}

/**
 * Imprime los elementos de la Lista
 * 
 * Itera sobre cada Nodo para extraer su elemento y los guarda en un flujo de strings
 */
template <typename T> 
void Lista<T>::mostrar() const{
    stringstream ss;
    Nodo<T>* iter {primero};
    while(iter != nullptr){
        ss << iter->get_elemento();
        if(iter->get_siguiente()!=nullptr){
            ss << ", ";
        }
        iter = iter->get_siguiente();
    }
    ss << endl;
    cout << ss.str();
}
