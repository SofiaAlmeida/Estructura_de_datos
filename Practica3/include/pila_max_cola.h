/***
   * @file Pila_max_Cola.h
   * @brief Fichero cabecera del TDA Pila_max_Cola
   * Pila ordenada implementada a partir de cola.h
   *
   * @author Sofía Almeida Bruno (@SofiaAlmeida)
   * @author Jesús Sánchez de Lechina Tejada (@jojelupipa)
   * @author Pedro Bonilla Nadal (@pedrobn23)
   */

#ifndef __PILA_MAX_COLA_H__
#define __PILA_MAX_COLA_H__

#include <cassert>
#include <algorithm>    // std::swap
#include "cola.h"

using namespace std;
/***
   *  @brief T.D.A. Pila_max_Cola
   *
   * La descripción de este T.D.A coincide con la del T.D.A @pila_max.h
   * Este archivo contiene el módulo realizado a partir de colas
   *
   *
   */

//template <class T>
class Pila_max {
private:
   Cola<elemento> pila;

public:
/***
   * @brief Constructor por defecto
   * @post pila vacía
   */
   Pila_max();

/***
   * @brief Constructor de copia
   * @param p Pila a copiar en el objeto implícito
   */
   Pila_max(const Pila_max &p) {
      pila = p.pila;
   }

/***
   * @brief Destructor
   */
  ~Pila_max();

/***
   * @brief Agregar un elemento al comienzo de la pila
   * @param e elemento a insertar
   * @post pila con el elemento máximo en elemento.max
   */
   void push(const elemento &e);

/***
   * @brief Eliminar el último elemento añadido
   * @post Pila sin el tope
   */
   void pop() {
      pila.quitar();
   }

/***
   * @brief Devuelve el tope de la pila
   */
   elemento top() {
      return pila.frente();
   }

/***
   * @brief Devuelve el tope de la pila constante
   */
   elemento top() const {
      return pila.frente();
   }

/***
   * @brief Sobrecarga operador de asignación
   * @param p Pila a asignar
   * return Objeto implícito
   */
   Pila_max& operator=(const Pila_max &p);
};
#include "../src/Pila_max_Cola.cpp" //FIXME

#endif
