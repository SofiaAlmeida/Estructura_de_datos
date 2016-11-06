/**
  * @file Pila_max_VD.h
  * @brief Implementación del TDA pila_max haciendo uso de vectores dinámicos
  *
  * @author Sofía Almeida Bruno (@SofiaAlmeida)
  * @author Jesús Sánchez de Lechina Tejada (@jojelupipa)
  * @author Pedro Bonilla Nadal (@pedrobn23)
  */

  #ifndef __PILA_MAX_VD_H__
  #define __PILA_MAX_VD_H__


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

    int max(int max_act, int elem_nuevo);


    // Resize

    /**
      * @brief Cambia el tamaño del vector para poder añadir más elementos
      * @param size
      */

      void resize(int size);

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
    * @param elem elemento a añadir
    */

    void push(int dato);


    // Pop

  /**
    * @brief Elimina el último elemento de la pila
    */

    void pop();

  /**
    * @brief Comprueba si la pila está vacía
    * @retval true si la pila está vacía
    */

    bool empty();


  /**
    * @brief Devuelve el elemento del tope
    * @return elemento
    */

    elemento top();

  /**
    * @brief Sobregarga del operador =
    * @param p Pila a copiar
    */

    Pila_max& operator= (const Pila_max &p);

      


  };

//  #include "Pila_max_VD.cpp"          // Para cuando añadamos templates
  #endif
