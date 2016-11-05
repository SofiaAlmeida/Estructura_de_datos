#include "pila_max_list.h"

Pila_max::Pila_max() : {
	*Celda aux = new Celda;
	cabecera = aux;
	aux->ant = 0;
}


void Pila_max::push(T y) {
	if (cabecera->ant != 0) {
		*Celda aux = new Celda;
		aux->ant = cabecera->ant;
		cabecera->ant = aux;

		aux->dato.ele = y;
		x = (aux->ant->dato.max)
		aux->dato.max = (y>x ? y : x);
	}

	else {
		*Celda aux = new Celda;
		aux->ant = cabecera;
		cabecera->ant = aux;
		aux->dato.ele = aux.dato.max = y
	}
}

void Pila_max::pop () {
	if (cabecera->ant) {
		Celda* aux = cabecera->ant
		cabecera->ant = cabecera->ant->ant;
		delete aux;
	}
}


Pila_max::~Pila_max () {

}
