#include "pila_max_list.h"

/*Duda de implementación
	Utilizar dos vectores o solo uno?
*/


Pila_max::Pila_max() {
	*Celda aux = new Celda;
	cabecera = aux;
	aux->ant = 0;
	aux->sig = 0;
}

int Pila_max::size () {
	int i = 0;
	Celda* p =cabecera->ant

	while (p != cabecera){
		i++;
		p = p->ant;
	}

	return i;
}

/*NOTE:recordadme que ponga el algoritmo algo mas fino si sobra tiempo, este es la version simple*/
Pila_max::Pila_max(const Pila_max& p) {
	cabecera->ant = cabecera->sig = 0; /*Esta linea de codigo se realiza para poder usar sin problemas la
	                                    función push;*/
	for (Celda* q = p.cabecera->sig;; q != cabecera; p = p->sig){
		push(p->dato.ele);
	}
}


Pila_max& Pila_max::operator= (const Pila_max& p){
	if (this != &p) {
		while (cabecera->ant) {
			pop();
		}

		for (Celda* q = p.cabecera->sig; q != cabecera; p = q->sig){
			push(q->dato.ele);
		}
	}

	return this;
}


void Pila_max::push(T y) {
	if (cabecera->ant != 0) {
		*Celda aux = new Celda;
		aux->ant = cabecera->ant;
		cabecera->ant->sig = aux;
		cabecera->ant = aux;
		aux->sig = cabecera

		aux->dato.ele = y;
		x = (aux->ant->dato.max)
		aux->dato.max = (y>x ? y : x);
	}

	else {
		*Celda aux = new Celda;
		aux->ant = aux->sig = cabecera;
		cabecera->ant = cabecera->sig = aux;
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
	while (cabecera->ant) {
		pop();
	}
	delete cabecera;
}
