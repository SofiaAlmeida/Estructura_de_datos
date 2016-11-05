/**
  * @file Pila_max_VD.cpp
  * @brief Implementación del TDA pila_max haciendo uso de vectores dinámicos
  */

  #include "pila_max_vd.h"

  /*_________________________________________________________________________*/

// Constructores

  Pila_max::Pila_max(const Pila_max &p){

    n_elem = p.n_elem;
    n_disp = p.n_disp;
    v_elem = new elemento [n_disp];

    for (int i = 0; i < n_elem; ++i){

      v_elem[i] = p.v_elem[i];
    }
  }


// Destructor

  Pila_max<T>::~Pila_max(){

    delete v_elem[];
    n_elem = 0;
    n_disp = 0;
  }


  // Maximo

    Elemento  Pila_max::max(const Elemento &max_act, const Elemento &elem_nuevo){    // TODO Se usa T para referirse a que se devuelve un objeto de la clase T?

      if (max_act < elem_nuevo)                                 // TODO Poner esta función en el .h
        return elem_nuevo;

      else
        return max_act;

    }

  // Push

    Pila_max<T>::Push(const Elemento &elem){

      if(n_elem < n_disp){

        v_elem[n_elem] = elem;
        v_max[n_elem] = max(tope(),elem);         // TODO tope aún no está implementada
        n_elem++;
      }

      else{
        resize(n_disp*2);        // TODO función resize, hacerla en el cpp y en el .h

      }
    }


    // Pop

    template <class T>
    Pila_max<T>::Pop(){

      if (n_elem > 0)
      num_elem--;
    }
