#include "Lista.h"
#include<iostream>

using namespace std;

int main() {
    Lista<double> mi_lista;

    mi_lista.agregar_tras(4.0, 3.0);
    mi_lista.borrar(7.0);
    mi_lista.mostrar();
    mi_lista.agregar_primero(3.1);
    mi_lista.mostrar();
   
    Lista<char> mi_lista2('a');

    mi_lista2.agregar_tras('d', 'a');
    mi_lista2.borrar('a');
    mi_lista2.agregar_final('I');
    mi_lista2.agregar_primero('M');
    mi_lista2.borrar('I');
    mi_lista2.mostrar();
    cout << "mi_lista2.get_tamanio(): " << mi_lista2.get_tamanio() << endl;
    mi_lista2.mostrar();

    return 0;
}
