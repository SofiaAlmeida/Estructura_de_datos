/***
   * @file Pila_max_List.h
   * @brief Fichero cabecera del TDA Pila_max_list
   * Pila ordenada implementada a partir de celdas enlazadas
   *
   * @author Sofía Almeida Bruno (@SofiaAlmeida)
   * @author Jesús Sánchez de Lechina Tejada (@jojelupipa)
   * @author Pedro Bonilla Nadal (@pedrobn23)
   */

#ifndef __PILA_MAX_LIST_H__
#define __PILA_MAX_LIST_H__

#include <cassert>
#include <iostream>

/***
   *  @brief T.D.A. Pila_max_list
   *
   */


/*Puesto que la pila es una estructura que solo se puede leer de atrás a adelante
no vamos a implementar una lista circular, si no una lista de celdas encalazadas hacia atrás,
pero también hacia adelante, para aumentar la eficiencia del constructor de entrada y salida
*/
struct Celda {
	elemento dato;
	*Celda ant;
	*Celda sig;
};


class Pila_max {
private:
	*Celda cabecera;
	//Funcion que implemente pero no llegue a usar
	int size ();


Public:
/**
  * @brief constructor por defecto de la función. Crea una pila vacia.
  */
	Pila_max ();
/**
  * @brief constructor de copia.
  * @param Pila_max& p pila a copiar.
  */
	Pila_max (const Pila_max& p);

/**
  * @brief Función que devuelve el valor del primer último de la pila. FIFO.
  * @return elemento de la pila.
  */
	elemento top () const {return (cabecera->ant.dato);};

/**
  * @brief Evalua si la pila está vacia.
  * @return devuelve un bool con la información.
  */
	bool empty() {return !(cabecera->ant)};
/**
  * @brief saca el último elemento de la pila
  */
	void pop();
/**
  * @brief añade un elemento de la pila
  */
	void push(T t);
/**
  * @brief operador de asignación standard.
  * @param Pila_max& p objeto a asignar.
  * @return el elemento asignado.
  */
	Pila_max& operator= (const Pila_max& p);
/**
  * @brief destructor de la función.
  */
	~Pila_max ();
}
