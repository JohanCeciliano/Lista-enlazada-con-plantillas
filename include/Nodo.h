#ifndef NODO_H
#define NODO_H

#include<iostream>

using namespace std;
/**
 * Clase Nodo
 * 
 * Contiene un entero y un puntero al siguiente Nodo
 * 
 */
template <typename T> 
class Nodo {
   public:
      Nodo(T);
      virtual ~Nodo();
      void set_elemento(T);
      T get_elemento() const;
      void set_siguiente(Nodo<T>*);
      Nodo<T>* get_siguiente() const;

   private:
      T elemento; // Valor entero contenido en el Nodo
      Nodo<T>* siguiente; // Puntero al siguiente Nodo

};

#endif

/**
 * Constructor con parámetros de la clase Nodo
 * 
 * Inicializa un Nodo con un elemento
 */
template <typename T>
Nodo<T>::Nodo(T elemento){
    this->elemento = elemento;
    this->siguiente = nullptr;
}

/**
 * Destructor de la clase Nodo
 * 
 * Libera la memoria ocupada por un Nodo
 */
template <typename T>
Nodo<T>::~Nodo(){
    // La clase Lista es la que se debe encargar de llamar al destructor de cada Nodo
    cout << "Nodo " << this->elemento << " destruido" <<endl;
}

/**
 * Define el elemento de la instancia
 * 
 * Recibe un elemento por parámetro e iguala el elemento a este
 * 
 * @param elemento entero recibido
 */
template <typename T>
void Nodo<T>::set_elemento(T elemento){
    this->elemento = elemento;
}

/**
 * Retorna el elemento
 * 
 * Retorna el elemento de una instancia Nodo
 * 
 * @return entero
 */
template <typename T>
T Nodo<T>::get_elemento() const{
    return this->elemento;
}

/**
 * Define el siguiente Nodo
 * 
 * Recibe un puntero a Nodo por parámetro e iguala el siguiente a este
 * 
 * @param siguiente puntero al siguiente nodo
 */
template <typename T>
void Nodo<T>::set_siguiente(Nodo* siguiente){
    this->siguiente = siguiente;
}

/**
 * Retorna el siguiente Nodo
 * 
 * Retorna un puntero al siguiente Nodo
 * 
 * @return puntero a Nodo
 */
template <typename T>
Nodo<T>* Nodo<T>::get_siguiente() const{
    return this->siguiente;
}
