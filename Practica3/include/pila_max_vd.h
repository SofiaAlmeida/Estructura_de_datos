/**
  * @file Pila_max_VD.h
  * @brief Implementación del TDA pila_max haciendo uso de vectores dinámicos
  */

  #ifndef __PILA_MAX_VD_H__
  #define __PILA_MAX_VD_H__

template <class T>

class Pila_max{
  private:

    elemento *v_elem;
    int n_elem;
    int n_disp;


    // Máximo

    /**
    * @brief Halla el máximo de dos elementos
    * @param max_act Es el máximo actual
    * @param elem_nuevo Es el elemento nuevo a comparar
    * @return Devuelve el máximo de los dos
    */

    max(const Elemento &max_act, const Elemento &elem_nuevo);


  public:

    // Constructores

  /**
    * @brief Constructor vacío
    */

    Pila_max():n_elem(0), n_disp(0) {}

  /**
    * @brief Constructor copia
    * @pararm objeto pila_max original a copiar
    */

    Pila_max(const Pila_max &original);

    // Destructor

  /**
    * @brief Destructor de Pila_max
    */

    ~Pila_max();


    // Push-agregar

  /**
    * @brief Añade un elemento al final de la pila
    * @param elem Elemento a añadir
    */

    push(const elemento &elem);


    // Pop

  /**
    * @brief Elimina el último elemento de la pila
    */

    pop();

    
  };

  #include "Pila_max_VD.cpp"
  #endif
