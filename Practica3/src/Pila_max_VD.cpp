/**
  * @file Pila_max_VD.cpp
  * @brief Implementación del TDA pila_max haciendo uso de vectores dinámicos
  */

  #include "pila_max_vd.h"

  /*_________________________________________________________________________*/


  /*__________________PARTE_PRIVADA__________________________________________*/

  // Maximo

  Elemento  Pila_max::max(const Elemento &max_act, const Elemento &elem_nuevo){

    if (max_act < elem_nuevo)
    return elem_nuevo;

    else
    return max_act;

  }


  /*__________________PARTE_PÚBLICA_________________________________________*/

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

  Pila_max::~Pila_max(){

    delete v_elem[];
    n_elem = 0;
    n_disp = 0;
  }



// Push

  Pila_max::Push(const Elemento &elem){

    Elemento nuevo;
    nuevo.ele = elem.ele;

    if (n_elem > 0)
      nuevo.max = max(elemento[n_elem - 1].max, nuevo.ele);      // Comparamos el máximo del último elemento insertado con el valor del actual

    else
      nuevo.max = elem.ele;

    if(n_elem < n_disp){

      v_elem[n_elem] = elem;
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
