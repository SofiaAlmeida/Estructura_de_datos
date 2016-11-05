/**
  * @file Pila_max_VD.cpp
  * @brief Implementación del TDA pila_max haciendo uso de vectores dinámicos
  */

  #include "pila_max_vd.h"

  /*_________________________________________________________________________*/


  /*__________________PARTE_PRIVADA__________________________________________*/

  // Máximo

  Elemento  Pila_max::max(const Elemento &max_act, const Elemento &elem_nuevo){

    if (max_act < elem_nuevo)
    return elem_nuevo;

    else
    return max_act;

  }

  // Resize

  void Pila_max::resize(int size){

    Elemento *nuevo;
    nuevo = new elemento[size];

    for(int i = 0; i < n_elem && i < size; ++i)   // En caso de que queramos "reducir" el espacio disponible añadimos que i < size
      nuevo[i] = v_elem[i];

    delete [] v_elem;
    v_elem = nuevo;

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

    delete [] v_elem;
    n_elem = 0;
    n_disp = 0;
  }



// Push

  void Pila_max::Push(int &dato){

    Elemento nuevo;
    nuevo.ele = dato;

    if (n_elem > 0)
      nuevo.max = max(elemento[n_elem - 1].max, dato);      // Comparamos el máximo del último elemento insertado con el valor del actual

    else
      nuevo.max = dato;

    if(n_elem < n_disp){

      v_elem[n_elem] = nuevo;
      n_elem++;
    }

    else{

      resize(n_disp*2);        // TODO función resize, hacerla en el cpp y en el .h
      v_elem[n_elem] = nuevo;

    }
  }


  // Pop

  void Pila_max<T>::Pop(){

    if (n_elem > 0)
    num_elem--;
  }
