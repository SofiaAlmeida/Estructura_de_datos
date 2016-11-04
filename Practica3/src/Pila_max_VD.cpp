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
    n_disp = p.n_disp;
    v_elem = new T [n_disp];
    v_max = new T [n_disp];

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
    n_disp = 0;
  }


  // Maximo

    template <class T>
    T  Pila_max::Max(const T &max_act, const T &elem_nuevo){    // TODO Se usa T para referirse a que se devuelve un objeto de la clase T?

      if (max_act < elem_nuevo)                                 // TODO Poner esta función en el .h
        return elem_nuevo;

      else
        return max_act;

    }

  // Push

    template <class T>
    Pila_max::Push(const T elem){

      if(n_elem < n_disp){

        v_elem[n_elem] = elem;
        v_max[n_elem] = max(tope,elem);
        n_elem++;
      }

      else{
        resize(n_disp*2);        // TODO función resize, hacerla en el cpp y en el .h

      }
    }


    // Pop

    template <class T>
    Pila_max::Pop(){

      if (n_elem > 0)
      num_elem--;
    }
