/**
  * @file Pila_max_VD.h
  * @brief Implementación del TDA pila_max haciendo uso de vectores dinámicos
  */

  #ifndef __PILA_MAX_VD_H__
  #define __PILA_MAX_VD_H__

template <class T>

class Pila_max{
  private:

    T *v_elem;          // "TODO" Pila_max sólo guarda enteros? O debemos de ampliar esta estructura a cualquier otro tipo de dato?
    T *v_max;           // En caso afirmativo, qué criterio usamos en esos tipos para decidir quién es el máximo del conjunto?
    int n_elem;
    int n_disp;

  public:

    // Constructores

    Pila_max():n_elem(0), n_disp(0){}

    Pila_max(const T &original);

    // Destructor

    ~Pila_max();


    // Push-agregar

    Push(const T &elem);


    // Pop

    Pop();
  };

  #include "Pila_max_VD.cpp"
  #endif
