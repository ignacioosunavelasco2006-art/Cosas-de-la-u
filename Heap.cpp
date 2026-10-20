#include <iostream>
#include <string>
#include "heap.h"
using namespace std;

void menu() {
    cout << "Menu: " << endl;
    cout << "1.-INSERTAR HEAP" << endl;
    cout << "2.-ELIMINAR RAIZ" << endl;
    cout << "3.-MOSTRAR ARRAY" << endl;
    cout << "4.-LEER ARCHIVO" << endl;
    cout << "5.-HEAP SORT" << endl;
    cout << "6.-LEER BOLIVIA" << endl;
    cout << "7.-SALIR" << endl;
}

static void opcionesMenu(heap<string>& arbol) {
    int opcion;
    bool cont = false;
    string dato;
    do {
        menu();
        cout << "Escoja una opcion del menu: ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            cin >> dato;
            arbol.insertar(dato);
            break;
        case 2:
            if (arbol.eliminarRaiz(dato))
                cout << "Raiz eliminada: " << dato << endl;
            else
                cout << "Heap vacio" << endl;
            break;
            break;
        case 3:cout << "Array:" << endl;
            arbol.mostrarArray();
            break;
        case 4:
            cout << "Archivo leido" << endl;
			arbol.leerArchivo();
            break;
        case 5:cout << "Sort: " << endl;
            arbol.heapSort();
            break;
        case 6:cout << "Texto leido" << endl;
            arbol.leertxt();
            arbol.mostrarArray2();
            break;
        case 7:cout << "saliendo" << endl;
            break;
        }
    } while (opcion != 7);
}

int main() {
    heap<string>* a = new heap<string>();
    opcionesMenu(*a);
    delete a;
    return 0;
}