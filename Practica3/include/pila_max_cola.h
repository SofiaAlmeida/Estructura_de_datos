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
#include "cola.h"

/***
   *  @brief T.D.A. Pila_max_Cola
   *
   * La descripción de este T.D.A coincide con la del T.D.A @pila_max.h
   * Este archivo contiene el módulo realizado a partir de colas
   *
   *
   */

template <class T>
class Pila_max {
private:
   Cola<elemento> pila;
public:
/***
   * @brief Constructor por defecto
   * @post pila vacía
   */
   Pila_max() {
      pila;
   }

/***
   * @brief Constructor
   * @param cola a guardar en la pila
   * @post pila que contiene los datos de l
   */
   Pila<T>(const Cola<T> &c);

/*
Destructor

Peek
push
pop
top

Operador
==
!=
=

};
*/
};
#include "Pila_max_Cola.cpp"

#endif
