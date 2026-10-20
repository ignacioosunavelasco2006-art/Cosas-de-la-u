#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template<class T>
class Nodo
{
private:
    T dato;
    T dato1;
    T dato2;
    bool presente;
public:
    Nodo();
    ~Nodo();
    T getDato1();
    T getDato2();
    T getDato();
    void setDato(T dato);
	void setDato2(T dato2);
    bool getPresente();
    void setDato1(T dato1); 
    void setPresente(bool presente);
};

template<class T>
Nodo<T>::Nodo()
{
    presente = false;
}

template<class T>
Nodo<T>::~Nodo()
{
}

template<class T>
T Nodo<T>::getDato1() {
    return dato1;
}

template<class T>
T Nodo<T>::getDato2()
{
    return dato2;
}

template<class T>
T Nodo<T>::getDato()
{
    return dato;
}

template<class T>
void Nodo<T>::setDato(T dato)
{
    this->dato = dato;
}

template<class T>
inline void Nodo<T>::setDato2(T dato2)
{
    this->dato2 = dato2;
}

template<class T>
 bool Nodo<T>::getPresente()
{
    return presente;
}

template<class T>
 void Nodo<T>::setDato1(T dato1)
{
     this->dato1 = dato1;
}

 template<class T>
  void Nodo<T>::setPresente(bool presente)
 {
      this->presente = presente;
 }