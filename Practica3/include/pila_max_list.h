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
#include

/***
   *  @brief T.D.A. Pila_max_list
   *
   */


/*Puesto que la pila es una estructura que solo se puede leer de atrás a adelante
no vamos a implementar una lista circular, si no una lista de celdas encalazadas hacia atrás.
*/
struct Celda {
	elemento dato;
	*Celda ant;
	*Celda sig;
};


class Pila_max {
private:
	*Celda cabecera;

	int size ();


Public:
	Pila_max ();
	Pila_max (const Pila_max& p);


	elemento top const() {return (cabecera->ant.dato);};
	bool empty() {return !(cabecera->ant)};
	void pop();
	void push();

	Pila_max& operator= (const Pila_max& p);

	~Pila_max ();
}
