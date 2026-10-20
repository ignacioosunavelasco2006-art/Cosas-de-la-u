#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Nodo.h"
#define TAM 20003
#define TAM2 15
using namespace std;
template <class T>
class heap
{
private:
    Nodo<T> ARR[TAM];
    Nodo<T> ARR2[TAM2];
    int ultimaHoja = 0;
public:
	void insertar(T dato1);
	bool eliminarRaiz(T& menor);
	void mostrarArray();
	void Rec(int i);
	void leerArchivo();
	void heapSort();
    void abajoArriba(int hoja);
    void leertxt();
    void insertar2(T dato,T dato1,T dato2);
    void abajoArriba2(int hoja);
    void mostrarArray2();

};

template<class T>
 void heap<T>::insertar(T dato1)
{
    if (ultimaHoja == 0) 
    {
        ultimaHoja = 1; 
        ARR[ultimaHoja].setDato1(dato1);
        ARR[ultimaHoja].setPresente(true);
    }
    else                                        
    {
        ultimaHoja = ultimaHoja + 1;
        ARR[ultimaHoja].setDato1(dato1);               
        ARR[ultimaHoja].setPresente(true);        
        abajoArriba(ultimaHoja);                  
    }
}

template<class T>
bool heap<T>::eliminarRaiz(T& menor)
{
    if (ultimaHoja == 0){
        return false;
}
     menor = ARR[1].getDato1();
     ARR[1].setDato1(ARR[ultimaHoja].getDato1());
     ARR[ultimaHoja].setPresente(false);
     ultimaHoja--;
     if (ultimaHoja > 0) {
         Rec(1);
     }
     return true;
}

template<class T>
 void heap<T>::mostrarArray()
{
    if (ultimaHoja == 0) {
        cout << "Heap vacio" << endl;
        return;
    }
    for (int i = 1; i <= ultimaHoja; i++)
        cout << ARR[i].getDato1() << " ";
    cout << endl;
}

template<class T>
 void heap<T>::Rec(int i)
{
     int izq = 2 * i;
     int der = 2 * i + 1;
     int menor = i;
     if (izq <= ultimaHoja && ARR[izq].getDato1() < ARR[menor].getDato1())
     {
         menor = izq;
     }
     if (der <= ultimaHoja && ARR[der].getDato1() < ARR[menor].getDato1())
     {
         menor = der;
     }
     if (menor != i)
     {
         swap(ARR[i], ARR[menor]);
         Rec(menor);
     }
}

template<class T>
 void heap<T>::leerArchivo()
{
	 ifstream arch("10000_Numeros.txt");
	 if (!arch) {
		 cout << "No se pudo abrir el archivo" << endl;
		 return;
	 }
	 T dato;
	 while (arch >> dato)
		 insertar(dato);
}

 template<class T>
  void heap<T>::heapSort()
 {
     if (ultimaHoja == 0) {
         cout << "Heap vacio" << endl;
         return;
     }
     heap<T>* copia = new heap<T>(*this);   
     T menor;
     while (copia->eliminarRaiz(menor))     
         cout << menor << " ";
     cout << endl;
     delete copia;
 }

  template<class T>
   void heap<T>::abajoArriba(int hoja)
  {
       if (hoja > 1)                                        
       {
           int padre = hoja / 2;
           if (ARR[hoja].getDato1() < ARR[padre].getDato1())
           {
               swap(ARR[hoja], ARR[padre]);
               abajoArriba(padre);
           }
       }
  }

   template<class T>
   void heap<T>::leertxt()
   {
       ifstream archivo("Valorado Bolivia Texto.txt");
       if (!archivo) {
           cout << "No se pudo abrir el archivo" << endl;
       }
       T dato,dato1, dato2;
       while (archivo >> dato >> dato1 >> dato2) {
           insertar2(dato,dato1, dato2);
       }
       archivo.close();
   }

   template<class T>
   void heap<T>::insertar2(T dato,T dato1, T dato2)
   {
        if (ultimaHoja == 0)
        {
            ultimaHoja = 1;
            ARR2[ultimaHoja].setDato(dato);
            ARR2[ultimaHoja].setDato1(dato1);
            ARR2[ultimaHoja].setDato2(dato2);
            ARR2[ultimaHoja].setPresente(true);
        }
        else
        {
            ultimaHoja = ultimaHoja + 1;
            ARR2[ultimaHoja].setDato(dato);
            ARR2[ultimaHoja].setDato1(dato1);
            ARR2[ultimaHoja].setDato2(dato2);
            ARR2[ultimaHoja].setPresente(true);
            abajoArriba2(ultimaHoja);
        }
   }

    template<class T>
    void heap<T>::abajoArriba2(int hoja)
    {
        if (hoja > 1)
        {
            int padre = hoja / 2;
            if (ARR2[hoja].getDato1() < ARR[padre].getDato1())
            {
                swap(ARR2[hoja], ARR2[padre]);
                abajoArriba2(padre);
            }
            else if (ARR2[hoja].getDato2() < ARR2[padre].getDato2()) {
                swap(ARR2[hoja], ARR2[padre]);
                abajoArriba2(padre);
            }
        }
    }

    template<class T>
    void heap<T>::mostrarArray2()
    {
        if (ultimaHoja == 0) {
            cout << "Heap vacio" << endl;
        }
        for (int i = 1; i <= ultimaHoja; i++)
            cout <<ARR2[i].getDato()<< " " << ARR2[i].getDato1() << " " << ARR2[i].getDato2() << endl;
    }
