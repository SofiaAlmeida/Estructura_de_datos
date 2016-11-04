/**
  * @file Pila_max_VD.cpp
  * @brief Implementación del TDA pila_max haciendo uso de vectores dinámicos
  */

  #include "pila_max_vd.h"

  /*_________________________________________________________________________*/

// Constructores

template <class T>
  Pila_max::Pila_max<T>(const Pila_max<T> &p){

    n_elem = p.n_elem;
    v_elem = new T [n_elem];
    v_max = new T [n_elem];

    for (int i = 0; i < n_elem; ++i){

      v_elem[i] = p.v_elem[i];
      v_max[i] = p.v_max[i];
    }
  }


// Destructor

  template <class T>
  Pila_max::~Pila_max(){

    delete v_elem[];
    delete v_max[];
    n_elem = 0;
  }


  // Push

    template <class T>
    Pila_max::Push(const T elem){


    }
