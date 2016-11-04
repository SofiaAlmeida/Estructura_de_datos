/***
   * @file PIla_max.h
   * @brief Fichero cabecera del TDA Pila_max
   *
   * Pila_max es una pila que almacena en su tope el máximo de los elementos
   *
   * @author Sofía Almeida Bruno (@SofiaAlmeida)
   * @author Jesús Sánchez de Lechina Tejada (@jojelupipa)
   * @author Pedro Bonilla Nadal (@pedrobn23)
   */

#ifndef __PILA_MAX_H__
#define __PILA_MAX_H__

#include <cassert>

/***
   *  @brief T.D.A. PIla_max
   *
   *
   * Una instancia @e c del tipo de dato abstracto Pila_max sobre un dominio @e T es
   * un conjunto de elementos del mismo tipo con un funcionamiento @e LIFO
   * (Last In, First Out}). En una pila, las operaciones de inserción y borrado
   * tienen lugar en uno de los extremos, denominado @e tope de la pila. Pila_max
   * se caracteriza por tener en el tope al máximo de los elementos
   *
   * Si n=0 diremos que la pila está vacía.
   *
   * En este módulo decidiremos que implementación de pila queremos usar:
   *
   * La primera es la implementación de Pila_max basada en un vector dinámico,
   * la segunda se basa en una lista, mientras que la última se basa en una cola
   */

   #define CUAL_COMPILA 2
   #if CUAL_COMPILA==1
   #include <pila_max_vd.h>
   #elif CUAL_COMPILA==2
   #include <pila_max_lista.h>
   #else
   #include <pila_max_cola.h>
   #endif
