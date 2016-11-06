/**
  * @file Pila_max_VD.cpp
  * @brief Implementación del TDA pila_max haciendo uso de vectores dinámicos
  */

  #include "Pila_max.h"

  /*_________________________________________________________________________*/


  /*__________________PARTE_PRIVADA__________________________________________*/

  // Máximo

  int Pila_max::max(int max_act, int elem_nuevo){

    if (max_act < elem_nuevo)
    return elem_nuevo;

    else
    return max_act;

  }

  // Resize

  void Pila_max::resize(int size){

    elemento *nuevo;
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

  void Pila_max::push(int dato){

    elemento nuevo;
    nuevo.ele = dato;

    if (n_elem > 0)
      nuevo.max = max(v_elem[n_elem-1].max, dato);      // Comparamos el máximo del último elemento insertado con el valor del actual

    else
      nuevo.max = dato;

    if(n_elem < n_disp){

      v_elem[n_elem] = nuevo;
      n_elem++;
    }

    else{

      resize(n_disp*2);
      v_elem[n_elem] = nuevo;

    }
  }


  // Pop

  void Pila_max::pop(){

    if (!empty())
    n_elem--;
  }

  bool Pila_max::empty(){

    if (n_elem == 0)
      return true;

    else
      return false;
  }


  elemento Pila_max::top(){

    if (!empty())
      return v_elem[n_elem-1];
  }


  Pila_max& Pila_max::operator= (const Pila_max &p){

    n_elem = p.n_elem;
    n_disp = p.n_disp;
    v_elem = new elemento [n_disp];

    for (int i = 0; i < n_elem; ++i){

      v_elem[i] = p.v_elem[i];
    }

    return *this;
  }
