/***
   * @file Pila_max_List.h
   * @brief Fichero cabecera del TDA Pila_max_Cola
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

template <class T>

/*Vamos a hacer una lista circular doblemente enlazada, con cabecera apuntando a
la primera celda y el anterior de la primera celda siendo el último y el siguiente del
último apuntando a 0.
*/
struct Celda {
	T dato;
	*Celda sig;
	*Celda ant;
};

class PilaMaxList {
private:
	*Celda cabecera;

Public:
	PilaMaxList ();
	PilaMaxList (const PilaMaxList& p);

	void pop();
	void push();
	void top const();

	~PilaMaxList ();

/*
Operador
==
!=
=
*/
}
